/*****************************************************************
 * libircservice is (C) CopyRight PTlink IRC Software 1999-2004   * 
 *                http://software.pt-link.net                     *
 * This program is distributed under GNU Public License          *
 * Please read the file COPYING for copyright information.       *
 *****************************************************************

  File: user.c
  Description: user handling functions

 *  $Id: user.c 33 2010-05-10 02:46:01Z openglx $
*/
#include "ircservice.h"
#include "channel.h"	/* we need this for del_user_from_chan() */
#include "dlink.h"
#include "event.h"
#include "common.h"
#include "hash.h"
#include "user.h"
#include "send.h"
#include "umode.h"
#include "irc_string.h"

static IRC_User *GlobalUserList=NULL;

unsigned int PeakUser = 0; /* Thales -- for fix the svsinfo message */
static unsigned int peakcnt = 0;

/* hmm */
#ifdef IRCD_PLEXUS
static long int permanentUniqueID = 0;

void applyUniqueTsId(IRC_User* user)
{
	char id[IDLEN + 1];

	// safe boundaries?
	snprintf(id, IDLEN, "%s%ld", myserversid, ++permanentUniqueID);

	// safe boundaries?
	strcpy(user->uid, id);

	return;
}
#endif

/* internal functions */
void m_nick(int parc,char *parv[]);
void m_quit(int parc,char *parv[]);
void m_kill(int parc,char *parv[]);

/* free all users data and remove user from global list */
void remove_remote_user(IRC_User *user)
{
  irc_CancelUserTimerEvents(user);	/* Delete any pending events from user */
  if(user->sname)			/* it is a server */
  {
#ifdef IRCD_PLEXUS
    if (user->sid)
    {
     del_from_uid_hash_table(user->sid, user);
    }
#endif
    del_from_user_hash_table(user->sname, user);    
  }
  else
  {
#ifdef IRCD_PLEXUS
    if (user->uid)
    {
     del_from_uid_hash_table(user->uid, user);
    }
#endif
    del_from_user_hash_table(user->nick, user);
  }
  del_user_chans(user);
  del_user_from_global_list(user);  
  /*  delete_user_msg_events(user); */
  FREE(user->sname);
  FREE(user->vlink);
  free(user);
}

/* free all users data */
void remove_local_user(IRC_User *user)
{
  if(irc_ChanMlocker == user)
		irc_ChanMlocker = irc_LocalServer;
  irc_CancelUserTimerEvents(user);	/* Delete any pending events from user */
  del_from_localuser_hash_table(user->nick, user);
  del_user_chans(user);
  delete_user_msg_events(user);
  FREE(user->sname);
  FREE(user->vlink);
  free(user);
}

#ifdef IRCD_PLEXUS
/*
 * m_uid
 */
void m_uid(int parc,char *parv[])
{
/* int i;

 for(i=0; i<parc; i++)
  fprintf(ircslogf,"m_uid parc[%d]=\"%s\"\n",i,parv[i]);

 return;*/

  IRC_User* nuser = NULL;
  IRC_Server* from = NULL;
  char *nick;
  int npc;
  int hopc;
  int ts;
  char *umode;
  char *username;
  char *realhost;
  char *publichost;
  char *servername;
  char *info;
  //char *vlink = NULL;
  char *uid;
  
  npc=9;
  servername = parv[0];
  nick = parv[1];

  if((nuser = irc_FindLocalUser(nick))) /* should NEVER be a collision */
  {
  	/** XXX check possible change in protocol (KILL) **/
    sendto_ircd(irc_LocalServer->sname,"KILL %s :%s", 
      nuser->nick, "Service override, remote nick !");
    irc_IntroduceUser(nuser);
    return;
  }

  hopc = atoi(parv[2]);
  ts = atoi(parv[3]);
  umode = parv[4];
  username = parv[5];
  publichost = parv[6];
  realhost = parv[10];
//if(parc == 11) /* support for brasnet vlinks */
//{      	
//  servername = parv[8];
//  vlink = parv[9];          
//  info = parv[10];
//}
//else
//{
  uid = parv[8];
  info = parv[11];
//}        

  //fprintf(ircslogf,"m_uid criando nick=(%s) uid=(%s)\n",nick,uid);
  //fprintf(ircslogf,"m_uid parc(%d) npc(%d)\n",parc,npc);

  if(parc < npc)
    return;
    
  if(parv[0])
    {
      from = irc_FindServer(parv[0]);
      if(from == NULL)
        {
          fprintf(ircslogf,"NICK from non-existent server %s\n",parv[0]);
          return;
        }
    }

  /* this is a new nick introduction */           	
  nuser = irc_CreateUser(nick, username, realhost, publichost,
        info, umode, servername);

  strncpy(nuser->uid, uid, IDLEN);

  //fprintf(ircslogf,"m_uid obteve nuser=(%p)\n",nuser);

  nuser->from = from;
  nuser->ts = ts;
  //if(vlink)
  //  nuser->vlink = strdup(vlink);

  /* add to hash table... TWICE! we need pointer to both uid and nick!
   * -- openglx */
  add_to_uid_hash_table(uid, nuser);
  add_to_user_hash_table(nick, nuser);
  /* add to user global list */
  add_user_to_global_list(nuser);
  if(irc_CallEvent(ET_NEW_USER, nuser, NULL) == 0) /* could be killed */
    umode_change(umode, nuser);

  //fprintf(ircslogf,"m_uid irc_FindUser(%s) == %p\n",uid,irc_FindUser(uid));
}
#endif // IRCD_PLEXUS


