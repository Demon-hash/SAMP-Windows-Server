#include <packs/core>
#include <packs/developer>

#pragma warning disable 208
#pragma warning disable 239

static const sqlTemplates[][] = {
    REGISTRATION_TEMPLATE, USERS_TEMPLATE, PRIVILEGES_TEMPLATE,
	GANGS_TEMPLATE, GANGS_USERS_TEMPLATE, GANGS_REQUESTS_TEMPLATE,
	GANGS_WARNS_TEMPLATE, GANGS_BLACKLISTED_TEMPLATE,
	GANGS_CONFIG_TEMPLATE, MAPS_TEMPLATE, WEAPONS_TEMPLATE,
	LANGUAGES_TEMPLATE, CLASSES_TEMPLATE, BANLOG_TEMPLATE,
	NAMELOG_TEMPLATE, LOGINLOG_TEMPLATE, PAYLOG_TEMPLATE,
	AUCTIONLOG_TEMPLATE, WARNSLOG_TEMPLATE, MUTESLOG_TEMPLATE,
	MUTESLOG_TEMPLATE, JAILSLOG_TEMPLATE, GANGPAYLOG_TEMPLATE,
	GANGDEPOSITLOG_TEMPLATE, AUCTION_TEMPLATE,
	AUCTION_CASHBACK_TEMPLATE, ACHIEVEMENTS_TEMPLATE,
	CONFIG_TEMPLATE, STATS_TEMPLATE, ANTICHEAT_TEMPLATE,
	ACHIEVEMENTS_CONFIG_TEMPLATE
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
    PREDIFINED_FLAMETHOWER, PREDIFINED_GRENADE, PREDIFINED_SPAS,
    PREDIFINED_CONFIG, PREDIFINED_GANGS_CONFIG, PREDIFINED_ANTICHEAT
};

static const sqlPredifinedLocalization[][] = {
    PRD_LD_DG_LOGIN_TITLE, PRD_LD_DG_LOGIN_DEFAULT, PRD_LD_DG_LOGIN_TRIES,
    PRD_LD_DG_LOGIN_SPACES, PRD_LD_DG_REG_TITLE, PRD_LD_DG_REG_DEFAULT,
    PRD_LD_DG_REG_SPACES, PRD_LD_BTN_REG, PRD_LD_BTN_LOGIN, PRD_LD_BTN_QUIT
};

static Player[MAX_PLAYERS][PLAYER_DATA];
static Round[MAX_PLAYERS][ROUND_DATA];
static Misc[MAX_PLAYERS][MISC_DATA];
static Privileges[MAX_PLAYERS][PRIVILEGES_DATA];
static Achievements[MAX_PLAYERS][ACHIEVEMENTS_DATA];
static Pickups[MAX_PICKUPS][PICKUP_DATA];
static Gangs[MAX_GANGS][GANG_DATA];
static Classes[MAX_CLASSES][CLASSES_DATA];

static MapConfig[MAP_DATA];
static AchievementsConfig[1];
static AnticheatConfig[1];
static ServerConfig[CONFIG_DATA];

static Localization[MAX_PLAYERS][LOCALIZATION_DATA][LOCALIZATION_LINE_SIZE];

static MySQL:Database;
static updateTimerId;

static Text:TimeLeftTexture, Text:InfectedTexture, Text:UntillEvacRectangleTexture;

static Text:UntilEvacTextTexture[MAX_PLAYERS], Text:AliveInfoTexture[MAX_PLAYERS], Text:PointsTexture[MAX_PLAYERS];

// ShowPlayerDialog
// SendClientMessage
// format
// CreatePlayer3DTextLabel
// static Language[MAX_PLAYERS][LANGUAGE_DATA];

/*
	1.1 Account
	    * We have the right to collect this information: IPs, Machine IDs, (un)bans, (gang) payments / deposits, names, mutes, warns, jails
	
	- The purchase of game values for real money between players is allowed, however, the administration and the founder of the project are not responsible for the transactions made
		* In case of cheating, we can ban the cheater
*/

