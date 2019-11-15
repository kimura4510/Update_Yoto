/**
* @file HelpScene.h
* @brief �w���v�V�[���̊֐��̐錾
*/
#ifndef HELP_SCENE_H_
#define HELP_SCENE_H_

#include "Scene.hpp"


class HELPSCENE
{
public:
	/**
	* @brief �w���v�V�[���̍X�V�֐�@n
	* �w���v�V�[���̎d�l�����s�����
	* @return �J�ڐ�V�[��ID(��{��SceneID::HelpScene���Ԃ�)
	*/
	SceneID UpdateHelpScene();

	/**
	* @brief �w���v�V�[���̕`��֐�@n
	* �w���v�V�[���̃I�u�W�F�N�g��`�悷��֐�
	*/
	void DrawHelpScene();

private:
	void InitHelpScene();
	void MainHelpScene();
	SceneID FinishHelpScene();
};


#endif
