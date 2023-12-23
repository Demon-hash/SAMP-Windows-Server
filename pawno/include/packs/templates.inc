#if defined _templates_pack_included
	#endinput
#endif
#define _templates_pack_included

#define USER_COLUMNS 4
#define USERS_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS users (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`login` varchar(24) NOT NULL,\
	`password` varchar(32) NOT NULL,\
	`language` int(2) unsigned NOT NULL default '0',\
	`coins` int(6) unsigned NOT NULL default '0',\
	`points` int(6) unsigned NOT NULL default '0',\
	PRIMARY KEY (`id`)\
);"

#define ACHIEVEMENTS_COLUMNS 46
#define ACHIEVEMENTS_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS achievements (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`rank` int(3) unsigned NOT NULL default '0',\
	`kills` int(6) unsigned NOT NULL default '0',\
	`deaths` int(6) unsigned NOT NULL default '0',\
	`ability` int(6) unsigned NOT NULL default '0',\
	`ran` DECIMAL(9,2) unsigned NOT NULL default '0',\
	`luck` int(6) unsigned NOT NULL default '0',\
	`humans` int(6) unsigned NOT NULL default '0',\
	`zombies` int(6) unsigned NOT NULL default '0',\
	`meats` int(6) unsigned NOT NULL default '0',\
	`ammo` int(6) unsigned NOT NULL default '0',\
	`killstreak` int(6) unsigned NOT NULL default '0',\
	`infection` int(6) unsigned NOT NULL default '0',\
	`cure` int(6) unsigned NOT NULL default '0',\
	`evacs` int(6) unsigned NOT NULL default '0',\
	`reported` int(6) unsigned NOT NULL default '0',\
	`jumps` int(6) unsigned NOT NULL default '0',\
	`total_points` int(6) unsigned NOT NULL default '0',\
	`hours` int(6) unsigned NOT NULL default '0',\
	`minutes` int(2) unsigned NOT NULL default '0',\
	`seconds` int(2) unsigned NOT NULL default '0',\
	`silinced` int(3) unsigned NOT NULL default '0',\
	`colt45` int(3) unsigned NOT NULL default '0',\
	`deagle` int(3) unsigned NOT NULL default '0',\
	`rifle` int(3) unsigned NOT NULL default '0',\
	`shotgun` int(3) unsigned NOT NULL default '0',\
	`mp5` int(3) unsigned NOT NULL default '0',\
	`combat` int(3) unsigned NOT NULL default '0',\
	`tec9` int(3) unsigned NOT NULL default '0',\
	`ak47` int(3) unsigned NOT NULL default '0',\
	`m4` int(3) unsigned NOT NULL default '0',\
	`master` int(1) unsigned NOT NULL default '0',\
	`hermitage` int(1) unsigned NOT NULL default '0',\
	`last_hope` int(1) unsigned NOT NULL default '0',\
	`terrorist` int(6) unsigned NOT NULL default '0',\
	`answer` int(6) unsigned NOT NULL default '0',\
	`lottery` int(6) unsigned NOT NULL default '0',\
	`capture` int(6) unsigned NOT NULL default '0',\
	`duels` int(6) unsigned NOT NULL default '0',\
	`session` int(2) unsigned NOT NULL default '0',\
	`blood` int(6) unsigned NOT NULL default '0',\
	`mary` int(1) unsigned NOT NULL default '0',\
	`gang` int(3) unsigned NOT NULL default '0',\
	`evacuations` int(3) unsigned NOT NULL default '0',\
	`vehicles` int(6) unsigned NOT NULL default '0',\
	`progress` varchar(256) NOT NULL default '',\
	PRIMARY KEY (`id`)\
);"

#define ACHIEVEMENTS_CONFIG_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS achievements_config (\
	`id` int(11) unsigned NOT NULL,\
	`type` int(3) unsigned NOT NULL default '0',\
	`count` int(6) unsigned NOT NULL default '0',\
	`reward` int(6) unsigned NOT NULL default '0',\
	`disabled` int(1) unsigned NOT NULL default '1',\
	PRIMARY KEY (`id`)\
);"

#define ACHIEVEMENTS_LOCALIZATION_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS achievements_localization (\
	`id` int(11) unsigned NOT NULL,\
	`english` TEXT NOT NULL default '',\
	`russian` TEXT NOT NULL default '',\
	`english_desc` TEXT NOT NULL default '',\
	`russian_desc` TEXT NOT NULL default '',\
	PRIMARY KEY (`id`)\
);"

#define PRIVILAGES_COLUMNS 4
#define PRIVILEGES_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS privileges (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`admin` int(2) unsigned NOT NULL default '0',\
	`vip` int(2) unsigned NOT NULL default '0',\
	`vip_till` int(11) unsigned NOT NULL default '0',\
	PRIMARY KEY (`id`)\
);"

#define REGISTRATION_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS registration (\
	`id` int(11) unsigned NOT NULL auto_increment,\
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
	`date` int(11) unsigned NOT NULL,\
	`valid_till` int(11) unsigned NOT NULL,\
	`permanent` int(1) unsigned NOT NULL,\
	`reason` varchar(128) NOT NULL,\
	`issued_ip` varchar(16) NOT NULL,\
	`target_ip` varchar(16) NOT NULL,\
	PRIMARY KEY (`id`)\
);"

#define BANIP_LOG_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS banip_log (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`account_id` int(11) unsigned NOT NULL,\
	`date` int(11) unsigned NOT NULL,\
	`reason` varchar(128) NOT NULL,\
	`target_ip` varchar(16) NOT NULL,\
	`ip` varchar(16) NOT NULL,\
	PRIMARY KEY (`id`)\
);"

#define VOTEKICK_LOG_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS votekick_log (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`account_id` int(11) unsigned NOT NULL,\
	`target_id` int(11) unsigned NOT NULL,\
	`date` int(11) unsigned NOT NULL,\
	`reason` varchar(128) NOT NULL,\
	`ip` varchar(16) NOT NULL,\
	`target_ip` varchar(16) NOT NULL,\
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
	`to_id` int(11) unsigned NOT NULL,\
	`from_id` int(11) unsigned NOT NULL,\
	`amount` int(6) NOT NULL,\
	`type` int(3) unsigned NOT NULL,\
	`to_ip` varchar(16) NOT NULL,\
	`from_ip` varchar(16) NOT NULL,\
	`date` int(11) unsigned NOT NULL,\
	PRIMARY KEY (`id`)\
);"

#define AUCTIONLOG_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS auction_log (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`account_id` int(11) unsigned NOT NULL,\
	`from_id` int(11) unsigned NOT NULL,\
	`amount` int(6) unsigned NOT NULL,\
	`date` int(11) unsigned NOT NULL,\
	`ip` varchar(16) NOT NULL,\
   	PRIMARY KEY (`id`)\
);"

#define WARNSLOG_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS warns_log (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`account_id` int(11) unsigned NOT NULL,\
	`issued_id` int(11) unsigned NOT NULL,\
	`date` int(11) unsigned NOT NULL,\
	`reason` varchar(128) NOT NULL,\
	`target_ip` varchar(16) NOT NULL,\
	`issued_ip` varchar(16) NOT NULL,\
	PRIMARY KEY (`id`)\
);"

#define MUTESLOG_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS mutes_log (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`account_id` int(11) unsigned NOT NULL,\
	`issued_id` int(11) unsigned NOT NULL,\
	`date` int(11) unsigned NOT NULL,\
	`time` int(3) unsigned NOT NULL,\
	`reason` varchar(128) NOT NULL,\
	`target_ip` varchar(16) NOT NULL,\
	`issued_ip` varchar(16) NOT NULL,\
	PRIMARY KEY (`id`)\
);"

#define JAILSLOG_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS jails_log (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`account_id` int(11) unsigned NOT NULL,\
	`issued_id` int(11) unsigned NOT NULL,\
	`date` int(11) unsigned NOT NULL,\
	`reason` varchar(128) NOT NULL,\
	`target_ip` varchar(16) NOT NULL,\
	`issued_ip` varchar(16) NOT NULL,\
	PRIMARY KEY (`id`)\
);"

#define GANGPAYLOG_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS gang_pay_log (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`account_id` int(11) unsigned NOT NULL,\
	`gang_id` int(11) unsigned NOT NULL,\
	`amount` int(6) unsigned NOT NULL,\
	`date` int(11) unsigned NOT NULL,\
	`ip` varchar(16) NOT NULL,\
	PRIMARY KEY (`id`)\
);"

#define GANGS_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS gangs (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`game_id` int(2) unsigned NOT NULL,\
	`leader_id` int(11) unsigned NOT NULL,\
	`date` int(11) unsigned NOT NULL,\
	`name` varchar(32) NOT NULL default '',\
	`tag` varchar(6) NOT NULL default '',\
	`capacity` int(6) unsigned NOT NULL default '5',\
	`points` int(6) unsigned NOT NULL default '0',\
	`war` varchar(32) NOT NULL default '',\
	`alliance` varchar(32) NOT NULL default '',\
	`settings` varchar(32) NOT NULL default '',\
	`disabled` int(1) unsigned NOT NULL default '0',\
	PRIMARY KEY (`id`)\
);"

#define GANG_USER_COLUMNS_META 3
#define GANG_USER_COLUMNS 5
#define GANGS_USERS_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS gangs_users (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`gang_id` int(3) NOT NULL default '-1',\
	`rank` int(2) unsigned NOT NULL default '0',\
	`warns` int(2) unsigned NOT NULL default '0',\
	`joined_at` int(11) unsigned NOT NULL default '0',\
	`accepted_by` int(11) unsigned NOT NULL default '0',\
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
	`id` int(11) unsigned NOT NULL,\
	`required` int(6) unsigned NOT NULL default '25000',\
	`default` int(6) unsigned NOT NULL default '5000',\
	`cure` int(6) unsigned NOT NULL default '1',\
	`kill` int(6) unsigned NOT NULL default '1',\
	`evac` int(6) unsigned NOT NULL default '1',\
	`ability` int(6) unsigned NOT NULL default '1',\
	`flag_id` int(11) unsigned NOT NULL default '11245',\
	`flag_distance` DECIMAL(9,2) unsigned NOT NULL default '100.0',\
	PRIMARY KEY (`id`)\
);"

