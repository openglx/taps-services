# $Id: ns_last.sql 33 2010-05-10 02:46:01Z openglx $
SET FOREIGN_KEY_CHECKS = 0;

DROP TABLE IF EXISTS ns_last;
CREATE TABLE ns_last
(
  snid INT UNSIGNED NOT NULL,
  web enum ('y', 'n') NOT NULL default 'y',
  t_when INT UNSIGNED NOT NULL,
  username varchar(16) default NULL,
  publichost varchar(64) default NULL,
  realhost varchar(64) default NULL,
  realname varchar(64) default NULL,
  INDEX(snid),
  CONSTRAINT FK_NSL1 FOREIGN KEY (snid) REFERENCES nickserv (snid) 
    ON DELETE CASCADE ON UPDATE CASCADE
) Type = InnoDB;

SET FOREIGN_KEY_CHECKS = 1;
