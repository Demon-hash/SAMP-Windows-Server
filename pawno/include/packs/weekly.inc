#if defined _weekly_quests_pack_included
	#endinput
#endif
#define _weekly_quests_pack_included

#define WEEKLY_MAX_ACTIVITIES 8
#define WEEKLY_MAX_ACTIVITIES_LEN 64

enum {
	WEEKLY_HUMAN_BOSSES,
	WEEKLY_KILLSTREAKS,
	WEEKLY_KILL_PLAYERS,
	WEEKLY_BLOODRUSH,
	
	WEEKLY_ZOMBIE_BOSSES,
	WEEKLY_KILL_HUMANS,
	WEEKLY_KILL_ZOMBIES,
	WEEKLY_COLLECT_POINTS,
	
	WEEKLY_INFECT,
	WEEKLY_CURE,
	WEEKLY_ABILITIES,
	WEEKLY_COLLECT_MEATS,
	WEEKLY_EVACUATE,
	WEEKLY_JUMP,
	WEEKLY_EOF,
}

enum WEEKLY_HASHMAP {
	whpId[WEEKLY_EOF],
	whpCount[WEEKLY_EOF],
	whpType[WEEKLY_EOF],
}

enum WEEKLY_DATA {
	wqpdStanding,
	wqpdCoins,
	wqpdActivity[WEEKLY_MAX_ACTIVITIES],
	wqpdProgress[WEEKLY_MAX_ACTIVITIES],
}

enum WEEKLY_CFG_DATA {
	wqdPeriod,
	wqdNextUpdate,
	wqdMinStanding,
	wqdMedStanding,
	wqdMaxStanding,
	wqdStandingPerLevel,
	wqdAttachement[2],
	wqdNickname[2],
	wqdActivitiesDataId[WEEKLY_MAX_ACTIVITIES_LEN],
	wqdActivitiesDataCount[WEEKLY_MAX_ACTIVITIES_LEN],
}