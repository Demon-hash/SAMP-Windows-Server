#define MAX_VOTEKICK_REASON_LEN 64

enum VOTEKICK_DATA {
	bool:vkIsStarted,
	vkTimeout,
	vkBreaker,
	vkBy,	
	vkVoites,
	vkMaxVoites,
	vkVoted[MAX_PLAYERS],
	vkReason[MAX_VOTEKICK_REASON_LEN],
}