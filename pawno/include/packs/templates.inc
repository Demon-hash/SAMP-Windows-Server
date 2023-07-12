#if defined _templates_pack_included
	#endinput
#endif
#define _templates_pack_included

#define USERS_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS users (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`login` varchar(24) NOT NULL,\
	`password` varchar(32) NOT NULL,\
	`language` int(2) unsigned NOT NULL default '0',\
	`points` DECIMAL(9,2) unsigned NOT NULL default '0',\
	PRIMARY KEY (`id`)\
);"

#define SKILLS_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS skills (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`pistol` int(11) unsigned NOT NULL default '0',\
	`silinced` int(11) unsigned NOT NULL default '0',\
	`shotgun` int(11) unsigned NOT NULL default '0',\
	`spas` int(11) unsigned NOT NULL default '0',\
	`uzi` int(11) unsigned NOT NULL default '0',\
	`mp5` int(11) unsigned NOT NULL default '0',\
	`ak47` int(11) unsigned NOT NULL default '0',\
	`m4` int(11) unsigned NOT NULL default '0',\
	`rifle` int(11) unsigned NOT NULL default '0',\
	PRIMARY KEY (`id`)\
);"

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
	`killstreak` int(6) unsigned NOT NULL default '0',\
	`infection` int(6) unsigned NOT NULL default '0',\
	`cure` int(6) unsigned NOT NULL default '0',\
	`evacs` int(6) unsigned NOT NULL default '0',\
	`reported` int(6) unsigned NOT NULL default '0',\
	`purchase` int(6) unsigned NOT NULL default '0',\
	`jumps` int(6) unsigned NOT NULL default '0',\
	`total_points` DECIMAL(9,2) unsigned NOT NULL default '0',\
	`hours` int(6) unsigned NOT NULL default '0',\
	`minutes` int(2) unsigned NOT NULL default '0',\
	`seconds` int(2) unsigned NOT NULL default '0',\
	PRIMARY KEY (`id`)\
);"

#define ACHIEVEMENTS_CONFIG_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS achievements_config (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`name` varchar(255) NOT NULL default '',\
	`description` varchar(255) NOT NULL default '',\
	`reward` DECIMAL(9,2) unsigned NOT NULL default '0',\
	`type` int(3) unsigned NOT NULL default '0',\
	`required` int(6) unsigned NOT NULL default '1',\
	`disabled` int(1) unsigned NOT NULL default '1',\
	PRIMARY KEY (`id`)\
);"

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
	`issued_id` int(11) unsigned NOT NULL,\
	`date` int(11) unsigned NOT NULL,\
	`reason` varchar(128) NOT NULL,\
	`issued_ip` varchar(16) NOT NULL,\
	`target_ip` varchar(16) NOT NULL,\
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
	`target_id` int(11) unsigned NOT NULL,\
	`issued_id` int(11) unsigned NOT NULL,\
	`amount` DECIMAL(9,2) unsigned NOT NULL,\
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
	`amount` DECIMAL(9,2) unsigned NOT NULL,\
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
	`time` int(3) unsigned NOT NULL,\
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
	`amount` DECIMAL(9,2) unsigned NOT NULL,\
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
	`level` int(3) unsigned NOT NULL default '0',\
	`points` DECIMAL(9,2) unsigned NOT NULL default '0',\
	`house` int(1) unsigned NOT NULL default '0',\
	`disabled` int(1) unsigned NOT NULL default '0',\
	PRIMARY KEY (`id`)\
);"

#define GANGS_USERS_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS gangs_users (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`gang_id` int(3) unsigned NOT NULL default '0',\
	`rank` int(2) unsigned NOT NULL default '0',\
	`warns` int(2) unsigned NOT NULL default '0',\
	`joined_at` int(11) unsigned NOT NULL default '0',\
	`accepted_by` int(11) unsigned NOT NULL default '0',\
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
	`id` int(11) unsigned NOT NULL,\
	`capacity` int(3) unsigned NOT NULL default '10',\
	`required` DECIMAL(9,2) unsigned NOT NULL default '25000.0',\
	`default` DECIMAL(9,2) unsigned NOT NULL default '5000.0',\
	`multiply` DECIMAL(9,2) unsigned NOT NULL default '2.0',\
	`armour_per_level` DECIMAL(9,2) unsigned NOT NULL default '10.0',\
	`crystal_health` DECIMAL(9,2) unsigned NOT NULL default '50000.0',\
	`flag_distance` DECIMAL(9,2) unsigned NOT NULL default '100.0',\
	`per_cure` DECIMAL(9,2) unsigned NOT NULL default '1.0',\
	`per_kill` DECIMAL(9,2) unsigned NOT NULL default '1.0',\
	`per_evac` DECIMAL(9,2) unsigned NOT NULL default '1.0',\
	`per_ability` DECIMAL(9,2) unsigned NOT NULL default '1.0',\
	`per_assist` DECIMAL(9,2) unsigned NOT NULL default '0.25',\
	`flag_id` int(11) unsigned NOT NULL default '11245',\
	PRIMARY KEY (`id`)\
);"

