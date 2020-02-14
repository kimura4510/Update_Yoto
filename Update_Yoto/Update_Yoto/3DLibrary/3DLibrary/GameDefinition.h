#ifndef GAMEDEFINITION_H_

#define GAMEDEFINITION_H_

#include <string>

//!< テクスチャリストのキーの例、使用者が各自で追加すること
const std::string texture_name = "ex.Update_Yoto";

// タイトルシーン
const std::string title_base				= "TitleBase";
const std::string title_button				= "TitleButton";
const std::string menu						= "Menu";


// ヘルプシーン
const std::string help1						= "Help1";
const std::string help2						= "Help2";
const std::string help3						= "Help3";
const std::string help4						= "Help4";
const std::string help_base					= "HelpBase";


// トランジションシーン
const std::string transition				= "Transition";// トランジションシーン


// 背景
const std::string background				= "BackGround";	// 背景
const std::string ground					= "Ground";		// 地面


// キャラクター
	// プレイヤー
const std::string player_walk_anime				= "P_Walk";				// プレイヤー：歩くアニメーション
const std::string player_walk_wait_anime		= "P_WalkWait";	// プレイヤー：歩いてきて構えるまでのアニメーション
const std::string player_wait_anime				= "P_WaitAnime";			// プレイヤー：構えている状態のアニメーション
const std::string player_attack_01_anime		= "P_Attack01";				// プレイヤー：1回目の攻撃アニメーション
const std::string player_r_attack_02_anime		= "P_R_Attack02";
const std::string player_l_attack_02_anime		= "P_L_Attack02";
const std::string player_defence_01_anime		= "P_Defence01";
const std::string player_r_defence_02_anime		= "P_R_Defence02";
const std::string player_l_defence_02_anime		= "P_L_Defence02";
const std::string player_r_attack_cross_anime	= "P_R_AttackCross";
const std::string player_l_attack_cross_anime	= "P_L_AttackCross";
const std::string player_r_defence_cross_anime	= "P_R_DefenceCross";
const std::string player_l_defence_cross_anime	= "P_L_DefenceCross";
const std::string player_r_frick_anime			= "P_R_Frick";
const std::string player_l_frick_anime			= "P_L_Frick";
const std::string player_r_kill_anime			= "P_R_Kill";
const std::string player_l_kill_anime			= "P_L_Kill";
const std::string player_r_kill_walk_anime		= "P_R_KillWalk";
const std::string player_l_kill_walk_anime		= "P_L_KillWalk";
const std::string player_r_back_anime			= "P_R_Back";
const std::string player_l_back_anime			= "P_L_Back";
const std::string player_r_death_anime			= "P_R_Death";
const std::string player_l_death_anime			= "P_L_Death";
	// 絵描き
const std::string drawer_wait_anime				= "D_WaitAnime";			
const std::string drawer_attack_01_anime		= "D_Attack01";		
const std::string drawer_r_attack_02_anime		= "D_R_Attack02";
const std::string drawer_l_attack_02_anime		= "D_L_Attack02";
const std::string drawer_defence_01_anime		= "D_Defence01";
const std::string drawer_r_defence_02_anime		= "D_R_Defence02";
const std::string drawer_l_defence_02_anime		= "D_L_Defence02";
const std::string drawer_r_attack_cross_anime	= "D_R_AttackCross";
const std::string drawer_l_attack_cross_anime	= "D_L_AttackCross";
const std::string drawer_r_defence_cross_anime	= "D_R_DefenceCross";
const std::string drawer_l_defence_cross_anime	= "D_L_DefenceCross";
const std::string drawer_r_frick_anime			= "D_R_Frick";
const std::string drawer_l_frick_anime			= "D_L_Frick";
const std::string drawer_r_kill_anime			= "D_R_Kill";
const std::string drawer_l_kill_anime			= "D_L_Kill";
const std::string drawer_r_kill_stand_anime		= "D_R_KillStand";
const std::string drawer_l_kill_stand_anime		= "D_L_KillStand";
const std::string drawer_r_back_anime			= "D_R_Back";
const std::string drawer_l_back_anime			= "D_L_Back";
const std::string drawer_r_death_anime			= "D_R_Death";
const std::string drawer_l_death_anime			= "D_L_Death";
	// ペリー			
const std::string perry_wait_anime				= "Pe_WaitAnime";		
const std::string perry_attack_01_anime			= "Pe_Attack01";	
const std::string perry_r_attack_02_anime		= "Pe_R_Attack02";
const std::string perry_l_attack_02_anime		= "Pe_L_Attack02";
const std::string perry_defence_01_anime		= "Pe_Defence01";
const std::string perry_r_defence_02_anime		= "Pe_R_Defence02";
const std::string perry_l_defence_02_anime		= "Pe_L_Defence02";
const std::string perry_r_attack_cross_anime	= "Pe_R_AttackCross";
const std::string perry_l_attack_cross_anime	= "Pe_L_AttackCross";
const std::string perry_r_defence_cross_anime	= "Pe_R_DefenceCross";
const std::string perry_l_defence_cross_anime	= "Pe_L_DefenceCross";
const std::string perry_r_frick_anime			= "Pe_R_Frick";
const std::string perry_l_frick_anime			= "Pe_L_Frick";
const std::string perry_r_kill_anime			= "Pe_R_Kill";
const std::string perry_l_kill_anime			= "Pe_L_Kill";
const std::string perry_r_kill_stand_anime		= "Pe_R_KillStand";
const std::string perry_l_kill_stand_anime		= "Pe_L_KillStand";
const std::string perry_r_back_anime			= "Pe_R_Back";
const std::string perry_l_back_anime			= "Pe_L_Back";
const std::string perry_r_death_anime			= "Pe_R_Death";
const std::string perry_l_death_anime			= "Pe_L_Death";
	// 仙人
const std::string hermit_tex				= "Hermit";
	// 新選組
const std::string sinsengumi_tex			= "Sinsengumi";
	// 狐
const std::string fox_tex					= "Fox";


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