/*
 - General Changes To Gameplay:
 - Zombies don't have chainsaw anymore, use your fists to deal damage (5 HP)
 - Classes unlocks abilities, but not weapons, you can set your own weapons
 - All classes can be infected
 - Points is gained from the quality of the round you played:
    * Survival (5 for evacuation)
    * Infect / Ability / Cure (3)
    * Kill (1)
    * Camping (0.3)
    
 - Gangs:
    - Capacity is 10 members only,
    - Create a gang required 25,000 points
 	- Quests (5):
		* Reach a total of 50,000 points (Reward: Country Rifle)
		* Reach a total of 75,000 points (Reward: Sniper Rifle)
		* Reach a total of 100,000 points (Reward: Flamethrower)
		* Reach a total of 1,00,000 points (Reward: Grenade)
		* Reach a total of 5,000,000 points (Reward: Combat Shotgun)
	 - How to capture:
    	* At the end of the round, gang players will receive weapons and must inflict the maximum possible damage on the spawned bot
		* The map will be captured by the gang that deals the most damage
		* Weapon modifications provide additional damage to the bot
 - Weapons:
    * Achieve 40 killstreak in a row using Silinced Pistol (Reward: Colt45)
    * Achieve 45 killstreak in a row using Colt45 (Reward: Shotgun)
    * Achieve 50 killstreak in a row using Shotgun (Reward: Deagle)
 	* Kill 250 zombies using Deagle (Reward: UZI)
	* Kill 500 zombies using UZI (Reward: Tec9)
	* Kill 750 zombies using Tec9 (Reward: MP5)
	* Kill 1250 zombies using MP5 (Reward: Ak47)
	* Kill 1500 zombies using Ak47 (Reward: M4)
	
	* Killing a zombie with a certain weapon can create a certain weapon pickup that can be sold (You can buy weapons from other players)
 - Maps:
    * Captured map gives more points for killing (+2)
    * The gang holding the map receives additional experience points for actions:
    	* Infect / Ability / Cure (0.1%)
    	* Evac (0.5%)
*/

/*
	General Weekly Quests:
 	- Kill 50 players (Armor Chest) (multiple)
 	- Kill 100 players (Double Ammo Chest) (multiple)
 	
 	- Kill 300 zombies (Skins Chest) (one per week)
 	- Kill 300 humans (Skins Chest) (one per week)
 	
 	- Collect 300 meats (Accessory Chest) (one per week)
	- Infect 300 humans (Accessory Chest) (one per week)
 	- Cure 300 humans (Accessory Chest) (one per week)
 	
 	- Achieve 50 killstreak in a row (Weapon Module Chest) (one per week)
 	- Achieve 100 killstreak in a row (Weapon Module Chest) (one per week)
	- Achieve 150 killstreak in a row (Weapon Module Chest) (one per week)
*/

