#ifndef HELPSCENE_H_
#define HELPSCENE_H_

#include "BaseScene.hpp"

class HelpScene : public BaseScene
{
	HelpScene(I_SceneChanger* changer);
	~HelpScene();
	void Init() override;
	void End() override;
	void Update() override;
	void Draw() override;
};

#endif