#define MAPS_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS maps (\
	`id` int(11) unsigned NOT NULL,\
	`filename` varchar(64) NOT NULL,\
	`author` int(11) unsigned NOT NULL default '0',\
	`interior` int(3) unsigned NOT NULL default '0',\
	`weather` int(3) unsigned NOT NULL default '0',\
	`time` int(2) unsigned NOT NULL default '12',\
	`gang` int(3) NOT NULL default '-1',\
	`points` int(6) unsigned NOT NULL default '0',\
	`water` int(1) unsigned NOT NULL default '1',\
	`humans_coords` TEXT NOT NULL default '',\
	`zombies_coords` TEXT NOT NULL default '',\
	`camera_coords` TEXT NOT NULL default '',\
	`checkpoint` TEXT NOT NULL default '',\
	`gates_id` varchar(24) NOT NULL default '',\
	`gates_speed` DECIMAL(9,2) NOT NULL default '1.0',\
	`gates_coords` TEXT NOT NULL default '',\
	`gates_move` TEXT NOT NULL default '',\
	`flag_date` int(11) unsigned NOT NULL default '0',\
	`flag_coords` TEXT NOT NULL default '',\
	`flag_text` TEXT NOT NULL default '',\
	`disabled` int(1) unsigned NOT NULL default '1',\
	PRIMARY KEY (`id`)\
);"

#define MAPS_LOCALIZATION_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS maps_localization (\
	`id` int(11) unsigned NOT NULL,\
	`english` TEXT NOT NULL default '',\
	`russian` TEXT NOT NULL default '',\
	PRIMARY KEY (`id`)\
);"

#define LANGUAGES_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS localization (\
	`id` int(11) unsigned NOT NULL,\
	`english` TEXT NOT NULL default '',\
	`russian` TEXT NOT NULL default '',\
   	PRIMARY KEY (`id`)\
);"

#define CLASSES_CONFIG_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS classes_config (\
	`id` int(11) unsigned NOT NULL,\
	`whopping_when` int(3) unsigned NOT NULL default '5',\
	`stomp_xyz` varchar(24) NOT NULL default '10.0,10.0,8.0',\
	`high_jump_xyz` varchar(24) NOT NULL default '1.0,1.0,10.0',\
	`long_jump_xyz` varchar(24) NOT NULL default '1.2,1.2,0.8',\
	`radioactive` DECIMAL(9,2) unsigned NOT NULL default '5.0',\
	`regeneration` DECIMAL(9,2) unsigned NOT NULL default '5.0',\
	`support` DECIMAL(9,2) unsigned NOT NULL default '2.5',\
	`air_range` DECIMAL(9,2) unsigned NOT NULL default '5.0',\
	`space` DECIMAL(9,2) unsigned NOT NULL default '5.0',\
	`stomper_effect` varchar(64) NOT NULL default '18675,0.0,0.0,0.0,-1.2,1000',\
	`flasher_effect` varchar(48) NOT NULL default '18693,10,2,15.0',\
	`engineer_effect` varchar(48) NOT NULL default '923,1057,15.0',\
	`spitter_effect` int(3) unsigned NOT NULL default '23',\
	`stealer_effect` int(3) unsigned NOT NULL default '5',\
   	PRIMARY KEY (`id`)\
);"

#define CLASSES_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS classes (\
	`id` int(11) unsigned NOT NULL,\
	`team` int(3) unsigned NOT NULL default '0',\
	`health` DECIMAL(9,2) unsigned NOT NULL default '100.0',\
	`armour` DECIMAL(9,2) unsigned NOT NULL default '0.0',\
    	`points` int(6) unsigned NOT NULL default '0',\
	`cooldown` int(3) unsigned NOT NULL default '15',\
	`time` int(3) unsigned NOT NULL default '15',\
	`count` int(3) unsigned NOT NULL default '3',\
    	`skin` int(3) unsigned NOT NULL default '181',\
	`ability` varchar(24) NOT NULL default '',\
	`immunity` varchar(24) NOT NULL default '',\
	`weapons` varchar(24) NOT NULL default '',\
	`distance` DECIMAL(9,2) unsigned NOT NULL default '1.0',\
    	`disabled` int(1) unsigned NOT NULL default '1',\
   	PRIMARY KEY (`id`)\
);"

#define CLASSES_LOCALIZATION_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS classes_localization (\
	`id` int(11) unsigned NOT NULL,\
	`english_title` TEXT NOT NULL default '',\
	`russian_title` TEXT NOT NULL default '',\
	`english_desc` TEXT NOT NULL default '',\
	`russian_desc` TEXT NOT NULL default '',\
	PRIMARY KEY (`id`)\
);"

#define DUELS_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS duels_config (\
	`id` int(11) unsigned NOT NULL,\
	`interior` int(6) unsigned NOT NULL default '1',\
	`skins` varchar(24) NOT NULL DEFAULT '106,104',\
	`coords` varchar(128) NOT NULL DEFAULT '1409.0046, -17.8430, 1000.9226, 90.0, 1372.6814, -16.9314, 1000.9219, 270.0',\
	PRIMARY KEY (`id`)\
);"

#define CONFIG_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS config (\
	`id` int(11) unsigned NOT NULL,\
	`pickup_protection` int(4) unsigned NOT NULL default '30',\
	`tip_per` int(3) unsigned NOT NULL default '40',\
	`random_question` varchar(24) NOT NULL default '15,200,30',\
	`lottery` varchar(24) NOT NULL DEFAULT '500,60,100,5',\
	`kills` int(6) unsigned NOT NULL default '1',\
	`evacuation` int(6) unsigned NOT NULL default '15',\
	`cure` int(6) unsigned NOT NULL default '1',\
	`ability` int(6) unsigned NOT NULL default '1',\
	`votekick` int(6) unsigned NOT NULL default '35000',\
	`name_price` int(6) unsigned NOT NULL default '50000',\
	`gang_price` int(6) unsigned NOT NULL default '50000',\
	`taxes` DECIMAL(9,2) unsigned NOT NULL default '0.35',\
	`infection_damage` DECIMAL(9,2) unsigned NOT NULL default '1.0',\
	`curse_damage` DECIMAL(9,2) unsigned NOT NULL default '4.0',\
	`fists_damage` DECIMAL(9,2) unsigned NOT NULL default '5.0',\
	`infection_drunk` int(6) unsigned NOT NULL default '50000',\
	`max_auth_timeout` int(3) unsigned NOT NULL default '2',\
	`max_auth_tries` int(3) unsigned NOT NULL default '3',\
	`preview_bot` int(3) unsigned NOT NULL default '181',\
	`preview_bot_coords` varchar(255) NOT NULL default '2415.5414,-50.4586,28.1535, 1.4218',\
	`preview_camera_coords` varchar(255) NOT NULL default '2415.7615, -45.1561, 28.8247, 2415.7559, -46.1539, 28.6447',\
	`spawn_range` DECIMAL(9,2) unsigned NOT NULL default '15.0',\
	`vehicle_damage` DECIMAL(9,2) unsigned NOT NULL default '50.0',\
	`min_zombies_to_win` int(3) unsigned NOT NULL default '2',\
	`max_weapon_ammo` int(5) unsigned NOT NULL default '1000',\
	`rifle` int(2) unsigned NOT NULL default '33',\
	`excluded_mirror_part` int(2) unsigned NOT NULL default '9',\
	`meat_pickup` int(6) unsigned NOT NULL default '2804',\
	`ammo_chance` int(3) unsigned NOT NULL default '4',\
	`antidote_chance` int(3) unsigned NOT NULL default '3',\
	`name` varchar(64) NOT NULL default '',\
	`mode` varchar(64) NOT NULL default '',\
	`discord` varchar(64) NOT NULL default '',\
	`site` varchar(64) NOT NULL default '',\
	`language` varchar(64) NOT NULL default '',\
   	PRIMARY KEY (`id`)\
);"

#define ANTICHEAT_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS anticheat (\
	`id` int(11) unsigned NOT NULL,\
	`weapons` int(1) unsigned NOT NULL default '1',\
	`teleportation` int(1) unsigned NOT NULL default '1',\
	`health` int(1) unsigned NOT NULL default '1',\
	`armour` int(1) unsigned NOT NULL default '1',\
	`fakekill` int(1) unsigned NOT NULL default '1',\
	`parkour` int(1) unsigned NOT NULL default '1',\
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
	`points` int(6) unsigned NOT NULL,\
	`date` int(11) unsigned NOT NULL,\
   	PRIMARY KEY (`id`)\
);"

#define AUCTION_CASHBACK_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS auction_cashback (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`account_id` int(11) unsigned NOT NULL,\
	`points` int(6) unsigned NOT NULL,\
   	PRIMARY KEY (`id`)\
);"

#define ROUND_SESSION_COLUMNS 12
#define ROUND_SESSION_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS round_session (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`account_id` int(11) unsigned NOT NULL,\
	`map_id` int(11) unsigned NOT NULL,\
	`team` int(3) unsigned NOT NULL,\
	`survival` DECIMAL(9,2) unsigned NOT NULL default '0',\
	`killing` DECIMAL(9,2) unsigned NOT NULL default '0',\
	`care` DECIMAL(9,2) unsigned NOT NULL default '0',\
	`mobility` DECIMAL(6,4) unsigned NOT NULL default '0',\
	`skillfulness` DECIMAL(9,2) unsigned NOT NULL default '0',\
	`brutality` DECIMAL(9,2) unsigned NOT NULL default '0',\
	`undead` DECIMAL(9,2) unsigned NOT NULL default '0',\
	`additional` DECIMAL(9,2) unsigned NOT NULL default '0',\
	`time` int(8) unsigned NOT NULL default '0',\
   	PRIMARY KEY (`id`)\
);"

