#if defined _maps_pack_included
	#endinput
#endif
#define _maps_pack_included

#define MAP_NONE_TIME -1
#define MAP_TIME 300
#define MAP_RESTART_TIME 10
#define MAP_UPDATE_TIME 5
#define MAP_END_TIME 60
#define MAP_BALANCE_TIME 10

#define MAX_MAP_FILENAME 64
#define MAX_MAP_NAME 64
#define MAX_MAP_GATES 2
#define MAX_MAP_GATE_DATA 6

#define MAX_MAP_SPAWNS 3
#define MAX_MAP_SPAWNPOINT_DATA 4

enum MAP_DATA {
	mpFilename[MAX_MAP_FILENAME],
	mpPrevFilename[MAX_MAP_FILENAME],
	mpName[MAX_MAP_NAME],
	mpAuthor[MAX_PLAYER_NAME],
	mpGates[MAX_MAP_GATES],
	mpTeamCount[2],
	mpId,
	mpCount,
	mpWeather,
	mpInterior,
	mpTime,
	mpGang,
	mpTimeout,
	mpTimeoutBeforeStart,
	mpTimeoutBeforeEnd,
	mpTimeoutIgnoreTick,
	mpWaterAllowed,
	bool:mpIsStarted,
	bool:mpPaused,
	Float:mpGateSpeed,
	Float:mpCheckpointSize,
	Float:mpCheckpointCoords[MAX_MAP_SPAWNPOINT_DATA - 1],
	Float:mpHumanSpawnX[MAX_MAP_SPAWNS],
	Float:mpHumanSpawnY[MAX_MAP_SPAWNS],
	Float:mpHumanSpawnZ[MAX_MAP_SPAWNS],
	Float:mpHumanSpawnA[MAX_MAP_SPAWNS],
	Float:mpZombieSpawnX[MAX_MAP_SPAWNS],
	Float:mpZombieSpawnY[MAX_MAP_SPAWNS],
	Float:mpZombieSpawnZ[MAX_MAP_SPAWNS],
	Float:mpZombieSpawnA[MAX_MAP_SPAWNS],
	Float:mpGangNPCSpawn[MAX_MAP_SPAWNPOINT_DATA],
	Float:mpCameraCoords[MAX_MAP_SPAWNPOINT_DATA - 1],
	Float:mpCameraLookAt[MAX_MAP_SPAWNPOINT_DATA - 1],
	Float:mpGatesCoords[MAX_MAP_GATE_DATA * MAX_MAP_GATES],
	Float:mpGatesMoveCoords[MAX_MAP_GATE_DATA * MAX_MAP_GATES],
};