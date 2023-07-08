#if defined _round_pack_included
	#endinput
#endif
#define _round_pack_included

#define MAX_ROUND_BOXES 6

enum ROUND_DATA {
	bool:rdIsEvacuated,
	bool:rdIsInfected,
	rdBox[MAX_ROUND_BOXES],
	Text3D:rdBoxText[MAX_ROUND_BOXES],
};