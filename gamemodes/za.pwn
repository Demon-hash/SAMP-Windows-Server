#include <packs/core>
#include <packs/developer>

static const sqlTemplates[][] = {
    REGISTRATION_TEMPLATE, USERS_TEMPLATE, PRIVILEGES_TEMPLATE,
	GANGS_TEMPLATE, GANGS_USERS_TEMPLATE, GANGS_REQUESTS_TEMPLATE,
	GANGS_WARNS_TEMPLATE, GANGS_BLACKLISTED_TEMPLATE,
	GANGS_CONFIG_TEMPLATE, MAPS_TEMPLATE, WEAPONS_CONFIG_TEMPLATE,
	LANGUAGES_TEMPLATE, CLASSES_TEMPLATE, BANLOG_TEMPLATE,
	NAMELOG_TEMPLATE, LOGINLOG_TEMPLATE, PAYLOG_TEMPLATE,
	AUCTIONLOG_TEMPLATE, WARNSLOG_TEMPLATE, MUTESLOG_TEMPLATE,
	MUTESLOG_TEMPLATE, JAILSLOG_TEMPLATE, GANGPAYLOG_TEMPLATE,
	AUCTION_TEMPLATE, AUCTION_CASHBACK_TEMPLATE,
	ACHIEVEMENTS_TEMPLATE, CONFIG_TEMPLATE, STATS_TEMPLATE,
	ANTICHEAT_TEMPLATE, ACHIEVEMENTS_CONFIG_TEMPLATE, ROUND_SESSION_TEMPLATE,
	ROUND_CONFIG_TEMPLATE, EVAC_CONFIG_TEMPLATE, MAP_CONFIG_TEMPLATE,
	WEAPONS_TEMPLATE
};

static const sqlPredifinedValues[][] = {
	PREDIFINED_CIVILIAN, PREDIFINED_NURSE,PREDIFINED_ENGINEER,
	PREDIFINED_JUMPER, PREDIFINED_FAKE_ZOMBIE, PREDIFINED_RUNNER,
	PREDIFINED_DOCTOR, PREDIFINED_STANDARD_ZOMBIE,
	PREDIFINED_ROGUE_ZOMBIE, PREDIFINED_FAST_ZOMBIE,
	PREDIFINED_STOMPER_ZOMBIE, PREDIFINED_RADIOACTIVE_ZOMBIE,
	PREDIFINED_SLOW_ZOMBIE, PREDIFINED_BOOMER_ZOMBIE,
	PREDIFINED_RUNNER_ZOMBIE, PREDIFINED_SEEKER_ZOMBIE,
	PREDIFINED_SILINCED, PREDIFINED_COLT45, PREDIFINED_DEAGLE,
	PREDIFINED_UZI, PREDIFINED_TEC9, PREDIFINED_MP5, PREDIFINED_AK47,
    PREDIFINED_M4, PREDIFINED_RIFLE, PREDIFINED_SNIPER,
    PREDIFINED_FLAMETHOWER, PREDIFINED_SPAS, PREDIFINED_RPG,
	PREDIFINED_HEATSEEKER, PREDIFINED_C4, PREDIFINED_CONFIG,
	PREDIFINED_GANGS_CONFIG, PREDIFINED_ANTICHEAT, PREDIFINED_MAP_VILLAGE,
	PREDIFINED_ROUND_CONFIG, PREDIFINED_EVAC_CONFIG, PREDIFINED_MAP_CONFIG
};

static const sqlPredifinedLocalization[][] = {
    PRD_LD_DG_LOGIN_TITLE, PRD_LD_DG_LOGIN_DEFAULT, PRD_LD_DG_LOGIN_TRIES,
    PRD_LD_DG_LOGIN_SPACES, PRD_LD_DG_REG_TITLE, PRD_LD_DG_REG_DEFAULT,
    PRD_LD_DG_REG_SPACES, PRD_LD_BTN_REG, PRD_LD_BTN_LOGIN, PRD_LD_BTN_QUIT
};

static Achievements[MAX_PLAYERS][ACHIEVEMENTS_DATA];
static AchievementsConfig[1];

static Round[MAX_PLAYERS][ROUND_DATA];
static RoundSession[MAX_PLAYERS][ROUND_SESSION_DATA];
static RoundConfig[ROUND_DATA_CONFIG];

static Gangs[MAX_GANGS][GANG_DATA];
static GangsConfig[GANGS_CONFIG_DATA];

static Map[MAP_DATA];
static MapConfig[MAP_CONFIG_DATA];

static Misc[MAX_PLAYERS][MISC_DATA];
static Player[MAX_PLAYERS][PLAYER_DATA];
static Privileges[MAX_PLAYERS][PRIVILEGES_DATA];

static Weapons[MAX_PLAYERS][MAX_WEAPONS][WEAPONS_DATA];
static WeaponsConfig[MAX_WEAPONS][WEAPONS_CONFIG_DATA];

static Classes[MAX_CLASSES][CLASSES_DATA];
static Pickups[MAX_PICKUPS][PICKUP_DATA];

static AnticheatConfig[1];
static EvacuationConfig[EVACUATION_CONFIG_DATA];
static ServerConfig[CONFIG_DATA];

static Localization[MAX_PLAYERS][LOCALIZATION_DATA][LOCALIZATION_LINE_SIZE];

static
	MySQL:Database,
	updateTimerId,
	Text:TimeLeftTexture,
	Text:InfectedTexture,
	Text:UntillEvacRectangleTexture,
	Text:UntilEvacTextTexture[MAX_PLAYERS],
	Text:AliveInfoTexture[MAX_PLAYERS],
	Text:PointsTexture[MAX_PLAYERS];

/*
	MAIN
	- Weapons
	- Classes
	- Abilities
	- Shop
	- SaveUserData
	- Commands
	- Anticheat
	- Zombies don't have chainsaw anymore, use your fists to deal damage (5 HP)
*/

/*
 - General Changes To Gameplay:
 - Gangs:
    - Capacity is 10 members only,
    - Create a gang required 25,000 points
 	- Quests (5):
		* Reach a total of 100,000 points (Reward: 10 Armour)
		* Reach a total of 200,000 points (Reward: 20 Armour)
		* Reach a total of 300,000 points (Reward: 30 Armour)
		* Reach a total of 400,000 points (Reward: 40 Armour)
		* Reach a total of 500,000 points (Reward: 50 Armour)
	 - How to capture:
    	* At the end of the round, gang players will receive weapons and must inflict the maximum possible damage on the spawned bot
		* The map will be captured by the gang that deals the most damage
 - Maps:
    * Captured map gives more points for killing (+2)
    * The gang holding the map receives additional experience points for actions:
    	* Infect / Ability / Cure (0.1%)
    	* Evac (0.5%)
*/

// ShowPlayerDialog
// SendClientMessage
// format
// CreatePlayer3DTextLabel
// OnPlayerGiveDamageActor

#define GANG_CONTROL_TEXT "{FFFFFF}%s\n\
		 {FFF000}Controlled by {FFFFFF}%s\n\
		 {FFF000}Captured at {FFFFFF}%02d:%02d {FFF000}on {FFFFFF}%02d/%02d/%d\n\
		 {FFF000}This gang dealt the most damage to capture the map\n\
		 {FFF000}The gang members get extra points for the following actions:\n\n\
		 {FFFFFF}+%.0f{FFF000} point(s) in gang pot for evacuating\n\
		 {FFFFFF}+%.0f{FFF000} point(s) in gang pot for curing humans\n\
		 {FFFFFF}+%.0f{FFF000} point(s) in gang pot for active ability using\n\
		 {FFFFFF}+%.0f{FFF000} point(s) in gang pot for killing players\n\
		 {FFFFFF}+%.2f{FFF000} point(s) in gang pot for assist\
		 "
		 
#define CRYSTAL_STONE_TEXT "CRYSTAL STONE\n{FFFFFF}>> %.0f <<{FFF000}\nDestroy this crystal to capture the map, only gang members can deal damage\nDamage dealt depends on rank"

main() {
}

public OnGameModeInit() {
	InitializePickups();
	InitializeClassesData();
	InitializeWeaponsData();
	InitializePlayersScreenTextures();
	InitializeDefaultValues();
	
	SetGameModeText("Zombies");
	ShowPlayerMarkers(PLAYER_MARKERS_MODE_GLOBAL);
    ShowNameTags(1);
	SetTeamCount(MAX_PLAYER_TEAMS);
	DisableInteriorEnterExits();
	EnableStuntBonusForAll(0);
	AllowInteriorWeapons(1);
	
	Database = mysql_connect(SQL_HOST, SQL_USER, SQL_PASS, SQL_DB);
	mysql_set_charset(SQL_CHARSET);
	
	new i;
	for(i = 0; i < sizeof(sqlTemplates); i++) {
		mysql_tquery(Database, sqlTemplates[i]);
	}
	
	for(i = 0; i < sizeof(sqlPredifinedValues); i++ ) {
		mysql_tquery(Database, sqlPredifinedValues[i]);
	}
	
	for(i = 0; i < sizeof(sqlPredifinedLocalization); i++ ) {
	    mysql_tquery(Database, sqlPredifinedLocalization[i]);
	}
	
	mysql_tquery(Database, LOAD_SERVER_CFG_QUERY, "LoadServerConfiguration");
	mysql_tquery(Database, LOAD_GANGS_CFG_QUERY, "LoadGangsConfiguration");
	mysql_tquery(Database, LOAD_ROUND_CFG_QUERY, "LoadRoundConfiguration");
	mysql_tquery(Database, LOAD_EVAC_CFG_QUERY, "LoadEvacConfiguration");
	mysql_tquery(Database, LOAD_MAP_CFG_QUERY, "LoadMapConfiguration");
	mysql_tquery(Database, LOAD_WEAPONS_CFG_QUERY, "LoadWeaponsConfiguration");
	mysql_tquery(Database, LOAD_MAPS_COUNT_QUERY, "LoadMapsCount");
 	mysql_log(SQL_LOG_LEVEL);
 	
 	new year, mounth, day, hours, minutes, seconds;
	TimestampToDate(gettime(), year, mounth, day, hours, minutes, seconds, SERVER_TIMESTAMP);
	printf("Started at %02d:%02d:%02d on %02d/%02d/%d... (%d)", hours, minutes, seconds, day, mounth, year, gettime());
	printf("Started with status of %d", mysql_errno(Database));
	
	updateTimerId = SetTimer("Update", 1000, true);
	return 1;
}

public OnGameModeExit() {
    mysql_close(Database);
	KillTimer(updateTimerId);
	UnloadFilterScript(Map[mpFilename]);
	DestroyPlayersScreenTextures();
	return 1;
}

public OnPlayerConnect(playerid) {
    ClearAllPlayerData(playerid);
    CheckForAccount(playerid);
    
    new formated[64];
    foreach(Player, i) {
        format(formated, sizeof(formated), "*** %s (ID: %d) has joined the server", Misc[playerid][mdPlayerName], playerid);
        SendClientMessage(i, 0xC0C0C0FF, formated);
    }
    return 1;
}

