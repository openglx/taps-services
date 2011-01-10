# $Id: cs_role.2.sql 33 2010-05-10 02:46:01Z openglx $

# Add an unique key to scid, name
ALTER TABLE cs_role
	ADD UNIQUE KEY(scid, name);

# Add a primary key on scid, snid and a status field
ALTER TABLE cs_role_users
	ADD PRIMARY KEY(scid, snid),
	ADD UNIQUE KEY (snid, rid),
	ADD COLUMN flags INT NOT NULL;
