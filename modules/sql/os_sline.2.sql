# $Id: os_sline.2.sql 33 2010-05-10 02:46:01Z openglx $

ALTER TABLE os_sline
    CHANGE mask mask VARCHAR(128) NOT NULL;

