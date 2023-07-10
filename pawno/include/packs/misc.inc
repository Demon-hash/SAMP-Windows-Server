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
	mdPlayerTeam,
    	mdSpawnProtection,
    	mdIgnoreAnticheatFor,
	bool:mdIsLogged,
    	Float:mdHealth,
    	Float:mdArmour,
	mdGang,
	mdGangRank,
	mdGangWarns,
	mdPassword[MAX_PLAYER_PASSWORD],
	mdIp[MAX_PLAYER_IP],
	mdSerial[GPCI_LENGTH],
	mdWeaponSkill[MAX_WEAPONS_SKILL],
	mdDialogId,
	mdKickForAuthTimeout,
	mdKickForAuthTries,
	PlayerText3D:mdSpawnPoints[3],
	PlayerText3D:mdFlagText,
};