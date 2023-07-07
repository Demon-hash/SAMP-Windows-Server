#if defined _classes_pack_included
	#endinput
#endif
#define _classes_pack_included

#define MAX_CLASSES 50

#define MAX_CLASS_SKINS 3
#define MAX_CLASS_WEAPONS 9

enum CLASSES_DATA {
	cldId,
	cldTranslateId,
	cldTeam,
	cldHealth,
	cldArmour,
	cldLevel,
	cldAbility,
	cldCooldown,
	cldSkin[MAX_CLASS_SKINS],
	cldWeapons[MAX_CLASS_WEAPONS],
	cldAmmo[MAX_CLASS_WEAPONS],
	cldDisabled,
};