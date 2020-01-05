#ifndef GAMEDEFINITION_H_
#define GAMEDEFINITION_H_

#include <string>

//!< テクスチャリストのキーの例、使用者が各自で追加すること
const std::string texture_name = "ex.Update_Yoto";

const std::string background		= "BackGround";

const std::string chara_anime		= "CharaAnime";

const std::string player_tex		= "Player";

const std::string drawer_tex		= "Drawer";
const std::string perry_tex			= "Perry";
const std::string hermit_tex		= "Hermit";
const std::string sinsengumi_tex	= "Sinsengumi";
const std::string fox_tex			= "Fox";

const std::string calloutui_tex		= "CalloutUI";
const std::string hpui_tex			= "HpUI";

enum class TextureCategory : int
{
	TitleCategory,
	GameCategory,
	HelpCategory,
	ClearCategory,
	GameoverCategory,
	MaxTextureCategory,
};

enum class TitleCategoryTextureList : int
{
	Background,
	MaxTitleTex
};

enum class GameCategoryTextureList : int
{
	Background,
	Character,
	MaxGameTex
};

enum class HelpCategoryTextureList : int
{
	Background,
	MaxHelpTex
};

enum class ClearCategoryTextureList : int
{
	Background,
	MaxClearTex
};

enum class GameoverCategoryTextureList : int
{
	Background,
	MaxGameoverTex
};

enum class CameraState
{
	Battle,
	WinningPlayer,
	LosingPlayer,
	GameClear,
};

#endif