#define ROUND_CONFIG_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS round_config (\
	`id` int(11) unsigned NOT NULL,\
	`survival_per` int(11) unsigned NOT NULL default '30',\
	`evac` DECIMAL(9,2) unsigned NOT NULL default '15.0',\
	`survival` DECIMAL(9,2) unsigned NOT NULL default '1',\
	`killing` DECIMAL(9,2) unsigned NOT NULL default '1.25',\
	`care` DECIMAL(9,2) unsigned NOT NULL default '2.5',\
	`mobility` DECIMAL(6,4) unsigned NOT NULL default '0.0125',\
	`skillfulness` DECIMAL(9,2) unsigned NOT NULL default '1.25',\
	`brutality` DECIMAL(9,2) unsigned NOT NULL default '1.0',\
	`undead` DECIMAL(9,2) unsigned NOT NULL default '1.0',\
	`cap` int(3) unsigned NOT NULL default '25',\
	`brutality_weapon` int(2) unsigned NOT NULL default '0',\
   	PRIMARY KEY (`id`)\
);"

#define EVAC_CONFIG_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS evac_config (\
	`id` int(11) unsigned NOT NULL,\
	`interior` int(4) unsigned NOT NULL default '3',\
	`sound` int(5) unsigned NOT NULL default '5448',\
	`position` varchar(255) NOT NULL default '960.3299,-52.5693,1001.1172,0.0',\
   	PRIMARY KEY (`id`)\
);"

#define MAP_CONFIG_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS map_config (\
	`id` int(11) unsigned NOT NULL,\
	`total` int(6) unsigned NOT NULL default '300',\
	`update` int(6) unsigned NOT NULL default '5',\
	`balance` int(6) unsigned NOT NULL default '30',\
	`end` int(6) unsigned NOT NULL default '60',\
	`restart` int(6) unsigned NOT NULL default '10',\
	`great_period` int(6) unsigned NOT NULL default '30',\
	`spawn_protection_time` int(6) unsigned NOT NULL default '15',\
	`killstreak_factor` int(6) unsigned NOT NULL default '5',\
	`capture_days` int(3) unsigned NOT NULL default '7',\
	`zombie_armour` DECIMAL(9,2) unsigned NOT NULL default '75.0',\
	`hero_armour` DECIMAL(9,2) unsigned NOT NULL default '75.0',\
	`hero_weapons` varchar(24) NOT NULL default '31, 24',\
	`spawn_text_range` DECIMAL(9,2) unsigned NOT NULL default '50.0',\
	`human_hero_kill` DECIMAL(9,2) unsigned NOT NULL default '15.0',\
	`zombie_boss_kill` DECIMAL(9,2) unsigned NOT NULL default '15.0',\
	`first_blood` DECIMAL(9,2) unsigned NOT NULL default '20.0',\
	`kill_last` DECIMAL(9,2) unsigned NOT NULL default '50.0',\
	`last_evacuated` DECIMAL(9,2) unsigned NOT NULL default '50.0',\
   	PRIMARY KEY (`id`)\
);"

#define WEAPONS_CONFIG_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS weapons_config (\
	`id` int(11) unsigned NOT NULL,\
	`type` int(3) unsigned NOT NULL,\
	`chance` int(3) unsigned NOT NULL default '0',\
	`default` int(4) unsigned NOT NULL default '0',\
	`pick` int(4) unsigned NOT NULL default '0',\
	PRIMARY KEY (`id`)\
);"

#define WEAPONS_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS weapons (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`account_id` int(11) unsigned NOT NULL,\
	`weapon_id` int(3) unsigned NOT NULL,\
	`time` int(6) unsigned NOT NULL default '1209600',\
	`set_as_default` int(1) unsigned NOT NULL default '0',\
	PRIMARY KEY (`id`)\
);"

#define BALANCE_CONFIG_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS balance_config (\
	`id` int(11) unsigned NOT NULL,\
	`min` DECIMAL(9,2) unsigned NOT NULL default '2.0',\
	`medium` DECIMAL(9,2) unsigned NOT NULL default '3.0',\
	`max` DECIMAL(9,2) unsigned NOT NULL default '4.0',\
	`by_default` DECIMAL(9,2) unsigned NOT NULL default '2.0',\
	PRIMARY KEY (`id`)\
);"

#define TEXTURES_CONFIG_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS `textures_config` (\
  	`id` int(11) unsigned NOT NULL,\
  	`position` varchar(255) NOT NULL DEFAULT '',\
  	`letter_size` varchar(255) NOT NULL DEFAULT '',\
  	`text_size` varchar(255) NOT NULL DEFAULT '',\
  	`default_value` varchar(255) NOT NULL DEFAULT '',\
  	`background_color` varchar(32) NOT NULL DEFAULT '',\
  	`texture_font` int(1) unsigned NOT NULL DEFAULT '0',\
  	`texture_draw_color` varchar(32) NOT NULL DEFAULT '',\
  	`texture_outline` int(1) unsigned NOT NULL DEFAULT '0',\
  	`texture_proportional` int(1) unsigned NOT NULL DEFAULT '0',\
  	`texture_shadow` int(1) unsigned NOT NULL DEFAULT '0',\
  	`texture_use_box` int(1) unsigned NOT NULL DEFAULT '0',\
  	`texture_box_color` varchar(32) NOT NULL DEFAULT '0',\
  	`texture_alignment` int(1) unsigned NOT NULL DEFAULT '0',\
  	PRIMARY KEY (`id`)\
);"

#define RANDOM_MESSAGES_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS random_messages (\
	`id` int(11) unsigned NOT NULL,\
	`english` TEXT NOT NULL default '',\
	`russian` TEXT NOT NULL default '',\
	PRIMARY KEY (`id`)\
);"

#define RANDOM_QUESTION_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS random_question (\
	`id` int(11) unsigned NOT NULL,\
	`english` TEXT NOT NULL default '',\
	`russian` TEXT NOT NULL default '',\
	`english_answer` TEXT NOT NULL default '',\
	`russian_answer` TEXT NOT NULL default '',\
	PRIMARY KEY (`id`)\
);"

#define SIGNS_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS signs (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`name` varchar(24) NOT NULL,\
	`account_id` int(11) unsigned NOT NULL,\
	`sign` varchar(64) NOT NULL,\
	`ip` varchar(16) NOT NULL,\
	`points` int(11) unsigned NOT NULL default '0',\
	`total` int(11) unsigned NOT NULL default '0',\
	`date` int(11) unsigned NOT NULL default '0',\
	PRIMARY KEY (`id`)\
);"

#define SETTINGS_COLUMNS 5
#define SETTINGS_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS settings (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`pm` int(1) unsigned NOT NULL default '0',\
	`ding` int(1) unsigned NOT NULL default '0',\
	`duels` int(1) unsigned NOT NULL default '0',\
	`ability` int(1) unsigned NOT NULL default '0',\
	`auto_login` int(1) unsigned NOT NULL default '0',\
	PRIMARY KEY (`id`)\
);"

#define RULES_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS za_rules (\
	`id` int(11) unsigned NOT NULL,\
	`english` TEXT NOT NULL default '',\
	`russian` TEXT NOT NULL default '',\
	PRIMARY KEY (`id`)\
);"

#define HELP_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS za_help (\
	`id` int(11) unsigned NOT NULL,\
	`english` TEXT NOT NULL default '',\
	`russian` TEXT NOT NULL default '',\
	PRIMARY KEY (`id`)\
);"

#define WEEKLY_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS weekly_cfg (\
	`id` int(11) unsigned NOT NULL,\
	`next_update` int(11) unsigned NOT NULL default '0',\
	`period` int(6) unsigned NOT NULL default '604800',\
	`min_standing` int(4) unsigned NOT NULL default '2000',\
	`med_standing` int(4) unsigned NOT NULL default '4500',\
	`max_standing` int(4) unsigned NOT NULL default '7000',\
	`per_level` int(5) unsigned NOT NULL default '10000',\
	`activities` varchar(64) NOT NULL default '',\
	`types` varchar(48) NOT NULL default '',\
	`count` varchar(96) NOT NULL default '',\
	`rewards` varchar(24) NOT NULL default '',\
	PRIMARY KEY (`id`)\
);"

#define WEEKLY_ACTIVITIES_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS weekly_activities_cfg (\
	`id` int(11) unsigned NOT NULL,\	
	`activity` int(6) unsigned NOT NULL default '0',\
	`english` TEXT NOT NULL default '',\
	`russian` TEXT NOT NULL default '',\
	`count` int(4) unsigned NOT NULL default '0',\
	`type` int(6) unsigned NOT NULL default '0',\
	PRIMARY KEY (`id`)\
);"

#define WEEKLY_PLAYERS_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS weekly (\
	`id` int(11) unsigned NOT NULL,\
	`standing` int(11) unsigned NOT NULL default '0',\
	`coins` int(11) unsigned NOT NULL default '0',\
	`activities` varchar(128) NOT NULL default '',\
	`progress` varchar(32) NOT NULL default '',\
	PRIMARY KEY (`id`)\
);"

#define CLOTHES_CFG_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS clothes_cfg (\
	`id` int(11) unsigned NOT NULL,\
	`kit` int(6) unsigned NOT NULL,\
	`slot` int(1) unsigned NOT NULL default '0',\
	`model` int(11) unsigned NOT NULL,\
	`bone` int(2) unsigned NOT NULL,\
	`coords` varchar(128) NOT NULL,\
	PRIMARY KEY (`id`)\
);"

