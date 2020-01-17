#ifndef GAMEDEFINITION_H_
#define GAMEDEFINITION_H_

#include <string>

//!< �e�N�X�`�����X�g�̃L�[�̗�A�g�p�҂��e���Œǉ����邱��
const std::string texture_name = "ex.Update_Yoto";

// �g�����W�V�����V�[��
const std::string transition				= "Transition";// �g�����W�V�����V�[��

// �w�i
const std::string background				= "BackGround";	// �w�i
const std::string ground					= "Ground";		// �n��

// �L�����N�^�[
const std::string chara_anime				= "CharaAnime";	// �v���C���[�̃A�j���[�V����

const std::string player_tex				= "Player";		//	�v���C���[

const std::string drawer_tex				= "Drawer";		// �G�`��
const std::string perry_tex					= "Perry";		// �y���[
const std::string hermit_tex				= "Hermit";		// ��l
const std::string sinsengumi_tex			= "Sinsengumi";	// �V�I�g
const std::string fox_tex					= "Fox";		// ��

// UI
const std::string calloutui_tex				= "CalloutUI";	// �u�����I�v�{�^��

const std::string hpui_tex					= "HpUI";		// HP

	// �E���p
const std::string r_cutin_tex				= "R_CutIn";
	// �����p
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