#define MAPS_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS maps (\
	`id` int(11) unsigned NOT NULL,\
	`filename` varchar(64) NOT NULL,\
	`author` int(11) unsigned NOT NULL default '0',\
	`interior` int(3) unsigned NOT NULL default '0',\
	`weather` int(3) unsigned NOT NULL default '0',\
	`checkpoint_size` DECIMAL(9,2) NOT NULL default '1.0',\
	`gates_ids` varchar(24) NOT NULL default '',\
	`gates_speed` DECIMAL(9,2) NOT NULL default '1.0',\
	`time` int(2) unsigned NOT NULL default '12',\
	`gang` int(3) unsigned NOT NULL default '0',\
	`water` int(1) unsigned NOT NULL default '1',\
	`humans_coords` TEXT NOT NULL default '',\
	`zombies_coords` TEXT NOT NULL default '',\
	`camera_coords` TEXT NOT NULL default '',\
	`checkpoint_coords` TEXT NOT NULL default '',\
	`gates_coords` TEXT NOT NULL default '',\
	`gates_move_coords` TEXT NOT NULL default '',\
	`crystal_coords` TEXT NOT NULL default '',\
	`near_crystal_coords` TEXT NOT NULL default '',\
	`crystal_id` int(6) unsigned NOT NULL default '18876',\
	`flag_coords` TEXT NOT NULL default '',\
	`flag_coords_text` TEXT NOT NULL default '',\
	`flag_date` int(11) unsigned NOT NULL default '0',\
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
	`high_jump_xyz` varchar(24) NOT NULL default '10.0,10.0,8.0',\
	`long_jump_xyz` varchar(24) NOT NULL default '10.0,10.0,8.0',\
	`radioactive` DECIMAL(9,2) unsigned NOT NULL default '5.0',\
	`regeneration` DECIMAL(9,2) unsigned NOT NULL default '5.0',\
	`support` DECIMAL(9,2) unsigned NOT NULL default '2.5',\
	`stomper_effect` varchar(64) NOT NULL default '18675,0.0,0.0,0.0,-1.2,1000',\
	`flasher_effect` varchar(64) NOT NULL default '18693,10,2,15.0',\
   	PRIMARY KEY (`id`)\
);"

#define CLASSES_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS classes (\
	`id` int(11) unsigned NOT NULL,\
	`team` int(3) unsigned NOT NULL default '0',\
	`health` DECIMAL(9,2) unsigned NOT NULL default '100.0',\
	`armour` DECIMAL(9,2) unsigned NOT NULL default '0.0',\
    	`points` DECIMAL(9,2) unsigned NOT NULL default '0',\
	`cooldown` int(3) unsigned NOT NULL default '15',\
	`ability_time` int(3) unsigned NOT NULL default '15',\
	`ability_count` int(3) unsigned NOT NULL default '6',\
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

#define CONFIG_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS config (\
	`id` int(11) unsigned NOT NULL,\
	`pickup_protection` int(4) unsigned NOT NULL default '30',\
	`kills` DECIMAL(9,2) unsigned NOT NULL default '1.0',\
	`evacuation` DECIMAL(9,2) unsigned NOT NULL default '15.0',\
	`cure` DECIMAL(9,2) unsigned NOT NULL default '1.0',\
	`ability` DECIMAL(9,2) unsigned NOT NULL default '1.0',\
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
	`curing_weapon` int(2) unsigned NOT NULL default '33',\
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
	`points` DECIMAL(9,2) unsigned NOT NULL,\
	`date` int(11) unsigned NOT NULL,\
   	PRIMARY KEY (`id`)\
);"

#define AUCTION_CASHBACK_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS auction_cashback (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`account_id` int(11) unsigned NOT NULL,\
	`points` DECIMAL(9,2) unsigned NOT NULL,\
   	PRIMARY KEY (`id`)\
);"

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
	`zombie_armour` DECIMAL(9,2) unsigned NOT NULL default '200.0',\
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

