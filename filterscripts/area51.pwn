#include <packs/filterscript>

public OnFilterScriptInit() {
    CreateTemporarlyObject(4874, 57.83850, 1928.11060, 20.56030,   0.00000, 0.00000, 0.00000);
	return 1;
}

public OnFilterScriptExit() {
	ClearMemory();
	return 1;
}
