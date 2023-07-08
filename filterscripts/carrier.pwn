#include <packs/filterscript>

public OnFilterScriptInit() {
	CreateTemporarlyObject(3799, -1420.01465, 498.78821, 1.92190,   0.00000, 0.00000, 0.00000);
	CreateTemporarlyObject(3799, -1420.01465, 495.86371, 1.93500,   0.00000, 0.00000, 0.00000);
	CreateTemporarlyObject(3799, -1420.01465, 492.94379, 1.93500,   0.00000, 0.00000, 0.00000);
	CreateTemporarlyObject(3799, -1420.01465, 490.02731, 1.93500,   0.00000, 0.00000, 0.00000);
	CreateTemporarlyObject(3799, -1420.01465, 498.78821, 4.15070,   0.00000, 0.00000, 0.00000);
	CreateTemporarlyObject(3799, -1420.01465, 495.86371, 4.17070,   0.00000, 0.00000, 0.00000);
	CreateTemporarlyObject(3799, -1420.01465, 492.94379, 4.17070,   0.00000, 0.00000, 0.00000);
	CreateTemporarlyObject(3799, -1420.01465, 490.02731, 4.17070,   0.00000, 0.00000, 0.00000);
	CreateTemporarlyObject(3799, -1417.11255, 495.86371, 1.93500,   0.00000, 0.00000, 0.00000);
	CreateTemporarlyObject(8210, -1412.39600, 514.97791, 9.12320,   0.00000, 0.00000, 0.00000);
	CreateTemporarlyObject(8210, -1300.49707, 514.97791, 9.12320,   0.00000, 0.00000, 0.00000);
	CreateTemporarlyObject(8210, -1324.44836, 487.39615, 9.34320,   0.00000, 0.00000, 180.00000);
	CreateTemporarlyObject(19373, -1377.27271, 492.87991, 7.34030,   0.00000, 0.00000, 0.00000);
	CreateTemporarlyObject(2944, -1367.20801, 514.40112, 11.75740,   0.00000, 0.00000, 90.00000);
	
	CreateTemporarlyVehicle(520, -1390.9899, 508.6136, 18.9672, 270.3647, 7, -1);
	CreateTemporarlyVehicle(497, -1312.3595, 507.7193, 19.0026, 270.0000, 7, -1);
	return 1;
}

public OnFilterScriptExit() {
    ClearMemory();
	return 1;
}
