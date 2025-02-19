#if defined _language_pack_included
	#endinput
#endif
#define _language_pack_included

#define AUTH_REG_TYPE 0
#define AUTH_LOGIN_TYPE 1

#define LOCALIZATION_SIZE 8
#define LOCALIZATION_LINE_SIZE 320
#define RUSSIAN_LOCALE "russian"
#define ENGLISH_LOCALE "english"
#define SPANISH_LOCALE "spanish"
#define ARABIC_LOCALE "arabic"

enum LOCALIZATION_DATA {
	LD_DG_LOGIN_TITLE,
	LD_DG_LOGIN_DEFAULT,
	LD_DG_LOGIN_TRIES,
	LD_DG_LOGIN_SPACES,
	LD_DG_REG_TITLE,
	LD_DG_REG_DEFAULT,
	LD_DG_REG_SPACES,
	LD_BTN_REGISTER,
	LD_BTN_LOGIN,
	LD_BTN_QUIT,
	LD_MSG_CONNECT,
	LD_MSG_DISCONNECT,
	LD_MSG_TIMEOUT,
	LD_MSG_LEAVE,
	LD_MSG_KICK,
	LD_MSG_CUSTOM_KICK,
	LD_MSG_MODE_END_KICK,
	LD_MSG_EVACUATED,
	LD_MSG_ALL_EVACUATED,
	LD_MSG_PICKUP_PROTECTION,
	LD_MSG_MAP_AUTHOR,
	LD_MSG_MAP_GANG,
	LD_MSG_MAP_ENTERING,
	LD_MSG_MAP_CREATE_OBJECTS,
	LD_MSG_MAP_ZOMBIES_WIN,
	LD_MSG_MAP_EVAC_ARRIVED,
	LD_MSG_MAP_EVAC_GETTO,
	LD_MSG_MAP_BEGINNING,
	LD_MSG_MAP_ROUND_OVER,
	LD_MSG_MAP_CRYSTAL_DAMAGE,
	LD_DISPLAY_ALIVE_INFO,
	LD_MAP_GANG_FLAP_PART_1,
	LD_MAP_GANG_FLAP_PART_2,
	LD_MSG_GANG_SCORE,
	LD_MSG_GANG_RECAPTURED,
	LD_MAP_GANG_CAN_CAPTURE,
	LD_MAP_DONOT_SHOT_HERE,
	LD_MAP_NAME,
	LD_DG_CLASSES_TITLE,
	LD_DG_CLASSES_LIST,
	LD_BTN_SELECT,
	LD_BTN_CLOSE,
	LD_CLASSES_TIP_EXP,
	LD_CLASSES_SPAWN_AS,
	LD_CLASS_GREAT_PERIOD,
	LD_CLASS_SET_AFTER,
	LD_MSG_POINTS,
	LD_MSG_NOT_ENOUGH_FOR_CLASS,
	LD_ANY_MISS,
	LD_ANY_AMMO_PICKUP,
	LD_MSG_CHOSEN_AS_ZOMBIE,
	LD_MSG_CHOSEN_ZOMBIE_ABILITY,
	LD_DISPLAY_TRY_TO_SURVIVE,
	LD_MSG_POINTS_MULTIPLE,
	LD_MSG_HUMAN_HERO,
	LD_MSG_HUMAN_HERO_KILLED,
	LD_MSG_ZOMBIE_BOSS,
	LD_MSG_ZOMBIE_BOSS_KILLED,
	LD_MSG_FIRST_BLOOD,
	LD_MSG_KILL_THE_LAST,	
	LD_MSG_KILLED_THE_LAST,
	LD_MSG_INFECTED_STANDARD,
	LD_MSG_INFECTED_MUTATED,
	LD_MSG_INFECTED_FLESHER,
	LD_MSG_INFECTED_SPORE,
	LD_MSG_INFECTED_SPITTER,
	LD_MSG_INFECTED_EXPLOSION,
	LD_MSG_EXPLODED,
	LD_MSG_EXPLODED_WHOPPING,
	LD_MSG_CURE_NURSE_FIELD,
	LD_MSG_CURE_RIFLE,
	LD_DISPLAY_REGENERATION,
	LD_DISPLAY_RADIOACTIVE,
	LD_ANY_ANTIDOTE,
	LD_MSG_ARMOUR_STOLE,
	LD_MSG_CURSE_PLAYER,
	LD_MSG_ABSOLVE_SINS,
	LD_DISLPAY_CURSE,
	LD_DISLPAY_FAKE_CLASS,
	LD_DISPLAY_OFF,
	LD_DISPLAY_ON,
	LD_DISPLAY_RDF_STATUS,
	LD_DISPLAY_CRF_STATUS,
	LD_DISPLAY_HLF_STATUS,
	LD_DISPLAY_SPF_STATUS,
	LD_MSG_PLAYER_INFECT_PLAYER,
	LD_MSG_PLAYER_OOM,
	LD_MSG_FROZE,
	LD_MSG_FROZE_WHOPPING,
	LD_DISLPAY_COOLDOWN,
	LD_DISPLAY_CANT_USE,
	LD_MSG_MISTY_INFECTED,
	LD_MSG_BLIND_INFECTED,
	LD_MSG_AMMO_STOLE,
	LD_MSG_BREAK_LEGS,
	LD_DISPLAY_REMOVE_WEAPS_FIELD,
	LD_DISPLAY_WEAPS_REMOVED,
	LD_MSG_PLAYER_POISONED,
	LD_DISPLAY_SPACE_DAMAGE,
	LD_MSG_RANDOM_QUESTION,
	LD_MSG_RANDOM_ANSWER,
	LD_BTN_NEXT,
	LD_DG_ACHS_TITLE,
	LD_DG_EMPTY,
	LD_DG_ACHS_HEADERS,
	LD_MSG_RND_QUESTION_NO_ANSWER,
	LD_MSG_LOTTERY,
	LD_MSG_LOTTERY_NOBODY_WIN,
	LD_MSG_LOTTERY_PLAYER_WIN,
	LD_MSG_LOTTERY_NOT_STARTED,
	LD_MSG_LOTTERY_CHOSEN,
	LD_MSG_LOTTERY_NUMBER,
	LD_MSG_STATS_TITLE,
	LD_MSG_STATS_KILLS,
	LD_MSG_STATS_WINS,
	LD_MSG_STATS_PLAYED,
	LD_MSG_STATS_GANG_ACCOUNT,
	LD_MSG_STATS_DATE_SIGN,
	LD_MSG_COINS,
	LD_MSG_ACH_UNLOCKED,
	LD_MSG_KILLSTREAKS,
	LD_MSG_KILLSTREAK_KILLED,
	LD_MSG_STATS_POINTS,
	LD_MSG_SAVED_STATS,
	LD_DG_LANGUAGES_TITLE,
	LD_DG_LANGUAGES_OPTS,
	LD_MSG_LANGUAGE_SET,
	LD_MSG_QUESTION_ASKED,
	LD_MSG_PMS_IS_BLOCKED,
	LD_MSG_SETTING_BLOCKED,
	LD_MSG_SETTING_UNBLOCKED,
	LD_DG_SETTINGS_TITLE,
	LD_DG_SETTINGS_OPTS,
	LD_DG_SETTINGS_YES,
	LD_DG_SETTINGS_NO,
	LD_DISPLAY_ABLT_READY,
	LD_MSG_BANNED_TITLE,
	LD_DG_RULES_TITLE,
	LD_DG_HELP_TITLE,
	LD_MSG_REPORT,
	LD_MSG_REPORT_SENT,
	LD_MSG_UNKNOW_COMMAND,
	LD_MSG_VOTEKICK_STARTED,
	LD_MSG_VOTEKICK,
	LD_MSG_VOTEKICK_OPTS,
	LD_MSG_VOTEKICK_YES,
	LD_MSG_VOTEKICK_NO,
	LD_MSG_VOTEKICK_SUCCESS,
	LD_MSG_VOTEKICK_FAIL,
	LD_MSG_CONNECT_ADMIN,
	LD_MSG_DISCONNECT_ADMIN,
	LD_MSG_ADMIN_MESSAGE,
	LD_MSG_PLAYER_MESSAGE,
	LD_MSG_ADMIN_JAILED,
	LD_MSG_PLAYER_JAILED,
	LD_MSG_ADMIN_UNJAILED,
	LD_MSG_PLAYER_UNJAILED,
	LD_DG_WEEKLY_TITLE,
	LD_DG_WEEKLY_OPTS,
	LD_DG_CLASSES_HEADERS,
	LD_MSG_CHAT_CLEARED_BY,
	LD_MSG_CHAT_CLEARED,
	LD_MSG_KICKED_BY,
	LD_MSG_KICKED,
	LD_MSG_SYNC_BY,
	LD_MSG_SYNC,
	LD_MSG_SLAP_BY,
	LD_MSG_SLAP,
	LD_MSG_MAKEZOMBIE_BY,
	LD_MSG_MAKEZOMBIE,
	LD_MSG_MATCHES,
	LD_MSG_MATCHES_NONE,
	LD_MSG_BANNED_BY,
	LD_MSG_BANNED,
	LD_MSG_AFK,
	LD_MSG_PING_KICK,
	LD_MSG_AFK_KICK,
	LD_MSG_REPORT_HELP,
	LD_MSG_WRONG_BANNED,
	LD_MSG_BANNED_SCREENSHOT,
	LD_MSG_BANNED_REASON,
	LD_MSG_BANNED_DATE,
	LD_MSG_PERM_BANNED,
	LD_MSG_TEMP_BANNED,
	LD_MSG_UNBAN_NONE,
	LD_MSG_UNBAN_BY,
	LD_MSG_ADMIN_TBANNED_BY,
	LD_MSG_ADMIN_TBANNED,
	LD_MSG_SPECTATE_START,
	LD_MSG_SPECTATE_END,
	LD_MSG_TIME_SET,
	LD_MSG_WEATHER_SET,
	LD_MSG_WARNED_BY,
	LD_MSG_WARNED,
	LD_DG_WARNED_TITLE,
	LD_MSG_WARNED_KICK,
	LD_MSG_UNWARN_BY,
	LD_MSG_NO_WARNS,
	LD_MSG_MUTED_BY,
	LD_MSG_MUTED,
	LD_MSG_UNMUTED_BY,
	LD_MSG_UNMUTED,
	LD_MSG_YOURE_MUTED,
	LD_MSG_CMD_USED,
	LD_DISPLAY_UNABLE_TO_USE,
	LD_MSG_OFFBAN_BY,
	LD_MSG_NO_ACCOUNT,
	LD_MSG_OFFTBAN_BY,
	LD_MSG_GI_NIP,
	LD_MSG_GI_HA,
	LD_MSG_GI_PM,
	LD_MSG_GI_TZ,
	LD_MSG_GI_TH,
	LD_MSG_GI_WA,
	LD_MSG_GI_PL,
	LD_MSG_INVALID_NAME,
	LD_MSG_NAME_TAKEN,
	LD_MSG_NAME_CHANGED,
	LD_MSG_KNOWN_AS,
	LD_MSG_BANIP,
	LD_MSG_IP_ALREADY_BAN,
	LD_MSG_IP_NOT_BAN,
	LD_MSG_UNBANIP,
	LD_MSG_FREEZE_BY,
	LD_MSG_FREEZE,
	LD_MSG_UNFREEZE_BY,
	LD_MSG_UNFREEZE,
	LD_DG_INFO_TITLE,
	LD_DG_ALOG_TITLE,
	LD_DG_NLOG_TITLE,
	LD_DG_BILOG_TITLE,
	LD_MSG_ADMIN_APPOINTMENT,
	LD_DISPLAY_DUEL_INVITE,
	LD_MSG_DUEL_ACCEPTED,
	LD_MSG_DUEL_REQ_ACCEPTED,
	LD_MSG_DUEL_DENIED,
	LD_MSG_DUEL_REQ_DENIED,
	LD_MSG_DUEL_POINTS,
	LD_MSG_DUEL_BLOCKED,
	LD_MSG_DUEL_ARMOUR,
	LD_MSG_DUEL_BET,
	LD_MSG_DUEL_REQUEST,
	LD_MSG_DUEL_REQ_OPTS,
	LD_MSG_DUEL_REQ_SENT,
	LD_MSG_DUEL_STARTED,
	LD_MSG_NO_IN_DUEL,
	LD_MSG_WON_DUEL,
	LD_MSG_PAY_TO,
	LD_MSG_GANG_LIST_MAPS,
	LD_MSG_PLAYER_BLACKLISTED,
	LD_MSG_ALREADY_IN_GANG,
	LD_MSG_GANG_CLOSED,
	LD_MSG_JOIN_REQUEST,
	LD_MSG_ACCEPT_REQUEST,
	LD_MSG_GANG_REQUEST_SENT,
	LD_MSG_LOW_GANG_RIGHTS,
	LD_MSG_GANG_REQ_ACPT_BY,
	LD_MSG_GANG_REQ_ACCEPTED,
	LD_MSG_GANG_HOW_CHAT,
	LD_MSG_GANG_LIST,
	LD_MSG_GANG_NO_SLOTS,
	LD_MSG_GANG_CREATED,
	LD_MSG_PRED_GANG_RANKS,
	LD_DG_WEEKLY_REWARD_TITLE,
	LD_DG_WEEKLY_BUY_REQ,
	LD_DG_WEEKLY_COMPLETED,
	LD_BTN_YES,
	LD_DG_WEEKLY_TARGETS,
	LD_DG_REWARD_NO_MONEY,
	LD_MSG_REWARD_BOUGHT,
	LD_MSG_GANG_CAPTURED,
	LD_MSG_GANG_UPDATED_SCORE,
	LD_MSG_GANG_ERR_CAPACITY,
	LD_MSG_GANG_ERR_RANK,
	LD_MSG_HIT_SPAWN_CAMP,
	LD_MSG_INSUFFICIENT_CALIBER,
	LD_DG_GANG_SETTINGS_1,
	LD_DG_GANG_SETTINGS_2,
	LD_DG_GANG_SETTINGS_3,
	LD_DG_OPENED,
	LD_DG_CLOSED,
	LD_MSG_MAYBE_TP,
	LD_DG_GANG_SETTINGS_INPUT,
	LD_DG_GANG_SETTINGS_NAME,
    	LD_DG_GANG_SETTINGS_TAG,
        LD_DG_GANG_SETTINGS_RANK,
	LD_MSG_GANG_INFO_TITLE,
	LD_MSG_GANG_INFO_PLAYERS,
	LD_DG_GANG_ACTIVITY_TITLE,
	LD_DG_ADMIN_ACTIVITY_TITLE,
	LD_MSG_AUTH_TIMEOUT_KICK,
	LD_MSG_AUTH_WRONG_TRIES,
	LD_MSG_GANG_CANT_LEAVE,
	LD_MSG_GANG_LEAVE,
	LD_MSG_GANGWAR_REQUEST,
    	LD_MSG_GANGWAR_1,
    	LD_MSG_GANGWAR_2,
    	LD_MSG_GANGWAR_ACCEPT_REQ,
	LD_MSG_GANGWAR_STARTED,
	LD_MSG_GANGWAR_END,
	LD_MSG_ALLIANCE_START,
	LD_MSG_ALLIANCE_END,
	LD_MSG_ALLIANCE_REQUEST,
	LD_MSG_ALLIANCE_1,
	LD_MSG_ALLIANCE_ACCEPT_REQ,
	LD_ENDF,
};