#define PREDIFINED_GANGS_CONFIG "INSERT IGNORE INTO gangs_config (id) VALUES (1);"
#define PREDIFINED_CONFIG "INSERT IGNORE INTO config (id) VALUES (1);"
#define PREDIFINED_ANTICHEAT "INSERT IGNORE INTO anticheat (id) VALUES (1);"
#define PREDIFINED_ROUND_CONFIG "INSERT IGNORE INTO round_config (id) VALUES (1);"
#define PREDIFINED_EVAC_CONFIG "INSERT IGNORE INTO evac_config (id) VALUES (1);"
#define PREDIFINED_MAP_CONFIG "INSERT IGNORE INTO map_config (id) VALUES (1);"
#define PREDIFINED_BALANCE_CONFIG "INSERT IGNORE INTO balance_config (id) VALUES (1);"
#define PREDIFINED_CLASSES_CONFIG "INSERT IGNORE INTO classes_config (id) VALUES (1);"

#define PREDIFINED_MAPS "INSERT IGNORE INTO \
	`maps` (`id`, `filename`, `author`, `interior`, `weather`, `checkpoint_size`, `gates_ids`, `gates_speed`, `time`, `gang`, `water`, `humans_coords`, `zombies_coords`, `camera_coords`, `checkpoint_coords`, `gates_coords`, `gates_move_coords`, `crystal_coords`, `flag_coords`, `flag_coords_text`, `near_crystal_coords`, `disabled`) \
	VALUES \
	(1, 'village', 0, 0, 6, '15.000', '', '1.000', 23, 0, 1, '744.0316,-550.7260,17.1647,358.7975,681.8290,-554.5507,16.1875,357.8575,641.3369,-557.3655,16.1875,359.1342', '741.9293,-549.5023,17.0694,354.7242,623.4771,-506.2735,16.3525,88.4586,611.7243,-601.8662,17.2266,272.0502', '676.6566,-460.0044,27.1080,676.7922,-460.9932,26.9030', '681.8102,-508.0689,16.1875', '', '', '681.7691,-603.2256,15.0,1.0143', '672.4241,-540.2498,17.5474,0.0000,290.0000,347.5840', '673.0986,-540.4794,18.4757', '681.2228,-590.5868,16.1946,183.2756', 0);\
"

#define PREDIFINED_LOCAL_MAPS "INSERT IGNORE INTO maps_localization (id, english, russian) VALUES \
	(1, 'The Village', 'Деревня');\
"

#define PREDIFINED_LOCALE_CLASSES_10 "INSERT IGNORE INTO classes_localization (id, english_title, russian_title, english_desc, russian_desc) VALUES \
	(1, 'Civillian', 'Гражданский', 'Silinced Pistol, Shotgun', 'Тихий пистолет, Дробовик'),\
	(2, 'Policeman', 'Полицейский', 'Deagle, Shotgun', 'Дигл, Дробовик'),\
	(3, 'Farmer', 'Фермер', 'Rifle', 'Винтовка'),\
	(4, 'Medic', 'Медик', 'Shooting From Rifle Cure Humans', 'Выстрел Из Винтовки Лечит Людей'),\
	(5, 'Scout', 'Скаут', 'Sniper', 'Снайперская винтовка'),\
	(6, 'Warm Person', 'Человек в шубе', 'Can not be freezed', 'Не может замерзнуть'),\
	(7, 'Mi7', 'Mi7', 'M4, Deagle', 'M4, Дигл'),\
	(8, 'Toughie', 'Крепкий орешек', 'Anti-Stomper', 'Анти-Топтун'),\
	(9, 'Pyromaniac', 'Пироманьяк', 'Anti-Radioactive Field', 'Анти-Радиоактивное Поле'),\
	(10, 'Engineer', 'Инжинер', 'Can build 6 boxes', 'Может создать 6 коробок'),\
	(11, 'Sharpshooter', 'Меткий стрелок', 'Sniper, Immunity', 'Снайперская винтовка, Иммунитет');\
"

