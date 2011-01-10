# $Id: cs_akick.sql 33 2010-05-10 02:46:01Z openglx $

# cs_akick table
DROP TABLE IF EXISTS cs_akick;
CREATE TABLE cs_akick(
  scid INT UNSIGNED NOT NULL,
  mask VARCHAR(64) NOT NULL,
  message VARCHAR(255),
  who_nick VARCHAR(32) NOT NULL,
  t_when INT NULL,
  duration INT NOT NULL,
  PRIMARY KEY (scid, mask),
  CONSTRAINT FK_AK1 FOREIGN KEY (scid) REFERENCES chanserv (scid)
    ON DELETE CASCADE ON UPDATE CASCADE
) Type = InnoDB;
