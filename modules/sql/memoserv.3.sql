# $Id: memoserv.3.sql 33 2010-05-10 02:46:01Z openglx $
# First remove the NOT NULL from sender
ALTER TABLE memoserv
  CHANGE sender_snid sender_snid INT UNSIGNED NULL;
# Update the sender if null
UPDATE memoserv SET sender_snid=NULL WHERE sender_snid=0;
# Add the foreign keys
ALTER TABLE memoserv
  ADD CONSTRAINT FK_MS1 FOREIGN KEY (owner_snid) REFERENCES nickserv (snid)
    ON DELETE CASCADE ON UPDATE CASCADE;
ALTER TABLE memoserv
  ADD CONSTRAINT FK_MS2 FOREIGN KEY (sender_snid) REFERENCES nickserv (snid)
    ON DELETE SET NULL ON UPDATE CASCADE;