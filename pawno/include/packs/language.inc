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
	(1, 1, 5, 1, 'Accessory: Sniper', 'Аксессуар: Снайперская винтовка'),\
	(2, 2, 5, 1, 'Accessory: Ak47', 'Аксессуар: Ak47'),\
	(3, 3, 5, 1, 'Accessory: Guitar', 'Аксессуар: Гитара'),\
	(4, 4, 5, 1, 'Accessory: Surfboard', 'Аксессуар: Доска для серфинга'),\
	(5, 5, 5, 1, 'Accessory: Money case', 'Аксессуар: Денежный ящик'),\
	(6, 6, 5, 1, 'Accessory: Backpack', 'Аксессуар: Рюкзак'),\
	(7, 7, 5, 2, 'Haloween Set', 'Набор одежды: Хэллоуин'),\
	(8, 8, 5, 2, 'Christmas Set', 'Набор одежды: Новый год'),\
	(9, 9, 5, 3, 'Army Set', 'Набор одежды: Армия');\
"

#define PREDIFINED_LOCALIZATION_1 "INSERT IGNORE INTO localization (id, english, russian) VALUES \
	(1, 'Login', 'Логин'),\
	(2, 'Welcome back, your account is already registered\nEnter your password below to login', 'Добро пожаловать, ваш аккаунт уже зарегистрирован\nВведите пароль'),\
	(3, 'Wrong password, %d / 3 tries left\n\nWelcome back, your account is already registered\nEnter your password below to login', 'Неверный пароль, осталось %d / 3 попыток\nДобро пожаловать, ваш аккаунт уже зарегистрирован\nВведите пароль'),\
	(4, 'You have to type at least something!\n\nWelcome back, your account is already registered\nEnter your password below to login', 'Поле пароля не может быть пустым!\nДобро пожаловать, ваш аккаунт уже зарегистрирован\nВведите пароль'),\				
	(5, 'Register', 'Регистрация'),\
	(6, 'Welcome to the server, your account was not found\nEnter your password below to complete registration', 'Добро пожаловать, ваш аккаунт не найден\nПридумайте пароль'),\
	(7, 'You have to type at least something!\n\nWelcome to the server, your account was not found\nEnter your password below to complete registration', 'Поле пароля не может быть пустым!\nДобро пожаловать, ваш аккаунт не найден\nПридумайте пароль'),\
	(8, 'Register', 'Регистрация'),\
	(9, 'Login', 'Логин'),\
	(10, 'Quit', 'Выйти'),\
	(11, '*** %s has joined the server (ID %d) (Player %d)', '*** Игрок %s подключился к серверу (ID %d) (Игрок %d)'),\
	(12, '*** %s has left the server (%s)', '*** Игрок %s вышел с сервера (%s)'),\
	(13, 'Timeout', 'Разрыв соединения'),\
	(14, 'Leave', 'Выход'),\
	(15, 'Kick', 'Кикнут'),\
	(16, 'Unknown', 'Неизвестно');\
"

#define PREDIFINED_LOCALIZATION_2 "INSERT IGNORE INTO localization (id, english, russian) VALUES \
	(17, 'Restarting', 'Перезагрузка'),\
	(18, '>> %s has made it to the evacuation point!', '>> Игрок %s эвакуировался!'),\
	(19, '>> ALL SURVIVORS EVACUATED!', '>> Все выжившие добрались до пункта эвакуации!'),\
	(20, '>> Under protection {FFFFFF}%d{FF0000} seconds left!', '>> Под защитой, до снятия {FFFFFF}%d{FF0000} секунд'),\
	(21, '(by %s)', '(автор %s)'),\
	(22, '(captured by %s)', '(под контролем у %s)'),\
	(23, '>> Entering The Map #%d (%s) %s %s', '>> Запускаем карту #%d (%s) %s %s'),\
	(24, '>> Creating objects...', '>> Создание объектов...'),\
	(25, '>> ZOMBIES WIN!', '>> ЗОМБИ ПОБЕДИЛИ!'),\
	(26, '>> An evacuation has arrived for humans!', '>> Эвакуация прибыла для людей!'),\
	(27, '>> Humans get to the checkpoint within a minute!', '>> Выжившие, доберитесь до чекпоинта за минуту!'),\
	(28, '>> Beginning new a round...', '>> Начинается новый раунд!'),\
	(29, '~r~ROUND OVER~n~~w~STARTING NEW ROUND...', '~r~КОНЕЦ РАУНДА~n~~w~НАЧИНАЕМ НОВЫЙ...'),\
	(30, '>> Gang members, a crystal stone has appeared, deal as much damage as possible!', 'Участники банд, появился защитный кристал, нанесите как можно больше урона!'),\
	(31, '~w~humans: %d~n~~r~zombies: %d', '~w~ЛЮДИ: %d~n~~r~ЗОМБИ: %d');\
"

