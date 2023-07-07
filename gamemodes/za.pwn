#include <packs/core>
#include <packs/config>
#include <packs/teams>
#include <packs/player>
#include <packs/gangs>
#include <packs/round>
#include <packs/pickups>
#include <packs/weapons>
#include <packs/misc>
#include <packs/colors>
#include <packs/classes>
#include <packs/templates>

#include <packs/developer>

static MySQL:Database;
static updateTimerId;

static const sqlTemplates[][] = {
    { REGISTRATION_TEMPLATE }, { USERS_TEMPLATE }, { PRIVILEGES_TEMPLATE },
	{ GANGS_TEMPLATE }, { GANGS_USERS_TEMPLATE },
	{ GANGS_REQUESTS_TEMPLATE }, { GANGS_WARNS_TEMPLATE },
	{ GANGS_BLACKLISTED_TEMPLATE }, { GANGS_CONFIG_TEMPLATE },
	{ MAPS_TEMPLATE },
	{ WEAPONS_TEMPLATE },
	{ LANGUAGES_TEMPLATE }, { CLASSES_TEMPLATE },
	{ BANLOG_TEMPLATE }, { NAMELOG_TEMPLATE }, { LOGINLOG_TEMPLATE },
	{ PAYLOG_TEMPLATE }, { AUCTIONLOG_TEMPLATE },
	{ AUCTION_TEMPLATE }, { AUCTION_CASHBACK_TEMPLATE },
	{ ACHIEVEMENTS_TEMPLATE },
	{ CONFIG_TEMPLATE },
	{ STATS_TEMPLATE }
};

static Player[MAX_PLAYERS][PLAYER_DATA];
static Round[MAX_PLAYERS][ROUND_DATA];
static Misc[MAX_PLAYERS][MISC_DATA];
static Gangs[MAX_GANGS][GANG_DATA];
static Pickup[MAX_PICKUPS][PICKUP_DATA];
static Classes[MAX_CLASSES][CLASSES_DATA];
static Config[CONFIG_DATA];


// static Language[MAX_PLAYERS][LANGUAGE_DATA];

/*
	- The purchase of game values for real money between players is allowed, however, the administration and the founder of the project are not responsible for the transactions made
		* In case of cheating, we can ban the cheater
*/

/*
 - General Changes To Gameplay:
 - Zombies don't have chainsaw anymore, use your fists to deal damage (5 HP)
 - Complete achievements to level up faster
 - Level unlocks new classes (abilities), but not weapons
 - Points is gained from the quality of the round you played:
    * Survival (5 for evacuation)
    * Infect / Ability / Cure (1)
    
 - Gangs:
    - Capacity is 15 members only
    - Create a gang required 25,000 points
 	- Quests (5):
		* Reach a total of 20,000 points (Reward: 25 armour)
		* Reach a total of 50,000 points (Reward: Country Rifle)
		* Reach a total of 80,000 points (Reward: Sniper Rifle)
		* Reach a total of 140,000 points (Reward: Ak47)
		* Reach a total of 200,000 points (Reward: M4)
	 - How to capture:
    	* At the end of the round, gang players will receive weapons and must inflict the maximum possible damage on the spawned bot
		* The map will be captured by the gang that deals the most damage
		* Character level gives additional damage to the bot
		* Weapon modifications provide additional damage to the bot
 - Weapons:
    * Achieve 25 killstreak in a row using Silinced Pistol (Reward: Colt45)
    * Achieve 40 killstreak in a row using Colt45 (Reward: Shotgun)
    * Achieve 50 killstreak in a row using Shotgun (Reward: Deagle)
 	* Kill 250 zombies using Deagle (Reward: UZI)
	* Kill 250 zombies using UZI (Reward: Tec9)
	* Kill 250 zombies using Tec9 (Reward: MP5)
	* Killing a zombie with a certain weapon can create a certain weapon pickup that can be sold (You can buy weapons from other players)
 - Maps:
    * Captured map gives more points for killing (+2)
    * The gang holding the map receives additional experience points for actions:
    	* Infect / Ability / Cure (0.1%)
    	* Evac (0.5%)
*/

