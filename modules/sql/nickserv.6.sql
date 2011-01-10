# $Id: nickserv.6.sql 33 2010-05-10 02:46:01Z openglx $

# Add t_expire and publichost
ALTER TABLE nickserv
  ADD COLUMN vhost varchar(64) default NULL AFTER publichost,
  ADD COLUMN favlink varchar(64) default NULL AFTER url;
