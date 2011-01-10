# $Id: recordstats.sql 33 2010-05-10 02:46:01Z openglx $

DROP TABLE IF EXISTS recordstats;
CREATE TABLE recordstats (
  day DATE NOT NULL,
  ns_total INT UNSIGNED NOT NULL,
  ns_new_irc INT NOT NULL,
  ns_new_web INT NOT NULL,
  ns_lost INT NOT NULL,
  cs_total INT UNSIGNED NOT NULL,
  cs_new_irc INT NOT NULL,
  cs_new_web INT NOT NULL,
  cs_lost INT NOT NULL,
  PRIMARY KEY(day)
) Type = InnoDB;
