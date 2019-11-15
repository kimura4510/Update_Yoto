/**
* @file Scene.h
* @brief �V�[���S�̂����s�A�`�悷��֐��̐錾
*/

#ifndef SCENE_H_
#define SCENE_H_

// @brief �V�[��ID
enum SceneID
{
	TitleScene,			//!<�^�C�g���V�[��
	HelpScene,			//!<�w���v�V�[��
	GameScene,			//!<�Q�[���{�҃V�[��
	GameClearScene,		//!<�Q�[���N���A�V�[��
	GameEndScene,		//!<�Q�[���I���V�[��
	SceneIDMax			//!<�V�[��ID�ő�
};

// @brief �V�[���X�e�b�v
enum SceneStep
{
	InitStep,		//!< ������
	MainStep,		//!< ���C��
	EndStep,		//!< �I��
};

class SCENE
{
public:
	SCENE()
	{
		g_CurrentSceneID = SceneID::TitleScene;
		g_CurrentSceneStep = SceneStep::InitStep;
	};

	// @brief ���ݎ��s���̃V�[��ID�̎擾�֐�
	SceneID GetCurrentSceneID();

	// @brief ���ݎ��s���̃V�[���X�e�b�v�̎擾�֐�
	SceneStep GetCurrentSceneStep();

	/**
	* @brief �V�[���X�e�b�v�ύX�֐�@n
	* ��k���Ŏw�肵���X�e�b�v�ɐ؂�ւ��܂�
	* @param[in] next_step�@���̃X�e�b�v
	*/
	void ChangeSceneStep(SceneStep next_step);

	/**
	* @brief �V�[�����s�֐�@n
	* �V�[�����������s����@n
	* �����Ŋe�V�[���𓮂������߁A�g�p�҂�UpdateTitleScene�������s����K�v�͂���܂���
	*/
	void UpdateScene();

	/**
	* @brief �V�[���`��֐�@n
	* �V�[���̃I�u�W�F�N�g��`�悵�܂�@n
	* �����Ŋe�V�[���̕`����s�����߁A�g�p�҂�DrawTitileScene�������s����K�v�͂���܂���
	*/
	void DrawScene();

private:
	SceneID g_CurrentSceneID;		// ���쒆�V�[��ID
	SceneStep g_CurrentSceneStep;	// ���쒆�V�[���̃X�e�b�v
};

#endif