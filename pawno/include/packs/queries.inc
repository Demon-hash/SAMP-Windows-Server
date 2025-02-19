#if defined _queries_pack_included
	#endinput
#endif
#define _queries_pack_included

#define MAX_AUTOLOG_HOURS 21600

#define REG_ACCOUNT_QUERY "INSERT INTO `users` (`login`, `password`) VALUES ('%e', '%e');"
#define REG_ACCOUNT_INFORMATION_QUERY "INSERT INTO `registration` (`reg_at`, `reg_ip`, `reg_key`) VALUES (%d, '%e', '%e');"
#define REG_PRIVILEGES_QUERY "INSERT INTO `privileges` (`id`) VALUE (NULL);"
#define REG_SETTINGS_QUERY "INSERT INTO `settings` (`id`) VALUE (NULL);"
#define REG_ACHIEVEMENTS_QUERY "INSERT INTO `achievements` (`id`) VALUE (NULL);"
#define REG_GANG_ACCCOUNT_QUERY "INSERT INTO `gangs_users` (`id`) VALUE (NULL);"
#define CREATE_SESSION_QUERY "INSERT INTO `login_log` (`account_id`, `date`, `ip`, `key`) VALUES (%d, %d, '%e', '%e');"
#define LOAD_LOCALIZATION_QUERY "SELECT `%e` as text FROM `localization` WHERE 1;"
#define LOAD_LOCALIZATION_TIPS_QUERY "SELECT `%e` as text FROM `random_messages` WHERE 1;"
#define LOAD_SERVER_CFG_QUERY "SELECT * FROM config WHERE 1 LIMIT 1;"
#define LOAD_WEEKLY_CFG_QUERY "SELECT * FROM weekly_cfg WHERE 1 LIMIT 1;"
#define LOAD_ROUND_CFG_QUERY "SELECT * FROM round_config WHERE 1 LIMIT 1;"
#define LOAD_MAPS_COUNT_QUERY "SELECT COUNT( `id` ) AS maps FROM `maps` WHERE `disabled`=0;"
#define LOAD_MAP_DATA_QUERY "SELECT m.*, COALESCE(u.login, '') AS login FROM `maps` m LEFT JOIN `users` u ON u.id = m.author WHERE m.id = %d;"
#define LOAD_MAP_NAME_QUERY "SELECT * FROM `maps_localization` WHERE id = %d;"
#define LOAD_ACHIEVEMENT_NAME_QUERY "SELECT * FROM `achievements_localization` WHERE id = %d;"
#define REFRESH_PLAYER_WEAPONS_QUERY "DELETE FROM `weapons` WHERE `time` < %d;"
#define LOAD_GANGS_CFG_QUERY "SELECT * FROM gangs_config WHERE 1 LIMIT 1;"
#define LOAD_EVAC_CFG_QUERY "SELECT * FROM evac_config WHERE 1 LIMIT 1;"
#define LOAD_MAP_CFG_QUERY "SELECT * FROM map_config WHERE 1 LIMIT 1;"
#define LOAD_WEAPONS_CFG_QUERY "SELECT * FROM weapons_config WHERE 1;"
#define LOAD_DUELS_CFG_QUERY "SELECT * FROM duels_config WHERE 1;"
#define LOAD_BALANCE_CFG_QUERY "SELECT * FROM balance_config WHERE 1 LIMIT 1;"
#define LOAD_TEXTURES_CFG_QUERY "SELECT * FROM textures_config WHERE 1;"
#define LOAD_LOCALIZED_CLASSES_QUERY "SELECT c.id, c.points, COALESCE(l.%e_title, '') as title, COALESCE(l.%e_desc, '') as description FROM `classes` c LEFT JOIN `classes_localization` l ON l.id = c.id WHERE c.disabled = 0 AND c.team = %d ORDER BY c.points ASC;"
#define LOAD_CLASSES_QUERY "SELECT * FROM `classes` WHERE 1;"
#define LOAD_CLASSES_CFG_QUERY "SELECT * FROM `classes_config` WHERE 1 LIMIT 1;"
#define GET_RANDOM_SKIN_QUERY "SELECT c.skin,c.health,c.armour FROM `classes` c WHERE `disabled` = 0 AND `team` = %d ORDER BY RAND() LIMIT 1;"
#define LOAD_OBJECTS_QUERY "SELECT * FROM `objects` WHERE 1;"
#define LOAD_LOCALIZATION_QST_QUERY "SELECT `%e` as text, `%e_answer` as answer FROM `random_question` WHERE 1;"
#define LOAD_ACHS_CFG_QUERY "SELECT * FROM `achievements_config` WHERE 1;"
#define GET_RULES_QUERY "SELECT %e as text FROM `za_rules` WHERE 1;"
#define GET_HELP_QUERY "SELECT %e as text FROM `za_help` WHERE 1;"
#define PREPARE_WEEKLY_ACTIVITIES_QUERY "SELECT %e as text, activity, count, type FROM weekly_activities_cfg WHERE `activity` IN (%e)"
#define GET_ID_MATCHES_QUERY "SELECT `id`, `login` FROM `users` WHERE `login` LIKE '%%%e%%' LIMIT 10"
#define LOAD_GANGS_QUERY "SELECT g . *, COUNT(gu.id) AS members FROM `gangs` g LEFT JOIN `gangs_users` gu ON gu.gang_id = g.game_id WHERE g.`disabled` = 0"
#define SAVE_MAP_DATA_QUERY "UPDATE `maps` SET `gang`='%d', `points`='%d', `flag_date`='%d' WHERE `id`='%d'"
#define SAVE_GANGS_DATA "UPDATE `gangs` SET name='%e', tag='%e', capacity='%d', points='%d', war='%e', alliance='%e', settings='%e' WHERE `game_id` = '%d'"