public OnPlayerDisconnect(playerid, reason) {
    ResetMapValuesOnDeath(playerid);
    ResetValuesOnDisconnect(playerid);
    
	static const reasons[] = { "Timeout", "Leave", "Kick" };
	
    new formated[64];
    foreach(Player, i) {
        format(formated, sizeof(formated), "*** %s has left the server [%s]", Misc[playerid][mdPlayerName], reasons[reason]);
        SendClientMessage(i, 0xC0C0C0FF, formated);
    }
	return 1;
}

public OnPlayerRequestClass(playerid, classid) {
    SetPlayerVirtualWorld(playerid, 1000 + playerid);

    SetSpawnInfo(
		playerid, TEAM_ZOMBIE, ServerConfig[svCfgPreviewBot],
		Map[mpZombieSpawnX][0], Map[mpZombieSpawnY][0], Map[mpZombieSpawnZ][0],
		0.0, 0, 0, 0, 0, 0, 0
	);

    SetPlayerPos(playerid, ServerConfig[svCfgPreviewBotPos][0],
	ServerConfig[svCfgPreviewBotPos][1], ServerConfig[svCfgPreviewBotPos][2]);
	SetPlayerFacingAngle(playerid, ServerConfig[svCfgPreviewBotPos][3]);

	SetPlayerCameraPos(playerid, ServerConfig[svCfgPreviewCameraPos][0],
	ServerConfig[svCfgPreviewCameraPos][1], ServerConfig[svCfgPreviewCameraPos][2]);
	SetPlayerCameraLookAt(playerid, ServerConfig[svCfgPreviewCameraPos][3],
	ServerConfig[svCfgPreviewCameraPos][4], ServerConfig[svCfgPreviewCameraPos][5]);

	SetPlayerSkin(playerid, ServerConfig[svCfgPreviewBot]);
	return 1;
}

public OnPlayerRequestSpawn(playerid) {
    if(!Misc[playerid][mdIsLogged]) {
	    return 0;
	}
	return 1;
}

public OnPlayerSpawn(playerid) {
	if(!Misc[playerid][mdIsLogged]) {
	    return 1;
	}

    CheckToStartMap();
    
    SetPlayerVirtualWorld(playerid, 0);
    SetPlayerInterior(playerid, Map[mpInterior]);
    SetPlayerWeather(playerid, Map[mpWeather]);
	SetPlayerTime(playerid, Map[mpTime], 0);
	
	SetByCurrentClass(playerid);
	return 1;
}

public OnPlayerUpdate(playerid) {
	if(GetPlayerSpeed(playerid) >= 10 && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT) {
	    Achievements[playerid][achRan] += 0.00001;

		if(IsAbleToGivePointsInCategory(playerid, SESSION_RUN_POINTS)) {
			RoundSession[playerid][rsdMobility] += RoundConfig[rdCfgMobility];
		}
	}
	SetPlayerScore(playerid, Achievements[playerid][achRank]);
	return 1;
}

public OnPlayerDeath(playerid, killerid, reason) {
	if(!IsPlayerConnected(playerid)) {
	    return 0;
	}

    reason = clamp(reason, WEAPON_FISTS, WEAPON_COLLISION);
	SendDeathMessage(killerid, playerid, reason);
	
	if(IsPlayerConnected(killerid)) {
	    if(IsAbleToGivePointsInCategory(killerid, SESSION_KILL_POINTS)) {
	        RoundSession[killerid][rsdKilling] += RoundConfig[rdCfgKilling];
	    }
	}
	
	if(IsAbleToGivePointsInCategory(playerid, SESSION_UNDEAD_POINTS)) {
	    RoundSession[playerid][rsdDeaths] += RoundConfig[rdCfgDeaths];
	}

 	ClearPlayerRoundData(playerid);
	CreateDropOnDeath(playerid, killerid);
	ResetMapValuesOnDeath(playerid);
	return 1;
}

public OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float: fX, Float: fY, Float: fZ) {
    if(!(weaponid >= WEAPON_COLT45 && weaponid <= WEAPON_MINIGUN)) {
	    return 0;
	}
	
	new weapname[32];
	GetWeaponName(weaponid, weapname, sizeof(weapname));
	SetPVarInt(playerid, weapname, GetPVarInt(playerid, weapname) - 1);
	if(GetPVarInt(playerid, weapname) <= -5 && strlen(weapname) >= 2 && GetPlayerWeapon(playerid) > 0) {
		return 0;
	}
	
	switch(hittype) {
	    case BULLET_HIT_TYPE_VEHICLE: {
            if(hitid <= -1 || !IsValidVehicle(hitid)) {
				return 0;
			}
			
			new Float:hp;
			GetVehicleHealth(hitid, hp);
			SetVehicleHealth(hitid, hp - 50.0);
	    }
	    case BULLET_HIT_TYPE_PLAYER: {
            if(!IsPlayerConnected(hitid)) {
				return 0;
			}
			
            if(gettime() < Misc[hitid][mdSpawnProtection]) {
            	SetPlayerChatBubble(hitid, "MISS", BUBBLE_COLOR, 20.0, 1000);
				return 0;
            }
	    }
	    case BULLET_HIT_TYPE_OBJECT: {
	        if(hitid == Map[mpCrystal]) {
	            Map[mpCrystalHealth] -= float(max(1, Achievements[playerid][achRank]));
	            
	        	new text[256];
				format(text, sizeof(text), CRYSTAL_STONE_TEXT, Map[mpCrystalHealth]);
				Update3DTextLabelText(Map[mpFlagText], 0xFFF000FF, text);
	        }
	    }
	}
	
	return 1;
}

public OnPlayerTakeDamage(playerid, issuerid, Float: amount, weaponid, bodypart) {
	if(IsAbleToGivePointsInCategory(issuerid, SESSION_HIT_POINTS) && weaponid == 0) {
        RoundSession[playerid][rsdBrutality] += RoundConfig[rdCfgBrutality];
	}

    ShowDamageTaken(playerid, amount);
	return 1;
}

public OnPlayerEnterCheckpoint(playerid) {
	if(GetPlayerTeamEx(playerid) != TEAM_HUMAN || Round[playerid][rdIsEvacuated]) {
	    return 1;
	}
	
 	if(IsAbleToGivePointsInCategory(playerid, SESSION_SURVIVAL_POINTS)) {
  		RoundSession[playerid][rsdSurvival] += RoundConfig[rdCfgEvac];
  	}

	PlayerPlaySound(playerid, EvacuationConfig[ecdCfgSound], 0.0, 0.0, 0.0);
	SetPlayerPos(playerid, EvacuationConfig[ecdCfgPosition][0], EvacuationConfig[ecdCfgPosition][1], EvacuationConfig[ecdCfgPosition][2]);
	SetPlayerFacingAngle(playerid, EvacuationConfig[ecdCfgPosition][3]);
	SetCameraBehindPlayer(playerid);
	SetPlayerInterior(playerid, EvacuationConfig[ecdCfgInterior]);
	
	DisablePlayerCheckpoint(playerid);
	SetPlayerColor(playerid,COLOR_EVACUATED);
	CurePlayer(playerid);
	Round[playerid][rdIsEvacuated] = true;
	
	++Map[mpEvacuatedHumans];
	
	new formated[64];
	foreach(Player, i) {
 		format(formated, sizeof(formated), ">> %s has made to the evacuation point!", Misc[playerid][mdPlayerName]);
 		SendClientMessage(i, 0xFFF000FF, formated);

		if(Map[mpEvacuatedHumans] == Map[mpTeamCount][1]) {
            SendClientMessage(i, 0xFFF000FF, ">> ALL SURVIVORS EVACUATED!");
 		}
 	}
	
	if(Map[mpEvacuatedHumans] == Map[mpTeamCount][1] && Map[mpIsStarted]) {
	   Map[mpTimeoutBeforeEnd] = MapConfig[mpCfgUpdate];
	}
	
	return 1;
}

public OnPlayerText(playerid, text[]) {
	if(!Misc[playerid][mdIsLogged]) {
	    return 0;
	}

	new i_pos;
	while(text[i_pos]) {
		if(text[i_pos] == '%') text[i_pos] = '#';
		i_pos++;
	}
	
	if(!EmptyMessage(text)) {
	    new message[256];
	    format(message, sizeof(message), "{%06x}%s{FFFFFF}(%d): %s", GetPlayerColor(playerid) >>> 8, Misc[playerid][mdPlayerName], playerid, text);
		SendClientMessageToAll(GetPlayerColor(playerid), message);
	}
	
	return 0;
}

public OnPlayerCommandText(playerid, cmdtext[]) {
	return 1;
}

public OnPlayerCommandReceived(playerid, cmdtext[]) {
	if(!Misc[playerid][mdIsLogged]) {
	    return 0;
	}
	
	return 1;
}

public OnPlayerCommandPerformed(playerid, cmdtext[], success) {
	if(success != 1) {
		return 0;
	}
	return 1;
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    if(KEY(KEY_WALK)) {
        if(IsAbleToGivePointsInCategory(playerid, SESSION_ABILITY_POINTS)) {
            RoundSession[playerid][rsdSkillfulness] += RoundConfig[rdCfgSkillfulness];
        }
	}
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]) {
	/*if(Misc[playerid][mdDialogId] != dialogid) {
	    return 0;
	}*/
	
	switch(dialogid) {
	    case DIALOG_REGISTER: {
	        if(!response) {
	            Kick(playerid);
	            return 1;
	        }
	        
	        if(strlen(inputtext) <= 0 || strlen(inputtext) >= MAX_PLAYER_PASSWORD) {
	            ShowRegisterDialog(playerid, DIALOG_ERROR);
	            return 1;
	        }
	        
	        static const accountQuery[] = REG_ACCOUNT_QUERY;
			new formatedAccountQuery[sizeof(accountQuery) + MAX_PLAYER_NAME + MAX_PLAYER_PASSWORD];
			
	        mysql_format(Database, formatedAccountQuery, sizeof(formatedAccountQuery), accountQuery, Misc[playerid][mdPlayerName], inputtext);
	        mysql_tquery(Database, formatedAccountQuery, "GetUserAccountId", "i", playerid);
	        return 1;
     	}
	    case DIALOG_LOGIN: {
	        if(!response) {
	            Kick(playerid);
	            return 1;
	        }
	        
	        if(strlen(inputtext) <= 0 || strlen(inputtext) >= MAX_PLAYER_PASSWORD) {
	            ShowLoginDialog(playerid, DIALOG_ERROR_WHITESPACES);
	            return 1;
	        }
	        
	        if(!strcmp(inputtext, Misc[playerid][mdPassword])) {
	            AfterAuthorization(playerid);
			} else {
			    Misc[playerid][mdKickForAuthTries]--;
			    
			    if(Misc[playerid][mdKickForAuthTries] <= 0) {
			        Kick(playerid);
			        return 1;
			    }
			    
			    ShowLoginDialog(playerid, DIALOG_ERROR);
			    return 1;
			}
			
	        return 1;
	    }
	}
	
	return 1;
}

public OnPlayerPickUpPickup(playerid, pickupid) {
    if(IsAbleToPickup(playerid, pickupid)) {
    	ProcedPickupAction(playerid, pickupid);
     	DestroyPickupEx(pickupid);
	} else if(IsValidPickupEx(pickupid)) {
	    new tip[64];
	    format(tip, sizeof(tip), ">> Protection {FFFFFF}%d{FF0000} seconds left!", max(0, Pickups[pickupid][pcd_protection_till] - gettime()));
 		SendClientMessage(playerid, 0xFF0000FF, tip);
	}
	return 1;
}