#define CLOTHES_LOCALIZATION_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS clothes_locale (\
	`id` int(11) unsigned NOT NULL,\
	`kit` int(6) unsigned NOT NULL,\
	`coins` int(3) unsigned NOT NULL default '1',\
	`emblems` int(3) unsigned NOT NULL default '1',\
	`english` TEXT NOT NULL default '',\
	`russian` TEXT NOT NULL default '',\
	PRIMARY KEY (`id`)\
);"

#define CLOTHES_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS clothes (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`account_id` int(11) unsigned NOT NULL,\
	`kit` int(6) unsigned NOT NULL,\
	PRIMARY KEY (`id`)\
);"

#define PREDIFINED_ACHS_LOCALIZATION_1 "INSERT IGNORE INTO `achievements_localization` (id, english, english_desc, russian, russian_desc) VALUES \
	(1, 'Trainee', 'Use your class ability %d times', 'Разминка', 'Используйте свою способность %d раз'),\
	(2, 'Semi Experienced', 'Use your class ability %d times', 'Упражнения', 'Используйте свою способность %d раз'),\
	(3, 'Experienced', 'Use your class ability %d times', 'Тренировка', 'Используйте свою способность %d раз'),\
	(4, 'Jogging', 'Run %d kilometers', 'Прогулка', 'Пробегите %d километров'),\
	(5, 'Runner', 'Run %d kilometers', 'Пробежка', 'Пробегите %d километров'),\
	(6, 'Olympic Champion', 'Run %d kilometers', 'Забег', 'Пробегите %d километров'),\
	(7, 'Lucky', 'Survive with a health of 1, %d times', 'Везение', 'Эвакуируйтесь с 1 ОЗ, %d раз'),\
	(8, 'Inviolable', 'Survive with a health of 1, %d times', 'На грани', 'Эвакуируйтесь с 1 ОЗ, %d раз'),\
	(9, 'Close To Death', 'Survive with a health of 1, %d times', 'На волоске', 'Эвакуируйтесь с 1 ОЗ, %d раз'),\
	(10, 'Maniac', 'Kill %d humans', 'Маньяк', 'Убейте %d людей'),\
	(11, 'Serial Maniac', 'Kill %d humans', 'Серийный Убийца', 'Убейте %d людей'),\
	(12, 'Jack The Ripper', 'Kill %d humans', 'Потрошитель', 'Убейте %d людей'),\
	(13, 'Conductor', 'Kill %d zombies', 'Проводник', 'Убейте %d зомби'),\
	(14, 'Undead Slayer', 'Kill %d zombies', 'Убийца Нежити', 'Убейте %d зомби'),\
	(15, 'Saint', 'Kill %d zombies', 'Святой', 'Убейте %d зомби'),\
	(16, 'Collector', 'Collect %d meats', 'Собиратель', 'Соберите %d мяса'),\
	(17, 'Butcher', 'Collect %d meats', 'Мясник', 'Соберите %d мяса'),\
	(18, 'Madman', 'Collect %d meats', 'Сумасшедший', 'Соберите %d мяса'),\
	(19, 'Ammo Belt', 'Collect %d ammo', 'Ремень с Патронами', 'Соберите %d патронов'),\
	(20, 'Ammo Box', 'Collect %d ammo', 'Ящик с Патронами', 'Соберите %d патронов');\
"

#define PREDIFINED_ACHS_LOCALIZATION_2 "INSERT IGNORE INTO `achievements_localization` (id, english, english_desc, russian, russian_desc) VALUES \
	(21, 'Ammo Depot', 'Collect %d ammo', 'Склад с Патронами', 'Соберите %d патронов'),\
	(22, 'Blood Lover', 'Achieve %d killstreaks', 'Любитель Крови', 'Достигните %d убийств за раз, не умирев'),\
	(23, 'Meat Lover', 'Achieve %d killstreaks', 'Любитель Мяса', 'Достигните %d убийств за раз, не умирев'),\
	(24, 'The Killer Machine', 'Achieve %d killstreaks', 'Машина По Уничтожению', 'Достигните %d убийств за раз, не умирев'),\
	(25, 'Nurse', 'Cure %d humans', 'Медсестра', 'Вылечите %d людей'),\
	(26, 'Medic', 'Cure %d humans', 'Медик', 'Вылечите %d людей'),\
	(27, 'Doctor', 'Cure %d humans', 'Доктор', 'Вылечите %d людей'),\
	(28, 'Risen From The Grave', 'Die %d times', 'Восставший', 'Умрите %d раз'),\
	(29, 'Dead Rising Army', 'Die %d times', 'Армия Мертвецов', 'Умрите %d раз'),\
	(30, 'Do Not Even Try', 'Die %d times', 'Даже Не Пытайся', 'Умрите %d раз'),\
	(31, 'Collection Point', 'Evac %d times', 'Точка Сбора', 'Эвакуируйтесь %d раз'),\
	(32, 'Safe Place', 'Evac %d times', 'Безопасное Место', 'Эвакуируйтесь %d раз'),\
	(33, 'Safe Zone', 'Evac %d times', 'Лагерь Выживших', 'Эвакуируйтесь %d раз'),\
	(34, 'In Cash', 'Get a total of %d points', 'При деньгах', 'Достигните в сумме %d очков'),\
	(35, 'Businessman', 'Get a total of %d points', 'Бизнессмен', 'Достигните в сумме %d очков'),\
	(36, 'Millionaire', 'Get a total of %d points', 'Миллионер', 'Достигните в сумме %d очков'),\
	(37, 'Unknown Virus', 'Infect %d humans', 'Неизвестный Вирус', 'Заразите %d людей');\
"

#define PREDIFINED_ACHS_LOCALIZATION_3 "INSERT IGNORE INTO `achievements_localization` (id, english, english_desc, russian, russian_desc) VALUES \
	(38, 'Disease', 'Infect %d humans', 'Болезнь', 'Заразите %d людей'),\
	(39, 'Mass Infection', 'Infect %d humans', 'Карантин', 'Заразите %d людей'),\
	(40, 'Fan', 'Play for a week in total', 'Игрок', 'Играйте в сумме в неделю'),\
	(41, 'Gamer', 'Play for a half a year in total', 'Обажатель', 'Играйте в сумме пол года'),\
	(42, 'Exanimate', 'Play for 1 year in total', 'Безжизненный', 'Играйте в сумме год'),\
	(43, 'Jumper', 'Jump %d times', 'Попрыгунчик', 'Прыгните %d раз'),\
	(44, 'Toad Paws', 'Jump %d times', 'Лягушачьи Лапки', 'Прыгните %d раз'),\
	(45, 'Pilot', 'Jump %d times', 'Пилот', 'Прыгните %d раз'),\
	(46, 'Let Me Think', 'Answer %d random questions', 'Дайте Подумать', 'Ответьте на %d случайных вопросов'),\
	(47, 'Quick Answer', 'Answer %d random questions', 'Быстрый Ответ', 'Ответьте на %d случайных вопросов'),\
	(48, 'Erudition', 'Answer %d random questions', 'Эрудиция', 'Ответьте на %d случайных вопросов'),\
	(49, 'Trembling', 'Win lottery %d times', 'Трепет', 'Выграйте %d раз в лотерее'),\
	(50, 'Within Temptation', 'Win lottery %d times', 'В Предвкушении', 'Выграйте %d раз в лотерее'),\
	(51, 'Casino', 'Win lottery %d times', 'Казино', 'Выграйте %d раз в лотерее'),\
	(52, 'This Is My Territory', 'Capture %d maps (Must be captured by another gang)', 'Это моя Территория', 'Захватите %d карт (Должна быть захвачена другой бандой)'),\
	(53, 'The Smell Of Prey', 'Capture %d maps (Must be captured by another gang)', 'Запах Добычи', 'Захватите %d карт (Должна быть захвачена другой бандой)'),\
	(54, 'The Beast Inside', 'Capture %d maps (Must be captured by another gang)', 'Зверь Внутри', 'Захватите %d карт (Должна быть захвачена другой бандой)');\
"

#define PREDIFINED_ACHS_LOCALIZATION_4 "INSERT IGNORE INTO `achievements_localization` (id, english, english_desc, russian, russian_desc) VALUES \
	(55, 'Street Shootout', 'Win %d duels (Bet on points)', 'Уличная Перестрелка', 'Выграйте %d дуэлей (Ставка на очки)'),\
	(56, 'Mud And Blood', 'Win %d duels (Bet on points)', 'Грязь и Кровь', 'Выграйте %d дуэлей (Ставка на очки)'),\
	(57, 'Steel Eggs', 'Win %d duels (Bet on points)', 'Стальные Яйца', 'Выграйте %d дуэлей (Ставка на очки)'),\
	(58, 'With Beer In Hand', 'Play %d hours withour quitting', 'С Пивом в Руках', 'Отыграйте %d часов за раз'),\
	(59, 'Do Your Best', 'Play %d hours withour quitting', 'Стараюсь Как Могу', 'Отыграйте %d часов за раз'),\
	(60, 'Excerpt', 'Play %d hours withour quitting', 'Выдержка', 'Отыграйте %d часов за раз'),\
	(61, 'Blood Letter', 'Draw First Blood %d times', 'Кровавое Письмо', 'Пустите Первую Кровь %d раз'),\
	(62, 'Recorder With Blood', 'Draw First Blood %d times', 'Диктофон с Кровью', 'Пустите Первую Кровь %d раз'),\
	(63, 'Blood Concert', 'Draw First Blood %d times', 'Кровавый Концерт', 'Пустите Первую Кровь %d раз'),\
	(64, 'Surrender', '/report %d cheaters', 'Сдавайся', 'Отправьте /report на читеров %d раз'),\
	(65, 'In A Cage', '/report %d cheaters', 'В Клетке', 'Отправьте /report на читеров %d раз'),\
	(66, 'We Are All In This Together', '/report %d cheaters', 'Мы Все Заодно', 'Отправьте /report на читеров %d раз'),\
	(67, 'Hush, Hush', 'Master Silinced Pistol', 'Тише, тише', 'Освойте Пистолет с Глушитилем'),\
	(68, 'Civil Defense', 'Master Colt45', 'Гражданская Оборона', 'Освойте Colt45'),\
	(69, 'With bros', 'Master Deagle', 'С Братанами', 'Освойте Дигл'),\
	(70, 'Stacks Of Hay', 'Master Rifle', 'Стопы Сена', 'Освойте Винтовку'),\
	(71, 'Arrest', 'Master Shotgun', 'Под Арест', 'Освойте Дробовик'),\
	(72, 'Special Forces', 'Master MP5', 'Спецназ', 'Освойте MP5'),\
	(73, 'Sergeant', 'Master Combat Shotgun', 'Сержант', 'Освойте Скорострельный Дробовик'),\
	(74, 'A Lot, A Little', 'Master Tec-9', 'Много, по немногу', 'Освойте Tec-9');\
