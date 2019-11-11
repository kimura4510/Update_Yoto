#ifndef SCENEMANAGER_H_
#define SCENEMANAGER_H_

#include "I_SceneChanger.hpp"
#include "BaseScene.hpp"

class SceneManager : public I_SceneChanger, Task
{
private:
	BaseScene* m_Scene;
	SceneID m_NextScene;

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
};



#endif