#define PREDIFINED_LOCALE_CLASSES_20 "INSERT IGNORE INTO classes_localization (id, english_title, russian_title, english_desc, russian_desc) VALUES \	
	(12, 'Terrorist', 'Террорист', 'C4', 'C4'),\	
	(13, 'Runner', 'Бегун', 'Fast run', 'Быстрый бег'),\
	(14, 'S.W.A.T', 'Спецназовец', 'M4, Deagle, Immunity', 'M4, Дигл, Иммунитет'),\
	(15, 'Rocketman', 'Техник', 'Rocketboots', 'Реактивные ботинки'),\
	(16, 'Mimic', 'Мимик', 'Mimicry, Immunity', 'Мимикрия, Иммунитет'),\
	(17, 'Sheriff', 'Шериф', 'Taser', 'Электрошокер'),\
	(18, 'Priest', 'Священник', 'Anti-Curse Field', 'Защитное Поле От Проклятья'),\
	(19, 'Athlete', 'Атлет', 'Long Jumps', 'Длинные прыжки'),\
	(20, 'Nurse', 'Медсестра', 'Cure Field, Anti-Radioactive Field', 'Лечащее Поле, Анти-Радиационное поле'),\
	(21, 'Iron Man', 'Железный Человек', 'Fast Run, High Jumps', 'Быстрый бег, Высокие прыжки'),\
	(22, 'Architect', 'Архитектор', 'Can build 9 boxes, Immunity', 'Может создать 9 коробок, Иммунитет'),\
	(23, 'Imaginary Doctor', 'Мнимый доктор', 'Space Traveling', 'Путишествие в пространстве'),\
	(24, 'Human Queen', 'Королева', 'Long Jumps, Immunity', 'Длиные прыжки, Иммунитет');\
"

#define PREDIFINED_LOCALE_CLASSES_30 "INSERT IGNORE INTO classes_localization (id, english_title, russian_title, english_desc, russian_desc) VALUES \
	(25, 'Standard Zombie', 'Обычный Зомби', 'Can Infect', 'Может Заразить'),\
	(26, 'Flesher Zombie', 'Гнилой Зомби', 'Infected Meat', 'Зараженное Мясо'),\
	(27, 'Regenerator Zombie', 'Регенератор Зомби', 'Can Regenerate HP', 'Может Восстанавливать ХП'),\
	(28, 'Support Zombie', 'Зомби Поддержка', 'Heals In A Range', 'Восстанавливает ХП В Радиусе'),\
	(29, 'Stealer Zombie', 'Вор Зомби', 'Can Steal Armour', 'Может Украсть Броню'),\
	(30, 'Boomer Zombie', 'Взрывающийся Зомби', 'Explodes And Infects On Death', 'Взрывается И Заражает При Смерти'),\
	(31, 'Jumper Zombie', 'Зомби Прыгун', 'High Jump', 'Высокий Прыжок'),\
	(32, 'Jumper Boomer Zombie', 'Взрывающийся Зомби Прыгун', 'High Jump, Explodes On Death', 'Высокий Прыжок, Взрывается при смерти'),\
	(33, 'Mega Jumper Zombie', 'Мега Зомби Прыгун', 'High Jumps', 'Высокие Прыжки'),\
	(34, 'Stomper Zombie', 'Топтун Зомби', 'Can Stomp Humans', 'Может Отбрасывать Людей'),\
	(35, 'Kamikaze Zombie', 'Камикадзе Зомби', 'Explodes On Request', 'Взрывается по желанию'),\
	(36, 'Spacebreaker Zombie', 'Зомби Крушащий Пространство', 'Space Traveling', 'Путишествие в пространстве'),\
	(37, 'Mimic Zombie', 'Мимик Зомби', 'Mimicry', 'Мимикрия');\
"

#define PREDIFINED_LOCALE_CLASSES_40 "INSERT IGNORE INTO classes_localization (id, english_title, russian_title, english_desc, russian_desc) VALUES \
	(38, 'Freezer Zombie', 'Холодный Зомби', 'Freezes On Death', 'Может Заморозить При Смерти'),\
	(39, 'Radioactive Zombie', 'Радиоактивный Зомби', 'Radioactive Field', 'Радиоактивное Поле'),\
	(40, 'Flash Zombie', 'Невероятно Быстрый Зомби', 'Lighting Attack', 'Мгновенная атака'),\
	(41, 'Spitter Zombie', 'Плюющийся Зомби', 'Can Infect In A Range', 'Может Заразить С Расстояния'),\
	(42, 'Mutated Zombie', 'Мутированный Зомби', 'Airborne Infection', 'Воздушно-капельная Инфекция'),\
	(43, 'Spore Zombie', 'Споровой Зомби', 'Can Infect By Spores', 'Заражает спорами'),\
	(44, 'Fast Zombie', 'Быстрый Зомби', 'Fast Run', 'Быстрый бег'),\
	(45, 'Enforcer Zombie', 'Пуленепробеваемый Зомби', 'Armour', 'Броня'),\
	(46, 'Witch Zombie', 'Зомби Ведьма', 'Can curse', 'Может проклясть'),\
	(47, 'Mirror Zombie', 'Отражающий Зомби', 'Reflect Damage', 'Отражает урон'),\
	(48, 'S.W.A.T Zombie', 'Зомби Спецназовец', 'Armour, Remove Weapons', 'Броня, Убирает оружие');\
"

