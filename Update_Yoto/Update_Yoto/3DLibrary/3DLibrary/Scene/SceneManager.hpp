#ifndef SCENEMANAGER_H_
#define SCENEMANAGER_H_

#include "BaseScene.hpp"
#include <vector>

class SceneManager
{
public:
	//�R���X�g���N�^
	SceneManager();

	//�f�X�g���N�^
	~SceneManager();

	//�������֐�
	void Init(SceneID id);

	//�I���֐�
	void End();
	
	//�X�V�֐�
	void Update();

	//�`��֐�
	void Draw();

	//�V�[���ύX�֐�
	void ChangeScene(SceneID nextScene);

	bool IsGameEnd();

private:
	std::vector<BaseScene*> m_SceneList;
	BaseScene* m_CurrentScene;
	SceneID m_SceneID;
};

#endif