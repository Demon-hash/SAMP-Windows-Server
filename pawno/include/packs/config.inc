#if defined _config_pack_included
	#endinput
#endif
#define _config_pack_included

#define MAX_SERVER_CONFIG_NAME_LEN 64

enum CONFIG_DATA {
	svCfgPreviewBot,
	svCfgMaxWeaponAmmo,
	svCfgRifle,
	svCfgMeatPickup,
	svCfgAmmoChance,
	svCfgAntidoteChance,
	svCfgExcludedMirrorPart,
	svCfgInfectionDrunkLevel,
	svCfgPickupProtection,
	svCfgVotekick,
	Float:svCfgPreviewBotPos[4],
	Float:svCfgPreviewCameraPos[6],
	Float:svCfgVehicleDamage,
	Float:svCfgSpawnRange,
	Float:svCfgZombieFistsDamage,
	Float:svCfgCurseDamage,
	Float:svCfgTaxes,
	svCfgName[MAX_SERVER_CONFIG_NAME_LEN],
	svCfgMode[MAX_SERVER_CONFIG_NAME_LEN],
	svCfgDiscord[MAX_SERVER_CONFIG_NAME_LEN],
	svCfgSite[MAX_SERVER_CONFIG_NAME_LEN],
	svCfgLanguage[MAX_SERVER_CONFIG_NAME_LEN],
	Float:svCfgInfectionDamage,
	svCfgAuthTries,
	svCfgMinZombiesToWin,
	svCfgAuthTimeout,
	svCfgLastTipMessage,
	svCfgTipMessageCooldown,
	svCfgLastQuiz,
	svCfgQuizResetTime,
	svCfgLotteryResetTime,
	svCfgGangCreate,
	svCfgLastLottery,
	svCfgLotteryReset,
	svCfgQuizPoints,
	svCfgQuizCooldown,
	svCfgLotteryJackpot,
	svCfgLotteryJackpotPerPlayer,
	svCfgLastLotteryCooldown,
	svCfgQuizReset,
	svCfgChangeName,
};