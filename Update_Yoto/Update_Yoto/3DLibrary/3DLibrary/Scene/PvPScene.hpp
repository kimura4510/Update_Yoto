#ifndef PVPSCENE_H_
#define PVPSCENE_H_

#include "BaseScene.hpp"

class PvPScene : public BaseScene
{
public:
	~PvPScene() override { }
	void Init() override;
	SceneID End() override;
	void Update() override;
	SceneID Control() override;
	void Draw() override;
};

#endif