#define PREDIFINED_CLOTHES_LOCALE "INSERT IGNORE INTO `clothes_locale` (id, kit, coins, emblems, english, russian) VALUES \
	(1, 1, 5, 1, 'Accessory: Sniper', '���������: ����������� ��������'),\
	(2, 2, 5, 1, 'Accessory: Ak47', '���������: Ak47'),\
	(3, 3, 5, 1, 'Accessory: Guitar', '���������: ������'),\
	(4, 4, 5, 1, 'Accessory: Surfboard', '���������: ����� ��� ��������'),\
	(5, 5, 5, 1, 'Accessory: Money case', '���������: �������� ����'),\
	(6, 6, 5, 1, 'Accessory: Backpack', '���������: ������'),\
	(7, 7, 5, 2, 'Haloween Set', '����� ������: ��������'),\
	(8, 8, 5, 2, 'Christmas Set', '����� ������: ����� ���'),\
	(9, 9, 5, 3, 'Army Set', '����� ������: �����');\
"

#define PREDIFINED_LOCALIZATION_1 "INSERT IGNORE INTO localization (id, english, russian) VALUES \
	(1, 'Login', '�����'),\
	(2, 'Welcome back, your account is already registered\nEnter your password below to login', '����� ����������, ��� ������� ��� ���������������\n������� ������'),\
	(3, 'Wrong password, %d / 3 tries left\n\nWelcome back, your account is already registered\nEnter your password below to login', '�������� ������, �������� %d / 3 �������\n����� ����������, ��� ������� ��� ���������������\n������� ������'),\
	(4, 'You have to type at least something!\n\nWelcome back, your account is already registered\nEnter your password below to login', '���� ������ �� ����� ���� ������!\n����� ����������, ��� ������� ��� ���������������\n������� ������'),\				
	(5, 'Register', '�����������'),\
	(6, 'Welcome to the server, your account was not found\nEnter your password below to complete registration', '����� ����������, ��� ������� �� ������\n���������� ������'),\
	(7, 'You have to type at least something!\n\nWelcome to the server, your account was not found\nEnter your password below to complete registration', '���� ������ �� ����� ���� ������!\n����� ����������, ��� ������� �� ������\n���������� ������'),\
	(8, 'Register', '�����������'),\
	(9, 'Login', '�����'),\
	(10, 'Quit', '�����'),\
	(11, '*** %s has joined the server (ID %d) (Player %d)', '*** ����� %s ����������� � ������� (ID %d) (����� %d)'),\
	(12, '*** %s has left the server (%s)', '*** ����� %s ����� � ������� (%s)'),\
	(13, 'Timeout', '������ ����������'),\
	(14, 'Leave', '�����'),\
	(15, 'Kick', '������'),\
	(16, 'Unknown', '����������');\
