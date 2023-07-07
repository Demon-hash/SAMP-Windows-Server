#if defined _templates_pack_included
	#endinput
#endif
#define _templates_pack_included

#define SQL_CHARSET "utf8"

#define USERS_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS users (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`login` varchar(24) NOT NULL,\
	`password` varchar(32) NOT NULL,\
	`language` int(2) unsigned NOT NULL default '0',\
	`points` int(11) unsigned NOT NULL default '0',\
	PRIMARY KEY (`id`)\
);"

#define ACHIEVEMENTS_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS achievements (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`rank` int(3) unsigned NOT NULL default '0',\
	`kills` int(6) unsigned NOT NULL default '0',\
	`deaths` int(6) unsigned NOT NULL default '0',\
	`ability` int(6) unsigned NOT NULL default '0',\
	`ran` DECIMAL(6,3) unsigned NOT NULL default '0',\
	`luck` int(6) unsigned NOT NULL default '0',\
	`humans` int(6) unsigned NOT NULL default '0',\
	`zombies` int(6) unsigned NOT NULL default '0',\
	`meats` int(6) unsigned NOT NULL default '0',\
	`killstreak` int(6) unsigned NOT NULL default '0',\
	`infection` int(6) unsigned NOT NULL default '0',\
	`cure` int(6) unsigned NOT NULL default '0',\
	`evacs` int(6) unsigned NOT NULL default '0',\
	`reported` int(6) unsigned NOT NULL default '0',\
	`purchase` int(6) unsigned NOT NULL default '0',\
	`jumps` int(6) unsigned NOT NULL default '0',\
	`total_points` int(11) unsigned NOT NULL default '0',\
	`hours` int(6) unsigned NOT NULL default '0',\
	`minutes` int(2) unsigned NOT NULL default '0',\
	`seconds` int(2) unsigned NOT NULL default '0',\
	PRIMARY KEY (`id`)\
);"

#define PRIVILEGES_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS privileges (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`account_id` int(11) unsigned NOT NULL,\
	`admin` int(2) unsigned NOT NULL default '0',\
	`vip` int(2) unsigned NOT NULL default '0',\
	`vip_till` int(11) unsigned NOT NULL default '0',\
	PRIMARY KEY (`id`)\
);"

#define REGISTRATION_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS registration (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`account_id` int(11) unsigned NOT NULL,\
	`reg_at` int(11) unsigned NOT NULL,\
	`reg_ip` varchar(16) NOT NULL,\
	`reg_key` varchar(64) NOT NULL,\
	PRIMARY KEY (`id`)\
);"

#define LOGINLOG_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS login_log (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`account_id` int(11) unsigned NOT NULL,\
	`date` int(11) unsigned NOT NULL,\
	`ip` varchar(16) NOT NULL,\
	`key` varchar(64) NOT NULL,\
	PRIMARY KEY (`id`)\
);"

#define BANLOG_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS ban_log (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`account_id` int(11) unsigned NOT NULL,\
	`issued_id` int(11) unsigned NOT NULL,\
	`unbanned_id` int(11) unsigned NOT NULL default '0',\
	`issued_at` int(11) unsigned NOT NULL,\
	`valid_till` int(11) unsigned NOT NULL,\
	`permanent` int(1) unsigned NOT NULL,\
	`reason` varchar(128) NOT NULL,\
	PRIMARY KEY (`id`)\
);"

#define NAMELOG_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS name_log (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`account_id` int(11) unsigned NOT NULL,\
	`current_name` varchar(24) NOT NULL,\
	`last_name` varchar(24) NOT NULL,\
	`ip` varchar(16) NOT NULL,\
	`date` int(11) unsigned NOT NULL,\
	PRIMARY KEY (`id`)\
);"

