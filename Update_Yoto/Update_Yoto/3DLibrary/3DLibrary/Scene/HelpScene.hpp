#ifndef HELPSCENE_H_
#define HELPSCENE_H_

#include "BaseScene.hpp"

class HelpScene : public BaseScene
{
public:
	~HelpScene() override { }
	void Init() override;
	SceneID End() override;
	void Update() override;
	SceneID Control() override;
	void Draw() override;

private:
	int m_counter;
};

#endif