public OnQueryError(errorid, const error[], const callback[], const query[], MySQL:handle) {
	printf("SQL: %s(%d) > (%s) > %s", error, errorid, callback, query);
	return 1;
}

custom Update() {
	static Float:hp, Float:armour;
	
	static currentHour, currentMinute, currentSecond, formated[48];
	gettime(currentHour, currentMinute, currentSecond);

	foreach(Player, playerid) {
	    if(Misc[playerid][mdKickForAuthTimeout] > 0) {
	        Misc[playerid][mdKickForAuthTimeout]--;
	        if(Misc[playerid][mdKickForAuthTimeout] == 0) {
	            KickForAuthTimeout(playerid);
	            Misc[playerid][mdKickForAuthTimeout] = -1;
				continue;
	        }
	    }
	    
	    CheckAndNormalizeACValues(playerid, hp, armour);
	    
	    if(Misc[playerid][mdIsLogged]) {
	    	if(Round[playerid][rdIsInfected]) {
	        	SetPlayerColor(playerid, COLOR_INFECTED);
	        	TextDrawShowForPlayer(playerid, InfectedTexture);
	        	SetPlayerHealthAC(playerid, GetPlayerHealthEx(playerid) - ServerConfig[svCfgInfectionDamage]);
	        	SetPlayerDrunkLevel(playerid, ServerConfig[svCfgInfectionDrunkLevel]);
    		}
    		
    		format(formated, sizeof(formated),"%.0f", Player[playerid][pPoints]);
    		TextDrawSetString(PointsTexture[playerid], formated);
    		
    		format(formated, sizeof(formated), "~w~humans: %d~n~~r~zombies: %d", Map[mpTeamCount][1], Map[mpTeamCount][0]);
            TextDrawSetString(AliveInfoTexture[playerid], formated);
            
            if(!Map[mpPaused] && IsAbleToGivePointsInCategory(playerid, SESSION_SURVIVAL_POINTS) && (Map[mpTimeout] % RoundConfig[rdCfgSurvivalPer]) == 0) {
                RoundSession[playerid][rsdSurvival] += RoundConfig[rdCfgSurvival];
            }
	    }
	}
	
	if((currentSecond % MapConfig[mpCfgUpdate]) == 0) {
		OnMapUpdate();
	}
}

custom LoadMapsCount() {
	if(cache_num_rows()) {
        cache_get_value_name_int(0, "maps", Map[mpCount]);
        printf("Loaded %d maps in total", Map[mpCount]);
        return 1;
    }
    
	printf("Loading maps failed");
	return 0;
}

custom LoadMap() {
    if(cache_num_rows() > 0) {
        static buff[256];
		static year, mounth, day, hours, minutes, seconds;
        
        strmid(Map[mpAuthor], "", 0, MAX_PLAYER_NAME);
        
	    cache_get_value_name_int(0, "weather", Map[mpWeather]);
	    cache_get_value_name_int(0, "interior", Map[mpInterior]);
	    cache_get_value_name_int(0, "time", Map[mpTime]);
	    cache_get_value_name_int(0, "gang", Map[mpGang]);
	    cache_get_value_name_int(0, "water", Map[mpWaterAllowed]);
	    cache_get_value_name_int(0, "npc_skin", Map[mpGangNPCSkin]);
	    cache_get_value_name_int(0, "flag_date", Map[mpFlagDate]);
    	
    	cache_get_value_name(0, "login", Map[mpAuthor]);
        cache_get_value_name(0, "name", Map[mpName]);
        cache_get_value_name(0, "filename", Map[mpFilename]);
        
        cache_get_value_name_float(0, "gates_speed", Map[mpGateSpeed]);
    	cache_get_value_name_float(0, "checkpoint_size", Map[mpCheckpointSize]);
        
    	cache_get_value_name(0, "gates_ids", buff);
    	sscanf(buff, "p<,>ii", Map[mpGates][0], Map[mpGates][1]);
    	
    	cache_get_value_name(0, "npc_coords", buff);
     	sscanf(buff, "p<,>ffff",
		 	Map[mpGangNPCSpawn][0], Map[mpGangNPCSpawn][1],
     		Map[mpGangNPCSpawn][2], Map[mpGangNPCSpawn][3]
 		);
 		
 		cache_get_value_name(0, "flag_coords", buff);
     	sscanf(buff, "p<,>ffffff",
		 	Map[mpFlagCoords][0], Map[mpFlagCoords][1],
     		Map[mpFlagCoords][2], Map[mpFlagCoords][3],
     		Map[mpFlagCoords][4], Map[mpFlagCoords][5]
 		);
 		
 		cache_get_value_name(0, "flag_coords_text", buff);
     	sscanf(buff, "p<,>fff",
		 	Map[mpFlagTextCoords][0], Map[mpFlagTextCoords][1],
     		Map[mpFlagTextCoords][2]
 		);
 		
 		cache_get_value_name(0, "npc_coords", buff);
     	sscanf(buff, "p<,>ffff",
		 	Map[mpGangNPCSpawn][0], Map[mpGangNPCSpawn][1],
     		Map[mpGangNPCSpawn][2], Map[mpGangNPCSpawn][3]
 		);
    	
	    cache_get_value_name(0, "humans_coords", buff);
     	sscanf(buff, "p<,>ffffffffffff",
		 	Map[mpHumanSpawnX][0], Map[mpHumanSpawnY][0],
			Map[mpHumanSpawnZ][0], Map[mpHumanSpawnA][0],
		 	Map[mpHumanSpawnX][1], Map[mpHumanSpawnY][1],
		 	Map[mpHumanSpawnZ][1], Map[mpHumanSpawnA][1],
		 	Map[mpHumanSpawnX][2], Map[mpHumanSpawnY][2],
		 	Map[mpHumanSpawnZ][2], Map[mpHumanSpawnA][2]
		);
		
		cache_get_value_name(0, "zombies_coords", buff);
     	sscanf(buff, "p<,>ffffffffffff",
		 	Map[mpZombieSpawnX][0], Map[mpZombieSpawnY][0],
	 		Map[mpZombieSpawnZ][0], Map[mpZombieSpawnA][0],
		 	Map[mpZombieSpawnX][1], Map[mpZombieSpawnY][1],
	 		Map[mpZombieSpawnZ][1], Map[mpZombieSpawnA][1],
		 	Map[mpZombieSpawnX][2], Map[mpZombieSpawnY][2],
	 		Map[mpZombieSpawnZ][2], Map[mpZombieSpawnA][2]
		);
		
		cache_get_value_name(0, "npc_coords", buff);
     	sscanf(buff, "p<,>ffff",
		 	Map[mpGangNPCSpawn][0], Map[mpGangNPCSpawn][1],
	 		Map[mpGangNPCSpawn][2], Map[mpGangNPCSpawn][3]
	 	);
	 	
	 	cache_get_value_name(0, "checkpoint_coords", buff);
	 	sscanf(buff, "p<,>fff",
		 	Map[mpCheckpointCoords][0],
	 	    Map[mpCheckpointCoords][1],
		 	Map[mpCheckpointCoords][2]
	 	);
		 
	 	cache_get_value_name(0, "camera_coords", buff);
 		sscanf(buff, "p<,>ffffff",
		 	Map[mpCameraCoords][0], Map[mpCameraCoords][1], Map[mpCameraCoords][2],
		 	Map[mpCameraLookAt][0], Map[mpCameraLookAt][1], Map[mpCameraLookAt][2]
	 	);

		cache_get_value_name(0, "gates_coords", buff);
 		sscanf(buff, "p<,>ffffffffffff",
		 	Map[mpGatesCoords][0], Map[mpGatesCoords][1], Map[mpGatesCoords][2],
		 	Map[mpGatesCoords][3], Map[mpGatesCoords][4], Map[mpGatesCoords][5],
		 	Map[mpGatesCoords][6], Map[mpGatesCoords][7], Map[mpGatesCoords][8],
		 	Map[mpGatesCoords][9], Map[mpGatesCoords][10], Map[mpGatesCoords][11]
	 	);
	 	
	 	cache_get_value_name(0, "gates_move_coords", buff);
 		sscanf(buff, "p<,>ffffffffffff",
		 	Map[mpGatesMoveCoords][0], Map[mpGatesMoveCoords][1], Map[mpGatesMoveCoords][2],
		 	Map[mpGatesMoveCoords][3], Map[mpGatesMoveCoords][4], Map[mpGatesMoveCoords][5],
		 	Map[mpGatesMoveCoords][6], Map[mpGatesMoveCoords][7], Map[mpGatesMoveCoords][8],
		 	Map[mpGatesMoveCoords][9], Map[mpGatesMoveCoords][10], Map[mpGatesMoveCoords][11]
	 	);
    
    	strmid(Map[mpPrevFilename], Map[mpFilename], 0, MAX_MAP_FILENAME);
    	
    	SetMapId();
    	StartMap();
    	SetMapName();
    	
    	LoadFilterScript(Map[mpFilename]);
		
		DestroyObjectEx(Map[mpCrystal]);
		DestroyObjectEx(Map[mpFlag]);
		Delete3DTextLabelEx(Map[mpFlagText]);
		
		if(Map[mpGang]) {
            TimestampToDate(Map[mpFlagDate], year, mounth, day, hours, minutes, seconds, SERVER_TIMESTAMP);
			Map[mpFlag] = CreateObject(GangsConfig[gdCfgFlagId],
			   	Map[mpFlagCoords][0], Map[mpFlagCoords][1],
	     		Map[mpFlagCoords][2], Map[mpFlagCoords][3],
	     		Map[mpFlagCoords][4], Map[mpFlagCoords][5], 50.0
			);

			new text[768];
			format(text, sizeof(text), GANG_CONTROL_TEXT,
		  		Map[mpName],
				Gangs[Map[mpGang]][gdName],
				hours, minutes,
				day, mounth, year,
			 	GangsConfig[gdCfgPerEvac],
				GangsConfig[gdCfgPerCure],
				GangsConfig[gdCfgPerAbility],
				GangsConfig[gdCfgPerKill],
				GangsConfig[gdCfgPerAssist]
			);
			
			Map[mpFlagText] = Create3DTextLabel(text, 0xFFF000FF, Map[mpFlagTextCoords][0], Map[mpFlagTextCoords][1], Map[mpFlagTextCoords][2], GangsConfig[gdCfgFlagDistance], 0, 0);
		} else {
		    Map[mpCrystal] = CreateObject(18876,
				Map[mpGangNPCSpawn][0], Map[mpGangNPCSpawn][1],
				Map[mpGangNPCSpawn][2], 0.0, 0.0, Map[mpGangNPCSpawn][3]
			);
			
			new text[256];
			format(text, sizeof(text), CRYSTAL_STONE_TEXT, Map[mpCrystalHealth]);
			Map[mpFlagText] = Create3DTextLabel(text, 0xFFF000FF, Map[mpGangNPCSpawn][0], Map[mpGangNPCSpawn][1], Map[mpGangNPCSpawn][2], GangsConfig[gdCfgFlagDistance], 0, 0);
		}
	 }
}

