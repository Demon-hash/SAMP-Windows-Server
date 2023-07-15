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
	SKILLS_TEMPLATE, BALANCE_CONFIG_TEMPLATE, TEXTURES_CONFIG_TEMPLATE,
	MAPS_LOCALIZATION_TEMPLATE, CLASSES_LOCALIZATION_TEMPLATE,
	BANIP_LOG_TEMPLATE, VOTEKICK_LOG_TEMPLATE, CLASSES_CONFIG_TEMPLATE,
	RANDOM_MESSAGES_TEMPLATE, RANDOM_MESSAGES_TEMPLATE, OBJECTS_TEMPLATE
};

static const sqlPredifinedValues[][] = {
    PREDIFINED_CONFIG, PREDIFINED_GANGS_CONFIG, PREDIFINED_ANTICHEAT,
    PREDIFINED_MAPS, PREDIFINED_ROUND_CONFIG, PREDIFINED_EVAC_CONFIG,
	PREDIFINED_MAP_CONFIG, PREDIFINED_BALANCE_CONFIG, PREDIFINED_TEXTURES,
	PREDIFINED_HUMANS, PREDIFINED_ZOMBIES, PREDIFINED_WEAPONS,
	PREDIFINED_LOCAL_MAPS, PREDIFINED_LOCALE_CLASSES_10,
	PREDIFINED_LOCALE_CLASSES_20, PREDIFINED_LOCALE_CLASSES_30,
	PREDIFINED_LOCALE_CLASSES_40, PREDIFINED_CLASSES_CONFIG,
	PREDIFINED_RND_MSGS, PREDIFINED_OBJECTS
};

static const LOCALIZATION_TABLES[][] = {
    ENGLISH_LOCALE, RUSSIAN_LOCALE
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

static ServerTextures[TEXTURES_DATA];
static ServerTexturesConfig[MAX_SERVER_TEXTURES][TEXTURES_CONFIG_DATA];

static Classes[MAX_CLASSES][CLASSES_DATA];
static ClassesConfig[CLASSES_CONFIG_DATA];
static ClassesSelection[MAX_PLAYERS][MAX_CLASSES][CLASSES_SELECTION_DATA];
static AbilitiesTimers[MAX_PLAYERS][ABLITY_MAX];

static AnticheatConfig[1];
static ServerConfig[CONFIG_DATA];
static ServerBalance[BALANCE_DATA];
static Pickups[MAX_PICKUPS][PICKUP_DATA];
static EvacuationConfig[EVACUATION_CONFIG_DATA];
static WeaponsConfig[MAX_WEAPONS][WEAPONS_CONFIG_DATA];
static Localization[MAX_PLAYERS][LOCALIZATION_DATA][LOCALIZATION_LINE_SIZE];
static LocalizedTips[MAX_PLAYERS][TIP_MSG_MAX][LOCALIZATION_LINE_SIZE];

static
    	Float:Polygon[RECTANGLE][POINT] = { { 0.0, 0.0 }, ... },
		MySQL:Database, updateTimerId, Iterator:Humans<MAX_PLAYERS>,
		Iterator:Zombies<MAX_PLAYERS>, Iterator:MutatedPlayers<MAX_PLAYERS>,
		Iterator:RadioactivePlayers<MAX_PLAYERS>, Iterator:NursePlayers<MAX_PLAYERS>,
		Iterator:PriestPlayers<MAX_PLAYERS>, Iterator:SupportPlayers<MAX_PLAYERS>,
		Iterator:RemoveWeaponsPlayers<MAX_PLAYERS>;

/*
	Random Question for %d Points:
	What is the name of the planet closest to the sun?",
	Which country has a plain green flag?",
	What causes craters on the moon?",
	The sunniest figure in geometry?",
	This month is called summer sunset. Which one?",
	What chemical element caused the death of Napoleon?",
	Where did the accordion first appear?",
	The deepest freshwater lake in the world?",
	What is the name of the water shell of the earth?",
	Which bird is called the forest doctor?",
	The highest point, above sea level, in Africa?",
	Gas, which is formed during photosynthesis of plants?",
	What month does Australia start in autumn?",
	What besides flags often fans wave in the stands?",
	Which US president wrote his own story about Sherlock Holmes?",
	Which of the famous artists in his life sold just one painting?",
	How many eyes does an ordinary fly have?",
	Every day, the Earth adds 400 tons in weight. Due to what?",
	What stones are not in the sea?",
	Which wheel does not spin in a right turn?"
*/

/*
	MAIN
	- Settings
	- Random questions
	- Shop
	- Achievements
	- Attachements
	- Commands & Gangs
	- SaveUserData
	- Anticheat
	- Promo codes
	- Custom tags
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

#define GANG_CONTROL_TEXT "{FFFFFF}%s\n\
		 {FFF000}Controlled by {FFFFFF}%s\n\
		 {FFF000}Captured at {FFFFFF}%02d:%02d {FFF000}on {FFFFFF}%02d/%02d/%d\n\
		 {FFF000}This gang dealt the most damage to capture the map\n\
		 {FFF000}The gang members get extra points for the following actions:\n\n\
		 {FFFFFF}+%.0f{FFF000} point(s) in gang pot for evacuating\n\
		 {FFFFFF}+%.0f{FFF000} point(s) in gang pot for curing humans\n\
		 {FFFFFF}+%.0f{FFF000} point(s) in gang pot for active ability using\n\
		 {FFFFFF}+%.0f{FFF000} point(s) in gang pot for killing players\n\
		 {FFFFFF}+%.2f{FFF000} point(s) in gang pot for assist\n\n\
		 >> All zombies have 200 HP <<\
		 "
		 
#define CRYSTAL_STONE_TEXT "CRYSTAL STONE\n{FFFFFF}>> %.0f <<{FFF000}\nDestroy this crystal to capture the map, only gang members can deal damage\nDamage dealt depends on rank"

#define SV_CFG_CONSOLE_LOG "(1): Server configuration"
#define GS_CFG_CONSOLE_LOG "(2): Gangs configuration"
#define RD_CFG_CONSOLE_LOG "(3): Round configuration"
#define EVC_CFG_CONSOLE_LOG "(4): Evacuation configuration"
#define MAP_CFG_CONSOLE_LOG "(5): Map configuration"
#define WPS_CFG_CONSOLE_LOG "(6): Weapons configuration"
#define BLC_CFG_CONSOLE_LOG "(7): Balance configuration"
#define TEX_CFG_CONSOLE_LOG "(8): Textures configuration"
#define CLS_CFG_CONSOLE_LOG "(9): Classes configuration"

main() {
	printf("%d", ABILITY_CURE);
}

public OnGameModeInit() {
	InitializePickups();
 	InitializeClassesData();
	InitializeWeaponsData();
	InitializeDefaultValues();
	
	Iter_Clear(MutatedPlayers);
	Iter_Clear(RadioactivePlayers);
	Iter_Clear(NursePlayers);
	Iter_Clear(PriestPlayers);
	Iter_Clear(SupportPlayers);
	Iter_Clear(RemoveWeaponsPlayers);
	Iter_Clear(Humans);
	Iter_Clear(Zombies);
	
	SetGameModeText("Zombies");
	ShowPlayerMarkers(PLAYER_MARKERS_MODE_GLOBAL);
    ShowNameTags(1);
	SetTeamCount(MAX_PLAYER_TEAMS);
	DisableInteriorEnterExits();
	EnableStuntBonusForAll(0);
	AllowInteriorWeapons(1);
	
	Database = mysql_connect(SQL_HOST, SQL_USER, SQL_PASS, SQL_DB);
    mysql_set_charset(GLOBAL_CHARSET);
	new i, year, mounth, day, hours, minutes, seconds;
	for(i = 0; i < sizeof(sqlTemplates); i++) mysql_tquery(Database, sqlTemplates[i]);
	for(i = 0; i < sizeof(sqlPredifinedValues); i++ ) mysql_tquery(Database, sqlPredifinedValues[i]);

	mysql_tquery(Database, PREDIFINED_LOCALIZATION_1);
	mysql_tquery(Database, PREDIFINED_LOCALIZATION_2);
	mysql_tquery(Database, PREDIFINED_LOCALIZATION_3);
	mysql_tquery(Database, PREDIFINED_LOCALIZATION_4);
	mysql_tquery(Database, PREDIFINED_LOCALIZATION_5);

    mysql_set_charset(LOCAL_CHARSET);
	mysql_tquery(Database, LOAD_SERVER_CFG_QUERY, "LoadServerConfiguration");
	mysql_tquery(Database, LOAD_GANGS_CFG_QUERY, "LoadGangsConfiguration");
	mysql_tquery(Database, LOAD_ROUND_CFG_QUERY, "LoadRoundConfiguration");
	mysql_tquery(Database, LOAD_EVAC_CFG_QUERY, "LoadEvacConfiguration");
	mysql_tquery(Database, LOAD_MAP_CFG_QUERY, "LoadMapConfiguration");
	mysql_tquery(Database, LOAD_WEAPONS_CFG_QUERY, "LoadWeaponsConfiguration");
	mysql_tquery(Database, LOAD_BALANCE_CFG_QUERY, "LoadBalanceConfiguration");
	mysql_tquery(Database, LOAD_TEXTURES_CFG_QUERY, "LoadTexturesConfiguration");
	mysql_tquery(Database, LOAD_CLASSES_CFG_QUERY, "LoadClassesConfiguration");
	
	mysql_tquery(Database, LOAD_CLASSES_QUERY, "LoadClasses");
	mysql_tquery(Database, LOAD_MAPS_COUNT_QUERY, "LoadMapsCount");
	mysql_tquery(Database, LOAD_OBJECTS_QUERY, "LoadObjects");
	
 	mysql_log(SQL_LOG_LEVEL);
 	
	TimestampToDate(gettime(), year, mounth, day, hours, minutes, seconds, SERVER_TIMESTAMP);
	printf("Started at %02d:%02d:%02d on %02d/%02d/%d... | Status: %d", hours, minutes, seconds, day, mounth, year, mysql_errno(Database));
	printf("JIT is %spresent", IsJITPresent() ? ("") : ("not "));
	updateTimerId = SetTimer("Update", 1000, true);
	
	return 1;
}

public OnGameModeExit() {
    mysql_close(Database);
	KillTimer(updateTimerId);
	UnloadFilterScript(Map[mpFilename]);
	DestroyScreenTextures();
	return 1;
}

public OnPlayerConnect(playerid) {
    ClearAllPlayerData(playerid);
    CheckForAccount(playerid);
    
    new formated[90];
    foreach(Player, i) {
        if(i == playerid) continue;
        format(formated, sizeof(formated), Localization[i][LD_MSG_CONNECT], Misc[playerid][mdPlayerName], playerid);
        SendClientMessage(i, 0xC0C0C0FF, formated);
    }
    return 1;
}

public OnPlayerDisconnect(playerid, reason) {
    ResetMapValuesOnDeath(playerid);
    ResetValuesOnDisconnect(playerid);
	
    new formated[90];
    foreach(Player, i) {
        format(formated, sizeof(formated), Localization[i][LD_MSG_DISCONNECT], Misc[playerid][mdPlayerName], Localization[i][LD_MSG_TIMEOUT + LOCALIZATION_DATA:reason]);
        SendClientMessage(i, 0xC0C0C0FF, formated);
    }
	return 1;
}

public OnPlayerRequestClass(playerid, classid) {
    SetPlayerVirtualWorld(playerid, 1000 + playerid);

    SetSpawnInfo(
		playerid, TEAM_UNKNOWN, ServerConfig[svCfgPreviewBot],
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
	
	CheckPlayerForOOM(playerid);
	SetPlayerScore(playerid, Achievements[playerid][achRank]);
	return 1;
}

public OnPlayerDeath(playerid, killerid, reason) {
	if(!IsPlayerConnected(playerid)) {
	    return 0;
	}
	
	if(!IsPlayerConnected(killerid) && IsPlayerConnected(Misc[playerid][mdLastIssuedDamage])) {
	    killerid = Misc[playerid][mdLastIssuedDamage];
    	reason = Misc[playerid][mdLastIssuedReason];
	}

    reason = clamp(reason, WEAPON_FISTS, WEAPON_COLLISION);
	SendDeathMessage(killerid, playerid, reason);
	
	if(IsPlayerConnected(killerid)) {
	    IncreaseWeaponSkillLevel(killerid, reason);
	    
	    if(!Map[mpFirstBlood]) {
	        RoundSession[killerid][rdAdditionalPoints] += MapConfig[mpCfgFirstBlood];
	        Map[mpFirstBlood] = true;
	        
		 	new formated[128];
		 	foreach(Player, i) {
		 		format(formated, sizeof(formated), Localization[i][LD_MSG_FIRST_BLOOD], Misc[killerid][mdPlayerName], Localization[i][LD_MSG_POINTS_MULTIPLE]);
		 		SendClientMessage(i, 0xFF0000FF, formated);
		 	}
	    }
	    
    	if(Map[mpKillTheLast] && GetPlayerTeamEx(playerid) == TEAM_HUMAN) {
    	    RoundSession[killerid][rdAdditionalPoints] += MapConfig[mpCfgKillLast];
    	    
    	    new formated[128];
		 	foreach(Player, i) {
		 		format(formated, sizeof(formated), Localization[i][LD_MSG_KILLED_THE_LAST], Misc[killerid][mdPlayerName], Localization[i][LD_MSG_POINTS_MULTIPLE]);
		 		SendClientMessage(i, 0xFF0000FF, formated);
		 	}
    	}
	    
	    if(IsAbleToGivePointsInCategory(killerid, SESSION_KILL_POINTS)) {
	        RoundSession[killerid][rsdKilling] += RoundConfig[rdCfgKilling];
	    }
	}
	
	if(Round[playerid][rdIsHumanHero]) {
	    Round[playerid][rdIsHumanHero] = false;
	    
	    if(IsPlayerConnected(killerid)) {
	    	RoundSession[killerid][rdAdditionalPoints] += MapConfig[mpCfgHumanHeroPoints];
	    	
	    	new formated[96];
		 	foreach(Player, i) {
		 		format(formated, sizeof(formated), Localization[i][LD_MSG_HUMAN_HERO_KILLED], Misc[killerid][mdPlayerName]);
		 		SendClientMessage(i, 0xFF0000FF, formated);
		 	}
		}
	}
	
	if(Round[playerid][rdIsZombieBoss]) {
	    Round[playerid][rdIsZombieBoss] = false;
	    
	    if(IsPlayerConnected(killerid)) {
	        RoundSession[killerid][rdAdditionalPoints] += MapConfig[mpCfgZombieBossPoints];
	        
	        new formated[96];
		 	foreach(Player, i) {
		 		format(formated, sizeof(formated), Localization[i][LD_MSG_ZOMBIE_BOSS_KILLED], Misc[killerid][mdPlayerName]);
		 		SendClientMessage(i, 0xFF0000FF, formated);
		 	}
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
			SetVehicleHealth(hitid, hp - ServerConfig[svCfgVehicleDamage]);
	    }
	    case BULLET_HIT_TYPE_PLAYER: {
            if(!IsPlayerConnected(hitid)) {
				return 0;
			}
			
            if(gettime() < Misc[hitid][mdSpawnProtection] || GetObjectModel(GetPlayerSurfingObjectID(playerid)) == ClassesConfig[clsCfgEngineerBox]) {
            	SetPlayerChatBubble(hitid, Localization[playerid][LD_ANY_MISS], BUBBLE_COLOR, 20.0, 1000);
				return 0;
            }
            
            if(GetPlayerTeamEx(hitid) == TEAM_ZOMBIE && GetPlayerArmourEx(hitid) > 0.0) {
			    switch(weaponid) {
			        case 24, 33, 34: return 1;
			    }
				    
			    SetPlayerChatBubble(hitid, Localization[playerid][LD_ANY_MISS], BUBBLE_COLOR, 20.0, 1000);
			    return 0;
            }
            
            if(GetPlayerTeamEx(playerid) == TEAM_ZOMBIE && GetPlayerTeamEx(hitid) == TEAM_HUMAN && weaponid == ClassesConfig[clsCfgSpitterWeapon]) {
                ProceedPassiveAbility(playerid, ABILITY_SPITTER, hitid);
                return 0;
			}
	    }
	    case BULLET_HIT_TYPE_OBJECT: {
			if(GetObjectModel(hitid) == ClassesConfig[clsCfgEngineerBox]) {
			    for( new i = 0; i < MAX_ROUND_BOXES; i++ ) {
			        if(Round[playerid][rdBox][i] == hitid) {
						DestroyObjectEx(Round[playerid][rdBox][i]);
						Delete3DTextLabelEx(Round[playerid][rdBoxText][i]);
						return 1;
					}
				}
			}
	    
	        /*if(hitid == Map[mpCrystal] && Misc[playerid][mdGangRank]) {
	            Map[mpCrystalHealth] -= float(max(1, Achievements[playerid][achRank]));
	            
	        	new text[256];
				format(text, sizeof(text), CRYSTAL_STONE_TEXT, Map[mpCrystalHealth]);
				Update3DTextLabelText(Map[mpFlagText], 0xFFF000FF, text);
	        }*/
	    }
	}
	
	return 1;
}

