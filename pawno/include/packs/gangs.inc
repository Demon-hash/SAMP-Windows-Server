#if defined _gangs_pack_included
	#endinput
#endif
#define _gangs_pack_included

#define MAX_GANGS 5
#define MAX_GANG_TAG 7
#define MAX_GANG_NAME 32

enum GANG_DATA {
	gdColumnId,
	gdOwnerId,
	gdName[MAX_GANG_NAME],
	gdTag[MAX_GANG_TAG],
	gdLevel,
	gdQuestId,
	gdQuestProgression,
	gdPot,
};

enum GANGS_CONFIG_DATA {
	gdCfgCapacity,
	gdCfgFlagId,
	gdCfgRequired,
	gdCfgDefault,
	Float:gdCfgMultiply,
	Float:gdCfgArmourPerLevel,
	Float:gdCfgCrystalHealth,
	Float:gdCfgFlagDistance,
	Float:gdCfgPerCure,
	Float:gdCfgPerKill,
	Float:gdCfgPerEvac,
	Float:gdCfgPerAbility,
	Float:gdCfgPerAssist,
};