#define PREDIFINED_HUMANS "INSERT IGNORE INTO classes (id, team, points, ability, immunity, weapons, cooldown, skin, disabled) VALUES \
	(1, 2, 0, '', '', '23, 25', 0, 121, 0),\
	(2, 2, 500, '', '', '24, 25', 0, 280, 0),\
	(3, 2, 1500, '', '', '33, 25', 0, 158, 0),\
	(4, 2, 3000, 'MEDIC', '', '24, 25, 33', 0, 275, 0),\
	(5, 2, 5000, '', '', '23, 34', 0, 294, 0),\
	(6, 2, 10000, 'WARM PERSON', '', '24, 25', 0, 249, 0),\
	(7, 2, 15000, '', '', '24, 31', 0, 164, 0),\
	(8, 2, 15000, 'TOUGHIE', '', '31, 25', 0, 109, 0),\
	(9, 2, 20000, 'PYRIMANIAC', '', '37, 25', 0, 277, 0),\
	(10, 2, 35000, 'ENGINEER', '', '24, 30, 33', 0, 27, 0),\
	(11, 2, 50000, 'SHARPSHOOTER', '', '34', 0, 286, 0),\
	(12, 2, 70000, '', '', '39, 41', 0, 228, 0),\
	(13, 2, 90000, '', '', '24, 31', 0, 0, 0),\
	(14, 2, 125000, 'SWAT', '', '24, 31', 0, 285, 0),\
	(15, 2, 180000, 'Rocketman', '', '24, 31, 33', 0, 50, 0),\
	(16, 2, 225000, 'Mimic', '', '24, 31', 0, 181, 0),\
	(17, 2, 250000, 'Sheriff', '', '24, 25', 0, 281, 0),\
	(18, 2, 300000, 'Priest', '', '24, 31', 0, 68, 0),\
	(19, 2, 300000, 'Athlete', '', '24, 32', 0, 170, 0),\
	(20, 2, 400000, 'Nurse', '', '24, 25, 31, 33', 0, 308, 0),\
	(21, 2, 600000, 'Iron Man', '', '24, 25, 33', 0, 0, 0),\
	(22, 2, 850000, 'Architect', '', '24, 25, 34', 0, 153, 0),\
	(23, 2, 1000000, 'Doctor', '', '24, 25, 31', 0, 70, 0),\
	(24, 2, 1500000, 'Queen', '', '24, 25, 31, 34', 0, 92, 0);\
"

#define PREDIFINED_ZOMBIES "INSERT IGNORE INTO classes (id, team, points, ability, immunity, weapons, cooldown, skin, disabled) VALUES \
	(25, 1, 0, 'Standard', '', '', 0, 181, 0),\
	(26, 1, 2500, 'Flesher', '', '', 0, 181, 0),\
	(27, 1, 5000, 'Regenerator', '', '', 0, 70, 0),\
	(28, 1, 7500, 'Support', '', '', 0, 75, 0),\
	(29, 1, 500000, 'Stealer', '', '', 0, 209, 0),\
	(30, 1, 5000, 'Boomer', '', '', 0, 264, 0),\
	(31, 1, 15000, 'Jumper', '', '', 0, 162, 0),\
	(32, 1, 25000, 'Jumper Boomer', '', '', 0, 162, 0),\
	(33, 1, 30000, 'Mega Jumper', '', '', 0, 162, 0),\
	(34, 1, 35000, 'Stomper', '', '', 0, 78, 0),\
	(35, 1, 10000, 'Kamikaze', '', '', 0, 241, 0),\
	(36, 1, 250000, 'Space Breaker', '', '', 0, 79, 0),\
	(37, 1, 75000, 'Mimic', '', '', 0, 121, 0),\
	(38, 1, 45000, 'Freezer', '', '', 0, 137, 0),\
	(39, 1, 50000, 'Radioactive', '', '', 0, 146, 0),\
	(40, 1, 35000, 'Flash', '', '', 0, 230, 0),\
	(41, 1, 125000, 'Spitter', '', '', 0, 212, 0),\
	(42, 1, 150000, 'Mutated', '', '', 0, 200, 0),\
	(43, 1, 250000, 'Spore', '', '', 0, 136, 0),\
	(44, 1, 400000, 'Fast', '', '', 0, 0, 0),\
	(45, 1, 850000, 'Enforcer', '', '', 0, 285, 0),\
	(46, 1, 600000, 'Witch', '', '', 0, 129, 0),\
	(47, 1, 700000, 'Mirror', '', '', 0, 135, 0),\
	(48, 1, 1000000, 'Juggernaut', '', '', 0, 285, 0);\