public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger) {
    if(Privileges[playerid][prsAdmin] < 1) {
        new Float:pos[3];
        ClearAnimations(playerid);
        GetPlayerVelocity(playerid, pos[0], pos[1], pos[2]);
		SetPlayerVelocity(playerid, pos[0], pos[1], pos[2] + 0.2);
    }
    return 1;
}

public OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid, bodypart) {
	if(IsPlayerConnected(damagedid)) {
	    Misc[damagedid][mdLastIssuedDamage] = playerid;
	    Misc[damagedid][mdLastIssuedReason] = weaponid;
	
        if( weaponid == 0 && GetPlayerTeamEx(playerid) == TEAM_ZOMBIE  && GetPlayerTeamEx(damagedid) == TEAM_HUMAN) {
			if(GetPlayerArmourEx(damagedid) > 0.0) {
			    SetPlayerArmourAC(damagedid, GetPlayerArmourEx(damagedid) - ServerConfig[svCfgZombieFistsDamage]);
			    return 1;
			}

			SetPlayerHealthAC(damagedid, GetPlayerHealthEx(damagedid) - ServerConfig[svCfgZombieFistsDamage]);
			return 1;
    	}
	}
	
    return 1;
}

public OnPlayerTakeDamage(playerid, issuerid, Float: amount, weaponid, bodypart) {
	if(!IsPlayerConnected(playerid) || !IsPlayerConnected(issuerid)) {
	    return 1;
	}

	if(GetPlayerTeamEx(playerid) == GetPlayerTeamEx(issuerid)) {
	    if(Misc[playerid][mdMimicry][2] > -1) {
	        GameTextForPlayer(playerid, RusToGame(Localization[playerid][LD_DISLPAY_FAKE_CLASS]), 1000, 5);
	    }
	    
	    return 1;
	}

	if(IsAbleToGivePointsInCategory(issuerid, SESSION_HIT_POINTS) && weaponid == RoundConfig[rdCfgBrutalityWeapon]) {
        RoundSession[issuerid][rsdBrutality] += RoundConfig[rdCfgBrutality];
	}
	
	if(GetPlayerTeamEx(playerid) == TEAM_ZOMBIE) {
		for( new j = 0; j < sizeof(Map[mpZombieSpawnX]); j++ ) {
			if(IsPlayerInRangeOfPoint(playerid, ServerConfig[svCfgSpawnRange], Map[mpZombieSpawnX][j], Map[mpZombieSpawnX][j], Map[mpZombieSpawnX][j])) {
			    SetPlayerHealthAC(issuerid, GetPlayerHealthEx(issuerid) - amount);
  				return 1;
			}
		}
		
		ProceedPassiveAbility(playerid, ABILITY_SPORE, issuerid);
		
		if(bodypart != ServerConfig[svCfgExcludedMirrorPart]) {
			ProceedPassiveAbility(playerid, ABILITY_MIRROR, issuerid, amount);
		}
	}
	
	if(weaponid == ServerConfig[svCfgRifle]) {
		ProceedPassiveAbility(issuerid, ABILITY_CURE, playerid);
		ProceedPassiveAbility(issuerid, ABILITY_POISON, playerid);
	}

    ShowDamageTaken(playerid, amount);
	return 1;
}

public OnPlayerEnterCheckpoint(playerid) {
	if(GetPlayerTeamEx(playerid) != TEAM_HUMAN || Round[playerid][rdIsEvacuated] || GetPlayerVirtualWorld(playerid) > 0) {
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
	CurePlayer(playerid);
	SetPlayerColor(playerid,COLOR_EVACUATED);
	Round[playerid][rdIsEvacuated] = true;
	
	++Map[mpEvacuatedHumans];
	
	new formated[90];
	foreach(Player, i) {
 		format(formated, sizeof(formated), Localization[i][LD_MSG_EVACUATED], Misc[playerid][mdPlayerName]);
 		SendClientMessage(i, 0xFFF000FF, formated);

		if(Map[mpEvacuatedHumans] == Map[mpTeamCount][1]) {
            SendClientMessage(i, 0xFFF000FF, Localization[i][LD_MSG_ALL_EVACUATED]);
 		}
 	}
 	
 	if(Map[mpTeamCount][1] == 1) {
 		RoundSession[playerid][rdAdditionalPoints] += MapConfig[mpCfgLastEvacuated];
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
        ProceedClassAbilityActivation(playerid);
        return 1;
	}
	
	if(KEY(KEY_JUMP)) {
	    if(Round[playerid][rdIsLegsBroken]) {
			ApplyAnimation(playerid, "PED", "getup_front", 4.1, 0, 0, 0, 0, 0);
			return 1;
		}
		
		return 1;
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
	    case DIALOG_CLASSES: {
	        if(!response) {
	            return 1;
	        }
	        
	        ProceedClassSelection(playerid, listitem, 1);
	        return 1;
	    }
	    case DIALOG_SELECTION: {
	        if(!response || Misc[playerid][mdSelectionTeam] == -1) {
	            Misc[playerid][mdSelectionTeam] = -1;
	            cmd::class(playerid);
	            return 1;
	        }
	        
	        new formated[90], i;
	        for( i = 0; i < MAX_CLASSES; i++ ) {
	            if(Classes[i][cldId] == ClassesSelection[playerid][listitem][csdId]) {
	                if(Achievements[playerid][achTotalPoints] < Classes[i][cldPoints]) {
	                    format(formated, sizeof(formated), Localization[playerid][LD_MSG_NOT_ENOUGH_FOR_CLASS], Classes[i][cldPoints], Localization[playerid][LD_MSG_POINTS]);
	                    SendClientMessage(playerid, 0xFF0000FF, formated);
	                    return 1;
	                }
	                
	                ProocedClassChange(playerid, i, Misc[playerid][mdSelectionTeam], listitem);
	                return 1;
	            }
	        }
	        
	        Misc[playerid][mdSelectionTeam] = -1;
         	cmd::class(playerid);
	        return 1;
	    }
	}
	
	return 1;
}

public OnPlayerPickUpPickup(playerid, pickupid) {
    if(IsAbleToPickup(playerid, pickupid)) {
    	ProceedPickupAction(playerid, pickupid);
     	DestroyPickupEx(pickupid);
	} else if(IsValidPickupEx(pickupid)) {
	    new tip[64];
	    format(tip, sizeof(tip), Localization[playerid][LD_MSG_PICKUP_PROTECTION], max(0, Pickups[pickupid][pcdProtectionTill] - gettime()));
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
	
	static currentHour, currentMinute, currentSecond, tip, formated[90];
	gettime(currentHour, currentMinute, currentSecond);
	tip = PrepareRandomTip();

	foreach(Player, playerid) {
	    if(ProceedAuthTimeoutKick(playerid)) continue;
	    CheckAndNormalizeACValues(playerid, hp, armour);
	    
	    if(Misc[playerid][mdIsLogged]) {
    		format(formated, sizeof(formated),"%.0f", Player[playerid][pPoints]);
    		TextDrawSetString(ServerTextures[pointsTexture][playerid], formated);
    		
    		format(formated, sizeof(formated), RusToGame(Localization[playerid][LD_DISPLAY_ALIVE_INFO]), Map[mpTeamCount][1], Map[mpTeamCount][0]);
            TextDrawSetString(ServerTextures[aliveInfoTexture][playerid], formated);
            
            ProceedRandomTip(playerid, tip, formated);
            ProceedInfection(playerid);
            ProceedBlind(playerid);
            ProceedSpaceDamage(playerid);
            ProceedUnfreeze(playerid);
            ProceedRecoveryLongJumps(playerid);
            ProceedMimicryChangeBack(playerid);
            ProceedPassiveAbility(playerid, ABILITY_REGENERATOR);
            
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
        printf("(8): Loaded %d maps in total", Map[mpCount]);
        return 1;
    }
    
	printf("(8): Loading maps failed");
	return 0;
}

custom LoadClasses() {
    if(cache_num_rows()) {
        new i, len = clamp(cache_num_rows(), 0, MAX_CLASSES);
        for( i = 0; i < len; i++ ) {
            cache_get_value_name_int(i, "id", Classes[i][cldId]);
			cache_get_value_name_int(i, "team", Classes[i][cldTeam]);
			cache_get_value_name_int(i, "skin", Classes[i][cldSkin]);
			cache_get_value_name_int(i, "cooldown", Classes[i][cldCooldown]);
			cache_get_value_name_int(i, "time", Classes[i][cldAbilityTime]);
			cache_get_value_name_int(i, "count", Classes[i][cldAbilityCount]);
			
            cache_get_value_float(i, "points", Classes[i][cldPoints]);

            cache_get_value_name(i, "ability", Classes[i][cldAbility]);
			cache_get_value_name(i, "immunity", Classes[i][cldImmunity]);
			cache_get_value_name(i, "weapons", Classes[i][cldWeapons]);

			cache_get_value_name_float(i, "health", Classes[i][cldHealth]);
			cache_get_value_name_float(i, "armour", Classes[i][cldArmour]);
			cache_get_value_name_float(i, "distance", Classes[i][cldDistance]);
			cache_get_value_name_float(i, "points", Classes[i][cldPoints]);
		}
		
		printf("(8): Classes loaded (%d / %d)", i, len);
        return 1;
    }
    
    printf("(8): Loading classes failed");
	return 0;
}

custom LoadObjects() {
	if(cache_num_rows()) {
	    new i, len = cache_num_rows(), model, position[6], buff[96];
    	for( i = 0; i < len; i++ ) {
    	    cache_get_value_name(i, "coords", buff);
    		cache_get_value_name_int(i, "model", model);
    		
    		sscanf(buff, "p<,>ffffff",
				position[0], position[1], position[2],
				position[3], position[4], position[5]
			);
			
			CreateObject(
				model,
				position[0], position[1], position[2],
				position[3], position[4], position[5]
			);
		}
		
		printf("%d objects loaded", len);
		return 1;
 	}
 	
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
	    cache_get_value_name_int(0, "crystal_id", Map[mpGangCrystalId]);
	    cache_get_value_name_int(0, "flag_date", Map[mpFlagDate]);
	    
	    cache_get_value_name(0, "polygon", buff);
	 	sscanf(buff, "p<,>ffffffff",
		 	Polygon[0][_ptX_], Polygon[0][_ptY_],
		 	Polygon[1][_ptX_], Polygon[1][_ptY_],
		 	Polygon[2][_ptX_], Polygon[2][_ptY_],
		 	Polygon[3][_ptX_], Polygon[3][_ptY_]
		);
    	
    	cache_get_value_name(0, "login", Map[mpAuthor]);
        cache_get_value_name(0, "filename", Map[mpFilename]);
        
        cache_get_value_name_float(0, "gates_speed", Map[mpGateSpeed]);
    	cache_get_value_name_float(0, "checkpoint_size", Map[mpCheckpointSize]);
        
    	cache_get_value_name(0, "gates_ids", buff);
    	sscanf(buff, "p<,>ii", Map[mpGates][0], Map[mpGates][1]);
    	
    	cache_get_value_name(0, "crystal_coords", buff);
     	sscanf(buff, "p<,>ffff",
		 	Map[mpGangCrystalSpawn][0], Map[mpGangCrystalSpawn][1],
     		Map[mpGangCrystalSpawn][2], Map[mpGangCrystalSpawn][3]
 		);
 		
 		cache_get_value_name(0, "near_crystal_coords", buff);
     	sscanf(buff, "p<,>ffff",
		 	Map[mpGangNearCrystalSpawn][0], Map[mpGangNearCrystalSpawn][1],
     		Map[mpGangNearCrystalSpawn][2], Map[mpGangNearCrystalSpawn][3]
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
    	
    	LoadFilterScript(Map[mpFilename]);
		
		DestroyObjectEx(Map[mpCrystal]);
		DestroyObjectEx(Map[mpFlag]);
		// Delete3DTextLabelEx(Map[mpFlagText]);
		
		if(Map[mpGang]) {
            TimestampToDate(Map[mpFlagDate], year, mounth, day, hours, minutes, seconds, SERVER_TIMESTAMP);
			Map[mpFlag] = CreateObject(GangsConfig[gdCfgFlagId],
			   	Map[mpFlagCoords][0], Map[mpFlagCoords][1],
	     		Map[mpFlagCoords][2], Map[mpFlagCoords][3],
	     		Map[mpFlagCoords][4], Map[mpFlagCoords][5], 50.0
			);

			/*new text[768];
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
			*/
		}
	 }
}

custom StartMap() {
	new j;
	new author[64] = "";
	new controlled[96] = "";
	new formated[256];

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
    		format(author, sizeof(author), Localization[i][LD_MSG_MAP_AUTHOR], Map[mpAuthor]);
 		}

 		if(Map[mpGang]) {
 	    	format(controlled, sizeof(controlled), Localization[i][LD_MSG_MAP_GANG], Gangs[Map[mpGang]][gdName]);
 		}
    	
    	format(formated, sizeof(formated), Localization[i][LD_MSG_MAP_ENTERING], Map[mpId], Localization[i][LD_MAP_NAME], author, controlled);
	    SendClientMessage(i, 0xE48800FF, formated);
    	
    	if(Map[mpInterior] <= 0) {
			SendClientMessage(i, 0xFFF000FF, Localization[i][LD_MSG_MAP_CREATE_OBJECTS]);
		}
	}
	
	SetTeams();
    InitializePickups();
	
    Map[mpIsStarted] = true;
    Map[mpPaused] = false;
    Map[mpTimeoutBeforeCrystal] = false;
    Map[mpFirstBlood] = false;
    Map[mpKillTheLast] = false;
    
    Map[mpTimeoutIgnoreTick] = 0;
    Map[mpEvacuatedHumans] = 0;
    Map[mpTimeout] = MapConfig[mpCfgTotal];
    Map[mpTimeoutBeforeEnd] = -MapConfig[mpCfgUpdate];
    Map[mpTimeoutBeforeStart] = -MapConfig[mpCfgUpdate];
    Map[mpCrystalHealth] = GangsConfig[gdCfgCrystalHealth];
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
	
	if(ServerConfig[svCfgCurrentOnline] >= ServerConfig[svCfgMinZombiesToWin] && Map[mpTeamCount][1] <= 0 && Map[mpIsStarted] && !Map[mpTimeoutBeforeCrystal]) {
	    foreach(Player, i) {
			SendClientMessage(i, 0xf21822FF, Localization[i][LD_MSG_MAP_ZOMBIES_WIN]);
 		}
 		
	    Map[mpTimeoutBeforeEnd] = MapConfig[mpCfgUpdate];
	}
	
	if(Map[mpTimeoutBeforeEnd] >= MapConfig[mpCfgUpdate]) {
	    Map[mpTimeoutBeforeEnd] -= MapConfig[mpCfgUpdate];
	    
	    if(Map[mpTimeoutBeforeEnd] == 0) {
	        if(!SpawnCrystalOnMapEnd()) {
                EndMap();
	        }
	    }
	}
	
	if(Map[mpTimeout] >= MapConfig[mpCfgUpdate]) {
	    Map[mpTimeout] -= MapConfig[mpCfgUpdate];
	    
	    static tm[4];
		format(tm,sizeof(tm), "%d", Map[mpTimeout]);
		TextDrawSetString(ServerTextures[timeLeftTexture], tm);
	    
        if(Map[mpTimeout] == 0) {
			TextDrawSetString(ServerTextures[timeLeftTexture], "...");

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
		    	SendClientMessage(i, 0xf21822FF, Localization[i][LD_MSG_MAP_EVAC_ARRIVED]);
				SendClientMessage(i, 0xf21822FF, Localization[i][LD_MSG_MAP_EVAC_GETTO]);
				ShowCheckpoint(i);
			}
			
			Map[mpTimeoutIgnoreTick] = 1;
			Map[mpTimeoutBeforeEnd] = MapConfig[mpCfgEnd];
 		}
	}
	
	
	foreach(Humans, targetid) {
	    foreach(MutatedPlayers, playerid) {
 			ProceedPassiveAbility(playerid, ABILITY_MUTATED, targetid);
		}
		
		foreach(RadioactivePlayers, playerid) {
 			ProceedPassiveAbility(playerid, ABILITY_RADIOACTIVE, targetid);
		}
		
		foreach(NursePlayers, playerid) {
 			ProceedPassiveAbility(playerid, ABILITY_CURE_FIELD, targetid);
		}
		
		foreach(PriestPlayers, playerid) {
 			ProceedPassiveAbility(playerid, ABILITY_HOLY_FIELD, targetid);
		}
		
		foreach(RemoveWeaponsPlayers, playerid) {
 			ProceedPassiveAbility(playerid, ABILITY_REMOVE_WEAPONS, targetid);
		}
 	}
	
	foreach(SupportPlayers, playerid) {
	    foreach(Zombies, targetid) {
	        ProceedPassiveAbility(playerid, ABILITY_SUPPORT, targetid);
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
    	
		SendClientMessage(i, 0xFFFFFFFF, Localization[i][LD_MSG_MAP_BEGINNING]);
		GameTextForPlayer(i, RusToGame(Localization[i][LD_MSG_MAP_ROUND_OVER]), 5000, 5);
		
		GivePointsForRound(i);
	}
	
	Map[mpTimeoutIgnoreTick] = 1;
	Map[mpTimeoutBeforeStart] = MapConfig[mpCfgRestart];
	Map[mpIsStarted] = false;
}

custom LoadLocalization(const playerid, const type) {
    static const query[] = LOAD_LOCALIZATION_QUERY;
    static const tipsQuery[] = LOAD_LOCALIZATION_TIPS_QUERY;
    
	new index = Player[playerid][pLanguage];
	
	new formated[sizeof(query) + LOCALIZATION_SIZE];
    mysql_format(Database, formated, sizeof(formated), query, LOCALIZATION_TABLES[index]);
	mysql_tquery(Database, formated, "InitializeLocalization", "ii", playerid, type);
	
	new formatedTips[sizeof(tipsQuery) + LOCALIZATION_SIZE];
	mysql_format(Database, formatedTips, sizeof(formatedTips), tipsQuery, LOCALIZATION_TABLES[index]);
	mysql_tquery(Database, formatedTips, "InitializeLocalizedTips", "i", playerid);
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
    mysql_tquery(Database, REG_SKILLS_QUERY);
    
    AfterAuthorization(playerid);
    return 1;
}

custom GetMimicrySkin(const playerid, const old) {
	if(cache_num_rows()) {
	    new skin, Float:health, Float:armour;
        cache_get_value_name_int(0, "skin", skin);
        cache_get_value_name_float(0, "health", health);
        cache_get_value_name_float(0, "armour", armour);
        
        SetPlayerHealthAC(playerid, health);
        SetPlayerArmourAC(playerid, armour);
        SetPlayerSkin(playerid, skin);
        ClearAnimations(playerid);
	}
}

custom DestroyObjectEffect(const objectid) {
	DestroyObject(objectid);
}

custom DestroyObjectEffectAndExplosion(const objectid, const Float:x, const Float:y, const Float:z) {
    DestroyObject(objectid);
	CreateExplosion(x, y, z, ClassesConfig[clsCfgFlasherExplosionType], ClassesConfig[clsCfgFlasherExplosionRange]);
}

custom MovePlayerAfterEffect(const playerid, const Float:x, const Float:y, const Float:z) {
	SetPlayerPos(playerid, x, y, z);
	ClearAnimations(playerid);
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
        cache_get_value_name_int(0, "min_zombies_to_win", ServerConfig[svCfgMinZombiesToWin]);
        cache_get_value_name_int(0, "max_weapon_ammo", ServerConfig[svCfgMaxWeaponAmmo]);
        cache_get_value_name_int(0, "rifle", ServerConfig[svCfgRifle]);
        cache_get_value_name_int(0, "excluded_mirror_part", ServerConfig[svCfgExcludedMirrorPart]);
        cache_get_value_name_int(0, "meat_pickup", ServerConfig[svCfgMeatPickup]);
        cache_get_value_name_int(0, "ammo_chance", ServerConfig[svCfgAmmoChance]);
        cache_get_value_name_int(0, "antidote_chance", ServerConfig[svCfgAntidoteChance]);
        cache_get_value_name_int(0, "tip_per", ServerConfig[svCfgTipMessageCooldown]);

        cache_get_value_name_float(0, "infection_damage", ServerConfig[svCfgInfectionDamage]);
        cache_get_value_name_float(0, "curse_damage", ServerConfig[svCfgCurseDamage]);
        
        cache_get_value_name_float(0, "vehicle_damage", ServerConfig[svCfgVehicleDamage]);
        cache_get_value_name_float(0, "spawn_range", ServerConfig[svCfgSpawnRange]);
        cache_get_value_name_float(0, "fists_damage", ServerConfig[svCfgZombieFistsDamage]);

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

        printf(""SV_CFG_CONSOLE_LOG" LOADED");
        return 1;
	}

	printf(""SV_CFG_CONSOLE_LOG" FAILED");
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
        cache_get_value_name_float(0, "crystal_health", GangsConfig[gdCfgCrystalHealth]);
        cache_get_value_name_float(0, "flag_distance", GangsConfig[gdCfgFlagDistance]);

        cache_get_value_name_float(0, "per_cure", GangsConfig[gdCfgPerCure]);
        cache_get_value_name_float(0, "per_kill", GangsConfig[gdCfgPerKill]);
        cache_get_value_name_float(0, "per_evac", GangsConfig[gdCfgPerEvac]);
        cache_get_value_name_float(0, "per_ability", GangsConfig[gdCfgPerAbility]);
        cache_get_value_name_float(0, "per_assist", GangsConfig[gdCfgPerAssist]);

        printf(""GS_CFG_CONSOLE_LOG" LOADED");
        return 1;
    }

    printf(""GS_CFG_CONSOLE_LOG" FAILED");
    return 0;
}

