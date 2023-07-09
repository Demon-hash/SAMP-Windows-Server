#if defined _weapons_pack_included
	#endinput
#endif
#define _weapons_pack_included

#define WEAPON_FISTS 0
#define MAX_WEAPONS 13

enum WEAPONS_DATA {
	wdId,
	wdCount,
	wdTime,
	wdAsDefault,
};

enum WEAPONS_CONFIG_DATA {
	wdCfgType,
	wdCfgChance,
	wdCfgDefault,
	wdCfgPick,
	wdCfgTime,
};