"

#define PREDIFINED_TEXTURES "INSERT IGNORE INTO `textures_config` (`id`, `position`, `letter_size`, `text_size`, `default_value`, `background_color`, `texture_font`, `texture_draw_color`, `texture_outline`, `texture_proportional`, `texture_shadow`, `texture_use_box`, `texture_box_color`, `texture_alignment`) VALUES \
	(1, '22.000000, 251.000000', '1.770000, 3.499999', '0.0,0.0', '300', '255', 3, 'FFFFFF', 1, 1, 1, 0, '0', 0),\
	(2, '655.500000, 1.500000', '0.000000, 50.262496', '-2.000000, 0.000000', 'usebox', '255', 0, '0', 0, 1, 1, 1, '0xFF0000BB', 0),\
	(3, '14.000000, 283.937500', '0.000000, 0.000000', '119.500000, 21.437500', 'LD_SPAC:white', '0x000000FF', 4, '0x000000FF', 0, 0, 0, 0, '0', 1),\
	(4, '18.500000, 285.250000', '0.562500, 1.984999', '0.0,0.0', 'UNTIL EVAC', '0x000000FF', 1, '0xFF0000FF', 1, 1, 0, 0, '0', 1),\
	(5, '21.500000, 220.000000', '0.511498, 1.477498', '0.0,0.0', '~w~humans: 0~n~~r~zombies: 0', '0x000000FF', 2, '0xFFFFFFFF', 0, 1, 1, 0, '0', 1),\
	(6, '546.000000, 35.000000', '0.270000, 1.000000', '0.0,0.0', '0', '0x000000FF', 2, '0x0d8adeFF', 0, 1, 1, 0, '0', 0);\
"

#define PREDIFINED_WEAPONS "INSERT IGNORE INTO weapons_config (id, type, chance, `default`, pick) VALUES \
	(1, 22, 100, 50, 10),\
	(2, 23, 100, 50, 10),\
	(3, 24, 75, 50, 10),\
	(4, 25, 75, 50, 10),\
	(5, 27, 5, 50, 3),\
	(6, 28, 12, 150, 50),\
	(7, 29, 5, 300, 35),\
	(8, 30, 9, 300, 30),\
	(9, 31, 5, 300, 30),\
	(10, 32, 9, 150, 50),\
	(11, 33, 20, 15, 3),\
	(12, 34, 20, 50, 3),\
	(13, 35, 1, 5, 1),\
	(14, 36, 1, 5, 1),\
	(15, 37, 1, 500, 150),\
	(16, 39, 10, 20, 2);\
"

#define PREDIFINED_LOCALIZATION_1 "INSERT IGNORE INTO localization (id, english, russian) VALUES \
	(1, 'Login', 'Логин'),\
	(2, 'Welcome back, your account is already registered\nEnter your password below to login', 'Добро пожаловать, ваш аккаунт уже зарегистрирован\nВведите пароль'),\
	(3, 'Wrong password, %d / 3 tries left\n\nWelcome back, your account is already registered\nEnter your password below to login', 'Неверный пароль, осталось %d / 3 попыток\nДобро пожаловать, ваш аккаунт уже зарегистрирован\nВведите пароль'),\
	(4, 'You have to type at least something!\n\nWelcome back, your account is already registered\nEnter your password below to login', 'Поле пароля не может быть пустым!\nДобро пожаловать, ваш аккаунт уже зарегистрирован\nВведите пароль'),\				
	(5, 'Register', 'Регистрация'),\
	(6, 'Welcome to the server, your account was not found\nEnter your password below to complete registration', 'Добро пожаловать, ваш аккаунт не найден\nПридумайте пароль'),\
	(7, 'You have to type at least something!\n\nWelcome to the server, your account was not found\nEnter your password below to complete registration', 'Поле пароля не может быть пустым!\nДобро пожаловать, ваш аккаунт не найден\nПридумайте пароль'),\
	(8, 'Register', 'Регистрация'),\
	(9, 'Login', 'Логин'),\
	(10, 'Quit', 'Выйти'),\
	(11, '*** %s (ID: %d) has joined the server', '*** Игрок %s (ИД: %d) подключился к серверу'),\
	(12, '*** %s has left the server [%s]', '*** Игрок %s вышел с сервера [%s]'),\
	(13, 'Timeout', 'Разрыв соединения'),\
	(14, 'Leave', 'Выход'),\
	(15, 'Kick', 'Кикнут'),\
	(16, 'Unknown', 'Неизвестно');\
"

