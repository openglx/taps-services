/*****************************************************************
 * libircservice is (C) CopyRight PTlink IRC Software 1999-2005  *
 *                    http://software.pt-link.net                *
 * This program is distributed under GNU Public License          *
 * Please read the file COPYING for copyright information.       *
 *****************************************************************
  
  Description: init/connect routines

 *  $Id: initconn.c 33 2010-05-10 02:46:01Z openglx $
*/
#include "stdinc.h"
#include "setup.h"
#include "sockutil.h"
#include "ircdio.h"
#include "ircservice.h"
#include "m_commands.h"
#include "common.h"
#include "channel.h"
#include "hash.h"
#include "event.h"
#include "send.h"
#include "umode.h"
#include "patchlevel.h"
#include "user.h" /* PeakUser */

#ifdef IRCD_PLEXUS
char myserversid[IRC_MAXSID];
#endif
char myservername[HOSTLEN];
char myserverinfo[HOSTLEN];
char myserverversion[HOSTLEN];
int ircd_fd;
int ircfullconnect = 0;
int ircs_debug;

#ifdef IRCD_PLEXUS
int ircd_type = PLEXUS3;
#else
int ircd_type = PTLINK6;
#endif

FILE *ircslogf;
int dkmask = 0;
static int server_sent = 0; /* SERVER message was sent */
static char *LocalAddress;

extern void cmodes_build(void);
/**
  * Set local address to bind before the connection
  */
void irc_SetLocalAddress(char *la)
{
  if(la)
    LocalAddress = strdup(la);
}

/**
  * init local server
  */
#ifdef IRCD_PLEXUS
int irc_Init(int stype,char *sname, char *sinfo, char *ssid, FILE *logfd)
#else
int irc_Init(int stype,char *sname, char *sinfo, FILE *logfd)
#endif
{
  cmodes_build();
  ircd_type = stype;
  ircslogf = logfd;
  strncpy(myservername, sname, HOSTLEN);
  strncpy(myserverinfo, sinfo, HOSTLEN);
#ifdef IRCD_PLEXUS
  strncpy(myserversid, ssid, IRC_MAXSID);
#endif
  irc_SetVersion(PATCHLEVEL);
  server_sent = 0;
  ircfullconnect = 0;
  irc_CurrentTime = time(NULL);
  add_me();
  irc_ChanMlocker = irc_LocalServer;
  return 1;
}

/**
  * set server version
  */
void irc_SetVersion(char *version)
{
  strncpy(myserverversion, version, HOSTLEN);
}
/*
 * Lets attempt the connection
 */
int irc_StartConnect(char* ircserver,int port, char* connectpass,
         int options)
{
  ircd_buff_init();
  ircd_fd = sock_conn(ircserver,port, LocalAddress, ircslogf);
  if(ircd_fd<0)
    return ircd_fd;
#ifdef IRCD_PLEXUS
  sendto_ircd(NULL, "PASS %s TS %d %s",connectpass, 6, myserversid);
  sendto_ircd(NULL, "SERVER %s 1 :%s %s",
    myservername, myserverversion, myserverinfo);
  sendto_ircd(NULL, "SVINFO %d %d 0 :%ld", 6, 3, irc_CurrentTime);
#else
  sendto_ircd(NULL, "PASS %s :TS",connectpass);
  sendto_ircd(NULL, "SERVER %s 1 %s :%s",
    myservername, myserverversion, myserverinfo);
  sendto_ircd(NULL, "SVINFO %d %d %d", TS_CURRENT, TS_MIN, irc_CurrentTime);
#endif
  sendto_ircd(NULL, "SVSINFO %d %d",
    irc_CurrentTime, PeakUser);
  sendto_ircd(NULL,"PING :%s", myservername); 
  server_sent = 1;
  return ircd_fd;
}

                  
/*
 * Lets do a full connection (return after gettin all netjoin data)
 */
int irc_FullConnect(char* ircserver,int port, char* connectpass,
         int options)
{
  int rc;
  IRC_User *u;
  
  rc = irc_StartConnect(ircserver, port, connectpass, options);
  if(rc < 0) /* we got an error */
    return rc;
    
/* we need to add the core handlers here */
#ifdef IRCD_PLEXUS
  irc_AddRawHandler("PASS", m_pass);
  irc_AddRawHandler("UID", m_uid);
  irc_AddRawHandler("TMODE", m_tmode);
  irc_AddRawHandler("JOIN", m_join);
  irc_AddRawHandler("SID", m_sid);
#endif
  irc_AddRawHandler("SERVER", m_server);
  irc_AddRawHandler("SQUIT", m_squit);
  irc_AddRawHandler("NICK", m_nick);
  irc_AddRawHandler("NNICK", m_nick);  
  irc_AddRawHandler("PONG", m_pong);
  irc_AddRawHandler("PING", m_ping);  
  irc_AddRawHandler("QUIT", m_quit);
  irc_AddRawHandler("MODE", m_mode);
  irc_AddRawHandler("KILL", m_kill);
  irc_AddRawHandler("PRIVMSG", m_privmsg);
  irc_AddRawHandler("SJOIN", m_sjoin);
  irc_AddRawHandler("NJOIN", m_sjoin);      
  irc_AddRawHandler("PART", m_part);
  irc_AddRawHandler("KICK", m_kick);  
  irc_AddRawHandler("TOPIC", m_topic);
  
  /* lets introduce our local clients */
  u = hash_next_localuser(1);
  while(u)
   {
     irc_IntroduceUser(u);
     u = hash_next_localuser(0);
   }
    
  while(irc_DoEvents() && !ircfullconnect)
    usleep(10000);
    
  if(ircfullconnect == 0)
    return -1;
    
  return 1;
}


