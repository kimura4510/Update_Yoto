#ifndef I_SCENECHANGER_H_
#define I_SCENECHANGER_H_

enum class SceneID
{
	eTitleScene,
	eGameScene,
	eHelpScene,
	eClearScene,
	eGameoverScene,

	eSceneIDMax,
	eNon_Scene,

};

// Scene�ύX�̂��߂̃C���^�[�t�F�C�X�N���X
class I_SceneChanger
{
public:
	virtual ~I_SceneChanger() = 0;

	/**
	* @brief �V�[���ύX�֐�
	* �w�肵���V�[���ɕύX����
	* param[in] nextScene�@���̃V�[��ID
	*/
	virtual void ChangeScene(SceneID nextScene) = 0;
};

#endif