"

#define PREDIFINED_LOCALIZATION_2 "INSERT IGNORE INTO localization (id, english, russian) VALUES \
	(17, 'Restarting', '������������'),\
	(18, '>> %s has made it to the evacuation point!', '>> ����� %s �������������!'),\
	(19, '>> ALL SURVIVORS EVACUATED!', '>> ��� �������� ��������� �� ������ ���������!'),\
	(20, '>> Under protection {FFFFFF}%d{FF0000} seconds left!', '>> ��� �������, �� ������ {FFFFFF}%d{FF0000} ������'),\
	(21, '(by %s)', '(����� %s)'),\
	(22, '(captured by %s)', '(��� ��������� � %s)'),\
	(23, '>> Entering The Map #%d (%s) %s %s', '>> ��������� ����� #%d (%s) %s %s'),\
	(24, '>> Creating objects...', '>> �������� ��������...'),\
	(25, '>> ZOMBIES WIN!', '>> ����� ��������!'),\
	(26, '>> An evacuation has arrived for humans!', '>> ��������� ������� ��� �����!'),\
	(27, '>> Humans get to the checkpoint within a minute!', '>> ��������, ���������� �� ��������� �� ������!'),\
	(28, '>> Beginning new a round...', '>> ���������� ����� �����!'),\
	(29, '~r~ROUND OVER~n~~w~STARTING NEW ROUND...', '~r~����� ������~n~~w~�������� �����...'),\
	(30, '>> Gang members, a crystal stone has appeared, deal as much damage as possible!', '��������� ����, �������� �������� �������, �������� ��� ����� ������ �����!'),\
	(31, '~w~humans: %d~n~~r~zombies: %d', '~w~����: %d~n~~r~�����: %d');\
"