#define GET_GANG_MEMBERS_QUERY "\
	SELECT gu.rank, gu.id, u.login,\n\
	COALESCE((SELECT `date` FROM login_log WHERE account_id = gu.id ORDER BY `date` DESC LIMIT 1),' ') AS last_login\n\
	FROM gangs_users gu\n\
	LEFT JOIN users u\n\
	ON gu.id = u.id\n\
	WHERE gu.gang_id = '%d' AND gu.id > '%d'\n\
	LIMIT %d\
"

#define PREPARE_CLOTH_INFO_QUERY "SELECT `%e` AS `text`, `coins`, `emblems`, `kit` FROM `clothes_locale` WHERE `kit` = '%d'"
#define PREPARE_WEEKLY_REWARD_QUERY "SELECT `%e` AS `text`, `coins`, `kit`, `emblems` FROM `clothes_locale` WHERE `kit` IN (%e)"
#define LOAD_CLOTHES_DATA_QUERY "SELECT * FROM `clothes_cfg` WHERE `kit` = '%d';"
#define BUY_WEEKLY_CLOTH_QUERY "INSERT INTO `clothes` (account_id, kit) VALUES (%d, %d)"
#define DELETE_PLAYER_WEEKLY_QUERY "DELETE FROM `weekly` WHERE 1;"
#define PREPARE_CLOTHES_INV_QUERY "\
	SELECT c.id, c.kit, cl.%e AS `text`\n\
	FROM `clothes` c\n\
	LEFT JOIN `clothes_locale` cl\n\
	ON cl.kit = c.kit\n\
	WHERE `account_id` = %d AND c.id > %d\n\
	LIMIT %d\
"

#define UPDATE_WEEKLY_CFG_QUERY "UPDATE `weekly_cfg` SET `next_update`='%d',`activities`='%e',`types`='%e',`count`='%e',`rewards`='%e' WHERE 1;"

#define SET_WEEKLY_VARIABLE_QUERY "\
	SET @weekly = (SELECT CONCAT_WS(',',\n\
		(SELECT SUBSTRING_INDEX(GROUP_CONCAT(activity ORDER BY RAND()), ',', 2) FROM weekly_activities_cfg WHERE type = 2),\n\
		(SELECT SUBSTRING_INDEX(GROUP_CONCAT(activity ORDER BY RAND()), ',', 2) FROM weekly_activities_cfg WHERE type = 1),\n\
		(SELECT SUBSTRING_INDEX(GROUP_CONCAT(activity ORDER BY RAND()), ',', 4) FROM weekly_activities_cfg WHERE type = 0)\n\
	));\