/*
	    "%sTrainee\t%sUse your class ability 1 time (0.2 EXP){FFFFFF} [%d/1]\n",
	    "%sSemi experienced\t%sUse your class ability 500 times (0.5 EXP){FFFFFF} [%d/500]\n",
	    "%sExperienced\t%sUse your class ability 1000 times (1 EXP){FFFFFF} [%d/1000]\n",
	    "%sJogging\t%sRun 10,000 kilometers (5 EXP){FFFFFF} [%.3f/10,000]\n",
	    "%sRunner\t%sRun 50,000 kilometers (15 EXP){FFFFFF} [%.3f/50,000]\n",
	    "%sOlympic champion\t%sRun 200,000 kilometers (20 EXP){FFFFFF} [%.3f/200,000]\n",
	    "%sLucky\t%sSurvive with a health of 1, 3 times (3 EXP){FFFFFF} [%d/3]\n",
	    "%sInviolable\t%sSurvive with a health of 1, 10 times (8 EXP){FFFFFF} [%d/10]\n",
	    "%sCheat death\t%sSurvive with a health of 1, 20 times (15 EXP){FFFFFF} [%d/20]\n",
	    "%sManiac\t%sKill 10 humans (1 EXP){FFFFFF} [%d/20]\n",
	    "%sSerial maniac\t%sKill 100 humans (5 EXP){FFFFFF} [%d/100]\n",
	    "%sJack the ripper\t%sKill 1000 humans (8 EXP){FFFFFF} [%d/1000]\n",
	    "%sConductor\t%sKill 10 zombies (20 EXP){FFFFFF} [%d/20]\n",
     	"%sUndead slayer\t%sKill 100 zombies (300 EXP){FFFFFF} [%d/100]\n",
     	"%sSaint\t%sKill 1000 zombies (2000 EXP){FFFFFF} [%d/1000]\n\n",
     	"%sTerrorist\t%sKill 10000 players (10000 EXP){FFFFFF} [%d/10000]\n",
     	"%sCollector\t%sCollect 100 Meats (200 EXP){FFFFFF} [%d/100]\n",
     	"%sButcher\t%sCollect 1000 Meats (1000 EXP){FFFFFF} [%d/1000]\n",
     	"%sMadman\t%sCollect 5000 Meats (3000 EXP){FFFFFF} [%d/5000]\n",
     	"%sBlood lover\t%sAchieve 5 killstreaks (10 EXP){FFFFFF} [%d/5]\n",
     	"%sMeat lover\t%sAchieve 50 killstreaks (4000 EXP){FFFFFF} [%d/50]\n",
     	"%sThe Killer Machine\t%sAchieve 100 killstreaks (10000 EXP){FFFFFF} [%d/100]\n",
     	"%sNurse\t%s/cure 1 human (10 EXP){FFFFFF} [%d/1]\n",
     	"%sMedic\t%s/cure 50 humans (150 EXP){FFFFFF} [%d/50]\n", 
     	"%sDoctor\t%s/cure 100 humans (400 EXP){FFFFFF} [%d/100]\n",
     	"%sRisen from the grave\t%sDie 10 times (10 EXP){FFFFFF} [%d/10]\n",
     	"%sDead Rising Army\t%sDie 100 times (100 EXP){FFFFFF} [%d/100]\n",
     	"%sDo Not Even Try\t%sDie 1000 times (1000 EXP){FFFFFF} [%d/1000]\n",

		 "%sCollection Point\t%sEvac 5 times (2000 EXP){FFFFFF} [%d/1]\n",
		 "%sSafe Place\t%sEvac 100 times (2000 EXP){FFFFFF} [%d/1]\n",
		 "%sSafe Zone\t%sEvac 300 times (2000 EXP){FFFFFF} [%d/1]\n",
     	
     	"%sTrust but check\t%s/report 10 cheaters (100 EXP){FFFFFF} [%d/10]\n",
     	"%sExemplary\t%s/report 50 cheaters (500 EXP){FFFFFF} [%d/50]\n",
     	"%sLaw-abiding\t%s/report 100 cheaters (2000 EXP){FFFFFF} [%d/100]\n",
     	
     	"%sAmateur\t%sMake 50 purchases in /shop (200 EXP){FFFFFF} [%d/50]\n",
     	"%sShopaholic\t%sMake 100 purchases in /shop (1000 EXP){FFFFFF} [%d/100]\n",
     	"%sMoney in nowhere\t%sMake 200 purchases in /shop (5000 EXP){FFFFFF} [%d/200]\n",
     	
     	"%sIn cash\t%sGet a total of 100,000 points (5000 EXP){FFFFFF} [%d/200]\n",
     	"%sBusinessman\t%sGet a total of 500,000 points (5000 EXP){FFFFFF} [%d/200]\n",
     	"%sMillionaire\t%sGet a total of 1,000,000 points (5000 EXP){FFFFFF} [%d/200]\n",

        "%sUnknown virus\t%sInfect 50 humans (20 EXP){FFFFFF} [%d/1000]\n",
        "%sDisease\t%sInfect 300 humans (20 EXP){FFFFFF} [%d/1000]\n",
		"%sMass infection\t%sInfect 1000 humans (20 EXP){FFFFFF} [%d/1000]\n",
        
        "%sFan\t%sPlay for one week in total (50 EXP){FFFFFF} [%d/168]\n",
        "%sGamer\t%sPlay for half a year in total (200 EXP){FFFFFF} [%d/4380]\n",
        "%sExanimate\t%sPlay for 1 year in total (500 EXP){FFFFFF} [%d/8760]\n",
        "%sJumper\t%sJump 100 times (200 EXP){FFFFFF} [%d/100]\n", // 66
        "%sToad paws\t%sJump 300 times (700 EXP){FFFFFF} [%d/300]\n", // 67
        "%sPilot\t%sJump 700 times (1500 EXP){FFFFFF} [%d/700]\n", // 68

        "%sParable\t%sComplete 1 gang quests (5000 EXP)\n", // 77
        "%sTales\t%sComplete 2 gang quests (5000 EXP)\n", // 77
        "%sStory\t%sComplete 3 gang quests (5000 EXP)\n", // 77
        "%sHistory\t%sComplete 4 gang quests (25000 EXP)\n", // 78
        "%sLegend\t%sComplete 5 gang quests (100000 EXP)\n", // 79
*/

