#if defined _classes_pack_included
	#endinput
#endif
#define _classes_pack_included

#define MAX_CLASS_NAME 32
#define MAX_CLASS_DESC 96

#define MAX_CLASSES 48
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
	clsCfgStomperEffectId,
	clsCfgStomperEffectTime,
	clsCfgEngineerBox,
	clsCfgEngineerSound,
	clsCfgSpitterWeapon,
	clsCfgSpitterWeaponAmmo,
	Float:clsCfgEngineerTextRange,
};

enum {
	ABILITY_NONE = 0,
	ABILITY_INFECT,
	ABILITY_FLESHER,
	ABILITY_REGENERATOR,
	ABILITY_SUPPORT,
	ABILITY_STEALER,
	ABILITY_BOOMER,
	ABILITY_JUMPER,
	ABILITY_STOMPER,
	ABILITY_KAMIKAZE,
	ABILITY_SPACEBREAKER,
	ABILITY_MIMICRY,
	ABILITY_FREEZER,
	ABILITY_RADIOACTIVE,
	ABILITY_FLASH,
	ABILITY_SPITTER,
	ABILITY_MUTATED,
	ABILITY_SPORE,
	ABILITY_WITCH,
	ABILITY_MIRROR,
	ABILITY_JUGGERNAUT,

	ABILITY_CURE,
	ABILITY_BUILD,
	ABILITY_TASER,
	ABILITY_LONG_JUMPS,
	ABILITY_CURE_FIELD,
	ABILITY_HOLY_FIELD,
	ABLITY_MAX,
};