custom StartMap() {
	/*if(!Map[mpIsStarted]) {
	    return 0;
	}*/
	
	static j;
	static author[64] = "";
	static controlled[96] = "";
	static formated[256];

	UnloadFilterScript(Map[mpPrevFilename]);
	
	for( j = 0; j < MAX_MAP_GATES; j++ ) {
	    DestroyObjectEx(Map[mpGates][j]);
	}
	
	foreach(Player, i) {
	    ClearPlayerRoundData(i);
    	DisablePlayerCheckpoint(i);
    	
    	if(IsPlayerInAnyVehicle(i)) {
    		RemovePlayerFromVehicle(i);
    	}
    	
    	if(GetPlayerState(i) == PLAYER_STATE_SPECTATING) {
    	    TogglePlayerSpectating(i, 0);
		}
		
		if(strlen(Map[mpAuthor])) {
    		format(author, sizeof(author), "(by %s)", Map[mpName]);
 		}

 		if(Map[mpGang]) {
 	    	format(controlled, sizeof(controlled), "(captured by %s)", Gangs[Map[mpGang]][gdName]);
 		}
    	
    	format(formated, sizeof(formated), ">> Entering The Map #%d (%s) %s %s", Map[mpId], Map[mpName], author, controlled);
	    SendClientMessage(i, 0xE48800FF, formated);
    	
    	if(Map[mpInterior] <= 0) {
			SendClientMessage(i, 0xFFF000FF, ">> Creating objects...");
		}
	}
	
	SetTeams();
    InitializePickups();
	
    Map[mpIsStarted] = true;
    Map[mpPaused] = false;
    
    Map[mpTimeoutIgnoreTick] = 0;
    Map[mpEvacuatedHumans] = 0;
    Map[mpTimeout] = MapConfig[mpCfgTotal];
    Map[mpTimeoutBeforeEnd] = -MapConfig[mpCfgUpdate];
    Map[mpTimeoutBeforeStart] = -MapConfig[mpCfgUpdate];
    Map[mpCrystalHealth] = GangsConfig[gdCfgBotHealth];
	return 1;
}

custom OnMapUpdate() {
	if(Map[mpPaused]) {
	    return 0;
	}
	
	if(Map[mpTimeoutIgnoreTick] > 0) {
	    Map[mpTimeoutIgnoreTick]--;
	    return 0;
	}
	
	if(Map[mpTimeoutBeforeStart] >= MapConfig[mpCfgUpdate]) {
	    Map[mpTimeoutBeforeStart] -= MapConfig[mpCfgUpdate];

	    if(Map[mpTimeoutBeforeStart] == 0) {
	        LoadNewMap();
	    }
	}
	
	if(ServerConfig[svCfgCurrentOnline] >= 2 && Map[mpTeamCount][1] <= 0 && Map[mpIsStarted]) {
	    foreach(Player, i) {
			SendClientMessage(i, 0xf21822FF, ">> The world ceased to exist, all humans died");
			SendClientMessage(i, 0xf21822FF, ">> Zombies have won");
 		}
 		
	    Map[mpTimeoutBeforeEnd] = MapConfig[mpCfgUpdate];
	}
	
	if(Map[mpTimeoutBeforeEnd] >= MapConfig[mpCfgUpdate]) {
	    Map[mpTimeoutBeforeEnd] -= MapConfig[mpCfgUpdate];
	    
	    if(Map[mpTimeoutBeforeEnd] == 0) {
	        EndMap();
	    }
	}
	
	if(Map[mpTimeout] >= MapConfig[mpCfgUpdate]) {
	    Map[mpTimeout] -= MapConfig[mpCfgUpdate];
	    
	    static tm[4];
		format(tm,sizeof(tm), "%d", Map[mpTimeout]);
		TextDrawSetString(TimeLeftTexture, tm);
	    
        if(Map[mpTimeout] == 0) {
			TextDrawSetString(TimeLeftTexture, "...");

			if(Map[mpGates][0]) {
				MoveObject(
					Map[mpGates][0],
					Map[mpGatesMoveCoords][0], Map[mpGatesMoveCoords][1], Map[mpGatesMoveCoords][2],
					Map[mpGateSpeed],
					Map[mpGatesMoveCoords][3], Map[mpGatesMoveCoords][4], Map[mpGatesMoveCoords][5]
				);
			}
			
			if(Map[mpGates][1]) {
				MoveObject(
					Map[mpGates][1],
					Map[mpGatesMoveCoords][6], Map[mpGatesMoveCoords][7], Map[mpGatesMoveCoords][8],
					Map[mpGateSpeed],
					Map[mpGatesMoveCoords][9], Map[mpGatesMoveCoords][10], Map[mpGatesMoveCoords][11]
				);
			}

			foreach(Player, i) {
		    	SendClientMessage(i, 0xf21822FF, ">> An evacuation has arrived for humans!");
				SendClientMessage(i, 0xf21822FF, ">> Humans get to the checkpoint within a minute!");
				ShowCheckpoint(i);
			}
			
			Map[mpTimeoutIgnoreTick] = 1;
			Map[mpTimeoutBeforeEnd] = MapConfig[mpCfgEnd];
 		}
	}
	
	return 1;
}

custom EndMap() {
    foreach(Player, i) {
        if(!Misc[i][mdIsLogged]) {
            continue;
        }
        
        if(!Round[i][rdIsEvacuated]) {
            SetPlayerCameraPos(i, Map[mpCameraCoords][0], Map[mpCameraCoords][1], Map[mpCameraCoords][2]);
   			SetPlayerCameraLookAt(i, Map[mpCameraLookAt][0], Map[mpCameraLookAt][1], Map[mpCameraLookAt][2]);
        }
    	
		SendClientMessage(i, 0xFFFFFFFF, ">> Beginning new a round...");
		GameTextForPlayer(i, "~r~ROUND OVER~n~~w~STARTING NEW ROUND...", 5000, 5);
		
		GivePointsForRound(i);
	}
	
	Map[mpTimeoutIgnoreTick] = 1;
	Map[mpTimeoutBeforeStart] = MapConfig[mpCfgRestart];
	Map[mpIsStarted] = false;
}

custom LoadLocalization(const playerid, const type) {
    static const query[] = LOAD_LOCALIZATION_QUERY;
	static const locale[][] = { ENGLISH_LOCALE, RUSSIAN_LOCALE };
    
	new formated[sizeof(query) + LOCALIZATION_SIZE], index = Player[playerid][pLanguage];
    mysql_format(Database, formated, sizeof(formated), query, locale[index]);
	mysql_tquery(Database, formated, "InitializeLocation", "ii", playerid, type);
}

custom CheckForAccount(const playerid) {
	static const query[] = CHECK_USER_QUERY;
	new formated[sizeof(query) + MAX_PLAYER_NAME];
	mysql_format(Database, formated, sizeof(formated), query, Misc[playerid][mdPlayerName]);
	mysql_tquery(Database, formated, "LoginOrRegister", "i", playerid);
}

custom GetUserCollectedWeapons(const playerid) {
	if(cache_num_rows() > 0) {
		new i, len = clamp(cache_num_rows(), 0, MAX_WEAPONS);
		for( i = 0; i < len; i++ ) {
			cache_get_value_name_int(i, "weapon_id", Weapons[playerid][i][wdId]);
		    cache_get_value_name_int(i, "time", Weapons[playerid][i][wdTime]);
		    cache_get_value_name_int(i, "amount", Weapons[playerid][i][wdCount]);
		    cache_get_value_name_int(i, "set_as_default", Weapons[playerid][i][wdAsDefault]);
		}
		
		for( i = 0; i < MAX_WEAPONS; i++ ) {
	        if(Weapons[playerid][i][wdAsDefault] && gettime() < Weapons[playerid][i][wdTime]) {
	            new index = GetWeaponFromConfigById(Weapons[playerid][i][wdId]);
	            new amount = (index > -1) ? WeaponsConfig[index][wdCfgDefault] : 1;
				GivePlayerWeaponAC(playerid, Weapons[playerid][i][wdId], amount);
	        }
    	}
	}
}

custom GetUserAccountId(const playerid) {
    Player[playerid][pAccountId] = cache_insert_id();

	if(Player[playerid][pAccountId] == -1) {
        Kick(playerid);
        return 1;
    }
    
    static const accountInformationQuery[] = REG_ACCOUNT_INFORMATION_QUERY;
	new formatedAccountInformationQuery[sizeof(accountInformationQuery) + MAX_ID_LENGTH + GPCI_LENGTH + MAX_PLAYER_IP];
    
    mysql_format(Database, formatedAccountInformationQuery, sizeof(formatedAccountInformationQuery), accountInformationQuery, gettime(), Misc[playerid][mdIp], Misc[playerid][mdSerial]);
    mysql_tquery(Database, formatedAccountInformationQuery);

    mysql_tquery(Database, REG_PRIVILEGES_QUERY);
    mysql_tquery(Database, REG_ACHIEVEMENTS_QUERY);
    mysql_tquery(Database, REG_GANG_ACCCOUNT_QUERY);
    
    AfterAuthorization(playerid);
    return 1;
}

custom KickForAuthTimeout(const playerid) {
    Kick(playerid);
}

custom LoadServerConfiguration() {
    if(cache_num_rows() > 0) {
        new buff[256];
        cache_get_value_name_int(0, "preview_bot", ServerConfig[svCfgPreviewBot]);
        cache_get_value_name_int(0, "preview_bot", ServerConfig[svCfgPreviewBot]);
        cache_get_value_name_int(0, "max_auth_timeout", ServerConfig[svCfgAuthTimeout]);
        cache_get_value_name_int(0, "max_auth_tries", ServerConfig[svCfgAuthTries]);
        cache_get_value_name_int(0, "infection_drunk", ServerConfig[svCfgInfectionDrunkLevel]);
        cache_get_value_name_int(0, "pickup_protection", ServerConfig[svCfgPickupProtection]);

        cache_get_value_name_float(0, "infection_damage", ServerConfig[svCfgInfectionDamage]);

        cache_get_value_name(0, "preview_bot_coords", buff);
		sscanf(buff, "p<,>ffff", ServerConfig[svCfgPreviewBotPos][0],
		ServerConfig[svCfgPreviewBotPos][1], ServerConfig[svCfgPreviewBotPos][2],
		ServerConfig[svCfgPreviewBotPos][3]);

		cache_get_value_name(0, "preview_camera_coords", buff);
		sscanf(buff, "p<,>ffffff", ServerConfig[svCfgPreviewCameraPos][0],
		ServerConfig[svCfgPreviewCameraPos][1], ServerConfig[svCfgPreviewCameraPos][2],
		ServerConfig[svCfgPreviewCameraPos][3], ServerConfig[svCfgPreviewCameraPos][4],
		ServerConfig[svCfgPreviewCameraPos][5]);

        cache_get_value_name(0, "name", ServerConfig[svCfgName]);
        cache_get_value_name(0, "mode", ServerConfig[svCfgMode]);
        cache_get_value_name(0, "discord", ServerConfig[svCfgDiscord]);
        cache_get_value_name(0, "site", ServerConfig[svCfgSite]);
        cache_get_value_name(0, "language", ServerConfig[svCfgLanguage]);

        format(buff, sizeof(buff), "weburl %s", ServerConfig[svCfgSite]);
        SendRconCommand(buff);

        format(buff, sizeof(buff), "language %s", ServerConfig[svCfgLanguage]);
        SendRconCommand(buff);

        printf("(1): Server configuration loaded...");
        return 1;
	}

	printf("(1): Server configuration failed");
	return 0;
}

