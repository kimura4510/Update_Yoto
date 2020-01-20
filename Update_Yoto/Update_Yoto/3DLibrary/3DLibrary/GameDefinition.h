#ifndef GAMEDEFINITION_H_
#define GAMEDEFINITION_H_

#include <string>

//!< �e�N�X�`�����X�g�̃L�[�̗�A�g�p�҂��e���Œǉ����邱��
const std::string texture_name = "ex.Update_Yoto";

// �^�C�g���V�[��
const std::string title_base = "TitleBase";
const std::string title_button = "TitleButton";
const std::string menu = "Menu";


// �g�����W�V�����V�[��
const std::string transition				= "Transition";// �g�����W�V�����V�[��


// �w�i
const std::string background				= "BackGround";	// �w�i
const std::string ground					= "Ground";		// �n��


// �L�����N�^�[
const std::string r_perry_anime_hold		= "RightPerryAnime";	// �E���̃y���[�̃A�j���[�V�����i���j

	// ���̃v���C���[�̕`��͂���
const std::string chara_anime				= "CharaAnime";	// �v���C���[�̃A�j���[�V�����i���j
const std::string walk_anime				= "WalkAnime";	// �v���C���[�̕����A�j���[�V�����i���j
const std::string walk_to_standby_anime		= "WalkToStanadbyAnime";	// �v���C���[�������Ă��č\����܂ł̃A�j���[�V�����i���j
const std::string standby_anime				= "StandbyAnime";		// �v���C���[�̍\���Ă����Ԃ̃A�j���[�V�����i���j

const std::string drawer_tex				= "Drawer";		// �G�`��
	// �y���[�̑҂��Ă���Ƃ��̃A�j���[�V����
const std::string perry_wait_anime			= "PerryWait";		// �y���[�F�҂A�j���[�V����
const std::string perry_die_anime			= "PerryDie";		// �y���[�F���ʃA�j���[�V����

const std::string hermit_tex				= "Hermit";		// ��l
const std::string sinsengumi_tex			= "Sinsengumi";	// �V�I�g
const std::string fox_tex					= "Fox";		// ��


// UI
const std::string calloutui_tex				= "CalloutUI";	// �u�����I�v�{�^��

const std::string hpui_tex					= "HpUI";		// HP

	// �E���p
const std::string r_cutin_player_tex		= "R_CutIn_Player";
const std::string r_cutin_drawer_tex		= "R_CutIn_Drawer";
const std::string r_cutin_perry_tex			= "R_CutIn_Perry";
const std::string r_cutin_hermit_tex		= "R_CutIn_Hermit";
const std::string r_cutin_sinsengumi_tex	= "R_CutIn_Sinsengumi";
const std::string r_cutin_fox_tex			= "R_CutIn_fox";
	// �����p
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