/*
	General Weekly Quests:
	
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
	ClearAllPickups();
	ClearClassesData();
	
	ShowPlayerMarkers(PLAYER_MARKERS_MODE_GLOBAL);
    ShowNameTags(1);
	SetTeamCount(MAX_PLAYER_TEAMS);
	DisableInteriorEnterExits();
	EnableStuntBonusForAll(0);
	AllowInteriorWeapons(1);
	
	Database = mysql_connect(SQL_HOST, SQL_USER, SQL_PASS, SQL_DB);

	mysql_set_charset(SQL_CHARSET);
	for(new sqlTemplateId; sqlTemplateId < sizeof(sqlTemplates); sqlTemplateId++) {
		mysql_tquery(Database, sqlTemplates[sqlTemplateId]);
	}
 	mysql_log(SQL_LOG_LEVEL);
	
	printf("Status: %d", mysql_errno(Database));
	
	SetGameModeText("Zombie Server");
	// SendRconCommand("weburl "SITE"");
	
	updateTimerId = SetTimer("Update", 1000, true);
	return 1;
}

public OnGameModeExit() {
    mysql_close(Database);
	KillTimer(updateTimerId);
	return 1;
}

public OnPlayerConnect(playerid) {
    ClearAllPlayerData(playerid);
    return 1;
}

public OnPlayerDisconnect(playerid, reason) {
	return 1;
}

public OnPlayerSpawn(playerid) {
    SetByCurrentClass(playerid);
	return 1;
}

public OnPlayerUpdate(playerid) {
	SetPlayerScore(playerid, Player[playerid][pd_vip]);
	return 1;
}

public OnPlayerDeath(playerid, killerid, reason) {
	if(!IsPlayerConnected(playerid)) {
	    return 0;
	}

    reason = clamp(reason, WEAPON_FISTS, WEAPON_COLLISION);
	SendDeathMessage(killerid, playerid, reason);
	
	CreateDropOnDeath(playerid);
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
	return 1;
}

public OnPlayerCommandPerformed(playerid, cmdtext[], success) {
	return 1;
}

public OnPlayerPickUpPickup(playerid, pickupid) {
    if(IsAbleToPickup(playerid, pickupid)) {
    	ProcedPickupAction(playerid, pickupid);
     	DestroyPickupEx(pickupid);
	} else if(IsValidPickupEx(pickupid)) {
	    new tip[64];
	    format(tip, sizeof(tip), ">> Protection {FFFFFF}%d{FF0000} seconds left!", max(0, Pickup[pickupid][pcd_protection_till] - gettime()));
 		SendClientMessage(playerid, 0xFF0000FF, tip);
	}
	return 1;
}

custom Update() {
	static Float:hp, Float:armour;

	foreach(Player, playerid) {
	    CheckAndNormalizeACValues(playerid, hp, armour);
	}
}


stock CreateDropOnDeath(const playerid) {
	new Float:pos[3];
	new type[4] = { M4_PICKUP, BULLETS_PICKUP, MEAT_PICKUP, -1 };
 	new index = random(sizeof(type));

	GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
  	CreatePickupEx(type[index], STATIC_PICKUP_TYPE, pos[0], pos[1], pos[2], GetPlayerVirtualWorld(playerid), playerid);
	return 1;
}

stock wipe() {
}

stock ClearClassesData() {
	new i, j;
	for( i = 0; i < MAX_CLASSES; i++ ) {
	    Classes[i][cldId] = -1;
	    Classes[i][cldTranslateId] = -1;
	    Classes[i][cldTeam] = TEAM_UNKNOWN;
	    Classes[i][cldAbility] = -1;
	    Classes[i][cldLevel] = 0;
	    Classes[i][cldHealth] = 0;
	    Classes[i][cldArmour] = 0;
	    Classes[i][cldCooldown] = 0;

	    Classes[i][cldDisabled] = 0;

		for( j = 0; j < MAX_CLASS_SKINS; j++ ) {
			Classes[i][cldSkin][j] = -1;
		}

		for( j = 0; j < MAX_CLASS_WEAPONS; j++ ) {
			Classes[i][cldWeapons][j] = -1;
			Classes[i][cldAmmo][j] = -1;
		}
	}
}

stock ClearAllPlayerData(const playerid) {
	SetPlayerHealthAC(playerid, 100.0);
    SetPlayerArmourAC(playerid, 0.0);
    SetPlayerVirtualWorld(playerid, 1000 + playerid);
    
    ClearPlayerData(playerid);
    ClearMiscData(playerid);
    ClearRoundData(playerid);
    ResetWeapons(playerid);
}

stock ClearPlayerData(const playerid) {
    Player[playerid][pd_xp] = 0;
    Player[playerid][pd_level] = 0;
}

stock ClearMiscData(const playerid) {
    Misc[playerid][mdPlayerTeam] = TEAM_UNKNOWN;
    GetPlayerName(playerid, Misc[playerid][mdPlayerName], MAX_PLAYER_NAME);
    Misc[playerid][mdSpawnProtection] = 0;
    Misc[playerid][mdIgnoreAnticheatFor] = 0;
    
    for( new i = 0; i < MAX_PLAYER_TEAMS; i++ ) {
	    Misc[playerid][mdCurrentClass][i] = 0;
        Misc[playerid][mdNextClass][i] = -1;
    }
}

stock ClearRoundData(const playerid) {
	Round[playerid][rpp_survival_time] = 0;
	Round[playerid][rpp_kills] = 0;
	
	Round[playerid][rpp_deaths] = 0;
	Round[playerid][rpp_infected] = 0;
}

stock GetPlayerTeamEx(const playerid) {
	return Misc[playerid][mdPlayerTeam];
}

stock SetPlayerTeamEx(const playerid, const teamid) {
	SetPlayerTeam(playerid, teamid);
	Misc[playerid][mdPlayerTeam] = teamid;
}

stock SetByCurrentClass(const playerid) {
    ResetWeapons(playerid);

	new team = Misc[playerid][mdPlayerTeam];
	new next = Misc[playerid][mdNextClass][team];
	new current = Misc[playerid][mdCurrentClass][team];
	
	if(next > -1) {
	    current = next;
		Misc[playerid][mdCurrentClass][team] = next;
	    Misc[playerid][mdNextClass][team] = -1;
	    next = -1;
	}
	
	switch(GetPlayerTeamEx(playerid)) {
	    case TEAM_ZOMBIE: SetZombie(playerid, current);
	    case TEAM_HUMAN: SetHuman(playerid, current);
	}
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
            switch(Pickup[pickupid][pcd_model]) {
	    		case M4_PICKUP: GivePlayerWeaponAC(playerid, 31, 100);
			}
	    }
	}

	return 1;
}

bool:IsValidPickupEx(const pickupid) {
	return (pickupid < 0 || pickupid >= (MAX_PICKUPS - 1)) ? false : Pickup[pickupid][is_active];
}

bool:IsAbleToPickup(const playerid, const pickupid) {
	if(!IsValidPickupEx(pickupid)) {
	    return false;
	}
	
	return Pickup[pickupid][pcd_for_player] == -1 || !IsPlayerConnected(playerid) ||
	playerid == Pickup[pickupid][pcd_for_player] || gettime() >= Pickup[pickupid][pcd_protection_till];
}

stock CreatePickupEx(const pickupid, const type, const Float:x, const Float:y, const Float:z, const world, const playerid = -1) {
	if(pickupid < 0) {
	    return pickupid;
	}

	new id = CreatePickup(pickupid, type, x, y, z, world);
    if(id >= 0 && pickupid <= MAX_PICKUPS) {
	 	Pickup[id][pcd_id] = id;
	 	Pickup[id][pcd_model] = pickupid;
	 	Pickup[id][pcd_protection_till] = gettime() + 30;
	 	Pickup[id][pcd_for_player] = playerid;
	 	Pickup[id][is_active] = true;
	}
	return id;
}

stock DestroyPickupEx(const pickupid) {
    if(IsValidPickupEx(pickupid)) {
        Pickup[pickupid][pcd_id] = -1;
        Pickup[pickupid][pcd_model] = -1;
	 	Pickup[pickupid][pcd_protection_till] = 0;
	 	Pickup[pickupid][pcd_for_player] = -1;
	 	Pickup[pickupid][is_active] = false;
    }
    DestroyPickup(pickupid);
}

stock ClearAllPickups() {
	for( new i = 0; i < MAX_PICKUPS; i++ ) {
	    DestroyPickupEx(i);
	}
}

stock ResetWeapons(playerid) {
    new gunname[32];
	for(new i = 0; i < 46; i++) {
		GetWeaponName(i, gunname, sizeof(gunname));
		SetPVarInt(playerid, gunname, -4);
	}
    SetPlayerArmedWeapon(playerid, 0);
    ResetPlayerWeapons(playerid);
}

stock GivePlayerWeaponAC(playerid, weapid, ammo) {
    new gunname[32], stack = min(1000, GetPVarInt(playerid, gunname) + ammo);
    GetWeaponName(weapid, gunname, sizeof(gunname));
    SetPVarInt(playerid, gunname, stack);
    GivePlayerWeapon(playerid, weapid, stack);
    SetPlayerAmmo(playerid, weapid, stack);
	return 1;
}

stock GetPlayerHealthEx(playerid, &Float:hp) {
	hp = Misc[playerid][mdHealth];
}

stock GetPlayerArmourEx(playerid, &Float:armour) {
	armour = Misc[playerid][mdArmour];
}


stock SetPlayerHealthAC(playerid, Float:hp) {
	Misc[playerid][mdIgnoreAnticheatFor] = 3;
 	Misc[playerid][mdHealth] = hp;
   	SetPlayerHealth(playerid, hp);
}

stock SetPlayerArmourAC(playerid, Float:armour) {
	Misc[playerid][mdIgnoreAnticheatFor] = 3;
	Misc[playerid][mdArmour] = armour;
   	SetPlayerArmour(playerid, armour);
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
    SetPlayerHealthAC(playerid, 100.0);
    SetPlayerArmourAC(playerid, 0.0);
    SetPlayerVirtualWorld(playerid, 0);
}

stock SetHuman(const playerid, const classid) {
    SetPlayerColor(playerid, COLOR_HUMAN);
    SetPlayerHealthAC(playerid, 100.0);
    SetPlayerArmourAC(playerid, 0.0);
    SetPlayerVirtualWorld(playerid, 0);
}
