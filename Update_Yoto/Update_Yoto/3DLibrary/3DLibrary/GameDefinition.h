#ifndef GAMEDEFINITION_H_
#define GAMEDEFINITION_H_
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

#endif