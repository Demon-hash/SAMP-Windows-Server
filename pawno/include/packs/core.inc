#if defined _core_pack_included
	#endinput
#endif
#define _core_pack_included

#include <a_samp>
#include <packs/colors>
#include <packs/player>
#include <packs/privileges>
#include <packs/achievements>
#include <packs/misc>
#include <packs/round>
#include <packs/teams>
#include <packs/gangs>
#include <packs/pickups>
#include <packs/weapons>
#include <packs/classes>
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

#include <dependencies/foreach>
#include <dependencies/sscanf2>
#include <dependencies/dc_cmd>
#include <dependencies/a_mysql>
#include <dependencies/indirection>
#include <dependencies/date>

#pragma warning disable 208
#pragma warning disable 239

#define SERVER_TIMESTAMP 3

#undef MAX_PLAYERS
#define MAX_PLAYERS 50

#undef MAX_VEHICLES
#define MAX_VEHICLES 50

#define MAX_ID_LENGTH 12

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

#define custom%0(%1) forward%0(%1);public%0(%1)