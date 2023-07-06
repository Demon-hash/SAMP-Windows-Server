#if defined _pickups_pack_included
	#endinput
#endif
#define _pickups_pack_included

#define COLT45_PICKUP 346
#define SILINCED_PISTOL_PICKUP 347
#define DEAGLE_PICKUP 348
#define SHOTGUN_PICKUP 349
#define UZI_PICKUP 352
#define TEC9_PICKUP 372
#define MP5_PICKUP 353
#define AK47_PICKUP 355
#define M4_PICKUP 356
#define COUNTRY_RIFLE_PICKUP 357
#define SNIPER_RIFLE_PICKUP 358
#define BULLETS_PICKUP 2061
#define MEDKIT_PICKUP 11738
#define MEAT_PICKUP 2804

#define STATIC_PICKUP_TYPE 1

enum PICKUP_DATA {
	pcd_id,
	pcd_type,
	pcd_model,
	pcd_for_player,
	pcd_protection_till,
	bool:is_active,
}