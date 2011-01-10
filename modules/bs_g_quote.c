/******************************************************************
 * PTlink Services is (C) CopyRight PTlink IRC Software 1999-2006 *
 *                http://software.pt-link.net                     *
 * This program is distributed under GNU Public License           *
 * Please read the file COPYING for copyright information.        *
 ******************************************************************
                                                                                
  Description: botserv global chan !quote command

  $Id: bs_g_quote.c 33 2010-05-10 02:46:01Z openglx $                                                                                
*/
#include "module.h"
#include "encrypt.h"
#include "my_sql.h"
#include "nsmacros.h"
#include "nickserv.h"
#include "dbconf.h"
/* lang files */
#include "lang/common.lh"
#include "lang/cscommon.lh"
#include "lang/os_quote.lh"

SVS_Module mod_info =
/* module, version, description */
{"bs_g_quote", "1.0", "botserv !quote command" };

/*
  ChangeLog
  V1.0 - creating this modules, to show network quotes on channels (my idea is to allow channel-wide quotes in a near future) -- openglx
 */

/* external functions we need */
extern void send_msg(char *source, const char *target, const char *fmt, ...); /* actually we need a better function to send .... */
int mysql_connection;
int bs_log;

MOD_REQUIRES
   MOD_FUNC(dbconf_get)
   MOD_FUNC(dbconf_get_or_build)
   MOD_FUNC(mysql_connection)
MOD_END

/* internal functions */

/* available commands from module */
void bs_g_quote(IRC_User *s, IRC_User *u);

/* Remote config */
static char* ChanTrigger;
DBCONF_PROVIDES
  DBCONF_WORD_OPT(ChanTrigger, "!quote", "Channel trigger to !quote command")
DBCONF_END

/* Local settings */

/* this is called before load and at services rehash */
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
  if (ChanTrigger)
	irc_AddChanGMsgEvent(ChanTrigger, bs_g_quote, 0);
  else
	irc_AddChanGMsgEvent("!quote", bs_g_quote, 0);

  return 0;
}

void mod_unload(void)
{
 /* I'm sure we need a DelChanGMsgEvent somewhere too ... -- openglx */
  if (ChanTrigger)
	irc_DelChanGMsgEvent(ChanTrigger, bs_g_quote);
  else
	irc_DelChanGMsgEvent("!quote", bs_g_quote);
}
 
/* s = service the command was sent to
   u = user the command was sent from */
void bs_g_quote(IRC_User *s, IRC_User *u)
{
  IRC_Chan* chan;
  char *chname;
  IRC_User *bot;

  chname = NULL;

  /* to better understand what is being done here, look bs_g_opme module -- openglx */

  chname = ((IRC_Chan*)s)->name;

  if((chan = irc_FindChan(chname)) == NULL)
	return;
  
  /* answer using the same user */
  bot = chan->local_user;

  if(irc_IsUMode(u, UMODE_STEALTH))
	return;

  if(sql_singlequery("SELECT quote FROM os_quote ORDER BY RAND() LIMIT 1") > 0)
  {
    /* send_lang(u, bot, QUOTE_STR, sql_field(0)); */
    send_msg(bot->nick, chname, "%s", sql_field(0));
  }

  return;
}
