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

#define ACHIEVEMENTS_CONFIG_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS achievements_config (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`name` varchar(255) NOT NULL default '',\
	`description` varchar(255) NOT NULL default '',\
	`reward` int(6) unsigned NOT NULL default '0',\
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
	`amount` int(11) unsigned NOT NULL,\
	`date` int(11) unsigned NOT NULL,\
	`ip` varchar(16) NOT NULL,\
	PRIMARY KEY (`id`)\
);"

#define GANGDEPOSITLOG_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS gang_deposit_log (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`account_id` int(11) unsigned NOT NULL,\
	`gang_id` int(11) unsigned NOT NULL,\
	`amount` int(11) unsigned NOT NULL,\
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
	`points` int(6) unsigned NOT NULL default '0',\
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
	`required` int(6) unsigned NOT NULL default '25000',\
	`default` int(6) unsigned NOT NULL default '100000',\
	`multiply` DECIMAL(6,3) unsigned NOT NULL default '2',\
	`armour_per_level` DECIMAL(6,3) unsigned NOT NULL default '10',\
	`bot_health` DECIMAL(6,3) unsigned NOT NULL default '50000',\
	`flag_distance` DECIMAL(6,3) unsigned NOT NULL default '100',\
	PRIMARY KEY (`id`)\
);"

#define MAPS_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS maps (\
	`id` int(11) unsigned NOT NULL,\
	`name` varchar(64) NOT NULL,\
	`filename` varchar(64) NOT NULL,\
	`author` int(11) unsigned NOT NULL default '0',\
	`interior` int(3) unsigned NOT NULL default '0',\
	`weather` int(3) unsigned NOT NULL default '0',\
	`checkpoint_size` DECIMAL(6,3) NOT NULL default '1.0',\
	`gates_ids` varchar(24) NOT NULL default '',\
	`gates_speed` DECIMAL(6,3) NOT NULL default '1.0',\
	`time` int(2) unsigned NOT NULL default '12',\
	`gang` int(3) unsigned NOT NULL default '0',\
	`water` int(11) unsigned NOT NULL default '1',\
	`humans_coords` TEXT NOT NULL default '',\
	`zombies_coords` TEXT NOT NULL default '',\
	`camera_coords` TEXT NOT NULL default '',\
	`checkpoint_coords` TEXT NOT NULL default '',\
	`gates_coords` TEXT NOT NULL default '',\
	`gates_move_coords` TEXT NOT NULL default '',\
	`npc_coords` TEXT NOT NULL default '',\
	`npc_skin` int(3) unsigned NOT NULL default '1',\
	`flag_coords` TEXT NOT NULL default '',\
	`flag_coords_text` TEXT NOT NULL default '',\
	`flag_date` int(11) unsigned NOT NULL default '0',\
	`disabled` int(1) unsigned NOT NULL default '1',\
	PRIMARY KEY (`id`)\
);"

#define WEAPONS_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS weapons (\
	`id` int(11) unsigned NOT NULL,\
	`type` int(3) unsigned NOT NULL default '0',\
	`min` int(4) unsigned NOT NULL default '0',\
	`max` int(4) unsigned NOT NULL default '1',\
	`pick` int(4) unsigned NOT NULL default '0',\
	PRIMARY KEY (`id`)\
);"

#define LANGUAGES_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS english (\
	`id` int(11) unsigned NOT NULL,\
	`text` TEXT NOT NULL default '',\
   	PRIMARY KEY (`id`)\
);"

#define CLASSES_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS classes (\
	`id` int(11) unsigned NOT NULL,\
	`name` varchar(255) NOT NULL default '',\
	`description` varchar(255) NOT NULL default '',\
	`team` int(3) unsigned NOT NULL default '0',\
	`health` int(3) unsigned NOT NULL default '100',\
	`armour` int(3) unsigned NOT NULL default '0',\
    	`level` int(3) unsigned NOT NULL default '0',\
    	`ability` int(3) unsigned NOT NULL default '0',\
	`cooldown` int(3) unsigned NOT NULL default '15',\
    	`skin` int(3) unsigned NOT NULL default '181',\
	`immunity` int(1) unsigned NOT NULL default '0',\
	`distance` DECIMAL(6,3) unsigned NOT NULL default '1.0',\
	`animation` int(5) unsigned NOT NULL default '0',\
	`animation_time` int(4) unsigned NOT NULL default '0',\
    	`disabled` int(1) unsigned NOT NULL default '1',\
   	PRIMARY KEY (`id`)\
);"

