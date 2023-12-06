#if defined _misc_pack_included
	#endinput
#endif
#define _misc_pack_included

#define MAX_PLAYER_IP 16
#define MAX_PLAYER_PASSWORD 32

#define GPCI_LENGTH 41
#define MAX_MAP_SPAWN 3 

#define MAX_WEAPONS_SKILL 10

enum MISC_DATA {
	mdPlayerName[MAX_PLAYER_NAME],
	mdCurrentClass[3],
	mdNextClass[3],
	mdMimicry[3],
	mdPlayerTeam,
    	mdSpawnProtection,
    	mdIgnoreAnticheatFor,
	mdLastIssuedDamage,
	mdLastIssuedReason,
	bool:mdIsLogged,
    	Float:mdHealth,
    	Float:mdArmour,
	Float:mdMimicryStats[2],
	mdGang,
	mdGangRank,
	mdGangWarns,
	mdPassword[MAX_PLAYER_PASSWORD],
	mdIp[MAX_PLAYER_IP],
	mdSerial[GPCI_LENGTH],
	mdDialogId,
	mdWeeklyStanding,
	mdSelectionTeam,
	mdKillstreak,
	mdBlindTimeout,
	mdNextPage,
	mdHumanSelectionName[MAX_CLASS_NAME],
	mdZombieSelectionName[MAX_CLASS_NAME],
	mdHumanNextSelectionName[MAX_CLASS_NAME],
	mdZombieNextSelectionName[MAX_CLASS_NAME],
	mdKickForAuthTimeout,
	mdKickForAuthTries,
	PlayerText3D:mdSpawnPoints[3],
	PlayerText3D:mdFlagText,
	mdGameplayWarns,
	mdSign[16],
};