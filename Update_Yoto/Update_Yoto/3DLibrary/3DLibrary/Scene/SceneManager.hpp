#ifndef SCENEMANAGER_H_
#define SCENEMANAGER_H_

#include "BaseScene.hpp"
#include "I_SceneChanger.hpp"

class SceneManager : public I_SceneChanger, Task
{
public:
	//�R���X�g���N�^
	SceneManager();

	//�f�X�g���N�^
	~SceneManager();

	//�������֐�
	void Init() override;

	//�I���֐�
	void End() override;
	
	//�X�V�֐�
	void Update() override;

	//�`��֐�
	void Draw() override;

	//�V�[���ύX�֐�
	void ChangeScene(SceneID nextScene) override;

	bool IsGameEnd();

private:
	BaseScene* m_Scene;
	SceneID m_NextScene;
};

#endif