#define PREDIFINED_LOCALIZATION_2 "INSERT IGNORE INTO localization (id, english, russian) VALUES \
	(17, 'Restarting', 'Перезагрузка'),\
	(18, '>> %s has made it to the evacuation point!', '>> Игрок %s эвакуировался!'),\
	(19, '>> ALL SURVIVORS EVACUATED!', '>> Все выжившие добрались до пункта эвакуации!'),\
	(20, '>> Under protection {FFFFFF}%d{FF0000} seconds left!', '>> Под защитой, до снятия {FFFFFF}%d{FF0000} секунд'),\
	(21, '(by %s)', '(автор %s)'),\
	(22, '(captured by %s)', '(под контролем у %s)'),\
	(23, '>> Entering The Map #%d (%s) %s %s', '>> Запускаем карту #%d (%s) %s %s'),\
	(24, '>> Creating objects...', '>> Создание объектов...'),\
	(25, '>> ZOMBIES WIN!', '>> ЗОМБИ ПОБЕДИЛИ!'),\
	(26, '>> An evacuation has arrived for humans!', '>> Эвакуация прибыла для людей!'),\
	(27, '>> Humans get to the checkpoint within a minute!', '>> Выжившие, доберитесь до чекпоинта за минуту!'),\
	(28, '>> Beginning new a round...', '>> Начинается новый раунд!'),\
	(29, '~r~ROUND OVER~n~~w~STARTING NEW ROUND...', '~r~КОНЕЦ РАУНДА~n~~w~НАЧИНАЕМ НОВЫЙ...'),\
	(30, '>> Gang members, a crystal stone has appeared, deal as much damage as possible!', 'Участники банд, появился защитный кристал, нанесите как можно больше урона!'),\
	(31, '~w~humans: %d~n~~r~zombies: %d', '~w~ЛЮДИ: %d~n~~r~ЗОМБИ: %d');\
"

#define PREDIFINED_LOCALIZATION_3 "INSERT IGNORE INTO localization (id, english, russian) VALUES \
	(32, '{FFFFFF}%s\n{FFF000}Controlled by {FFFFFF}%s\n{FFF000}Captured at {FFFFFF}%02d:%02d {FFF000}on {FFFFFF}%02d/%02d/%d\n', '{FFFFFF}%s\n{FFF000}Под контролем у {FFFFFF}%s\n{FFF000}Захвачено в {FFFFFF}%02d:%02d {FFF000}, дата {FFFFFF}%02d/%02d/%d\n'),\ 
	(33, '{FFF000}This gang dealt the most damage to crystal to capture the map\n', '{FFF000}Эта банда внесла наибольшее количество урона по кристаллу, чтобы захватить карту\n'),\
	(34, '{FFF000}The gang members get extra points for the following actions:\n\n{FFFFFF}+%.0f{FFF000} point(s) in gang pot for evacuating\n', '{FFF000}Участники банды получают дополнительные очки за следующие действия:\n\n{FFFFFF}+%.0f{FFF000} очков в казну клана за эвакуацию\n'),\ 
	(35, '{FFFFFF}+%.0f{FFF000} point(s) in gang pot for curing humans\n{FFFFFF}+%.0f{FFF000} point(s) in gang pot for active ability using\n', '{FFFFFF}+%.0f{FFF000} очков в казну клана за лечение людей\n{FFFFFF}+%.0f{FFF000} очков в казну клана за использование активных способностей\n'),\
	(36, '{FFFFFF}+%.0f{FFF000} point(s) in gang pot for killing players\n{FFFFFF}+%.2f{FFF000} point(s) in gang pot for assist', '{FFFFFF}+%.0f{FFF000} очков в казну клана за убийство игроков\n{FFFFFF}+%.2f{FFF000} очков в казну клана за помощь в убийстве зомби'),\
	(37, '{FFFFFF}Zombie Spawn\ndo{FF0000} not{FFFFFF} shoot zombies here', '{FFFFFF}Точка появления зомби\n{FF0000}не убивайте / стреляйте{FFFFFF} здесь'),\
	(38, 'UNUSED', 'UNUSED'),\
	(39, 'Classes', 'Классы'),\
	(40, 'Human Classes\nZombie Classes', 'Классы Людей\nКлассы Зомби'),\
	(41, 'Select', 'Выбрать'),\
	(42, 'Close', 'Закрыть'),\
	(43, 'POINTS', 'ОЧКОВ'),\
	(44, '>> You have been spawned as a(n) %s', '>> Ваш текущий класс %s'),\
	(45, '>> You have changed your class within the grace period and have been respawned instanlty!', '>> Вы успели сменить свой класс в подходящее время!'),\
	(46, '>> Class set, will change next respawn!', '>> Класс установлен, будет изменен после перерождения!'),\
	(47, 'points', 'очков'),\
	(48, '>> You need %.0f %s to use this class!', '>> Вам нужно %.0f %s чтобы использовать этот класс!'),\
	(49, 'MISS', 'ПРОМАХ'),\
	(50, '~g~Found:~w~ %d ammo', '~g~Поднято:~w~ %d патрон(ов)');\