#define PREDIFINED_LOCALIZATION_3 "INSERT IGNORE INTO localization (id, english, russian) VALUES \
	(32, '{FFFFFF}%s {FFF000}(by %s)\n{FFF000}Score: {FFFFFF}%d\n\n{FFF000}+%d / +%d / +%d / +%d\n', '{FFFFFF}%s {FFF000}(под контролем %s)\n{FFF000}Очков: {FFFFFF}%d\n\n{FFF000}+%d / +%d / +%d / +%d\n'),\ 
	(33, 'Evacuating / Curing / Ability using / Killing players\n(Deagle, M4, Armour)', 'Эвакуация / Лечение / Использование способности / Убийство игроков\n(Deagle, M4, Броня)'),\
	(34, '>> %s (Score %d)', '>> %s (Очков %d)'),\ 
	(35, '>> %s has taken control of the map from %s with %d score!', '>> Банда %s отвоевала карту у банды %s со значением в %d очков!'),\
	(36, '>> The map can be captured by a gang', '>> Карта может быть захвачена любой бандой'),\
	(37, '{FFFFFF}Zombie Spawn\ndo{FF0000} not{FFFFFF} shoot zombies here', '{FFFFFF}Точка появления зомби\n{FF0000}не убивайте / стреляйте{FFFFFF} здесь'),\
	(38, 'Error loading language pack', 'Ошибка загрузки языкового пакета'),\
	(39, 'Classes', 'Классы'),\
	(40, 'Human Classes\nZombie Classes', 'Классы Людей\nКлассы Зомби'),\
	(41, 'Select', 'Выбрать'),\
	(42, 'Close', 'Закрыть'),\
	(43, 'POINTS', 'ОЧКОВ'),\
	(44, '>> You have been spawned as a(n) %s. Use /class to change this', '>> Ваш текущий класс %s. Используйте /class чтобы изменить его'),\
	(45, '>> You have changed your class within the grace period and have been respawned instanlty!', '>> Вы успели сменить свой класс в подходящее время!'),\
	(46, '>> Class set, will change next respawn!', '>> Класс установлен, будет изменен после спавна!'),\
	(47, 'points', 'очков'),\
	(48, '>> You need %d %s!', '>> Вам нужно %d %s!'),\
	(49, 'MISS', 'ПРОМАХ'),\
	(50, '~g~Found:~w~ %d ammo', '~g~Поднято:~w~ %d патрон(ов)');\
"

#define PREDIFINED_LOCALIZATION_4 "INSERT IGNORE INTO localization (id, english, russian) VALUES \
	(51, '>> You were chosen as a zombie go and kill all the humans!', '>> Вы были выбраны как зомби, убейте всех людей!'),\	
	(52, '>> Use your abilities to make it faster (LEFT ALT)', '>> Используйте свои способности, чтобы ускорить это (Левый Альт)'),\
	(53, '~r~TRY TO STAY~n~~w~ALIVE', '~r~ПОПЫТАЙТЕСЬ ~w~ВЫЖИТЬ'),\
	(54, 'points', 'очки'),\
	(55, '>> Player %s was chosen to be the Human Hero / Queen. Kill him(er) and get additional %s!', '>> Игрок %s был выбран как Герой(иня). Убейте его(ее) и получите дополнительные %s!'),\
	(56, '>> Player %s has killed the Human Hero / Queen!', '>> Игрок %s убил Героя(иню)!'),\
	(57, '>> Player %s was chosen to be the Zombie Boss / Queen. Kill him(er) and get additional %s!', '>> Игрок %s был выбран как Зомби Босс / Королева. Убейте его(ее) и получите дополнительные %s!'),\
	(58, '>> Player %s has killed the Zombie Boss / Queen!', '>> Игрок %s убил Зомби Босса / Королеву!'),\
	(59, '>> [First Blood] Player %s has drawn {FF0000}first blood{FFFFFF} and gains additional %s!', '>> [Первая Кровь] Игрок %s {FF0000}пустил первую кровь{FFFFFF} и получил дополниельные %s!'),\
	(60, '>> Kill the last human and receive extra %s!', '>> Убейте последнего выжевшего и получите дополнительные %s!'),\
	(61, '>> Player %s killed the last survivor and got an additional %s!', '>> Игрок %s убил последнего выжившего и получил дополнительные %s!'),\
	(62, '>> Player %s has been infected by standard zombie %s!', '>> Игрок %s был заражен обычным зомби %s!'),\
	(63, '>> Player %s has been infected by mutated zombie %s!', '>> Игрок %s был заражен от мутированного зомби %s!'),\
	(64, '>> Player %s has been infected by flesher zombie %s! (by meat)', '>> Игрок %s был заражен гнилым зомби %s! (через мясо)'),\
	(65, '>> Player %s has been infected by spore zombie %s!', '>> Игрок %s был заражен через споры от зомби %s!'),\
	(66, '>> Player %s has been infected by spitter zombie %s!', '>> Игрок %s был заражен плевком от зомби %s!'),\
	(67, '>> Player %s has been infected by explosion from %s!', '>> Игрок %s был заражен взрывом от зомби %s!'),\
	(68, '>> Player %s has blown up and infected{FFFFFF} %d human(s)!', '>> Игрок %s взорвался и заразил {FFFFFF} %d человек(а)!'),\
	(69, '>> Player %s has blown up and infected{FFFFFF} WHOPPING{FF0000} %d human(s)!', '>> Игрок %s взорвался и заразил {FFFFFF} НЕВЕРОЯТНО{FF0000} %d человек(а)!'),\
	(70, '>> Player %s has been cured by cure field!', '>> Игрок %s был выличен лечящем полем!'),\
	(71, '>> Player %s has been cured by %s! (shot)', '>> Игрок %s был выличен игроком %s! (выстрел)'),\
	(72, '~r~~h~Regeneration', '~r~~h~Восстановление'),\
	(73, '~g~~h~Radioactive Field', '~g~~h~Радиоактивное_Поле'),\
	(74, '~g~Antidote', '~g~Антидот'),\
	(75, '>> Player %s has stole an armour from player %s!', '>> Игрок %s украл броню игрока %s!'),\
	(76, '>> Player %s has been cursed by witch %s!', '>> Игрок %s был проклят ведьмой %s!'),\
	(77, '>> Priest %s absolved all sins of the player %s!', '>> Священик %s отпустил все грехи игрока %s!'),\
	(78, '~w~You are ~g~Cursed~n~~r~Abilities disabled', '~w~Вы ~g~прокляты~n~~r~Способности отключены');\