#define PREDIFINED_LOCALIZATION_3 "INSERT IGNORE INTO localization (id, english, russian) VALUES \
	(32, '{FFFFFF}%s {FFF000}(by %s)\n{FFF000}Score: {FFFFFF}%d\n\n{FFF000}+%d / +%d / +%d / +%d\n', '{FFFFFF}%s {FFF000}(��� ��������� %s)\n{FFF000}�����: {FFFFFF}%d\n\n{FFF000}+%d / +%d / +%d / +%d\n'),\ 
	(33, 'Evacuating / Curing / Ability using / Killing players\n(Deagle, M4, Armour)', '��������� / ������� / ������������� ����������� / �������� �������\n(Deagle, M4, �����)'),\
	(34, '>> %s (Score %d)', '>> %s (����� %d)'),\ 
	(35, '>> %s has taken control of the map from %s with %d score!', '>> ����� %s ��������� ����� � ����� %s �� ��������� � %d �����!'),\
	(36, '>> The map can be captured by a gang', '>> ����� ����� ���� ��������� ����� ������'),\
	(37, '{FFFFFF}Zombie Spawn\ndo{FF0000} not{FFFFFF} shoot zombies here', '{FFFFFF}����� ��������� �����\n{FF0000}�� �������� / ���������{FFFFFF} �����'),\
	(38, 'Error loading language pack', '������ �������� ��������� ������'),\
	(39, 'Classes', '������'),\
	(40, 'Human Classes\nZombie Classes', '������ �����\n������ �����'),\
	(41, 'Select', '�������'),\
	(42, 'Close', '�������'),\
	(43, 'POINTS', '�����'),\
	(44, '>> You have been spawned as a(n) %s. Use /class to change this', '>> ��� ������� ����� %s. ����������� /class ����� �������� ���'),\
	(45, '>> You have changed your class within the grace period and have been respawned instanlty!', '>> �� ������ ������� ���� ����� � ���������� �����!'),\
	(46, '>> Class set, will change next respawn!', '>> ����� ����������, ����� ������� ����� ������!'),\
	(47, 'points', '�����'),\
	(48, '>> You need %d %s!', '>> ��� ����� %d %s!'),\
	(49, 'MISS', '������'),\
	(50, '~g~Found:~w~ %d ammo', '~g~�������:~w~ %d ������(��)');\
"

#define PREDIFINED_LOCALIZATION_4 "INSERT IGNORE INTO localization (id, english, russian) VALUES \
	(51, '>> You were chosen as a zombie go and kill all the humans!', '>> �� ���� ������� ��� �����, ������ ���� �����!'),\	
	(52, '>> Use your abilities to make it faster (LEFT ALT)', '>> ����������� ���� �����������, ����� �������� ��� (����� ����)'),\
	(53, '~r~TRY TO STAY~n~~w~ALIVE', '~r~����������� ~w~������'),\
	(54, 'points', '����'),\
	(55, '>> Player %s was chosen to be the Human Hero / Queen. Kill him(er) and get additional %s!', '>> ����� %s ��� ������ ��� �����(���). ������ ���(��) � �������� �������������� %s!'),\
	(56, '>> Player %s has killed the Human Hero / Queen!', '>> ����� %s ���� �����(���)!'),\
	(57, '>> Player %s was chosen to be the Zombie Boss / Queen. Kill him(er) and get additional %s!', '>> ����� %s ��� ������ ��� ����� ���� / ��������. ������ ���(��) � �������� �������������� %s!'),\
	(58, '>> Player %s has killed the Zombie Boss / Queen!', '>> ����� %s ���� ����� ����� / ��������!'),\
	(59, '>> [First Blood] Player %s has drawn {FF0000}first blood{FFFFFF} and gains additional %s!', '>> [������ �����] ����� %s {FF0000}������ ������ �����{FFFFFF} � ������� ������������� %s!'),\
	(60, '>> Kill the last human and receive extra %s!', '>> ������ ���������� ��������� � �������� �������������� %s!'),\
	(61, '>> Player %s killed the last survivor and got an additional %s!', '>> ����� %s ���� ���������� ��������� � ������� �������������� %s!'),\
	(62, '>> Player %s has been infected by standard zombie %s!', '>> ����� %s ��� ������� ������� ����� %s!'),\
	(63, '>> Player %s has been infected by mutated zombie %s!', '>> ����� %s ��� ������� �� ������������� ����� %s!'),\
	(64, '>> Player %s has been infected by flesher zombie %s! (by meat)', '>> ����� %s ��� ������� ������ ����� %s! (����� ����)'),\
	(65, '>> Player %s has been infected by spore zombie %s!', '>> ����� %s ��� ������� ����� ����� �� ����� %s!'),\
	(66, '>> Player %s has been infected by spitter zombie %s!', '>> ����� %s ��� ������� ������� �� ����� %s!'),\
	(67, '>> Player %s has been infected by explosion from %s!', '>> ����� %s ��� ������� ������� �� ����� %s!'),\
	(68, '>> Player %s has blown up and infected{FFFFFF} %d human(s)!', '>> ����� %s ��������� � ������� {FFFFFF} %d �������(�)!'),\
	(69, '>> Player %s has blown up and infected{FFFFFF} WHOPPING{FF0000} %d human(s)!', '>> ����� %s ��������� � ������� {FFFFFF} ����������{FF0000} %d �������(�)!'),\
	(70, '>> Player %s has been cured by cure field!', '>> ����� %s ��� ������� ������� �����!'),\
	(71, '>> Player %s has been cured by %s! (shot)', '>> ����� %s ��� ������� ������� %s! (�������)'),\
	(72, '~r~~h~Regeneration', '~r~~h~��������������'),\
	(73, '~g~~h~Radioactive Field', '~g~~h~�������������_����'),\
	(74, '~g~Antidote', '~g~�������'),\
	(75, '>> Player %s has stole an armour from player %s!', '>> ����� %s ����� ����� ������ %s!'),\
	(76, '>> Player %s has been cursed by witch %s!', '>> ����� %s ��� ������� ������� %s!'),\
	(77, '>> Priest %s absolved all sins of the player %s!', '>> �������� %s �������� ��� ����� ������ %s!'),\
	(78, '~w~You are ~g~Cursed~n~~r~Abilities disabled', '~w~�� ~g~��������~n~~r~����������� ���������');\
"

