#include "ircservice.h"
#include "irc_string.h"
#include "event.h"
#include "common.h"
#include "hash.h"
#include "user.h" /* we need remove_user() */

IRC_Server *irc_LocalServer;

/* internal functions */
#ifdef IRCD_PLEXUS
static IRC_Server *irc_RemotePeer = NULL;
void m_sid(int parc, char *parv[]);
#endif
void m_server(int parc, char *parv[]);
void m_squit(int parc, char *parv[]);
void del_all_from_server(IRC_Server *serv);

#ifdef IRCD_PLEXUS
/*
       parc[0]="(null)" (ignored, no source)
       parc[1]="servpass" (ignored, the connection password)
       parc[2]="TS" (ignored, a keyword)
       parc[3]="6" (ignored, the CURRENT_TS for remote server)
       parc[4]="37Z"
 */
void m_pass(int parc,char *parv[])
{
  IRC_Server* nserver;
  IRC_Server* from = NULL;
  char *sid;
  /* validations */
  sid = parv[4];    
  if(parv[0])
    {
      fprintf(ircslogf,"PASS from known source %s?? IGNORED!\n", parv[0]);
      return;
    }
  if(irc_FindServer(sid) != NULL)
    {
      fprintf(ircslogf,"Ignoring duplicated server %s from %s", 
        sid, from->sname);
      return;
    }
  /* create the new server structure */
  if (irc_RemotePeer == NULL)
  {
	  nserver = malloc(sizeof(IRC_Server));
	  bzero(nserver, sizeof(IRC_Server));    
          irc_RemotePeer = nserver;
  }
  else
  {
	nserver = irc_RemotePeer;
  }

  strncpy(nserver->sid, sid, IRC_MAXSID);
  /*Don't change it with SID: nserver->sname = strdup(name);*/
  nserver->from = from;    
  	
  /*Don't change it with SID:
  irc_CallEvent(ET_NEW_SERVER, nserver, nserver);  */
  add_to_uid_hash_table(sid, nserver);
  /* add_user_to_global_list(nserver); */

}

/*
Parsing: :37F SID chaos.arpa 2 37G :hybrid-7 test server

        parv[0] = our peer SID (37F)
	parv[1] = actual new server name (chaos.arpa)
        parv[2] = hop count (>1)
	parv[3] = actual new server SID (37G)
        parv[4] = server description (hybrid-7 test server)
*/
void m_sid(int parc,char *parv[])
{
	IRC_Server* nserver;
	IRC_Server* from = NULL;
	char *name;
	char *sid;
	/*int i;*/

	/* validations */
	if (parc < 4)
		return;

/*	fprintf(ircslogf,"SID recebido... (");
	for(i=0; i<parc; i++)
		fprintf(ircslogf, "%s,", parv[i]);
	fprintf(ircslogf,"**)\n");*/

	/* we need to add both name and SID... beware to release these on squit!
         * I'm actually removing the entry from hash table at remove_remote_user
         * -- openglx
         */
	name = parv[1];
	sid = parv[3];

	if (parv[0])
		from = irc_FindServer(parv[0]);

	if (parv[0] && (from == NULL))
	{
		fprintf(ircslogf,"SID from non-existent server %s\n",
			parv[0]);
		return;
	}

	if (irc_FindServer(name) != NULL)
	{
		fprintf(ircslogf, "Ignoring duplicated server %s from %s\n",
			name, from->sname);
		return;
	}

	if (irc_FindServer(sid) != NULL)
	{
		fprintf(ircslogf, "Ignoring duplicated SID %s from %s\n",
			sid, from->sname);
		return;
	}

	/* create the new server structure for 'name'.. */
	nserver = malloc(sizeof(IRC_Server));
	bzero(nserver, sizeof(IRC_Server));    
	strncpy(nserver->nick, name, NICKLEN);
	nserver->sname = strdup(name);
	nserver->from = from;
	strncpy(nserver->sid, sid, IRC_MAXSID);

	irc_CallEvent(ET_NEW_SERVER, nserver, nserver);  
	add_to_user_hash_table(name, nserver);

	if (irc_FindServer(sid) == NULL)
		add_to_uid_hash_table(sid, nserver);

	/* add_user_to_global_list(nserver); */

	return;
}
#endif

