#include "TransitionScene.hpp"
#include "../Engine/Input.hpp"
#include "../Engine/Graphics.hpp"
#include "../Texture/Texture.hpp"
#include "../../../LoadResources/LoadResources.h"

void TransitionScene::Init()
{
	LoadResources::Load();

	m_State = SceneState::eMain;
}

SceneID TransitionScene::End()
{
	m_State = SceneState::eInit;
	return SceneID::eGameScene;
}

void TransitionScene::Update()
{
	Input* input = Input::GetInputInstance();
	if (input->GetKey(KEY_INFO::ENTER_KEY) == true)
	{
		m_State = SceneState::eEnd;
	}
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
	Graphics* gp = Graphics::GetGraphicInstance();
	cTexture* tex = cTexture::GetTextureInstance();
	gp->DrawTexture(0.0f, 0.0f, tex->GetTexture(transition));
}