enum {
	ACH_TIME_VICTIM,
	ACH_PARABLE,
	ACH_TALES,
	ACH_STORY,
	ACH_HISTORY,
	ACH_LEGEND,
};

main() {
}

public OnGameModeInit() {
	InitializePickups();
	InitializeClassesData();
	InitializePlayersScreenTextures();
	InitializeDefaultValues();
	
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
	mysql_tquery(Database, LOAD_MAPS_COUNT_QUERY, "LoadMapsCount");
	
 	mysql_log(SQL_LOG_LEVEL);
 	
	printf("Status: %d", mysql_errno(Database));
	
	SetGameModeText("Zombies");
	updateTimerId = SetTimer("Update", 1000, true);
	return 1;
}

public OnGameModeExit() {
    mysql_close(Database);
	KillTimer(updateTimerId);
	UnloadFilterScript(MapConfig[mpFilename]);
	DestroyPlayersScreenTextures();
	return 1;
}

public OnPlayerConnect(playerid) {
    ClearAllPlayerData(playerid);
    CheckForAccount(playerid);
    return 1;
}

public OnPlayerRequestClass(playerid, classid) {
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

public OnPlayerDisconnect(playerid, reason) {
	return 1;
}

public OnPlayerSpawn(playerid) {
	if(!Misc[playerid][mdIsLogged]) {
	    return 0;
	}
	
    SetByCurrentClass(playerid);
    
    CheckToStartMap();
    
    SetPlayerWeather(playerid, MapConfig[mpWeather]);
	SetPlayerTime(playerid, MapConfig[mpTime], 0);
	return 1;
}

public OnPlayerUpdate(playerid) {
	SetPlayerScore(playerid, Achievements[playerid][achRank]);
	return 1;
}

public OnPlayerDeath(playerid, killerid, reason) {
	if(!IsPlayerConnected(playerid)) {
	    return 0;
	}

    reason = clamp(reason, WEAPON_FISTS, WEAPON_COLLISION);
	SendDeathMessage(killerid, playerid, reason);

 	ClearPlayerRoundData(playerid);
	CreateDropOnDeath(playerid, killerid);
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
	}
	
	return 1;
}

public OnPlayerTakeDamage(playerid, issuerid, Float: amount, weaponid, bodypart) {
    ShowDamageTaken(playerid, amount);
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
		SendClientMessage(playerid, 0xFF0000FF, "Unknown command");
		return 0;
	}
	return 1;
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
	        	SetPlayerDrunkLevel(playerid, 50000);
    		}
    		
    		format(formated, sizeof(formated),"%d", Player[playerid][pPoints]);
    		TextDrawSetString(PointsTexture[playerid], formated);
    		
    		format(formated, sizeof(formated), "~w~humans: %d~n~~r~zombies: %d", MapConfig[mpTeamCount][1], MapConfig[mpTeamCount][0]);
            TextDrawSetString(AliveInfoTexture[playerid], formated);
	    }
	}
	
	if((currentSecond % MAP_UPDATE_TIME) == 0) {
		OnMapUpdate();
	}
}

custom LoadMapsCount() {
     if(cache_num_rows()) {
        cache_get_value_name_int(0, "maps", MapConfig[mpCount]);
        printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
        printf("%d maps are loaded!", MapConfig[mpCount]);
        printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
    }
}

