#ifndef BASE_SCENE_H_
#define BASE_SCENE_H_

#include "../Task.hpp"
#include "I_SceneChanger.hpp"

class BaseScene :public Task
{
protected:
	// @biref �N���X�̏��L���ɃV�[���̐؂�ւ���`����C���^�[�t�F�C�X
	I_SceneChanger* m_SceneChanger;

public:
	BaseScene(I_SceneChanger* sceneChanger);
	virtual ~BaseScene() { }
	virtual void Update() override {};
	virtual void Draw() override {};

	virtual void Init() override {};
	virtual void End() override {};
}


#endif