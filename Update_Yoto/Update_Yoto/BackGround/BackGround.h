#ifndef BACK_GROUND_H_
#define BACK_GROUND_H_

#include "../3DLibrary/3DLibrary/Engine/Graphics.hpp"

class BackGround {
public:
	BackGround();
	~BackGround() {}

public:
	void MoveTransitionScene();
	bool TransitionSceneLower();
	void TransitionSceneSetToRight();
	bool TransitionSceneInstall();

	void Draw();
	void TransitionDraw();
	

private:
	DrawingData3D m_bg[4];
	
	float m_transition_x, m_transition_y;
};

#endif