custom LoadMap() {
    if(cache_num_rows() > 0) {
        new buff[256];
        
        strmid(MapConfig[mpAuthor], "", 0, MAX_PLAYER_NAME);
        
	    cache_get_value_name_int(0, "weather", MapConfig[mpWeather]);
	    cache_get_value_name_int(0, "interior", MapConfig[mpInterior]);
	    cache_get_value_name_int(0, "time", MapConfig[mpTime]);
	    cache_get_value_name_int(0, "gang", MapConfig[mpGang]);
	    cache_get_value_name_int(0, "water", MapConfig[mpWaterAllowed]);
    	
    	cache_get_value_name(0, "login", MapConfig[mpAuthor]);
        cache_get_value_name(0, "name", MapConfig[mpName]);
        cache_get_value_name(0, "filename", MapConfig[mpFilename]);
        
        cache_get_value_name_float(0, "gates_speed", MapConfig[mpGateSpeed]);
    	cache_get_value_name_float(0, "checkpoint_size", MapConfig[mpCheckpointSize]);
        
    	cache_get_value_name(0, "gates_ids", buff);
    	sscanf(buff, "p<,>ii", MapConfig[mpGates][0], MapConfig[mpGates][1]);
    	
	    cache_get_value_name(0, "humans_coords", buff);
     	sscanf(buff, "p<,>ffffffffffff",
		 	MapConfig[mpHumanSpawnX][0], MapConfig[mpHumanSpawnY][0],
			MapConfig[mpHumanSpawnZ][0], MapConfig[mpHumanSpawnA][0],
		 	MapConfig[mpHumanSpawnX][1], MapConfig[mpHumanSpawnY][1],
		 	MapConfig[mpHumanSpawnZ][1], MapConfig[mpHumanSpawnA][1],
		 	MapConfig[mpHumanSpawnX][2], MapConfig[mpHumanSpawnY][2],
		 	MapConfig[mpHumanSpawnZ][2], MapConfig[mpHumanSpawnA][2]
		);
		
		cache_get_value_name(0, "zombies_coords", buff);
     	sscanf(buff, "p<,>ffffffffffff",
		 	MapConfig[mpZombieSpawnX][0], MapConfig[mpZombieSpawnY][0],
	 		MapConfig[mpZombieSpawnZ][0], MapConfig[mpZombieSpawnA][0],
		 	MapConfig[mpZombieSpawnX][1], MapConfig[mpZombieSpawnY][1],
	 		MapConfig[mpZombieSpawnZ][1], MapConfig[mpZombieSpawnA][1],
		 	MapConfig[mpZombieSpawnX][2], MapConfig[mpZombieSpawnY][2],
	 		MapConfig[mpZombieSpawnZ][2], MapConfig[mpZombieSpawnA][2]
		);
		
		cache_get_value_name(0, "npc_coords", buff);
     	sscanf(buff, "p<,>ffff",
		 	MapConfig[mpGangNPCSpawn][0], MapConfig[mpGangNPCSpawn][1],
	 		MapConfig[mpGangNPCSpawn][2], MapConfig[mpGangNPCSpawn][3]
	 	);
	 	
	 	cache_get_value_name(0, "checkpoint_coords", buff);
	 	sscanf(buff, "p<,>fff",
		 	MapConfig[mpCheckpointCoords][0],
	 	    MapConfig[mpCheckpointCoords][1],
		 	MapConfig[mpCheckpointCoords][2]
	 	);
		 
	 	cache_get_value_name(0, "camera_coords", buff);
 		sscanf(buff, "p<,>ffffff",
		 	MapConfig[mpCameraCoords][0], MapConfig[mpCameraCoords][1], MapConfig[mpCameraCoords][2],
		 	MapConfig[mpCameraLookAt][0], MapConfig[mpCameraLookAt][1], MapConfig[mpCameraLookAt][2]
	 	);

		cache_get_value_name(0, "gates_coords", buff);
 		sscanf(buff, "p<,>ffffffffffff",
		 	MapConfig[mpGatesCoords][0], MapConfig[mpGatesCoords][1], MapConfig[mpGatesCoords][2],
		 	MapConfig[mpGatesCoords][3], MapConfig[mpGatesCoords][4], MapConfig[mpGatesCoords][5],
		 	MapConfig[mpGatesCoords][6], MapConfig[mpGatesCoords][7], MapConfig[mpGatesCoords][8],
		 	MapConfig[mpGatesCoords][9], MapConfig[mpGatesCoords][10], MapConfig[mpGatesCoords][11]
	 	);
	 	
	 	cache_get_value_name(0, "gates_move_coords", buff);
 		sscanf(buff, "p<,>ffffffffffff",
		 	MapConfig[mpGatesMoveCoords][0], MapConfig[mpGatesMoveCoords][1], MapConfig[mpGatesMoveCoords][2],
		 	MapConfig[mpGatesMoveCoords][3], MapConfig[mpGatesMoveCoords][4], MapConfig[mpGatesMoveCoords][5],
		 	MapConfig[mpGatesMoveCoords][6], MapConfig[mpGatesMoveCoords][7], MapConfig[mpGatesMoveCoords][8],
		 	MapConfig[mpGatesMoveCoords][9], MapConfig[mpGatesMoveCoords][10], MapConfig[mpGatesMoveCoords][11]
	 	);
    
    	strmid(MapConfig[mpPrevFilename], MapConfig[mpFilename], 0, MAX_MAP_FILENAME);
    	
    	SetMapId();
    	StartMap();
    	SetMapName();
    	
    	LoadFilterScript(MapConfig[mpFilename]);
 	}
}

