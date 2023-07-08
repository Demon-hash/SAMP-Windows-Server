#if defined _filterscript_pack_included
	#endinput
#endif
#define _filterscript_pack_included
#include <a_samp>

new bool:ScriptObject[MAX_OBJECTS];
new bool:ScriptVehicles[MAX_VEHICLES];

stock CreateTemporarlyObject(modelid, Float:x, Float:y, Float:z, Float:rx = 0.00000, Float:ry = 0.00000, Float: rz = 0.00000, Float:distance = 500.0) {
	new o = CreateObject(modelid, x, y, z, rx, ry, rz, distance);
	if(o >= 0 && o < MAX_OBJECTS)  {
		ScriptObject[o] = true;
		return o;
	}
	return 0;
}

stock CreateTemporarlyVehicle(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:angle, color1, color2) {
	new v = AddStaticVehicle(modelid, spawn_x, spawn_y, spawn_z, angle, color1, color2);
	if(v >= 0 && v < MAX_VEHICLES) {
		ScriptVehicles[v] = true;
		return v;
	}
	return 0;
}

stock ClearMemory() {
	new i;
	for( i = 0; i < sizeof(ScriptObject); i++ ) {
		if(ScriptObject[i]) {	
			DestroyObject(i);	
		}	
	}

	for( i = 0; i < sizeof(ScriptVehicles); i++ ) {
		if(ScriptVehicles[i]) {	
			DestroyVehicle(i);	
		}	
	}
}