/* -- Thales - When services is restarted, PeakUser
* needs get your value
*/

int irc_SetPeak (unsigned int peak)
{
   PeakUser = peak;
   return (PeakUser < 0);
}


/*
 * m_nick
 */
void m_nick(int parc,char *parv[])
{
  IRC_User* nuser = NULL;
  IRC_Server* from = NULL;
  char *nick;
  int npc;
  int hopc;
  int ts;
  char *umode;
  char *username;
  char *realhost;
  char *publichost;
  char *servername;
  char *info;
  char *vlink = NULL;
  
  if(parc>3) /* new user */
    {
      if(ircd_type==PTLINK6)
      {
        npc=10;
      	nick = parv[1];
      	if((nuser = irc_FindLocalUser(nick))) /* kill on nick collision */
      	{
      	  sendto_ircd(irc_LocalServer->sname,"KILL %s :%s", 
      	    nuser->nick, "Service override, remote nick !");
          irc_IntroduceUser(nuser);
      	  return;
        }
      	hopc = atoi(parv[2]);
      	ts = atoi(parv[3]);
      	umode = parv[4];
      	username = parv[5];
      	realhost = parv[6];
      	publichost = parv[7];
      	if(parc == 11) /* support for brasnet vlinks */
      	{      	
          servername = parv[8];
          vlink = parv[9];          
          info = parv[10];
        }
        else
      	{
          servername = parv[8];
          info = parv[9];
        }        
      }
      else return;
    } 
  else /* nick change */
    {
      nuser = irc_FindUser(parv[0]);
      if(nuser==NULL)
        {
          fprintf(ircslogf,"Nick change from non-existent user %s\n",parv[0]);    
          return;        
        }
      strncpy(nuser->lastnick, parv[0], NICKLEN);
#ifdef IRCD_PLEXUS
      /* Update TS, as some hybrid7-based ircds will require this.
       * Found by after @ irc.CHATnet.org.br
       * -- openglx
       */
       nuser->ts = atoi(parv[2]);

      /* careful! hybrid7 doesn't send "oldnick NICK newnick", so don't loose 
       * the UID information. That's why I only delete it from user_hash_table.
       * -- openglx
       */
      del_from_user_hash_table(nuser->nick, nuser);
#else
      del_from_user_hash_table(parv[0], nuser);
#endif
      strncpy(nuser->nick, parv[1], NICKLEN);
      add_to_user_hash_table(parv[1], nuser);
      nuser->umodes &= ~UMODE_IDENTIFIED;
      irc_CallEvent(ET_NICK_CHANGE, nuser, parv[0]);
      return;      
    }

  /* IRCD_PLEXUS code won't get past here, as all nicknames are introduced in
   * an UID message... adding this just to be sure. -- openglx
   */
#ifdef IRCD_PLEXUS
  fprintf(ircslogf,"IRCD_PLEXUS: NICK from server %s, shouldn't be a UID?\n",parv[0]);
  return;
#endif

  if(parc < npc)
    return;
    
  if(parv[0])
    {
      from = irc_FindServer(parv[0]);
      if(from == NULL)
        {
          fprintf(ircslogf,"NICK from non-existent server %s\n",parv[0]);
          return;
        }
    }
  /* this is a new nick introduction */           	
  nuser = irc_CreateUser(nick, username, realhost, publichost,
        info, umode, servername);
  nuser->from = from;
  nuser->ts = ts;
  if(vlink)
    nuser->vlink = strdup(vlink);

  /* add to hash table */
  add_to_user_hash_table(nick, nuser);
  /* add to user global list */
  add_user_to_global_list(nuser);
  
 
  peakcnt++;
  if (PeakUser < peakcnt) {
    PeakUser = peakcnt;
    irc_CallEvent (ET_PEAKUSER, (void *) &PeakUser, NULL);
  }

  if(irc_CallEvent(ET_NEW_USER, nuser, NULL) == 0) /* could be killed */
    umode_change(umode, nuser);
}