custom StartMap() {
	/*if(!MapConfig[mpIsStarted]) {
	    return 0;
	}*/
	
	static j;
	static author[64] = "";
	static controlled[96] = "";
	static formated[256];

	UnloadFilterScript(MapConfig[mpPrevFilename]);
	
	for( j = 0; j < MAX_MAP_GATES; j++ ) {
	    DestroyObjectEx(MapConfig[mpGates][j]);
	}
	
	foreach(Player, i) {
	    ClearPlayerRoundData(i);

     	SetPlayerTeamAC(i, TEAM_HUMAN);
    	DisablePlayerCheckpoint(i);
    	
    	if(IsPlayerInAnyVehicle(i)) {
    		RemovePlayerFromVehicle(i);
    	}
    	
    	if(GetPlayerState(i) == PLAYER_STATE_SPECTATING) {
    	    TogglePlayerSpectating(i, 0);
		}
		
		if(strlen(MapConfig[mpAuthor])) {
    		format(author, sizeof(author), "(by %s)", MapConfig[mpName]);
 		}

 		if(MapConfig[mpGang]) {
 	    	format(controlled, sizeof(controlled), "(captured by %s)", Gangs[MapConfig[mpGang]][gdName]);
 		}
    	
    	format(formated, sizeof(formated), "|: Entering The Map #%d %s %s %s", MapConfig[mpId], MapConfig[mpName], author, controlled);
	    SendClientMessage(i, 0xE48800FF, formated);
    	
    	if(MapConfig[mpInterior] <= 0) {
			SendClientMessage(i, 0xFFF000FF, "Creating objects...");
		}
		
		SpawnPlayer(i);
		SetCameraBehindPlayer(i);
	}
	
	// SetZombies();

    InitializePickups();
	
    MapConfig[mpIsStarted] = true;
    MapConfig[mpPaused] = false;
    
    MapConfig[mpTimeoutIgnoreTick] = 0;
    MapConfig[mpTimeout] = MAP_TIME;
    MapConfig[mpTimeoutBeforeEnd] = -MAP_UPDATE_TIME;
    MapConfig[mpTimeoutBeforeStart] = -MAP_UPDATE_TIME;
	return 1;
}

custom OnMapUpdate() {
	if(MapConfig[mpPaused]) {
	    return 0;
	}
	
	if(MapConfig[mpTimeoutIgnoreTick] > 0) {
	    MapConfig[mpTimeoutIgnoreTick]--;
	    return 0;
	}
	
	if(MapConfig[mpTimeoutBeforeStart] >= MAP_UPDATE_TIME) {
	    MapConfig[mpTimeoutBeforeStart] -= MAP_UPDATE_TIME;

	    if(MapConfig[mpTimeoutBeforeStart] == 0) {
	        LoadNewMap();
	    }
	}
	
	if(MapConfig[mpTimeoutBeforeEnd] >= MAP_UPDATE_TIME) {
	    MapConfig[mpTimeoutBeforeEnd] -= MAP_UPDATE_TIME;
	    
	    if(MapConfig[mpTimeoutBeforeEnd] == 0) {
	        EndMap();
	    }
	}
	
	if(MapConfig[mpTimeout] >= MAP_UPDATE_TIME) {
	    MapConfig[mpTimeout] -= MAP_UPDATE_TIME;
	    
	    static tm[4];
		format(tm,sizeof(tm), "%d", MapConfig[mpTimeout]);
		TextDrawSetString(TimeLeftTexture, tm);
	    
        if(MapConfig[mpTimeout] == 0) {
			TextDrawSetString(TimeLeftTexture, "...");

			if(MapConfig[mpGates][0]) {
				MoveObject(
					MapConfig[mpGates][0],
					MapConfig[mpGatesMoveCoords][0], MapConfig[mpGatesMoveCoords][1], MapConfig[mpGatesMoveCoords][2],
					MapConfig[mpGateSpeed],
					MapConfig[mpGatesMoveCoords][3], MapConfig[mpGatesMoveCoords][4], MapConfig[mpGatesMoveCoords][5]
				);
			}
			
			if(MapConfig[mpGates][1]) {
				MoveObject(
					MapConfig[mpGates][1],
					MapConfig[mpGatesMoveCoords][6], MapConfig[mpGatesMoveCoords][7], MapConfig[mpGatesMoveCoords][8],
					MapConfig[mpGateSpeed],
					MapConfig[mpGatesMoveCoords][9], MapConfig[mpGatesMoveCoords][10], MapConfig[mpGatesMoveCoords][11]
				);
			}

			foreach(Player, i) {
		    	SendClientMessage(i, 0xFF0000FF, ">> An evacuation has arrived for humans!");
				SendClientMessage(i, 0xFF0000FF, ">> Humans get to the checkpoint within a minute!");
				ShowCheckpoint(i);
			}
			
			MapConfig[mpTimeoutIgnoreTick] = 1;
			MapConfig[mpTimeoutBeforeEnd] = MAP_END_TIME;
 		}
	}
	
	return 1;
}

