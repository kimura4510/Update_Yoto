/**
* @file Graphics.h
* @bief 描画に関係する関数、定数の宣言
*/

#ifndef DIRECT_GRAPHICS_H_
#define DIRECT_GRAPHICS_H_

#include <Windows.h>
#include <d3d9.h>

//!< @brief テクスチャデータやサイズを保持する構造体
struct Texture
{
	LPDIRECT3DTEXTURE9 m_TextureData;	//!< テクスチャデータ
	float m_Width;						//!< 横幅
	float m_Height;						//!< 縦幅
};

//!< @biref 3D描画用頂点座標保存構造体
struct CustomVertex3D
{
	float m_x;
	float m_y;
	float m_z;
	D3DCOLOR color;
	float tu, tv;
};

//!< @brief 2D描画用頂点座標保存構造体
struct CustomVertex
{
	float x;	//x座標
	float y;	//y座標
	float z;	//z座標
	float rhw;	//除算数

	float tu;	//テクスチャ座標x
	float tv;	//テクスチャ座標y
};

//!< @brief 3D描画のために必要なパラメータを設定するデータ構造体
struct DrawingData3D
{
	float m_x;	//x座標
	float m_y;	//y座標
	float m_z;	//z座標

	float m_tu;	//uテクスチャ座標
	float m_tv;	//vテクスチャ座標

	float m_width;	//幅
	float m_height;	//高さ

	DWORD m_color;	//color

	float m_rotx;	//x回転
	float m_roty;	//y回転
	float m_rotz;	//z回転

	float m_scalex;	//拡縮x
	float m_scaley;	//拡縮y
};

class Graphics
{
public:
	/**
	* @brief Graphics機能の初期化関数@n
	* 描画関連を使用可能にするための初期化を行います@n
	* Engine.cppのInitEngineで実行しているので使用者が自分で使う必要はありません
	* @param[in] window_handle インスタンスハンドル
	* @return 初期化結果、成功の場合はtrue
	*/
	bool InitGraphics(HWND window_handle);

	/**
	* @brief Graphics機能の終了関数@n
	* 描画関連の処理を終了させる関数@n
	* Engine.cppのEndEngineで実行しているので使用者が自分で使う必要はありません
	*/
	void ReleaseGraphics();

	/**
	* @brief 描画開始関数@n
	* 描画開始を宣言し、バックバッファのクリアを行います
	* @return 描画開始の成否、成功の場合はtrue
	*/
	bool DrawStart();

	/**
	* @brief 描画終了関数@n
	* 描画の終了を宣言し、バックバッファとフロントバッファを入れ替えます@n
	* この関数は必ずDrawStartの後に実行するようにしてください
	*/
	void DrawEnd();

	/**
	* @brief テクスチャ作成関数@n
	* 指定された情報から読み込み、テクスチャを作成します
	* 開発側はTexture.hのLoadTextureを使用してください
	* @return 作成結果、成功の場合はtrue
	* @param[in] file_name 読み込むテクスチャの名前(パスを含む)
	* @param[out] texture_data 読み込まれたテクスチャを反映するデータ
	*/
	bool CreateTexture(const char* file_name, Texture* texture_data);

	/**
	* @brief テクスチャ描画関数@n
	* 指定された位置にテクスチャを描画します@n
	* texture_dataはTexture.hのGetTextureDataを使用してください
	* @param[in] x X軸描画座標
	* @param[in] y Y軸描画座標
	* @param[in] texture_data 描画で使用するテクスチャのデータ
	*/
	void DrawTexture(float x, float y, Texture* texture_data);