"

#define PREDIFINED_LOCALIZATION_5 "INSERT IGNORE INTO localization (id, english, russian) VALUES \
	(79, '~r~This~w~ player is on your team', '~r~Этот~w~ игрок в вашей команде'),\
	(80, '~r~OFF', '~r~ВЫКЛЮЧЕНО'),\
	(81, '~g~ON', '~g~ВКЛЮЧЕНО'),\
	(82, '~y~Radioactive Field is %s', '~y~Радиоактивное Поле %s'),\
	(83, '~y~Cure Field is %s', '~y~Лечащие Поле %s'),\
	(84, '~y~Holy Field is %s', '~y~Святое Поле %s'),\
	(85, '~y~Support Field is %s', '~y~Поддерживающие Поле %s'),\
	(86, '>> Player %s has been infected by %s!{FFFFFF} (by air)', '>> Игрок %s был заражен от игрока %s!{FFFFFF} (по воздуху)'),\
	(87, '>> Player %s has been respawned as Zombie [Reason: Out Of Map]', '>> Игрок %s был возрожден как Зомби [Причина: Выход за карту]'),\
	(88, '>> Player %s froze{FFFFFF} %d human(s)!', '>> Игрок %s заморозил {FFFFFF} %d человек(а)!'),\
	(89, '>> Player %s frozeFFFFFF} WHOPPING{FF0000} %d human(s)!', '>> Игрок %s заморозил {FFFFFF} НЕВЕРОЯТНО{FF0000} %d человек(а)!'),\
	(90, '~g~Wait some time', '~g~Подождите'),\
	(91, '~r~Can not use', '~g~Невозможно использовать'),\
	(92, '>> Player %s has been infected by misty zombie %s!', '>> Игрок %s был заражен от туманного зомби %s!'),\
	(93, '>> Player %s has been infected by blind zombie %s!', '>> Игрок %s был заражен ослепляющим зомби %s!'),\
	(94, '>> Player %s has stole ammo from player %s!', '>> Игрок %s украл патроны игрока %s!'),\
	(95, '>> %s legs have been broken by %s!', '>> Ноги игрока %s были сломаны игроком %s!'),\
	(96, '~y~Remove Weapons Field is %s', '~y~Поле отнимания оружия %s'),\
	(97, '~r~Weapons Removed', '~r~Оружие убрано'), \
	(98, '>> Player %s has been poisoned by %s!', '>> Игрок %s был отравлен игроком %s!'),\
	(99, '~r~Space starts damaging you', '~r~Пространство начинает разрывать вас'),\
	(100, '|: Random Question for %d points: %s', '|: Случайная викторина на %d очков: %s'),\
	(101, '>> %s was the first one answer the question (Answer : %s) and earns %d points!', '>> Игрок %s был первым, кто ответил на вопрос (Ответ: %s) и получил %d очков'),\
	(102, 'Next', 'Следующая'),\
	(103, '{d5d5c3}Achievements', '{d5d5c3}Достижения'),\
	(104, 'Nothing yet', 'Тут пока пусто'),\
	(105, '{d5d5c3}Name\t{d5d5c3}Description\n', '{d5d5c3}Название\t{d5d5c3}Описание\n'),\
	(106, 'RANDOM QUESTION: No one answered!', 'Случайная викторина: никто не ответил!'),\
	(107, '>> Lottery: Number will be drawn soon. Use /lottery to get your own number', '>> Лотерея: Номер скоро будет разыгран. Используйте /lottery и выберите ваш номер!'),\
	(108, '>> Lottery: Nobody won!{FF0000} Number: %d Jackpot: %d', '>> Лотерея: Никто не выграл! {FF0000} Номер: %d Джекпот: %d'),\
	(109, '>> Lottery: %s has won the lottery!{C659B6} Number: %d Jackpot: %d', '>> Лотерея: Игрок %s выграл лотерею! {C659B6} Номер: %d Джекпот: %d'),\
	(110, '>> The lottery hasnt started yet', '>> Лотерея еще не началась'),\
	(111, '>> You have already chosen your number!', '>> Вы уже выбрали свой номер!'),\
	(112, '>> Your number is %d', '>> Ваш номер - %d');\
"

