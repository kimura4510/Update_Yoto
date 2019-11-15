/**
* @file Texture.h
* @brief テクスチャの読み込み、開放など、テクスチャに関係する関数、定数の宣言
*/
#ifndef TEXTURE_H_
#define TEXTURE_H_

#include "../Engine/Graphics.hpp"
#include "../Scene/I_SceneChanger.hpp"

// @brief タイトル用のテクスチャリスト
enum class TitleCategoryTextureList : int
{
	TitleBgTex,				//!< 背景
	TitleObject,			//!< 選択アイコン
	Max,		//!< リスト最大数
};

// @brief ゲーム本編用テクスチャリスト
enum class GameCategoryTextureList : int
{
	GameBgTex,			//!< 背景
	Max,		//!< リスト最大数
};


// @brief ヘルプ用テスクチャリスト
enum class HelpCategoryTextureList : int
{
	Help1,				//!< 背景
	Max,			//!< リスト最大数
};


enum class GameoverCategoryTextureList : int
{
	Max,
};


enum class ClearCategoryTextureList : int
{
	Max,
};

#define TEXTURE_CATEGORY_TITLE ((int)SceneID::eTitleScene);
#define TEXTURE_CATEGORY_GAME ((int)SceneID::eGameScene);
#define TEXTURE_CATEGORY_HELP ((int)SceneID::eHelpScene);
#define TEXTURE_CATEGORY_CLEAR ((int)SceneID::eClearScene);
#define TEXTURE_CATEGORY_GAMEOVER ((int)SceneID::eGameoverScene);
#define MAX_TEXTURE_CATEGORY ((int)SceneID::eSceneIDMax)

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
	bool LoadTexture(const char* file_name, int category_id, int texture_id);

	/**
	* @brief テクスチャデータの取得関数@n
	* 指定されたカテゴリーのテクスチャデータを取得します
	* @return テクスチャデータ、失敗した場合はnullptr
	* @param[in] category_id 取得したいテクスチャのカテゴリ
	* @param[in] texture_id 取得したいテクスチャのID
	*/
	Texture* GetTexture(int category_id, int texture_id);

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
	//カテゴリごとのテクスチャ保存用配列
	Texture*** m_ppTextureList;

	//カテゴリのテクスチャ最大サイズの配列
	int* m_pTextureCategorySize;

	bool IsCategoryIDCheck(int category_id, int texture_id);

	//シングルトン
	//コンストラクタ
	cTexture();
	~cTexture();		//デストラクタ

	static cTexture* p_TextureInstance;		//Textureのインスタンス
};

#endif