	/**
	* @brief 統合画像描画関数
	* texture_dataはTexture.hのGetTextureDataを使用してください
	* @param[in] x X軸描画座標
	* @param[in] y Y軸描画座標
	* @param[in] texture_data 描画で使用するテクスチャのデータ
	* @param[in] tu テクスチャU座標の幅
	* @param[in] tv テクスチャV座標の高さ
	* @param[in] spriteX 描画したいスプライトの幅
	* @param[in] spriteY 描画したいスプライトの高さ
	* @param[in] spriteNumX 描画したいスプライトが左から何番目か
	* @param[in] spriteNumY 描画したいスプライトが上から何番目か
	*/
	void DrawIntegratedImage(float x, float y, Texture* texture_data, float tu, float tv, float spriteX, float spriteY, int spriteNumX, int spriteNumY);

	/**
	* @biref 3D描画関数
	* 指定された位置に3Dポリゴンを描画します@n
	* texture_dataはFile.hのGetTextureDataを使用してください
	* @param[in] v3D 座標などの情報群
	* @param[in] texture_data 描画で使用するテクスチャのデータ
	*/
	void Draw3D(const DrawingData3D& v3D, Texture* texture_data);

	/**
	* @biref 統合画像描画関数3Dversion
	* texture_dataはTexture.hのGetTextureDataを使用してください
	* @param[in] x X軸描画座標
	* @param[in] y Y軸描画座標
	* @param[in] texture_data 描画で使用するテクスチャのデータ
	* @param[in] tu テクスチャU座標の幅
	* @param[in] tv テクスチャV座標の高さ
	* @param[in] spriteX 描画したいスプライトの幅
	* @param[in] spriteY 描画したいスプライトの高さ
	* @param[in] spriteNumX 描画したいスプライトが左から何番目か
	* @param[in] spriteNumY 描画したいスプライトが上から何番目か
	*/
	void DrawIntegratedImage3D(const DrawingData3D& drawdata, Texture* texture_data, float tu, float tv, float spriteX, float spriteY, int spriteNumX, int spriteNumY);

	/**
	* @biref 統合画像描画関数3Dversion
	* texture_dataはTexture.hのGetTextureDataを使用してください
	* @param[in] x X軸描画座標
	* @param[in] y Y軸描画座標
	* @param[in] texture_data 描画で使用するテクスチャのデータ
	* @param[in] tu テクスチャU座標の幅
	* @param[in] tv テクスチャV座標の高さ
	* @param[in] spriteX 描画したいスプライトの幅
	* @param[in] spriteY 描画したいスプライトの高さ
	* @param[in] spriteNumX 描画したいスプライトが左から何番目か
	* @param[in] spriteNumY 描画したいスプライトが上から何番目か
	*/
	void DrawBillboard(const DrawingData3D& drawdata, Texture* texture_data, float tu, float tv, float spriteX, float spriteY, int spriteNumX, int spriteNumY);

	//カメラ用の関数
	bool SetView(const D3DMATRIX& matView) const;
	void GetViewport_Camera(D3DVIEWPORT9* vp);
	bool SetMatProj(const D3DMATRIX& matProj) const;

	//シングルトンデザインパターン
public:
	/**
	* @brief インスタンス生成関数@n
	* Graphicsクラスのインスタンスを生成する関数です@n
	*/
	static void CreateGraphicInstance();

	/**
	* @brief インスタンス破棄関数@n
	* Graphicsクラスのインスタンスを破棄する関数です@n
	*/
	static void DestroyGraphicInstance();

	/**
	* @brief インスタンス確認関数@n
	* Graphicsクラスのインスタンスの有無を確認する関数です@n
	*/
	static bool IsGraphicInstance_NULL();
	
	/**
	* @brief インスタンス取得関数@n
	* Graphicsクラスのインスタンスを取得する関数です@n
	*/
	static Graphics* GetGraphicInstance();

private:

	//シングルトン
//コンストラクタ
	Graphics();
//デストラクタ
	~Graphics();

private:
	//グローバル変数
	LPDIRECT3D9 g_D3DInterface;		//DirectGraphicsインターフェース
	LPDIRECT3DDEVICE9 g_D3DDevice;		//DirectGraphicsデバイス


	static Graphics* p_GraphicInstance;		//Graphicsのインスタンス
};

#endif