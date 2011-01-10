# $Id: os_quote.sql 33 2010-05-10 02:46:01Z openglx $

DROP TABLE IF EXISTS os_quote;
CREATE TABLE os_quote(
  id INT UNSIGNED NOT NULL auto_increment,
  who VARCHAR(32) NOT NULL,
  quote TEXT NOT NULL,
  PRIMARY KEY  (id)
) Type = InnoDB;
