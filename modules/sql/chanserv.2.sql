# $Id: chanserv.2.sql 33 2010-05-10 02:46:01Z openglx $

# Replace the per table memo id to a per user memo id
ALTER TABLE chanserv
	ADD COLUMN t_ltopic_tmp INT AFTER t_ltopic,
	ADD COLUMN t_reg_tmp INT AFTER t_reg,
	ADD COLUMN t_last_use_tmp INT AFTER t_last_use,
	ADD COLUMN t_maxusers_tmp INT AFTER t_maxusers;

# Now lets convert the dates to unix timestamp
UPDATE chanserv SET
	t_ltopic_tmp = UNIX_TIMESTAMP(t_ltopic),
	t_reg_tmp = UNIX_TIMESTAMP(t_reg),
	t_last_use_tmp  = UNIX_TIMESTAMP(t_last_use),
	t_maxusers_tmp = UNIX_TIMESTAMP(t_maxusers);

ALTER TABLE chanserv
	DROP COLUMN t_ltopic,
	CHANGE t_ltopic_tmp t_ltopic INT NOT NULL,
	DROP COLUMN t_reg,
	CHANGE t_reg_tmp t_reg INT NOT NULL,
	DROP COLUMN t_last_use,
	CHANGE t_last_use_tmp t_last_use INT NOT NULL,
	DROP COLUMN t_maxusers,
	CHANGE t_maxusers_tmp t_maxusers INT NOT NULL;

# We need the binary bit for proper lookups
ALTER TABLE chanserv
	CHANGE name name varchar(32) BINARY NOT NULL;

