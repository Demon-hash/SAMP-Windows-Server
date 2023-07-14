#if defined _round_pack_included
	#endinput
#endif
#define _round_pack_included

#define MAX_ROUND_BOXES 9

enum ROUND_DATA {
	bool:rdIsEvacuated,
	bool:rdIsHumanHero,
	bool:rdIsZombieBoss,
	bool:rdIsInfected,
	bool:rdIsAdvanceInfected,
	bool:rdIsInRadioactiveField,
	bool:rdIsCursed,
	bool:rdIsLegsBroken,
	rdBox[MAX_ROUND_BOXES],
	Text3D:rdBoxText[MAX_ROUND_BOXES],
	rdBoxCount,
	rdCheckForOOM,
	rdFrozeTime,
	rdAbilityTimes,
};

enum ROUND_SESSION_DATA {
	rsdMapId,
	rsdTeam,
	Float:rsdSurvival,
	Float:rsdKilling,
	Float:rsdCare,
	Float:rsdMobility,
	Float:rsdSkillfulness,
	Float:rsdBrutality,
	Float:rsdDeaths,
	Float:rdAdditionalPoints,
};

enum ROUND_DATA_CONFIG {
	rdCfgSurvivalPer,
	rdCfgCap,
	rdCfgBrutalityWeapon,
	Float:rdCfgEvac,
	Float:rdCfgSurvival,
	Float:rdCfgKilling,
	Float:rdCfgCare,
	Float:rdCfgMobility,
	Float:rdCfgSkillfulness,
	Float:rdCfgBrutality,
	Float:rdCfgDeaths,
};

enum {
	SESSION_SURVIVAL_POINTS,
	SESSION_KILL_POINTS,
	SESSION_CARE_POINTS,
	SESSION_RUN_POINTS,
	SESSION_ABILITY_POINTS,
	SESSION_HIT_POINTS,
	SESSION_UNDEAD_POINTS,
}