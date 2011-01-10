# $Id: ns_blist.sql 33 2010-05-10 02:46:01Z openglx $

DROP TABLE IF EXISTS ns_blist;
CREATE TABLE ns_blist (
  data varchar(32) NOT NULL,
  PRIMARY KEY  (data)
) Type = InnoDB;