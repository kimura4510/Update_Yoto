#include "HelpScene.hpp"
#include "../Engine/Graphics.hpp"
#include "../Engine/Input.hpp"
#include "../Texture/Texture.hpp"

void HelpScene::Init()
{
	m_State = SceneState::eMain;
}

void HelpScene::Update()
{
	Input* inp =  Input::GetInputInstance();

	if (inp->GetKeyDown(KEY_INFO::ENTER_KEY) == true || inp->GetGamePadBottonState(0, GAMEPAD_BUTTONS::A) == INPUT_STATE::PUSH_DOWN)
	{
		m_State = SceneState::eEnd;
	}
}

void HelpScene::Draw()
{
	if (m_State != SceneState::eMain)
	{
		return;
	}
}

SceneID HelpScene::End()
{
	return SceneID::eTitleScene;
}

SceneID HelpScene::Control()
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
	return SceneID::eHelpScene;
}