#define PREDIFINED_LOCALIZATION_6 "INSERT IGNORE INTO localization (id, english, russian) VALUES \
	(113, '~~~~~~~~~~~~~~ %s ~~~~~~~~~~~~~~', '~~~~~~~~~~~~~~ %s ~~~~~~~~~~~~~~'),\
	(114, '>> Kills: %d - Killstreak: %d (best: %d)', '>> Убийств: %d - Убийств подряд: %d (Лучший результат: %d)'),\
	(115, '>> Wins: %d - Duel Wins: %d - Rank: %d', '>> Эвакуаций: %d - Duel Wins: %d - Rank: %d'),\
	(116, '>> Played: %d Hours - %d Minutes - %d Seconds', '>> Всего в игре: %d Час(а/ов) - %d Минут(а/ы) - %d Секунд(а/ы)'),\
	(117, '>> Gang: (ID %d)(Rank: %d) - {dfb7bc}Account ID: %d', '>> Банда: (ИД %d)(Ранг: %d) - {dfb7bc}ID Аккаунта: %d'),\
	(118, '>> Date: %02dD/%02dM/%dY - Session: MD_%s', '>> Дата: %02dD/%02dM/%dY - Сессия: MD_%s'),\
	(119, 'Coin(s)', 'Монет(а/ы)'),\
	(120, '>> %s has unlocked a New Achievement named{FFFFFF} %s +%d %s (/achievements)', '>> Игрок %s открыл новое достижение{FFFFFF} %s +%d %s (/achievements)'),\
	(121, '>> %s has achieved a %d killstreak!{FFFFFF} (+%d %s)', '>> Игрок %s достиг серии из %d убийств!{FFFFFF} (+%d %s)'),\
	(122, '>> %s earned %d %s for killing %s on {FFFFFF}%d killstreak!', '>> Игрок %s заработал %d %s за убийство игрока %s на{FFFFFF} серии из %d убийств!'),\
	(123, '>> Points: %d - Total: %d', '>> Очки: %d - Всего: %d'),\
	(124, '>> You have saved your stats!', '>> Вы сохранили свою статистику!'),\
	(125, 'Choose your language', 'Выберите свой язык'),\
	(126, 'English\nRussian', 'Английский\nРусский'),\
	(127, '>> Language set!', '>> Язык переключен!'),\
	(128, '[QUESTION]: %s asked a question:{FFFFFF} %s', '[ВОПРОС]: Игрок %s задал вопрос:{FFFFFF} %s'),\
	(129, '>> The player has closed private messages!', '>> Игрок закрыл личные сообщения!'),\
	(130, '>> Setting disabled!', '>> Настройка отключена!'),\
	(131, '>> Setting enabled!', '>> Настройка включена!'),\
	(132, 'Settings', 'Настройки'),\
	(133, 'Setting Name\tState\nBlock PMs\t%s\nDing On Hit\t%s\nBlock Duel Requests\t%s\n\"Ability Is Ready\" notification\t%s\nAuto-Login\t%s', 'Название\tСостояние\nБлокировать ЛС\t%s\nЗвук при попадании\t%s\nБлокировать дуэли\t%s\nУведомление \"Способность Готова\"\t%s\nАвто-Логин\t%s'),\
	(134, '{009900}[ YES ]', '{009900}[ ДА ]'),\
	(135, '{ff1a1a}[ NO ]', '{ff1a1a}[ НЕТ ]'),\
	(136, '~y~ABILITY~w~ IS~g~ READY!', '~y~СПОСОБНОСТЬ~g~ ГОТОВА!'),\
	(137, '>> Congratulations, {FF0000}you are banned!', '>> Поздравляем, {FF0000}вы заблокированы!'),\
	(138, 'Rules', 'Правила'),\
	(139, 'Help', 'Помощь'),\
	(140, '[REPORT] %s has reported %s(%d):{FFFFFF} %s', '[ЖАЛОБА] Игрок %s отправил жалобу на игрока %s(%d):{FFFFFF} %s'),\
	(141, 'Report sent!', 'Жалоба отправлена!'),\
	(142, 'Unknown command. Check /cmds', 'Неизвестная команда. Просмотрите /cmds'),\
	(143, '>> Voting is already underway!', '>> Голосование уже идёт!'),\
	(144, '[VOTEKICK] Player %s(%d) will be kicked [Reason: %s]{FFFFFF} (by %s)', '[ГОЛОСОВАНИЕ] Игрок %s(%d) будет кикнут [Причина: %s]{FFFFFF} (инициатор %s)'),\
	(145, '[VOTEKICK] Use /yes and /no for voting!', '[ГОЛОСОВАНИЕ] Используйте /yes и /no для голосования!'),\
	(146, '>> %s voted for a kick (%d / %d)', '>> Игрок %s проголосовал за кик (%d / %d)'),\
	(147, '>> %s did not vote for a kick (%d / %d)', '>> Игрок %s проголосовал против (%d / %d)');\
"