"

#define CREATE_WEEKLY_ACTIVITIES_QUERY "\
	SELECT (SELECT SUBSTRING_INDEX(GROUP_CONCAT(kit ORDER BY RAND()), ',', 4) FROM clothes_locale WHERE 1) as rewards,\n\
	@weekly AS `activities`,\n\
	(SELECT GROUP_CONCAT(type ORDER BY FIND_IN_SET(w.activity, @weekly)) FROM weekly_activities_cfg w WHERE FIND_IN_SET (w.activity, @weekly)) as `types`,\n\
	(SELECT GROUP_CONCAT(count ORDER BY FIND_IN_SET(w.activity, @weekly)) FROM weekly_activities_cfg w WHERE FIND_IN_SET (w.activity, @weekly)) as `count`\n\
	FROM config\n\
	WHERE 1\
"

#define LOAD_ACHIEVEMENTS_PAGE "SELECT l.%e AS title, l.%e_desc AS description, c.type, c.count, c.reward, (\
	SELECT COUNT( c.id ) \
		FROM achievements_config c \
		WHERE c.disabled = 0 \
	) AS total \
	FROM achievements_localization l \
	LEFT JOIN achievements_config c ON c.id = l.id \
	WHERE c.disabled = 0 \
	LIMIT %d, %d\
"

#define PRELOAD_CLASSES_TITLES "\
	SELECT COALESCE(l.%e_title, '') AS title, c.id -1 AS id \
	FROM `classes` c \
	LEFT JOIN `classes_localization` l ON l.id = c.id \
	WHERE c.disabled = 0 \
	AND c.team = %d \
	LIMIT 1 \
	UNION (\
		SELECT COALESCE(l.%e_title, ''), c.id -1 AS id \
		FROM `classes` c \
		LEFT JOIN `classes_localization` l ON l.id = c.id \
		WHERE c.disabled = 0 \
		AND c.team = %d \
		ORDER BY c.points ASC \
		LIMIT 1 \
	) \
	LIMIT 2\
"

#define UPDATE_USER_QUERY "\
	UPDATE `users` \n\
	SET \n\
		`language`='%d',\
		`points`='%d',\
		`coins`='%d'\n\
		WHERE `id`='%d'\
"

#define CREATE_WEEKLY_PLAYER_QUERY "\
	INSERT INTO `weekly` (id, standing, coins, activities, progress)\n\
	VALUES(%d, %d, %d, '%e', '%e')\n\
	ON DUPLICATE KEY UPDATE\n\
	standing=%d,\ 
	coins=%d,\
	activities='%e',\
	progress='%e'\
"

#define UPDATE_GANG_USER_QUERY "UPDATE `gangs_users` SET `gang_id`='%d', `rank`='%d' WHERE `id`='%d'"
#define SET_GANG_USER_QUERY "UPDATE `gangs_users` SET `joined_at`='%d', `accepted_by`='%d' WHERE `id`='%d'"

#define UPDATE_PRIVILAGES_QUERY "\
	UPDATE `privileges` \n\
	SET \n\
		`admin`='%d',\
		`vip`='%d',\
		`vip_till`='%d'\n\
		WHERE `id`='%d'\
"

#define UPDATE_SETTINGS_QUERY "\
	UPDATE `settings` \n\
	SET \n\
		`pm`='%d',\
		`ding`='%d',\
		`duels`='%d',\
		`ability`='%d',\
		`auto_login`='%d'\n\
		WHERE `id`='%d'\
"

