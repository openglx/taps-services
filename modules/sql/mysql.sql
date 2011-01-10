# $Id: mysql.sql 33 2010-05-10 02:46:01Z openglx $

DROP TABLE IF EXISTS ircsvs_tables;
CREATE TABLE ircsvs_tables(
  name varchar(32) NOT NULL,
  version INT UNSIGNED NOT NULL,
  inst_time datetime NOT NULL
) Type = InnoDB;
