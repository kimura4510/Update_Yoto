#ifndef GAMESCENE_H_
#define GAMESCENE_H_

#include "BaseScene.hpp"

class GameScene : public BaseScene
{
	GamseScene(I_SceneChanger* changer);
	void Init() override;
	void End() override;
	void Update() override;
	void Draw() override;
};

#endif