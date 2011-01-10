# $Id: memoserv.2.sql 33 2010-05-10 02:46:01Z openglx $

# Add temporary columns for conversion
ALTER TABLE memoserv
	DROP INDEX smid,
	CHANGE smid id INT UNSIGNED NOT NULL,
	DROP PRIMARY KEY,
	ADD PRIMARY KEY(owner_snid, id),
	ADD INDEX(sender_snid),
	ADD COLUMN t_send_tmp INT AFTER t_send;

# Now lets convert the date to unix timestamp
UPDATE memoserv SET t_send_tmp=UNIX_TIMESTAMP(t_send);
ALTER TABLE memoserv 
	DROP COLUMN t_send,
	CHANGE t_send_tmp t_send INT NOT NULL;

