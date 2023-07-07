#if defined _classes_pack_included
	#endinput
#endif
#define _classes_pack_included

#define MAX_CLASSES 20
#define MAX_CLASS_NAME 64
#define MAX_CLASS_DESC 64

enum CLASSES_DATA {
	cldId,
	cldName[MAX_CLASS_NAME],
	cldDesc[MAX_CLASS_DESC],
	cldRuName[MAX_CLASS_NAME],
	cldRuDesc[MAX_CLASS_DESC],
	cldTeam,
	cldHealth,
	cldArmour,
	cldLevel,
	cldAbility,
	cldCooldown,
	cldSkin,
	cldDisabled,
};