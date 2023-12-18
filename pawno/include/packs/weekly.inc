#if defined _weekly_quests_pack_included
	#endinput
#endif
#define _weekly_quests_pack_included

#define WEEKLY_MAX_ACTIVITIES 8
#define WEEKLY_MAX_ACTIVITIES_LEN 64
#define WEEKLY_MAX_REWARDS_LEN 24
#define WEEKLY_MAX_TYPES_LEN 24
#define WEEKLY_MAX_COUNT_LEN 96
#define WEEKLY_MAX_CLOTHES_LIST 10

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

enum WEEKLY_CLOTHES {
	wdcsKit,
	wdcsCoins,
	wdcsEmblems,
	wdcsText[64],
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
	wqdKit[4],
	wqdActivities[WEEKLY_MAX_ACTIVITIES_LEN],
	wqdTypes[WEEKLY_MAX_TYPES_LEN],
	wqdCount[WEEKLY_MAX_COUNT_LEN],
	wqdRewards[WEEKLY_MAX_REWARDS_LEN],
}