# $Id: nickserv.8.sql 33 2010-05-10 02:46:01Z openglx $

DROP TABLE IF EXISTS nickserv_suspensions;
CREATE TABLE nickserv_suspensions
(
  snid INT UNSIGNED NOT NULL,
  who varchar(32) NOT NULL,
  t_when INT UNSIGNED NOT NULL,
  duration INT UNSIGNED NOT NULL,
  reason VARCHAR(128) NOT NULL,
  PRIMARY KEY  (snid),
  CONSTRAINT FK_NSS1 FOREIGN KEY (snid) REFERENCES nickserv (snid)
) Type = InnoDB;