#define PAYLOG_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS pay_log (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`target_id` int(11) unsigned NOT NULL,\
	`issued_id` int(11) unsigned NOT NULL,\
	`amount` int(11) unsigned NOT NULL,\
	`target_ip` varchar(16) NOT NULL,\
	`issued_ip` varchar(16) NOT NULL,\
	`date` int(11) unsigned NOT NULL,\
	PRIMARY KEY (`id`)\
);"

#define AUCTIONLOG_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS auction_log (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`account_id` int(11) unsigned NOT NULL,\
	`from_id` int(11) unsigned NOT NULL,\
	`amount` int(11) unsigned NOT NULL,\
	`date` int(11) unsigned NOT NULL,\
	`ip` varchar(16) unsigned NOT NULL,\
   	PRIMARY KEY (`id`)\
);"

#define GANGS_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS gangs (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`game_id` int(2) unsigned NOT NULL,\
	`leader_id` int(11) unsigned NOT NULL,\
	`created_at` int(11) unsigned NOT NULL,\
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

#define GANGS_CONFIG_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS gangs_config (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`capacity` int(3) unsigned NOT NULL default '15',\
	`required` int(6) unsigned NOT NULL default '25000',\
	`first` int(6) unsigned NOT NULL default '20000',\
	`second` int(6) unsigned NOT NULL default '50000',\
	`three` int(6) unsigned NOT NULL default '80000',\
	`four` int(6) unsigned NOT NULL default '140000',\
	`five` int(6) unsigned NOT NULL default '200000',\
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
	`humans_coords` varchar(255) NOT NULL default '',\
	`zombies_coords` varchar(255) NOT NULL default '',\
	`camera_coords` varchar(255) NOT NULL default '',\
	`checkpoint_coords` varchar(255) NOT NULL default '',\
	`checkpoint_size` DECIMAL(6,3) NOT NULL default '1.0',\
	`gates_ids` varchar(24) NOT NULL default '',\
	`gates_coords` varchar(255) NOT NULL default '',\
	`gates_speed` DECIMAL(6,3) NOT NULL default '1.0',\
	`time` int(2) unsigned NOT NULL default '12',\
	`gang` int(3) unsigned NOT NULL default '0',\
	`water` int(11) unsigned NOT NULL default '1',\
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
	CREATE TABLE IF NOT EXISTS english (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`for` int(11) unsigned NOT NULL auto_increment,\
	`text` varchar(255) NOT NULL default '',\
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
	`cooldown` int(3) unsigned NOT NULL default '15',\
    	`skins` varchar(64) NOT NULL default '181',\
    	`weapons` varchar(96) NOT NULL default '',\
    	`ammo` varchar(96) NOT NULL default '',\
    	`disabled` int(3) unsigned NOT NULL default '1',\
   	PRIMARY KEY (`id`)\
);"

#define CONFIG_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS config (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`kills` int(3) unsigned NOT NULL default '1',\
	`evacuation` int(3) unsigned NOT NULL default '5',\
	`cure` int(3) unsigned NOT NULL default '1',\
	`infect` int(3) unsigned NOT NULL default '1',\
	`ability` int(3) unsigned NOT NULL default '1',\
	`infection_damage` DECIMAL(6,3) unsigned NOT NULL default '1.0',\
	`fists_damage` DECIMAL(6,3) unsigned NOT NULL default '5.0',\
	`name` varchar(255) NOT NULL default '',\
	`discord` varchar(255) NOT NULL default '',\
	`site` varchar(255) NOT NULL default '',\
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

#define AUCTION_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS auction (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`seller_id` int(11) unsigned NOT NULL,\
	`type` int(4) unsigned NOT NULL,\	
	`count` int(11) unsigned NOT NULL,\
	`points` int(11) unsigned NOT NULL,\
	`date` int(11) unsigned NOT NULL,\
   	PRIMARY KEY (`id`)\
);"

#define AUCTION_CASHBACK_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS auction_cashback (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`account_id` int(11) unsigned NOT NULL,\
	`points` int(11) unsigned NOT NULL,\
   	PRIMARY KEY (`id`)\
);"