#define PREDIFINED_LOCALIZATION_5 "INSERT IGNORE INTO localization (id, english, russian) VALUES \
	(79, '~r~This~w~ player is on your team', '~r~����~w~ ����� � ����� �������'),\
	(80, '~r~OFF', '~r~���������'),\
	(81, '~g~ON', '~g~��������'),\
	(82, '~y~Radioactive Field is %s', '~y~������������� ���� %s'),\
	(83, '~y~Cure Field is %s', '~y~������� ���� %s'),\
	(84, '~y~Holy Field is %s', '~y~������ ���� %s'),\
	(85, '~y~Support Field is %s', '~y~�������������� ���� %s'),\
	(86, '>> Player %s has been infected by %s!{FFFFFF} (by air)', '>> ����� %s ��� ������� �� ������ %s!{FFFFFF} (�� �������)'),\
	(87, '>> Player %s has been respawned as Zombie [Reason: Out Of Map]', '>> ����� %s ��� ��������� ��� ����� [�������: ����� �� �����]'),\
	(88, '>> Player %s froze{FFFFFF} %d human(s)!', '>> ����� %s ��������� {FFFFFF} %d �������(�)!'),\
	(89, '>> Player %s frozeFFFFFF} WHOPPING{FF0000} %d human(s)!', '>> ����� %s ��������� {FFFFFF} ����������{FF0000} %d �������(�)!'),\
	(90, '~g~Wait some time', '~g~���������'),\
	(91, '~r~Can not use', '~g~���������� ������������'),\
	(92, '>> Player %s has been infected by misty zombie %s!', '>> ����� %s ��� ������� �� ��������� ����� %s!'),\
	(93, '>> Player %s has been infected by blind zombie %s!', '>> ����� %s ��� ������� ����������� ����� %s!'),\
	(94, '>> Player %s has stole ammo from player %s!', '>> ����� %s ����� ������� ������ %s!'),\
	(95, '>> %s legs have been broken by %s!', '>> ���� ������ %s ���� ������� ������� %s!'),\
	(96, '~y~Remove Weapons Field is %s', '~y~���� ��������� ������ %s'),\
	(97, '~r~Weapons Removed', '~r~������ ������'), \
	(98, '>> Player %s has been poisoned by %s!', '>> ����� %s ��� �������� ������� %s!'),\
	(99, '~r~Space starts damaging you', '~r~������������ �������� ��������� ���'),\
	(100, '|: Random Question for %d points: %s', '|: ��������� ��������� �� %d �����: %s'),\
	(101, '>> %s was the first one answer the question (Answer : %s) and earns %d points!', '>> ����� %s ��� ������, ��� ������� �� ������ (�����: %s) � ������� %d �����'),\
	(102, 'Next', '���������'),\
	(103, '{d5d5c3}Achievements', '{d5d5c3}����������'),\
	(104, 'Nothing yet', '��� ���� �����'),\
	(105, '{d5d5c3}Name\t{d5d5c3}Description\n', '{d5d5c3}��������\t{d5d5c3}��������\n'),\
	(106, 'RANDOM QUESTION: No one answered!', '��������� ���������: ����� �� �������!'),\
	(107, '>> Lottery: Number will be drawn soon. Use /lottery to get your own number', '>> �������: ����� ����� ����� ��������. ����������� /lottery � �������� ��� �����!'),\
	(108, '>> Lottery: Nobody won!{FF0000} Number: %d Jackpot: %d', '>> �������: ����� �� ������! {FF0000} �����: %d �������: %d'),\
	(109, '>> Lottery: %s has won the lottery!{C659B6} Number: %d Jackpot: %d', '>> �������: ����� %s ������ �������! {C659B6} �����: %d �������: %d'),\
	(110, '>> The lottery hasnt started yet', '>> ������� ��� �� ��������'),\
	(111, '>> You have already chosen your number!', '>> �� ��� ������� ���� �����!'),\
	(112, '>> Your number is %d', '>> ��� ����� - %d');\
"

#define PREDIFINED_LOCALIZATION_6 "INSERT IGNORE INTO localization (id, english, russian) VALUES \
	(113, '~~~~~~~~~~~~~~ %s ~~~~~~~~~~~~~~', '~~~~~~~~~~~~~~ %s ~~~~~~~~~~~~~~'),\
	(114, '>> Kills: %d - Killstreak: %d (best: %d)', '>> �������: %d - ������� ������: %d (������ ���������: %d)'),\
	(115, '>> Wins: %d - Duel Wins: %d - Rank: %d', '>> ���������: %d - Duel Wins: %d - Rank: %d'),\
	(116, '>> Played: %d Hours - %d Minutes - %d Seconds', '>> ����� � ����: %d ���(�/��) - %d �����(�/�) - %d ������(�/�)'),\
	(117, '>> Gang: (ID %d)(Rank: %d) - {dfb7bc}Account ID: %d', '>> �����: (�� %d)(����: %d) - {dfb7bc}ID ��������: %d'),\
	(118, '>> Date: %02dD/%02dM/%dY - Session: MD_%s', '>> ����: %02dD/%02dM/%dY - ������: MD_%s'),\
	(119, 'Coin(s)', '�����(�/�)'),\
	(120, '>> %s has unlocked a New Achievement named{FFFFFF} %s +%d %s (/achievements)', '>> ����� %s ������ ����� ����������{FFFFFF} %s +%d %s (/achievements)'),\
	(121, '>> %s has achieved a %d killstreak!{FFFFFF} (+%d %s)', '>> ����� %s ������ ����� �� %d �������!{FFFFFF} (+%d %s)'),\
	(122, '>> %s earned %d %s for killing %s on {FFFFFF}%d killstreak!', '>> ����� %s ��������� %d %s �� �������� ������ %s ��{FFFFFF} ����� �� %d �������!'),\
	(123, '>> Points: %d - Total: %d', '>> ����: %d - �����: %d'),\
	(124, '>> You have saved your stats!', '>> �� ��������� ���� ����������!'),\
	(125, 'Choose your language', '�������� ���� ����'),\
	(126, 'English\nRussian', '����������\n�������'),\
	(127, '>> Language set!', '>> ���� ����������!'),\
	(128, '[QUESTION]: %s asked a question:{FFFFFF} %s', '[������]: ����� %s ����� ������:{FFFFFF} %s'),\
	(129, '>> The player has closed private messages!', '>> ����� ������ ������ ���������!'),\
	(130, '>> Setting disabled!', '>> ��������� ���������!'),\
	(131, '>> Setting enabled!', '>> ��������� ��������!'),\
	(132, 'Settings', '���������'),\
	(133, 'Setting Name\tState\nBlock PMs\t%s\nDing On Hit\t%s\nBlock Duel Requests\t%s\n\"Ability Is Ready\" notification\t%s\nAuto-Login\t%s', '��������\t���������\n����������� ��\t%s\n���� ��� ���������\t%s\n����������� �����\t%s\n����������� \"����������� ������\"\t%s\n����-�����\t%s'),\
	(134, '{009900}[ YES ]', '{009900}[ �� ]'),\
	(135, '{ff1a1a}[ NO ]', '{ff1a1a}[ ��� ]'),\
	(136, '~y~ABILITY~w~ IS~g~ READY!', '~y~�����������~g~ ������!'),\
	(137, '>> Congratulations, {FF0000}you are banned!', '>> �����������, {FF0000}�� �������������!'),\
	(138, 'Rules', '�������'),\
	(139, 'Help', '������'),\
	(140, '[REPORT] %s has reported %s(%d):{FFFFFF} %s', '[������] ����� %s �������� ������ �� ������ %s(%d):{FFFFFF} %s'),\
	(141, 'Report sent!', '������ ����������!'),\
	(142, 'Unknown command. Check /cmds', '����������� �������. ����������� /cmds'),\
	(143, '>> Voting is already underway!', '>> ����������� ��� ���!'),\
	(144, '[VOTEKICK] Player %s(%d) will be kicked [Reason: %s]{FFFFFF} (by %s)', '[�����������] ����� %s(%d) ����� ������ [�������: %s]{FFFFFF} (��������� %s)'),\
	(145, '[VOTEKICK] Use /yes and /no for voting!', '[�����������] ����������� /yes � /no ��� �����������!'),\
	(146, '>> %s voted for a kick (%d / %d)', '>> ����� %s ������������ �� ��� (%d / %d)'),\
	(147, '>> %s did not vote for a kick (%d / %d)', '>> ����� %s ������������ ������ (%d / %d)');\
