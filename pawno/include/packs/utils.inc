#if defined _utils_pack_included
	#endinput
#endif
#define _utils_pack_included

#define getBySlot(%0,%1) (%0) >> (1 * (%1)) & 1
#define setBySlot(%0,%1,%2) (%0) = ((%0) & (~0 ^ (1 << (1 * (%1))))) | ((%2) << (1 * (%1)))