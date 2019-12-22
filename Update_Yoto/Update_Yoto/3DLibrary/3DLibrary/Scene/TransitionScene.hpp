#ifndef TRANSITIONSCENE_H_
#define TRANSITIONSCENE_H_

#include "BaseScene.hpp"

class TransitionScene : public BaseScene
{
public:
	~TransitionScene() override { }
	void Init() override;
	SceneID End() override;
	void Update() override;
	SceneID Control() override;
	void Draw() override;
};


#endif