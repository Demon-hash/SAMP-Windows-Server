#include <a_samp>

enum {
	DIALOG_ATTACH_INDEX_SELECTION = 2023,
	DIALOG_ATTACH_MODEL_SELECTION,
	DIALOG_ATTACH_EDITREPLACE,
	DIALOG_ATTACH_BONE_SELECTION,
}

enum AttachmentEnum {
    attachmodel,
    attachname[36]
}

// SetPlayerAttachedObject(playerid, );
// SetPlayerAttachedObject(playerid, 1, );
// SetPlayerAttachedObject(playerid, );
// SetPlayerAttachedObject(playerid, );
// SetPlayerAttachedObject(playerid, 4, 19101, 2, 0.155, 0.000, 0.000, 0.000, 0.000, 0.000, 1.000, 1.000, 1.000);

new AttachmentObjects[][AttachmentEnum] = {
    {19101, "beat"}
};

new AttachmentBones[][24] = {
	{"Spine"},
	{"Head"},
	{"Left upper arm"},
	{"Right upper arm"},
	{"Left hand"},
	{"Right hand"},
	{"Left thigh"},
	{"Right thigh"},
	{"Left foot"},
	{"Right foot"},
	{"Right calf"},
	{"Left calf"},
	{"Left forearm"},
	{"Right forearm"},
	{"Left clavicle"},
	{"Right clavicle"},
	{"Neck"},
	{"Jaw"}
};

main() {
	new year, month, day;
    getdate(year, month, day);
    if(month == 12) { } // 19054
    if(month == 11) { } // 19320
	if(month >= 4 && month <= 5) { } // 19343
    
    printf("%d", month);
}

public OnGameModeInit() {
	return 1;
}

public OnPlayerCommandText(playerid, cmdtext[]) {
	if (strcmp("/c", cmdtext, true, 2) == 0) {
	    for(new i = 0; i < 9; i++ ) {
	    	RemovePlayerAttachedObject(playerid, i);
    	}
    	return 1;
	}
	
	if (strcmp("/att", cmdtext, true, 4) == 0) {
        new string[128];
    	
	    for( new x; x < 10; x++) {
	    	if(IsPlayerAttachedObjectSlotUsed(playerid, x)) format(string, sizeof(string), "%s%d (Used)\n", string, x);
	     	else format(string, sizeof(string), "%s%d\n", string, x);
	    }
    
    	ShowPlayerDialog(playerid, DIALOG_ATTACH_INDEX_SELECTION, DIALOG_STYLE_LIST, "{FF0000}Attachment Modification - Index Selection", string, "Select", "Cancel");
		return 1;
	}
	return 0;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]) {
	switch(dialogid) {
    	case DIALOG_ATTACH_INDEX_SELECTION:
        {
            if(response)
            {
                if(IsPlayerAttachedObjectSlotUsed(playerid, listitem))
                {
                    ShowPlayerDialog(playerid, DIALOG_ATTACH_EDITREPLACE, DIALOG_STYLE_MSGBOX, \
                    "{FF0000}Attachment Modification", "Do you wish to edit the attachment in that slot, or delete it?", "Edit", "Delete");
                }
                else
                {
                    new string[4000+1], index = 0;
                    for(new x = index; x< sizeof(AttachmentObjects); x++) format(string, sizeof(string), "%s%s\n", string, AttachmentObjects[x][attachname]);
					ShowPlayerDialog(playerid, DIALOG_ATTACH_MODEL_SELECTION, DIALOG_STYLE_LIST,"{FF0000}Attachment Modification - Model Selection", string, "Select", "Cancel");

				}
                SetPVarInt(playerid, "AttachmentIndexSel", listitem);
            }
            return 1;
        }

        case DIALOG_ATTACH_EDITREPLACE:
        {
            if(response) EditAttachedObject(playerid, GetPVarInt(playerid, "AttachmentIndexSel"));
            else {
				RemovePlayerAttachedObject(playerid, GetPVarInt(playerid, "AttachmentIndexSel"));
			}
			DeletePVar(playerid, "AttachmentIndexSel");
            return 1;
        }

        case DIALOG_ATTACH_MODEL_SELECTION:
        {
            if(response)
            {
                if(GetPVarInt(playerid, "AttachmentUsed") == 1) EditAttachedObject(playerid, listitem);
                else
                {
                    new index = 0;
					SetPVarInt(playerid, "AttachmentModelSel", AttachmentObjects[listitem+index][attachmodel]);
					
					new string[256+1];
                    for(new x;x<sizeof(AttachmentBones);x++)
                    {
                        format(string, sizeof(string), "%s%s\n", string, AttachmentBones[x]);
                    }
                    ShowPlayerDialog(playerid, DIALOG_ATTACH_BONE_SELECTION, DIALOG_STYLE_LIST, \
                    "{FF0000}Attachment Modification - Bone Selection", string, "Select", "Cancel");
                }
            }
            else DeletePVar(playerid, "AttachmentIndexSel");
            return 1;
        }

        case DIALOG_ATTACH_BONE_SELECTION:
        {
            if(response)
            {
                SetPlayerAttachedObject(playerid, GetPVarInt(playerid, "AttachmentIndexSel"), GetPVarInt(playerid, "AttachmentModelSel"), listitem + 1);
				EditAttachedObject(playerid, GetPVarInt(playerid, "AttachmentIndexSel"));
                SendClientMessage(playerid, 0xFFFFFFFF, "Hint: Use {FFFF00}~k~~PED_SPRINT~{FFFFFF} to look around.");
            }
            DeletePVar(playerid, "AttachmentIndexSel");
            DeletePVar(playerid, "AttachmentModelSel");
            return 1;
        }
	}
	return 1;
}

public OnPlayerEditAttachedObject(playerid, response, index, modelid, boneid, Float:fOffsetX, Float:fOffsetY, Float:fOffsetZ, Float:fRotX, Float:fRotY, Float:fRotZ, Float:fScaleX, Float:fScaleY, Float:fScaleZ)
{
    if (response) {
        printf("SetPlayerAttachedObject(playerid, %d, %d, %d, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f);", index, modelid, boneid, fOffsetX, fOffsetY, fOffsetZ, fRotX, fRotY, fRotZ, fScaleX, fScaleY, fScaleZ);
    
    }
    return 1;
}
