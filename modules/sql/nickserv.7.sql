# $Id: nickserv.7.sql 33 2010-05-10 02:46:01Z openglx $

# Drops columns we don't need anymore
ALTER TABLE nickserv
  DROP COLUMN username,
  DROP COLUMN realhost,
  DROP COLUMN publichost,
  DROP COLUMN info,
  DROP COLUMN nmask,
  DROP COLUMN ajoin;
