/******************************************************************
 * PTlink Services is (C) CopyRight PTlink IRC Software 1999-2006 *
 *                http://software.pt-link.net                     *
 * This program is distributed under GNU Public License           *
 * Please read the file COPYING for copyright information.        *
 ******************************************************************
                                                                                
  Description: botserv global chan !op and !deop command

  $Id: bs_g_opdeop.c 33 2010-05-10 02:46:01Z openglx $                                                                                
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
#include "lang/cs_opdeop.lh"

SVS_Module mod_info =
/* module, version, description */
{"bs_g_opdeop", "1.1", "botserv !op and !deop command" };

/*
  ChangeLog
  V1.1 - making this thing really work -- openglx
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
void bs_g_op(IRC_User *s, IRC_User *u);
void bs_g_deop(IRC_User *s, IRC_User *u);

/* Remote config */
static int NeedsAuth;
DBCONF_REQUIRES
  DBCONF_GET("chanserv", NeedsAuth)
DBCONF_END

static char* ChanTriggerOP;
static char* ChanTriggerDEOP;
DBCONF_PROVIDES
  DBCONF_WORD_OPT(ChanTriggerOP, "!op", "Channel trigger to !op command")
  DBCONF_WORD_OPT(ChanTriggerDEOP, "!deop", "Channel trigger to !deop command")
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

  if (ChanTriggerOP)
	irc_AddChanGMsgEvent(ChanTriggerOP, bs_g_op, 0);
  else
	irc_AddChanGMsgEvent("!op", bs_g_op, 0);

  if (ChanTriggerDEOP)
	irc_AddChanGMsgEvent(ChanTriggerDEOP, bs_g_deop, 0);
  else
	irc_AddChanGMsgEvent("!deop", bs_g_deop, 0);

  /* suser_add_cmd(bsu, "HELP", bs_help, HELP_SUMMARY, HELP_HELP);  */
  return 0;
}

void mod_unload(void)
{
 /* suser_del_mod_cmds(bsu, &mod_info); */

  if (ChanTriggerOP)
	irc_DelChanGMsgEvent(ChanTriggerOP, bs_g_op);
  else
	irc_DelChanGMsgEvent("!op", bs_g_op);

  if (ChanTriggerDEOP)
	irc_DelChanGMsgEvent(ChanTriggerDEOP, bs_g_deop);
  else
	irc_DelChanGMsgEvent("!deop", bs_g_deop);

}
 
/* s = service the command was sent to
   u = user the command was sent from */
void bs_g_op(IRC_User *s, IRC_User *u)
{
/*  char *extra = strtok(NULL, "");
  printf("Got an !opme\n");
  if(extra)
    printf("Got !opme with %s\n", extra);*/

  u_int32_t source_snid;
  ChanRecord* cr;
  IRC_Chan* chan;
  IRC_ChanNode* cn;
  char *chname;
  IRC_User *bot;

  char *target;
  IRC_User *targetu;

  cr = NULL;
  chname = NULL;

  /* chname is actually from IRC_Chan, but we got here as IRC_User... gdb told me that!

#0  bs_g_opme (s=0x7c88c0, u=0x7c8c10) at bs_g_opme.c:52
        extra = 0x0
#1  0x000000000041309f in m_privmsg (parc=<value optimized out>, parv=0x771e60) at initconn.c:220
        dest = (IRC_Chan *) 0x7c88c0
        src = (IRC_User *) 0x7c8c10

   so we need a little hacking here, no?? :)
	-- openglx
  */

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

  CHECK_IF_IDENTIFIED_NICK
  if(NeedsAuth && !IsAuthenticated(u))
    send_lang(u, bot, NEEDS_AUTH_NICK);
  else
  if(irc_IsUMode(targetu, UMODE_STEALTH) || (cn = irc_FindOnChan(chan, targetu)) == NULL)
    send_lang(u, bot, NICK_X_NOT_ON_X, target, chname);
  else  
  if(cn->cumodes & CU_MODE_OP)
    send_lang(u, bot, NICK_X_ALREADY_OP_ON_X, target, chname);
  else
  if((cr = chan->sdata) == NULL)
    send_lang(u, bot, CHAN_X_NOT_REGISTERED, chname);
  else /* everything is valid */
  if(role_with_permission(cr->scid, source_snid, P_OPDEOP) == 0)
    send_lang(u, bot, NO_OPDEOP_PERM_ON_X, chname);
  else
    {
      if(IsOpNotice(cr))
        irc_SendONotice(chan, bot, "%s used !op %s BotServ command on %s",
          u->nick, target, chname);      
      irc_ChanUMode(bot, chan, "+o" , targetu);
    }

}

 
/* s = service the command was sent to
   u = user the command was sent from */
void bs_g_deop(IRC_User *s, IRC_User *u)
{
  /* just an ugly copy of _bs_g_op -- openglx */
  u_int32_t source_snid;
  ChanRecord* cr;
  IRC_Chan* chan;
  IRC_ChanNode* cn;
  char *chname;
  IRC_User *bot;

  char *target;
  IRC_User *targetu;

  cr = NULL;
  chname = NULL;

  chname = ((IRC_Chan*)s)->name;

  if((chan = irc_FindChan(chname)) == NULL)
    return;

  bot = chan->local_user ? chan->local_user : bsu->u;
  
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

  CHECK_IF_IDENTIFIED_NICK
  if(NeedsAuth && !IsAuthenticated(u))
    send_lang(u, bot, NEEDS_AUTH_NICK);
  else
  if(irc_IsUMode(targetu, UMODE_STEALTH) || (cn = irc_FindOnChan(chan, targetu)) == NULL)
    send_lang(u, bot, NICK_X_NOT_ON_X, target, chname);
  else  
  if(!(cn->cumodes & CU_MODE_OP))
    send_lang(u, bot, NICK_X_NOT_OP_ON_X, target, chname);
  else
  if(cn->cumodes & CU_MODE_ADMIN)
    send_lang(u, s, CANT_DEOP_ADMIN_X_ON_X, target, chname);
  else
  if((cr = chan->sdata) == NULL)
    send_lang(u, bot, CHAN_X_NOT_REGISTERED, chname);
  else /* everything is valid */
  if(role_with_permission(cr->scid, source_snid, P_OPDEOP) == 0)
    send_lang(u, bot, NO_OPDEOP_PERM_ON_X, chname);
  else
    {
      if(IsOpNotice(cr))
        irc_SendONotice(chan, bot, "%s used !deop %s BotServ command on %s",
          u->nick, targetu->nick, chname);      
      irc_ChanUMode(bot, chan, "-o" , targetu);
    }

}

