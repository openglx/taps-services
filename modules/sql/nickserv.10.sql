ALTER TABLE nickserv
  ADD COLUMN network_email varchar(80) default NULL AFTER master_snid;
