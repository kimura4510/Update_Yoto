/**
* @file TitleScene.h
* @brief タイトルシーンの関数の宣言
*/
#ifndef TITLE_SCENE_H_
#define TITLE_SCENE_H_

#include "Scene.hpp"


class TITLESCENE
{
public:

	TITLESCENE()
	{
		IsGameEnd = false;
		IsNextScene = true;
	};
	/**
	* @brief タイトルシーンの更新関数@n
	* タイトルシーンの仕様が実行される
	* @return 遷移先シーンID(基本はSceneID::TitleSceneが返る)
	*/
	SceneID UpdateTitleScene();

	/**
	* @brief タイトルシーンの描画関数@n
	* タイトルシーンのオブジェクトを描画する関数
	*/
	void DrawTitleScene();

	/**
	* @brief ゲーム終了関数@n
	* ゲームを終了させる関数
	*/
	bool EndCheck();

private:
	bool IsGameEnd;			//ゲーム終了フラグ
	bool IsNextScene;		//シーン以降フラグ true->GameScene false->HelpScene

	void InitTitleScene();
	void MainTitleScene();
	SceneID FinishTitleScene();
};

#endif