"

#define PREDIFINED_ACHS_LOCALIZATION_5 "INSERT IGNORE INTO `achievements_localization` (id, english, english_desc, russian, russian_desc) VALUES \
	(75, 'From Russia with love', 'Master Ak47', 'Из России с Любовью', 'Освойте Ak47'),\
	(76, 'An Eagle Eye', 'Master M4', 'Орлиный Глаз', 'Освойте M4'),\
	(77, 'Master', 'Master all weapons', 'Мастер', 'Освойте все виды оружия'),\
	(78, 'Hermitage', 'Be the one man who evacuated', 'Одиночество', 'Будьте единственым мужчиной, который эвакуировался'),\
	(79, 'The Virgin Mary', 'Be the one woman who evacuated', 'Одиночество Марии', 'Будьте единственой женщиной, которая эвакуировалась'),\
	(80, 'Last Hope', 'Only a woman and a man alive', 'Последняя надежда', 'Лишь женщина и мужчина выжили'),\
	(81, 'Terrorist', 'Kill %d players', 'Террорист', 'Убейте %d игроков'),\
	(82, 'Gang Player', 'Join a gang', 'Задира', 'Вступите в банду'),\
	(83, 'Gang Deputy', 'Get 5 rank in a gang', 'Проныра', 'Получите 5 ранг в банде'),\
	(84, 'Gang Boss', 'Get 6 rank in a gang', 'Криминальный авторитет', 'Получите 6 ранг в банде'),\
	(85, 'Spine chills', 'Evacuate 5 times in a row (Min. 10 players)', 'Мурашки по спине', 'Эвакуируйтесь 5 раз не умирая (Мин. 10 игроков)'),\
	(86, 'By a thread', 'Evacuate 10 times in a row (Min. 10 players)', 'На волоске', 'Эвакуируйтесь 10 раз не умирая (Мин. 10 игроков)'),\
	(87, 'Schizophrenia', 'Evacuate 15 times in a row (Min. 10 players)', 'Шизофрения', 'Эвакуируйтесь 15 раз не умирая (Мин. 10 игроков)'),\
	(88, 'In the oncoming lane', 'Deal 100,000 damage to vehicles', 'На встречной полосе', 'Нанесите 100,000 урона технике'),\
	(89, 'Road accident', 'Deal 350,000 damage to vehicles', 'ДТП', 'Нанесите 350,000 урона технике'),\
	(90, 'Taken apart', 'Deal 500,000 damage to vehicles', 'На запчасти', 'Нанесите 500,000 урона технике');\
"

#define PREDIFINED_ACHS_CFG "INSERT IGNORE INTO `achievements_config` (id, type, count, reward, disabled) VALUES \
	(1, 0, 10, 1, 0),\
	(2, 0, 500, 1, 0),\
	(3, 0, 1000, 1, 0),\
	(4, 1, 10000, 1, 0),\
	(5, 1, 50000, 1, 0),\
	(6, 1, 200000, 1, 0),\
	(7, 2, 3, 1, 0),\
	(8, 2, 10, 1, 0),\
	(9, 2, 20, 1, 0),\
	(10, 3, 10, 1, 0),\
	(11, 3, 100, 1, 0),\
	(12, 3, 1000, 1, 0),\
	(13, 4, 10, 1, 0),\
	(14, 4, 100, 1, 0),\
	(15, 4, 1000, 1, 0),\
	(16, 5, 100, 1, 0),\
	(17, 5, 1000, 1, 0),\
	(18, 5, 5000, 1, 0),\
	(19, 6, 100, 1, 0),\
	(20, 6, 1000, 1, 0),\
	(21, 6, 5000, 1, 0),\
	(22, 7, 5, 1, 0),\
	(23, 7, 50, 1, 0),\
	(24, 7, 100, 1, 0),\
	(25, 8, 10, 1, 0),\
	(26, 8, 100, 1, 0),\
	(27, 8, 300, 1, 0),\
	(28, 9, 10, 1, 0),\
	(29, 9, 100, 1, 0),\
	(30, 9, 1000, 1, 0),\
	(31, 10, 5, 1, 0),\
	(32, 10, 100, 1, 0),\
	(33, 10, 300, 1, 0),\
	(34, 11, 10000, 1, 0),\
	(35, 11, 50000, 1, 0),\
	(36, 11, 100000, 1, 0),\
	(37, 12, 50, 1, 0),\
	(38, 12, 300, 1, 0),\
	(39, 12, 1000, 1, 0),\
	(40, 13, 168, 1, 0),\
	(41, 13, 4383, 1, 0),\
	(42, 13, 8760, 1, 0),\
	(43, 14, 100, 1, 0),\
	(44, 14, 300, 1, 0),\
	(45, 14, 700, 1, 0),\
	(46, 15, 10, 1, 0),\
	(47, 15, 50, 1, 0),\
	(48, 15, 100, 1, 0),\
	(49, 16, 10, 1, 0),\
	(50, 16, 20, 1, 0),\
	(51, 16, 30, 1, 0),\
	(52, 17, 10, 1, 0),\
	(53, 17, 20, 1, 0),\
	(54, 17, 30, 1, 0),\
	(55, 18, 10, 1, 0),\
	(56, 18, 30, 1, 0),\
	(57, 18, 70, 1, 0),\
	(58, 19, 2, 1, 0),\
	(59, 19, 6, 1, 0),\
	(60, 19, 12, 1, 0),\
	(61, 20, 10, 1, 0),\
	(62, 20, 30, 1, 0),\
	(63, 20, 60, 1, 0),\
	(64, 21, 50, 1, 0),\
	(65, 21, 100, 1, 0),\
	(66, 21, 200, 1, 0),\
	(67, 22, 1000, 1, 0),\
	(68, 23, 1000, 1, 0),\
	(69, 24, 1000, 1, 0),\
	(70, 25, 1000, 1, 0),\
	(71, 26, 1000, 1, 0),\
	(72, 27, 1000, 1, 0),\
	(73, 28, 1000, 1, 0),\
	(74, 29, 1000, 1, 0),\
	(75, 30, 1000, 1, 0),\
	(76, 31, 1000, 1, 0),\
	(77, 32, 1, 1, 0),\
	(78, 33, 1, 1, 0),\
	(79, 34, 1, 1, 0),\
	(80, 35, 1, 1, 0),\
	(81, 36, 10000, 1, 0),\
	(82, 37, 1, 1, 0),\
	(83, 37, 5, 1, 0),\
	(84, 37, 6, 1, 0),\
	(85, 38, 5, 1, 0),\
	(86, 38, 10, 1, 0),\
	(87, 38, 15, 1, 0),\
	(88, 39, 100000, 1, 0),\
	(89, 39, 350000, 1, 0),\
	(90, 39, 500000, 1, 0);\
"

#define PREDIFINED_RND_QUESTIONS "INSERT IGNORE INTO `random_question` (id, english, russian, english_answer, russian_answer) VALUES \
	(1, 'What is the name of the planet closest to the sun?', 'Как называется планета, ближайшая к Солнцу?', 'Mercury', 'Меркурий'),\
	(2, 'Which country has a plain green flag?', 'Какая страна имеет зеленый флаг?', 'Brazil', 'Ливия'),\
	(3, 'What causes craters on the moon?', 'Что создает кратеры на Луне?', 'Meteorites', 'Метеориты'),\
	(4, 'The sunniest figure in geometry?', 'Самая солечная фигура в гиометрии?', 'Beam', 'Луч'),\
	(5, 'This month is called summer sunset. Which one?', 'Какой месяц можно назвать летним закатом?', 'August', 'Август'),\
	(6, 'What chemical element caused the death of Napoleon?', 'Какой химический элемент вызвал смерть Наполеона?', 'Arsenic', 'Мышьяк'),\
	(7, 'Where did the accordion first appear?', 'Где впервые появился аккордеон?', 'Australia', 'Австралия'),\
	(8, 'The deepest freshwater lake in the world?', 'Самое глубокое пресноводное озеро в мире?', 'Baikal', 'Байкал'),\
	(9, 'What is the name of the water shell of the earth?', 'Как называется водная оболочка земли?', 'Hydrosphere', 'Гидросфера'),\
	(10, 'Which bird is called the forest doctor?', 'Какую птицу называют лесным врачом?', 'Woodpecker', 'Дятел'),\
	(11, 'The highest point, above sea level, in Africa?', 'Самая высокая точка над уровнем моря в Африке?', 'Kilimanjaro', 'Килиманджаро'),\
	(12, 'Gas, which is formed during photosynthesis of plants?', 'Газ, который образуется при фотосинтезе растений?', 'Oxygen', 'Кислород'),\
	(13, 'What month does Australia start in autumn?', 'Какой месяц в Австралии начинается осенью?', 'March', 'Март'),\
	(14, 'What besides flags often fans wave in the stands?', 'Чем помимо флагов часто фанаты машут на трибунах?', 'Scarves', 'Шарфы'),\
	(15, 'Which US president wrote his own story about Sherlock Holmes?', 'Какой президент США написал свой собственный рассказ о Шерлоке Холмсе?', 'Franklin Roosevelt', 'Франклин Рузвельт'),\
	(16, 'Which of the famous artists in his life sold just one painting?', 'Кто из известных художников в своей жизни продал только одну картину?', 'Vincent Van Gogh', 'Винсент Ван Гог'),\
	(17, 'How many eyes does an ordinary fly have?', 'Сколько глаз у обычной мухи?', 'Five', 'Пять'),\
	(18, 'Every day, the Earth adds 400 tons in weight. Due to what?', 'Каждый день Земля прибавляет в весе 400 тонн. Из-за чего?', 'Cosmic dust', 'Космическая пыль'),\
	(19, 'What stones are not in the sea?', 'Каких камней нет в море?', 'Dry', 'Сухих'),\
	(20, 'Which wheel does not spin in a right turn?', 'Какое колесо не вращается при правом развороте?', 'Spare wheel', 'Запасное');\