custom LoadGangsConfiguration() {
    if(cache_num_rows() > 0) {
        cache_get_value_name_int(0, "capacity", GangsConfig[gdCfgCapacity]);
        cache_get_value_name_int(0, "flag_id", GangsConfig[gdCfgFlagId]);

        cache_get_value_name_float(0, "required", GangsConfig[gdCfgRequired]);
        cache_get_value_name_float(0, "default", GangsConfig[gdCfgDefault]);

        cache_get_value_name_float(0, "multiply", GangsConfig[gdCfgMultiply]);
        cache_get_value_name_float(0, "armour_per_level", GangsConfig[gdCfgArmourPerLevel]);
        cache_get_value_name_float(0, "bot_health", GangsConfig[gdCfgBotHealth]);
        cache_get_value_name_float(0, "flag_distance", GangsConfig[gdCfgFlagDistance]);

        cache_get_value_name_float(0, "per_cure", GangsConfig[gdCfgPerCure]);
        cache_get_value_name_float(0, "per_kill", GangsConfig[gdCfgPerKill]);
        cache_get_value_name_float(0, "per_evac", GangsConfig[gdCfgPerEvac]);
        cache_get_value_name_float(0, "per_ability", GangsConfig[gdCfgPerAbility]);
        cache_get_value_name_float(0, "per_assist", GangsConfig[gdCfgPerAssist]);

        printf("(2): Server gangs configuration loaded...");
        return 1;
    }

    printf("(2): Server gangs configuration failed");
    return 0;
}

custom LoadRoundConfiguration() {
    if(cache_num_rows() > 0) {
        cache_get_value_name_int(0, "survival_per", RoundConfig[rdCfgSurvivalPer]);
        cache_get_value_name_int(0, "cap", RoundConfig[rdCfgCap]);
        cache_get_value_name_float(0, "evac", RoundConfig[rdCfgEvac]);
        cache_get_value_name_float(0, "survival", RoundConfig[rdCfgSurvival]);
        cache_get_value_name_float(0, "killing", RoundConfig[rdCfgKilling]);
        cache_get_value_name_float(0, "care", RoundConfig[rdCfgCare]);
        cache_get_value_name_float(0, "mobility", RoundConfig[rdCfgMobility]);
        cache_get_value_name_float(0, "skillfulness", RoundConfig[rdCfgSkillfulness]);
        cache_get_value_name_float(0, "brutality", RoundConfig[rdCfgBrutality]);
        cache_get_value_name_float(0, "undead", RoundConfig[rdCfgDeaths]);
        
        printf("(3): Round configuration loaded...");
        return 1;
    }
    
    printf("(3): Round configuration failed");
    return 0;
}

custom LoadEvacConfiguration() {
    if(cache_num_rows() > 0) {
        new buff[256];
        cache_get_value_name(0, "position", buff);
        cache_get_value_name_int(0, "interior", EvacuationConfig[ecdCfgInterior]);
        cache_get_value_name_int(0, "sound", EvacuationConfig[ecdCfgSound]);

        sscanf(buff, "p<,>ffff", EvacuationConfig[ecdCfgPosition][0],
			EvacuationConfig[ecdCfgPosition][1], EvacuationConfig[ecdCfgPosition][2],
			EvacuationConfig[ecdCfgPosition][3]
		);

        printf("(4): Evacuation configuration loaded...");
        return 1;
    }

    printf("(4): Evacuation configuration failed");
    return 0;
}

custom LoadMapConfiguration() {
    if(cache_num_rows() > 0) {
        cache_get_value_name_int(0, "total", MapConfig[mpCfgTotal]);
        cache_get_value_name_int(0, "update", MapConfig[mpCfgUpdate]);
        cache_get_value_name_int(0, "balance", MapConfig[mpCfgBalance]);
        cache_get_value_name_int(0, "end", MapConfig[mpCfgEnd]);
        cache_get_value_name_int(0, "restart", MapConfig[mpCfgRestart]);
        
        printf("(5): Map configuration loaded...");
        return 1;
    }
    
    printf("(5): Map configuration failed");
    return 0;
}

custom LoadWeaponsConfiguration() {
    if(cache_num_rows() > 0) {
        new i, len = clamp(cache_num_rows(), 0, MAX_WEAPONS);
        for( i = 0; i < len; i++ ) {
            cache_get_value_name_int(i, "type", WeaponsConfig[i][wdCfgType]);
        	cache_get_value_name_int(i, "chance", WeaponsConfig[i][wdCfgChance]);
        	cache_get_value_name_int(i, "default", WeaponsConfig[i][wdCfgDefault]);
        	cache_get_value_name_int(i, "pick", WeaponsConfig[i][wdCfgPick]);
        	cache_get_value_name_int(i, "time", WeaponsConfig[i][wdCfgTime]);
        }
        
        printf("(6): Weapons configuration loaded... (%d)", len);
        return 1;
    }
    printf("(6): Weapons configuration failed");
	return 0;
}

custom LoginOrRegister(const playerid) {
	Misc[playerid][mdKickForAuthTimeout] = (ServerConfig[svCfgAuthTimeout] * 60);

    if(cache_num_rows() > 0) {
		cache_get_value_name(0, "password", Misc[playerid][mdPassword]);
        cache_get_value_name_int(0, "id", Player[playerid][pAccountId]);
        cache_get_value_name_int(0, "language", Player[playerid][pLanguage]);
        cache_get_value_name_int(0, "rank", Achievements[playerid][achRank]);
        cache_get_value_name_int(0, "kills", Achievements[playerid][achKills]);
        cache_get_value_name_int(0, "deaths", Achievements[playerid][achDeaths]);
        cache_get_value_name_int(0, "ability", Achievements[playerid][achAbility]);
        cache_get_value_name_int(0, "luck", Achievements[playerid][achLuck]);
        cache_get_value_name_int(0, "humans", Achievements[playerid][achHumans]);
        cache_get_value_name_int(0, "zombies", Achievements[playerid][achZombies]);
        cache_get_value_name_int(0, "meats", Achievements[playerid][achMeats]);
        cache_get_value_name_int(0, "killstreak", Achievements[playerid][achKillstreak]);
        cache_get_value_name_int(0, "infection", Achievements[playerid][achInfection]);
        cache_get_value_name_int(0, "cure", Achievements[playerid][achCure]);
        cache_get_value_name_int(0, "evacs", Achievements[playerid][achEvac]);
        cache_get_value_name_int(0, "reported", Achievements[playerid][achReported]);
        cache_get_value_name_int(0, "purchase", Achievements[playerid][achPurchase]);
        cache_get_value_name_int(0, "jumps", Achievements[playerid][achJumps]);
        cache_get_value_name_int(0, "hours", Achievements[playerid][achHours]);
        cache_get_value_name_int(0, "minutes", Achievements[playerid][achMinutes]);
        cache_get_value_name_int(0, "seconds", Achievements[playerid][achSeconds]);
        cache_get_value_name_int(0, "admin", Privileges[playerid][prsAdmin]);
        cache_get_value_name_int(0, "vip", Privileges[playerid][prsVip]);
        cache_get_value_name_int(0, "vip_till", Privileges[playerid][prsVipTill]);
        cache_get_value_name_int(0, "gang_id", Misc[playerid][mdGang]);
        cache_get_value_name_int(0, "gang_rank", Misc[playerid][mdGangRank]);
        cache_get_value_name_int(0, "gang_warns", Misc[playerid][mdGangWarns]);
        
        cache_get_value_name_float(0, "points", Player[playerid][pPoints]);
        cache_get_value_name_float(0, "total_points", Achievements[playerid][achTotalPoints]);
        cache_get_value_name_float(0, "ran", Achievements[playerid][achRan]);
        
        LoadLocalization(playerid, AUTH_LOGIN_TYPE);
        return 1;
    }

	LoadLocalization(playerid, AUTH_REG_TYPE);
    return 0;
}

custom InitializeLocation(const playerid, const type) {
    if(cache_num_rows() > 0) {
        for( new i = 0; i < cache_num_rows(); i++ ) {
            cache_get_value_name(i, "text", Localization[playerid][LOCALIZATION_DATA:i]);
        }
    
        if(type == AUTH_LOGIN_TYPE) {
            ShowLoginDialog(playerid);
        } else {
            ShowRegisterDialog(playerid);
        }
    }
}

stock LoadFilterScript(const filename[]) {
	static const cmd[] = "loadfs %s";
	new formated[sizeof(cmd) + MAX_MAP_FILENAME];
	format(formated, sizeof(formated), cmd, filename);
	SendRconCommand(formated);
}

stock UnloadFilterScript(const filename[]) {
	static const cmd[] = "unloadfs %s";
	new formated[sizeof(cmd) + MAX_MAP_FILENAME];
	format(formated, sizeof(formated), cmd, filename);
	SendRconCommand(formated);
}

stock SetMapName() {
    static const cmd[] = "mapname %s";
    new formated[sizeof(cmd) + MAX_MAP_NAME];
	format(formated, sizeof(formated), cmd, Map[mpName]);
	SendRconCommand(formated);
}

stock CheckToStartMap() {
    if(!Map[mpIsStarted] && !Map[mpPaused]) {
		LoadNewMap();
	}
}

stock ShowCheckpoint(const playerid) {
	SetPlayerCheckpoint(playerid,
		Map[mpCheckpointCoords][0],
		Map[mpCheckpointCoords][1],
		Map[mpCheckpointCoords][2],
		Map[mpCheckpointSize]
	);
}

stock LoadNewMap() {
	if((Map[mpId]-1) > Map[mpCount] || Map[mpId] < 1) {
		Map[mpId] = 1;
	}
	
	static const loadMapQuery[] = LOAD_MAP_DATA_QUERY;
	new formated[sizeof(loadMapQuery) + MAX_ID_LENGTH];
 	mysql_format(Database, formated, sizeof(formated), loadMapQuery, Map[mpId]);
 	mysql_tquery(Database, formated, "LoadMap");
}


stock SetMapId() {
    if(Map[mpId] < Map[mpCount]) {
		Map[mpId]++;
	} else {
		Map[mpId] = 1;
	}
}

stock ShowLoginDialog(const playerid, const type = DIALOG_NOERROR) {
	new formated[256];
	format(formated, sizeof(formated),
		Localization[playerid][LD_DG_LOGIN_DEFAULT + LOCALIZATION_DATA:type],
		Misc[playerid][mdKickForAuthTries]
	);
	
    ShowPlayerDialogAC(
		playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD,
		Localization[playerid][LD_DG_LOGIN_TITLE], formated,
		Localization[playerid][LD_BTN_LOGIN],
		Localization[playerid][LD_BTN_QUIT]
	);
}

