#ifndef GAMEDEFINITION_H_
#define GAMEDEFINITION_H_

#include <string>

//!< �e�N�X�`�����X�g�̃L�[�̗�A�g�p�҂��e���Œǉ����邱��
const std::string texture_name = "ex.Update_Yoto";

//!< Title�p�e�N�X�`�����X�g�L�[
const std::string title = "Title";
const std::string menue = "Menue";

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