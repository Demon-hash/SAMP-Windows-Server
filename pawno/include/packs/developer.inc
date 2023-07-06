#if defined _developer_pack_included
	#endinput
#endif
#define _developer_pack_included

#define DEBUG_MODE

#if defined SQL_HOST
	#undef SQL_HOST
#endif

#if defined SQL_USER
	#undef SQL_USER
#endif

#if defined SQL_PASS
	#undef SQL_PASS
#endif

#if defined SQL_DB
	#undef SQL_DB
#endif


#if defined SQL_LOG_LEVEL
	#undef SQL_LOG_LEVEL
#endif

#define SQL_HOST "localhost"
#define SQL_USER "root"
#define SQL_PASS ""
#define SQL_DB "zamp"
#define SQL_LOG_LEVEL ALL