DROP TABLE IF EXISTS ns_buddy;
CREATE TABLE ns_buddy(
  source_snid INT UNSIGNED NOT NULL,
  target_snid INT UNSIGNED NOT NULL,
  status INT NOT NULL,
  t_when INT NOT NULL,
  PRIMARY KEY (source_snid, target_snid),
  INDEX(target_snid),
  CONSTRAINT FK_NSB1 FOREIGN KEY (source_snid) REFERENCES nickserv (snid)
    ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT FK_NSB2 FOREIGN KEY (target_snid) REFERENCES nickserv (snid)
    ON DELETE CASCADE ON UPDATE CASCADE
) Type = InnoDB;