#define UPDATE_ACHIEVEMENTS_QUERY "\
	UPDATE `achievements` \n\
	SET \n\
		`rank`='%d',\
		`kills`='%d',\
		`deaths`='%d',\
		`ability`='%d',\
		`luck`='%d',\
		`humans`='%d',\
		`zombies`='%d',\
		`meats`='%d',\
		`ammo`='%d',\
		`killstreak`='%d',\
		`infection`='%d',\
		`cure`='%d',\
		`evacs`='%d',\
		`reported`='%d',\
		`jumps`='%d',\
		`hours`='%d',\
		`minutes`='%d',\
		`seconds`='%d',\
		`silinced`='%d',\
		`colt45`='%d',\
		`deagle`='%d',\
		`rifle`='%d',\
		`shotgun`='%d',\
		`mp5`='%d',\
		`combat`='%d',\
		`tec9`='%d',\
		`ak47`='%d',\
		`m4`='%d',\
		`master`='%d',\
		`hermitage`='%d',\
		`last_hope`='%d',\
		`answer`='%d',\
		`lottery`='%d',\
		`capture`='%d',\
		`duels`='%d',\
		`session`='%d',\
		`blood`='%d',\
		`mary`='%d',\
		`gang`='%d',\
		`evacuations`='%d',\
		`vehicles`='%d',\
		`total_points`='%d',\
		`ran`='%f',\
		`progress`='%e'\n\
		WHERE `id` = '%d'\
"

#define CHECK_USER_QUERY "\
	SELECT \n\
		u.*,\n\
		COALESCE(a.rank, 0) as rank,\n\
		COALESCE(a.kills, 0) as kills,\n\
		COALESCE(a.deaths, 0) as deaths,\n\
		COALESCE(a.ability, 0) as ability,\n\
		COALESCE(a.ran, 0.0) as ran,\n\
		COALESCE(a.luck, 0) as luck,\n\
		COALESCE(a.humans, 0) as humans,\n\
		COALESCE(a.zombies, 0) as zombies,\n\
		COALESCE(a.meats, 0) as meats,\n\
		COALESCE(a.ammo, 0) as ammo,\n\
		COALESCE(a.killstreak, 0) as killstreak,\n\
		COALESCE(a.infection, 0) as infection,\n\
		COALESCE(a.cure, 0) as cure,\n\
		COALESCE(a.evacs, 0) as evacs,\n\
		COALESCE(a.reported, 0) as reported,\n\
		COALESCE(a.jumps, 0) as jumps,\n\
		COALESCE(a.total_points, 0) as total_points,\n\
		COALESCE(a.hours, 0) as hours,\n\
		COALESCE(a.minutes, 0) as minutes,\n\
		COALESCE(a.seconds, 0) as seconds,\n\
		COALESCE(a.silinced, 0) as silinced,\n\
		COALESCE(a.colt45, 0) as colt45,\n\
		COALESCE(a.deagle, 0) as deagle,\n\
		COALESCE(a.rifle, 0) as rifle,\n\
		COALESCE(a.shotgun, 0) as shotgun,\n\
		COALESCE(a.mp5, 0) as mp5,\n\
		COALESCE(a.combat, 0) as combat,\n\
		COALESCE(a.tec9, 0) as tec9,\n\
		COALESCE(a.ak47, 0) as ak47,\n\
		COALESCE(a.m4, 0) as m4,\n\
		COALESCE(a.master, 0) as master,\n\
		COALESCE(a.hermitage, 0) as hermitage,\n\
		COALESCE(a.last_hope, 0) as last_hope,\n\
		COALESCE(a.answer, 0) as answer,\n\
		COALESCE(a.lottery, 0) as lottery,\n\
		COALESCE(a.capture, 0) as capture,\n\
		COALESCE(a.duels, 0) as duels,\n\
		COALESCE(a.session, 0) as session,\n\
		COALESCE(a.blood, 0) as blood,\n\
		COALESCE(a.mary, 0) as mary,\n\
		COALESCE(a.gang, 0) as ach_gang,\n\
		COALESCE(a.vehicles, 0) as vehicles,\n\
		COALESCE(a.progress, '') as progress,\n\
		COALESCE(p.admin, 0) as admin,\n\
		COALESCE(p.vip, 0) as vip,\n\
		COALESCE(p.vip_till, 0) as vip_till,\n\
		COALESCE(g.gang_id, -1) as gang_id,\n\
		COALESCE(g.rank, 0) as gang_rank,\n\
		COALESCE(s.pm, 0) as set_pm,\n\
		COALESCE(s.ding, 0) as set_ding,\n\
		COALESCE(s.duels, 0) as set_duels,\n\
		COALESCE(s.ability, 0) as set_ability,\n\
		COALESCE(s.auto_login, 0) as set_auto_login,\n\
		COALESCE(w.standing, 0) as w_standing,\n\
		COALESCE(w.coins, 0) as w_coins,\n\
		COALESCE(w.progress, '') as w_progress,\n\
		COALESCE(w.activities, '') as w_activities,\n\
		COALESCE(l.ip, 'NULL') as login_ip,\n\
		COALESCE(l.date, 0) as login_date,\n\
		COALESCE(l.account_id, -1) as login_id,\n\
		COALESCE(r.map_id, 65535) as rnd_mapid,\n\
		COALESCE(r.team, 65535) as rnd_team,\n\
		COALESCE(r.survival, 0.0) as rnd_survival,\n\
		COALESCE(r.killing, 0.0) as rnd_killing,\n\
		COALESCE(r.care, 0.0) as rnd_care,\n\
		COALESCE(r.mobility, 0.0) as rnd_mobility,\n\
		COALESCE(r.skillfulness, 0.0) as rnd_skillfulness,\n\
		COALESCE(r.brutality, 0.0) as rnd_brutality,\n\
		COALESCE(r.undead, 0.0) as rnd_undead,\n\
		COALESCE(r.time, 0) as rnd_time,\n\
		COALESCE(r.additional, 0.0) as rnd_additional\n\
		FROM `users` u\n\
		LEFT JOIN `achievements` a ON u.id = a.id\n\
		LEFT JOIN `privileges` p ON u.id = p.id\n\
		LEFT JOIN `gangs_users` g ON u.id = g.id\n\
		LEFT JOIN `settings` s ON u.id = s.id\n\
		LEFT JOIN `round_session` r ON u.id = r.account_id\n\
		LEFT JOIN `login_log` l ON u.id = l.account_id\n\
		LEFT JOIN `weekly` w ON u.id = w.id\n\
		WHERE u.login = '%e'\n\
		ORDER BY l.date DESC\n\
		LIMIT 1\
