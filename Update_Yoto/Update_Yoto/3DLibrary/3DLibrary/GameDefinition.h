#ifndef GAMEDEFINITION_H_
#define GAMEDEFINITION_H_

#include <string>

//!< テクスチャリストのキーの例、使用者が各自で追加すること
const std::string texture_name = "ex.Update_Yoto";

// タイトルシーン
const std::string title_base = "TitleBase";
const std::string title_button = "TitleButton";
const std::string menu = "Menu";


// トランジションシーン
const std::string transition				= "Transition";// トランジションシーン


// 背景
const std::string background				= "BackGround";	// 背景
const std::string ground					= "Ground";		// 地面


// キャラクター
const std::string r_perry_anime_hold		= "RightPerryAnime";	// 右側のペリーのアニメーション（仮）

	// 今のプレイヤーの描画はこれ
const std::string chara_anime				= "CharaAnime";	// プレイヤーのアニメーション（仮）
const std::string walk_anime				= "WalkAnime";	// プレイヤーの歩くアニメーション（仮）
const std::string walk_to_standby_anime		= "WalkToStanadbyAnime";	// プレイヤーが歩いてきて構えるまでのアニメーション（仮）
const std::string standby_anime				= "StandbyAnime";		// プレイヤーの構えている状態のアニメーション（仮）

const std::string drawer_tex				= "Drawer";		// 絵描き
	// ペリーの待っているときのアニメーション
const std::string perry_wait_anime			= "PerryWait";		// ペリー：待つアニメーション
const std::string perry_die_anime			= "PerryDie";		// ペリー：死ぬアニメーション

const std::string hermit_tex				= "Hermit";		// 仙人
const std::string sinsengumi_tex			= "Sinsengumi";	// 新選組
const std::string fox_tex					= "Fox";		// 狐


// UI
const std::string calloutui_tex				= "CalloutUI";	// 「押せ！」ボタン

const std::string hpui_tex					= "HpUI";		// HP

	// 右側用
const std::string r_cutin_player_tex		= "R_CutIn_Player";
const std::string r_cutin_drawer_tex		= "R_CutIn_Drawer";
const std::string r_cutin_perry_tex			= "R_CutIn_Perry";
const std::string r_cutin_hermit_tex		= "R_CutIn_Hermit";
const std::string r_cutin_sinsengumi_tex	= "R_CutIn_Sinsengumi";
const std::string r_cutin_fox_tex			= "R_CutIn_fox";
	// 左側用
const std::string l_cutin_player_tex		= "L_CutIn_Player";
const std::string l_cutin_drawer_tex		= "L_CutIn_Drawer";
const std::string l_cutin_perry_tex			= "L_CutIn_Perry";
const std::string l_cutin_hermit_tex		= "L_CutIn_Hermit";
const std::string l_cutin_sinsengumi_tex	= "L_CutIn_Sinsengumi";
const std::string l_cutin_fox_tex			= "L_CutIn_fox";

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