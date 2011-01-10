/**********************************************************************
 * PTlink IRC Services is (C) CopyRight PTlink IRC Software 1999-2006 *
 *                     http://software.pt-link.net                    *
 * This program is distributed under GNU Public License               *
 * Please read the file COPYING for copyright information.            *
 **********************************************************************

  Description: bl managment
  
*/

#include "module.h"
#include "my_sql.h"
#include "path.h"
#include "ns_group.h"
#include "lang/ns_blist.lh"
#include "nsmacros.h"

SVS_Module mod_info =
 /* module, version, description */
{"ns_blist", "1.0",  "nickserv blist module" };

#define DB_VERSION      1

/* Change Log 
  1.0 - initial version
*/

/** functions and events we require **/
ServiceUser* (*nickserv_suser)(void);
u_int32_t (*find_group)(char *name);


MOD_REQUIRES
  MOD_FUNC(nickserv_suser)  
  MOD_FUNC(is_sadmin)
  MOD_FUNC(find_group) 
MOD_END

/** functions and events we provide **/
/* void my_function(void); */
int forbidden_email(char *email);
int check_domain(char *email);
static void ns_blist_list(IRC_User *s, IRC_User *u);
static void ns_blist_del(IRC_User *s, IRC_User *u);
static void ns_blist_add(IRC_User *s, IRC_User *u);

MOD_PROVIDES
  MOD_FUNC(forbidden_email)
MOD_END

/** Internal functions declaration **/
void ns_blist(IRC_User *s, IRC_User *u);

/** Local variables **/
ServiceUser* nsu;
    
/** load code **/
int mod_load(void)
{
  int r;
  
  r = sql_check_inst_upgrade(mod_info.name, DB_VERSION, NULL);
  if(r < 0)
    return -2;
      
  nsu = nickserv_suser();
  suser_add_cmd_g(nsu, "BLIST", ns_blist, BLIST_SUMMARY, BLIST_HELP, find_group("Admin"));
  return 0;
}
    
/** unload code **/
void mod_unload(void)
{
  return;
}
  
/* checks if a given email is forbidden
   Returns:
        0 not forbidden
        !=0 is forbidden
 */
int forbidden_email(char *email)
{
  MYSQL_RES *res;
  MYSQL_ROW row;
  char *domain;
  int i;
  
  domain = strchr(email, '@');
  if(domain == NULL)
    return 0;
  
  res = sql_query("SELECT count(*) from ns_blist WHERE data=%s OR data=%s", 
    sql_str(email), sql_str(domain));
  if(res == NULL || ((row = sql_next_row(res)) == NULL))
    return 0;
  i = atoi(row[0]);
  sql_free(res);  
  return i;
}

int check_domain(char *email)
{
    char *domain;
    domain = strchr(email, '@');
    if(domain == NULL)
	return 0;
    else
	return 1;
}

void ns_blist(IRC_User* s, IRC_User* u)
{
    u_int32_t source_snid;
    
    CHECK_IF_IDENTIFIED_NICK
    
    if(!is_sadmin(source_snid))
	send_lang(u, s, ONLY_FOR_SADMINS);
    else
    {
	char* subcmd = strtok(NULL, " ");
	if(subcmd == NULL)
	    send_lang(u, s, NS_BLIST_SYNTAX);
	else if(strcasecmp(subcmd, "ADD") ==0)
	    ns_blist_add(s, u);
	else if(strcasecmp(subcmd, "DEL") == 0)
	    ns_blist_del(s, u);
	else if(strcasecmp(subcmd, "LIST") == 0)
	    ns_blist_list(s, u);
	else
	    send_lang(u, s, NS_BLIST_SYNTAX, irc_GetLastMsgCmd());
    }
}

static void ns_blist_add(IRC_User *s, IRC_User *u)
{
	char *target = strtok(NULL, " ");

	if(target == NULL)
		send_lang(u, s, NS_BLIST_ADD_SYNTAX);
	else if(check_domain(target) == 0)
		send_lang(u, s, NS_BLIST_INPUT_NOT_CORRECT, target);
	else if(sql_singlequery("SELECT data FROM ns_blist WHERE data='%s'", target) !=0)
		send_lang(u, s, NS_BLIST_X_ALREADY_ON_LIST, target);
	else
	{
		sql_execute("INSERT INTO ns_blist VALUES ('%s')", target);
		send_lang(u, s, NS_BLIST_X_ADD_TO_LIST, target);
	}
}

static void ns_blist_del(IRC_User *s, IRC_User *u)
{
	char *target = strtok(NULL, " ");
	
	if(target == NULL)
		send_lang(u, s, NS_BLIST_DEL_SYNTAX);
	else if(sql_singlequery("SELECT data FROM ns_blist WHERE data='%s'", target)==0)
		send_lang(u, s, NS_BLIST_NOT_ON_LIST, target);
	else
	{
		sql_execute("DELETE FROM ns_blist WHERE data='%s'", target);
		send_lang(u, s, NS_BLIST_TARGET_REMOVED, target);
	}
}

static void ns_blist_list(IRC_User *s, IRC_User *u)
{
    MYSQL_RES* res;
    MYSQL_ROW row;
    char sql[1024];
    int count = 0;
    char *c;
    char* mask;
    
    mask = strtok(NULL, " ");
    
    if(IsNull(mask))
    {
	send_lang(u, s, NS_BLIST_SYNTAX);
    }
    else
    {
	while((c=strchr(mask, '*'))) 
	    *c='%';
	snprintf(sql, sizeof(sql), "SELECT data FROM ns_blist WHERE data LIKE %s", sql_str(mask));
	res = sql_query("%s", sql); 
    
        send_lang(u, s, NS_BLIST_HEADER);
        while((row = sql_next_row(res)))
        {
    	    send_lang(u, s, NS_BLIST_ITEM_X, row[0]);
	    count++;
	}

	send_lang(u, s, NS_BLIST_TAIL, count);	
	sql_free(res);
    }
}
/* End of module */
