# $Id: dbconf.sql 33 2010-05-10 02:46:01Z openglx $

DROP TABLE IF EXISTS dbconf;
CREATE TABLE dbconf(
  module varchar(32) NOT NULL,
  name varchar(64) NOT NULL,
  stype enum('int', 'switch', 'time', 'word', 'str') NOT NULL,
  ddesc varchar(255) NOT NULL,
  optional enum ('y', 'n') NOT NULL default 'y',
  configured enum ('y','n') NOT NULL default 'n',  
  value varchar(255),
  PRIMARY KEY (module, name)
) Type = InnoDB;