/*
        parv[1] = server name
        parv[2] = hop count (1 since we are directly connected)
        parv[3] = server version
        parv[4] = server description
*/
void m_server(int parc,char *parv[])
{
  IRC_Server* nserver;
  IRC_Server* from = NULL;
  char *name;

	int i;
	fprintf(ircslogf,"SERVER recebido... (");
	for(i=0; i<parc; i++)
		fprintf(ircslogf, "%s,", parv[i]);
	fprintf(ircslogf,"**)\n");

  /* validations */
/*  if(parc<5)
    return;*/
  name = parv[1];    
  if(parv[0])
    from = irc_FindServer(parv[0]);
  if(parv[0] && (from == NULL))
    {
      fprintf(ircslogf,"SERVER from non-existent server %s\n", parv[0]);
      return;
    }
  if(irc_FindServer(name) != NULL) 
    {
      fprintf(ircslogf,"Ignoring duplicated server %s from %s", 
        name, from->sname);
      return;
    }
  /* create the new server structure */
#ifdef IRCD_PLEXUS
  if (irc_RemotePeer == NULL)
  {
	  nserver = malloc(sizeof(IRC_Server));
	  bzero(nserver, sizeof(IRC_Server));    
          irc_RemotePeer = nserver;
  }
  else
  {
	nserver = irc_RemotePeer;
  }
#else
  nserver = malloc(sizeof(IRC_Server));
  bzero(nserver, sizeof(IRC_Server));
#endif

  strncpy(nserver->nick, name, NICKLEN);
  nserver->sname = strdup(name);
  nserver->from = from;    
  	
  irc_CallEvent(ET_NEW_SERVER, nserver, nserver);  
  add_to_user_hash_table(name, nserver);

  /* add_user_to_global_list(nserver); */
}

/*
 * m_squit - SQUIT message handler
 *	parv[0] = sender prefix
 *   	parv[1] = server name
 *      parv[2] = comment
 */     
void m_squit(int parc,char *parv[])
{
  IRC_Server *serv = irc_FindServer(parv[1]);

  if(serv == NULL) /* this should never happen*/
    {
      fprintf(ircslogf,"SQUIT for non-existen server %s\n", parv[1]);
      return;
    }

  fprintf(ircslogf,"SQUIT received for server %s\n", parv[1]);

  /* shouldn't this be here before? */
#ifdef IRCD_PLEXUS
  if((strcasecmp(serv->nick, myservername)==0) ||
     (strcasecmp(serv->nick, myserversid)==0))
#else
  if(strcasecmp(serv->nick, myservername)==0)
#endif
    {
      fprintf(ircslogf,"SQUIT for myself?? Shutting down...\n");
      exit(0);
    }

  del_all_from_server(serv);
  remove_remote_user(serv);
}

void del_all_from_server(IRC_Server *serv)
{
  IRC_UserList ul;
  IRC_User *user, *next;
  user = irc_GetGlobalList(&ul);
  
  /* delete all users from that server */
  while(user)
    {
      next = irc_GetNextUser(&ul);

      if((user->server == serv) || (user->from == serv))
          remove_remote_user(user);

      user = next;
    }
}

IRC_Server* irc_FindServer(char *name)
{
  return hash_find_server(name);
}


void add_me(void)
{
  IRC_Server* nserver;
  
  /* create the new server structure */
  nserver = malloc(sizeof(IRC_Server));
  bzero(nserver, sizeof(IRC_Server));    
  strncpy(nserver->nick, myservername, NICKLEN);
  nserver->sname = strdup(myservername);
  nserver->from = NULL;
  add_to_user_hash_table(myservername, nserver);
#ifdef IRCD_PLEXUS
  add_to_uid_hash_table(myserversid, nserver);
#endif
  /* add_user_to_global_list(nserver); */
  irc_LocalServer = nserver;
}