#define CONFIG_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS config (\
	`id` int(11) unsigned NOT NULL,\
	`kills` int(3) unsigned NOT NULL default '1',\
	`evacuation` int(3) unsigned NOT NULL default '15',\
	`cure` int(3) unsigned NOT NULL default '1',\
	`infect` int(3) unsigned NOT NULL default '1',\
	`ability` int(3) unsigned NOT NULL default '1',\
	`infection_damage` DECIMAL(6,3) unsigned NOT NULL default '1.0',\
	`fists_damage` DECIMAL(6,3) unsigned NOT NULL default '5.0',\
	`max_auth_timeout` int(3) unsigned NOT NULL default '2',\
	`max_auth_tries` int(3) unsigned NOT NULL default '3',\
	`preview_bot` int(3) unsigned NOT NULL default '181',\
	`preview_bot_coords` varchar(255) NOT NULL default '2415.5414,-50.4586,28.1535, 1.4218',\
	`preview_camera_coords` varchar(255) NOT NULL default '2415.7615, -45.1561, 28.8247, 2415.7559, -46.1539, 28.6447',\
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

#define ROUND_SESSION_TEMPLATE "\
	CREATE TABLE IF NOT EXISTS round_session (\
	`id` int(11) unsigned NOT NULL auto_increment,\
	`account_id` int(11) unsigned NOT NULL,\
	`map_id` int(11) unsigned NOT NULL,\
	`team` int(3) unsigned NOT NULL,\
	`survival` int(2) unsigned NOT NULL default '0',\
	`killing` DECIMAL(6,3) unsigned NOT NULL default '0',\
	`care` DECIMAL(6,3) unsigned NOT NULL default '0',\
	`mobility_as_human` DECIMAL(6,3) unsigned NOT NULL default '0',\
	`mobility_as_zombie` DECIMAL(6,3) unsigned NOT NULL default '0',\
	`skillfulness` DECIMAL(6,3) unsigned NOT NULL default '0',\
	`brutality` DECIMAL(6,3) unsigned NOT NULL default '0',\
   	PRIMARY KEY (`id`)\
);"

#define PREDIFINED_MAP_VILLAGE "INSERT IGNORE INTO \
	`maps` (`id`, `name`, `filename`, `author`, `interior`, `weather`, `checkpoint_size`, `gates_ids`, `gates_speed`, `time`, `gang`, `water`, `humans_coords`, `zombies_coords`, `camera_coords`, `checkpoint_coords`, `gates_coords`, `gates_move_coords`, `npc_coords`, `npc_skin`, `flag_coords`, `flag_coords_text`, `disabled`) \
	VALUES \
	(1, 'The Village', 'village', 0, 0, 12, '15.000', '', '1.000', 12, 0, 1, '744.0316,-550.7260,17.1647,358.7975,681.8290,-554.5507,16.1875,357.8575,641.3369,-557.3655,16.1875,359.1342', '741.9293,-549.5023,17.0694,354.7242,623.4771,-506.2735,16.3525,88.4586,611.7243,-601.8662,17.2266,272.0502', '676.6566,-460.0044,27.1080,676.7922,-460.9932,26.9030', '681.8102,-508.0689,16.1875', '', '', '681.7691,-603.2256,16.1849,1.0143', 158, '672.4241,-540.2498,17.5474,0.0000,290.0000,347.5840', '673.0986,-540.4794,18.4757', 0);\
"

