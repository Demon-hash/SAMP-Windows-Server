#if defined _classes_pack_included
	#endinput
#endif
#define _classes_pack_included

#define MAX_CLASS_NAME 24
#define MAX_CLASS_DESC 96

#define MAX_CLASSES 48
#define MAX_CLASSDATA_STR_LEN 24

enum CLASSES_DATA {
	cldId,
	cldTeam,
	Float:cldHealth,
	Float:cldArmour,
	cldImmunity[MAX_CLASSDATA_STR_LEN],
	cldAbility[MAX_CLASSDATA_STR_LEN],
	cldWeapons[MAX_CLASSDATA_STR_LEN],
	Float:cldPoints,
	cldCooldown,
	cldAnimation,
	cldAnimationTime,
	Float:cldDistance,
	cldSkin,
	cldDisabled,
};

enum CLASSES_SELECTION_DATA {
	csdId,
	csdName[MAX_CLASS_NAME],
};