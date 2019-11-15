/**
* @file GameScene.h
* @brief ゲーム本編シーンの関数の宣言
*/
#ifndef GAME_SCENE_H_
#define GAME_SCENE_H_

#include "Scene.hpp"

enum STAGES
{
	Stage1,
	Stage2,
	Stage3,
	Stage4,
	Stage5,
	MaxStages,
};

class GAMESCENE
{
public:

	GAMESCENE()
	{
		g_CurrentStage = STAGES::Stage1;
	};

	/**
	* @brief ゲーム本編シーンの更新関数@n
	* ゲーム本編シーンの仕様が実行される
	* @return 遷移先シーンID(基本はSceneID::GameSceneが返る)
	*/
	SceneID UpdateGameScene();

	/**
	* @brief ゲーム本編シーンの描画関数@n
	* ゲーム本編シーンのオブジェクトを描画するための関数
	*/
	void DrawGameScene();

private:
	int g_CurrentStage;

	void InitGameScene();
	void UpdateStage();
	void MainGameScene();
	SceneID FinishGameScene();
};


#endif