stock ShowRegisterDialog(const playerid, const type = DIALOG_NOERROR) {
    ShowPlayerDialogAC(
		playerid, DIALOG_REGISTER, DIALOG_STYLE_INPUT,
		Localization[playerid][LD_DG_REG_TITLE],
		Localization[playerid][LD_DG_REG_DEFAULT + LOCALIZATION_DATA:type],
		Localization[playerid][LD_BTN_REGISTER],
		Localization[playerid][LD_BTN_QUIT]
	);
}

stock AfterAuthorization(const playerid) {
    static const sessionQuery[] = CREATE_SESSION_QUERY;
    new formatedSessionQuery[sizeof(sessionQuery) + MAX_ID_LENGTH + MAX_ID_LENGTH + MAX_PLAYER_IP + GPCI_LENGTH];
    mysql_format(Database, formatedSessionQuery, sizeof(formatedSessionQuery), sessionQuery, Player[playerid][pAccountId], gettime(), Misc[playerid][mdIp], Misc[playerid][mdSerial]);
    mysql_tquery(Database, formatedSessionQuery);
	
	Misc[playerid][mdKickForAuthTimeout] = -1;
	ServerConfig[svCfgCurrentOnline]++;
	
	Misc[playerid][mdIsLogged] = true;
    SetPlayerTeamAC(playerid, TEAM_ZOMBIE);
   	SpawnPlayer(playerid);
}

stock InitializeWeaponsData() {
    for( new i; i < MAX_WEAPONS; i++ ) {
	    WeaponsConfig[i][wdCfgType] = 0;
	    WeaponsConfig[i][wdCfgChance] = 0;
	    WeaponsConfig[i][wdCfgDefault] = 0;
	    WeaponsConfig[i][wdCfgPick] = 0;
	}
}

stock InitializeClassesData() {
	for( new i; i < MAX_CLASSES; i++ ) {
	    Classes[i][cldId] = -1;
	    Classes[i][cldTeam] = TEAM_UNKNOWN;
	    Classes[i][cldAbility] = -1;
	    Classes[i][cldLevel] = 0;
	    Classes[i][cldHealth] = 100;
	    Classes[i][cldArmour] = 0;
	    Classes[i][cldCooldown] = 0;
        Classes[i][cldSkin] = 1;
	    Classes[i][cldDisabled] = 1;
	    Classes[i][cldImmunity] = 0;
	    Classes[i][cldDistance] = 0.0;
	    Classes[i][cldAnimation] = 0;
		Classes[i][cldAnimationTime] = 0;
	    
		strmid(Classes[i][cldName], "", 0, MAX_CLASS_NAME);
		strmid(Classes[i][cldDesc], "", 0, MAX_CLASS_DESC);
	}
}

stock ClearAllPlayerData(const playerid) {
    ClearPlayerData(playerid);
    ClearPlayerPrevilegesData(playerid);
    ClearPlayerMiscData(playerid);
    ClearPlayerAchievementsData(playerid);
    ClearPlayerRoundData(playerid);
    ClearPlayerRoundSession(playerid);
    ClearPlayerWeaponsData(playerid);
    ResetWeapons(playerid);
    
    SetPlayerHealthAC(playerid, 100.0);
    SetPlayerArmourAC(playerid, 0.0);
}

stock ClearPlayerData(const playerid) {
    Player[playerid][pAccountId] = 0;
    Player[playerid][pLanguage] = 0;
    Player[playerid][pPoints] = 0.0;
}

stock ClearPlayerWeaponsData(const playerid) {
    for( new i; i < MAX_WEAPONS; i++ ) {
        Weapons[playerid][i][wdId] = 0;
        Weapons[playerid][i][wdTime] = 0;
        Weapons[playerid][i][wdAsDefault] = 0;
        Weapons[playerid][i][wdCount] = 0;
    }

    SetPlayerSkillLevel(playerid, WEAPONSKILL_PISTOL, 40);
    SetPlayerSkillLevel(playerid, WEAPONSKILL_PISTOL_SILENCED, 500);
    SetPlayerSkillLevel(playerid, WEAPONSKILL_SAWNOFF_SHOTGUN, 200);
    SetPlayerSkillLevel(playerid, WEAPONSKILL_SPAS12_SHOTGUN, 200);
    SetPlayerSkillLevel(playerid, WEAPONSKILL_MICRO_UZI, 50);
    SetPlayerSkillLevel(playerid, WEAPONSKILL_MP5, 250);
    SetPlayerSkillLevel(playerid, WEAPONSKILL_AK47, 200);
    SetPlayerSkillLevel(playerid, WEAPONSKILL_M4, 200);
    SetPlayerSkillLevel(playerid, WEAPONSKILL_SNIPERRIFLE, 300);
}

stock ClearPlayerAchievementsData(const playerid) {
	Achievements[playerid][achRank] = 0;
 	Achievements[playerid][achKills] = 0;
  	Achievements[playerid][achDeaths] = 0;
    Achievements[playerid][achAbility] = 0;
    Achievements[playerid][achLuck] = 0;
    Achievements[playerid][achHumans] = 0;
    Achievements[playerid][achZombies] = 0;
    Achievements[playerid][achMeats] = 0;
    Achievements[playerid][achKillstreak] = 0;
    Achievements[playerid][achInfection] = 0;
    Achievements[playerid][achCure] = 0;
    Achievements[playerid][achEvac] = 0;
    Achievements[playerid][achReported] = 0;
    Achievements[playerid][achPurchase] = 0;
    Achievements[playerid][achJumps] = 0;
    Achievements[playerid][achTotalPoints] = 0;
    Achievements[playerid][achHours] = 0;
    Achievements[playerid][achMinutes] = 0;
    Achievements[playerid][achSeconds] = 0;
    Achievements[playerid][achRan] = 0.0;
}
		
stock ClearPlayerPrevilegesData(const playerid) {
	Privileges[playerid][prsAdmin] = 0;
	Privileges[playerid][prsVip] = 0;
 	Privileges[playerid][prsVipTill] = 0;
}

stock ClearPlayerMiscData(const playerid) {
    GetPlayerName(playerid, Misc[playerid][mdPlayerName], MAX_PLAYER_NAME);
    GetPlayerIp(playerid, Misc[playerid][mdIp], MAX_PLAYER_IP);
    gpci(playerid, Misc[playerid][mdSerial], GPCI_LENGTH);
    
    Misc[playerid][mdPlayerTeam] = TEAM_UNKNOWN;
    Misc[playerid][mdSpawnProtection] = 0;
    Misc[playerid][mdIgnoreAnticheatFor] = 0;
    Misc[playerid][mdGang] = -1;
	Misc[playerid][mdGangRank] = 0;
	Misc[playerid][mdGangWarns] = 0;
	Misc[playerid][mdDialogId] = -1;
    Misc[playerid][mdIsLogged] = false;
    Misc[playerid][mdKickForAuthTimeout] = -1;
    Misc[playerid][mdKickForAuthTries] = ServerConfig[svCfgAuthTries];
    
    for( new i = 0; i < MAX_PLAYER_TEAMS; i++ ) {
	    Misc[playerid][mdCurrentClass][i] = 0;
        Misc[playerid][mdNextClass][i] = -1;
    }
    
    strmid(Misc[playerid][mdPassword], "", 0, MAX_PLAYER_PASSWORD);
}

stock InitializePlayersScreenTextures() {
	TimeLeftTexture = TextDrawCreate(22.000000, 251.000000, "300");
	TextDrawBackgroundColor(TimeLeftTexture, 255);
	TextDrawFont(TimeLeftTexture, 3);
	TextDrawLetterSize(TimeLeftTexture, 1.770000, 3.499999);
	TextDrawColor(TimeLeftTexture, 16777215);
	TextDrawSetOutline(TimeLeftTexture, 0);
	TextDrawSetProportional(TimeLeftTexture, 1);
	TextDrawSetShadow(TimeLeftTexture, 1);
	
	InfectedTexture = TextDrawCreate(655.500000, 1.500000, "usebox");
 	TextDrawBackgroundColor(InfectedTexture, 255);
  	TextDrawFont(InfectedTexture, 0);
	TextDrawLetterSize(InfectedTexture, 0.000000, 50.262496);
	TextDrawColor(InfectedTexture, 0);
	TextDrawSetOutline(InfectedTexture, 0);
	TextDrawSetProportional(InfectedTexture, 1);
	TextDrawSetShadow(InfectedTexture, 1);
	TextDrawUseBox(InfectedTexture, true);
	TextDrawBoxColor(InfectedTexture, 0xFF0000BB);
	TextDrawTextSize(InfectedTexture, -2.000000, 0.000000);
	
	UntillEvacRectangleTexture = TextDrawCreate(14.000000, 283.937500, "LD_SPAC:white");
	TextDrawLetterSize(UntillEvacRectangleTexture, 0.000000, 0.000000);
	TextDrawTextSize(UntillEvacRectangleTexture, 119.500000, 21.437500);
	TextDrawAlignment(UntillEvacRectangleTexture, 1);
	TextDrawColor(UntillEvacRectangleTexture, 255);
	TextDrawSetShadow(UntillEvacRectangleTexture, 0);
	TextDrawSetOutline(UntillEvacRectangleTexture, 0);
	TextDrawBackgroundColor(UntillEvacRectangleTexture, 255);
	TextDrawFont(UntillEvacRectangleTexture, 4);

	for( new i; i < MAX_PLAYERS; i++ ) {
        UntilEvacTextTexture[i] = TextDrawCreate(18.500000, 285.250000, "UNTIL EVAC");
		TextDrawLetterSize(UntilEvacTextTexture[i], 0.562500, 1.984999);
		TextDrawAlignment(UntilEvacTextTexture[i], 1);
		TextDrawColor(UntilEvacTextTexture[i], 0xFF0000FF);
		TextDrawSetShadow(UntilEvacTextTexture[i], 0);
		TextDrawSetOutline(UntilEvacTextTexture[i], 1);
		TextDrawBackgroundColor(UntilEvacTextTexture[i], 51);
		TextDrawFont(UntilEvacTextTexture[i], 1);
		TextDrawSetProportional(UntilEvacTextTexture[i], 1);

	    AliveInfoTexture[i] = TextDrawCreate(21.500000, 220.000000, "~w~humans: 0~n~~r~zombies: 0");
		TextDrawLetterSize(AliveInfoTexture[i], 0.511498, 1.477498);
		TextDrawAlignment(AliveInfoTexture[i], 1);
		TextDrawColor(AliveInfoTexture[i], -16776961);
		TextDrawSetShadow(AliveInfoTexture[i], 1);
		TextDrawSetOutline(AliveInfoTexture[i], 0);
		TextDrawBackgroundColor(AliveInfoTexture[i], 255);
		TextDrawFont(AliveInfoTexture[i], 2);
		TextDrawSetProportional(AliveInfoTexture[i], 1);
		
		PointsTexture[i] = TextDrawCreate(546.000000, 35.000000, "0");
	    TextDrawBackgroundColor(PointsTexture[i], 255);
	    TextDrawFont(PointsTexture[i], 2);
	    TextDrawLetterSize(PointsTexture[i], 0.270000, 1.000000);
	    TextDrawColor(PointsTexture[i], 16777215);
	    TextDrawSetOutline(PointsTexture[i], 0);
	    TextDrawSetProportional(PointsTexture[i], 1);
	    TextDrawSetShadow(PointsTexture[i], 1);
	}
}

