/*
 *  $Id: channel.h 33 2010-05-10 02:46:01Z openglx $
 */ 
IRC_Chan* irc_CreateChan(char *name);
IRC_ChanNode* add_user_to_chan(IRC_User* user, IRC_Chan *chan, int cumodes);
IRC_UserNode* add_chan_to_user(IRC_Chan* chan, IRC_User *user, int cumodes);
void del_user_from_chan(IRC_User *user, IRC_Chan *chan);
void del_chan_from_user(IRC_Chan* chan, IRC_User *user);
void channel_mode(int parc,char *parv[], int check_mlock);
void send_user_njoins(IRC_User* u);
char *cmode_string(IRC_Chan *chan);

/* m_commands */
void m_sjoin(int parc,char *parv[]);
void m_part(int parc,char *parv[]);
void m_topic(int parc,char *parv[]);
void m_kick(int parc,char *parv[]);

