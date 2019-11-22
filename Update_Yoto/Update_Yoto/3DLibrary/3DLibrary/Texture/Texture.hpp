/**
* @file Texture.h
* @brief テクスチャの読み込み、開放など、テクスチャに関係する関数、定数の宣言
*/
#ifndef TEXTURE_H_
#define TEXTURE_H_

#include "../Engine/Graphics.hpp"

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

class cTexture
{
public:
	/**
	* @brief テクスチャデータの初期化関数@n
	* ゲームで使用するテクスチャデータを保存できるようにします
	*/
	void InitTexture();

	/**
	* @brief カテゴリー単位のテクスチャ解放関数@n
	* 引数で指定されたカテゴリーのテクスチャを全て解放します
	* @param[in] category_id 解放するカテゴリー
	*/
	void ReleaseCategoryTexture(int category_id);

	/**
	* @brief 全てのテクスチャの解放関数@n
	* 読み込んでいる全てのテクスチャを解放します
	* この関数はEndEngineで実行してるので、開発側が実行する必要はありません
	*/
	void AllReleaseTexture();

	/**
	* @brief テクスチャの読み込み関数@n
	* 指定したパスのテクスチャを読み込み、カテゴリに登録します
	* return 読み込み結果、成功の場合はtrue
	* @param[in] file_name 読み込むテクスチャの名前(パスを含む)
	* @param[in] category_id 登録するカテゴリー
	* @param[in] texture_id カテゴリー内のテクスチャID
	*/
	bool LoadTexture(const char* file_name, int id, int textureID);

	/**
	* @brief テクスチャデータの取得関数@n
	* 指定されたカテゴリーのテクスチャデータを取得します
	* @return テクスチャデータ、失敗した場合はnullptr
	* @param[in] category_id 取得したいテクスチャのカテゴリ
	* @param[in] texture_id 取得したいテクスチャのID
	*/
	Texture* GetTexture(int categoryID, int textureID);

	//シングルトンデザインパターン
public:
	/**
	* @brief インスタンス生成関数@n
	* Textureクラスのインスタンスを生成する関数です@n
	*/
	static void CreateTextureInstance();

	/**
	* @brief インスタンス破棄関数@n
	* Textureクラスのインスタンスを破棄する関数です@n
	*/
	static void DestroyTextureInstance();

	/**
	* @brief インスタンス確認関数@n
	* Textureクラスのインスタンスの有無を確認する関数です@n
	*/
	static bool IsTextureInstance_NULL();

	/**
	* @brief インスタンス取得関数@n
	* Textureクラスのインスタンスを取得する関数です@n
	*/
	static cTexture* GetTextureInstance();


private:
	//シングルトン
//コンストラクタ
	cTexture();
	//デストラクタ
	~cTexture();

	bool IsCategoryIDCheck(int category_id, int texture_id);

private:
	//Textureのインスタンス
	static cTexture* p_TextureInstance;

	//カテゴリのテクスチャ最大サイズの配列
	Texture** m_ppTextureList[(int)TextureCategory::MaxTextureCategory];

	const int TextureCategorySize[(int)TextureCategory::MaxTextureCategory] =
	{
		(int)TitleCategoryTextureList::MaxTitleTex,
		(int)GameCategoryTextureList::MaxGameTex,
		(int)HelpCategoryTextureList::MaxHelpTex,
		(int)ClearCategoryTextureList::MaxClearTex,
		(int)GameoverCategoryTextureList::MaxGameoverTex,
	};
};

#endif