stock InitializeDefaultValues() {
    new i, j;
    for( i = 0; i < MAX_PLAYERS; i++ ) {
        for( j = 0; j < MAX_ROUND_BOXES; j++ ) {
			Round[i][rdBox][j] = INVALID_OBJECT_ID;
			Round[i][rdBoxText][j] = Text3D:-1;
		}
		
		for( j = 0; j < MAX_MAP_SPAWNS; j++ ) {
		    Misc[i][mdSpawnPoints][j] = PlayerText3D:-1;
		}
    }
    
    for( j = 0; j < MAX_MAP_GATES; j++ ) {
	    Map[mpGates][j] = INVALID_OBJECT_ID;
	}
	
	Map[mpCrystal] = -1;
	Map[mpFlag] = -1;
	Map[mpFlagText] = Text3D:-1;
	ServerConfig[svCfgCurrentOnline] = 0;
}

stock DestroyPlayersScreenTextures() {
    for( new i; i < MAX_PLAYERS; i++ ) {
        if(IsPlayerConnected(i)) {
            TextDrawHideForPlayer(i, UntilEvacTextTexture[i]);
            TextDrawHideForPlayer(i, AliveInfoTexture[i]);
            TextDrawHideForPlayer(i, PointsTexture[i]);
        }
        
        TextDrawDestroy(UntilEvacTextTexture[i]);
        TextDrawDestroy(AliveInfoTexture[i]);
        TextDrawDestroy(PointsTexture[i]);
	}
	
	TextDrawHideForAll(UntillEvacRectangleTexture);
	TextDrawDestroy(UntillEvacRectangleTexture);
	
	TextDrawHideForAll(InfectedTexture);
	TextDrawDestroy(InfectedTexture);
	
	TextDrawHideForAll(TimeLeftTexture);
	TextDrawDestroy(TimeLeftTexture);
}

stock ClearPlayerRoundData(const playerid) {
    Round[playerid][rdIsEvacuated] = false;
    Round[playerid][rdIsInfected] = false;
    SetPlayerDrunkLevel(playerid, 0);
    TextDrawHideForPlayer(playerid, InfectedTexture);

    new i;
    for( i = 0; i < MAX_ROUND_BOXES; i++ ) {
		DestroyObjectEx(Round[playerid][rdBox][i]);
		Delete3DTextLabelEx(Round[playerid][rdBoxText][i]);
	}
	
	for( i = 0; i < MAX_MAP_SPAWNS; i++ ) {
		DeletePlayer3DTextLabelEx(playerid, Misc[playerid][mdSpawnPoints][i]);
		Misc[playerid][mdSpawnPoints][i] = CreatePlayer3DTextLabel(playerid, "{FFFFFF}Zombie Spawn\ndo{FF0000} not{FFFFFF} shoot zombies here", 0xFF0000FF, Map[mpZombieSpawnX][i], Map[mpZombieSpawnY][i], Map[mpZombieSpawnZ][i], 50.0);
	}
}

stock bool:IsAbleToGivePointsInCategory(const playerid, const type) {
	if(RoundSession[playerid][rsdTeam] != GetPlayerTeamEx(playerid) || RoundSession[playerid][rsdMapId] != Map[mpId]) {
	    return false;
	}

	switch(type) {
	    case SESSION_SURVIVAL_POINTS, SESSION_KILL_POINTS, SESSION_CARE_POINTS:
			return GetPlayerTeamEx(playerid) == TEAM_HUMAN;
		case SESSION_ABILITY_POINTS, SESSION_HIT_POINTS, SESSION_UNDEAD_POINTS:
		    return GetPlayerTeamEx(playerid) == TEAM_ZOMBIE;
	    case SESSION_RUN_POINTS:
	        return true;
	}
	return false;
}

stock GivePointsForRound(const playerid) {
	Player[playerid][pPoints] +=
	float(
		clamp(floatround(RoundSession[playerid][rsdSurvival], floatround_tozero), 0, RoundConfig[rdCfgCap]) +
		clamp(floatround(RoundSession[playerid][rsdKilling], floatround_tozero), 0, RoundConfig[rdCfgCap]) +
		clamp(floatround(RoundSession[playerid][rsdCare], floatround_tozero), 0, RoundConfig[rdCfgCap]) +
		clamp(floatround(RoundSession[playerid][rsdMobility], floatround_tozero), 0, RoundConfig[rdCfgCap]) +
		clamp(floatround(RoundSession[playerid][rsdSkillfulness], floatround_tozero), 0, RoundConfig[rdCfgCap]) +
		clamp(floatround(RoundSession[playerid][rsdBrutality], floatround_tozero), 0, RoundConfig[rdCfgCap]) +
		clamp(floatround(RoundSession[playerid][rsdDeaths], floatround_tozero), 0, RoundConfig[rdCfgCap])
	);
}


stock ResetRoundSessionOnMapStart(const playerid) {
    RoundSession[playerid][rsdMapId] = Map[mpId];
    RoundSession[playerid][rsdTeam] = GetPlayerTeamEx(playerid);
    RoundSession[playerid][rsdSurvival] = 0.0;
    RoundSession[playerid][rsdKilling] = 0.0;
    RoundSession[playerid][rsdCare] = 0.0;
    RoundSession[playerid][rsdMobility] = 0.0;
    RoundSession[playerid][rsdSkillfulness] = 0.0;
    RoundSession[playerid][rsdBrutality] = 0.0;
    RoundSession[playerid][rsdDeaths] = 0.0;
}

stock ClearPlayerRoundSession(const playerid) {
    RoundSession[playerid][rsdMapId] = -1;
    RoundSession[playerid][rsdTeam] = TEAM_UNKNOWN;
    RoundSession[playerid][rsdSurvival] = 0.0;
    RoundSession[playerid][rsdKilling] = 0.0;
    RoundSession[playerid][rsdCare] = 0.0;
    RoundSession[playerid][rsdMobility] = 0.0;
    RoundSession[playerid][rsdSkillfulness] = 0.0;
    RoundSession[playerid][rsdBrutality] = 0.0;
    RoundSession[playerid][rsdDeaths] = 0.0;
}

stock GetPlayerTeamEx(const playerid) {
	return Misc[playerid][mdPlayerTeam];
}

stock SetPlayerTeamAC(const playerid, const teamid) {
	new old = GetPlayerTeamEx(playerid);

	if(old != teamid) {
	    switch(teamid) {
	    	case TEAM_ZOMBIE: {
				Map[mpTeamCount][0]++;

				if(old == TEAM_HUMAN) {
					Map[mpTeamCount][1]--;
				}
			}
	    	case TEAM_HUMAN: {
				Map[mpTeamCount][1]++;

				if(old == TEAM_ZOMBIE) {
					Map[mpTeamCount][0]--;
				}
        	}
		}
	}

	SetPlayerTeam(playerid, teamid);
	Misc[playerid][mdPlayerTeam] = teamid;
}

stock SetByCurrentClass(const playerid) {
	SetPlayerHealthAC(playerid, 100.0);
    SetPlayerArmourAC(playerid, 0.0);
    ResetWeapons(playerid);
    ClearPlayerRoundData(playerid);

	new team = Misc[playerid][mdPlayerTeam];
	new next = Misc[playerid][mdNextClass][team];
	new current = Misc[playerid][mdCurrentClass][team];
	new point = random(MAX_MAP_SPAWNS);
	new Float:distance = random(50) / 100;
	
	if(next > -1) {
	    current = next;
		Misc[playerid][mdCurrentClass][team] = next;
	    Misc[playerid][mdNextClass][team] = -1;
	    next = -1;
	}
	
	switch(GetPlayerTeamEx(playerid)) {
	    case TEAM_ZOMBIE: {
			SetZombie(playerid, current);
			SetPlayerPos(playerid, 	Map[mpZombieSpawnX][point] + distance, Map[mpZombieSpawnY][point] + distance, Map[mpZombieSpawnZ][point]);
			SetPlayerFacingAngle(playerid, Map[mpZombieSpawnA][point]);
		}
	    case TEAM_HUMAN: {
			SetHuman(playerid, current);
			SetPlayerPos(playerid, 	Map[mpHumanSpawnX][point] + distance, Map[mpHumanSpawnY][point] + distance, Map[mpHumanSpawnZ][point]);
			SetPlayerFacingAngle(playerid, Map[mpHumanSpawnA][point]);
  		}
	}
	
	SetCameraBehindPlayer(playerid);
	TextDrawShowForPlayer(playerid, TimeLeftTexture);
	TextDrawShowForPlayer(playerid, UntillEvacRectangleTexture);
	TextDrawShowForPlayer(playerid, UntilEvacTextTexture[playerid]);
 	TextDrawShowForPlayer(playerid, AliveInfoTexture[playerid]);
  	TextDrawShowForPlayer(playerid, PointsTexture[playerid]);
}

stock InfectPlayer(const playerid, const targetId) {
	if(Round[playerid][rdIsInfected]) {
	    return 0;
	}
    
    Round[playerid][rdIsInfected] = true;
    return 1;
}

stock CurePlayer(const playerid) {
    if(!Round[playerid][rdIsInfected]) {
	    return 0;
	}
	
    Round[playerid][rdIsInfected] = false;
    SetPlayerDrunkLevel(playerid, 0);
    TextDrawHideForPlayer(playerid, InfectedTexture);
    return 1;
}

Float:GetXYInFrontOfPlayer(playerid, &Float:q, &Float:w, Float:distance)
{
	new Float:a;
	GetPlayerPos(playerid, q, w, a);
	if (GetPlayerState(playerid) == PLAYER_STATE_DRIVER) GetVehicleZAngle(GetPlayerVehicleID(playerid), a);
	else GetPlayerFacingAngle(playerid, a);
	q += (distance * floatsin(-a, degrees));
	w += (distance * floatcos(-a, degrees));
	return a;
}

stock ProcedPickupAction(const playerid, const pickupid) {
	if(GetPlayerTeamEx(playerid) == TEAM_HUMAN && Pickups[pickupid][pcd_model] == BULLETS_PICKUP) {
	    new weapon = GetPlayerWeapon(playerid);
	    new index = GetWeaponFromConfigById(weapon);
	    new amount = (index > -1) ? WeaponsConfig[index][wdCfgPick] : 1;
	    new formated[32];
	    
	    GivePlayerWeapon(playerid, weapon, amount);
	    format(formated, sizeof(formated), "~w~%d~g~ ammo", amount);
	    GameTextForPlayer(playerid, formated, 2000, 5);
	    return 1;
	}
	
	if(Pickups[pickupid][pcd_model] == MEAT_PICKUP) {
	    if(GetPlayerTeamEx(playerid) == TEAM_ZOMBIE) {
	        SetPlayerHealthAC(playerid, 100.0);
	        return 1;
	    }
	}
	
	return 1;
}

stock CreateDropOnDeath(const playerid, const killerid) {
	new Float:pos[3];
	new type[4] = { -1, BULLETS_PICKUP, MEAT_PICKUP, -1 };
 	new index = random(sizeof(type));

	GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
  	CreatePickupEx(type[index], STATIC_PICKUP_TYPE, pos[0], pos[1], pos[2], GetPlayerVirtualWorld(playerid), IsPlayerConnected(killerid) ? killerid : -1);
  	SetPlayerTeamAC(playerid, TEAM_ZOMBIE);
	return 1;
}