/* m_quit handler */
void m_quit(int parc,char *parv[])
{
  IRC_User* user;
  user = irc_FindUser(parv[0]);
  if(!user)
    {
      fprintf(ircslogf,"Quit from non-existent user %s\n",parv[0]);    
      return;
    }    
  irc_CallEvent(ET_QUIT, user, parv[1]);
  remove_remote_user(user);
  peakcnt--;
}

void m_kill(int parc,char *parv[])
{
 
  IRC_User* source;
  IRC_User* target;

  source = irc_FindUser(parv[0]);

#if 0    
  if(!source)
    {
      fprintf(ircslogf,"Kill from non-existent user %s\n", parv[0]);    
      return;
    }
#endif    

  /* remove remote user */
  target = irc_FindUser(parv[1]);
  if(target)
  {
    if(irc_IsLocalUser(target)) /* reintroduce local user */
      irc_IntroduceUser(target);
    else
    {    
      irc_CallEvent(ET_KILL, target, NULL);
      remove_remote_user(target);  
    }
  }
  if(!target)
  {
    fprintf(ircslogf,"Kill for non-existent user %s\n",parv[1]);    
    return;
  }
}


IRC_User* irc_FindUser(char *name)
{
  IRC_User* u = NULL;

#ifdef IRCD_PLEXUS
  /* if using IRCD_PLEXUS, try to find an UID */
  if (IsDigit(*name))
  {
    u = hash_find_uid(name);

    if (u != NULL)
      return u;	
  }
#endif

  u = hash_find_user(name);

  return u ? u : hash_find_localuser(name);
}

IRC_User* irc_FindLocalUser(char *name)
{
  return hash_find_localuser(name);
}

/* returns first element on the to global list */
IRC_User* irc_GetGlobalList(IRC_UserList* ul)
{
  ul->ltype = LT_GLOBAL;
  ul->currpos = GlobalUserList;
  return GlobalUserList;
}

/* get next item on the global user list */
IRC_User* irc_GetNextUser(IRC_UserList* ul)
{
  /* global list handling */
  if(ul->ltype==LT_GLOBAL)
    {
      if(ul->currpos==NULL)
        return NULL; 
      ul->currpos=ul->currpos->glnext;
      return ul->currpos;
    }
  return NULL;
}

/* creates a new user strucuture */
IRC_User 
*irc_CreateUser(char *nick, char *username, char *host, char *phost, 
	char *info, char* umode, char *servername)
{
  IRC_User* u;
  u = malloc(sizeof(IRC_User));
  bzero(u, sizeof(IRC_User));
  strncpy(u->nick, nick, NICKLEN);  
  strncpy(u->username, username, USERLEN);
  strncpy(u->realhost, host, HOSTLEN);
  strncpy(u->publichost, phost, HOSTLEN);
  strncpy(u->info, info, REALLEN);
  u->msglist = NULL;  
  u->fcount = 0;
  if(servername)
    u->server = irc_FindServer(servername);
  else
    u->server = NULL;  
  umode_update(umode, u); /* update user modes */
  return u;
}

