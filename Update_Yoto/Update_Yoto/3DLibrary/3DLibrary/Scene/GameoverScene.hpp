#ifndef GAMEOVERSCENE_H_
#define GAMEOVERSCENE_H_

#include "BaseScene.hpp"
#include <string>

const std::string lose = "Lose";

class GameoverScene : public BaseScene
{
public:
	~GameoverScene() override { }
	void Init() override;
	void Update() override;
	SceneID End() override;
	void Draw() override;
	SceneID Control() override;

private:
};

#endif 