bool:IsValidPickupEx(const pickupid) {
	return (pickupid < 0 || pickupid >= (MAX_PICKUPS - 1)) ? false : Pickups[pickupid][is_active];
}

bool:IsAbleToPickup(const playerid, const pickupid) {
	if(!IsValidPickupEx(pickupid)) {
	    return false;
	}
	
	return Pickups[pickupid][pcd_for_player] == -1 || !IsPlayerConnected(playerid) ||
	playerid == Pickups[pickupid][pcd_for_player] || gettime() >= Pickups[pickupid][pcd_protection_till];
}

stock CreatePickupEx(const pickupid, const type, const Float:x, const Float:y, const Float:z, const world, const playerid = -1) {
	if(pickupid < 0) {
	    return pickupid;
	}

	new id = CreatePickup(pickupid, type, x, y, z, world);
    if(id >= 0 && pickupid <= MAX_PICKUPS) {
	 	Pickups[id][pcd_id] = id;
	 	Pickups[id][pcd_model] = pickupid;
	 	Pickups[id][pcd_protection_till] = gettime() + ServerConfig[svCfgPickupProtection];
	 	Pickups[id][pcd_for_player] = playerid;
	 	Pickups[id][is_active] = true;
	}
	return id;
}

stock DestroyPickupEx(const pickupid) {
    if(IsValidPickupEx(pickupid)) {
        Pickups[pickupid][pcd_id] = -1;
        Pickups[pickupid][pcd_model] = -1;
	 	Pickups[pickupid][pcd_protection_till] = 0;
	 	Pickups[pickupid][pcd_for_player] = -1;
	 	Pickups[pickupid][is_active] = false;
    }
    DestroyPickup(pickupid);
}

stock InitializePickups() {
	for( new i = 0; i < MAX_PICKUPS; i++ ) {
	    DestroyPickupEx(i);
	}
}

stock ResetWeapons(const playerid) {
    new gunname[32];
	for(new i = 0; i < 46; i++) {
		GetWeaponName(i, gunname, sizeof(gunname));
		SetPVarInt(playerid, gunname, -4);
	}
    SetPlayerArmedWeapon(playerid, 0);
    ResetPlayerWeapons(playerid);
}

stock GivePlayerWeaponAC(const playerid, const weapid, const ammo) {
    new gunname[32], stack = min(1000, GetPVarInt(playerid, gunname) + ammo);
    GetWeaponName(weapid, gunname, sizeof(gunname));
    SetPVarInt(playerid, gunname, stack);
    GivePlayerWeapon(playerid, weapid, stack);
    SetPlayerAmmo(playerid, weapid, stack);
	return 1;
}

stock Float:GetPlayerHealthEx(const playerid) {
	return Misc[playerid][mdHealth];
}

stock Float:GetPlayerArmourEx(const playerid) {
	return Misc[playerid][mdArmour];
}

stock SetPlayerHealthAC(const playerid, const Float:hp) {
	Misc[playerid][mdIgnoreAnticheatFor] = 3;
 	Misc[playerid][mdHealth] = hp;
   	SetPlayerHealth(playerid, hp);
}

stock SetPlayerArmourAC(const playerid, const Float:armour) {
	Misc[playerid][mdIgnoreAnticheatFor] = 3;
	Misc[playerid][mdArmour] = armour;
   	SetPlayerArmour(playerid, armour);
}

stock ShowPlayerDialogAC(const playerid, const dialogId, const dialogStyle, caption[], info[], button1[], button2[]) {
    Misc[playerid][mdDialogId] = dialogId;
	ShowPlayerDialog(playerid, dialogId, dialogStyle, caption, info, button1, button2);
}

stock NormalizeHealthAC(const playerid, &Float:hp) {
    GetPlayerHealth(playerid, hp);
	if(Misc[playerid][mdHealth] < hp) {
		SetPlayerHealth(playerid, Misc[playerid][mdHealth]);
	} else {
		Misc[playerid][mdHealth] = hp;
	}
}

stock NormalizeArmourAC(const playerid, &Float:armour) {
    GetPlayerArmour(playerid, armour);
	if(Misc[playerid][mdArmour] < armour) {
		SetPlayerHealth(playerid, Misc[playerid][mdArmour]);
	} else {
		Misc[playerid][mdArmour] = armour;
	}
}

stock CheckAndNormalizeACValues(const playerid, &Float:hp, &Float:armour) {
    if(Misc[playerid][mdIgnoreAnticheatFor]) {
    	Misc[playerid][mdIgnoreAnticheatFor]--;
    } else {
    	NormalizeHealthAC(playerid, hp);
     	NormalizeArmourAC(playerid, armour);
    }
}

stock ShowDamageTaken(playerid, Float:damage = 0.0) {
	new s[13];
	format(s, sizeof(s), "-%.0f", damage);
    SetPlayerChatBubble(playerid, s, BUBBLE_COLOR, 20.0, 1000);
}

stock EmptyMessage(const string[]) {
    for(new i = 0; string[i] != 0x0; i++) {
        switch(string[i]) {
            case 0x20: continue;
            default: return 0;
        }
    }
    return 1;
}

stock SetZombie(const playerid, const classid) {
    SetPlayerColor(playerid, COLOR_ZOMBIE);
}

stock SetHuman(const playerid, const classid) {
    SetPlayerColor(playerid, COLOR_HUMAN);
    LoadPlayerWeaponsOnStart(playerid);
}

stock SetToZombieOrHuman(playerid) {
	if(random(2) == 0) {
		SetPlayerTeamAC(playerid, TEAM_HUMAN);
	} else {
	    SetPlayerTeamAC(playerid, TEAM_ZOMBIE);
	}
}

stock ResetMapValuesOnDeath(const playerid) {
    if(Round[playerid][rdIsEvacuated]) {
	    Map[mpEvacuatedHumans]--;
	}
}

stock ResetValuesOnDisconnect(const playerid) {
	if(Misc[playerid][mdIsLogged]) {
    	ServerConfig[svCfgCurrentOnline]--;
    }
    
    if(Map[mpTeamCount][0] >= 1 && GetPlayerTeamEx(playerid) == TEAM_ZOMBIE) {
        Map[mpTeamCount][0]--;
    }
    
    if(Map[mpTeamCount][1] >= 1 && GetPlayerTeamEx(playerid) == TEAM_HUMAN) {
        Map[mpTeamCount][1]--;
    }
}

stock GetWeaponByChance(const index, const chance, const slot) {
	switch(index) {
		case 22, 23, 24, 25, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 39:
			return chance <= WeaponsConfig[slot][wdCfgChance] ? slot : -1;
		default: return -1;
	}
	return -1;
}

stock GetWeaponFromConfigById(const weaponid) {
    for( new i; i < MAX_WEAPONS; i++ ) {
        if(WeaponsConfig[i][wdCfgType] == weaponid) {
            return i;
        }
	}
	
	return -1;
}

stock LoadPlayerWeaponsOnStart(const playerid) {
    static const weaponsQuery[] = LOAD_PLAYER_WEAPONS_QUERY;
	new formatedWeaponsQuery[sizeof(weaponsQuery) + MAX_ID_LENGTH + MAX_ID_LENGTH + MAX_ID_LENGTH];
	mysql_format(Database, formatedWeaponsQuery, sizeof(formatedWeaponsQuery), weaponsQuery, Player[playerid][pAccountId], gettime(), MAX_WEAPONS);
 	mysql_tquery(Database, formatedWeaponsQuery, "GetUserCollectedWeapons", "i", playerid);
 	
 	static const deleteOldWeaponsQuery[] = REFRESH_PLAYER_WEAPONS_QUERY;
 	new formatedDeleteOldWeaponsQuery[sizeof(deleteOldWeaponsQuery) + MAX_ID_LENGTH];
 	mysql_format(Database, formatedDeleteOldWeaponsQuery, sizeof(formatedDeleteOldWeaponsQuery), deleteOldWeaponsQuery, gettime());
 	mysql_tquery(Database, formatedDeleteOldWeaponsQuery);
}

stock SavePlayerWeaponToDatabase(const playerid, const weaponid, const index) {
	static const insertWeaponQuery[] = CREATE_PLAYER_WEAPON_QUERY;
    new formatedInsertWeaponQuery[sizeof(insertWeaponQuery) + MAX_ID_LENGTH + MAX_ID_LENGTH + MAX_ID_LENGTH];
    mysql_format(Database, formatedInsertWeaponQuery, sizeof(formatedInsertWeaponQuery), insertWeaponQuery, Player[playerid][pAccountId], weaponid, gettime() + WeaponsConfig[index][wdCfgTime]);
 	mysql_tquery(Database, formatedInsertWeaponQuery);
}

stock GetRequiredZombiesCount() {
    switch(ServerConfig[svCfgCurrentOnline]) {
        case 0..3:
            return floatround(ServerConfig[svCfgCurrentOnline] / 2, floatround_tozero);
		case 4..7:
			return floatround(ServerConfig[svCfgCurrentOnline] / 3, floatround_tozero);
		default:
		    return floatround(ServerConfig[svCfgCurrentOnline] / 4, floatround_tozero);
    }

    return floatround(ServerConfig[svCfgCurrentOnline] / 2, floatround_tozero);
}

stock SetTeams() {
	new required = GetRequiredZombiesCount(), current, i, j;
    new players[MAX_PLAYERS] = { 1, 2, 3, ... }, playerid;

    for( i = MAX_PLAYERS - 1; i > 0; i-- ) {
        j = random(i + 1);
        swap(players[i], players[j]);
    }

    for ( i = 0; i < MAX_PLAYERS; i++ ) {
	    playerid = players[i] - 1;
	    if(!IsPlayerConnected(playerid) || !Misc[playerid][mdIsLogged]) {
	    	continue;
		}

	    if(current < required) {
	        SetPlayerTeamAC(playerid, TEAM_ZOMBIE);
            ++current;
        } else {
            SetPlayerTeamAC(playerid, TEAM_HUMAN);
        }
        
        ResetRoundSessionOnMapStart(playerid);
        SpawnPlayer(playerid);
		SetCameraBehindPlayer(playerid);
    }
}

CMD:weapons(const playerid) {
	return 1;
}

CMD:cure(const playerid, const targetid) {
	if(playerid != targetid && IsAbleToGivePointsInCategory(playerid, SESSION_CARE_POINTS)) {
	    RoundSession[playerid][rsdCare] += RoundConfig[rdCfgCare];
	}

	return 1;
}

CMD:test(playerid) {
	SetPlayerTeamAC(playerid, TEAM_HUMAN);
	SetByCurrentClass(playerid);

	new index = random(MAX_WEAPONS);
	new weapon = WeaponsConfig[index][wdCfgType];
	if(weapon == WEAPON_SILENCED) {
	    weapon = WEAPON_COLT45;
	}

	new slot = GetWeaponByChance(weapon, random(100), index);
	if(slot > -1) {
	    GivePlayerWeaponAC(playerid, weapon, WeaponsConfig[index][wdCfgDefault]);
	    SavePlayerWeaponToDatabase(playerid, weapon, index);
	}
	return 0;
}

