/**********************************************************************
 * PTlink IRC Services is (C) CopyRight PTlink IRC Software 1999-2006 *
 *                     http://software.pt-link.net                    *
 * This program is distributed under GNU Public License               *
 * Please read the file COPYING for copyright information.            *
 **********************************************************************  

  Description: ns_buddy module
*/

#include "module.h"
#define BUDDY
#include "path.h"
#include "my_sql.h"
#include "dbconf.h"
#include "nsmacros.h"
#include "ns_buddy.h"
#include "lang/common.lh"
#include "lang/ns_buddy.lh"

/* module, version, description */
SVS_Module mod_info = {"ns_buddy", "1.0", "ns_buddy core module" };

#define DB_VERSION      1

/* ChangeLog
*/
  
/* functions and events we require */
int e_nick_identify;
int mysql_connection;
int e_expire = -1;
ServiceUser* (*nickserv_suser)(void);

MOD_REQUIRES
  MOD_FUNC(dbconf_get_or_build)
  MOD_FUNC(nickserv_suser)
  MOD_FUNC(e_nick_identify)
  MOD_FUNC(e_expire) /* we need this to run the expire routines */
MOD_END

/* functions and events we provide */
ServiceUser* ns_buddy_suser(void); /* the ns_buddy user */

MOD_PROVIDES
/*  BUDDY_FUNCTIONS */
MOD_END

/* Local config */
static int MaxBuddiesPerUser = 0;
static int ExpireTime = 0;

DBCONF_PROVIDES
  DBCONF_WORD(MaxBuddiesPerUser, "64",
    "Maximum number of buddies per nick")
  DBCONF_TIME(ExpireTime, "60d",
    "How long a buddy inivitation will be kept pending for accept")
DBCONF_END

/* internal variables */
static int ns_log = -1;
static ServiceUser* nsu;

/* internal functions */
static void ns_buddy(IRC_User *s, IRC_User *u);
static void ns_buddy_add(IRC_User *s, IRC_User *u);
static void ns_buddy_del(IRC_User *s, IRC_User *u);
static void ns_buddy_accept(IRC_User *s, IRC_User *u);
static void ns_buddy_list(IRC_User *s, IRC_User *u);

/* core events */
void ev_ns_buddy_nick_identify(IRC_User* u, u_int32_t *snid);
int ev_ns_buddy_expire(void* dummy1, void* dummy2);

/* commands */

int mod_rehash(void)
{
  if(dbconf_get_or_build(mod_info.name, dbconf_provides) < 0 )
  {
    errlog("Error reading dbconf!");
    return -1;
  }
  return 0;
}

int mod_load(void)
{
  /* first try to open the log file */
  ns_log = log_handle("nickserv");
    
  if(ns_log < 0)
  {
    errlog("Could not open ns_buddy log file!");
    return -1;
  }

  nsu = nickserv_suser();
  
  if(sql_check_inst_upgrade(mod_info.name, DB_VERSION, NULL) < 0 )
    return -4;
    
  /* Add user events */
  suser_add_cmd(nsu,
    "BUDDY", ns_buddy, NS_BUDDY_SUMMARY, NS_BUDDY_HELP);
    
  /* Add actions  */
#if 0  
  mod_add_event_action(e_nick_identify, (ActionHandler) ev_ns_buddy_nick_identify);
#endif

  if(ExpireTime == 0)
    stdlog(L_INFO, "ExpireTime is not set, nick buddy invitations will not expire");
  else
    mod_add_event_action(e_expire, (ActionHandler) ev_ns_buddy_expire);
  
  return 0;
}

void
mod_unload(void)
{
#if 0  
  mod_del_event_action(e_expire, (ActionHandler) ev_ns_buddy_nick_identify);
#endif  
  if(ExpireTime)
    mod_del_event_action(e_expire, (ActionHandler) ev_ns_buddy_expire);
  
}