/* creates a new user strucuture and add it to the local user hash */
IRC_User 
*irc_CreateLocalUser(char *nick, char *username, char *host, char *phost, 
	char *info, char* umode)
{
  IRC_User* u;  
  if((u = irc_FindUser(nick)))
  {
    if(irc_IsLocalUser(u))
    {
      fprintf(ircslogf,"Attempt to recreate local user %s !\n", nick);
      return u;
    }
    else    
      irc_Kill(u, irc_LocalServer, "Service override, local user");
  }
  u = irc_CreateUser(nick, username, host, phost, info, umode, NULL);
  u->iflags |= IFL_LOCAL;
  add_to_localuser_hash_table(nick, u);

#ifdef IRCD_PLEXUS
  applyUniqueTsId(u);
#endif

  if(irc_ConnectionStatus() > 0)
    irc_IntroduceUser(u);
  return u;
}

void irc_SendNotice(IRC_User *to, IRC_User *from, char *fmt, ...)
{
  char buf[512];
  va_list args;
  
  va_start(args, fmt);
  vsnprintf(buf, sizeof(buf), fmt, args);
  sendto_ircd(from->nick, "NOTICE %s :%s", to->nick, buf);
  va_end(args);
}

void irc_SendMsg(IRC_User *to, IRC_User *from, char *fmt, ...)
{
  char buf[512];
  va_list args;
  
  va_start(args, fmt);
  vsnprintf(buf, sizeof(buf), fmt, args);
  sendto_ircd(from->nick, "PRIVMSG %s :%s", to->nick, buf);
  va_end(args);
}

void irc_SendCNotice(IRC_Chan *to, IRC_User *from, char *fmt, ...)
{
  char buf[512];
  va_list args;
  
  va_start(args, fmt);
  vsnprintf(buf, sizeof(buf), fmt, args);
  sendto_ircd(from->nick, "NOTICE %s :%s", to->name, buf);
  va_end(args);
}

void irc_SendCMsg(IRC_Chan *to, IRC_User *from, char *fmt, ...)
{
  char buf[512];
  va_list args;
  
  va_start(args, fmt);
  vsnprintf(buf, sizeof(buf), fmt, args);
  sendto_ircd(from->nick, "PRIVMSG %s :%s", to->name, buf);
  va_end(args);
}

void irc_SendONotice(IRC_Chan *to, IRC_User *from, char *fmt, ...)
{
  char buf[512];
  va_list args;
  
  va_start(args, fmt);
  vsnprintf(buf, sizeof(buf), fmt, args);
  sendto_ircd(from->nick, "NOTICE @%s :%s", to->name, buf);
  va_end(args);
}

void irc_GlobalNotice(IRC_User *from, char *mask, char *fmt, ...)
{
  char buf[512];
  va_list args;
  
  va_start(args, fmt);
  vsnprintf(buf, sizeof(buf), fmt, args);
  sendto_ircd(from->nick, "NOTICE $*%s :%s", mask, buf);
  va_end(args);
}

void irc_GlobalMessage(IRC_User *from, char *mask, char *fmt, ...)
{
  char buf[512];
  va_list args;
  
  va_start(args, fmt);
  vsnprintf(buf, sizeof(buf), fmt, args);
  sendto_ircd(from->nick, "PRIVMSG $*%s :%s", mask, buf);
  va_end(args);
}

/* This command will send the required NNICK for user
 * It is safe for services to always send NNICKS instead of SNICKS
 * we will also send NCHANS for the chans the user is joining
 */
void irc_IntroduceUser(IRC_User* u)
{

#ifdef IRCD_PLEXUS
/*
  if (HasID(target_p) && IsCapable(client_p, CAP_TS6))
    sendto_one(client_p, ":%s UID %s %d %lu %s %s %s %s %s :%s",
               target_p->servptr->id,
               target_p->name, target_p->hopcount + 1,
               (unsigned long) target_p->tsinfo,
               ubuf, target_p->username, target_p->host,
               (MyClient(target_p) && IsIPSpoof(target_p)) ?
#ifndef PLEXUS
               "0" : target_p->sockhost, target_p->id, target_p->info);
#else
               "0" : target_p->sockhost, target_p->id, svsts, realhost target_p->info);
#endif
* 
* so we have there
* :37Z UID openglx 1 1236816997 +aiow openglx I.still.hate.packets 0 37ZAAAAAB :openglx
*
*/

  sendto_ircd(NULL,
	":%s UID %s %d %lu %s %s %s %s %s %ld %s :%s",
	myserversid,
	u->nick,
	1,
	time(NULL),
	umode_string(u->umodes), 
	u->username,
	u->publichost,
	u->realhost,
	u->uid,
	u->ts,
	u->realhost,
	u->info);
#else
  sendto_ircd(NULL,
    "NICK %s %d %lu +%s %s %s %s %s :%s",
    u->nick, 
    1,
    time(NULL),
    umode_string(u->umodes),
    u->username,
    u->realhost,
    u->publichost,
    myservername,
    u->info);
#endif

  send_user_njoins(u);
}

