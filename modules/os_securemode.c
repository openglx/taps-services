/**********************************************************************
 * PTlink IRC Services is (C) CopyRight PTlink IRC Software 1999-2006 *
 *                     http://software.pt-link.net                    *
 * This program is distributed under GNU Public License               *
 * Please read the file COPYING for copyright information.            *
 **********************************************************************  
 
  Description: operserv securemode command
                                                                                
 *  $Id: os_securemode.c 33 2010-05-10 02:46:01Z openglx $
*/
#include "module.h"
#include "ns_group.h" /* we need is_sroot() */
#include "nsmacros.h"

#include "lang/os_securemode.lh"

SVS_Module mod_info =
/* module, version, description */
{ "os_securemode", "1.0", "operserv securemode command" };

/* Change Log
*/

/* external functions we need */
ServiceUser* (*operserv_suser)(void);

MOD_REQUIRES 
  MOD_FUNC(operserv_suser)
  MOD_FUNC(is_sroot)
  MOD_FUNC(is_soper)
MOD_END

/* internal functions */
       
/* available commands from module */
void os_securemode(IRC_User *s, IRC_User *u);

/* local variables */
ServiceUser *osu;
int os_log = 0;

int mod_load(void)
{
  os_log = log_handle("operserv");
  osu = operserv_suser();
  suser_add_cmd(osu, "SECUREMODE", os_securemode, SECUREMODE_SUMMARY, SECUREMODE_HELP);  
  return 0;
}

void
mod_unload(void)
{
  suser_del_mod_cmds(osu, &mod_info);
}

/* s = service the command was sent to
   u = user the command was sent from */
void os_securemode(IRC_User *s, IRC_User *u)
{
    u_int32_t source_snid;
    char *set = strtok(NULL, " ");
    
    CHECK_IF_IDENTIFIED_NICK
    
    if(is_sroot(source_snid)==0)
    {
	send_lang(u, s, SECUREMODE_NEEDS_ROOT);
	return;
    }
    
    if(IsNull(set))
    {
	send_lang(u, s, SECUREMODE_SYNTAX);
    }
    else if(strcasecmp(set, "on") == 0)
    {
	send_lang(u, s, SECUREMODE_ON);
	log_log(os_log, mod_info.name, "SECUREMODE turned ON by %s", u->nick);
    	irc_SendRaw(NULL, "SVSADMIN ALL SECUREMODE_ON");
    }
    else if(strcasecmp(set, "off") == 0)
    {
	send_lang(u, s, SECUREMODE_OFF);
	log_log(os_log, mod_info.name, "SECUREMODE turned OFF by %s", u->nick);
        irc_SendRaw(NULL, "SVSADMIN ALL SECUREMODE_OFF");
    }
    else
	send_lang(u, s, SECUREMODE_SYNTAX);
}
