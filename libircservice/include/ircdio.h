/*****************************************************************
 * ircservicelib is (C) CopyRight PTlink IRC Software 1999-2002   *
 * http://www.ptlink.net/Coders/ - coders@PTlink.net             *
 * This program is distributed under GNU Public License          *
 * Please read the file COPYING for copyright information.       *
 *****************************************************************
 
  Description: ircd I/O header file
  
 *  $Id: ircdio.h 33 2010-05-10 02:46:01Z openglx $  
*/

#define INBUFFER_SIZE 0xffff
#define IRC_READ_TIMEOUT 300

int check_ircd_buffer(void);
void ircd_connect(void);
void ircd_buff_init(void);
void introduce_user(char* nick, char *user, char *host, char *info, char *umodes);

#define TS_CURRENT      10  /* current TS protocol version */
#define TS_MIN          9  	/* minimum supported TS protocol version */
