#if defined _classes_pack_included
	#endinput
#endif
#define _classes_pack_included

#define MAX_CLASS_NAME 32
#define MAX_CLASS_DESC 96

#define MAX_CLASSES 55
#define MAX_CLASSDATA_STR_LEN 24

#define MAX_CLASS_ID_LEN 2

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
	cldAbilityTime,
	cldAbilityCount,
	Float:cldDistance,
	cldSkin,
	cldDisabled,
};

enum CLASSES_SELECTION_DATA {
	csdId,
	csdName[MAX_CLASS_NAME],
};

enum CLASSES_CONFIG_DATA {
	clsCfgWhoppingWhen,
	clsCfgFlasherEffectId,
	clsCfgFlasherEffectTime,
	clsCfgFlasherExplosionType,
	Float:clsCfgAirRange,
	Float:clsCfgRadioactiveDamage,
	Float:clsCfgRegenHealth,
	Float:clsCfgSupportHealth,
	Float:clsCfgStomp[3],
	Float:clsCfgHighJump[3],
	Float:clsCfgLongJump[3],
	Float:clsCfgStomperEffectPos[3],
	Float:clsCfgFlasherExplosionRange,
	Float:clsCfgSpaceDamage,
	clsCfgStomperEffectId,
	clsCfgStomperEffectTime,
	clsCfgEngineerBox,
	clsCfgEngineerSound,
	Float:clsCfgEngineerTextRange,
	clsCfgSpitterWeapon,
	clsCfgStealAmmoFactor,
};

enum {
	ABILITY_NONE = 0,
	ABILITY_INFECT, // 1
	ABILITY_DRUNK, // 2
	ABILITY_BLIND, // 3
	ABILITY_FLESHER, // 4
	ABILITY_REGENERATOR, // 5
	ABILITY_SUPPORT, // 6
	ABILITY_STEALER, // 7
	ABILITY_LEG_BREAK, // 8
	ABILITY_ARMOUR_REMOVE, // 9
	ABILITY_BOOMER, // 10
	ABILITY_JUMPER, // 11
	ABILITY_STOMPER, // 12
	ABILITY_KAMIKAZE, // 13
	ABILITY_SPACEBREAKER, // 14
	ABILITY_MIMICRY, // 15
	ABILITY_FREEZER, // 16
	ABILITY_RADIOACTIVE, // 17
	ABILITY_FLASH, // 18
	ABILITY_SPITTER, // 19
	ABILITY_MUTATED, // 20
	ABILITY_SPORE, // 21
	ABILITY_WITCH, // 22
	ABILITY_MIRROR, // 23
	ABILITY_REMOVE_WEAPONS, // 24

	ABILITY_CURE, // 25
	ABILITY_BUILD, // 26
	ABILITY_LONG_JUMPS, // 27
	ABILITY_CURE_FIELD, // 28
	ABILITY_HOLY_FIELD, // 29
	ABILITY_POISON, // 30
	ABLITY_MAX,
};