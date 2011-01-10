# $Id: nickserv.5.sql 33 2010-05-10 02:46:01Z openglx $

# Convert table type
ALTER TABLE nickserv_security Type=InnoDB;
# Add foreign key
ALTER TABLE nickserv_security ADD
  CONSTRAINT FK_NS1 FOREIGN KEY (snid) REFERENCES nickserv (snid)
    ON DELETE CASCADE ON UPDATE CASCADE;
