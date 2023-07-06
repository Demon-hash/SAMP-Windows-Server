#if defined _player_pack_included
	#endinput
#endif
#define _player_pack_included

#undef MAX_PLAYERS
#define MAX_PLAYERS 50

#define MAX_PLAYER_IP 16
#define MAX_PLAYER_PASSWORD 32

enum PLAYER_DATA {
	Float:pd_xp,
	pd_level,
	pd_vip,
	pd_admin,
};