#ifndef NON_SCENE_H_
#define NON_SCENE_H_

#include "BaseScene.hpp"

class NonScene : public BaseScene
{
public:
	virtual void Init() override
	{ }
	virtual void Update() override
	{ }
	virtual void Draw() override
	{ }

	virtual SceneID End()
	{
		return SceneID::eNon_Scene;
	}

	virtual SceneID Control()
	{
		return SceneID::eNon_Scene;
	}
};

#endif