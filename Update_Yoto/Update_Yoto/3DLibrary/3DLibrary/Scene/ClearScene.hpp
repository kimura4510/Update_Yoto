#ifndef CLEARSCENE_H_
#define CLEARSCENE_H_

#include "BaseScene.hpp"

class ClearScene : public BaseScene
{
public:
	~ClearScene() override { }
	void Init() override;
	void Update() override;
	SceneID End() override;
	void Draw() override;
	SceneID Control() override;

private:
};


#endif // !CLEARSCENE_H_


