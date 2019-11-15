/**
* @file HelpScene.h
* @brief ヘルプシーンの関数の宣言
*/
#ifndef HELP_SCENE_H_
#define HELP_SCENE_H_

#include "Scene.hpp"


class HELPSCENE
{
public:
	/**
	* @brief ヘルプシーンの更新関数@n
	* ヘルプシーンの仕様が実行される
	* @return 遷移先シーンID(基本はSceneID::HelpSceneが返る)
	*/
	SceneID UpdateHelpScene();

	/**
	* @brief ヘルプシーンの描画関数@n
	* ヘルプシーンのオブジェクトを描画する関数
	*/
	void DrawHelpScene();

private:
	void InitHelpScene();
	void MainHelpScene();
	SceneID FinishHelpScene();
};


#endif