#define PREDIFINED_CIVILIAN "INSERT IGNORE INTO classes (id, name, description, team, level, ability, cooldown, skin, disabled) VALUES (1, \"Civilian|Гражданский\", \"No abilities|Без способностей\", 2, 0, 0, 0, 37, 0);"
#define PREDIFINED_NURSE "INSERT IGNORE INTO classes (id, name, description, team, level, ability, cooldown, skin, disabled) VALUES (2, \"Nurse|Медсестра\", \"Can Cure|Может Лечить\", 2, 0, 1, 5, 308, 0);"
#define PREDIFINED_ENGINEER "INSERT IGNORE INTO classes (id, name, description, team, level, ability, cooldown, skin, disabled) VALUES (3, \"Engineer|Инжинер\", \"Can Build Boxes|Может Строить Коробки\", 2, 9, 2, 0, 153, 0);"
#define PREDIFINED_JUMPER "INSERT IGNORE INTO classes (id, name, description, team, level, ability, cooldown, skin, disabled) VALUES (4, \"Jumper|Прыгун\", \"Can Use High Jump|Может Высоко Подпрыгнуть\", 2, 12, 3, 15, 210, 0);"
#define PREDIFINED_FAKE_ZOMBIE "INSERT IGNORE INTO classes (id, name, description, team, level, ability, cooldown, skin, disabled) VALUES (5, \"Fake Zombie|Подделный зомби\", \"Invisible|Невидимость\", 2, 15, 4, 0, 181, 0);"
#define PREDIFINED_RUNNER "INSERT IGNORE INTO classes (id, name, description, team, level, ability, cooldown, skin, disabled) VALUES (6, \"Runner|Бегун\", \"Fast Run|Быстрый Бег\", 2, 18, 0, 0, 0, 0);"
#define PREDIFINED_DOCTOR "INSERT IGNORE INTO classes (id, name, description, team, level, ability, cooldown, skin, disabled) VALUES (7, \"Doctor|Доктор\", \"Can Heal|Может Лечить\", 2, 21, 5, 10, 70, 0);"

#define PREDIFINED_STANDARD_ZOMBIE "INSERT IGNORE INTO classes (id, name, description, team, level, ability, cooldown, skin, disabled) VALUES (8, \"Standard Zombie|Обычный Зомби\", \"Can Infect|Может Заразить\", 1, 0, 6, 5, 181, 0);"
#define PREDIFINED_ROGUE_ZOMBIE "INSERT IGNORE INTO classes (id, name, description, team, level, ability, cooldown, skin, disabled) VALUES (9, \"Rogue Zombie|Поддельный Человек\", \"Invisible|Невидимость\", 1, 3, 4, 0, 135, 0);"
#define PREDIFINED_FAST_ZOMBIE "INSERT IGNORE INTO classes (id, name, description, team, level, ability, cooldown, skin, disabled) VALUES (10, \"Fast Zombie|Прыгающий Зомби\", \"Can Use High Jump|Может Высоко Подпрыгнуть\", 1, 6, 3, 15, 162, 0);"
#define PREDIFINED_STOMPER_ZOMBIE "INSERT IGNORE INTO classes (id, name, description, team, level, ability, cooldown, skin, disabled) VALUES (11, \"Stomper Zombie|Подбрасывающий Зомби\", \"Can Stomp Humans|Может Подбросить Людей\", 1, 9, 7, 15, 78, 0);"
#define PREDIFINED_RADIOACTIVE_ZOMBIE "INSERT IGNORE INTO classes (id, name, description, team, level, ability, cooldown, skin, disabled) VALUES (12, \"Radioactive Zombie|Радиоактивный Зомби\", \"Radioactive Field|Радиоактивное Поле\", 1, 12, 8, 0, 146, 0);"
#define PREDIFINED_SLOW_ZOMBIE "INSERT IGNORE INTO classes (id, name, description, team, level, ability, cooldown, skin, disabled) VALUES (13, \"Slow Zombie|Замедляющий Зомби\", \"Can Infect|Может Заразить\", 1, 15, 9, 15, 160, 0);"
#define PREDIFINED_BOOMER_ZOMBIE "INSERT IGNORE INTO classes (id, name, description, team, level, ability, cooldown, skin, disabled) VALUES (14, \"Boomer Zombie|Взрывающийся Зомби\", \"Huge Explode On Death|Большой Взрыв При Смерти\", 1, 18, 10, 0, 264, 0);"
#define PREDIFINED_RUNNER_ZOMBIE "INSERT IGNORE INTO classes (id, name, description, team, level, ability, cooldown, skin, disabled) VALUES (15, \"Runner Zombie|Быстрый Зомби\", \"Fast Run|Быстрый Бег\", 1, 21, 0, 0, 0, 0);"
#define PREDIFINED_SEEKER_ZOMBIE "INSERT IGNORE INTO classes (id, name, description, team, level, ability, cooldown, skin, disabled) VALUES (16, \"Seeker Zombie|Охотник Зомби\", \"Can Teleport|Может Телепортироватся\", 1, 24, 11, 45, 142, 0);"

