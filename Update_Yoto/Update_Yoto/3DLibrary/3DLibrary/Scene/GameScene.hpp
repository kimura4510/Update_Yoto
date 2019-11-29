#ifndef GAMESCENE_H_
#define GAMESCENE_H_

#include "BaseScene.hpp"

class GameScene : public BaseScene
{
public:
	//�f�X�g���N�^
	~GameScene() override { }
	void Init() override;
	SceneID End() override;
	void Update() override;
	SceneID Control() override;
	void Draw() override;
};

#endif