/* enable/disable debug mode */
void irc_SetDebug(int dval)
{
  ircs_debug=dval;
}

/* Event handling loop, returns when connection is lost */
void irc_LoopWhileConnected(void) 
{
  while(irc_DoEvents())
    {
      irc_CallEvent(ET_LOOP, NULL, NULL);
      usleep(100);      
    }
}


void m_pong(int parc,char *parv[])
{
  if(parc<2)
    return ;
  ircfullconnect = 1;
}

void m_ping(int parc,char *parv[])
{
  if(parc<2)
    return;  
  sendto_ircd(myservername,"PONG :%s", parv[1]);    
}

#ifdef IRCD_PLEXUS
/*
 * Parsing: :37Z SJOIN 1237053196 #services.log +nt :@37ZAAAAAF @37ZAAAAAE
 * Parsing: :37ZAAAAAF JOIN 1237055134 #services.log +
 * m_join parv[0]="37ZAAAAAE"
 * m_join parv[1]="1237055134"
 * m_join parv[2]="#services.log"
 * m_join parv[3]="+"
 */
void m_join(int parc,char *parv[])
{
  char *new_parv[5];
  char new_parc;

/*  int i;
  for(i=0; i<parc; i++)
    fprintf(ircslogf,"m_join parv[%d]=\"%s\"\n",i,parv[i]);
*/

  new_parv[0] = myservername;
  new_parv[1] = parv[1];
  new_parv[2] = parv[2];
  new_parv[3] = parv[3];
  new_parv[4] = parv[0];
  new_parc = 5;

  m_sjoin(new_parc, new_parv);
}


/*
 * Parsing: :37ZAAAAAE TMODE 1237053019 #services.log +o 37ZAAAAAF
 * m_tmode parv[0]="37ZAAAAAE"
 * m_tmode parv[1]="1237053019"
 * m_tmode parv[2]="#services.log"
 * m_tmode parv[3]="+o"
 * m_tmode parv[4]="37ZAAAAAF"
 */
void m_tmode(int parc,char *parv[])
{
  IRC_User* src_u = NULL;
  IRC_User* dst_u = NULL;
  char *new_parv[4];
  char new_parc;

/*
 int i;

 for(i=0; i<parc; i++)
  fprintf(ircslogf,"m_tmode parv[%d]=\"%s\"\n",i,parv[i]);
*/

  if(parc < 5)
    return;

  src_u = irc_FindUser(parv[0]);
  dst_u = irc_FindUser(parv[4]);

  if(!src_u || !dst_u)
    {
      fprintf(ircslogf, "Channel mode %s for non-existents %s or %s at %s?",
          parv[3], parv[0], parv[4], parv[2]);
    }

  /* needs now to be 'source_nick #channel +mode dst_nick' */
  //new_parv[0] = src_u->nick;
  new_parv[0] = parv[0];
  new_parv[1] = parv[2];
  new_parv[2] = parv[3]; 
  //new_parv[3] = dst_u->nick;
  new_parv[3] = parv[4];
  new_parc = 4;

  channel_mode(new_parc, new_parv, 1);
}
#endif

void m_mode(int parc,char *parv[])
{
  IRC_User* u;
  if(parc<3)
    return;        
  if(parv[1][0] == '#')
  	{
    	  channel_mode(parc, parv, 1);
  	}
  else
  	{
  		u=irc_FindUser(parv[1]);
  		if(!u)
  		  {
  		      fprintf(ircslogf,"Mode for non-existent user %s\n",parv[1]);
  		      return ;
  		  }
    	umode_change(parv[2], u);
  	}
}

void m_privmsg(int parc,char *parv[])
{
  char *ch;

  IRC_User *src = irc_FindUser(parv[0]);
	
  if(parc < 3)
    return;
	  
  if(src == NULL)
  {
    fprintf(ircslogf,"Received message from non existent user %s\n", parv[0]);
    return;		
  }
  	
  if(parv[1][0] == '#')
  {
    IRC_Chan *dest = irc_FindChan(parv[1]);
    if(!dest)
    {
      fprintf(ircslogf,"Received message for non local chan %s\n", parv[1]);
      return ;
    }
    check_chan_gmsg_events(dest, src, parv[2]);
    check_chan_msg_events(dest, src, parv[2]);    
  }
  else if(parv[1][0] != '$') /* we simply ignore this */
  {
    IRC_User *dest = irc_FindLocalUser(parv[1]);;
    if((ch = strchr(parv[1],'@'))) /* it can be nick@server */
      *ch = '\0';
    dest = irc_FindLocalUser(parv[1]);
    if(!dest)
    {
      fprintf(ircslogf,"Received message for non local user %s\n", parv[1]);
      return ;
    }    
    check_user_msg_events(dest, src, parv[2]);
  }
}

/* Returns the current connection status
 */
int irc_ConnectionStatus(void)
{
  if(ircfullconnect)
    return 2;
  if(server_sent)
    return 1;  
    
  return 0;
}
