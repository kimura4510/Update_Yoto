#ifndef GAMESCENE_H_
#define GAMESCENE_H_

#include "BaseScene.hpp"
#include "../../../Character/CharacterManager.h"]

class GameScene : public BaseScene
{
public:
	//デストラクタ
	~GameScene() override { }
	void Init() override;
	SceneID End() override;
	void Update() override;
	SceneID Control() override;
	void Draw() override;

private:
	CharacterManager chmanager;
};

#endif