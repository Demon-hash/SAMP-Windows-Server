#if defined _queries_pack_included
	#endinput
#endif
#define _queries_pack_included

#define REG_ACCOUNT_QUERY "INSERT INTO `users` (`login`, `password`) VALUES ('%e', '%e');"
#define REG_ACCOUNT_INFORMATION_QUERY "INSERT INTO `registration` (`reg_at`, `reg_ip`, `reg_key`) VALUES (%d, '%e', '%e');"
#define REG_PRIVILEGES_QUERY "INSERT INTO `privileges` (`id`) VALUE (NULL);"
#define REG_ACHIEVEMENTS_QUERY "INSERT INTO `achievements` (`id`) VALUE (NULL);"
#define REG_GANG_ACCCOUNT_QUERY "INSERT INTO `gangs_users` (`id`) VALUE (NULL);"
#define CREATE_SESSION_QUERY "INSERT INTO `login_log` (`account_id`, `date`, `ip`, `key`) VALUES (%d, %d, '%e', '%e');"
#define LOAD_LOCALIZATION_QUERY "SELECT * FROM %e WHERE 1;"
#define LOAD_SERVER_CFG_QUERY "SELECT * FROM config WHERE 1;"
#define LOAD_MAPS_COUNT_QUERY "SELECT COUNT( `id` ) AS maps FROM `maps` WHERE `disabled`='0';"
#define LOAD_MAP_DATA_QUERY "SELECT m.*, COALESCE(u.login, '') as login FROM `maps` m LEFT JOIN `users` u ON u.id = m.author WHERE m.id = %d;"
#define LOAD_GANGS_CFG_QUERY "SELECT * FROM gangs_config WHERE 1;"


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
		COALESCE(a.killstreak, 0) as killstreak,\n\
		COALESCE(a.infection, 0) as infection,\n\
		COALESCE(a.cure, 0) as cure,\n\
		COALESCE(a.evacs, 0) as evacs,\n\
		COALESCE(a.reported, 0) as reported,\n\
		COALESCE(a.purchase, 0) as purchase,\n\
		COALESCE(a.jumps, 0) as jumps,\n\
		COALESCE(a.total_points, 0) as total_points,\n\
		COALESCE(a.hours, 0) as hours,\n\
		COALESCE(a.minutes, 0) as minutes,\n\
		COALESCE(a.seconds, 0) as seconds,\n\
		COALESCE(p.admin, 0) as admin,\n\
		COALESCE(p.vip, 0) as vip,\n\
		COALESCE(p.vip_till, 0) as vip_till,\n\
		COALESCE(g.gang_id, -1) as gang_id,\n\
		COALESCE(g.rank, 0) as gang_rank,\n\
		COALESCE(g.warns, 0) as gang_warns\n\
		FROM `users` u\n\
		LEFT JOIN `achievements` a ON u.id = a.id\n\
		LEFT JOIN `privileges` p ON u.id = p.id\n\
		LEFT JOIN `gangs_users` g ON u.id = g.id\n\
		WHERE u.login = '%e'\
	"