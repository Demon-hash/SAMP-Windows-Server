#if defined _config_pack_included
	#endinput
#endif
#define _config_pack_included

enum CONFIG_DATA {
	svCfgPreviewBot,
	svCfgInfectionDrunkLevel,
	svCfgPickupProtection,
	Float:svCfgPreviewBotPos[4],
	Float:svCfgPreviewCameraPos[6],
	svCfgName[64],
	svCfgMode[64],
	svCfgDiscord[64],
	svCfgSite[64],
	svCfgLanguage[64],
	Float:svCfgInfectionDamage,
	svCfgAuthTries,
	svCfgAuthTimeout,
	svCfgCurrentOnline,
};