/* quits local user with msg */
void irc_QuitLocalUser(IRC_User* u, char *msg)
{
  sendto_ircd(u->nick,"QUIT :%s", msg ? msg : "");
  remove_local_user(u);
}

/* adds an user to the global list */
void add_user_to_global_list(IRC_User *user)
{
  user->glnext = GlobalUserList;
  user->glprev = NULL;
  if(GlobalUserList)   
    GlobalUserList->glprev=user;    
  GlobalUserList = user;
}

/* deletes an user from the global list */
void del_user_from_global_list(IRC_User* user)
{
  if(user->glprev)
    user->glprev->glnext=user->glnext;
  if(user->glnext)
    user->glnext->glprev=user->glprev;
  if(user==GlobalUserList)
    GlobalUserList=user->glnext;
}


void irc_Kill(IRC_User* u, IRC_User *s, char *msg)
{
  if(irc_IsLocalUser(u))
    return;
  sendto_ircd(s->nick,"KILL %s :%s", u->nick, msg ? msg : "");
  irc_CallEvent(ET_KILL, u, s);
  remove_remote_user(u);
}

void irc_Gline(IRC_User* s, char *who, char *mask, int duration, char *msg)
{
  sendto_ircd(s->nick, "GLINE %s %d %s :%s", mask, duration, who, msg);
}


/* send svs mode for nick */
void irc_SvsMode(IRC_User* u, IRC_User *s, char *mchange)
{
#ifndef IRCD_PLEXUS
  sendto_ircd(s->nick,"SVSMODE %s :%s", u->nick, mchange);
#else
  sendto_ircd(s->nick,"ENCAP * SVSMODE %s %ld :%s", u->nick, (long) u->ts, mchange);
#endif
}

/* send a svs join */
void irc_SvsJoin(IRC_User* u, IRC_User *s, char *channel)
{
#ifndef IRCD_PLEXUS
    sendto_ircd(s->nick,"SVSJOIN %s :%s", u->nick, channel);
#else
    sendto_ircd(s->nick,"ENCAP * SVSJOIN %s :%s", u->nick, channel);
#endif
}

/* send a svs part */
void irc_SvsPart(IRC_User *u, IRC_User *s, char *channel)
{
    sendto_ircd(s->nick, "SVSPART %s :%s", u->nick, channel);
}

/* send a svs nick change */
void irc_SvsNick(IRC_User* u, IRC_User *s, char *newnick)
{
#ifndef IRCD_PLEXUS
  sendto_ircd(s->nick,"SVSNICK %s :%s", u->nick, newnick);
#else
  time_t now = time(NULL);
  sendto_ircd(s->nick,"ENCAP * SVSNICK %s %ld %s %ld", u->nick, (long int) u->ts, newnick, (long int) now);
  u->ts = (long int) now;
#endif
}

/* send a svs guest */
void irc_SvsGuest(IRC_User* u, IRC_User *s, char *prefix, int number)
{ 
  u->guest_count++;
  sendto_ircd(s->nick,"SVSGUEST %s %s %d", u->nick, prefix, number);
}

/* sends a sanotice */
void irc_SendSanotice(IRC_User* from, char *fmt, ...)
{
  char buf[512];
  va_list args;
  
  va_start(args, fmt);
  vsnprintf(buf, sizeof(buf), fmt, args);
  sendto_ircd(from->nick, "SANOTICE :%s", buf);
  va_end(args);
}

/* delete user info from all channels */
void del_user_chans(IRC_User* user){
 IRC_UserNode *un;

 while((un = user->chanlist))
  {
     user->chanlist = un->next;
     del_user_from_chan(user, un->chan);
     free(un);
  }
 user->chanlist = NULL;
}


