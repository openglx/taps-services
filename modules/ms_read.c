/**********************************************************************
 * PTlink IRC Services is (C) CopyRight PTlink IRC Software 1999-2005 *
 *                     http://software.pt-link.net                    *
 * This program is distributed under GNU Public License               *
 * Please read the file COPYING for copyright information.            
 **********************************************************************

  Description: Memoserv read command

 *  $Id: ms_read.c 33 2010-05-10 02:46:01Z openglx $
*/

#include "module.h"
#include "memoserv.h"
#include "my_sql.h"
#include "nsmacros.h"
#include "dbconf.h"
/* lang files */
#include "lang/common.lh"
#include "lang/ms_read.lh"
#include "lang/memoserv.lh"


SVS_Module mod_info =
 /* module, version, description */
{"ms_read", "2.2",  "memoserv read command" };

/* Change Log
  2.2 - issue #34 - memoserv read new/all
  2.1 - #69, memoserv expiration with save option
  2.0 - 0000265: remove nickserv cache system
*/  

/** functions and events we require **/
/* void (*FunctionPointer)(void);*/
ServiceUser* (*memoserv_suser)(void);

MOD_REQUIRES
  MOD_FUNC(memoserv_suser)
  DBCONF_FUNCTIONS
  MEMOSERV_FUNCTIONS
MOD_END


/** Internal functions declaration **/
/* void internal_function(void); */
void ms_read(IRC_User *s, IRC_User *u);
void set_read(u_int32_t id, u_int32_t owner_snid);
void single_memo_read(IRC_User *s, IRC_User *u, u_int32_t source_snid, int memo_index);
void multiple_memo_read(IRC_User *s, IRC_User *u, u_int32_t source_snid, int ALL_OR_NEW);

/** Local variables **/
/* int my_local_variable; */
ServiceUser* msu;
static int ExpireTime = 0;

DBCONF_REQUIRES
  DBCONF_GET("memoserv", ExpireTime)
DBCONF_END  

/* this is called before load and at services rehash */
int mod_rehash(void)
{
  if(dbconf_get(dbconf_requires) < 0 )
  {
    errlog("Error reading dbconf!");
    return -1;
  }
  return 0;
}
    
/** load code **/
int mod_load(void)
{
  msu = memoserv_suser();
  suser_add_cmd(msu, "READ", ms_read, READ_SUMMARY, READ_HELP);
  return 0;
}
    
/** unload code **/
void mod_unload(void)
{
  suser_del_mod_cmds(msu, &mod_info);
}
    
/** internal functions implementation starts here **/
void ms_read(IRC_User *s, IRC_User *u)
{
  u_int32_t source_snid;
  char* memolist;
  int memo_index;
  
  /* status validation */
  CHECK_IF_IDENTIFIED_NICK
  
  memolist = strtok(NULL, " ");
  
  /* syntax validation */
  if(IsNull(memolist))
    send_lang(u, s, READ_SYNTAX);
  else if((memo_index = atoi(memolist)) != 0)
    single_memo_read(s, u, source_snid, memo_index);
  else if (!strcasecmp(memolist, "ALL"))
    multiple_memo_read(s, u, source_snid, 0);
  else if (!strcasecmp(memolist, "NEW"))
    multiple_memo_read(s, u, source_snid, 1);
  else
   send_lang(u, s, READ_SYNTAX);
}

/* set a message as read */
void set_read(u_int32_t id, u_int32_t owner_snid)
{
  sql_execute("UPDATE memoserv SET FLAGS=FLAGS & %d WHERE owner_snid=%d AND id=%d",
    ~MFL_UNREAD, owner_snid, id);
}

/* generic memo read */
void single_memo_read(IRC_User *s, IRC_User *u, u_int32_t source_snid, int memo_index)
{
  /* check requirements */
  if(sql_singlequery("SELECT id, flags, t_send, sender_name, message FROM memoserv"
    " WHERE owner_snid=%d AND id=%d", source_snid, memo_index) == 0)
    send_lang(u, s, NO_SUCH_MEMO_X, memo_index);
  /* execute operation */
  else 
    {
      char buf[64];
      struct tm *tm;
      u_int32_t id;
      u_int32_t flags;
      time_t t_send = atoi(sql_field(2));
      id = atoi(sql_field(0));
      flags = atoi(sql_field(1));
      tm = localtime(&t_send);
      strftime(buf, sizeof(buf), format_str(u, DATE_FORMAT), tm);      
      send_lang(u, s, MEMO_READ_X, atoi(sql_field(0)), buf, sql_field(3), sql_field(4));
      set_read(id, source_snid);
      if(ExpireTime && !(flags & MFL_SAVED))
        send_lang(u, s, MS_READ_WILL_EXPIRE_ON_X_X, 
        ((ExpireTime-(irc_CurrentTime-t_send))/(24*3600))+1, id);
    }
}

/* read multiple entries */
void multiple_memo_read(IRC_User *s, IRC_User *u, u_int32_t source_snid, int ALL_OR_NEW)
{
  MYSQL_RES* res;
  MYSQL_ROW row;
  char sql[1024];
  int* memos_to_read;
  int i, count = 0;


  if (ALL_OR_NEW == 0)
  {
    count = memos_count(source_snid);
    snprintf(sql, sizeof(sql), "SELECT id FROM memoserv WHERE owner_snid=%d",
             source_snid);
  }
  else
  {
    count = unread_memos_count(source_snid);
    snprintf(sql, sizeof(sql), "SELECT id FROM memoserv WHERE owner_snid=%d"
       " AND flags & %d", source_snid, MFL_UNREAD);
  }

  if (count < 1)
  {
    send_lang(u, msu->u, YOU_HAVE_X_UNREAD_MEMOS, count);
    return;
  }

  res = sql_query("%s", sql);

  memos_to_read = (int *)malloc(count * sizeof(int));

  for (i = 0; i < count; i++)
   {
     row = sql_next_row(res);
     if (row)
       memos_to_read[i] = atoi(row[0]);
   }
   sql_free(res);

  for (i = 0; i < count; i++)
    single_memo_read(s, u, source_snid, memos_to_read[i]);

  free(memos_to_read);
}

/* End of module */