"

#define LOAD_PLAYER_BAN "\
	SELECT b.date, b.valid_till, b.permanent, b.reason, u.login AS admin\n\
	FROM `ban_log` b\n\
	LEFT JOIN users u ON u.id = b.issued_id\n\
	WHERE `account_id` = %d AND `unbanned_id` = 0\n\
	ORDER BY b.date DESC\n\
	LIMIT 1\
"

#define CREATE_RND_SESSION_QUERY "INSERT INTO `round_session` (account_id, map_id, team, survival, killing, care, mobility, skillfulness, brutality, undead, additional, time) VALUES (%d,%d,%d,%f,%f,%f,%f,%f,%f,%f,%f,%d)"
#define DELETE_RND_SESSION_QUERY "DELETE FROM `round_session` WHERE `account_id`='%d'"

#define CREATE_SIGN "INSERT INTO `signs` (name, account_id, ip, sign, date) VALUES ('%e', %d, '%e', '%e', %d)"
#define UPDATE_SIGN "UPDATE `signs` SET `name`='%e',`points`='%d',`total`='%d' WHERE `account_id` = '%d'"

#define CREATE_VOTEKICK_LOG "INSERT INTO `votekick_log` (account_id, target_id, date, reason, ip, target_ip) VALUES (%d, %d, %d, '%e', '%e', '%e')"
#define CREATE_JAIL_LOG "INSERT INTO `jails_log` (account_id, issued_id, date, reason, target_ip, issued_ip) VALUES (%d, %d, %d, '%e', '%e', '%e')"
#define CREATE_WARN_LOG "INSERT INTO `warns_log` (account_id, issued_id, date, reason, target_ip, issued_ip) VALUES (%d, %d, %d, '%e', '%e', '%e')"
#define CREATE_MUTE_LOG "INSERT INTO `mutes_log` (account_id, issued_id, date, time, reason, target_ip, issued_ip) VALUES (%d, %d, %d, %d, '%e', '%e', '%e')"
#define CREATE_NAME_LOG "INSERT INTO `name_log` (account_id, date, current_name, last_name, ip) VALUES (%d, %d, '%e', '%e', '%e')"
#define CREATE_PAY_LOG "INSERT INTO `pay_log` (to_id, from_id, amount, type, to_ip, from_ip, date) VALUES (%d, %d, %d, %d, '%e', '%e', %d)"

