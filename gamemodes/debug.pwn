#include <a_samp>

stock hash(const text[]) {
	new i, ret;
	for( i = 0; i < strlen(text); i++ ) {
	    ret = ret * 31 + text[i];
    	ret |= 0;
	}
	
	return ret;
}

stock toUpper(const text[]) {
	new str[32];
	for( new i = 0; i < strlen(text); i++ ) {
    	str[i] = toupper(text[i]);
    }
    return str;
}

main(){

	new values[][] = {
	    "help",
        "accept",
		"applications",
		"alliance",
		"list",
		"leave",
	 	"members",
	 	"pay",
	 	"deposit",
	 	"demote",
	 	"delete",
	  	"info",
	   	"join",
	   	"promote",
		"fire",
		"ban",
		"create",
		"settings",
		"warn",
		"close",
		"unban",
		"terminate",
		"war"
 	};

	printf("enum GANG_COMMANDS {");
	printf("GANG_COMMAND_NONE = 0,");
	for( new i = 0; i < sizeof(values); i++ ) {
	    printf("GANG_COMMAND_%s = %d,", toUpper(values[i]), hash(values[i]));
	}
	printf("}");
}
