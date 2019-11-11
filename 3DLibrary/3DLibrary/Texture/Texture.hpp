/**
* @file Texture.h
* @brief テクスチャの読み込み、開放など、テクスチャに関係する関数、定数の宣言
*/
#ifndef TEXTURE_H_
#define TEXTURE_H_

#include "../Engine/Graphics.hpp"
#include "Scene.hpp"

// @brief タイトル用のテクスチャリスト
enum TitleCategoryTextureList
{
	TitleBgTex,				//!< 背景
	TitleObject,			//!< 選択アイコン
	TitleTextureMax,		//!< リスト最大数
};

// @brief ゲーム本編用テクスチャリスト
enum GameCategoryTextureList
{
	GameBgTex,			//!< 背景
	GameTextureMax,		//!< リスト最大数
};

// @brief ヘルプ用テスクチャリスト
enum HelpCategoryTextureList
{
	Help1,				//!< 背景
	HelpTextureMax,			//!< リスト最大数
};

#define TEXTURE_CATEGORY_TITLE (SceneID::TitleScene)			//!< タイトルカテゴリー
#define TEXTURE_CATEGORY_HELP (SceneID::HelpScene)				//!< ヘルプカテゴリー
#define TEXTURE_CATEGORY_GAME (SceneID::GameScene)				//!< ゲーム本編カテゴリー
#define TEXTURE_CATEGORY_GAMECLEAR (SceneID::GameClearScene)	//!< ゲームクリア―カテゴリー
#define TEXTURE_CATEGORY_GAMEOVER (SceneID::GameOverScene)		//!< ゲームオーバーカテゴリー
#define MAX_TEXTURE_CATEGORY (SceneID::SceneIDMax)				//!< カテゴリー最大

class TEXTURE
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
	bool LoadTexture(const char* file_name, int category_id, int texture_id);

	/**
	* @brief テクスチャデータの取得関数@n
	* 指定されたカテゴリーのテクスチャデータを取得します
	* @return テクスチャデータ、失敗した場合はnullptr
	* @param[in] category_id 取得したいテクスチャのカテゴリ
	* @param[in] texture_id 取得したいテクスチャのID
	*/
	Texture* GetTexture(int category_id, int texture_id);

private:
	//カテゴリごとのテクスチャ保存用配列
	Texture** g_TextureList[6] = { nullptr };

	//カテゴリのテクスチャ最大サイズの配列
	int TextureCategorySize[3] = {
		TitleCategoryTextureList::TitleTextureMax,
		HelpCategoryTextureList::HelpTextureMax,
		GameCategoryTextureList::GameTextureMax,
	};

	bool IsCategoryIDCheck(int category_id, int texture_id);

};

#endif