"

#define PREDIFINED_LOCALIZATION_7 "INSERT IGNORE INTO localization (id, english, russian) VALUES \
	(148, '[VOTEKICK] %s has been kicked', '[�����������] ����� %s ��� ������'),\
	(149, '[VOTEKICK] Voting canceled', '[�����������] ��������'),\
	(150, '*** %s has joined the server (ID %d) (Player %d) (IP %s)', '*** ����� %s ����������� � ������� (ID %d) (����� %d) (IP %s)'),\
	(151, '*** %s has left the server (%s) (%s)', '*** ����� %s ����� � ������� (%s) (%s)'),\
	(152, '[ADMIN MESSAGE] %s send an admin message to %s(%d):{FFFFFF} %s', '[�����-���������] ������������� %s ������� ������ %s(%d):{FFFFFF} %s'),\
	(153, '[ADMIN MESSAGE]:{FFFFFF} %s', '[�����-���������]:{FFFFFF} %s'),\
	(154, '>> %s(%d) has been jailed by %s for 3 minutes [Reason: %s]', '>> ����� %s(%d) ��� ������� � ������ ��������������� %s �� 3 ������ [�������: %s]'),\
	(155, '>> %s has been jailed for 3 minutes [Reason: %s]', '>> ����� %s ��� ������� � ������ �� 3 ������ [�������: %s]'),\
	(156, '>> %s(%d) has been unjailed by %s', '>> ����� %s(%d) ��� ��������� �� ������ ��������������� %s'),\
	(157, '>> %s has been unjailed', '>> ����� %s ��� ��������� �� ������'),\
	(158, '{d5d5c3}Weekly Activities', '{d5d5c3}������������ �������'),\
	(159, 'Activities\nRewards', '�������\n�������'),\
	(160, '{d5d5c3}Name\t{d5d5c3}Description\t{d5d5c3}Total Points\n', '{d5d5c3}��������\t{d5d5c3}��������\t{d5d5c3}����� � �����\n'),\
	(161, '>> Chat cleared by %s', '��� ��� ������ ��������������� %s'),\
	(162, '>> Chat cleared by an administrator', '��� ��� ������ ���������������'),\
	(163, '>> %s(%d) has been kicked by %s [Reason: %s]', '%s(%d) ��� ������ ��������������� %s [�������: %s]'),\
	(164, '>> %s has been kicked [Reason: %s]', '%s ��� ������ [�������: %s]'),\
	(165, '>> %s(%d) has been synced by %s', '����� %s(%d) ��� ��������������� ��������������� %s'),\
	(166, '>> %s has been synced', '����� %s ��� ���������������'),\
	(167, '>> %s(%d) got a slap from %s [Reason: %s]', '����� %s(%d) ������� �������� �� %s [�������: %s]'),\
	(168, '>> %s got a slap [Reason: %s]', '����� %s ������� �������� [�������: %s]'),\
	(169, '>> %s has changed %s(%d) team to zombie [Reason: %s]', '������������� %s ������ ������� ������ %s(%d) �� ����� [�������: %s]'),\
	(170, '>> %s has changed team to zombie [Reason: %s]', '����� %s ������ ������� �� ����� [�������: %s]'),\
	(171, '~~~~~~~ MATCHES ~~~~~~~', '~~~~~~~ ���������� ~~~~~~~'),\
	(172, '>> Nothing found', '>> ������ �� �������'),\
	(173, '>> %s(%d) has been banned by %s [Reason: %s]', '>> ����� %s(%d) ��� ������������ ��������������� %s [�������: %s]'),\
	(174, '>> %s has been banned [Reason: %s]', '����� %s ��� ������������ [�������: %s]'),\
	(175, '>> You have been in afk too long, your team has been changed to zombies', '>> �� ���������� � ��� ������� �����, ���� ������� �������� �� �����'),\
	(176, '>> %s has been kicked [Reason: Exceeding the allowed ping limit]', '>> ����� %s ��� ������ [�������: ���������� ������ ����������� �����]'),\
	(177, '>> %s has been kicked [Reason: Exceeding the limit of being in AFK]', '>> ����� %s ��� ������ [�������: ���������� ������ ���������� � ���]');\
"

#define PREDIFINED_LOCALIZATION_8 "INSERT IGNORE INTO localization (id, english, russian) VALUES \
	(178, '>> Thank you for your assistance, you have been given additional points for helping the administration', '>> ������� �� ������, ��� ��������� �������������� ����'),\
	(179, '>> Wrong banned? Appeal at %s', '>> ������ �������� ���? ������� ������ �����: %s'),\
	(180, '>> Create a screenshot of your ban by pressing F8 | (Documents/GTA San Andreas User Files/SAMP/screens)', '>> �������� �������� ����� F8 � ��������� � Documents/GTA San Andreas User Files/SAMP/screens'),\
	(181, '>> By %s - {FF0000}Reason: %s', '>> �������������: %s - {FF0000}�������: %s'),\
	(182, '>> At: %02dD/%02dM/%04dY', '>> ����: %02dD/%02dM/%04dY'),\
	(183, '>> %s has attempted to join the server whilst serving a ban', '>> ����� %s ������� �����������, �� ��� ��������� ���������'),\
	(184, '>> %s has attempted to join the server whilst serving a temp ban', '����� %s ������� �����������, �� ��� ��������� �������� ���������'),\
	(185, '>> Account not found in ban list', '>> ������� �� ������ � ������ ����������'),\
	(186, '>> %s has been unbanned by %s', '>> ������� %s ��� ������������� ��������������� %s'),\
	(187, '>> %s(%d) has been banned by %s for %d hour(s) [Reason: %s]', '>> ����� %s(%d) ��� ������������ ��������������� %s �� %d ���(�/��) [�������: %s]'),\
	(188, '>> %s has been banned for %d hour(s) [Reason: %s]', '����� %s ��� ������������ �� %d ���(�/��) [�������: %s]'),\
	(189, '>> %s has started to spectating for %s(%d)', '������������� %s ����� ������ �� %s(%d)'),\
	(190, '>> %s has stopped spectating for %s(%d)', '������������� %s ��������� ������ �� %s(%d)'),\
	(191, '>> %s has changed time to %d', '������������� %s ������� ����� �� %d'),\
	(192, '>> %s has changed weather to %d', '������������� %s ������� ������ �� %d'),\
	(193, '>> %s(%d) has been warned by %s (%d / 3) [Reason: %s]', '>> %s(%d) ������� �������������� �� �������������� %s (%d / 3) [�������: %s]'),\
	(194, '>> %s has been warned (%d / 3) [Reason: %s]', '>> %s ������� �������������� (%d / 3) [�������: %s]'),\
	(195, 'WARNING', '��������������'),\
	(196, '>> %s has been kicked [Reason: Maximum number of warnings reached]', '>> ����� %s ��� ������ [�������: ���������� ������������ ���������� ��������������]'),\
	(197, '>> %s(%d) has been unwarned by %s', '>> �������������� � ������ %s(%d) ���� ����� ��������������� %s'),\
	(198, '>> The player does not have warns!', '>> � ������ ���� ��������������'),\
	(199, '>> %s(%d) has been muted for %d minutes by %s [Reason: %s]', '>> %s(%d) ������� ��� �� %d �����(�/�) �� �������������� %s [�������: %s]'),\
	(200, '>> %s has been muted for %d minutes [Reason: %s]', '>> %s ������� ��� �� %d �����(�/�) [�������: %s]'),\
	(201, '>> %s(%d) has been unmuted by %s', '>> ����� %s(%d) ������� ������ �� �������������� %s'),\
	(202, '>> %s has been unmuted', '>> ����� %s ������� ������'),\
	(203, '>> You are muted, %d seconds left', '>> � ��� ���, �������� ��������� %d ������');\