/* ns_buddy main handler */
void ns_buddy(IRC_User* s, IRC_User* u)
{
  u_int32_t source_snid;
  
  CHECK_IF_IDENTIFIED_NICK  
  
  char* subcmd = strtok(NULL, " ");
  if(subcmd == NULL)
    send_lang(u, s, NS_BUDDY_SYNTAX, "");
  else
  if(strcasecmp(subcmd, "ADD") == 0)
    ns_buddy_add(s, u);
  else
  if(strcasecmp(subcmd, "DEL") == 0)
    ns_buddy_del(s, u);    
  else
  if(strcasecmp(subcmd, "ACCEPT") == 0)
    ns_buddy_accept(s, u);
  else
  if(strcasecmp(subcmd, "LIST") == 0)
    ns_buddy_list(s, u);
  else  
    send_lang(u, s, NS_BUDDY_SYNTAX, irc_GetLastMsgCmd());
}

static void ns_buddy_add(IRC_User *s, IRC_User *u)
{
  char *target = strtok(NULL, " ");
  u_int32_t t_snid;
  int count;
  
  /* required parameter */
  if(target == NULL)
    send_lang(u, s, NS_BUDDY_ADD_SYNTAX);
  else
  /* nick exists ? */
  if((t_snid = nick2snid(target)) == 0)
    send_lang(u, s, NICK_X_NOT_REGISTERED, target);
  else
  if(t_snid == u->snid)
    send_lang(u, s, NS_BUDDY_NOT_SELF);
  else
  /* check if target is already on the buddy list */
  if(sql_singlequery("SELECT source_snid FROM ns_buddy"
       " WHERE source_snid=%d and target_snid=%d", u->snid, t_snid) != 0)
    send_lang(u, s, NS_BUDDY_NICK_X_ALREADY_BUDDY, target);
  else
  /* check for own max buddies */
  if((count = buddies_count(u->snid)) >= MaxBuddiesPerUser)
    send_lang(u, s, NS_BUDDY_MAX_REACHED);
  else
  /* check for target max buddies */
  if((count = buddies_count(t_snid)) >= MaxBuddiesPerUser)
    send_lang(u, s, NS_BUDDY_X_MAX_REACHED, target);
  else
  
  {
    send_lang(u, s, NS_BUDDY_X_WAS_ADDED, target);
    /* we silently do nothing if the user is blocked */
    if(sql_singlequery("SELECT source_snid FROM ns_buddy"
      " WHERE source_snid=%d and target_snid=%d", t_snid, u->snid) == 0)
    {           
      if(buddy_add(u->snid, t_snid, BUDDY_INVITING) &&
        buddy_add(t_snid, u->snid, BUDDY_INVITED))
      {
        IRC_User* target_u = irc_FindUser(target);
        
        if(target_u)
          send_lang(target_u, s, NS_BUDDY_X_X_X_ADDED_YOU, 
            u->nick, u->nick, u->nick);
      }
      else
        send_lang(u, s, UPDATE_FAIL);      
    }
  }
}

static void ns_buddy_del(IRC_User *s, IRC_User *u)
{
  char *target = strtok(NULL, " ");
  u_int32_t t_snid;
  
  /* required parameter */
  if(target == NULL)
    send_lang(u, s, NS_BUDDY_DEL_SYNTAX);
  else
  /* nick exists ? */
  if((t_snid = nick2snid(target)) == 0)
    send_lang(u, s, NICK_X_NOT_REGISTERED, target);
  else
  /* check if target is already on the buddy list */
  if(sql_singlequery("SELECT source_snid FROM ns_buddy"
       " WHERE source_snid=%d and target_snid=%d", u->snid, t_snid) == 0)
    send_lang(u, s, NS_BUDDY_NICK_X_NOT_BUDDY, target);
  else
  {
    sql_execute("DELETE FROM ns_buddy WHERE source_snid=%d AND target_snid=%d",
      u->snid, t_snid);
    sql_execute("DELETE FROM ns_buddy WHERE target_snid=%d AND source_snid=%d"\
      " AND status<>%i",
      u->snid, t_snid, BUDDY_BLOCKED);
    send_lang(u, s, NS_BUDDY_X_REMOVED, target);
  }
}

