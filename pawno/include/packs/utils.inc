#if defined _utils_pack_included
	#endinput
#endif
#define _utils_pack_included

#define GetBySlot(%0,%1) (%0) >> (1 * (%1)) & 1
#define SetBySlot(%0,%1,%2) (%0) = ((%0) & (~0 ^ (1 << (1 * (%1))))) | ((%2) << (1 * (%1)))
#define KEY(%0) (((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))

stock GetPlayerSpeed(const playerid) {
    new Float:st[4];
    GetPlayerVelocity(playerid,st[0],st[1],st[2]);
    st[3] = floatsqroot(floatpower(floatabs(st[0]), 2.0) + floatpower(floatabs(st[1]), 2.0) + floatpower(floatabs(st[2]), 2.0)) * 150.0;
    return floatround(st[3]);
}

stock DestroyObjectEx(&objectid) {
	if(objectid != INVALID_OBJECT_ID) {
		DestroyObject(objectid);
	}
	
	objectid = INVALID_OBJECT_ID;
}

stock DeletePlayer3DTextLabelEx(playerid, &id) {
	if(id > -1) {
	    DeletePlayer3DTextLabel(playerid, PlayerText3D:id);
	}
	
	id = -1;
}

stock Delete3DTextLabelEx(&id) {
	if(id > -1) {
	    Delete3DTextLabel(Text3D:id);
	}
	
	id = -1;
}

stock DestroyActorEx(&id) {
	if(id > -1) {
	    DestroyActor(id);
	}
	
	id = -1;
}