/* returns the full mask of an user */
char* irc_UserMask(IRC_User* user)
{
  static char mask[NICKLEN+USERLEN+HOSTLEN+3];
  snprintf(mask, NICKLEN+USERLEN+HOSTLEN+3, "%s!%s@%s", user->nick, user->username, user->realhost);
  return mask;
}

/* returns the full mask of an user (with the public host)*/
char* irc_UserMaskP(IRC_User* user)
{
  static char mask[NICKLEN+USERLEN+HOSTLEN+3];
  snprintf(mask, NICKLEN+USERLEN+HOSTLEN+3, "%s!%s@%s", user->nick, user->username, user->publichost);
  return mask;
}

/* returns the short (user/host) mask of an user */
char* irc_UserSMask(IRC_User* user)
{
  static char mask[USERLEN+HOSTLEN+3];
  snprintf(mask, USERLEN+HOSTLEN+3, "%s@%s", user->username, user->realhost);
  return mask;
}

void irc_UserStats(IRC_User *to, IRC_User* from)
{
  IRC_UserList gl;
  IRC_User* user;
  u_int32_t count = 0;

  user = irc_GetGlobalList(&gl);
  while(user)
  {
    ++count;
    user = irc_GetNextUser(&gl);
  }
  irc_SendNotice(to, from,
    "  Users on global list: %d [%.1f KBytes]",
    count, (count*sizeof(IRC_User))/1024.0);
}

void irc_ChgHost(IRC_User* to, char *vhost)
{
#ifndef IRCD_PLEXUS
  sendto_ircd(NULL, "CHGHOST %s %s", to->nick, vhost);
#else
  sendto_ircd(NULL, "ENCAP * CHGHOST %s %s", to->nick, vhost);
#endif
  strncpy(to->publichost, vhost, HOSTLEN);
}

#ifdef IRCD_PLEXUS
void irc_ChgIdent(IRC_User* to, char *vhost)
{
  sendto_ircd(NULL, "ENCAP * CHGIDENT %s %s", to->nick, vhost);
  strncpy(to->username, vhost, HOSTLEN);
}

void irc_SendGlobops(IRC_User* from, char *fmt, ...)
{
  char buf[512];
  va_list args;

  va_start(args, fmt);
  vsnprintf(buf, sizeof(buf), fmt, args);
  sendto_ircd(from->nick, "GLOBOPS :%s", buf);
  va_end(args);
}

#endif

/* 
 * valid_hostname - check hostname for validity
 *
 * Inputs       - pointer to user
 * Output       - 1 for valid, 0 for invalid
 *
 * NOTE: this doesn't allow a hostname to begin with a dot and
 * will not allow more dots than chars.
 */
int irc_IsValidHostname(const char* hostname)
{
  int         dots  = 0;
  int         chars = 0;
  const char* p     = hostname;

  assert(0 != p);

  if ('.' == *p)
    return 0;

  while (*p) {
    if (!IsHostChar(*p))
      return 0;
    if ('.' == *p || ':' == *p)
    {
      ++p;
      ++dots;
    }
    else
    {
      ++p;
      ++chars;
    }
  }
  return ( 0 == dots || chars < dots) ? 0 : 1;
}

/* 
 * valid_username - check username for validity
 *
 * Inputs       - username
 * Output       - 1 for valid, 0 for invalid
 * 
 * Absolutely always reject any '*' '!' '?' '@' '.' in an user name
 * reject any odd control characters names.
 */
int irc_IsValidUsername(const char* username)
{
  const char *p = username;
  assert(0 != p);

  if (*p=='\0')
  	return 0;  

  if ('~' == *p)
    ++p;
        
  while (*p) 
	{
  	  if (!IsUserChar(*p))
    	return 0;
		
	  ++p;
  }
  return 1;
}

int irc_IsValidNick(const char* nick)
{
  const char* ch   = nick;
  const char* endp = ch + NICKLEN;
      
  if (*nick == '-' || IsDigit(*nick)) /* first character in [0..9-] */
    return 0;
            
  for ( ; ch < endp && *ch; ++ch) 
  {
    if (!IsNickChar(*ch))
     return 0;
  }
                            
  return 1;
}
