#if defined _maps_pack_included
	#endinput
#endif
#define _maps_pack_included

#define MAP_NONE_TIME -1

#define MAX_MAP_FILENAME 64
#define MAX_MAP_NAME 64
#define MAX_MAP_GATES 2
#define MAX_MAP_GATE_DATA 6

#define MAX_MAP_SPAWNS 3
#define MAX_MAP_SPAWNPOINT_DATA 4

enum MAP_DATA {
	mpFilename[MAX_MAP_FILENAME],
	mpPrevFilename[MAX_MAP_FILENAME],
	mpAuthor[MAX_PLAYER_NAME],
	mpGates[MAX_MAP_GATES],
	mpGatesObject[MAX_MAP_GATES],
	mpId,
	mpPoints,
	mpCount,
	mpWeather,
	mpInterior,
	mpEvacuatedHumans,
	mpTime,
	bool:mpSkipped,
	mpGang,
	mpTimeout,
	mpTimeoutBeforeStart,
	mpTimeoutBeforeEnd,
	mpTimeoutIgnoreTick,
	bool:mpTimeoutBeforeCrystal,
	bool:mpFirstBlood,
	bool:mpKillTheLast,
	mpWaterAllowed,
	mpFlag,
	mpFlagDate,
	mpGangPoints[MAX_GANGS],
	bool:mpIsStarted,
	bool:mpPaused,
	Float:mpGateSpeed,
	Float:mpCheckpointSize,
	Float:mpFlagCoords[MAX_MAP_GATE_DATA],
	Float:mpFlagTextCoords[MAX_MAP_SPAWNS],
	Float:mpCheckpointCoords[MAX_MAP_SPAWNPOINT_DATA - 1],
	Float:mpHumanSpawnX[MAX_MAP_SPAWNS],
	Float:mpHumanSpawnY[MAX_MAP_SPAWNS],
	Float:mpHumanSpawnZ[MAX_MAP_SPAWNS],
	Float:mpHumanSpawnA[MAX_MAP_SPAWNS],
	Float:mpZombieSpawnX[MAX_MAP_SPAWNS],
	Float:mpZombieSpawnY[MAX_MAP_SPAWNS],
	Float:mpZombieSpawnZ[MAX_MAP_SPAWNS],
	Float:mpZombieSpawnA[MAX_MAP_SPAWNS],
	Float:mpCameraCoords[MAX_MAP_SPAWNPOINT_DATA - 1],
	Float:mpCameraLookAt[MAX_MAP_SPAWNPOINT_DATA - 1],
	Float:mpGatesCoords[MAX_MAP_GATE_DATA * MAX_MAP_GATES],
	Float:mpGatesMoveCoords[MAX_MAP_GATE_DATA * MAX_MAP_GATES],
	Text3D:mpFlagText,
};

enum MAP_CONFIG_DATA {
	mpCfgTotal,
	mpCfgUpdate,
	mpCfgBalance,
	mpCfgEnd,
	mpCfgRestart,
	mpCfgGreatTime,
	mpCfgSpawnProtectionTime,
	mpCfgKillstreakFactor,
	mpCfgCapturePeriod,
	mpCfgHumanHeroWeapons[24],
	Float:mpCfgSpawnTextRange,
	Float:mpCfgHumanHeroPoints,
	Float:mpCfgZombieBossPoints,
	Float:mpCfgFirstBlood,
	Float:mpCfgKillLast,
	Float:mpCfgLastEvacuated,
	Float:mpCfgHumanHeroArmour,
	Float:mpCfgZombieBossArmour,
};