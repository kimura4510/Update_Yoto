/**
* @file Engine.h
* @brief エンジン処理(描画、入力)に関する関数、定数の宣言
*/
#ifndef ENGINE_H_
#define ENGINE_H_

class Engine
{
public:
	/**
* @brief エンジン初期化の関数@n
* ゲームで使うエンジン部分(描画、入力)の初期化を行います@n
* この関数はゲームループの開始前に1度だけ実行してください
* @return 初期化結果、成功の場合はtrue
*/
	bool InitEngine(HINSTANCE hInstance, HWND hW);

	/**
	* @brief エンジン終了の関数@n
	* ゲーム終了後にエンジン部分の終了を行います@n
	* この関数はゲームループ終了後に1度だけ実行してください
	*/
	void EndEngine();
};

#endif
