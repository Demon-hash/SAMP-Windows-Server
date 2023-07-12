#if defined _config_pack_included
	#endinput
#endif
#define _config_pack_included

enum CONFIG_DATA {
	svCfgPreviewBot,
	svCfgMaxWeaponAmmo,
	svCfgCuringWeapon,
	svCfgMeatPickup,
	svCfgAmmoChance,
	svCfgAntidoteChance,
	svCfgExcludedMirrorPart,
	svCfgInfectionDrunkLevel,
	svCfgPickupProtection,
	Float:svCfgPreviewBotPos[4],
	Float:svCfgPreviewCameraPos[6],
	Float:svCfgVehicleDamage,
	Float:svCfgSpawnRange,
	Float:svCfgZombieFistsDamage,
	svCfgName[64],
	svCfgMode[64],
	svCfgDiscord[64],
	svCfgSite[64],
	svCfgLanguage[64],
	Float:svCfgInfectionDamage,
	svCfgAuthTries,
	svCfgMinZombiesToWin,
	svCfgAuthTimeout,
	svCfgCurrentOnline,
};