#define PREDIFINED_LOCALIZATION_7 "INSERT IGNORE INTO localization (id, english, russian) VALUES \
	(148, '[VOTEKICK] %s has been kicked', '[ГОЛОСОВАНИЕ] Игрок %s был кикнут'),\
	(149, '[VOTEKICK] Voting canceled', '[ГОЛОСОВАНИЕ] Отменено'),\
	(150, '*** %s has joined the server (ID %d) (Player %d) (IP %s)', '*** Игрок %s подключился к серверу (ID %d) (Игрок %d) (IP %s)'),\
	(151, '*** %s has left the server (%s) (%s)', '*** Игрок %s вышел с сервера (%s) (%s)'),\
	(152, '[ADMIN MESSAGE] %s send an admin message to %s(%d):{FFFFFF} %s', '[АДМИН-СООБШЕНИЕ] Администратор %s ответил игроку %s(%d):{FFFFFF} %s'),\
	(153, '[ADMIN MESSAGE]:{FFFFFF} %s', '[АДМИН-СООБШЕНИЕ]:{FFFFFF} %s'),\
	(154, '>> %s(%d) has been jailed by %s for 3 minutes [Reason: %s]', '>> Игрок %s(%d) был посажен в тюрьму администратором %s на 3 минуты [Причина: %s]'),\
	(155, '>> %s has been jailed for 3 minutes [Reason: %s]', '>> Игрок %s был посажен в тюрьму на 3 минуты [Причина: %s]'),\
	(156, '>> %s(%d) has been unjailed by %s', '>> Игрок %s(%d) был освобождён из тюрьмы администратором %s'),\
	(157, '>> %s has been unjailed', '>> Игрок %s был освобождён из тюрьмы'),\
	(158, '{d5d5c3}Weekly Activities', '{d5d5c3}Еженедельные задания'),\
	(159, 'Activities\nRewards', 'Задания\nНаграды'),\
	(160, '{d5d5c3}Name\t{d5d5c3}Description\t{d5d5c3}Total Points\n', '{d5d5c3}Название\t{d5d5c3}Описание\t{d5d5c3}Очков в общем\n'),\
	(161, '>> Chat cleared by %s', 'Чат был очищен администратором %s'),\
	(162, '>> Chat cleared by an administrator', 'Чат был очищен администратором'),\
	(163, '>> %s(%d) has been kicked by %s [Reason: %s]', '%s(%d) был кикнут администратором %s [Причина: %s]'),\
	(164, '>> %s has been kicked [Reason: %s]', '%s был кикнут [Причина: %s]'),\
	(165, '>> %s(%d) has been synced by %s', 'Игрок %s(%d) был синхронизирован администратором %s'),\
	(166, '>> %s has been synced', 'Игрок %s был синхронизирован'),\
	(167, '>> %s(%d) got a slap from %s [Reason: %s]', 'Игрок %s(%d) получил пощечину от %s [Причина: %s]'),\
	(168, '>> %s got a slap [Reason: %s]', 'Игрок %s получил пощечину [Причина: %s]'),\
	(169, '>> %s has changed %s(%d) team to zombie [Reason: %s]', 'Администратор %s сменил команду игрока %s(%d) на зомби [Причина: %s]'),\
	(170, '>> %s has changed team to zombie [Reason: %s]', 'Игрок %s сменил команду на зомби [Причина: %s]'),\
	(171, '~~~~~~~ MATCHES ~~~~~~~', '~~~~~~~ СОВПАДЕНИЯ ~~~~~~~'),\
	(172, '>> Nothing found', '>> Ничего не найдено'),\
	(173, '>> %s(%d) has been banned by %s [Reason: %s]', '>> Игрок %s(%d) был заблокирован администратором %s [Причина: %s]'),\
	(174, '>> %s has been banned [Reason: %s]', 'Игрок %s был заблокирован [Причина: %s]'),\
	(175, '>> You have been in afk too long, your team has been changed to zombies', '>> Вы находились в АФК слишком долго, ваша команда изменена на зомби'),\
	(176, '>> %s has been kicked [Reason: Exceeding the allowed ping limit]', '>> Игрок %s был кикнут [Причина: Превышение лимита допустимого пинга]'),\
	(177, '>> %s has been kicked [Reason: Exceeding the limit of being in AFK]', '>> Игрок %s был кикнут [Причина: Превышение лимита нахождения в АФК]');\
"

