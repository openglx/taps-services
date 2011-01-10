# $Id: nickserv.3.sql 33 2010-05-10 02:46:01Z openglx $

# Add t_expire and publichost
ALTER TABLE nickserv
  CHANGE COLUMN t_sign t_expire INT NOT NULL,
  ADD COLUMN publichost varchar(64) default NULL AFTER realhost;
# Now update publichost from realhost
UPDATE nickserv SET publichost=realhost;
