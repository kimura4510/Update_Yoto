#ifndef GAMESCENE_H_
#define GAMESCENE_H_

#include "BaseScene.hpp"

class GameScene : public BaseScene
{
	//�R���X�g���N�^
	GameScene(I_SceneChanger* changer);
	//�f�X�g���N�^
	~GameScene();
	void Init() override;
	void End() override;
	void Update() override;
	void Draw() override;
};

#endif