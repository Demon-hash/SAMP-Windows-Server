#if defined _textures_pack_included
	#endinput
#endif
#define _textures_pack_included

#define MAX_SERVER_TEXTURES 6

enum {
	TIMELEFT_TEXTURE_ID,
	INFECTED_TEXTURE_ID,
	UNTILEVAC_RECTANGLE_TEXTURE_ID,
	UNTILEVAC_TEXT_TEXTURE_ID,
	ALIVE_INFO_TEXTURE_ID,
	POINTS_TEXTURE_ID,
};

enum TEXTURES_DATA {
	Text:timeLeftTexture,
	Text:infectedTexture,
	Text:untillEvacRectangleTexture,
	Text:untilEvacTextTexture[MAX_PLAYERS],
	Text:aliveInfoTexture[MAX_PLAYERS],
	Text:pointsTexture[MAX_PLAYERS],
};

enum TEXTURES_CONFIG_DATA {
	Float:svTxCfgTexturePosition[2],
	Float:svTxCfgTextureLetterSize[2],
	Float:svTxCfgTextureTextSize[2],
	svTxCfgTextureDefaultValue[32],
	svTxCfgTextureUpdateValue,
	svTxCfgTextureBackgroundColor,
	svTxCfgTextureFont,
	svTxCfgTextureColor,
	svTxCfgTextureDrawColor,
	svTxCfgTextureOutline,
	svTxCfgTextureProportional,
	svTxCfgTextureShadow,
	svTxCfgTextureUseBox,
	svTxCfgTextureBoxColor,
	svTxCfgTextureAlignment,
};