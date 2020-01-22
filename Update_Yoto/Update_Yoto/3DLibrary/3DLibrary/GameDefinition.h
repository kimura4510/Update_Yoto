#ifndef GAMEDEFINITION_H_
#define GAMEDEFINITION_H_

#include <string>

//!< テクスチャリストのキーの例、使用者が各自で追加すること
const std::string texture_name = "ex.Update_Yoto";

// タイトルシーン
const std::string title_base				= "TitleBase";
const std::string title_button				= "TitleButton";
const std::string menu						= "Menu";


// トランジションシーン
const std::string transition				= "Transition";// トランジションシーン


// 背景
const std::string background				= "BackGround";	// 背景
const std::string ground					= "Ground";		// 地面


// キャラクター
const std::string r_perry_anime_hold		= "RightPerryAnime";	// 右側のペリーのアニメーション（仮）

	// プレイヤー
const std::string walk_anime				= "WalkAnime";				// プレイヤー：歩くアニメーション
const std::string walk_wait_anime			= "WalkToStanadbyAnime";	// プレイヤー：歩いてきて構えるまでのアニメーション
const std::string wait_anime				= "StandbyAnime";			// プレイヤー：構えている状態のアニメーション
const std::string attack1_anime				= "Attack1";				// プレイヤー：1回目の攻撃アニメーション
const std::string player_die_anime			= "PlayerDie";				// プレイヤー：死ぬアニメーション
	// 絵描き
const std::string drawer_wait_anime			= "DrawerWait";		// 絵描き：待つアニメーション
const std::string drawer_attack1_anime		= "DrawerAttack1";	// 絵描き：1回目の攻撃アニメーション
const std::string drawer_die_anime			= "DrawerDie";		// 絵描き：死ぬアニメーション
	// ペリー
const std::string perry_wait_anime			= "PerryWait";		// ペリー：待つアニメーション
const std::string perry_attack1_anime		= "PerryAttack1";		// ペリー：1回目の攻撃アニメーション
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
	Gameover
};

#endif