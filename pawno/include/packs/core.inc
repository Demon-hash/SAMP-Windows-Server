#if defined _core_pack_included
	#endinput
#endif
#define _core_pack_included

#include <a_samp>
#include <packs/colors>
#include <packs/player>
#include <packs/privileges>
#include <packs/achievements>
#include <packs/classes>
#include <packs/round>
#include <packs/teams>
#include <packs/gangs>
#include <packs/misc>
#include <packs/pickups>
#include <packs/weapons>
#include <packs/templates>
#include <packs/config>
#include <packs/queries>
#include <packs/dialogs>
#include <packs/language>
#include <packs/maps>
#include <packs/utils>
#include <packs/evacuation>
#include <packs/textures>
#include <packs/balance>
#include <packs/polygons>
#include <packs/messages>
#include <packs/lottery>
#include <packs/settings>
#include <packs/votekick>
#include <packs/duels>
#include <packs/payments>
#include <packs/weekly>
#include <packs/anticheat>

#include <dependencies/jit>
#include <dependencies/foreach>
#include <dependencies/sscanf2>
#include <dependencies/dc_cmd>
#include <dependencies/a_mysql>
#include <dependencies/date>
#include <dependencies/Pawn.RakNet>

#pragma warning disable 208
#pragma warning disable 239

#define SERVER_TIMESTAMP 3

#undef MAX_PLAYERS
#define MAX_PLAYERS 50

#undef MAX_VEHICLES
#define MAX_VEHICLES MAX_PLAYERS

#define MAX_ID_LENGTH 12
#define MAX_LOGS_LENGTH 15

#define GLOBAL_CHARSET "utf8"
#define LOCAL_CHARSET "cp1251"
#define SQL_HOST "db3.myarena.ru"
#define SQL_USER "u9764_taxa"
#define SQL_PASS "d@u87Ud!KA87Rj"
#define SQL_DB "u9764_taxa"
#define SQL_LOG_LEVEL NONE

#if !defined IsValidVehicle
	native IsValidVehicle(vehicleid);
#endif

#if !defined gpci
	native gpci(playerid, serial[], len);
#endif

#if !defined SHA256_PassHash
	native SHA256_PassHash(password[], salt[], ret_hash[], ret_hash_len);
#endif

#if !defined SendClientCheck
	native SendClientCheck(playerid, actionid, memaddr, memOffset, bytesCount);
#endif

#define custom%0(%1) forward%0(%1);public%0(%1)
#define INVALID_VALUE 65535

#if !defined IsNaN
    #define IsNaN(%0) ((%0) != (%0))
#endif

#define CLEAR_SIGN_DAYS 14
#define CLEAR_LOGIN_DAYS 14
#define CLEAR_JAILS_DAYS 30
#define CLEAR_MUTES_DAYS 30
#define CLEAR_VOTEKICK_DAYS 30
#define CLEAR_PAYS_DAYS 90
#define CLEAR_NAMES_DAYS 90

enum {
	DISCONNECT_TIMEOUT,
	DISCONNECT_QUIT,
	DISCONNECT_KICK,
	DISCONNECT_CUSTOM,
	DISCONNECT_MODE_END,
}

enum {
	VOTEKICK_LOGS,
    	WARN_LOGS,
    	MUTE_LOGS,
    	JAIL_LOGS,
	PAY_LOGS,
	NAME_LOGS,
	BAN_LOGS,
	MEMBERS_LOG,
}

enum {
	CAPTURED_MAP_EVAC,
	CAPTURED_MAP_CURE,
	CAPTURED_MAP_ABILITY,
	CAPTURED_MAP_KILL,
}