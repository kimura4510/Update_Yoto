#ifndef GAMEDEFINITION_H_
#define GAMEDEFINITION_H_

#include <string>

//!< テクスチャリストのキーの例、使用者が各自で追加すること
const std::string texture_name = "ex.Update_Yoto";

// トランジションシーン
const std::string transition				= "Transition";// トランジションシーン

// 背景
const std::string background				= "BackGround";	// 背景
const std::string ground					= "Ground";		// 地面

// キャラクター
const std::string chara_anime				= "CharaAnime";	// プレイヤーのアニメーション

const std::string player_tex				= "Player";		//	プレイヤー

const std::string drawer_tex				= "Drawer";		// 絵描き
const std::string perry_tex					= "Perry";		// ペリー
const std::string hermit_tex				= "Hermit";		// 仙人
const std::string sinsengumi_tex			= "Sinsengumi";	// 新選組
const std::string fox_tex					= "Fox";		// 狐

// UI
const std::string calloutui_tex				= "CalloutUI";	// 「押せ！」ボタン

const std::string hpui_tex					= "HpUI";		// HP

	// 右側用
const std::string r_cutin_tex				= "R_CutIn";
	// 左側用
const std::string l_cutin_tex				= "L_CutIn";

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