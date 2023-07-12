#if defined _pickups_pack_included
	#endinput
#endif
#define _pickups_pack_included

#define BULLETS_PICKUP 2061
#define MEDKIT_PICKUP 11738
#define MEAT_PICKUP 2804

#define STATIC_PICKUP_TYPE 1

enum PICKUP_DATA {
	pcdId,
	pcdType,
	pcdModel,
	pcdForPlayer,
	pcdFromPlayer,
	pcdProtectionTill,
	bool:pcdIsActive,
}