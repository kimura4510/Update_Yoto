#ifndef HELPSCENE_H_
#define HELPSCENE_H_

#include "BaseScene.hpp"

class HelpScene : public BaseScene
{
	~HelpScene();
	void Init() override;
	SceneID End() override;
	void Update() override;
	void Draw() override;
};

#endif