"

#define PREDIFINED_LOCALIZATION_9 "INSERT IGNORE INTO localization (id, english, russian) VALUES \
	(204, '>> This CMD has already been used!', '>> ��� ������� ��� ���� ������������!'),\
	(205, 'You need to wait', '���������'),\
	(206, '>> %s has been banned by %s [Reason: %s] (OFFLINE)', '>> ������� %s ��� ������������ ��������������� %s [�������: %s] (�������)'),\
	(207, '>> Account not found!', '>> ������� �� ������!'),\
	(208, '>> %s has been banned by %s for %d hour(s) [Reason: %s] (OFFLINE)', '>> ������� %s ��� ������������ ��������������� %s �� %d ���(�/��) [�������: %s] (�������)'),\
	(209, '>> Name: %s - IP: %s', '>> ���: %s - IP: %s'),\
	(210, '>> Health: %.2f% - Armour: %.2f', '>> ��������: %.2f - �����: %.2f'),\
	(211, '>> Points: %d / %d - Money: %d', '>> ����: %d / %d - ������: %d'),\
	(212, '>> Team: Zombie - Class: %s', '>> �������: ����� - �����: %s'),\
	(213, '>> Team: Human - Class: %s', '>> �������: ���� - �����: %s'),\
	(214, '>> Weapon: %s - Ammo: %d', '>> ������: %s - �������: %d'),\
	(215, '>> Packets lost: %.2f', '>> ��������� ������� �������: %.2f'),\
	(216, '>> This nickname does not fit, come up with another one', '>> ���� ��� �� ��������, ���������� ������'),\
	(217, '>> This nickname is already taken, come up with another one', '>> ���� ��� ��� �����, ���������� ������'),\
	(218, '>> Your nickname has successfully changed to %s, the fee for changing is %d', '>> ��� ��� ������� ������� �� %s, ����� �� ����� ��������� %d'),\
	(219, '[ADMIN]: %s is now known as %s!', '[�����]: ����� %s ������ ��� �� %s!'),\
	(220, '>> IP %s has been banned by %s [Reason: %s]', '>> IP %s ��� ������������ ��������������� %s [�������: %s]'),\
	(221, '>> This IP is already banned', '>> ���� IP ��� ������������'),\
	(222, '>> This IP is not banned', '>> ���� IP �� ������������'),\
	(223, '>> IP %s has been unbanned by %s', '>> IP %s ��� ������������� ��������������� %s'),\
	(224, '>> %s(%d) has been frozen by %s [Reason: %s]', '>> ����� %s(%d) ��� ��������� ��������������� %s [�������: %s]'),\
	(225, '>> %s has been frozen [Reason: %s]', '>> ����� %s ��� ��������� [�������: %s]'),\
	(226, '>> %s(%d) has been unfrozen by %s', '>> ����� %s(%d) ��� ���������� ��������������� %s'),\
	(227, '>> %s has been unfrozen', '>> ����� %s ��� ����������'),\
	(228, 'Information', '����������'),\
	(229, 'Player\tBy\tReason\tDate\n', '�����\t���\t�������\t����\n'),\
	(230, 'New\tOld\tIP\tDate\n', '�����\t������\tIP\t����\n'),\
	(231, 'IP\tBy\tReason\tDate\n', 'IP\t���\t�������\t����\n'),\
	(232, '[ADMIN]: %s has set admin rank of %s to %d!', '[�����]: ������������� %s ��������� ����� ���� ������ %s �� %d �������!'),\
	(233, '~y~REQUEST FOR A DUEL', '~y~������ �� �����'),\
	(234, '>> You have accepted the duel!', '>> �� ������� �����!'),\
	(235, '>> The player accepted your request!', '>> ����� ������ ��� ������ �� �����!'),\
	(236, '>> You have denied the duel!', '>> �� ��������� �����!'),\
	(237, '>> The player denied your request!', '>> ����� �������� ��� ������ �� �����!'),\
	(238, '>> Not enough points from one of sides', '>> ������������ ����� � ����� �� ������'),\
	(239, '>> You cannot send a request to this person', '>> �� �� ������ ��������� ����� � ���� ���������');\
"