custom LoadRoundConfiguration() {
    if(cache_num_rows() > 0) {
        cache_get_value_name_int(0, "survival_per", RoundConfig[rdCfgSurvivalPer]);
        cache_get_value_name_int(0, "cap", RoundConfig[rdCfgCap]);
        cache_get_value_name_int(0, "brutality_weapon", RoundConfig[rdCfgBrutalityWeapon]);
        
        cache_get_value_name_float(0, "evac", RoundConfig[rdCfgEvac]);
        cache_get_value_name_float(0, "survival", RoundConfig[rdCfgSurvival]);
        cache_get_value_name_float(0, "killing", RoundConfig[rdCfgKilling]);
        cache_get_value_name_float(0, "care", RoundConfig[rdCfgCare]);
        cache_get_value_name_float(0, "mobility", RoundConfig[rdCfgMobility]);
        cache_get_value_name_float(0, "skillfulness", RoundConfig[rdCfgSkillfulness]);
        cache_get_value_name_float(0, "brutality", RoundConfig[rdCfgBrutality]);
        cache_get_value_name_float(0, "undead", RoundConfig[rdCfgDeaths]);
        
        printf(""RD_CFG_CONSOLE_LOG" LOADED");
        return 1;
    }
    
    printf(""RD_CFG_CONSOLE_LOG" FAILED");
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

        printf(""EVC_CFG_CONSOLE_LOG" LOADED");
        return 1;
    }

    printf(""EVC_CFG_CONSOLE_LOG" FAILED");
    return 0;
}

custom LoadMapConfiguration() {
    if(cache_num_rows() > 0) {
        cache_get_value_name_int(0, "total", MapConfig[mpCfgTotal]);
        cache_get_value_name_int(0, "update", MapConfig[mpCfgUpdate]);
        cache_get_value_name_int(0, "balance", MapConfig[mpCfgBalance]);
        cache_get_value_name_int(0, "end", MapConfig[mpCfgEnd]);
        cache_get_value_name_int(0, "restart", MapConfig[mpCfgRestart]);
        cache_get_value_name_int(0, "great_period", MapConfig[mpCfgGreatTime]);
        cache_get_value_name_int(0, "spawn_protection_time", MapConfig[mpCfgSpawnProtectionTime]);
        cache_get_value_name_int(0, "oom_check", MapConfig[mpCfgOOMCheck]);
        
        cache_get_value_name_float(0, "spawn_text_range", MapConfig[mpCfgSpawnTextRange]);
        cache_get_value_name_float(0, "human_hero_kill", MapConfig[mpCfgHumanHeroPoints]);
        cache_get_value_name_float(0, "zombie_boss_kill", MapConfig[mpCfgZombieBossPoints]);
		cache_get_value_name_float(0, "first_blood", MapConfig[mpCfgFirstBlood]);
        cache_get_value_name_float(0, "kill_last", MapConfig[mpCfgKillLast]);
        cache_get_value_name_float(0, "last_evacuated", MapConfig[mpCfgLastEvacuated]);
        
        cache_get_value_name(0, "hero_weapons", MapConfig[mpCfgHumanHeroWeapons]);
        cache_get_value_name_float(0, "hero_armour", MapConfig[mpCfgHumanHeroArmour]);
        cache_get_value_name_float(0, "zombie_armour", MapConfig[mpCfgZombieBossArmour]);
        
        printf(""MAP_CFG_CONSOLE_LOG" LOADED");
        return 1;
    }
    
    printf(""MAP_CFG_CONSOLE_LOG" FAILED");
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
        }

        printf(""WPS_CFG_CONSOLE_LOG" LOADED (%d / %d)", len, MAX_WEAPONS);
        return 1;
    }
    printf(""WPS_CFG_CONSOLE_LOG" FAILED");
	return 0;
}

custom LoadBalanceConfiguration() {
    if(cache_num_rows() > 0) {
        cache_get_value_name_float(0, "min", ServerBalance[svbMinZombies]);
    	cache_get_value_name_float(0, "medium", ServerBalance[svbMediumZombies]);
    	cache_get_value_name_float(0, "max", ServerBalance[svbMaxZombies]);
    	cache_get_value_name_float(0, "by_default", ServerBalance[svbDefaultZombies]);

        printf(""BLC_CFG_CONSOLE_LOG" LOADED");
        return 1;
    }
    printf(""BLC_CFG_CONSOLE_LOG" FAILED");
	return 0;
}

custom LoadTexturesConfiguration() {
    if(cache_num_rows() > 0) {
        new buff[128], i, len = clamp(cache_num_rows(), 0, MAX_SERVER_TEXTURES);
        for( i = 0; i < len; i++ ) {
            cache_get_value_name(i, "position", buff);
            sscanf(buff, "p<,>ff", ServerTexturesConfig[i][svTxCfgTexturePosition][0], ServerTexturesConfig[i][svTxCfgTexturePosition][1]);
            
            cache_get_value_name(i, "letter_size", buff);
            sscanf(buff, "p<,>ff", ServerTexturesConfig[i][svTxCfgTextureLetterSize][0], ServerTexturesConfig[i][svTxCfgTextureLetterSize][1]);
            
            cache_get_value_name(i, "text_size", buff);
            sscanf(buff, "p<,>ff", ServerTexturesConfig[i][svTxCfgTextureTextSize][0], ServerTexturesConfig[i][svTxCfgTextureTextSize][1]);
            
            cache_get_value_name(i, "texture_box_color", buff);
			sscanf(buff, "x", ServerTexturesConfig[i][svTxCfgTextureBoxColor]);
			
			cache_get_value_name(i, "background_color", buff);
			sscanf(buff, "x", ServerTexturesConfig[i][svTxCfgTextureBackgroundColor]);
			
			cache_get_value_name(i, "texture_draw_color", buff);
            sscanf(buff, "x", ServerTexturesConfig[i][svTxCfgTextureDrawColor]);
            
            cache_get_value_name(i, "default_value", ServerTexturesConfig[i][svTxCfgTextureDefaultValue]);
            cache_get_value_name_int(i, "texture_font", ServerTexturesConfig[i][svTxCfgTextureFont]);
            cache_get_value_name_int(i, "texture_outline", ServerTexturesConfig[i][svTxCfgTextureOutline]);
            cache_get_value_name_int(i, "texture_proportional", ServerTexturesConfig[i][svTxCfgTextureProportional]);
            cache_get_value_name_int(i, "texture_shadow", ServerTexturesConfig[i][svTxCfgTextureShadow]);
			cache_get_value_name_int(i, "texture_use_box", ServerTexturesConfig[i][svTxCfgTextureUseBox]);
			cache_get_value_name_int(i, "texture_alignment", ServerTexturesConfig[i][svTxCfgTextureAlignment]);
        }

        printf(""TEX_CFG_CONSOLE_LOG" LOADED (%d / %d)", len, MAX_SERVER_TEXTURES);
        InitializeScreenTextures();
        
        return 1;
    }
    
    printf(""TEX_CFG_CONSOLE_LOG" FAILED");
	return 0;
}

custom LoadClassesConfiguration() {
    if(cache_num_rows() > 0) {
        new buff[64];
        cache_get_value_name_int(0, "whopping_when", ClassesConfig[clsCfgWhoppingWhen]);
        cache_get_value_name_int(0, "spitter_effect", ClassesConfig[clsCfgSpitterWeapon]);
        cache_get_value_name_int(0, "stealer_effect", ClassesConfig[clsCfgStealAmmoFactor]);
        
        cache_get_value_name_float(0, "air_range", ClassesConfig[clsCfgAirRange]);
        cache_get_value_name_float(0, "radioactive", ClassesConfig[clsCfgRadioactiveDamage]);
        cache_get_value_name_float(0, "regeneration", ClassesConfig[clsCfgRegenHealth]);
        cache_get_value_name_float(0, "support", ClassesConfig[clsCfgSupportHealth]);
        cache_get_value_name_float(0, "space", ClassesConfig[clsCfgSpaceDamage]);
        
        cache_get_value_name(0, "stomp_xyz", buff);
        sscanf(buff, "p<,>fff",
			ClassesConfig[clsCfgStomp][0], ClassesConfig[clsCfgStomp][1],
			ClassesConfig[clsCfgStomp][2]
		);
		
		cache_get_value_name(0, "stomper_effect", buff);
		sscanf(buff, "p<,>ifffi", ClassesConfig[clsCfgStomperEffectId],
			ClassesConfig[clsCfgStomperEffectPos][0], ClassesConfig[clsCfgStomperEffectPos][1],
			ClassesConfig[clsCfgStomperEffectPos][2], ClassesConfig[clsCfgStomperEffectTime]
		);
		
		
		cache_get_value_name(0, "flasher_effect", buff);
		sscanf(buff, "p<,>iiif", ClassesConfig[clsCfgFlasherEffectId],
			ClassesConfig[clsCfgFlasherEffectTime],
			ClassesConfig[clsCfgFlasherExplosionType],
			ClassesConfig[clsCfgFlasherExplosionRange]
		);
		
		cache_get_value_name(0, "high_jump_xyz", buff);
		sscanf(buff, "p<,>fff", ClassesConfig[clsCfgHighJump][0],
			ClassesConfig[clsCfgHighJump][1], ClassesConfig[clsCfgHighJump][2]
		);
		
		cache_get_value_name(0, "long_jump_xyz", buff);
		sscanf(buff, "p<,>fff", ClassesConfig[clsCfgLongJump][0],
			ClassesConfig[clsCfgLongJump][1], ClassesConfig[clsCfgLongJump][2]
		);
		
		cache_get_value_name(0, "engineer_effect", buff);
		sscanf(buff, "p<,>iif",  ClassesConfig[clsCfgEngineerBox],
			ClassesConfig[clsCfgEngineerSound],
			ClassesConfig[clsCfgEngineerTextRange]
		);
			
		printf(""CLS_CFG_CONSOLE_LOG" LOADED");
		return 1;
    }
    
    printf(""CLS_CFG_CONSOLE_LOG" FAILED");
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

        PreloadDefaultLocalizedTitles(playerid);
        LoadLocalization(playerid, AUTH_LOGIN_TYPE);
        return 1;
    }
   	
	PredictPreferedLocalization(playerid);
	PreloadDefaultLocalizedTitles(playerid);
	LoadLocalization(playerid, AUTH_REG_TYPE);
    return 0;
}