#define CREATE_BAN_LOG "INSERT INTO `ban_log` (account_id, issued_id, unbanned_id, date, valid_till, permanent, reason, target_ip, issued_ip) VALUES (%d, %d, %d, %d, %d, %d, '%e', '%e', '%e')"
#define UPDATE_BAN_LOG "UPDATE `ban_log` SET `unbanned_id` = %d WHERE `account_id` = (SELECT `id` FROM `users` WHERE `login` = '%e')"

#define CREATE_GANG_QUERY "INSERT INTO `gangs` (name, tag, game_id, leader_id, date) VALUES ('%e', '%e', %d, %d, %d)"

#define CHANGENAME_QUERY "\
	UPDATE `users` SET `login` = '%e' WHERE `id` = '%d'\n\
	AND (NOT EXISTS (SELECT * FROM (SELECT * FROM `users`) AS temp WHERE temp.login = '%e'))\
"

#define BANIP_QUERY "\
	INSERT INTO `banip_log` (account_id, date, reason, target_ip, ip)\n\
	SELECT '%d', '%d', '%e', '%e', '%e'\n\
	FROM config\n\
	WHERE (NOT EXISTS (SELECT * FROM (SELECT * FROM `banip_log`) AS temp WHERE temp.ip = '%e'))\
"

#define UNBANIP_QUERY "\
	DELETE FROM `banip_log`\n\
	WHERE `ip`='%e'\
"

#define OFFLINE_BAN_QUERY "\
	INSERT INTO `ban_log` (account_id, issued_id, unbanned_id, `date`, valid_till, permanent, reason, target_ip, issued_ip)\n\
	SELECT u.id, '%d', '%d', '%d', '%d', '%d', '%e', l.ip, '%e'\n\
	FROM `users` u\n\
	LEFT JOIN `login_log` l\n\
	ON u.id = l.id\n\
	WHERE `login` = '%e'\n\
	ORDER BY l.date DESC\n\
	LIMIT 1\
"

#define GET_GANGS_LIST_QUERY "\
	SELECT g.name, g.tag, g.game_id, u.login AS founder,\n\
	COALESCE(GROUP_CONCAT((SELECT `%e` FROM `maps_localization` l WHERE l.id = m.id LIMIT 3)), '') AS `maps`\n\
	FROM gangs g\n\
	LEFT JOIN users u ON g.leader_id = u.id\n\
	LEFT JOIN maps m ON g.game_id = m.gang\n\
	WHERE g.disabled = 0 AND g.leader_id > 0\n\
	GROUP BY g.id\n\
	ORDER BY COUNT(m.gang) DESC\
"

#define GET_BLACKLIST_QUERY "\
	SELECT `reason`\n\
	FROM `gangs_blacklisted`\n\
	WHERE `gang_id` = '%d' AND `account_id` = '%d'\
"

#define IPRANGE_QUERY "SELECT DISTINCT `ip` FROM `login_log` WHERE `account_id` = '%d' LIMIT 30;"
#define IPID_QUERY "SELECT DISTINCT `account_id` AS id FROM `login_log` WHERE `ip` = '%e' ORDER BY date DESC LIMIT 30;"
#define HASH_QUERY "SELECT DISTINCT `key` FROM `login_log` WHERE `account_id` = '%d' LIMIT 30;"

#define GET_WARNLOG_QUERY "\
        SELECT u.login, b.id, b.reason, b.date,\n\
	COALESCE((SELECT `login` FROM `users` WHERE `id` = b.issued_id), '') as admin\n\
	FROM `warns_log` b\n\
	LEFT JOIN users u\n\
	ON u.id = b.account_id\n\
	WHERE b.account_id = '%d' AND b.id < %d\n\
	ORDER BY b.date DESC\n\
	LIMIT %d;\
"

#define GET_JAILLOG_QUERY "\
        SELECT u.login, b.id, b.reason, b.date,\n\
	COALESCE((SELECT `login` FROM `users` WHERE `id` = b.issued_id), '') as admin\n\
	FROM `jails_log` b\n\
	LEFT JOIN users u\n\
	ON u.id = b.account_id\n\
	WHERE b.account_id = '%d' AND b.id < %d\n\
	ORDER BY b.date DESC\n\
	LIMIT %d;\
