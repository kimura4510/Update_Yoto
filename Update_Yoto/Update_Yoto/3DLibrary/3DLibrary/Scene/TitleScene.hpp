#ifndef TITLESCENE_H_
#define TITLESCENE_H_

#include "BaseScene.hpp"

class TitleScene : public BaseScene
{
public:
	~TitleScene() override { }
	void Init() override;
	void Update() override;
	SceneID End() override;
	void Draw() override;
	SceneID Control() override;
};

#endif