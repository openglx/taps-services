# $Id: ns_group.3.sql 33 2010-05-10 02:46:01Z openglx $

# Add maxusers;
ALTER TABLE ns_group
	ADD COLUMN maxusers int(4) NOT NULL AFTER autoumodes;

# Add t_expire and maxusers
ALTER TABLE ns_group_users
	ADD COLUMN t_expire INT NOT NULL DEFAULT '0' AFTER snid;
