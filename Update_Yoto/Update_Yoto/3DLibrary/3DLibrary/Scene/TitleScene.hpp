#ifndef TITLESCENE_H_
#define TITLESCENE_H_

#include "BaseScene.hpp"

class TitleScene : public BaseScene
{
public:
	TitleScene(I_SceneChanger* changer);
	void Init() override;
	//void End() override;
	void Update() override;
	void Draw() override;
};

#endif