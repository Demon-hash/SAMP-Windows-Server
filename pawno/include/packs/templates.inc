#if defined _templates_pack_included
	#endinput
#endif
#define _templates_pack_included

#define USERS_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS users (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`login` varchar(24) NOT NULL,\
	`password` varchar(32) NOT NULL,\
	`ip` varchar(16) NOT NULL,\
	`level` int(3) unsigned NOT NULL default '0',\
	`xp` DECIMAL(6,3) unsigned NOT NULL default '0',\
	`kills` int(6) unsigned NOT NULL default '0',\
	`deaths` int(6) unsigned NOT NULL default '0',\
	`language` int(2) unsigned NOT NULL default '0',\
	`vip` int(2) unsigned NOT NULL default '0',\
	`admin` int(2) unsigned NOT NULL default '0',\
	`reg_at` int(11) unsigned NOT NULL,\
	`reg_ip` varchar(16) NOT NULL,\
	`seen_at` int(11) unsigned NOT NULL default '0',\
	`vip_till` int(11) unsigned NOT NULL default '0',\
	PRIMARY KEY (`id`)\
);"

#define GANGS_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS gangs (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`game_id` int(2) unsigned NOT NULL,\
	`leader_id` int(11) unsigned NOT NULL,\
	`quest_id` int(3) unsigned NOT NULL default '0',\
	`level` int(3) unsigned NOT NULL default '0',\
	`points` int(6) unsigned NOT NULL default '0',\
	PRIMARY KEY (`id`)\
);"

#define GANGS_USERS_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS gangs_users (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`account_id` int(11) unsigned NOT NULL,\
	`gang_id` int(3) unsigned NOT NULL,\
	`rank` int(2) unsigned NOT NULL,\
	`warns` int(2) unsigned NOT NULL default '0',\
	`joined_at` int(11) unsigned NOT NULL,\
	`accepted_by` int(11) unsigned NOT NULL,\
	PRIMARY KEY (`id`)\
);"

#define GANGS_REQUESTS_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS gangs_requests (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`account_id` int(11) unsigned NOT NULL,\
	`gang_id` int(3) unsigned NOT NULL,\
	`request_at` int(11) unsigned NOT NULL,\
	`valid_till` int(11) unsigned NOT NULL,\
	PRIMARY KEY (`id`)\
);"

#define GANGS_WARNS_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS gangs_warns (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`gang_id` int(3) unsigned NOT NULL,\
	`issued_id` int(11) unsigned NOT NULL,\
	`reason` varchar(255) NOT NULL,\
	`given_at` int(11) unsigned NOT NULL,\
	`valid_till` int(11) unsigned NOT NULL,\
	PRIMARY KEY (`id`)\
);"

#define GANGS_BLACKLISTED_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS gangs_blacklisted (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`gang_id` int(3) unsigned NOT NULL,\
	`account_id` int(11) unsigned NOT NULL,\
	`issued_id` int(11) unsigned NOT NULL,\
	`reason` varchar(255) NOT NULL,\
	`given_at` int(11) unsigned NOT NULL,\
	PRIMARY KEY (`id`)\
);"

#define MAPS_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS maps (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`name` varchar(128) NOT NULL,\
	`filename` varchar(128) NOT NULL,\
	`author` int(11) unsigned NOT NULL default '0',\
	`interior` int(3) unsigned NOT NULL default '0',\
	`weather` int(3) unsigned NOT NULL default '0',\
	`time` int(2) unsigned NOT NULL default '12',\
	`gang` int(3) unsigned NOT NULL default '0',\
	`disabled` int(1) unsigned NOT NULL default '0',\
	PRIMARY KEY (`id`)\
);"

#define WEAPONS_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS weapons (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`type` int(3) unsigned NOT NULL default '0',\
	`min` int(4) unsigned NOT NULL default '0',\
	`max` int(4) unsigned NOT NULL default '1',\
	`pick` int(4) unsigned NOT NULL default '0',\
	PRIMARY KEY (`id`)\
);"

#define LANGUAGES_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS translation (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`en` varchar(255) NOT NULL default '',\
	`ru` varchar(255) NOT NULL default '',\
   	PRIMARY KEY (`id`)\
);"

#define CLASSES_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS classes (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`translate_id` int(3) unsigned NOT NULL\
	`team` int(3) unsigned NOT NULL default '0',\
	`health` int(3) unsigned NOT NULL default '100',\
	`armour` int(3) unsigned NOT NULL default '0',\
    	`level` int(3) unsigned NOT NULL default '0',\
    	`ability` int(3) unsigned NOT NULL default '-1',\
    	`skins` varchar(64) NOT NULL default '181',\
    	`weapons` varchar(96) NOT NULL default '',\
    	`ammo` varchar(96) NOT NULL default '',\
    	`disabled` int(3) unsigned NOT NULL default '1',\
   	PRIMARY KEY (`id`)\
);"

#define CONFIG_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS config (\
	`id` int(11) unsigned NOT NULL auto_increment,\
    	`xp` DECIMAL(6,3) unsigned NOT NULL default '1',\
	`kills` DECIMAL(6,3) unsigned NOT NULL default '0.25',\
	`evacuation` DECIMAL(6,3) unsigned NOT NULL default '2.5',\
	`discord` varchar(255) NOT NULL default '',\
   	PRIMARY KEY (`id`)\
);"

#define STATS_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS stats (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`month` int(11) unsigned NOT NULL,\
	`year` int(11) unsigned NOT NULL,\
    	`evacuated_humans` int(11) unsigned NOT NULL default '0',\
	`cured_humans` int(11) unsigned NOT NULL default '0',\
	`win_as_zombie` int(11) unsigned NOT NULL default '0',\
	`infected_humans` int(11) unsigned NOT NULL default '0',\
	`killed_humans` int(11) unsigned NOT NULL default '0',\
	`killed_zombie` int(11) unsigned NOT NULL default '0',\
	`players_joined` int(11) unsigned NOT NULL default '0',\
	`players_online` int(11) unsigned NOT NULL default '0',\
   	PRIMARY KEY (`id`)\
);"