#define PREDIFINED_SILINCED "INSERT IGNORE INTO weapons (id, type, min, max, pick) VALUES (1, 23, 50, 150, 10);"
#define PREDIFINED_COLT45 "INSERT IGNORE INTO weapons (id, type, min, max, pick) VALUES (2, 22, 50, 150, 10);"
#define PREDIFINED_DEAGLE "INSERT IGNORE INTO weapons (id, type, min, max, pick) VALUES (3, 24, 50, 100, 10);"
#define PREDIFINED_UZI "INSERT IGNORE INTO weapons (id, type, min, max, pick) VALUES (4, 28, 150, 400, 50);"
#define PREDIFINED_TEC9 "INSERT IGNORE INTO weapons (id, type, min, max, pick) VALUES (5, 32, 150, 300, 50);"
#define PREDIFINED_MP5 "INSERT IGNORE INTO weapons (id, type, min, max, pick) VALUES (6, 29, 150, 300, 35);"
#define PREDIFINED_AK47 "INSERT IGNORE INTO weapons (id, type, min, max, pick) VALUES (7, 30, 300, 500, 30);"
#define PREDIFINED_M4 "INSERT IGNORE INTO weapons (id, type, min, max, pick) VALUES (8, 31, 300, 500, 30);"
#define PREDIFINED_RIFLE "INSERT IGNORE INTO weapons (id, type, min, max, pick) VALUES (9, 33, 15, 30, 3);"
#define PREDIFINED_SNIPER "INSERT IGNORE INTO weapons (id, type, min, max, pick) VALUES (10, 34, 50, 50, 3);"
#define PREDIFINED_FLAMETHOWER "INSERT IGNORE INTO weapons (id, type, min, max, pick) VALUES (11, 37, 500, 500, 150);"
#define PREDIFINED_GRENADE "INSERT IGNORE INTO weapons (id, type, min, max, pick) VALUES (12, 16, 3, 15, 1);"
#define PREDIFINED_SPAS "INSERT IGNORE INTO weapons (id, type, min, max, pick) VALUES (13, 27, 50, 50, 3);"

#define PREDIFINED_GANGS_CONFIG "INSERT IGNORE INTO gangs_config (id) VALUES (NULL);"
#define PREDIFINED_CONFIG "INSERT IGNORE INTO config (id) VALUES (NULL);"
#define PREDIFINED_ANTICHEAT "INSERT IGNORE INTO anticheat (id) VALUES (NULL);"

#define PRD_LD_DG_LOGIN_TITLE "INSERT IGNORE INTO english (id, text) VALUES (1, 'Login');"
#define PRD_LD_DG_LOGIN_DEFAULT "INSERT IGNORE INTO english (id, text) VALUES (2, 'Welcome back, your account is already registered\nEnter your password below to login');"
#define PRD_LD_DG_LOGIN_TRIES "INSERT IGNORE INTO english (id, text) VALUES (3, 'Wrong password, %d / 3 tries left\n\nWelcome back, your account is already registered\nEnter your password below to login');"
#define PRD_LD_DG_LOGIN_SPACES "INSERT IGNORE INTO english (id, text) VALUES (4, 'You have to type at least something!\n\nWelcome back, your account is already registered\nEnter your password below to login');"
#define PRD_LD_DG_REG_TITLE "INSERT IGNORE INTO english (id, text) VALUES (5, 'Register');"
#define PRD_LD_DG_REG_DEFAULT "INSERT IGNORE INTO english (id, text) VALUES (6, 'Welcome to the server, your account was not found\nEnter your password below to complete registration');"
#define PRD_LD_DG_REG_SPACES "INSERT IGNORE INTO english (id, text) VALUES (7, 'You have to type at least something!\n\nWelcome to the server, your account was not found\nEnter your password below to complete registration');"
#define PRD_LD_BTN_REG "INSERT IGNORE INTO english (id, text) VALUES (8, 'Register');"
#define PRD_LD_BTN_LOGIN "INSERT IGNORE INTO english (id, text) VALUES (9, 'Login');"
#define PRD_LD_BTN_QUIT "INSERT IGNORE INTO english (id, text) VALUES (10, 'Quit');"