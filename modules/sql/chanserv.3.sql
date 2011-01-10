# $Id: chanserv.3.sql 33 2010-05-10 02:46:01Z openglx $

# first change the column types
ALTER TABLE chanserv
  CHANGE founder founder INT UNSIGNED NULL,
  CHANGE successor successor INT UNSIGNED NULL,
  ADD INDEX(founder),
  ADD INDEX(successor);

# fix successor
UPDATE chanserv SET founder=NULL WHERE founder=0;
UPDATE chanserv SET successor=NULL WHERE successor=0;

# now add the foreign keys
ALTER TABLE chanserv
  ADD CONSTRAINT FK_CS1 FOREIGN KEY (founder) REFERENCES nickserv (snid)
    ON DELETE CASCADE ON UPDATE CASCADE;
ALTER TABLE chanserv
  ADD CONSTRAINT FK_CS2 FOREIGN KEY (successor) REFERENCES nickserv (snid)
    ON DELETE SET NULL ON UPDATE CASCADE;