custom InitializeLocalization(const playerid, const type) {
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

custom InitializeLocalizedTips(const playerid) {
    if(cache_num_rows() > 0) {
        new i, len = clamp(cache_num_rows(), 0, _:TIP_MSG_MAX);
        for( i = 0; i < len; i++ ) {
            cache_get_value_name(i, "text", LocalizedTips[playerid][TIPS_DATA:i]);
        }
    }
}

custom LoadFirstClassesTitles(const playerid) {
    if(cache_num_rows() > 0) {
        cache_get_value_name(0, "title", Misc[playerid][mdZombieSelectionName]);
       	cache_get_value_name(1, "title", Misc[playerid][mdHumanSelectionName]);
       	
       	cache_get_value_name_int(0, "id", Misc[playerid][mdCurrentClass][TEAM_ZOMBIE]);
       	cache_get_value_name_int(0, "id", Misc[playerid][mdNextClass][TEAM_ZOMBIE]);
       	
       	cache_get_value_name_int(1, "id", Misc[playerid][mdCurrentClass][TEAM_HUMAN]);
       	cache_get_value_name_int(1, "id", Misc[playerid][mdNextClass][TEAM_HUMAN]);
       	
       	strmid(Misc[playerid][mdHumanNextSelectionName], Misc[playerid][mdHumanSelectionName], 0, MAX_CLASS_NAME);
		strmid(Misc[playerid][mdZombieNextSelectionName], Misc[playerid][mdZombieSelectionName], 0, MAX_CLASS_NAME);
    }
}


custom ShowClassesSelection(const playerid, const teamId, const showDialog) {
    if(cache_num_rows() > 0) {
        static const disabledTitlesColors[] = { 0xEC3013, 0xFF4D55 };
        static const enabledTitlesColors[] = { 0x009900, 0x75F0B0 };
        static const descriptionColors[] = { 0xFFFFFF, 0xA7A5A5 };

        new i, len = clamp(cache_num_rows(), 0, MAX_CLASSES), Float:points;
        new list[2560], formated[256], description[MAX_CLASS_DESC], color;
        
        for( i = 0; i < len; i++ ) {
            cache_get_value_name_int(i, "id", ClassesSelection[playerid][i][csdId]);
            cache_get_value_name(i, "title", ClassesSelection[playerid][i][csdName]);
            cache_get_value_name(i, "description", description);
            cache_get_value_float(i, "points", points);

			if(!showDialog) continue;
            color = (Achievements[playerid][achTotalPoints] < points) ? disabledTitlesColors[i % 2] : enabledTitlesColors[i % 2];
            format(formated, sizeof(formated), "{%06x}%s{%06x} - %s - %s%.0f %s\n",
				color,
				ClassesSelection[playerid][i][csdName],
				descriptionColors[i % 2],
                description,
				(Achievements[playerid][achTotalPoints] < points) ? "{FF0000}" : "",
				points,
				Localization[playerid][LD_CLASSES_TIP_EXP]
			);
			
            strcat(list, formated);
        }

        Misc[playerid][mdSelectionTeam] = teamId;
        
        if(showDialog) {
	        ShowPlayerDialogAC(
				playerid, DIALOG_SELECTION, DIALOG_STYLE_LIST,
				Localization[playerid][LD_DG_CLASSES_TITLE],
				list,
				Localization[playerid][LD_BTN_SELECT],
				Localization[playerid][LD_BTN_CLOSE]
			);
		}
        return 1;
    }

 	return 1;
}

stock ProceedClassSelection(const playerid, const selection, const showDialog) {
 	static const loadClassesQuery[] = LOAD_LOCALIZED_CLASSES_QUERY;
	new team = (selection == 0) ? TEAM_HUMAN : TEAM_ZOMBIE, index = Player[playerid][pLanguage];
    new formatedLoadClassesQuery[sizeof(loadClassesQuery) + LOCALIZATION_SIZE + LOCALIZATION_SIZE + MAX_TEAMS_LEN];

    mysql_format(Database, formatedLoadClassesQuery, sizeof(formatedLoadClassesQuery), loadClassesQuery, LOCALIZATION_TABLES[index], LOCALIZATION_TABLES[index], team);
    mysql_tquery(Database, formatedLoadClassesQuery, "ShowClassesSelection", "iii", playerid, team, showDialog);
}

stock ProocedClassChange(const playerid, const classid, const team, const fromSelection) {
	if(Map[mpTimeout] >= (MapConfig[mpCfgTotal] - MapConfig[mpCfgGreatTime]) && team == GetPlayerTeamEx(playerid)) {
	    switch(team) {
     		case TEAM_HUMAN: strmid(Misc[playerid][mdHumanSelectionName], ClassesSelection[playerid][fromSelection][csdName], 0, MAX_CLASS_NAME);
       		case TEAM_ZOMBIE: strmid(Misc[playerid][mdZombieSelectionName], ClassesSelection[playerid][fromSelection][csdName], 0, MAX_CLASS_NAME);
		}
		
		Misc[playerid][mdCurrentClass][team] = classid;
		SendClientMessage(playerid, 0xFFF000FF, Localization[playerid][LD_CLASS_GREAT_PERIOD]);
		SetByCurrentClass(playerid);
		return 1;
	}
	
	switch(team) {
		case TEAM_HUMAN: strmid(Misc[playerid][mdHumanNextSelectionName], ClassesSelection[playerid][fromSelection][csdName], 0, MAX_CLASS_NAME);
		case TEAM_ZOMBIE: strmid(Misc[playerid][mdZombieNextSelectionName], ClassesSelection[playerid][fromSelection][csdName], 0, MAX_CLASS_NAME);
	}
	
	Misc[playerid][mdNextClass][team] = classid;
	SendClientMessage(playerid, 0xFFF000FF, Localization[playerid][LD_CLASS_SET_AFTER]);
 	return 1;
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
    
    static const loadMapNameQuery[] = LOAD_MAP_NAME_QUERY;
    new formatedLoadMapNameQuery[sizeof(loadMapNameQuery) + LOCALIZATION_SIZE], index;
    foreach(Player, i) {
        index = Player[i][pLanguage];
    	mysql_format(Database, formatedLoadMapNameQuery, sizeof(formatedLoadMapNameQuery), loadMapNameQuery, LOCALIZATION_TABLES[index], Map[mpId]);
        mysql_tquery(Database, formatedLoadMapNameQuery, "GetLocalizedMapName", "i", i);
    }
    
   	static const loadMapQuery[] = LOAD_MAP_DATA_QUERY;
	new formated[sizeof(loadMapQuery) + MAX_ID_LENGTH];
 	mysql_format(Database, formated, sizeof(formated), loadMapQuery, Map[mpId]);
 	mysql_tquery(Database, formated, "LoadMap");
}

custom GetLocalizedMapName(const playerid) {
	if(cache_num_rows()) {
        cache_get_value_name(0, "name", Localization[playerid][LD_MAP_NAME]);
	}
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
	    Classes[i][cldPoints] = 0;
	    Classes[i][cldHealth] = 100.0;
	    Classes[i][cldArmour] = 0.0;
	    Classes[i][cldCooldown] = 0;
	    Classes[i][cldAbilityTime] = 0;
        Classes[i][cldSkin] = 1;
	    Classes[i][cldDisabled] = 1;
	    Classes[i][cldDistance] = 0.0;

		strmid(Classes[i][cldAbility], "", 0, MAX_CLASSDATA_STR_LEN);
		strmid(Classes[i][cldImmunity], "", 0, MAX_CLASSDATA_STR_LEN);
		strmid(Classes[i][cldWeapons], "", 0, MAX_CLASSDATA_STR_LEN);
	}
}

