/**
* @file Texture.h
* @brief テクスチャの読み込み、開放など、テクスチャに関係する関数、定数の宣言
*/
#ifndef TEXTURE_H_
#define TEXTURE_H_

#include "../Engine/Graphics.hpp"
#include "../GameDefinition.h"
#include <unordered_map>
#include <string>

class cTexture
{
public:
	/**
	* @brief テクスチャデータの初期化関数@n
	* ゲームで使用するテクスチャデータを保存できるようにします
	*/
	void InitTexture();

	/**
	* @brief 全てのテクスチャの解放関数@n
	* 読み込んでいる全てのテクスチャを解放します
	* この関数はEndEngineで実行してるので、開発側が実行する必要はありません
	*/
	void ReleaseAllTexture();
	
	/**
	* @brief 指定したテクスチャの開放関数
	* 指定したテクスチャを開放します
	* return 解放に成功した場合はtrue、失敗でfalse(キー指定ミス)
	* param[in] key_name 解放したいテクスチャのキー
	*/
	bool ReleaseTexture(std::string key_name);

	/**
	* @brief テクスチャ読み込み関数
	* 指定したパスのテクスチャを読み込み、mapに登録します
	* return 読み込み結果、成功の場合はtrue
	* @param[in] file_name 読み込むテクスチャのパスを含む名前
	* @param[in] key_name 読み込むテクスチャに当てはめるキー
	*/
	bool LoadTexture(const char* file_name, std::string key_name);

	/**
	* @brief テクスチャデータの取得関数
	* 指定された名前のテクスチャデータを取得します
	* @return テクスチャデータ、失敗した場合はnullptr
	* @param[in] file_name 取得したいテクスチャのキー
	*/
	Texture* GetTexture(std::string file_name);

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

	/**
	* @brief TextureListのキーチェック関数
	* 引数で指定されたキーが登録されているかを確認します
	* return 登録されていた場合はtrue、未登録の場合はfalse
	* @param[in] key_name　チェックしたいキー
	*/
	bool HasKeyName(std::string key_name);

private:
	//Textureのインスタンス
	static cTexture* p_TextureInstance;

	//!< Texture構造体保存用ポインタ配列
	std::unordered_map<std::string, Texture*> m_pTextureList;
};

#endif