"

#define GET_MUTELOG_QUERY "\
        SELECT u.login, b.reason, b.id, b.date,\n\
	COALESCE((SELECT `login` FROM `users` WHERE `id` = b.issued_id), '') as admin\n\
	FROM `mutes_log` b\n\
	LEFT JOIN users u\n\
	ON u.id = b.account_id\n\
	WHERE b.account_id = '%d' AND b.id < %d\n\
	ORDER BY b.date DESC\n\
	LIMIT %d;\
"

#define GET_VOTEKICKLOG_QUERY "\
        SELECT u.login, b.reason, b.id, b.date,\n\
	COALESCE((SELECT `login` FROM `users` WHERE `id` = b.account_id), '') as admin\n\
	FROM `votekick_log` b\n\
	LEFT JOIN users u\n\
	ON u.id = b.target_id\n\
	WHERE b.target_id = '%d' AND b.id < %d\n\
	ORDER BY b.date DESC\n\
	LIMIT %d;\
"

#define GET_NAMELOG_QUERY "\
        SELECT current_name, last_name, ip, id, date\n\
	FROM `name_log`\n\
	WHERE account_id = '%d' AND id < %d\n\
	ORDER BY date DESC\n\
	LIMIT %d;\
"

#define GET_BANLOG_QUERY "\
        SELECT u.login AS target, b.id, b.reason, b.target_ip, b.date,\n\
	COALESCE((SELECT `login` FROM `users` WHERE `id` = b.issued_id), '') as admin,\n\
	COALESCE((SELECT `login` FROM `users` WHERE `id` = b.unbanned_id), '') as unbanner\n\
	FROM `ban_log` b\n\
	LEFT JOIN users u\n\
	ON u.id = b.account_id\n\
	WHERE b.account_id = '%d' AND b.id < %d\n\
	ORDER BY b.date DESC\n\
	LIMIT %d;\
"

#define GET_PAYLOG_QUERY "\
        SELECT COALESCE(u.login, 'System') AS `to`, b.amount, b.type, b.id, b.to_ip, b.from_ip, b.date,\n\
	COALESCE((SELECT `login`FROM `users` WHERE `id` = b.from_id), 'System') AS `from`\n\
	FROM `pay_log` b\n\
	LEFT JOIN users u ON u.id = b.to_id\n\
	WHERE (b.to_id = '%d' OR b.from_id = '%d') AND b.id < %d\n\
	ORDER BY b.date DESC\n\
	LIMIT %d;\
"

#define GET_BANIPLOG_QUERY "\
	SELECT u.login, b.id, b.date, b.reason, b.ip\n\
	FROM `banip_log` b\n\
	LEFT JOIN users u\n\
	ON u.id = b.account_id\n\
	WHERE 1\n\
	LIMIT 15;\
"

#define GET_ADMINS_ACTIVITY "\
        SELECT u.login, p.admin, (SELECT `date` FROM `login_log` WHERE account_id = u.id ORDER BY `date` DESC LIMIT 1) AS `date`\
	FROM PRIVILEGES p\n\
	LEFT JOIN users u ON p.id = u.id\n\
	WHERE p.admin > 0\n\
	GROUP BY u.id\n\
	LIMIT 15;\
"

#define CLEAR_SIGNS_QUERY "DELETE FROM `signs` WHERE `date` < %d"
#define CLEAR_LOGINS_QUERY "DELETE FROM `login_log` WHERE `date` < %d"
#define CLEAR_JAILS_QUERY "DELETE FROM `jails_log` WHERE `date` < %d"
#define CLEAR_MUTES_QUERY "DELETE FROM `mutes_log` WHERE `date` < %d"
#define CLEAR_VOTEKICK_QUERY "DELETE FROM `votekick_log` WHERE `date` < %d"
#define CLEAR_PAYS_QUERY "DELETE FROM `pay_log` WHERE `date` < %d"
#define CLEAR_NAMES_QUERY "DELETE FROM `name_log` WHERE `date` < %d"