#include "TransitionScene.hpp"



void TransitionScene::Init()
{
	m_State = SceneState::eMain;
}

SceneID TransitionScene::End()
{
	m_State = SceneState::eInit;
}


void TransitionScene::Update()
{
	// m_State = SceneState::eEnd;
}

SceneID TransitionScene::Control()
{
	switch (m_State)
	{
	case SceneState::eInit:
		Init();
		break;
	case SceneState::eMain:
		Update();
		break;
	case SceneState::eEnd:
		return End();
	}
	return SceneID::eTransitionScene;
}

void TransitionScene::Draw()
{

}