stock ClearLocalizedClassesData(const playerid) {
    for( new i; i < MAX_CLASSES; i++ ) {
        ClassesSelection[playerid][i][csdId] = 0;
        strmid(ClassesSelection[playerid][i][csdName], "", 0, MAX_CLASS_NAME);
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
    ClearLocalizedClassesData(playerid);
    
    ResetWeapons(playerid);
    
    SetPlayerHealthAC(playerid, 100.0);
    SetPlayerArmourAC(playerid, 0.0);
}

stock ClearAbilitiesTimers(const playerid) {
	for( new i; i < ABLITY_MAX; i++ ) {
    	AbilitiesTimers[playerid][i] = 0;
    }
}

stock ClearPlayerData(const playerid) {
    Player[playerid][pAccountId] = 0;
    Player[playerid][pLanguage] = 0;
    Player[playerid][pPoints] = 0.0;
}

stock IncreaseWeaponSkillLevel(const playerid, const weaponid) {
	new index = -1;
	
	switch(weaponid) {
	    case 22: index = WEAPONSKILL_PISTOL;
	    case 23: index = WEAPONSKILL_PISTOL_SILENCED;
	    case 24: index = WEAPONSKILL_DESERT_EAGLE;
	    case 25: index = WEAPONSKILL_SHOTGUN;
	    case 26: index = WEAPONSKILL_SAWNOFF_SHOTGUN;
	    case 27: index = WEAPONSKILL_SPAS12_SHOTGUN;
	    case 28, 32: index = WEAPONSKILL_MICRO_UZI;
	    case 29: index = WEAPONSKILL_MP5;
	    case 30: index = WEAPONSKILL_AK47;
	    case 31: index = WEAPONSKILL_M4;
	    case 33,34: index = WEAPONSKILL_SNIPERRIFLE;
	}
	
	if(index > -1) {
		Misc[playerid][mdWeaponSkill][index]++;
    	SetPlayerSkillLevel(playerid, index, Misc[playerid][mdWeaponSkill][index]);
    }
}

stock ClearPlayerWeaponsData(const playerid) {
    for( new i = 0; i < MAX_WEAPONS_SKILL; i++ ) {
        Misc[playerid][mdWeaponSkill][i] = 0;
        SetPlayerSkillLevel(playerid, i, Misc[playerid][mdWeaponSkill][i]);
    }
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
	Misc[playerid][mdBlindTimeout] = -1;
	Misc[playerid][mdDialogId] = -1;
	Misc[playerid][mdSelectionTeam] = -1;
	strmid(Misc[playerid][mdHumanSelectionName], "", 0, MAX_CLASS_NAME);
	strmid(Misc[playerid][mdZombieSelectionName], "", 0, MAX_CLASS_NAME);
    Misc[playerid][mdIsLogged] = false;
    Misc[playerid][mdKickForAuthTimeout] = -1;
    Misc[playerid][mdKickForAuthTries] = ServerConfig[svCfgAuthTries];
    
    Misc[playerid][mdMimicry][0] = -1;
    Misc[playerid][mdMimicry][1] = 0;
    Misc[playerid][mdMimicry][2] = -1;
    Misc[playerid][mdMimicryStats][0] = 100.0;
    Misc[playerid][mdMimicryStats][1] = 0.0;
    
    for( new i = 0; i < MAX_PLAYER_TEAMS; i++ ) {
	    Misc[playerid][mdCurrentClass][i] = 0;
        Misc[playerid][mdNextClass][i] = -1;
    }
    
    strmid(Misc[playerid][mdPassword], "", 0, MAX_PLAYER_PASSWORD);
}

stock InitializeScreenTextures() {
    CreateTextureFromConfig(ServerTextures[timeLeftTexture], TIMELEFT_TEXTURE_ID);
	CreateTextureFromConfig(ServerTextures[infectedTexture], INFECTED_TEXTURE_ID);
	CreateTextureFromConfig(ServerTextures[untillEvacRectangleTexture], UNTILEVAC_RECTANGLE_TEXTURE_ID);
	
	for( new i; i < MAX_PLAYERS; i++ ) {
	    CreateTextureFromConfig(ServerTextures[untilEvacTextTexture][i], UNTILEVAC_TEXT_TEXTURE_ID);
		CreateTextureFromConfig(ServerTextures[aliveInfoTexture][i], ALIVE_INFO_TEXTURE_ID);
		CreateTextureFromConfig(ServerTextures[pointsTexture][i], POINTS_TEXTURE_ID);
	}
	
	CreateTextureFromConfig(ServerTextures[blindTexture], BLIND_TEXTURE_ID);
}

stock DestroyScreenTextures() {
    for( new i; i < MAX_PLAYERS; i++ ) {
        if(IsPlayerConnected(i)) {
            TextDrawHideForPlayer(i, ServerTextures[untilEvacTextTexture][i]);
            TextDrawHideForPlayer(i, ServerTextures[aliveInfoTexture][i]);
            TextDrawHideForPlayer(i, ServerTextures[pointsTexture][i]);
        }

        TextDrawDestroy(ServerTextures[untilEvacTextTexture][i]);
        TextDrawDestroy(ServerTextures[aliveInfoTexture][i]);
        TextDrawDestroy(ServerTextures[pointsTexture][i]);
	}

	TextDrawHideForAll(ServerTextures[untillEvacRectangleTexture]);
	TextDrawDestroy(ServerTextures[untillEvacRectangleTexture]);

	TextDrawHideForAll(ServerTextures[infectedTexture]);
	TextDrawDestroy(ServerTextures[infectedTexture]);

	TextDrawHideForAll(ServerTextures[timeLeftTexture]);
	TextDrawDestroy(ServerTextures[timeLeftTexture]);
}

stock InitializeDefaultValues() {
    new i, j;
    for( i = 0; i < MAX_PLAYERS; i++ ) {
    
        Round[i][rdBoxCount] = -1;
        Round[i][rdCheckForOOM] = 0;
        Round[i][rdAbilityTimes] = 0;
        
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
	//Map[mpFlagText] = Text3D:-1;
	ServerConfig[svCfgCurrentOnline] = 0;
	ServerConfig[svCfgLastTipMessage] = 0;
}

stock ClearPlayerRoundData(const playerid) {
    Round[playerid][rdIsEvacuated] = false;
    Round[playerid][rdIsInfected] = false;
    Round[playerid][rdIsAdvanceInfected] = false;
	Round[playerid][rdIsInRadioactiveField] = false;
	Round[playerid][rdIsCursed] = false;
	Round[playerid][rdIsLegsBroken] = false;
	Round[playerid][rdIsPoisoned] = false;
    Round[playerid][rdBoxCount] = -1;
    Round[playerid][rdCheckForOOM] = 0;
 	Round[playerid][rdFrozeTime] = -1;
 	Round[playerid][rdAbilityTimes] = 0;
    
	Misc[playerid][mdMimicry][2] = -1;
	Misc[playerid][mdMimicryStats][0] = 100.0;
    Misc[playerid][mdMimicryStats][1] = 0.0;
    
    Misc[playerid][mdLastIssuedDamage] = -1;
    Misc[playerid][mdLastIssuedReason] = 0;
    
    SetPlayerDrunkLevel(playerid, 0);
    TextDrawHideForPlayer(playerid, ServerTextures[infectedTexture]);
    AbilitiesTimers[playerid][ABILITY_LONG_JUMPS] = 0;

    new i;
    for( i = 0; i < MAX_ROUND_BOXES; i++ ) {
		DestroyObjectEx(Round[playerid][rdBox][i]);
		Delete3DTextLabelEx(Round[playerid][rdBoxText][i]);
	}
	
	for( i = 0; i < MAX_MAP_SPAWNS; i++ ) {
		DeletePlayer3DTextLabelEx(playerid, Misc[playerid][mdSpawnPoints][i]);
		Misc[playerid][mdSpawnPoints][i] = CreatePlayer3DTextLabel(playerid, Localization[playerid][LD_MAP_DONOT_SHOT_HERE], 0xFF0000FF, Map[mpZombieSpawnX][i], Map[mpZombieSpawnY][i], Map[mpZombieSpawnZ][i], MapConfig[mpCfgSpawnTextRange]);
	}
	
	ClearAbilitiesTimers(playerid);
	TextDrawHideForPlayer(playerid, ServerTextures[infectedTexture]);
	TextDrawHideForPlayer(playerid, ServerTextures[blindTexture]);
}

stock bool:IsPlayerInsideMap(const playerid) {
	if(GetPlayerInterior(playerid) > 0) {
	    return true;
	}

	new Float:pos[3];
    GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
    return IsPointInPolygon(ToPolygonPoint(pos[0], pos[1]), Polygon);
}

stock CheckPlayerForOOM(const playerid) {
	if(!Misc[playerid][mdIsLogged] || !Map[mpIsStarted] ||
		Map[mpTimeout] <= 0 || Map[mpTimeout] >= (MapConfig[mpCfgTotal] - MapConfig[mpCfgGreatTime]) ||
		GetPlayerState(playerid) != PLAYER_STATE_ONFOOT || Round[playerid][rdCheckForOOM] > gettime()) {
	    return;
	}
	
	Round[playerid][rdCheckForOOM] = gettime() + MapConfig[mpCfgOOMCheck];
	
    if(!IsPlayerInsideMap(playerid)) {
		SetPlayerTeamAC(playerid, TEAM_ZOMBIE);
		SpawnPlayer(playerid);

		new formated[90];
		foreach(Player, i) {
		    format(formated, sizeof(formated), Localization[i][LD_MSG_PLAYER_OOM], Misc[playerid][mdPlayerName]);
		    SendClientMessage(i, 0x33CCFFFF, formated);
		}
	}
	
	return;
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

stock ProceedClassImmunity(const playerid, const abilityid) {
    new immunities[2], immunity;
    new classid = Misc[playerid][mdCurrentClass][GetPlayerTeamEx(playerid)];
    sscanf(Classes[classid][cldImmunity], "p<,>ii", immunities[0], immunities[1]);
    for( immunity = 0; immunity < sizeof(immunities); immunity++ ) {
        if(immunities[immunity] == abilityid) {
			return 1;
       }
	}

	return 0;
}

stock ProceedClassAbilityActivation(const playerid) {
	if(!IsAbleToUseAbility(playerid)) {
	    GameTextForPlayer(playerid, RusToGame(Localization[playerid][LD_DISPLAY_CANT_USE]), 1000, 5);
	    return 0;
	}

    new abilities[2], ability;
    new classid = Misc[playerid][mdCurrentClass][GetPlayerTeamEx(playerid)];
    sscanf(Classes[classid][cldAbility], "p<,>ii", abilities[0], abilities[1]);
    for( ability = 0; ability < sizeof(abilities); ability++ ) {
        if(abilities[ability] <= 0 || abilities[ability] >= ABLITY_MAX) continue;
    
        if(gettime() < AbilitiesTimers[playerid][abilities[ability]] && abilities[ability] != ABILITY_LONG_JUMPS && GetPlayerVirtualWorld(playerid) <= 0) {
        	GameTextForPlayer(playerid, RusToGame(Localization[playerid][LD_DISLPAY_COOLDOWN]), 1000, 5);
			continue;
		}
		
        switch(abilities[ability]) {
            case ABILITY_INFECT: InfectPlayer(playerid, classid, ABILITY_INFECT);
            case ABILITY_DRUNK: InfectPlayerDrunk(playerid, classid, ABILITY_DRUNK);
            case ABILITY_BLIND: InfectPlayerBlind(playerid, classid, ABILITY_BLIND);
			case ABILITY_MUTATED: InfectPlayerAdvanced(playerid, classid, ABILITY_MUTATED);
            case ABILITY_ARMOUR_REMOVE: StealArmour(playerid, classid, ABILITY_ARMOUR_REMOVE);
            case ABILITY_STEALER: StealAmmo(playerid, classid, ABILITY_STEALER);
            case ABILITY_LEG_BREAK: BreakLegs(playerid, classid, ABILITY_LEG_BREAK);
			case ABILITY_STOMPER: StompHumans(playerid, classid, ABILITY_STOMPER);
			case ABILITY_WITCH: CurseHuman(playerid, classid, ABILITY_WITCH);
            case ABILITY_FLASH: FlashAttackOnHuman(playerid, classid, ABILITY_FLASH);
            case ABILITY_FREEZER: FreezePlayers(playerid, classid, ABILITY_FREEZER);
            case ABILITY_MIMICRY: MimicrySkin(playerid, classid, ABILITY_MIMICRY);
            case ABILITY_JUMPER: HighJump(playerid, classid, ABILITY_JUMPER);
            case ABILITY_SPACEBREAKER: BreakSpace(playerid, classid, ABILITY_SPACEBREAKER);
			case ABILITY_SPITTER: GiveSpitterWeapon(playerid, classid, ABILITY_SPITTER);
			case ABILITY_SUPPORT: EnableDisableSupportField(playerid);
            case ABILITY_RADIOACTIVE: EnableDisableRadioActiveField(playerid);
            case ABILITY_CURE_FIELD: EnableDisableCureField(playerid);
            case ABILITY_HOLY_FIELD: EnableDisableHolyField(playerid);
            case ABILITY_REMOVE_WEAPONS: EnableDisableRemoveWeapons(playerid);
            case ABILITY_KAMIKAZE: InfectAndExplode(playerid, classid);
            case ABILITY_BUILD: BuildBox(playerid, classid);
            case ABILITY_LONG_JUMPS: LongJump(playerid, classid);
        }
	}
	
	return 1;
}

stock ProceedPassiveAbility(const playerid, const abilityid, const targetid = -1, const Float:amount = 0.0) {
    if(IsPoisoned(playerid)) {
	    GameTextForPlayer(playerid, RusToGame(Localization[playerid][LD_DISPLAY_CANT_USE]), 1000, 5);
	    return 0;
	}

    new abilities[2], ability;
    new classid = Misc[playerid][mdCurrentClass][GetPlayerTeamEx(playerid)];
    
    sscanf(Classes[classid][cldAbility], "p<,>ii", abilities[0], abilities[1]);
    for( ability = 0; ability < sizeof(abilities); ability++ ) {
        if(abilities[ability] != abilityid) continue;
        switch(abilities[ability]) {
	        case ABILITY_SUPPORT: RegenerateHealth(targetid, playerid, ClassesConfig[clsCfgRegenHealth], classid);
	        case ABILITY_RADIOACTIVE: DamageFromRadioactiveField(targetid, playerid, ClassesConfig[clsCfgRadioactiveDamage], classid);
	        case ABILITY_BOOMER: InfectAndExplode(playerid, classid);
	        case ABILITY_FLESHER: InfectPlayerFlesher(targetid, playerid);
	        case ABILITY_SPORE: InfectPlayerSpore(targetid, playerid);
	        case ABILITY_SPITTER: InfectPlayerSpitter(targetid, playerid);
			case ABILITY_CURE: CurePlayerByShot(targetid, playerid);
			case ABILITY_POISON: PoisePlayerByShot(targetid, playerid);
			case ABILITY_CURE_FIELD: CurePlayerInField(targetid, playerid, classid);
	        case ABILITY_REGENERATOR: RegenerateHealth(playerid, playerid, ClassesConfig[clsCfgSupportHealth]);
	        case ABILITY_MIRROR: MirrorDamageBack(targetid, playerid, amount);
			case ABILITY_HOLY_FIELD: PlayerInHolyField(targetid, playerid, classid);
			case ABILITY_REMOVE_WEAPONS: PlayerInRemoveField(targetid, playerid, classid);
			case ABILITY_MUTATED: PlayerInfectPlayer(targetid, playerid, ClassesConfig[clsCfgAirRange]);
		}
	}
	
	return 1;
}

stock GivePointsForRound(const playerid) {
	new Float: amount = float(
		clamp(floatround(RoundSession[playerid][rsdSurvival], floatround_tozero), 0, RoundConfig[rdCfgCap]) +
		clamp(floatround(RoundSession[playerid][rsdKilling], floatround_tozero), 0, RoundConfig[rdCfgCap]) +
		clamp(floatround(RoundSession[playerid][rsdCare], floatround_tozero), 0, RoundConfig[rdCfgCap]) +
		clamp(floatround(RoundSession[playerid][rsdMobility], floatround_tozero), 0, RoundConfig[rdCfgCap]) +
		clamp(floatround(RoundSession[playerid][rsdSkillfulness], floatround_tozero), 0, RoundConfig[rdCfgCap]) +
		clamp(floatround(RoundSession[playerid][rsdBrutality], floatround_tozero), 0, RoundConfig[rdCfgCap]) +
		clamp(floatround(RoundSession[playerid][rsdDeaths], floatround_tozero), 0, RoundConfig[rdCfgCap]) +
		floatround(RoundSession[playerid][rdAdditionalPoints], floatround_tozero)
	);
	
	Achievements[playerid][achTotalPoints] += amount;
	Player[playerid][pPoints] += amount;
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
    RoundSession[playerid][rdAdditionalPoints] = 0.0;
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
    RoundSession[playerid][rdAdditionalPoints] = 0.0;
}

stock GetPlayerTeamEx(const playerid) {
	return Misc[playerid][mdPlayerTeam];
}

stock SetPlayerTeamAC(const playerid, const teamid) {
	new old = GetPlayerTeamEx(playerid);

	if(old != teamid) {
	    switch(teamid) {
	        case TEAM_UNKNOWN: {
	            switch(old) {
	                case TEAM_ZOMBIE: {
                        Map[mpTeamCount][0]--;
                        if(Iter_Contains(Zombies, playerid)) {
							Iter_Remove(Zombies, playerid);
						}
	                }
	                case TEAM_HUMAN: {
                        Map[mpTeamCount][1]--;
                        if(Iter_Contains(Humans, playerid)) {
                        	Iter_Remove(Humans, playerid);
                        }
	                }
	            }
	        }
	    	case TEAM_ZOMBIE: {
	    	    if(!Iter_Contains(Zombies, playerid)) {
	    	    	Iter_Add(Zombies, playerid);
	    	    	Map[mpTeamCount][0]++;
				}

				if(old == TEAM_HUMAN) {
				    if(Iter_Contains(Humans, playerid)) {
						Iter_Remove(Humans, playerid);
					}
					
				    Map[mpTeamCount][1]--;
				}
				
				if(Map[mpTeamCount][1] == 1 && !Map[mpKillTheLast]) {
				    Map[mpKillTheLast] = true;
				    
				    new formated[90];
				    foreach(Player, i) {
				        format(formated, sizeof(formated), Localization[i][LD_MSG_KILL_THE_LAST], Localization[i][LD_MSG_POINTS_MULTIPLE]);
                        SendClientMessage(i, 0x59E4B5FF, formated);
				    }
				}
				
			}
	    	case TEAM_HUMAN: {
	    	    if(!Iter_Contains(Humans, playerid)) {
	    	    	Iter_Add(Humans, playerid);
					Map[mpTeamCount][1]++;
				}
				
				if(old == TEAM_ZOMBIE) {
					if(Iter_Contains(Zombies, playerid)) {
				    	Iter_Remove(Zombies, playerid);
				    }
				    
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
	    
	    strmid(Misc[playerid][mdHumanSelectionName], Misc[playerid][mdHumanNextSelectionName], 0, MAX_CLASS_NAME);
		strmid(Misc[playerid][mdZombieSelectionName], Misc[playerid][mdZombieNextSelectionName], 0, MAX_CLASS_NAME);
	    next = -1;
	}
	
	switch(GetPlayerTeamEx(playerid)) {
	    case TEAM_ZOMBIE: {
			SetZombie(playerid, current);
			SetPlayerPos(playerid, 	Map[mpZombieSpawnX][point] + distance, Map[mpZombieSpawnY][point] + distance, Map[mpZombieSpawnZ][point]);
			SetPlayerFacingAngle(playerid, Map[mpZombieSpawnA][point]);
			Misc[playerid][mdSpawnProtection] = gettime() + MapConfig[mpCfgSpawnProtectionTime];
			
			new formated[90];
			format(formated, sizeof(formated), Localization[playerid][LD_CLASSES_SPAWN_AS], Misc[playerid][mdZombieSelectionName]);
			SendClientMessage(playerid, 0xFFF000FF, formated);
		}
	    case TEAM_HUMAN: {
			SetHuman(playerid, current);
			SetPlayerPos(playerid, 	Map[mpHumanSpawnX][point] + distance, Map[mpHumanSpawnY][point] + distance, Map[mpHumanSpawnZ][point]);
			SetPlayerFacingAngle(playerid, Map[mpHumanSpawnA][point]);
			
			new formated[90];
			format(formated, sizeof(formated), Localization[playerid][LD_CLASSES_SPAWN_AS], Misc[playerid][mdHumanSelectionName]);
			SendClientMessage(playerid, 0xFFF000FF, formated);
  		}
	}
	
	SetCameraBehindPlayer(playerid);
	TextDrawShowForPlayer(playerid, ServerTextures[timeLeftTexture]);
	TextDrawShowForPlayer(playerid, ServerTextures[untillEvacRectangleTexture]);
	TextDrawShowForPlayer(playerid, ServerTextures[untilEvacTextTexture][playerid]);
 	TextDrawShowForPlayer(playerid, ServerTextures[aliveInfoTexture][playerid]);
  	TextDrawShowForPlayer(playerid, ServerTextures[pointsTexture][playerid]);
}

stock bool:IsAbleToTakeRadioactiveDamage(const playerid) {
	if(GetPlayerVirtualWorld(playerid) > 0 || ProceedClassImmunity(playerid, ABILITY_RADIOACTIVE)) {
	    return false;
	}

	if(Round[playerid][rdIsInRadioactiveField]) {
	    return true;
	}

	return false;
}

stock bool:IsAbleToBeInfected(const playerid) {
    if(
		Round[playerid][rdIsInfected] || Round[playerid][rdIsAdvanceInfected] ||
		GetPlayerTeamEx(playerid) == TEAM_ZOMBIE || GetPlayerVirtualWorld(playerid) > 0 ||
		ProceedClassImmunity(playerid, ABILITY_INFECT)) {
        return false;
    }
    
    return true;
}

stock bool:IsAbleToTakeArmour(const playerid) {
	if(GetPlayerVirtualWorld(playerid) > 0 || ProceedClassImmunity(playerid, ABILITY_ARMOUR_REMOVE)) {
	    return false;
	}
	
	return GetPlayerArmourEx(playerid) > 0.0;
}

stock bool:IsAbleToBeStomped(const playerid) {
	if(GetPlayerVirtualWorld(playerid) > 0 || ProceedClassImmunity(playerid, ABILITY_STOMPER)) {
	    return false;
	}
	
	return true;
}

stock bool:IsAbleToBeCursed(const playerid) {
	if(GetPlayerVirtualWorld(playerid) > 0 || ProceedClassImmunity(playerid, ABILITY_WITCH)) {
	    return false;
	}
	
	return Round[playerid][rdIsCursed] == false;
}

stock bool:IsAbleToBePoisoned(const playerid) {
	if(GetPlayerVirtualWorld(playerid) > 0 || ProceedClassImmunity(playerid, ABILITY_POISON)) {
	    return false;
	}

	return Round[playerid][rdIsPoisoned] == false;
}

stock bool:IsAbleToBeFlashAttacked(const playerid) {
	if( !IsPlayerConnected(playerid) || GetPlayerVirtualWorld(playerid) > 0 ||
		ProceedClassImmunity(playerid, ABILITY_FLASH) || Round[playerid][rdIsEvacuated]) {
	    return false;
	}
	return true;
}

stock bool:IsAbleToBeFreezed(const playerid) {
    if(IsFrozen(playerid) || GetPlayerVirtualWorld(playerid) > 0 || ProceedClassImmunity(playerid, ABILITY_FREEZER)) {
        return false;
    }
    
	return true;
}

stock bool:IsAbleToBreakLegs(const playerid) {
	if(GetPlayerVirtualWorld(playerid) > 0 || ProceedClassImmunity(playerid, ABILITY_LEG_BREAK) || Round[playerid][rdIsLegsBroken]) {
	    return false;
	}
	
	return true;
}

stock bool:IsAbleToTakeAmmo(const playerid) {
	if(GetPlayerVirtualWorld(playerid) > 0 || ProceedClassImmunity(playerid, ABILITY_STEALER)) {
	    return false;
	}

	return true;
}

stock bool:IsAbleToRemoveWeapons(const playerid) {
    if(GetPlayerVirtualWorld(playerid) > 0 || ProceedClassImmunity(playerid, ABILITY_REMOVE_WEAPONS)) {
	    return false;
	}

	return true;
}

stock bool:IsAbleToBeAbsolved(const playerid) {
    if(GetPlayerVirtualWorld(playerid) > 0) {
	    return false;
	}
	
	return true;
}

stock bool:IsAbleToBeCured(const playerid) {
    if(GetPlayerVirtualWorld(playerid) > 0) {
	    return false;
	}
	
	return true;
}

stock bool:IsCursed(const playerid) {
    return Round[playerid][rdIsCursed];
}

stock bool:IsPoisoned(const playerid) {
    return Round[playerid][rdIsPoisoned];
}

stock bool:IsFrozen(const playerid) {
    return Round[playerid][rdFrozeTime] > 0;
}

stock bool:IsAbleToUseAbility(const playerid) {
	if(IsCursed(playerid) || IsPoisoned(playerid) || IsFrozen(playerid) || Round[playerid][rdIsEvacuated]) {
		return false;
	}
	
	return true;
}

stock bool:IsInfected(const playerid) {
    if(Round[playerid][rdIsInfected] || Round[playerid][rdIsAdvanceInfected]) {
	    return true;
	}
	
	return false;
}

stock DefaultCure(const playerid) {
    Round[playerid][rdIsInfected] = false;
    Round[playerid][rdIsAdvanceInfected] = false;
    SetPlayerDrunkLevel(playerid, 0);
    TextDrawHideForPlayer(playerid, ServerTextures[infectedTexture]);
    SetPlayerColor(playerid, COLOR_HUMAN);
    
    if(IsAbleToGivePointsInCategory(playerid, SESSION_CARE_POINTS)) {
    	RoundSession[playerid][rsdCare] += RoundConfig[rdCfgCare];
	}
	
	if(Iter_Contains(MutatedPlayers, playerid)) {
        Iter_Remove(MutatedPlayers, playerid);
    }
}

stock DefaultInfection(const playerid) {
    Round[playerid][rdIsInfected] = true;
}

stock SendInfectionMessage(const LOCALIZATION_DATA:localeid, const targetid, const playerid) {
    new formated[96];
	foreach(Player, i) {
		format(formated, sizeof(formated), Localization[i][localeid], Misc[targetid][mdPlayerName], Misc[playerid][mdPlayerName]);
		SendClientMessage(i, 0x009900FF, formated);
	}
}

stock IsInAbilityRange(const targetid, const playerid, const classid) {
	new Float:pos[3];
	GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
	return IsPlayerInRangeOfPoint(targetid, Classes[classid][cldDistance], pos[0], pos[1], pos[2]);
}

stock AbilityUsed(const playerid, const classid = -1, const abilityid = -1) {
    if(IsAbleToGivePointsInCategory(playerid, SESSION_ABILITY_POINTS)) {
    	RoundSession[playerid][rsdSkillfulness] += RoundConfig[rdCfgSkillfulness];
   	}
   	
   	if(classid > -1 && abilityid > -1) {
   		AbilitiesTimers[playerid][abilityid] = gettime() + Classes[classid][cldCooldown];
   	}
}

stock InfectPlayer(const playerid, const classid, const abilityid) {
	foreach(Humans, targetid) {
	    if(!IsInAbilityRange(targetid, playerid, classid)) continue;
		if(!IsAbleToBeInfected(targetid)) continue;

        DefaultInfection(targetid);
    	ApplyAnimation(playerid, "BIKELEAP", "bk_jmp", 3.1, 0, 0, 0, 0, 450);
    	SendInfectionMessage(LD_MSG_INFECTED_STANDARD, targetid, playerid);
    	AbilityUsed(playerid, classid, abilityid);
        return 1;
	}
	
    return 0;
}

stock InfectPlayerDrunk(const playerid, const classid, const abilityid) {
    foreach(Humans, targetid) {
	    if(!IsInAbilityRange(targetid, playerid, classid)) continue;
		if(!IsAbleToBeInfected(targetid)) continue;

        DefaultInfection(targetid);
        SetPlayerDrunkLevel(targetid, ServerConfig[svCfgInfectionDrunkLevel]);
    	ApplyAnimation(playerid, "BIKELEAP", "bk_jmp", 3.1, 0, 0, 0, 0, 450);
    	SendInfectionMessage(LD_MSG_MISTY_INFECTED, targetid, playerid);
    	AbilityUsed(playerid, classid, abilityid);
        return 1;
	}

    return 0;
}

stock InfectPlayerBlind(const playerid, const classid, const abilityid) {
    foreach(Humans, targetid) {
	    if(!IsInAbilityRange(targetid, playerid, classid)) continue;
		if(!IsAbleToBeInfected(targetid)) continue;

        DefaultInfection(targetid);
        Misc[targetid][mdBlindTimeout] = Classes[classid][cldAbilityTime];
       	TextDrawShowForPlayer(targetid, ServerTextures[blindTexture]);
    	ApplyAnimation(playerid, "BIKELEAP", "bk_jmp", 3.1, 0, 0, 0, 0, 450);
    	SendInfectionMessage(LD_MSG_BLIND_INFECTED, targetid, playerid);
    	AbilityUsed(playerid, classid, abilityid);
        return 1;
	}
	
	return 0;
}

stock InfectPlayerAdvanced(const playerid, const classid, const abilityid) {
    foreach(Humans, targetid) {
	    if(!IsInAbilityRange(targetid, playerid, classid)) continue;
		if(!IsAbleToBeInfected(targetid)) continue;

        Iter_Add(MutatedPlayers, targetid);

		Round[targetid][rdIsAdvanceInfected] = true;
    	ApplyAnimation(playerid, "BIKELEAP", "bk_jmp", 3.1, 0, 0, 0, 0, 450);
    	SendInfectionMessage(LD_MSG_INFECTED_MUTATED, targetid, playerid);
    	AbilityUsed(playerid, classid, abilityid);
    	return 1;
	}
	return 0;
}

stock PlayerInfectPlayer(const targetid, const playerid, const Float:range) {
	new Float:pos[3];
	GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
	
	if(!IsPlayerInRangeOfPoint(targetid, range, pos[0], pos[1], pos[2]) || !IsAbleToBeInfected(targetid)) {
	    return 0;
	}
    
    Iter_Add(MutatedPlayers, targetid);
	Round[targetid][rdIsAdvanceInfected] = true;
	SendInfectionMessage(LD_MSG_PLAYER_INFECT_PLAYER, targetid, playerid);
	return 1;
}

stock InfectPlayerFlesher(const targetid, const pickupid) {
	new playerid = Pickups[pickupid][pcdFromPlayer];
	
    if(!IsAbleToBeInfected(targetid) || !IsPlayerConnected(playerid) || GetPlayerTeamEx(playerid) != TEAM_ZOMBIE) {
	    return 0;
	}

    DefaultInfection(targetid);
    ApplyAnimation(targetid, "FOOD", "EAT_VOMIT_P", 4.1, 0, 0, 0, 0, 0);
    SendInfectionMessage(LD_MSG_INFECTED_FLESHER, targetid, playerid);
    AbilityUsed(playerid);
    return 1;
}

stock InfectPlayerSpore(const targetid, const playerid) {
    if(!IsAbleToBeInfected(targetid)) {
	    return 0;
	}

    DefaultInfection(targetid);
    SendInfectionMessage(LD_MSG_INFECTED_SPORE, targetid, playerid);
    AbilityUsed(playerid);
    return 1;
}

stock InfectPlayerSpitter(const targetid, const playerid) {
    if(!IsAbleToBeInfected(targetid)) {
	    return 0;
	}

    DefaultInfection(targetid);
    SendInfectionMessage(LD_MSG_INFECTED_SPITTER, targetid, playerid);
    AbilityUsed(playerid);
    return 1;
}

stock InfectAndExplode(const playerid, const classid) {
	new Float:pos[3], count, Float:range = Classes[classid][cldDistance];
	
	GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
	CreateExplosion(pos[0], pos[1], pos[2], 0, range);

	foreach(Humans, i) {
	    if(!IsAbleToBeInfected(i)) continue;
		if(IsPlayerInRangeOfPoint(i, range, pos[0], pos[1], pos[2])) {
	        DefaultInfection(i);
	        ++count;
	    }
	}
	
	if(count) {
	    new formated[96], LOCALIZATION_DATA:type = (count >= ClassesConfig[clsCfgWhoppingWhen]) ? LD_MSG_EXPLODED_WHOPPING : LD_MSG_EXPLODED;
	    foreach(Player, i) {
	    	format(formated, sizeof(formated), Localization[i][type], Misc[playerid][mdPlayerName], count);
			SendClientMessage(i, 0x009900FF, formated);
		}
		
		AbilityUsed(playerid);
	}
}

stock DamageFromRadioactiveField(const targetid, const playerid, const Float:amount, const classid) {
	if(!IsInAbilityRange(targetid, playerid, classid)) {
	    return 0;
	}
	
	Round[targetid][rdIsInRadioactiveField] = true;
	
	if(IsAbleToTakeRadioactiveDamage(targetid)) {
	    GameTextForPlayer(targetid, RusToGame(Localization[targetid][LD_DISPLAY_RADIOACTIVE]), 1500, 5);
	    SetPlayerHealthAC(targetid, GetPlayerHealthEx(targetid) - amount);

		Round[targetid][rdIsInRadioactiveField] = false;
		AbilityUsed(playerid);
		return 1;
	}
	
	return 1;
}

stock MirrorDamageBack(const targetid, const playerid, const Float:amount) {
    SetPlayerHealthAC(targetid, GetPlayerHealthEx(targetid) - amount);
    AbilityUsed(playerid);
}

stock StealArmour(const playerid, const classid, const abilityid) {
    foreach(Humans, targetid) {
        if(!IsAbleToTakeArmour(targetid)) continue;
    	if(IsInAbilityRange(targetid, playerid, classid)) {
            SetPlayerArmourAC(targetid, 0.0);

		    new formated[96];
			foreach(Player, i) {
				format(formated, sizeof(formated), Localization[i][LD_MSG_ARMOUR_STOLE], Misc[playerid][mdPlayerName], Misc[targetid][mdPlayerName]);
				SendClientMessage(i, 0x009900FF, formated);
			}
			
			ApplyAnimation(playerid, "CARRY", "putdwn05", 3.0, 0, 1, 1, 0, 410);
			AbilityUsed(playerid, classid, abilityid);
    	    return 1;
    	}
	}
	
	return 0;
}

stock StealAmmo(const playerid, const classid, const abilityid) {
    foreach(Humans, targetid) {
        if(!IsAbleToTakeAmmo(targetid)) continue;
    	if(IsInAbilityRange(targetid, playerid, classid)) {
		    new formated[96], gunname[32], index, weapon, ammo, bool: taken;
		    
		    for( index = 0; index < 9; index++ ) {
		    	GetPlayerWeaponData(targetid, index, weapon, ammo);
		    	if(ammo > 0) {
		    	    GetWeaponName(weapon, gunname, sizeof(gunname));
		    	    ammo = max(0, floatround(ammo / ClassesConfig[clsCfgStealAmmoFactor], floatround_tozero));
		    	    SetPVarInt(targetid, gunname, ammo);
                    SetPlayerAmmo(targetid, weapon, ammo);
                    taken = true;
		    	}
		    }
		    
		    if(taken) {
		        SetPlayerArmedWeapon(targetid, 0);
		    
				foreach(Player, i) {
					format(formated, sizeof(formated), Localization[i][LD_MSG_AMMO_STOLE], Misc[playerid][mdPlayerName], Misc[targetid][mdPlayerName]);
					SendClientMessage(i, 0x009900FF, formated);
				}

				ApplyAnimation(playerid, "CARRY", "putdwn05", 3.0, 0, 1, 1, 0, 410);
				AbilityUsed(playerid, classid, abilityid);
	    	    return 1;
    	    }
    	    
    	    return 0;
    	}
	}

	return 0;
}

stock BreakLegs(const playerid, const classid, const abilityid) {
    foreach(Humans, targetid) {
        if(!IsAbleToBreakLegs(targetid)) continue;
    	if(IsInAbilityRange(targetid, playerid, classid)) {
		    new formated[96];
			foreach(Player, i) {
				format(formated, sizeof(formated), Localization[i][LD_MSG_BREAK_LEGS], Misc[targetid][mdPlayerName], Misc[playerid][mdPlayerName]);
				SendClientMessage(i, 0x009900FF, formated);
			}

            Round[targetid][rdIsLegsBroken] = true;
			ApplyAnimation(playerid, "CARRY", "putdwn05", 3.0, 0, 1, 1, 0, 410);
			AbilityUsed(playerid, classid, abilityid);
    	    return 1;
    	}
	}

	return 0;
}

stock StompHumans(const playerid, const classid, const abilityid) {
    new Float:pos[3], count, objectid;
    foreach(Humans, targetid) {
        if(!IsAbleToBeStomped(targetid)) continue;
		if(IsInAbilityRange(targetid, playerid, classid)) {
        	GetPlayerVelocity(targetid, pos[0], pos[1], pos[2]);
			SetPlayerVelocity(targetid, pos[0] * ClassesConfig[clsCfgStomp][0], pos[1] * ClassesConfig[clsCfgStomp][1], pos[2] + ClassesConfig[clsCfgStomp][2]);
			++count;
    	}
	}
    
    if(count) {
        GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
		objectid = CreateObject(
			ClassesConfig[clsCfgStomperEffectId],
			pos[0] + ClassesConfig[clsCfgStomperEffectPos][0],
			pos[1] + ClassesConfig[clsCfgStomperEffectPos][1],
			pos[2] + ClassesConfig[clsCfgStomperEffectPos][2],
			0.0, 0.0, 0.0
		);
				
		ApplyAnimation(playerid, "CARRY", "putdwn05", 3.0, 0, 1, 1, 0, 410);
		SetTimerEx("DestroyObjectEffect", ClassesConfig[clsCfgStomperEffectTime], 0, "i", objectid);
		AbilityUsed(playerid, classid, abilityid);
	}
	return 1;
}

stock CurseHuman(const playerid, const classid, const abilityid) {
    foreach(Humans, targetid) {
        if(!IsAbleToBeCursed(targetid)) continue;
    	if(IsInAbilityRange(targetid, playerid, classid)) {
		    new formated[96];
			foreach(Player, i) {
				format(formated, sizeof(formated), Localization[i][LD_MSG_CURSE_PLAYER], Misc[targetid][mdPlayerName], Misc[playerid][mdPlayerName]);
				SendClientMessage(i, 0x009900FF, formated);
			}

			ApplyAnimation(playerid, "CARRY", "putdwn05", 3.0, 0, 1, 1, 0, 410);
			AbilityUsed(playerid, classid, abilityid);
    	    return 1;
    	}
	}

	return 0;
}

stock FlashAttackOnHuman(const playerid, const classid, const abilityid) {
	new targetid = Iter_Random(Humans);
 	if(IsAbleToBeFlashAttacked(targetid)) {
		new Float:pos[3], Float:old[3], objectid;
        GetPlayerPos(playerid, old[0], old[1], old[2]);
        GetPlayerPos(targetid, pos[0], pos[1], pos[2]);
        
        SetPlayerPos(playerid, pos[0], pos[1], pos[2]);
        GetXYInFrontOfPlayer(playerid, pos[0], pos[1], 1.0);
        
        objectid = CreateObject(ClassesConfig[clsCfgFlasherEffectId], pos[0], pos[1], pos[2] - 2.0, 0.0, 0.0, 0.0);
       	SetTimerEx("DestroyObjectEffectAndExplosion", (ClassesConfig[clsCfgFlasherEffectTime] * 1000), 0, "ifff", objectid, pos[0], pos[1], pos[2]);
       	
       	SetTimerEx("MovePlayerAfterEffect", 900, 0, "ifff", playerid, old[0], old[1], old[2]);
        ApplyAnimation(playerid, "CARRY", "PUTDWN", 4.1, 0, 0, 0, 0, 850);
        AbilityUsed(playerid, classid, abilityid);
        return 1;
  	}
     
   	return 0;
}

stock MimicrySkin(const playerid, const classid, const abilityid) {
	static const getRandomSkinQuery[] = GET_RANDOM_SKIN_QUERY;
	new formated[sizeof(getRandomSkinQuery) + MAX_CLASS_ID_LEN], team = (GetPlayerTeamEx(playerid) == TEAM_HUMAN) ? TEAM_ZOMBIE : TEAM_HUMAN;
	mysql_format(Database, formated, sizeof(formated), getRandomSkinQuery, team);
    mysql_tquery(Database, formated, "GetMimicrySkin", "i", playerid);

    (team == TEAM_HUMAN) && SetPlayerColor(playerid, COLOR_HUMAN) || SetPlayerColor(playerid, COLOR_ZOMBIE);
    
    Misc[playerid][mdMimicry][0] = GetPlayerSkin(playerid);
    Misc[playerid][mdMimicry][1] = GetPlayerTeamEx(playerid);
    Misc[playerid][mdMimicry][2] = Classes[classid][cldAbilityTime];
    Misc[playerid][mdMimicryStats][0] = GetPlayerHealthEx(playerid);
    Misc[playerid][mdMimicryStats][1] = GetPlayerArmourEx(playerid);
    
    SetPlayerArmourAC(playerid, 0.0);
    AbilityUsed(playerid, classid, abilityid);
    return 1;
}

stock ProceedMimicryChangeBack(const playerid) {
	if(Misc[playerid][mdMimicry][2] > 0) {
 		Misc[playerid][mdMimicry][2]--;
   		if(Misc[playerid][mdMimicry][2] == 0) {
   		    new color = GetPlayerColor(playerid);
   		
     		switch(Misc[playerid][mdMimicry][1]) {
       			case TEAM_HUMAN: {
       			    if(color == COLOR_ZOMBIE) {
				   		SetPlayerColor(playerid, COLOR_HUMAN);
				   	}
				}
          		case TEAM_ZOMBIE: {
          		    if(color == COLOR_HUMAN) {
				  		SetPlayerColor(playerid, COLOR_ZOMBIE);
				  	}
				}
       		}
       		
       		SetPlayerSkin(playerid, Misc[playerid][mdMimicry][0]);
			SetPlayerHealthAC(playerid, Misc[playerid][mdMimicryStats][0]);
			SetPlayerArmourAC(playerid, Misc[playerid][mdMimicryStats][1]);
   			ClearAnimations(playerid);
      		Misc[playerid][mdMimicry][2] = -1;
   		}
	}
}

stock FreezePlayers(const playerid, const classid, const abilityid) {
    new count;
    foreach(Humans, targetid) {
		if(!IsAbleToBeFreezed(targetid)) continue;
        if(IsInAbilityRange(targetid, playerid, classid)) {
			TogglePlayerControllable(targetid, 0);
			Round[targetid][rdFrozeTime] = Classes[classid][cldAbilityTime];
			SetCameraBehindPlayer(targetid);
			++count;
        }
    }
    
    if(count) {
        new formated[64], LOCALIZATION_DATA:type = (count >= ClassesConfig[clsCfgWhoppingWhen]) ? LD_MSG_FROZE_WHOPPING : LD_MSG_FROZE;
	    foreach(Player, i) {
	    	format(formated, sizeof(formated), Localization[i][type], Misc[playerid][mdPlayerName], count);
			SendClientMessage(i, 0x009900FF, formated);
		}
    
        ApplyAnimation(playerid, "CARRY", "putdwn05", 3.0, 0, 1, 1, 0, 410);
        AbilityUsed(playerid, classid, abilityid);
    }
    
    return 1;
}

stock PlayerInHolyField(const targetid, const playerid, const classid) {
    if(!IsAbleToBeAbsolved(targetid) || !IsInAbilityRange(targetid, playerid, classid)) {
        return 0;
    }
    
	if(IsCursed(targetid)) {
	    Round[targetid][rdIsCursed] = false;

	    new formated[96];
	    foreach(Player, i) {
	    	format(formated, sizeof(formated), Localization[i][LD_MSG_ABSOLVE_SINS], Misc[playerid][mdPlayerName], Misc[targetid][mdPlayerName]);
			SendClientMessage(i, 0xB2F558FF, formated);
		}
		
		AbilityUsed(playerid);
	}
	
	return 1;
}

stock PlayerInRemoveField(const targetid, const playerid, const classid) {
    if(!IsAbleToRemoveWeapons(targetid) || !IsInAbilityRange(targetid, playerid, classid)) {
        return 0;
    }
    
    GameTextForPlayer(targetid, RusToGame(Localization[playerid][LD_DISPLAY_WEAPS_REMOVED]), 1000, 5);
	SetPlayerArmedWeapon(targetid, 0);
	AbilityUsed(playerid);
	return 1;
}

stock CurePlayerInField(const targetid, const playerid, const classid) {
    if(!IsAbleToBeCured(targetid) || !IsInAbilityRange(targetid, playerid, classid)) {
        return 0;
    }

	Round[targetid][rdIsInRadioactiveField] = false;
    	        
    if(!IsInfected(targetid)) {
	    return 0;
	}

    DefaultCure(targetid);
    AbilityUsed(playerid);
    
    new formated[96];
   	foreach(Player, i) {
   		format(formated, sizeof(formated), Localization[i][LD_MSG_CURE_NURSE_FIELD], Misc[playerid][mdPlayerName]);
		SendClientMessage(i, 0xB2F558FF, formated);
	}
	
    return 1;
}

stock CurePlayerByShot(const targetid, const playerid) {
	if(!IsInfected(targetid)) {
	    return 0;
	}

    DefaultCure(targetid);
    AbilityUsed(playerid);
    
    new formated[96];
   	foreach(Player, i) {
   		format(formated, sizeof(formated), Localization[i][LD_MSG_CURE_RIFLE], Misc[targetid][mdPlayerName], Misc[playerid][mdPlayerName]);
		SendClientMessage(i, 0xB2F558FF, formated);
	}
    return 1;
}

stock PoisePlayerByShot(const targetid, const playerid) {
	if(!IsAbleToBePoisoned(targetid)) {
	    return 0;
	}

    Round[targetid][rdIsPoisoned] = true;
    SetPlayerColor(targetid, COLOR_POISONED);
    AbilityUsed(playerid);

    new formated[96];
   	foreach(Player, i) {
   		format(formated, sizeof(formated), Localization[i][LD_MSG_PLAYER_POISONED], Misc[targetid][mdPlayerName], Misc[playerid][mdPlayerName]);
		SendClientMessage(i, 0x6e14b8FF, formated);
	}
    return 1;
}

stock CurePlayer(const playerid) {
    if(!IsInfected(playerid)) {
	    return 0;
	}
	
    DefaultCure(playerid);
    return 1;
}

stock RegenerateHealth(const targetid, const playerid, const Float:amount, const parentClassId = -1) {
	if(parentClassId > -1 && !IsInAbilityRange(targetid, playerid, parentClassId)) {
	    return 0;
	}

	new team = GetPlayerTeamEx(targetid);
    new classid = Misc[targetid][mdCurrentClass][team];
    
    if(GetPlayerHealthEx(targetid) < (Classes[classid][cldHealth] + amount)) {
        GameTextForPlayer(targetid, RusToGame(Localization[targetid][LD_DISPLAY_REGENERATION]), 1000, 5);
   		SetPlayerHealthAC(targetid, GetPlayerHealthEx(targetid) + amount);
   		AbilityUsed(playerid);
	}
	
	return 1;
}

stock EnableDisableSupportField(const playerid) {
    new formated[32];
    if(Iter_Contains(SupportPlayers, playerid)) {
		Iter_Remove(SupportPlayers, playerid);
		format(formated, sizeof(formated), RusToGame(Localization[playerid][LD_DISPLAY_SPF_STATUS]), Localization[playerid][LD_DISPLAY_OFF]);
        GameTextForPlayer(playerid, formated, 1000, 5);
	} else {
	    Iter_Add(SupportPlayers, playerid);
	    format(formated, sizeof(formated), RusToGame(Localization[playerid][LD_DISPLAY_SPF_STATUS]), Localization[playerid][LD_DISPLAY_ON]);
        GameTextForPlayer(playerid, formated, 1000, 5);
	}
}

stock EnableDisableRadioActiveField(const playerid) {
    new formated[32];
    if(Iter_Contains(RadioactivePlayers, playerid)) {
		Iter_Remove(RadioactivePlayers, playerid);
		format(formated, sizeof(formated), RusToGame(Localization[playerid][LD_DISPLAY_RDF_STATUS]), Localization[playerid][LD_DISPLAY_OFF]);
        GameTextForPlayer(playerid, formated, 1000, 5);
	} else {
	    Iter_Add(RadioactivePlayers, playerid);
	    format(formated, sizeof(formated), RusToGame(Localization[playerid][LD_DISPLAY_RDF_STATUS]), Localization[playerid][LD_DISPLAY_ON]);
        GameTextForPlayer(playerid, formated, 1000, 5);
	}
}

stock EnableDisableCureField(const playerid) {
    new formated[32];
    if(Iter_Contains(NursePlayers, playerid)) {
		Iter_Remove(NursePlayers, playerid);
		format(formated, sizeof(formated), RusToGame(Localization[playerid][LD_DISPLAY_CRF_STATUS]), Localization[playerid][LD_DISPLAY_OFF]);
        GameTextForPlayer(playerid, formated, 1000, 5);
	} else {
	    Iter_Add(NursePlayers, playerid);
	    format(formated, sizeof(formated), RusToGame(Localization[playerid][LD_DISPLAY_CRF_STATUS]), Localization[playerid][LD_DISPLAY_ON]);
        GameTextForPlayer(playerid, formated, 1000, 5);
	}
}

stock EnableDisableHolyField(const playerid) {
    new formated[32];
    if(Iter_Contains(PriestPlayers, playerid)) {
		Iter_Remove(PriestPlayers, playerid);
		format(formated, sizeof(formated), RusToGame(Localization[playerid][LD_DISPLAY_HLF_STATUS]), Localization[playerid][LD_DISPLAY_OFF]);
        GameTextForPlayer(playerid, formated, 1000, 5);
	} else {
	    Iter_Add(PriestPlayers, playerid);
	    format(formated, sizeof(formated), RusToGame(Localization[playerid][LD_DISPLAY_HLF_STATUS]), Localization[playerid][LD_DISPLAY_ON]);
        GameTextForPlayer(playerid, formated, 1000, 5);
	}
}

stock EnableDisableRemoveWeapons(const playerid) {
    new formated[32];
    if(Iter_Contains(RemoveWeaponsPlayers, playerid)) {
		Iter_Remove(RemoveWeaponsPlayers, playerid);
		format(formated, sizeof(formated), RusToGame(Localization[playerid][LD_DISPLAY_REMOVE_WEAPS_FIELD]), Localization[playerid][LD_DISPLAY_OFF]);
        GameTextForPlayer(playerid, formated, 1000, 5);
	} else {
	    Iter_Add(RemoveWeaponsPlayers, playerid);
	    format(formated, sizeof(formated), RusToGame(Localization[playerid][LD_DISPLAY_REMOVE_WEAPS_FIELD]), Localization[playerid][LD_DISPLAY_ON]);
        GameTextForPlayer(playerid, formated, 1000, 5);
	}
}

stock GiveSpitterWeapon(const playerid, const classid, const abilityid) {
	if(GetPlayerWeaponAmmo(playerid, ClassesConfig[clsCfgSpitterWeapon]) > 0) {
	    return 0;
	}

	GivePlayerWeaponAC(playerid, ClassesConfig[clsCfgSpitterWeapon], Classes[classid][cldAbilityCount]);
	AbilityUsed(playerid, classid, abilityid);
    return 1;
}

stock HighJump(const playerid, const classid, const abilityid) {
    new Float:pos[3];
    GetPlayerVelocity(playerid, pos[0], pos[1], pos[2]);
    SetPlayerVelocity(playerid,
		pos[0] * ClassesConfig[clsCfgHighJump][0],
		pos[1] * ClassesConfig[clsCfgHighJump][1],
		pos[2] + ClassesConfig[clsCfgHighJump][2]
	);
	
	AbilityUsed(playerid, classid, abilityid);
	return 1;
}

stock LongJump(const playerid, const classid) {
    if( Round[playerid][rdAbilityTimes] > 0) {
	    new Float:pos[3];
	    GetPlayerCameraFrontVector(playerid, pos[0], pos[1], pos[2]);
		SetPlayerVelocity(playerid,
			pos[0] /  ClassesConfig[clsCfgLongJump][0],
			pos[1] / ClassesConfig[clsCfgLongJump][1],
			pos[2] + ClassesConfig[clsCfgLongJump][2]
		);
		
		AbilitiesTimers[playerid][ABILITY_LONG_JUMPS] = gettime() + Classes[classid][cldCooldown];
		Round[playerid][rdAbilityTimes]--;
		AbilityUsed(playerid);
		return 1;
	}
	
	return 0;
}

stock ProceedRecoveryLongJumps(const playerid) {
    new classid = Misc[playerid][mdCurrentClass][GetPlayerTeamEx(playerid)];
	if( AbilitiesTimers[playerid][ABILITY_LONG_JUMPS] > 0 &&
		gettime() > AbilitiesTimers[playerid][ABILITY_LONG_JUMPS] &&
		Round[playerid][rdAbilityTimes] < Classes[classid][cldAbilityCount]) {
	    Round[playerid][rdAbilityTimes]++;
	    AbilitiesTimers[playerid][ABILITY_LONG_JUMPS] = gettime() + Classes[classid][cldCooldown];
	}
}

stock ProceedSpaceDamage(const playerid) {
    if(gettime() > AbilitiesTimers[playerid][ABILITY_SPACEBREAKER] && GetPlayerVirtualWorld(playerid) > 0) {
        GameTextForPlayer(playerid, RusToGame(Localization[playerid][LD_DISPLAY_SPACE_DAMAGE]), 1000, 5);
        SetPlayerHealthAC(playerid, GetPlayerHealthEx(playerid) - 5.0);
    }
}

stock BreakSpace(const playerid, const classid, const abilityid) {
	new world = GetPlayerVirtualWorld(playerid);
	AbilityUsed(playerid, classid, abilityid);
	
	if(world > 0) {
	    SetPlayerVirtualWorld(playerid, 0);
        SetPlayerWeather(playerid, Map[mpWeather]);
		SetPlayerTime(playerid, Map[mpTime], 0);
	} else {
	    SetPlayerVirtualWorld(playerid, 1);
        SetPlayerWeather(playerid, 101);
		SetPlayerTime(playerid, 10, 0);
	}
	return 1;
}

stock BuildBox(const playerid, const classid) {
	if(Round[playerid][rdBoxCount] > -1) {
	    new str[32], Float: pos[4], index = Round[playerid][rdBoxCount];
		new cr = (Classes[classid][cldAbilityCount] - index) + 1;
		new mx = Classes[classid][cldAbilityCount] + 1;

		GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
		GetPlayerFacingAngle(playerid, pos[3]);
	    GetXYInFrontOfPlayer(playerid, pos[0], pos[1], 1.0);

        format(str, sizeof(str), "%s - [%d / %d]", Misc[playerid][mdPlayerName], cr, mx);
		Round[playerid][rdBox][index] = CreateObject(
			ClassesConfig[clsCfgEngineerBox],
			pos[0], pos[1], pos[2],
			0.0, 0.0, pos[3]
		);
		
		MoveObject(Round[playerid][rdBox][index], pos[0], pos[1], pos[2] + 2.5, 0.0000001);

		Round[playerid][rdBoxText][index] = Create3DTextLabel(str, COLOR_HUMAN,
			pos[0], pos[1], pos[2],
			ClassesConfig[clsCfgEngineerTextRange],
			0, 0
		);

		Round[playerid][rdBoxCount]--;
		PlayerPlaySound(playerid,
			ClassesConfig[clsCfgEngineerSound],
			0.0, 0.0, 0.0
		);
		
		AbilityUsed(playerid);
		return 1;
	}

	return 0;
}

stock ProceedAuthTimeoutKick(const playerid) {
	if(Misc[playerid][mdKickForAuthTimeout] > 0) {
		Misc[playerid][mdKickForAuthTimeout]--;
		if(Misc[playerid][mdKickForAuthTimeout] == 0) {
			KickForAuthTimeout(playerid);
			Misc[playerid][mdKickForAuthTimeout] = -1;
			return 1;
		}
	}
   	return 0;
}

stock ProceedBlind(const playerid) {
    if(Misc[playerid][mdBlindTimeout] > 0) {
        Misc[playerid][mdBlindTimeout]--;
        if(Misc[playerid][mdBlindTimeout] == 0) {
            TextDrawHideForPlayer(playerid, ServerTextures[blindTexture]);
            Misc[playerid][mdBlindTimeout] = -1;
        }
    }
}

stock ProceedInfection(const playerid) {
    if(IsInfected(playerid)) {
    	SetPlayerColor(playerid, COLOR_INFECTED);
    	TextDrawShowForPlayer(playerid, ServerTextures[infectedTexture]);
    	SetPlayerHealthAC(playerid, GetPlayerHealthEx(playerid) - ServerConfig[svCfgInfectionDamage]);
	}
}

stock ProceedUnfreeze(const playerid) {
    if(IsFrozen(playerid)) {
	    Round[playerid][rdFrozeTime]--;
	    if(Round[playerid][rdFrozeTime] == 0) {
	    	Round[playerid][rdFrozeTime] = -1;
	    	TogglePlayerControllable(playerid, 1);
	    	ClearAnimations(playerid);
	    }
	}
}

stock PrepareRandomTip() {
	if(gettime() > ServerConfig[svCfgLastTipMessage]) {
        ServerConfig[svCfgLastTipMessage] = gettime() + ServerConfig[svCfgTipMessageCooldown];
        return random(_:TIP_MSG_MAX);
	}

	return -1;
}

stock ProceedRandomTip(const playerid, const index, buffer[], const len = sizeof(buffer)) {
    if(index > -1) {
    	format(buffer, len, LocalizedTips[playerid][TIPS_DATA:index]);
     	SendClientMessage(playerid, 0xc25b89FF, buffer);
	}
}

stock Float:GetXYInFrontOfPlayer(playerid, &Float:q, &Float:w, Float:distance)
{
	new Float:a;
	GetPlayerPos(playerid, q, w, a);
	if (GetPlayerState(playerid) == PLAYER_STATE_DRIVER) GetVehicleZAngle(GetPlayerVehicleID(playerid), a);
	else GetPlayerFacingAngle(playerid, a);
	q += (distance * floatsin(-a, degrees));
	w += (distance * floatcos(-a, degrees));
	return a;
}

stock CreateObjectsCircular(objectid, Float:px, Float:py, Float:pz, Float:rx, Float:ry, ammount, Float:radius, time, Float:angle = 360.0, bool:circleangles = true, Float:rz = 0.0) {
	if(ammount <= 1 || 0.0 <= angle > 360.0 || radius <= 0.0) {
		return 0;
	}
	
	for(new i = 0; i <= ammount; i++) {
		new obj = CreateObject(objectid, px+floatsin((angle/ammount)*i, degrees)*radius, py+floatcos((angle/ammount)*i, degrees)*radius, pz, rx, ry, circleangles ? ((-angle/ammount)*i) : (rz));
        SetTimerEx("DestroyObjectEffect", time * 1000, 0, "i", obj);
	}
	return 1;
}

stock ProceedPickupAction(const playerid, const pickupid) {
	if(Pickups[pickupid][pcdModel] == ServerConfig[svCfgMeatPickup]) {
	    switch(GetPlayerTeamEx(playerid)) {
	        case TEAM_ZOMBIE: {
                new classid = Misc[playerid][mdCurrentClass][TEAM_ZOMBIE];
	        	SetPlayerHealthAC(playerid, Classes[classid][cldHealth]);
	        	return 1;
	        }
	        case TEAM_HUMAN: {
	            if(IsInfected(playerid)) {
	                if(random(ServerConfig[svCfgAntidoteChance]) == 0) {
	                	CurePlayer(playerid);
	                	GameTextForPlayer(playerid,  RusToGame(Localization[playerid][LD_ANY_ANTIDOTE]), 2000, 5);
	                }
	                return 1;
	            }
	            
	            if(random(ServerConfig[svCfgAmmoChance]) == 0) {
		            new weapon = GetPlayerWeapon(playerid);
				    new index = GetWeaponFromConfigById(weapon);
				    new amount = (index > -1) ? 1 + random(WeaponsConfig[index][wdCfgPick]) : 1;
				    new formated[48];

				    GivePlayerWeapon(playerid, weapon, amount);
				    format(formated, sizeof(formated), RusToGame(Localization[playerid][LD_ANY_AMMO_PICKUP]), amount);
				    GameTextForPlayer(playerid, formated, 2000, 5);
				    return 1;
				}
				
                ProceedPassiveAbility(pickupid, ABILITY_FLESHER, playerid);
                return 1;
	        }
	    }
	}
	
	return 1;
}

stock CreateDropOnDeath(const playerid, const killerid) {
	new Float:pos[3];
	GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
  	CreatePickupEx(ServerConfig[svCfgMeatPickup], STATIC_PICKUP_TYPE, pos[0], pos[1], pos[2], GetPlayerVirtualWorld(playerid), playerid, IsPlayerConnected(killerid) ? killerid : -1);
  	SetPlayerTeamAC(playerid, TEAM_ZOMBIE);
  	
  	ProceedPassiveAbility(playerid, ABILITY_BOOMER);
	return 1;
}

bool:IsValidPickupEx(const pickupid) {
	return (pickupid < 0 || pickupid >= (MAX_PICKUPS - 1)) ? false : Pickups[pickupid][pcdIsActive];
}

bool:IsAbleToPickup(const playerid, const pickupid) {
	if(!IsValidPickupEx(pickupid)) {
	    return false;
	}
	
	return Pickups[pickupid][pcdForPlayer] == -1 || !IsPlayerConnected(playerid) ||
	playerid == Pickups[pickupid][pcdForPlayer] || gettime() >= Pickups[pickupid][pcdProtectionTill];
}

stock CreatePickupEx(const pickupid, const type, const Float:x, const Float:y, const Float:z, const world, const playerid = -1, const killerid = -1) {
	if(pickupid < 0) {
	    return pickupid;
	}

	new id = CreatePickup(pickupid, type, x, y, z, world);
    if(id >= 0 && pickupid <= MAX_PICKUPS) {
	 	Pickups[id][pcdId] = id;
	 	Pickups[id][pcdModel] = pickupid;
	 	Pickups[id][pcdProtectionTill] = gettime() + ServerConfig[svCfgPickupProtection];
	 	Pickups[id][pcdFromPlayer] = playerid;
	 	Pickups[id][pcdForPlayer] = killerid;
	 	Pickups[id][pcdIsActive] = true;
	}
	return id;
}

stock DestroyPickupEx(const pickupid) {
    if(IsValidPickupEx(pickupid)) {
        Pickups[pickupid][pcdId] = -1;
        Pickups[pickupid][pcdModel] = -1;
	 	Pickups[pickupid][pcdProtectionTill] = 0;
	 	Pickups[pickupid][pcdFromPlayer] = -1;
	 	Pickups[pickupid][pcdForPlayer] = -1;
	 	Pickups[pickupid][pcdIsActive] = false;
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

stock GetPlayerWeaponAmmo(const playerid, const weapid) {
    new gunname[32];
    GetWeaponName(weapid, gunname, sizeof(gunname));
    return GetPVarInt(playerid, gunname);
}

stock GivePlayerWeaponAC(const playerid, const weapid, const ammo) {
    new gunname[32], stack = min(ServerConfig[svCfgMaxWeaponAmmo], GetPVarInt(playerid, gunname) + ammo);
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

stock ShowDamageTaken(const playerid, const Float:damage = 0.0) {
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

stock ClassSetup(const playerid, const classid) {
    new i, weapons[9], index, amount;
    SetPlayerSkin(playerid, Classes[classid][cldSkin]);
    SetPlayerHealthAC(playerid, Classes[classid][cldHealth]);
    SetPlayerArmourAC(playerid, Classes[classid][cldArmour]);

    sscanf(Classes[classid][cldWeapons], "p<,>iiiiiiiii", weapons[0],
		weapons[1], weapons[2], weapons[3], weapons[4], weapons[5],
		weapons[6], weapons[7], weapons[8]
	);

	for( i = 0; i < sizeof(weapons); i++ ) {
	    if(!weapons[i]) continue;
	    index = GetWeaponFromConfigById(weapons[i]);
        amount = (index > -1) ? WeaponsConfig[index][wdCfgDefault] : 1;
	    GivePlayerWeaponAC(playerid, weapons[i], amount);
	}
	
	Round[playerid][rdBoxCount] = Classes[classid][cldAbilityCount];
	Round[playerid][rdAbilityTimes] = Classes[classid][cldAbilityCount];
}

stock SetZombie(const playerid, const classid) {
    SetPlayerColor(playerid, COLOR_ZOMBIE);
    ClassSetup(playerid, classid);
    
    if(Round[playerid][rdIsZombieBoss]) {
        SetPlayerArmourAC(playerid, MapConfig[mpCfgZombieBossArmour]);
        SetPlayerColor(playerid, COLOR_ZOMBIE_BOSS);
    }
}

stock SetHuman(const playerid, const classid) {
    SetPlayerColor(playerid, COLOR_HUMAN);
    ClassSetup(playerid, classid);
    
    if(Round[playerid][rdIsHumanHero]) {
        new weapons[2];
        sscanf(MapConfig[mpCfgHumanHeroWeapons], "p<,>ii", weapons[0], weapons[1]);
        GivePlayerWeaponAC(playerid, weapons[0], floatround(ServerConfig[svCfgMaxWeaponAmmo] / 2, floatround_tozero));
        GivePlayerWeaponAC(playerid, weapons[1], floatround(ServerConfig[svCfgMaxWeaponAmmo] / 2, floatround_tozero));
        SetPlayerArmourAC(playerid, MapConfig[mpCfgHumanHeroArmour]);
        SetPlayerColor(playerid, COLOR_HUMAN_HERO);
    }
}

stock SetUnknown(const playerid) {
	SetPlayerTeamAC(playerid, TEAM_UNKNOWN);
}

stock ResetMapValuesOnDeath(const playerid) {
    if(Round[playerid][rdIsEvacuated]) {
	    Map[mpEvacuatedHumans]--;
	}
	
	Misc[playerid][mdLastIssuedDamage] = -1;
    Misc[playerid][mdLastIssuedReason] = 0;
}

stock ResetValuesOnDisconnect(const playerid) {
	if(Misc[playerid][mdIsLogged]) {
    	ServerConfig[svCfgCurrentOnline]--;
    }
    
   	switch(GetPlayerTeamEx(playerid)) {
    	case TEAM_ZOMBIE: {
     		if(Map[mpTeamCount][0] >= 1) {
        		Map[mpTeamCount][0]--;
    		}
    		
			Iter_Remove(Zombies, playerid);
        }
        
        case TEAM_HUMAN: {
            if(Map[mpTeamCount][1] >= 1) {
        		Map[mpTeamCount][1]--;
    		}
    		
            Iter_Remove(Humans, playerid);
        }
    }
    
    ClearFromIterators(playerid);
    ClearPlayerRoundData(playerid);
    Round[playerid][rdIsHumanHero] = false;
	Round[playerid][rdIsZombieBoss] = false;
}

stock ClearFromIterators(const playerid) {
    if(Iter_Contains(MutatedPlayers, playerid)) {
        Iter_Remove(MutatedPlayers, playerid);
    }

    if(Iter_Contains(RadioactivePlayers, playerid)) {
		Iter_Remove(RadioactivePlayers, playerid);
	}

	if(Iter_Contains(NursePlayers, playerid)) {
	    Iter_Remove(NursePlayers, playerid);
	}

	if(Iter_Contains(PriestPlayers, playerid)) {
	    Iter_Remove(PriestPlayers, playerid);
	}

	if(Iter_Contains(SupportPlayers, playerid)) {
		Iter_Remove(SupportPlayers, playerid);
	}
	
	if(Iter_Contains(RemoveWeaponsPlayers, playerid)) {
		Iter_Remove(RemoveWeaponsPlayers, playerid);
	}
}

stock GetWeaponFromConfigById(const weaponid) {
    for( new i; i < MAX_WEAPONS; i++ ) {
        if(WeaponsConfig[i][wdCfgType] == weaponid) {
            return i;
        }
	}
	
	return -1;
}

stock SpawnCrystalOnMapEnd() {
    if(!Map[mpTimeoutBeforeCrystal] && Map[mpGang] <= 0) {
	    Map[mpCrystal] = CreateObject(Map[mpGangCrystalId],
			Map[mpGangCrystalSpawn][0], Map[mpGangCrystalSpawn][1],
			Map[mpGangCrystalSpawn][2], 0.0, 0.0, Map[mpGangCrystalSpawn][3]
		);
		
		Map[mpTimeoutBeforeCrystal] = true;
		Map[mpTimeoutBeforeEnd] = MapConfig[mpCfgBalance];

		new text[256];
		format(text, sizeof(text), CRYSTAL_STONE_TEXT, Map[mpCrystalHealth]);
	//	Map[mpFlagText] = Create3DTextLabel(text, 0xFFF000FF, Map[mpGangCrystalSpawn][0], Map[mpGangCrystalSpawn][1], Map[mpGangCrystalSpawn][2], GangsConfig[gdCfgFlagDistance], 0, 0);

		foreach(Player, i) {
		    SendClientMessage(i, 0xb823b3FF, Localization[i][LD_MSG_MAP_CRYSTAL_DAMAGE]);
		    if(Misc[i][mdGangRank]) {
                SetPlayerInterior(i, 0);
				DisablePlayerCheckpoint(i);
				SetPlayerPos(i, Map[mpGangNearCrystalSpawn][0], Map[mpGangNearCrystalSpawn][1], Map[mpGangNearCrystalSpawn][2]);
				SetPlayerFacingAngle(i, Map[mpGangNearCrystalSpawn][3]);
				SetUnknown(i);
				SetPlayerVirtualWorld(i, 2500);
			}
		}
		
		return 1;
	}
	
	return 0;
}

stock CreateTextureFromConfig(&Text:texid, const buffer) {
	texid = TextDrawCreate(
		ServerTexturesConfig[buffer][svTxCfgTexturePosition][0],
		ServerTexturesConfig[buffer][svTxCfgTexturePosition][1],
		ServerTexturesConfig[buffer][svTxCfgTextureDefaultValue]
	);

	TextDrawLetterSize(texid, ServerTexturesConfig[buffer][svTxCfgTextureLetterSize][0], ServerTexturesConfig[buffer][svTxCfgTextureLetterSize][1]);
    TextDrawBackgroundColor(texid, ServerTexturesConfig[buffer][svTxCfgTextureBackgroundColor]);
    TextDrawFont(texid, ServerTexturesConfig[buffer][svTxCfgTextureFont]);
    TextDrawColor(texid, ServerTexturesConfig[buffer][svTxCfgTextureDrawColor]);
    TextDrawSetOutline(texid, ServerTexturesConfig[buffer][svTxCfgTextureOutline]);
    TextDrawSetProportional(texid, ServerTexturesConfig[buffer][svTxCfgTextureProportional]);
    TextDrawSetShadow(texid, ServerTexturesConfig[buffer][svTxCfgTextureShadow]);
    TextDrawAlignment(texid, ServerTexturesConfig[buffer][svTxCfgTextureAlignment]);

    if(ServerTexturesConfig[buffer][svTxCfgTextureTextSize][0] > 0.0 || ServerTexturesConfig[buffer][svTxCfgTextureTextSize][1] > 0.0) {
    	TextDrawTextSize(texid, ServerTexturesConfig[buffer][svTxCfgTextureTextSize][0], ServerTexturesConfig[buffer][svTxCfgTextureTextSize][1]);
    }

    if(ServerTexturesConfig[buffer][svTxCfgTextureUseBox]) {
		TextDrawUseBox(texid, ServerTexturesConfig[buffer][svTxCfgTextureUseBox]);
		TextDrawBoxColor(texid, ServerTexturesConfig[buffer][svTxCfgTextureBoxColor]);
		TextDrawTextSize(texid, ServerTexturesConfig[buffer][svTxCfgTextureTextSize][0], ServerTexturesConfig[buffer][svTxCfgTextureTextSize][1]);
	}
}

stock PredictPreferedLocalization(const playerid) {
    new symbolPos = strfind(Misc[playerid][mdPlayerName], "_", true);
	if(symbolPos != -1 && symbolPos + 1 < strlen(Misc[playerid][mdPlayerName])) {
	    switch(Misc[playerid][mdPlayerName][symbolPos + 1]) {
	        case 'a'..'z', 'A'..'Z': Player[playerid][pLanguage] = 1;
	        default: Player[playerid][pLanguage] = 0;
	    }
	}
}

stock RusToGame(const string[]) {
    new result[128];
    for( new i; i < 128; i++ ) {
    	switch(string[i]) {
      		case 'à':result[i] = 'a';
      		case 'À':result[i] = 'A';
      		case 'á':result[i] = '—';
	      	case 'Á':result[i] = '€';
	      	case 'â':result[i] = '¢';
	      	case 'Â':result[i] = '‹';
	      	case 'ã':result[i] = '™';
	      	case 'Ã':result[i] = '‚';
	      	case 'ä':result[i] = 'š';
	      	case 'Ä':result[i] = 'ƒ';
	      	case 'å':result[i] = 'e';
	      	case 'Å':result[i] = 'E';
	      	case '¸':result[i] = 'e';
	      	case '¨':result[i] = 'E';
	      	case 'æ':result[i] = '›';
	      	case 'Æ':result[i] = '„';
	      	case 'ç':result[i] = 'Ÿ';
	      	case 'Ç':result[i] = 'ˆ';
	      	case 'è':result[i] = 'œ';
	      	case 'È':result[i] = '…';
	      	case 'é':result[i] = '';
	      	case 'É':result[i] = '…';
	      	case 'ê':result[i] = 'k';
	      	case 'Ê':result[i] = 'K';
	      	case 'ë':result[i] = 'ž';
	      	case 'Ë':result[i] = '‡';
	      	case 'ì':result[i] = '¯';
	      	case 'Ì':result[i] = 'M';
	      	case 'í':result[i] = '®';
	      	case 'Í':result[i] = 'H';
	      	case 'î':result[i] = 'o';
	      	case 'Î':result[i] = 'O';
	      	case 'ï':result[i] = '£';
	      	case 'Ï':result[i] = 'Œ';
	      	case 'ð':result[i] = 'p';
	      	case 'Ð':result[i] = 'P';
	      	case 'ñ':result[i] = 'c';
	      	case 'Ñ':result[i] = 'C';
	      	case 'ò':result[i] = '¦';
	      	case 'Ò':result[i] = '';
	      	case 'ó':result[i] = 'y';
	      	case 'Ó':result[i] = 'Y';
	      	case 'ô':result[i] = '?';
	      	case 'Ô':result[i] = '';
	      	case 'õ':result[i] = 'x';
	      	case 'Õ':result[i] = 'X';
	      	case 'ö':result[i] = '$';
	      	case 'Ö':result[i] = '‰';
	      	case '÷':result[i] = '¤';
	      	case '×':result[i] = '';
	      	case 'ø':result[i] = '¥';
	      	case 'Ø':result[i] = 'Ž';
	      	case 'ù':result[i] = '¡';
	      	case 'Ù':result[i] = 'Š';
	      	case 'ü':result[i] = '©';
	      	case 'Ü':result[i] = '’';
	      	case 'ú':result[i] = '';
	      	case 'Ú':result[i] = '§';
	      	case 'û':result[i] = '¨';
	      	case 'Û':result[i] = '‘';
	      	case 'ý':result[i] = 'ª';
	      	case 'Ý':result[i] = '“';
	      	case 'þ':result[i] = '«';
	      	case 'Þ':result[i] = '”';
	      	case 'ÿ':result[i] = '¬';
	      	case 'ß':result[i] = '•';
   			default:result[i]=string[i];
     	}
	}
    return result;
}

stock PreloadDefaultLocalizedTitles(const playerid) {
	static const preloadTitles[] = PRELOAD_CLASSES_TITLES;
    new formated[sizeof(preloadTitles) + LOCALIZATION_SIZE + MAX_TEAMS_LEN + LOCALIZATION_SIZE + MAX_TEAMS_LEN], index = Player[playerid][pLanguage];
    mysql_format(Database, formated, sizeof(formated), preloadTitles, LOCALIZATION_TABLES[index], TEAM_ZOMBIE, LOCALIZATION_TABLES[index], TEAM_HUMAN);
    mysql_tquery(Database, formated, "LoadFirstClassesTitles", "i", playerid);
}

stock GetRequiredZombiesCount() {
    switch(ServerConfig[svCfgCurrentOnline]) {
        case 0..3:
            return floatround(ServerConfig[svCfgCurrentOnline] / ServerBalance[svbMinZombies], floatround_tozero);
		case 4..7:
			return floatround(ServerConfig[svCfgCurrentOnline] / ServerBalance[svbMediumZombies], floatround_tozero);
		default:
		    return floatround(ServerConfig[svCfgCurrentOnline] / ServerBalance[svbMaxZombies], floatround_tozero);
    }

    return floatround(ServerConfig[svCfgCurrentOnline] / ServerBalance[svbDefaultZombies], floatround_tozero);
}

stock SetTeams() {
	new required = GetRequiredZombiesCount(), current, i, j;
    new players[MAX_PLAYERS] = { 1, 2, 3, ... }, playerid;
	new bool: hero, bool:boss, formated[128];

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
	        SendClientMessage(playerid, 0xFF0000FF, Localization[playerid][LD_MSG_CHOSEN_AS_ZOMBIE]);
  			SendClientMessage(playerid, 0xFF0000FF, Localization[playerid][LD_MSG_CHOSEN_ZOMBIE_ABILITY]);
	        SetPlayerTeamAC(playerid, TEAM_ZOMBIE);
            ++current;
            
            if(!boss) {
	    		Round[playerid][rdIsZombieBoss] = true;
	    		boss = true;
	    		
	    		foreach(Player, p) {
					format(formated, sizeof(formated), Localization[p][LD_MSG_ZOMBIE_BOSS], Misc[playerid][mdPlayerName], Localization[p][LD_MSG_POINTS_MULTIPLE]);
					SendClientMessage(p, 0x59E4B5FF, formated);
				}
			}
        } else {
            GameTextForPlayer(playerid, RusToGame(Localization[playerid][LD_DISPLAY_TRY_TO_SURVIVE]), 2000, 6);
            SetPlayerTeamAC(playerid, TEAM_HUMAN);
            
            if(!hero) {
				Round[playerid][rdIsHumanHero] = true;
				hero = true;
				
				foreach(Player, p) {
					format(formated, sizeof(formated), Localization[p][LD_MSG_HUMAN_HERO], Misc[playerid][mdPlayerName], Localization[p][LD_MSG_POINTS_MULTIPLE]);
					SendClientMessage(p, 0x59E4B5FF, formated);
				}
			}
        }
        
        ResetRoundSessionOnMapStart(playerid);
        SpawnPlayer(playerid);
		SetCameraBehindPlayer(playerid);
    }
}

CMD:class(const playerid) {
    ShowPlayerDialogAC(
		playerid, DIALOG_CLASSES, DIALOG_STYLE_LIST,
		Localization[playerid][LD_DG_CLASSES_TITLE],
		Localization[playerid][LD_DG_CLASSES_LIST],
		Localization[playerid][LD_BTN_SELECT],
		Localization[playerid][LD_BTN_CLOSE]
	);
	return 1;
}

CMD:test(playerid) {
	if(Player[playerid][pAccountId] != 1) {
	    return 0;
	}
	
	SetPlayerTeamAC(playerid, TEAM_ZOMBIE);
	SetByCurrentClass(playerid);
	return 1;
}
