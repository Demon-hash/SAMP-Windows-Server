#if defined _core_pack_included
	#endinput
#endif
#define _core_pack_included

#include <a_samp>
#include <dependencies/foreach>
#include <dependencies/sscanf2>
#include <dependencies/dc_cmd>
#include <dependencies/a_mysql>
#include <dependencies/indirection>

#undef MAX_PLAYERS
#define MAX_PLAYERS 50

#undef MAX_VEHICLES
#define MAX_VEHICLES 50

#define SQL_HOST "db3.myarena.ru"
#define SQL_USER "u9764_taxa"
#define SQL_PASS "d@u87Ud!KA87Rj"
#define SQL_DB "u9764_taxa"

#if !defined IsValidVehicle
	native IsValidVehicle(vehicleid);
#endif

#define custom%0(%1) forward%0(%1);public%0(%1)