custom EndMap() {
    foreach(Player, i) {
    	SetPlayerCameraPos(i, MapConfig[mpCameraCoords][0], MapConfig[mpCameraCoords][1], MapConfig[mpCameraCoords][2]);
   		SetPlayerCameraLookAt(i, MapConfig[mpCameraLookAt][0], MapConfig[mpCameraLookAt][1], MapConfig[mpCameraLookAt][2]);
    	
		SendClientMessage(i, 0xFFFFFFFF, "Beginning new a round...");
		GameTextForPlayer(i, "~r~ROUND OVER~n~~w~STARTING NEW ROUND...", 5000, 5);
	}
	
	MapConfig[mpTimeoutIgnoreTick] = 1;
	MapConfig[mpTimeoutBeforeStart] = MAP_RESTART_TIME;
	MapConfig[mpIsStarted] = false;
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
	}
}

custom LoginOrRegister(const playerid) {
	Misc[playerid][mdKickForAuthTimeout] = (ServerConfig[svCfgAuthTimeout] * 60);

    if(cache_num_rows() > 0) {
		cache_get_value_name(0, "password", Misc[playerid][mdPassword]);
        cache_get_value_name_int(0, "id", Player[playerid][pAccountId]);
        cache_get_value_name_int(0, "language", Player[playerid][pLanguage]);
        cache_get_value_name_int(0, "points", Player[playerid][pPoints]);
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
        cache_get_value_name_int(0, "total_points", Achievements[playerid][achTotalPoints]);
        cache_get_value_name_int(0, "hours", Achievements[playerid][achHours]);
        cache_get_value_name_int(0, "minutes", Achievements[playerid][achMinutes]);
        cache_get_value_name_int(0, "seconds", Achievements[playerid][achSeconds]);
        cache_get_value_name_float(0, "ran", Achievements[playerid][achRan]);
        cache_get_value_name_int(0, "admin", Privileges[playerid][prsAdmin]);
        cache_get_value_name_int(0, "vip", Privileges[playerid][prsVip]);
        cache_get_value_name_int(0, "vip_till", Privileges[playerid][prsVipTill]);
        cache_get_value_name_int(0, "gang_id", Misc[playerid][mdGang]);
        cache_get_value_name_int(0, "gang_rank", Misc[playerid][mdGangRank]);
        cache_get_value_name_int(0, "gang_warns", Misc[playerid][mdGangWarns]);
        
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
	format(formated, sizeof(formated), cmd, MapConfig[mpName]);
	SendRconCommand(formated);
}

stock CheckToStartMap() {
    if(!MapConfig[mpIsStarted] && !MapConfig[mpPaused]) {
		LoadNewMap();
	}
}

stock ShowCheckpoint(const playerid) {
	SetPlayerCheckpoint(playerid,
		MapConfig[mpCheckpointCoords][0],
		MapConfig[mpCheckpointCoords][1],
		MapConfig[mpCheckpointCoords][2],
		MapConfig[mpCheckpointSize]
	);
}

stock LoadNewMap() {
	if((MapConfig[mpId]-1) > MapConfig[mpCount] || MapConfig[mpId] < 1) {
		MapConfig[mpId] = 1;
	}
	
	static const loadMapQuery[] = LOAD_MAP_DATA_QUERY;
	new formated[sizeof(loadMapQuery) + MAX_ID_LENGTH];
 	mysql_format(Database, formated, sizeof(formated), loadMapQuery, MapConfig[mpId]);
 	mysql_tquery(Database, formated, "LoadMap");
}


stock SetMapId() {
    if(MapConfig[mpId] < MapConfig[mpCount]) {
		MapConfig[mpId]++;
	} else {
		MapConfig[mpId] = 1;
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
	
	Misc[playerid][mdIsLogged] = true;
    SetPlayerTeamAC(playerid, TEAM_ZOMBIE);
   	SpawnPlayer(playerid);
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
	SetPlayerVirtualWorld(playerid, 1000 + playerid);
	
    ClearPlayerData(playerid);
    ClearPlayerPrevilegesData(playerid);
    ClearPlayerMiscData(playerid);
    ClearPlayerAchievementsData(playerid);
    ClearPlayerRoundData(playerid);
    ResetWeapons(playerid);
    
    SetPlayerHealthAC(playerid, 100.0);
    SetPlayerArmourAC(playerid, 0.0);
}

stock ClearPlayerData(const playerid) {
    Player[playerid][pAccountId] = 0;
    Player[playerid][pLanguage] = 0;
    Player[playerid][pPoints] = 0;
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

	    AliveInfoTexture[i] = TextDrawCreate(21.500000, 220.000000, "~b~humans: 0~n~~g~zombies: 0");
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
	    MapConfig[mpGates][j] = INVALID_OBJECT_ID;
	}
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
		Misc[playerid][mdSpawnPoints][i] = CreatePlayer3DTextLabel(playerid, "{FFFFFF}Zombie Spawn\ndo{FF0000} not{FFFFFF} shoot zombies here", 0xFF0000FF, MapConfig[mpZombieSpawnX][i], MapConfig[mpZombieSpawnY][i], MapConfig[mpZombieSpawnZ][i], 50.0);
	}
}