"

#define PREDIFINED_RND_MSGS "INSERT IGNORE INTO random_messages (id, english, russian) VALUES \
	(1, '>> Want to talk about something personal? Use /pm!', '>> Хотите поговорить о чем-то личном? Используйте /pm'),\
	(2, '>> Change your class using /class!', '>> Измените свой класс, использовав /class'),\
	(3, '>> As a Human, you must survive. As a Zombie, you must kill humans!', '>> Как человек, вы должны выжить. Как зомби, вы должны убивать людей!'),\
	(4, '>> Earn points for active playing!', '>> Зарабатывайте очки за активную игру!'),\
	(5, '>> Newbie? We advise you to look /cmds, /help, /rules!', '>> Новичек? Советуем использовать /cmds, /help, /rules'),\
	(6, '>> Use /report to report rulebreakers and get points!', '>> Используйте /report чтобы сообщать о нарушителях и получайте очки!'),\
	(7, '>> Want to become a team player? Join the gang /gang join!', '>> Хотите стать командным игроком? Вступайте в клан /gang join'),\
	(8, '>> Did you see the cheater? Use /votekick if no admins online!', '>> Увидели нарушителя? Используйте /votekick если администрация не в сети!'),\
	(9, '>> Almost each class has unique ability. Use LEFT ALT to activate it!', '>> Почти каждый класс имеет уникальную способность. Используйте Левый Альт, чтобы активировать ее!'),\
	(10, '>> Medics can cure humans by using rifle!', '>> Медики могут лечить людей выстрелив в них с винтовки!'),\
	(11, '>> You can save your stats with /ss!', '>> Вы можете сохранить свою статистику использовав /ss!'),\
	(12, '>> Do not forget to add our server to favorites!', '>> Не забудьте добавить наш сервер в избранное!'),\
	(13, '>> You can change some settings, check /settings!', '>> Вы можете настроить некоторые настройки под себя, используйте /settings!'),\
	(14, '>> Используйте /language, чтобы сменить язык', '>> You can change language by using /language'),\
	(15, '>> You can gain coins by completing /achievements!', '>> Вы можете получить монеты, выполняя достижения! (/achievements)'),\
	(16, '>> You can gain points by winning in /lottery!', '>> Вы можете получить очки, выигрывая в лотерею! (/lottery)'),\
	(17, '>> You can get attachments by completing weekly activities! (/weekly)', '>> Вы можете получить предметы одежды за выполнение еженедельных заданий! (/weekly)'),\
	(18, '>> You can improve your weapon skills faster by winning duels for points!', '>> Вы можете улучшать навыки владения оружием быстрее побеждая в дуэлях на очки!'),\
	(19, '>> The gang that captured the map has 50 armor and better weapons!', '>> Банда, захватившая карту, имеет 50 брони и улучшеное оружие!'),\
	(20, '>> Gain and lose ranks by competing in duels!', '>> Получайте и теряйте ранги соревнуясь в дуэлях!');\
"

#define PREDIFINED_GANGS_CONFIG "INSERT IGNORE INTO gangs_config (id) VALUES (1);"
#define PREDIFINED_CONFIG "INSERT IGNORE INTO config (id) VALUES (1);"
#define PREDIFINED_ANTICHEAT "INSERT IGNORE INTO anticheat (id) VALUES (1);"
#define PREDIFINED_ROUND_CONFIG "INSERT IGNORE INTO round_config (id) VALUES (1);"
#define PREDIFINED_EVAC_CONFIG "INSERT IGNORE INTO evac_config (id) VALUES (1);"
#define PREDIFINED_MAP_CONFIG "INSERT IGNORE INTO map_config (id) VALUES (1);"
#define PREDIFINED_BALANCE_CONFIG "INSERT IGNORE INTO balance_config (id) VALUES (1);"
#define PREDIFINED_CLASSES_CONFIG "INSERT IGNORE INTO classes_config (id) VALUES (1);"
#define PREDIFINED_DUELS_CONFIG "INSERT IGNORE INTO duels_config (id) VALUES (1);"

#define PREDIFINED_MAPS "INSERT IGNORE INTO \
	`maps` (`id`, `filename`, `interior`, `weather`, `time`, `water`, `checkpoint`, `humans_coords`, `zombies_coords`, `camera_coords`, `gates_id`, `gates_coords`, `gates_move`,  `flag_coords`, `flag_text`, `disabled`) \
	VALUES \
	(1, 'village', 0, 6, 23, 1, '15.0,681.8102,-508.0689,16.1875', '681.7961,-557.6867,16.1875,1.3275,655.5219,-546.1632,16.3359,357.2775,661.8522,-460.3403,16.3359,180.6026', '741.9293,-549.5023,17.0694,354.7242,623.4771,-506.2735,16.3525,88.4586,611.7243,-601.8662,17.2266,272.0502', '676.6566,-460.0044,27.1080,676.7922,-460.9932,26.9030', '', '',  '', '672.4241,-540.2498,17.5474,0.0000,290.0000,347.5840', '673.0986,-540.4794,18.4757', 0),\
	(2, 'area51', 0, 6, 12, 1, '15.0,40.7631, 1926.4884, 20.4740', '205.8697,1861.7646,13.1406,359.7609,218.3002,1862.0453,13.1470,3.2076,213.4941,1870.2069,13.1406,0.0743', '129.9853,1933.0864,19.2458,184.6293,141.1911,1933.0723,19.2429,181.1826,119.1792,1902.8755,18.6035,359.1342', '8.2182, 1875.4252,46.0364,8.9282,1876.1360,45.5263', '8674', '96.8059,1920.4825,19.8964,0.0,90.0,270.0', '96.8059,1920.4825,26.6360,0.0,90.0,270.0', '188.8057,1921.2452,21.8361,0.0,0.0,257.7737', '188.4427,1921.4395,20.9732', 0),\
	(3, 'aircraft', 0, 6, 23, 0, '10.0,-1267.0817, 502.9364, 17.2233', '-1310.7435,506.1808,11.1953,89.9783,-1412.8375,505.5197,11.1953,267.3267,-1424.8868,497.0233,11.1953,269.2067', '-1398.1670,509.0323,3.0391,177.7125,-1412.9148,501.1045,3.0391,270.7734,-1390.7615,492.2116,3.0391,357.2776', '-1246.4172,539.9838,41.0123,-1247.1200,539.2711,40.5823', '2944', '-1348.5950,499.4212,18.7097,0.0,0.0,90.0', '-1349.85,499.4212,18.7097,0.0,0.0,90.0', '-1454.4364,502.4528,11.4543,0.0,290.0,270.0', '-1454.4346,501.7881,11.4091', 0),\
	(4, 'area51', 10, 0, 12, 0, '10.0,-973.6262,1077.4434,1344.0015', '-1131.4468,1057.8196,1346.4163,271.7368,-1133.2869,1046.7906,1345.7609,270.1702,-1132.1740,1035.9816,1345.7395,271.1102', '-971.7824,1068.7997,1345.0138,90.3150,-971.9465,1073.8569,1345.0071,89.3750,-973.8672,1061.1390,1345.6736,86.8683', '-1039.4342,1072.1166,1351.5865,-1040.1729,1071.4478,1351.4718', '', '', '', '-1106.1906,1082.2078,1343.4412,0.0,290.0,0.0', '-1105.3647,1083.2095,1343.0952', 0);\
"

#define PREDIFINED_LOCAL_MAPS "INSERT IGNORE INTO maps_localization (id, english, russian) VALUES \
	(1, 'The Village', 'Деревня'),\
	(2, 'Area 51', 'Зона 51'),\
	(3, 'Aircraft Carrier', 'Авианосец'),\
	(4, 'RC Field', 'Игровое поле');\
"

#define PREDIFINED_WEEKLY_ACTIVITIES "INSERT IGNORE INTO weekly_activities_cfg (id, activity, english, russian, type, count) VALUES \
	(1, 0, 'Kill %d human boses', 'Убейте %d героев', 2, 10),\
	(2, 1, 'Achieve %d killstreaks in a row', 'Достигните серии из %d убийств подряд', 2, 100),\
	(3, 2, 'Kill %d players', 'Убейте %d игроков', 2, 500),\
	(4, 3, 'Draw First Blood %d times', 'Пустите первую кровь %d раз', 2, 10),\
	(5, 4, 'Kill %d zombie bosses', 'Убейте %d зомби боссов', 1, 10),\
	(6, 5, 'Kill %d humans', 'Убейте %d людей', 1, 50),\
	(7, 6, 'Kill %d zombies', 'Убейте %d зомби', 1, 200),\
	(8, 7, 'Collect %d points', 'Получите %d очков', 1, 5000),\
	(9, 8, 'Infect %d humans', 'Заразите %d людей', 0, 100),\
	(10, 9, 'Cure %d humans', 'Выличите %d людей', 0, 100),\
	(11, 10, 'Use ability %d times', 'Используйте способности %d раз', 0, 300),\
	(12, 11, 'Collect %d meats', 'Соберите %d мяса с зомби', 0, 100),\
	(13, 12, 'Evacuate %d times', 'Эвакуируйтесь %d раз', 0, 5),\
	(14, 13, 'Jump %d times', 'Прыгните %d раз', 0, 500);\