"

#define PREDIFINED_LOCALIZATION_4 "INSERT IGNORE INTO localization (id, english, russian) VALUES \
	(51, '>> You were chosen as a zombie go and kill all the humans!', '>> Вы были выбраны как зомби, убейте всех людей!'),\	
	(52, '>> Use your abilities to make it faster (LEFT ALT)', '>> Используйте свои способности, чтобы ускорить это (Левый Альт)'),\
	(53, '~r~TRY TO STAY~n~~w~ALIVE', '~r~ПОПЫТАЙТЕСЬ ~w~ВЫЖИТЬ'),\
	(54, 'points', 'очки'),\
	(55, '>> Player %s was chosen to be the Human Hero / Queen. Kill him(er) and get additional %s!', '>> Игрок %s был выбран как Герой(иня). Убейте его(ее) и получите дополнительные %s!'),\
	(56, '>> Player %s has killed the Human Hero / Queen!', '>> Игрок %s убил Героя(иню)!'),\
	(57, '>> Player %s was chosen to be the Zombie Boss / Queen. Kill him(er) and get additional %s!', '>> Игрок %s был выбран как Зомби Босс / Королева. Убейте его(ее) и получите дополнительные %s!'),\
	(58, '>> Player %s has killed the Zombie Boss / Queen!', '>> Игрок %s убил Зомби Босса / Королеву!'),\
	(59, '>> [First Blood] Player %s has drawn {FF0000}first blood{FFFFFF} and gains additional %s!', '>> [Первая Кровь] Игрок %s {FF0000}пустил первую кровь{FFFFFF} и получил дополниельные %s!'),\
	(60, '>> Kill the last human and receive extra %s!', '>> Убейте последнего выжевшего и получите дополнительные %s!'),\
	(61, '>> Player %s killed the last survivor and got an additional %s!', '>> Игрок %s убил последнего выжившего и получил дополнительные %s!'),\
	(62, '>> Player %s has been infected by standard zombie %s!', '>> Игрок %s был заражен обычным зомби %s!'),\
	(63, '>> Player %s has been infected by %s! (by air)', '>> Игрок %s был заражен от %s! (по воздуху)'),\
	(64, '>> Player %s has been infected by flesher zombie %s! (by meat)', '>> Игрок %s был заражен гнилым зомби %s! (через мясо)'),\
	(65, '>> Player %s has been infected by spore zombie %s!', '>> Игрок %s был заражен через споры от зомби %s!'),\
	(66, '>> Player %s has been infected by spitter zombie %s!', '>> Игрок %s был заражен плевком от зомби %s!'),\
	(67, '>> Player %s has been infected by explosion from %s!', '>> Игрок %s был заражен взрывом от зомби %s!'),\
	(68, '>> Player %s has blown up and infected{FFFFFF} %d human(s)!', '>> Игрок %s взорвался и заразил {FFFFFF} %d человек(а)!'),\
	(69, '>> Player %s has blown up and infected{FFFFFF} WHOPPING{FF0000} %d human(s)!', '>> Игрок %s взорвался и заразил {FFFFFF} НЕВЕРОЯТНО{FF0000} %d человек(а)!'),\
	(70, '>> Player %s has been cured by cure field!', '>> Игрок %s был выличен лечящем полем!'),\
	(71, '>> Player %s has been cured by %s! (shot)', '>> Игрок %s был выличен игроком %s! (выстрел)'),\
	(72, '~r~~h~Regeneration', '~r~~h~Восстановление'),\
	(73, '~g~~h~Radioactive Field', '~g~~h~Радиоактивное Поле'),\
	(74, '~g~Antidote', '~g~Антидот'),\
	(75, '>> Player %s has stole an armour from player %s!', '>> Игрок %s украл броню игрока %s!'),\
	(76, '>> Player %s has been cursed by witch %s!', '>> Игрок %s был проклят ведьмой %s!'),\
	(77, '>> Priest %s absolved all sins of the player %s!', '>> Священик %s отпустил все грехи игрока %s!'),\
	(78, '~w~You_are_~g~Cursed~n~~r~Kill~w~_humans_to_survive', '~w~Вы_~g~прокляты~n~~r~Убивайте~w~_людей_чтобы_жить');\
"