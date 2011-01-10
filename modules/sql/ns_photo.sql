# $Id: ns_photo.sql 33 2010-05-10 02:46:01Z openglx $

DROP TABLE IF EXISTS ns_photo;
CREATE TABLE ns_photo(
  id INT UNSIGNED NOT NULL auto_increment,
  snid INT UNSIGNED NOT NULL,
  t_update datetime NOT NULL,
  status char NOT NULL default 'P',
  photo MEDIUMBLOB,
  thumb BLOB,
  hits INT NOT NULL,
  PRIMARY KEY (id),
  UNIQUE KEY(snid),
  CONSTRAINT FK_NSP1 FOREIGN KEY (snid) REFERENCES nickserv (snid)
    ON DELETE CASCADE ON UPDATE CASCADE
) Type = InnoDB;