static void ns_buddy_accept(IRC_User *s, IRC_User *u)
{
  char *target = strtok(NULL, " ");
  u_int32_t t_snid;
  
  /* required parameter */
  if(target == NULL)
    send_lang(u, s, NS_BUDDY_ACCEPT_SYNTAX);
  else
  /* nick exists ? */
  if((t_snid = nick2snid(target)) == 0)
    send_lang(u, s, NICK_X_NOT_REGISTERED, target);
  else
  /* check if target is already on the buddy list */
  if(sql_singlequery("SELECT source_snid FROM ns_buddy"\
       " WHERE source_snid=%d and target_snid=%d", t_snid, u->snid) == 0)
    send_lang(u, s, NS_BUDDY_NICK_X_NOT_BUDDY, target);
  else
  {
    sql_execute("UPDATE ns_buddy SET status=%i"\
      " WHERE source_snid=%d AND target_snid=%d ", BUDDY_ACCEPTED, u->snid, t_snid);
    sql_execute("UPDATE ns_buddy SET status=%i"\
      " WHERE source_snid=%d AND target_snid=%d", BUDDY_ACCEPTED, t_snid, u->snid);
    send_lang(u, s, NS_BUDDY_ACCEPTED_X, target);
  }
}

#if 0
void ev_ns_buddy_nick_identify(IRC_User* u, u_int32_t *snid)
{
  MYSQL_RES* res;
  MYSQL_ROW row;
  u_int32_t snid = *snid;
  int count= 0; 
  res = sql_query("SELECT ns.nick, nsb.status"
    " FROM ns_buddy nsb, nickserv ns"
    " WHERE nsb.source_snid=%d AND nsb.status=%i AND ns.snid=nsb.target_snid", 
      *snid, NS_BUDDY_STATUS_INVITED);  
  while((row = sql_next_row(res)))
  {
    if(count++ == 0)
      send_lang(u, s, NS_BUDDY_INVITED)    
    send_lang(u, s, NS_BUDDY_LIST_ITEM_X_X, row[0], status);  
  }
  sql_free(res);  
  send_lang(u, s, NS_BUDDY_LIST_TAIL);  
}

#endif
int ev_ns_buddy_expire(void* dummy1, void* dummy2)
{
  sql_execute("DELETE FROM ns_buddy WHERE (status=%i OR status=%i)"
  " AND t_when<%lu", BUDDY_INVITING, BUDDY_INVITED,
    irc_CurrentTime - ExpireTime);
  return 1;
}

/* return buddies for a given user */
int buddies_count(u_int32_t snid)
{
  MYSQL_RES* res;
  MYSQL_ROW row;
  int count = 0;
  res = sql_query("SELECT count(*) FROM ns_buddy  WHERE source_snid=%d", snid);
  row = sql_next_row(res);
  if(row)
    count = atoi(row[0]);
  sql_free(res);
  return count;
}

/* adds buddy_snid as buddy of target_snid */
int buddy_add(u_int32_t buddy_snid, u_int32_t target_snid, int status)
{
  return sql_execute("INSERT INTO ns_buddy VALUES(%d, %d, %d, %d)", 
    buddy_snid, target_snid, status, irc_CurrentTime);
}

static void ns_buddy_list(IRC_User *s, IRC_User *u)
{
  MYSQL_RES* res;
  MYSQL_ROW row;
  u_int32_t source_snid = u->snid;
  
  send_lang(u, s, NS_BUDDY_LIST_HEADER);
  res = sql_query("SELECT ns.nick, nsb.status"
    " FROM ns_buddy nsb, nickserv ns"
    " WHERE nsb.source_snid=%d AND ns.snid=nsb.target_snid", source_snid);  
  while((row = sql_next_row(res)))
  {
    char *status = "";
    switch(atoi(row[1]))
    {
      case BUDDY_INVITING: 
        status = lang_str(u, NS_BUDDY_STATUS_INVITING); 
        break;        
    }
    send_lang(u, s, NS_BUDDY_LIST_ITEM_X_X, row[0], status);  
  }
  sql_free(res);  
  send_lang(u, s, NS_BUDDY_LIST_TAIL);  
}
