#ifndef CLEARSCENE_H_
#define CLEARSCENE_H_

#include "BaseScene.hpp"
#include <string>

const std::string win = "Win";

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


