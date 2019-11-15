/**
* @file GameScene.h
* @brief �Q�[���{�҃V�[���̊֐��̐錾
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
	* @brief �Q�[���{�҃V�[���̍X�V�֐�@n
	* �Q�[���{�҃V�[���̎d�l�����s�����
	* @return �J�ڐ�V�[��ID(��{��SceneID::GameScene���Ԃ�)
	*/
	SceneID UpdateGameScene();

	/**
	* @brief �Q�[���{�҃V�[���̕`��֐�@n
	* �Q�[���{�҃V�[���̃I�u�W�F�N�g��`�悷�邽�߂̊֐�
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
