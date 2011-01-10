#  $Id: clear_db.sql 33 2010-05-10 02:46:01Z openglx $
#
# CAUTION: This sql will drop all your tables
#
DROP TABLE IF EXISTS botserv_chans;
DROP TABLE IF EXISTS botserv;
DROP TABLE IF EXISTS cs_akick;
DROP TABLE IF EXISTS cs_role_users;
DROP TABLE IF EXISTS cs_role;
DROP TABLE IF EXISTS chanserv;
DROP TABLE IF EXISTS memoserv;
DROP TABLE IF EXISTS ns_group_users;
DROP TABLE IF EXISTS ns_group;
DROP TABLE IF EXISTS ns_photo;
DROP TABLE IF EXISTS nickserv_security;
DROP TABLE IF EXISTS nickserv;
DELETE FROM ircsvs_tables;