stock GetPlayerTeamEx(const playerid) {
	return Misc[playerid][mdPlayerTeam];
}

stock SetPlayerTeamAC(const playerid, const teamid) {
	switch(teamid) {
	    case TEAM_ZOMBIE: {
			MapConfig[mpTeamCount][0]++;
			
			if(GetPlayerTeamEx(playerid) == TEAM_HUMAN) {
				MapConfig[mpTeamCount][1]--;
			}
		}
	    case TEAM_HUMAN: {
			MapConfig[mpTeamCount][1]++;
			
			if(GetPlayerTeamEx(playerid) == TEAM_ZOMBIE) {
				MapConfig[mpTeamCount][0]--;
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
			SetPlayerPos(playerid, 	MapConfig[mpZombieSpawnX][point] + distance, MapConfig[mpZombieSpawnY][point] + distance, MapConfig[mpZombieSpawnZ][point]);
			SetPlayerFacingAngle(playerid, MapConfig[mpZombieSpawnA][point]);
			SetCameraBehindPlayer(playerid);
		}
	    case TEAM_HUMAN: {
			SetHuman(playerid, current);
			SetPlayerPos(playerid, 	MapConfig[mpHumanSpawnX][point] + distance, MapConfig[mpHumanSpawnY][point] + distance, MapConfig[mpHumanSpawnZ][point]);
			SetPlayerFacingAngle(playerid, MapConfig[mpHumanSpawnA][point]);
			SetCameraBehindPlayer(playerid);
  		}
	}
	
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
	switch(GetPlayerTeamEx(playerid)) {
	    case TEAM_HUMAN: {
            switch(Pickups[pickupid][pcd_model]) {
	    		case M4_PICKUP: GivePlayerWeaponAC(playerid, 31, 100);
			}
	    }
	}

	return 1;
}

stock CreateDropOnDeath(const playerid, const killerid) {
	new Float:pos[3];
	new type[4] = { M4_PICKUP, BULLETS_PICKUP, MEAT_PICKUP, -1 };
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
	 	Pickups[id][pcd_protection_till] = gettime() + 30;
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
    SetPlayerVirtualWorld(playerid, 0);
}

stock SetHuman(const playerid, const classid) {
    SetPlayerColor(playerid, COLOR_HUMAN);
    SetPlayerVirtualWorld(playerid, 0);
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