#define PREDIFINED_LOCALIZATION_8 "INSERT IGNORE INTO localization (id, english, russian) VALUES \
	(178, '>> Thank you for your assistance, you have been given additional points for helping the administration', '>> Спасибо за помощь, вам начислены дополнительные очки'),\
	(179, '>> Wrong banned? Appeal at %s', '>> Хотите оспорить бан? Подайте заявку здесь: %s'),\
	(180, '>> Create a screenshot of your ban by pressing F8 | (Documents/GTA San Andreas User Files/SAMP/screens)', '>> Создайте скриншот нажав F8 и перейдите в Documents/GTA San Andreas User Files/SAMP/screens'),\
	(181, '>> By %s - {FF0000}Reason: %s', '>> Администратор: %s - {FF0000}Причина: %s'),\
	(182, '>> At: %02dD/%02dM/%04dY', '>> Дата: %02dD/%02dM/%04dY'),\
	(183, '>> %s has attempted to join the server whilst serving a ban', '>> Игрок %s пытался подключится, но был обнаружен забаненым'),\
	(184, '>> %s has attempted to join the server whilst serving a temp ban', 'Игрок %s пытался подключится, но был обнаружен временно забаненым'),\
	(185, '>> Account not found in ban list', '>> Аккаунт не найден в списке блокировок'),\
	(186, '>> %s has been unbanned by %s', '>> Аккаунт %s был разблокирован администратором %s'),\
	(187, '>> %s(%d) has been banned by %s for %d hour(s) [Reason: %s]', '>> Игрок %s(%d) был заблокирован администратором %s на %d час(а/ов) [Причина: %s]'),\
	(188, '>> %s has been banned for %d hour(s) [Reason: %s]', 'Игрок %s был заблокирован на %d час(а/ов) [Причина: %s]'),\
	(189, '>> %s has started to spectating for %s(%d)', 'Администратор %s начал слежку за %s(%d)'),\
	(190, '>> %s has stopped spectating for %s(%d)', 'Администратор %s прекратил слежку за %s(%d)'),\
	(191, '>> %s has changed time to %d', 'Администратор %s изменил время на %d'),\
	(192, '>> %s has changed weather to %d', 'Администратор %s изменил погоду на %d'),\
	(193, '>> %s(%d) has been warned by %s (%d / 3) [Reason: %s]', '>> %s(%d) получил предупреждение от администратора %s (%d / 3) [Причина: %s]'),\
	(194, '>> %s has been warned (%d / 3) [Reason: %s]', '>> %s получил предупреждение (%d / 3) [Причина: %s]'),\
	(195, 'WARNING', 'ПРЕДУПРЕЖДЕНИЕ'),\
	(196, '>> %s has been kicked [Reason: Maximum number of warnings reached]', '>> Игрок %s был кикнут [Причина: Достигнуто максимальное количество предупреждений]'),\
	(197, '>> %s(%d) has been unwarned by %s', '>> Предупреждение с игрока %s(%d) было снято администратором %s'),\
	(198, '>> The player does not have warns!', '>> У игрока нету предупреждений'),\
	(199, '>> %s(%d) has been muted for %d minutes by %s [Reason: %s]', '>> %s(%d) получил мут на %d минут(а/ы) от администратора %s [Причина: %s]'),\
	(200, '>> %s has been muted for %d minutes [Reason: %s]', '>> %s получил мут на %d минут(а/ы) [Причина: %s]'),\
	(201, '>> %s(%d) has been unmuted by %s', '>> Игрок %s(%d) получил размут от администратора %s'),\
	(202, '>> %s has been unmuted', '>> Игрок %s получил размут'),\
	(203, '>> You are muted, %d seconds left', '>> У вас мут, осталось подождать %d секунд');\
"

#define PREDIFINED_LOCALIZATION_9 "INSERT IGNORE INTO localization (id, english, russian) VALUES \
	(204, '>> This CMD has already been used!', '>> Эта команда уже была использована!'),\
	(205, 'You need to wait', 'Подождите'),\
	(206, '>> %s has been banned by %s [Reason: %s] (OFFLINE)', '>> Аккаунт %s был заблокирован администратором %s [Причина: %s] (ОФФЛАЙН)'),\
	(207, '>> Account not found!', '>> Аккаунт не найден!'),\
	(208, '>> %s has been banned by %s for %d hour(s) [Reason: %s] (OFFLINE)', '>> Аккаунт %s был заблокирован администратором %s на %d час(а/ов) [Причина: %s] (ОФФЛАЙН)'),\
	(209, '>> Name: %s - IP: %s', '>> Ник: %s - IP: %s'),\
	(210, '>> Health: %.2f% - Armour: %.2f', '>> Здоровье: %.2f - Броня: %.2f'),\
	(211, '>> Points: %d / %d - Money: %d', '>> Очки: %d / %d - Деньги: %d'),\
	(212, '>> Team: Zombie - Class: %s', '>> Команда: Зомби - Класс: %s'),\
	(213, '>> Team: Human - Class: %s', '>> Команда: Люди - Класс: %s'),\
	(214, '>> Weapon: %s - Ammo: %d', '>> Оружие: %s - Патроны: %d'),\
	(215, '>> Packets lost: %.2f', '>> Потерянно сетевых пакетов: %.2f'),\
	(216, '>> This nickname does not fit, come up with another one', '>> Этот ник не подходит, попробуйте другой'),\
	(217, '>> This nickname is already taken, come up with another one', '>> Этот ник уже занят, попробуйте другой'),\
	(218, '>> Your nickname has successfully changed to %s, the fee for changing is %d', '>> Ваш ник успешно изменён на %s, плата за смену составила %d'),\
	(219, '[ADMIN]: %s is now known as %s!', '[АДМИН]: Игрок %s сменил ник на %s!'),\
	(220, '>> IP %s has been banned by %s [Reason: %s]', '>> IP %s был заблокирован администратором %s [Причина: %s]'),\
	(221, '>> This IP is already banned', '>> Этот IP уже заблокирован'),\
	(222, '>> This IP is not banned', '>> Этот IP не заблокирован'),\
	(223, '>> IP %s has been unbanned by %s', '>> IP %s был разблокирован администратором %s'),\
	(224, '>> %s(%d) has been frozen by %s [Reason: %s]', '>> Игрок %s(%d) был заморожен администратором %s [Причина: %s]'),\
	(225, '>> %s has been frozen [Reason: %s]', '>> Игрок %s был заморожен [Причина: %s]'),\
	(226, '>> %s(%d) has been unfrozen by %s', '>> Игрок %s(%d) был разморожен администратором %s'),\
	(227, '>> %s has been unfrozen', '>> Игрок %s был разморожен'),\
	(228, 'Information', 'Информация'),\
	(229, 'Player\tBy\tReason\tDate\n', 'Игрок\tКем\tПричина\tДата\n'),\
	(230, 'New\tOld\tIP\tDate\n', 'Новый\tСтарый\tIP\tДата\n'),\
	(231, 'IP\tBy\tReason\tDate\n', 'IP\tКем\tПричина\tДата\n'),\
	(232, '[ADMIN]: %s has set admin rank of %s to %d!', '[АДМИН]: Администратор %s установил админ ранг игрока %s на %d уровень!'),\
	(233, '~y~REQUEST FOR A DUEL', '~y~ЗАПРОС НА ДУЭЛЬ'),\
	(234, '>> You have accepted the duel!', '>> Вы приняли дуэль!'),\
	(235, '>> The player accepted your request!', '>> Игрок принял ваш запрос на дуэль!'),\
	(236, '>> You have denied the duel!', '>> Вы отклонили дуэль!'),\
	(237, '>> The player denied your request!', '>> Игрок отклонил ваш запрос на дуэль!'),\
	(238, '>> Not enough points from one of sides', '>> Недостаточно очков с одной из сторон'),\
	(239, '>> You cannot send a request to this person', '>> Вы не можете запросить дуэль с этим человеком');\
