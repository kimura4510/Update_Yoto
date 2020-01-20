#ifndef BACK_GROUND_H_
#define BACK_GROUND_H_

#include "../3DLibrary/3DLibrary/Engine/Graphics.hpp"

class BackGround {
public:
	BackGround();
	~BackGround() {}

public:
	void Update();
	void Draw();

	bool TransitionSceneInstall();

private:
	DrawingData3D m_bg[4];

	float m_x, m_y;
};

#endif