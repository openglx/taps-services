# $Id: os_sline.sql 33 2010-05-10 02:46:01Z openglx $

DROP TABLE IF EXISTS os_sline;
CREATE TABLE os_sline(
  id INT UNSIGNED NOT NULL auto_increment,
  letter CHAR(1) NOT NULL,
  who_nick VARCHAR(32) NOT NULL,
  mask VARCHAR(128) NOT NULL,
  t_create DATETIME NOT NULL,
  message VARCHAR(128) NOT NULL,  
  PRIMARY KEY (id),
  KEY id (id)
) Type = InnoDB;