"

#define PREDIFINED_LOCALIZATION_10 "INSERT IGNORE INTO localization (id, english, russian) VALUES \
	(240, ' (Armour: %d)', ' (Броня: %d)'),\
	(241, ' (Points: %d)', ' (Очки: %d)'),\
	(242, '>> %s is inviting you to duel with weapon: %s (ID %d)%s%s', '>> Игрок %s приглашает вас на дуэль с оружием %s (ID %d)%s%s'),\
	(243, '>> Type /y to agree and /n to deny', '>> Введите /y для согласия и /n для отказа'),\
	(244, '>> You sent a duel request to %s!', '>> Вам запрос на дуэль отправлен игроку %s'),\
	(245, '>> %s has started a duel with %s (%s) (ID %d)%s%s', '>> Игрок %s начал дуэль с игроком %s (%s) (ID %d)%s%s'),\
	(246, '>> You are not in duel!', '>> Вы не в дуэле!'),\
	(247, '[DUEL]: %s has won the duel against %s!%s', '[ДУЭЛЬ]: Игрок %s выграл дуэль против игрока %s!%s'),\
	(248, '>> %s paid %d points to %s. With taxes: %d', '>> Игрок %s передал %d очков игроку %s. Итоговое значение с налогом: %d'),\
	(249, '[%s] %s by {FFFFFF}%s (Members: %d) (Control over: %s)', '[%s] %s {FFFFFF}(Руководитель %s) (Участники: %d) (Контроль над: %s)'),\
	(250, '>> You are blacklisted from this gang [Reason: %s]', '>> Вы в чёрном списке этой банды [Причина: %s]'),\
	(251, '>> You have to leave your gang first! (/gang leave)', '>> Вы должны покинуть вашу текущую банду! (/gang leave)'),\
	(252, '>> This gang is not currently accepting requests!', '>> Эта банда пока не принимает заявки!'),\
	(253, '>> %s sent a request to join your gang!', '>> Игрок %s прислал заявку на вступление в вашу банду!'),\
	(254, '>> Use /gang accept %d to accept!', '>> Используйте /gang accept %d для одобрения заявки!'),\
	(255, '>> You have sent a request to join %s (ID %d)', '>> Вы отправили заявку на вступление в %s (ID %d)'),\
	(256, '>> Insufficient rights to use this command!', '>> Недостаточно прав для использования команды!'),\
	(257, '>> %s has been accepted to your gang by %s!', '>> Игрок %s был принят в вашу банду игроком %s!'),\
	(258, '>> Your gang request has been accepted!', '>> Ваша заявка в банду была одобрена!'),\
	(259, '>> Put ! at the beginning of the message to send a message to the gang!', 'Поставтье ! в начале сообщения чтобы отправить сообщение в банду!'),\
	(260, '[%s] %s by {FFFFFF}%s (Members: %d)', '[%s] %s {FFFFFF}(Руководитель %s) (Участники: %d)'),\
	(261, '>> All slots are occupied, it is impossible to create a gang', '>> Все слоты заняты, создать банду невозможно'),\
	(262, '[ADMIN] %s has created a new gang %s (ID %d)', '[АДМИН] Игрок %s создал новую банду %s (ID %d)'),\
	(263, 'Peon,Policeman,Scout,Agent,Director,Boss', 'Новичек,Полицейский,Скаут,Агент,Директор,Босс'),\
	(264, '{FFFFFF}Set or Accessory\t{FFFFFF}Spiral knots (%d)\t{FFFFFF}Coins (%d)\n', '{FFFFFF}Набор или Аксессуар\t{FFFFFF}Спиральные узлы (%d)\t{FFFFFF}Монеты (%d)\n'),\
	(265, 'Are you sure want to buy %s for %d Spiral knots and %d Coins?', 'Вы точно хотите купить %s за %d Спиральных узлов и %d Монет(у)'),\
	(266, 'Completed', 'Выполнено'),\
	(267, 'Yes', 'Да'),\
	(268, '{FFFFFF}Tagret\t{FFFFFF}Reputation\t{FFFFFF}Progress\n', '{FFFFFF}Цель\t{FFFFFF}Репутация\t{FFFFFF}Прогресс\n'),\
	(269, '{FFFFFF}Not enough currency to purchase', '{FFFFFF}Недостаточно валюты для покупки'),\
	(270, '>> You bought %s! (/clothes)', '>> Вы купили %s! (/clothes)');\
