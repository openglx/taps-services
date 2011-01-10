/******************************************************************
 * PTlink Services is (C) CopyRight PTlink IRC Software 1999-2006 *
 *                http://software.pt-link.net                     *
 * This program is distributed under GNU Public License           *
 * Please read the file COPYING for copyright information.        *
 ******************************************************************
                                                                                
  Description: botserv global chan !kick command

  $Id: bs_g_kick.c 33 2010-05-10 02:46:01Z openglx $                                                                                
*/
#include "module.h"
#include "encrypt.h"
#include "nickserv.h"
#include "chanserv.h"
#include "chanrecord.h"
#include "my_sql.h"
#include "cs_role.h"
#include "nsmacros.h"
#include "nickserv.h"
#include "dbconf.h"
/* lang files */
#include "lang/common.lh"
#include "lang/cscommon.lh"
#include "lang/cs_kick.lh"

SVS_Module mod_info =
/* module, version, description */
{"bs_g_kick", "1.0", "botserv !kick command" };

/*
  ChangeLog
  V1.0 - shameless copy from opdeop -- openglx
 */

/* external functions we need */
ServiceUser* (*botserv_suser)(void);
ServiceUser* (*chanserv_suser)(void);
int (*role_with_permission)(u_int32_t scid, u_int32_t snid, int permission);
int mysql_connection;
int bs_log;

MOD_REQUIRES
   MOD_FUNC(botserv_suser)
   MOD_FUNC(dbconf_get)
   MOD_FUNC(chanserv_suser)
   MOD_FUNC(role_with_permission)
   MOD_FUNC(dbconf_get_or_build)
   MOD_FUNC(mysql_connection)
MOD_END

/* internal functions */

/* available commands from module */
void bs_g_kick(IRC_User *s, IRC_User *u);

/* Remote config */
static int NeedsAuth;
DBCONF_REQUIRES
  DBCONF_GET("chanserv", NeedsAuth)
DBCONF_END

static char* ChanTriggerKICK;
DBCONF_PROVIDES
  DBCONF_WORD_OPT(ChanTriggerKICK, "!kick", "Channel trigger to !kick command")
DBCONF_END

/* Local settings */

/* this is called before load and at services rehash */
int mod_rehash(void)
{
  if(dbconf_get(dbconf_requires) < 0 )
  {
    errlog("Error reading dbconf!");
    return -1;
  }
  if(dbconf_get_or_build(mod_info.name, dbconf_provides) < 0 )
  {
    errlog("Error reading dbconf!");
    return -1;
  }

  return 0;
}

ServiceUser* bsu;

int mod_load(void)
{
  bsu = botserv_suser();

  if (ChanTriggerKICK)
	irc_AddChanGMsgEvent(ChanTriggerKICK, bs_g_kick, 0);
  else
	irc_AddChanGMsgEvent("!kick", bs_g_kick, 0);

  /* suser_add_cmd(bsu, "HELP", bs_help, HELP_SUMMARY, HELP_HELP);  */
  return 0;
}

void mod_unload(void)
{
 /* suser_del_mod_cmds(bsu, &mod_info); */

  if (ChanTriggerKICK)
	irc_DelChanGMsgEvent(ChanTriggerKICK, bs_g_kick);
  else
	irc_DelChanGMsgEvent("!kick", bs_g_kick);
}
 
/*
 * this is a shamless copy from bs_g_opdeop, look there to know how we made it
 * -- openglx
 * */

/* s = service the command was sent to
   u = user the command was sent from */
void bs_g_kick(IRC_User *s, IRC_User *u)
{
  u_int32_t source_snid;
  ChanRecord* cr;
  IRC_Chan* chan;
  IRC_ChanNode* cn;
  char *chname;
  IRC_User *bot;

  char *target;
  IRC_User *targetu;

  char *reason;

  cr = NULL;
  chname = NULL;

  chname = ((IRC_Chan*)s)->name;

  /* if there's no such channel, just return quietly */
  if((chan = irc_FindChan(chname)) == NULL)
    return;

  /* answer using the same user */
  bot = chan->local_user ? chan->local_user : bsu->u;
  
  /* is there a target? */
  target = strtok(NULL, " ");
  if (target)
  {
    if((targetu = irc_FindUser(target)) == NULL)
    {
	send_lang(u,bot, NICK_X_NOT_ONLINE, target);
	return;
    }	
  }
  else
  {
	targetu = u;
	target = u->nick;
  }

  if (targetu != u)
	reason = strtok(NULL, "");
  else
	reason = NULL;

  CHECK_IF_IDENTIFIED_NICK
  if(NeedsAuth && !IsAuthenticated(u))
    send_lang(u, bot, NEEDS_AUTH_NICK);
  else
  if(irc_IsUMode(targetu, UMODE_STEALTH) || (cn = irc_FindOnChan(chan, targetu)) == NULL)
    send_lang(u, bot, NICK_X_NOT_ON_X, target, chname);
  else  
  if(cn->cumodes & CU_MODE_ADMIN)
    send_lang(u, bot, CANT_KICK_ADMIN_X_ON_X, target, chname);
  else
  if((cr = chan->sdata) == NULL)
    send_lang(u, bot, CHAN_X_NOT_REGISTERED, chname);
  else /* everything is valid */
  if(role_with_permission(cr->scid, source_snid, P_KICK) == 0)
    send_lang(u, bot, NO_KICK_PERM_ON_X, chname);
  else
    {
      if(IsOpNotice(cr))
        irc_SendONotice(chan, bot, "%s used !kick %s BotServ command on %s",
          u->nick, target, chname);      

      if(reason)
        irc_Kick(bot, chan, targetu, "%s", reason);
      else
        irc_Kick(bot, chan, targetu, NULL);
    }

}


