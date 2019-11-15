/**
* @file TitleScene.h
* @brief �^�C�g���V�[���̊֐��̐錾
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
	* @brief �^�C�g���V�[���̍X�V�֐�@n
	* �^�C�g���V�[���̎d�l�����s�����
	* @return �J�ڐ�V�[��ID(��{��SceneID::TitleScene���Ԃ�)
	*/
	SceneID UpdateTitleScene();

	/**
	* @brief �^�C�g���V�[���̕`��֐�@n
	* �^�C�g���V�[���̃I�u�W�F�N�g��`�悷��֐�
	*/
	void DrawTitleScene();

	/**
	* @brief �Q�[���I���֐�@n
	* �Q�[�����I��������֐�
	*/
	bool EndCheck();

private:
	bool IsGameEnd;			//�Q�[���I���t���O
	bool IsNextScene;		//�V�[���ȍ~�t���O true->GameScene false->HelpScene

	void InitTitleScene();
	void MainTitleScene();
	SceneID FinishTitleScene();
};

#endif