/**********************************************************************
 * PTlink IRC Services is (C) CopyRight PTlink IRC Software 1999-2006 *
 *                     http://software.pt-link.net                    *
 * This program is distributed under GNU Public License               *
 * Please read the file COPYING for copyright information.            *
 **********************************************************************

  Description: record statistics gathering module

 *  $Id: recordstats.c 33 2010-05-10 02:46:01Z openglx $
*/

#include "module.h"
#include "my_sql.h"

SVS_Module mod_info =
 /* module, version, description */
{"recordstats", "2.0",  "record statistics module" };

#define	DB_VERSION 2

/* Change Log
  2.0   - 0000027: SVSINFO message always send 0 as peak user count
  1.0	- 0000331: recordstats module to save daly nick/chan records balance
*/

/** functions/events we require **/
/* void (*FunctionPointer)(void);*/
int e_nick_register = -1;
int e_nick_delete = -1;
int e_chan_register = -1;
int e_chan_delete = -1;
extern int e_complete;

MOD_REQUIRES
  MOD_FUNC(e_nick_register)
  MOD_FUNC(e_nick_delete)
  MOD_FUNC(e_chan_register)
  MOD_FUNC(e_chan_delete)
  MOD_FUNC(e_complete)
MOD_END


/** Internal functions declaration **/
/* void internal_function(void); */
void insert_today_stats();
int ev_recordstats_nick_register(IRC_User *u, u_int32_t *snid);
int ev_recordstats_nick_delete(u_int32_t *snid, void *dummy);
int ev_recordstats_chan_register(IRC_User *u, ChanRecord *cr);
int ev_recordstats_chan_delete(u_int32_t *snid, void *dummy);
int ev_recordstats_set_peak(void* dummy1, void* dummy2);

int get_peak_user(unsigned int *peakcnt, void *dummy);

/** Local variables **/
/* int my_local_variable; */

unsigned int all_time_peak = 0;

/** load code **/
int mod_load(void)
{
  int r;
  
  if(sql_check_inst_upgrade(mod_info.name, DB_VERSION, NULL) < 0)
    return -1;
    
  /* firs lets check if this is our first day run */    
  r = sql_singlequery("SELECT count(*) FROM recordstats WHERE day=CURDATE()");
  if( r < 1 || (sql_field_i(0) == 0)) /* first run  */
    insert_today_stats();

  /* setup the actions for the updates */
  mod_add_event_action(e_nick_register, 
    (ActionHandler) ev_recordstats_nick_register);
  mod_add_event_action(e_nick_delete, 
    (ActionHandler) ev_recordstats_nick_delete);
  mod_add_event_action(e_chan_register, 
    (ActionHandler) ev_recordstats_chan_register);
  mod_add_event_action(e_chan_delete, 
    (ActionHandler) ev_recordstats_chan_delete);    

  /* wait for complete startup and set peak, luckly before irc_StartConnect */
  mod_add_event_action(e_complete, (ActionHandler) ev_recordstats_set_peak);
  
  /* -- Thales - Adding event to get the value of Peak USER  Count */
  irc_AddEvent (ET_PEAKUSER, get_peak_user);
  return 0;
}
    
/** unload code **/
void mod_unload(void)
{
  irc_DelEvent (ET_PEAKUSER, get_peak_user);
  return;
}
    
/** internal functions implementation starts here **/
void insert_today_stats()
{
  u_int32_t ns_total = 0;
  u_int32_t ns_today = 0;
  u_int32_t cs_total = 0;
  u_int32_t cs_today = 0;
  sql_singlequery("SELECT count(*) FROM nickserv");
  ns_total = sql_field_i(0);
  sql_singlequery("SELECT count(*) FROM nickserv WHERE "
    "DATE_FORMAT(FROM_UNIXTIME(t_reg), '%s')=CURDATE()", "%Y-%m-%d");
  ns_today = sql_field_i(0);
  sql_singlequery("SELECT count(*) FROM chanserv");
  cs_total = sql_field_i(0);
  sql_singlequery("SELECT count(*) FROM chanserv WHERE "
    "DATE_FORMAT(FROM_UNIXTIME(t_reg), '%s')=CURDATE()", "%Y-%m-%d");
  cs_today = sql_field_i(0);
  sqlb_init("recordstats");
  
  sqlb_add_func("day", "CURDATE()");
  sqlb_add_int("ns_total", ns_total);
  sqlb_add_int("ns_new_irc", ns_today);
  sqlb_add_int("ns_new_web", 0);
  sqlb_add_int("ns_lost", 0);
  sqlb_add_int("cs_total", cs_total);
  sqlb_add_int("cs_new_irc", cs_today);
  sqlb_add_int("cs_new_web", 0);
  sqlb_add_int("cs_lost", 0);
  sqlb_add_int("all_time_peak", all_time_peak);
  
  sql_execute("%s", sqlb_insert());    
}

int ev_recordstats_nick_register(IRC_User *u, u_int32_t *snid)
{
  sql_execute("UPDATE recordstats SET ns_new_irc=ns_new_irc+1, ns_total=ns_total+1"
    " WHERE day=CURDATE()");
  return 0;
}

int ev_recordstats_chan_register(IRC_User *u, ChanRecord *cr)
{
  sql_execute("UPDATE recordstats SET cs_new_irc=cs_new_irc+1, cs_total=cs_total+1"
    " WHERE day=CURDATE()");
  return 0;
}

int ev_recordstats_nick_delete(u_int32_t *snid, void *dummy)
{  
  sql_execute("UPDATE recordstats SET ns_lost=ns_lost+1, ns_total=ns_total-1"
    " WHERE day=CURDATE()");
  return 0;
}

int ev_recordstats_chan_delete(u_int32_t *snid, void *dummy)
{  
  int r = sql_execute("UPDATE recordstats SET cs_lost=cs_lost+1, cs_total=cs_total-1"
    " WHERE day=CURDATE()");
  if(r == 0) /* this should only happen when we have a nick change */
    insert_today_stats();
  return 0;
}
    

int get_peak_user(unsigned int *peakcnt, void *dummy)
{
  char sql[1024];

  all_time_peak = *peakcnt;

  snprintf(sql, sizeof(sql), "UPDATE recordstats SET all_time_peak=%d"
         " WHERE day=CURDATE()", all_time_peak);

  sql_execute(sql);

  return 0;
}

int ev_recordstats_set_peak(void* dummy1, void* dummy2)
{
  sql_singlequery("SELECT MAX(all_time_peak) FROM recordstats");
  all_time_peak = sql_field_i(0);

  irc_SetPeak(all_time_peak);
  stdlog(L_INFO, "Current all time user peak is: %d\n", all_time_peak);

  return 0;
}

/* End of module */
