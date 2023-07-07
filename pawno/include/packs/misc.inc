#if defined _misc_pack_included
	#endinput
#endif
#define _misc_pack_included

#define MAX_PLAYER_IP 16
#define MAX_PLAYER_PASSWORD 32

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
};