"

#define PREDIFINED_LOCALE_CLASSES_10 "INSERT IGNORE INTO classes_localization (id, english_title, russian_title, english_desc, russian_desc) VALUES \
	(1, 'Civillian', 'Гражданский', 'Silinced Pistol', 'Пистолет с глушитилем'),\
	(2, 'Gangster', 'Гангстер', 'Pistol, Spraycan', 'Пистолет, Аэрозоль'),\
	(3, 'Policeman', 'Полицейский', 'Pistol, Shotgun', 'Пистолет, Дробовик'),\
	(4, 'Farmer', 'Фермер', 'Rifle', 'Винтовка'),\
	(5, 'Soldier', 'Солдат', 'Ak47', 'Ak47'),\
	(6, 'Warm Person', 'Человек в шубе', 'Anti-Freeze', 'Антифриз'),\	
	(7, 'Medic', 'Медик', 'Cure Rifle', 'Лечащая винтовка'),\
	(8, 'Scout', 'Скаут', 'Sniper', 'Снайперская винтовка'),\
	(9, 'Rollerskater', 'Конькобежец', 'Rollerskaters', 'Ролики'),\
	(10, 'Mi7', 'Mi7', 'Pistol, Ak47, Shotgun', 'Пистолет, Ak47, Дробовик'),\
	(11, 'Toughie', 'Крепкий орешек', 'Anti-Stomper', 'Анти-Топтун'),\
	(12, 'Pyromaniac', 'Пироманьяк', 'Anti-Radioactive', 'Защита От Радиации'),\
	(13, 'Engineer', 'Инжинер', 'Can Build 6 Boxes', 'Может Создать 6 Коробок'),\
	(14, 'Sharpshooter', 'Меткий стрелок', 'Sniper, Immunity', 'Снайперская винтовка, Иммунитет');\
"

#define PREDIFINED_LOCALE_CLASSES_20 "INSERT IGNORE INTO classes_localization (id, english_title, russian_title, english_desc, russian_desc) VALUES \	
	(15, 'Terrorist', 'Террорист', 'C4', 'C4'),\	
	(16, 'Runner', 'Бегун', 'Fast run', 'Быстрый бег'),\
	(17, 'S.W.A.T', 'Спецназовец', 'MP5, Ak47, Shotgun, Immunity', 'MP5, Ak47, Дробовик, Иммунитет'),\
	(18, 'Rocketman', 'Техник', 'Rocketboots', 'Реактивные ботинки'),\
	(19, 'Mimic', 'Мимик', 'Mimicry, Immunity', 'Мимикрия, Иммунитет'),\
	(20, 'Priest', 'Священник', 'Anti-Curse Field', 'Защитное Поле От Проклятья'),\
	(21, 'Athlete', 'Атлет', 'Long Jumps', 'Длинные прыжки'),\
	(22, 'Nurse', 'Медсестра', 'Cure Field, Anti-Radioactive Field', 'Лечащее Поле, Анти-Радиационное поле'),\
	(23, 'Poisoner', 'Отравитель', 'Poisoned Bullets', 'Отравленые пули'),\
	(24, 'Iron Man', 'Железный Человек', 'Fast Run, Long Jumps', 'Быстрый бег, Длинные прыжки'),\
	(25, 'Architect', 'Архитектор', 'Can build 9 boxes, Immunity', 'Может создать 9 коробок, Иммунитет'),\
	(26, 'Imaginary Doctor', 'Мнимый доктор', 'Space Traveling', 'Путишествие в пространстве'),\
	(27, 'Human Queen', 'Королева', 'Long Jumps, Immunity', 'Длиные прыжки, Иммунитет');\
"

#define PREDIFINED_LOCALE_CLASSES_30 "INSERT IGNORE INTO classes_localization (id, english_title, russian_title, english_desc, russian_desc) VALUES \
	(28, 'Standard Zombie', 'Обычный Зомби', 'Can Infect', 'Может Заразить'),\
	(29, 'Misty Zombie', 'Туманный Зомби', 'Infection Drunk Vision', 'Зараженный Теряет Точность'),\
	(30, 'Blind Zombie', 'Ослепляющий Зомби', 'Infection Blinds', 'Зараженный Перестает Видеть'),\
	(31, 'Flesher Zombie', 'Гнилой Зомби', 'Infected Meat', 'Зараженное Мясо'),\
	(32, 'Regenerator Zombie', 'Регенератор Зомби', 'Can Regenerate HP', 'Может Восстанавливать ХП'),\
	(33, 'Support Zombie', 'Зомби Поддержка', 'Heals In A Range', 'Восстанавливает ХП В Радиусе'),\
	(34, 'Gangster Zombie', 'Гангстер Зомби', 'Can Steal Armour', 'Может Украсть Броню'),\
	(35, 'Boomer Zombie', 'Взрывающийся Зомби', 'Explodes And Infects On Death', 'Взрывается И Заражает При Смерти'),\
	(36, 'Jumper Zombie', 'Зомби Прыгун', 'High Jump', 'Высокий Прыжок'),\
	(37, 'Jumper Boomer Zombie', 'Взрывающийся Зомби Прыгун', 'High Jump And Explode', 'Высокий Прыжок И Взрыв'),\
	(38, 'Mega Jumper Zombie', 'Мега Зомби Прыгун', 'High Jumps', 'Высокие Прыжки'),\
	(39, 'Stomper Zombie', 'Топтун Зомби', 'Can Stomp Humans', 'Может Отбрасывать Людей'),\
	(40, 'Kamikaze Zombie', 'Камикадзе Зомби', 'Explodes On Request', 'Взрывается по желанию'),\
	(41, 'Spacebreaker Zombie', 'Зомби Крушащий Пространство', 'Space Traveling', 'Путишествие в пространстве'),\
	(42, 'Mimic Zombie', 'Мимик Зомби', 'Mimicry', 'Мимикрия');\
"

#define PREDIFINED_LOCALE_CLASSES_40 "INSERT IGNORE INTO classes_localization (id, english_title, russian_title, english_desc, russian_desc) VALUES \
	(43, 'Freezer Zombie', 'Холодный Зомби', 'Can Freeze', 'Может Заморозить'),\
	(44, 'Radioactive Zombie', 'Радиоактивный Зомби', 'Radioactive Field', 'Радиоактивное Поле'),\
	(45, 'Flash Zombie', 'Невероятно Быстрый Зомби', 'Lighting Attack', 'Мгновенная атака'),\
	(46, 'Spitter Zombie', 'Плюющийся Зомби', 'Can Infect In A Range', 'Может Заразить С Расстояния'),\
	(47, 'Mutated Zombie', 'Мутированный Зомби', 'Airborne Infection', 'Воздушно-капельная Инфекция'),\
	(48, 'Stealer Zombie', 'Вор Зомби', 'Can Steal Ammo', 'Крадет Патроны'),\
	(49, 'Legs Breaker Zombie', 'Ветеран Зомби', 'Can Break Human Legs', 'Ломает Ноги Людям'),\
	(50, 'Spore Zombie', 'Споровой Зомби', 'Can Infect By Spores', 'Заражает спорами'),\
	(51, 'Fast Zombie', 'Быстрый Зомби', 'Fast Run', 'Быстрый бег'),\
	(52, 'Enforcer Zombie', 'Пуленепробеваемый Зомби', 'Armour', 'Броня'),\
	(53, 'Witch Zombie', 'Зомби Ведьма', 'Can curse', 'Может проклясть'),\
	(54, 'Mirror Zombie', 'Отражающий Зомби', 'Reflect Damage', 'Отражает урон'),\
	(55, 'Special Force Zombie', 'Зомби Спецназовец', 'Armour, Remove Weapons', 'Броня, Убирает оружие');\
"

#define PREDIFINED_HUMANS "INSERT IGNORE INTO classes (id, team, points, ability, count, immunity, weapons, cooldown, time, skin, distance, disabled) VALUES \
	(1, 2, 0, '', 0, '', '23', 0, 0, 121, 0, 0),\
	(2, 2, 500, '', 0, '', '22, 41', 0, 0, 105, 0, 0),\
	(3, 2, 750, '', 0, '', '22, 25', 0, 0, 280, 0, 0),\
	(4, 2, 1000, '', 0, '', '33, 25', 0, 0, 201, 0, 0),\	
	(5, 2, 1500, '', 0, '', '30', 0, 0, 287, 0, 0),\
	(6, 2, 2000, '', 0, '16', '22,25', 0, 0, 249, 0, 0),\	
	(7, 2, 3000, '25', 0, '', '22,25, 33', 0, 0, 308, 0, 0),\
	(8, 2, 5000, '', 0, '', '34', 0, 0, 294, 0, 0),\
	(9, 2, 9000, '', 0, '', '22,25', 0, 0, 99, 0, 0),\
	(10, 2, 12500, '', 0, '', '22,30,25', 0, 0, 164, 0, 0),\
	(11, 2, 15000, '', 0, '12', '30, 22', 0, 0, 109, 0, 0),\
	(12, 2, 20000, '', 0, '17', '37, 22, 25', 0, 0, 277, 0, 0),\
	(13, 2, 35000, '26', 5, '', '22, 30, 33', 0, 0, 27, 0, 0),\
	(14, 2, 50000, '', 0, '1', '34', 0, 0, 286, 0, 0),\
	(15, 2, 70000, '', 0, '', '25, 39', 0, 0, 3, 0, 0),\
	(16, 2, 90000, '', 0, '', '22, 30', 0, 0, 0, 0, 0),\
	(17, 2, 125000, '', 0, '1', '29, 25, 30', 0, 0, 285, 0, 0),\
	(18, 2, 180000, '11', 0, '', '25, 30, 33', 15, 0, 50, 0, 0),\
	(19, 2, 225000, '15', 0, '', '29, 30', 60, 30, 97, 0, 0),\
	(20, 2, 300000, '29', 0, '22', '22, 30', 0, 0, 68, 10.0, 0),\
	(21, 2, 300000, '27', 3, '', '25, 32', 5, 0, 170, 0, 0),\
	(22, 2, 400000, '28', 0, '1,17', '22, 30, 33', 0, 0, 308, 10.0, 0),\
	(23, 2, 500000, '30', 0, '', '22, 30, 33, 25', 0, 0, 143, 0, 0),\
	(24, 2, 600000, '27', 3, '', '25, 33, 37', 5, 0, 0, 0, 0),\
	(25, 2, 850000, '26', 8, '1', '22, 30, 34', 0, 0, 153, 0, 0),\
	(26, 2, 1000000, '14', 0, '', '22, 29', 15, 10, 70, 0, 0),\
	(27, 2, 1500000, '27', 3, '1', '22, 30, 33', 5, 0, 92, 0, 0);\