#define PREDIFINED_LOCALIZATION_10 "INSERT IGNORE INTO localization (id, english, russian) VALUES \
	(240, ' (Armour: %d)', ' (�����: %d)'),\
	(241, ' (Points: %d)', ' (����: %d)'),\
	(242, '>> %s is inviting you to duel with weapon: %s (ID %d)%s%s', '>> ����� %s ���������� ��� �� ����� � ������� %s (ID %d)%s%s'),\
	(243, '>> Type /y to agree and /n to deny', '>> ������� /y ��� �������� � /n ��� ������'),\
	(244, '>> You sent a duel request to %s!', '>> ��� ������ �� ����� ��������� ������ %s'),\
	(245, '>> %s has started a duel with %s (%s) (ID %d)%s%s', '>> ����� %s ����� ����� � ������� %s (%s) (ID %d)%s%s'),\
	(246, '>> You are not in duel!', '>> �� �� � �����!'),\
	(247, '[DUEL]: %s has won the duel against %s!%s', '[�����]: ����� %s ������ ����� ������ ������ %s!%s'),\
	(248, '>> %s paid %d points to %s. With taxes: %d', '>> ����� %s ������� %d ����� ������ %s. �������� �������� � �������: %d'),\
	(249, '[%s] %s by {FFFFFF}%s (Members: %d) (Control over: %s)', '[%s] %s {FFFFFF}(������������ %s) (���������: %d) (�������� ���: %s)'),\
	(250, '>> You are blacklisted from this gang [Reason: %s]', '>> �� � ������ ������ ���� ����� [�������: %s]'),\
	(251, '>> You have to leave your gang first! (/gang leave)', '>> �� ������ �������� ���� ������� �����! (/gang leave)'),\
	(252, '>> This gang is not currently accepting requests!', '>> ��� ����� ���� �� ��������� ������!'),\
	(253, '>> %s sent a request to join your gang!', '>> ����� %s ������� ������ �� ���������� � ���� �����!'),\
	(254, '>> Use /gang accept %d to accept!', '>> ����������� /gang accept %d ��� ��������� ������!'),\
	(255, '>> You have sent a request to join %s (ID %d)', '>> �� ��������� ������ �� ���������� � %s (ID %d)'),\
	(256, '>> Insufficient rights to use this command!', '>> ������������ ���� ��� ������������� �������!'),\
	(257, '>> %s has been accepted to your gang by %s!', '>> ����� %s ��� ������ � ���� ����� ������� %s!'),\
	(258, '>> Your gang request has been accepted!', '>> ���� ������ � ����� ���� ��������!'),\
	(259, '>> Put ! at the beginning of the message to send a message to the gang!', '��������� ! � ������ ��������� ����� ��������� ��������� � �����!'),\
	(260, '[%s] %s by {FFFFFF}%s (Members: %d)', '[%s] %s {FFFFFF}(������������ %s) (���������: %d)'),\
	(261, '>> All slots are occupied, it is impossible to create a gang', '>> ��� ����� ������, ������� ����� ����������'),\
	(262, '[ADMIN] %s has created a new gang %s (ID %d)', '[�����] ����� %s ������ ����� ����� %s (ID %d)'),\
	(263, 'Peon,Policeman,Scout,Agent,Director,Boss', '�������,�����������,�����,�����,��������,����'),\
	(264, '{FFFFFF}Set or Accessory\t{FFFFFF}Spiral knots (%d)\t{FFFFFF}Coins (%d)\n', '{FFFFFF}����� ��� ���������\t{FFFFFF}���������� ���� (%d)\t{FFFFFF}������ (%d)\n'),\
	(265, 'Are you sure want to buy %s for %d Spiral knots and %d Coins?', '�� ����� ������ ������ %s �� %d ���������� ����� � %d �����(�)'),\
	(266, 'Completed', '���������'),\
	(267, 'Yes', '��'),\
	(268, '{FFFFFF}Tagret\t{FFFFFF}Reputation\t{FFFFFF}Progress\n', '{FFFFFF}����\t{FFFFFF}���������\t{FFFFFF}��������\n'),\
	(269, '{FFFFFF}Not enough currency to purchase', '{FFFFFF}������������ ������ ��� �������'),\
	(270, '>> You bought %s! (/clothes)', '>> �� ������ %s! (/clothes)');\
"

#define PREDIFINED_LOCALIZATION_11 "INSERT IGNORE INTO localization (id, english, russian) VALUES \
	(271, '>> %s has captured the map with %d score!', '>> ����� %s ��������� ����� �� ��������� � %d �����!'),\
	(272, '>> %s set a new record of %d score!', '>> ����� %s ���������� ����� ������ � ������� %d �����!'),\
	(273, '>> There are not enough slots in the gang to apply!', '>> � ���� ����� ������������ ������ ��� ������ ������!'),\
	(274, '>> Your rank does not allow you to apply to this gang!', '>> ��� ���� �� ��������� ��� ������ ������ � ��� �����!'),\
	(275, 'SPAWN PROTECTION', '������� ����-����� ���������'),\
	(276, 'INSUFFICIENT CALIBER', '����� ������'),\
	(277, 'Option\tState\nState\t%s\nName\t%s\nTag\t%s\nRank is needed to send request\t%d\nRank that can use /gang settings\t%d\n', '���������\t��������\n���������\t%s\n��������\t%s\n���\t%s\n\n���� ��� ������ ������\t%d\n���� ��� ������������� /gang settings\t%d\n'),\
	(278, 'Rank that can use /gang ban\t%d\nRank that can use /gang promote/demote\t%d\n', '���� ��� ������������� /gang ban\t%d\n���� ��� ������������� /gang promote/demote\t%d\n'),\
	(279, 'Rank that can use /gang pay\t%d\nRank that can use /gang accept\t%d\n', '���� ��� ������������� /gang pay\t%d\n���� ��� ������������� /gang accept\t%d'),\
	(280, 'Open', '�������'),\
	(281, 'Closed', '�������'),\
	(282, '>> %s supposedly uses Teleport Hack', '>> ����� %s �������� ���������������'),\
	(283, 'Type the rank you think is appropriate for this setting\nValid rank values from 1 to 6', '������� ����, ������� �������� ������ ��� ���� ���������\n���������� �������� � 1 �� 6'),\
	(284, 'Type a new name for the gang', '������� ����� ��� �����'),\
	(285, 'Type a new gang tag', '������� ����� ��� �����'),\
	(286, 'Type new rank for gang applications, min. 0 and max. 100', '������� ����� ���� ��� ������ ������, ���. 0 � ����. 100'),\
	(287, '---------- %s (Pot %d) (Members %d / %d) ----------', '---------- %s (����� %d) (��������� %d / %d) ----------'),\
	(288, '(Rank %d) >> %s (ID %d)', '(���� %d) >> %s (�� %d)'),\
	(289, 'Member\tRank\tLast Online\n', '��������\t����\t��������� ��� � ����\n'),\
	(290, 'Admin\tLevel\tLast Online\n', '�������������\t�������\t��������� ��� � ����\n'),\
	(291, '>> %s has been kicked [Reason: Auth time exceeded]', '>> ����� %s ��� ������ [�������: ���������� ������� �����������]'),\
	(292, '>> %s has been kicked for 3 failed login attempts!', '>> ����� %s ��� ������ �� 3 �������� ������� �����������!'),\
	(293, '>> It is impossible to leave the gang due to the number of members, or you are the founder!', '>> ���������� �������� ����� �� �� ������ ���-�� ����������, ���� �� ���������� �����!'),\
	(294, '>> You left the gang', '>> �� �������� �����'),\
	(295, '>> %s proposed war to your gang', '>> ����� %s ���������� ����� ����� �����'),\
	(296, '>> Compete with another gang to collect score per round, the one with the most wins!', '>> ������������ � ������ ������ � ������ ����� �� �����, ������� ��, � ������� ����� ������!'),\
	(297, '>> On the captured map you will receive M4, Deagle, Armor and the opportunity to replenish the gang pot for actions!', '>> �� ���������� ����� �� �������� M4, ����, ����� � ����������� ��������� ����� ����� �� ��������!'),\
	(298, '>> Use /gang war %d to accept the war', '>> ����������� /gang war %d ����� ������� ������ �� �����'),\
	(299, '>> %s started a war against %s!', '>> ����� %s ������ ����� ������ ����� %s!'),\
	(300, '>> %s ended a war against %s', '>> ����� %s ����������� �� ����� � ������ %s!'),\
	(301, '>> %s created an alliance with %s!', '>> ����� %s ������� ������ � ������ %s!'),\
	(302, '>> %s broke off alliance with %s!', '>> ����� %s ��������� ������ � ������ %s!'),\
	(303, '>> %s proposed alliance to your gang', '>> ����� %s ���������� ������ ����� �����'),\
	(304, '>> Allied gangs have a unified chat', '>> � ������� ���� ����� ���'),\
	(305, '>> Use /gang alliance %d to accept the alliance', '>> ����������� /gang alliance %d ����� ������� ������');\
"