"

#define PREDIFINED_LOCALIZATION_11 "INSERT IGNORE INTO localization (id, english, russian) VALUES \
	(271, '>> %s has captured the map with %d score!', '>> Банда %s захватила карту со значением в %d очков!'),\
	(272, '>> %s set a new record of %d score!', '>> Банда %s установила новый рекорд в размере %d очков!'),\
	(273, '>> There are not enough slots in the gang to apply!', '>> В этой банде недостаточно слотов для подачи заявки!'),\
	(274, '>> Your rank does not allow you to apply to this gang!', '>> Ваш ранг не позволяет вам подать заявку в эту банду!'),\
	(275, 'SPAWN PROTECTION', 'ЗАЩИЩЕН АНТИ-СПАВН УБИЙСТВОМ'),\
	(276, 'INSUFFICIENT CALIBER', 'МАЛЫЙ КАЛИБР'),\
	(277, 'Option\tState\nState\t%s\nName\t%s\nTag\t%s\nRank is needed to send request\t%d\nRank that can use /gang settings\t%d\n', 'Настройка\tЗначение\nСостояние\t%s\nНазвание\t%s\nТэг\t%s\n\nРанг для подачи заявки\t%d\nРанг для использования /gang settings\t%d\n'),\
	(278, 'Rank that can use /gang ban\t%d\nRank that can use /gang promote/demote\t%d\n', 'Ранг для использования /gang ban\t%d\nРанг для использования /gang promote/demote\t%d\n'),\
	(279, 'Rank that can use /gang pay\t%d\nRank that can use /gang accept\t%d\n', 'Ранг для использования /gang pay\t%d\nРанг для использования /gang accept\t%d'),\
	(280, 'Open', 'Открыто'),\
	(281, 'Closed', 'Закрыто'),\
	(282, '>> %s supposedly uses Teleport Hack', '>> Игрок %s возможно Телепортируется'),\
	(283, 'Type the rank you think is appropriate for this setting\nValid rank values from 1 to 6', 'Введите ранг, который считаете нужным для этой настройки\nДопустимые значения с 1 до 6'),\
	(284, 'Type a new name for the gang', 'Введите новое имя банды'),\
	(285, 'Type a new gang tag', 'Введите новый тэг банды'),\
	(286, 'Type new rank for gang applications, min. 0 and max. 100', 'Введите новый ранг для подачи заявок, мин. 0 и макс. 100'),\
	(287, '---------- %s (Pot %d) (Members %d / %d) ----------', '---------- %s (Казна %d) (Участники %d / %d) ----------'),\
	(288, '(Rank %d) >> %s (ID %d)', '(Ранг %d) >> %s (ИД %d)'),\
	(289, 'Member\tRank\tLast Online\n', 'Участник\tРанг\tПоследний раз в сети\n'),\
	(290, 'Admin\tLevel\tLast Online\n', 'Администратор\tУровень\tПоследний раз в сети\n'),\
	(291, '>> %s has been kicked [Reason: Auth time exceeded]', '>> Игрок %s был кикнут [Причина: Превышение времени авторизации]'),\
	(292, '>> %s has been kicked for 3 failed login attempts!', '>> Игрок %s был кикнут за 3 неверные попытки авторизации!'),\
	(293, '>> It is impossible to leave the gang due to the number of members, or you are the founder!', '>> Невозможно покинуть банду из за малого кол-ва участников, либо вы основатель банды!'),\
	(294, '>> You left the gang', '>> Вы покинули банду'),\
	(295, '>> %s proposed war to your gang', '>> Банда %s предложила войну вашей банде'),\
	(296, '>> Compete with another gang to collect score per round, the one with the most wins!', '>> Соревнуйтесь с другой бандой в наборе очков за раунд, выграет та, у которой будет больше!'),\
	(297, '>> On the captured map you will receive M4, Deagle, Armor and the opportunity to replenish the gang pot for actions!', '>> На захваченой карте вы получите M4, Дигл, Броню и возможность пополнять казну клана за действия!'),\
	(298, '>> Use /gang war %d to accept the war', '>> Используйте /gang war %d чтобы принять запрос на войну'),\
	(299, '>> %s started a war against %s!', '>> Банда %s начала войну против банды %s!'),\
	(300, '>> %s ended a war against %s', '>> Банда %s отступилась от войны с бандой %s!'),\
	(301, '>> %s created an alliance with %s!', '>> Банда %s создала альянс с бандой %s!'),\
	(302, '>> %s broke off alliance with %s!', '>> Банда %s разорвала альянс с бандой %s!'),\
	(303, '>> %s proposed alliance to your gang', '>> Банда %s предложила альянс вашей банде'),\
	(304, '>> Allied gangs have a unified chat', '>> У союзных банд общий чат'),\
	(305, '>> Use /gang alliance %d to accept the alliance', '>> Используйте /gang alliance %d чтобы принять альянс');\
"