"

#define PREDIFINED_ZOMBIES "INSERT IGNORE INTO classes (id, team, points, armour, health, ability, count, cooldown, `time`, skin, distance, disabled) VALUES \
	(28, 1, 0, 0, 100, '1', 0, 5, 0, 181, 1.5, 0),\
	(29, 1, 500,  0, 100, '2', 0, 5, 0, 1, 1.5, 0),\
	(30, 1, 1500, 0, 100, '3', 0, 5, 15, 213, 1.5, 0),\
	(31, 1, 2500, 0, 100, '4', 0, 0, 0, 181, 0, 0),\
	(32, 1, 5000, 0, 100, '5', 0, 0, 0, 70, 0, 0),\
	(33, 1, 7500, 0, 100, '6', 0, 0, 0, 75, 10.0, 0),\
	(34, 1, 25000,0, 100, '9', 0, 15, 0, 28, 3.5, 0),\
	(35, 1, 5000, 0, 45, '10',0, 0, 0, 264, 7.0, 0),\
	(36, 1, 15000, 0, 100, '11', 0, 15, 0, 162, 0, 0),\
	(37, 1, 25000, 0, 100, '10,11', 0, 15, 0, 162, 7.0, 0),\
	(38, 1, 30000, 0, 100, '27', 5, 5, 0, 162, 0, 0),\
	(39, 1, 35000, 0, 100, '12', 0, 15, 0, 78, 10.0, 0),\
	(40, 1, 10000, 0, 45, '13', 0, 0, 0, 241, 5.0, 0),\
	(41, 1, 250000, 0, 100, '14', 0, 15, 0, 79, 0, 0),\
	(42, 1, 75000,  0, 100, '15', 0, 60, 30, 135, 0, 0),\
	(43, 1, 45000,  0, 45, '16', 0, 30, 10, 137, 5.5, 0),\
	(44, 1, 50000,  0, 100, '17', 0, 0, 0, 146, 10.0, 0),\
	(45, 1, 35000,  0, 100, '18', 0, 30, 0, 230, 0, 0),\
	(46, 1, 125000, 0, 100, '19', 1, 15, 0, 96, 0, 0),\
	(47, 1, 150000, 0, 100, '20', 0, 15, 0, 200, 1.5, 0),\
	(48, 1, 150000, 0, 100, '7',  0, 15, 0, 209, 1.5, 0),\
	(49, 1, 150000, 0, 100, '8',  0, 15, 0, 30, 1.5, 0),\
	(50, 1, 250000, 0, 100, '21', 0, 0, 0, 136, 0, 0),\
	(51, 1, 400000, 0, 100, '', 0, 0, 0, 0, 0, 0),\
	(52, 1, 850000, 100, 100, '', 0, 0, 0, 285, 0, 0),\
	(53, 1, 600000, 0, 100, '22', 0, 15, 0, 129, 1.5, 0),\
	(54, 1, 700000, 0, 100, '23', 0, 0, 0, 112, 0, 0),\
	(55, 1, 1000000, 100, 100, '24', 0, 0, 0, 285, 10.0, 0);\
"

#define PREDIFINED_TEXTURES "INSERT IGNORE INTO `textures_config` (`id`, `position`, `letter_size`, `text_size`, `default_value`, `background_color`, `texture_font`, `texture_draw_color`, `texture_outline`, `texture_proportional`, `texture_shadow`, `texture_use_box`, `texture_box_color`, `texture_alignment`) VALUES \
	(1, '22.000000, 251.000000', '1.770000, 3.499999', '0.0,0.0', '300', '255', 3, 'FFFFFF', 1, 1, 1, 0, '0', 0),\
	(2, '655.500000, 1.500000', '0.000000, 50.262496', '-2.000000, 0.000000', 'usebox', '255', 0, '0', 0, 1, 1, 1, '0xFF0000BB', 0),\
	(3, '14.000000, 283.937500', '0.000000, 0.000000', '119.500000, 21.437500', 'LD_SPAC:white', '0x000000FF', 4, '0x000000FF', 0, 0, 0, 0, '0', 1),\
	(4, '18.500000, 285.250000', '0.562500, 1.984999', '0.0,0.0', 'UNTIL EVAC', '0x000000FF', 1, '0xFF0000FF', 1, 1, 0, 0, '0', 1),\
	(5, '21.500000, 220.000000', '0.511498, 1.477498', '0.0,0.0', '~w~humans: 0~n~~r~zombies: 0', '0x000000FF', 2, '0xFFFFFFFF', 0, 1, 1, 0, '0', 1),\
	(6, '546.000000, 35.000000', '0.270000, 1.000000', '0.0,0.0', '0', '0x000000FF', 2, '0x0d8adeFF', 0, 1, 1, 0, '0', 0),\
	(7, '0.0,0.0', '0.0,0.0', '640.0,450.0', 'LD_SPAC:white', '0xFFFFFFFF', '4', '0x000000FF', '0', '0', '0', '0', '0', '1'),\
	(8, '300.000000,426.875000', '0.637500,2.107499', '0.0,0.0', 'null', '0x000000FF', '2', '0xFFFFFFFF', '0', '1', '1', '0', '0', '1');\
"

#define PREDIFINED_WEAPONS "INSERT IGNORE INTO weapons_config (id, type, chance, `default`, pick) VALUES \
	(1, 22, 100, 150, 10),\
	(2, 23, 100, 150, 10),\
	(3, 24, 75, 50, 10),\
	(4, 25, 75, 75, 10),\
	(5, 27, 5, 50, 3),\
	(6, 28, 12, 150, 50),\
	(7, 29, 5, 500, 35),\
	(8, 30, 9, 500, 20),\
	(9, 31, 5, 500, 35),\
	(10, 32, 9, 1500, 100),\
	(11, 33, 20, 30, 3),\
	(12, 34, 20, 150, 3),\
	(13, 35, 1, 5, 1),\
	(14, 36, 1, 5, 1),\
	(15, 37, 1, 500, 150),\
	(16, 39, 10, 50, 2),\
	(17, 41, 100, 1500, 250);\
"

#define PREDIFINED_CLOTHES "INSERT IGNORE INTO `clothes_cfg` (id, kit, slot, model, bone, coords) VALUES \
	(1, 1, 0, 2036,  1, '0.150, -0.125, -0.069, 85.400, -4.000, -20.300, 1.000, 1.000, 1.000'),\
	(2, 2, 0, 2035,  1, '0.095, -0.081, 0.015, 89.299, -3.800, 153.199, 1.000, 1.000, 1.000'),\
	(3, 3, 0, 19317, 1, '0.147, -0.093, -0.037, 0.000, 115.700, 0.000, 0.535, 1.000, 0.503'),\
	(4, 4, 0, 2406,  1, '0.093, -0.114, -0.011, 0.000, 126.199, 0.000, 0.509, 1.000, 0.322'),\
	(5, 5, 0, 1210,  5, '0.282, 0.068, -0.035, 0.000, -85.200, 7.499, 1.000, 1.000, 1.000'),\
	(6, 6, 0, 19559, 1, '0.095, -0.046, 0.000, 1.199, 90.800, -1.100, 0.795, 1.000, 1.000'),\
	(7, 7, 0, 19528, 2, '0.134, 0.000, 0.000, 0.000, 0.000, 0.000, 1.000, 1.000, 1.000'),\
	(8, 7, 1, 19527, 1, '0.000, -0.213, -0.020, 45.300, 87.999, 0.000, 0.275, 0.256, 0.322'),\
	(9, 7, 2, 19320, 1, '0.263, -0.220, -0.015, 0.000, 83.299, 0.000, 0.132, 0.105, 0.193'),\
	(10, 8, 0, 19064, 2, '0.136, 0.000, 0.000, 0.000, 89.699, 93.499, 1.000, 1.000, 1.000'),\
	(11, 8, 1, 19054, 1, '0.168, -0.189, 0.000, -7.999, 92.900, 5.300, 0.207, 0.214, 0.276'),\
	(12, 9, 0, 342, 7, '0.047, 0.083, -0.006, -58.299, -60.499, 116.899, 1.000, 1.000, 1.000'),\
	(13, 9, 1, 353, 8, '0.000, -0.074, 0.099, -92.299, 19.800, 0.000, 1.000, 1.000, 1.000'),\
	(14, 9, 2, 358, 1, '0.000, -0.131, -0.146, 0.000, 4.899, 0.000, 1.000, 1.000, 1.000'),\
	(15, 9, 3, 355, 1, '0.219, -0.135, 0.149, 0.000, -179.400, 0.000, 1.000, 1.000, 1.000'),\
	(16, 9, 4, 19101, 2, '0.155, 0.000, 0.000, 0.000, 0.000, 0.000, 1.000, 1.000, 1.000')\
"

#define PREDIFINED_WEEKLY "INSERT IGNORE INTO weekly_cfg (id) VALUES (1)"