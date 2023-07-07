#if defined _player_pack_included
	#endinput
#endif
#define _player_pack_included

#undef MAX_PLAYERS
#define MAX_PLAYERS 50

enum PLAYER_DATA {
	pAccountId,
	pPoints,
	pLanguage,
};