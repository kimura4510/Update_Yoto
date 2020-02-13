#include "PvPScene.hpp"
#include "../Engine/Graphics.hpp"
#include "../Engine/Input.hpp"
#include "../Texture/Texture.hpp"

void PvPScene::Init()
{
	m_State = SceneState::eMain;
}

void PvPScene::Update()
{
	Input* inp = Input::GetInputInstance();

	if (inp->GetKeyDown(KEY_INFO::ENTER_KEY) == true || inp->GetGamePadBottonState(0, GAMEPAD_BUTTONS::A) == INPUT_STATE::PUSH_DOWN)
	{
		m_State = SceneState::eEnd;
	}
}

void PvPScene::Draw()
{
	if (m_State != SceneState::eMain)
	{
		return;
	}
}

SceneID PvPScene::End()
{
	return SceneID::eTitleScene;
}

SceneID PvPScene::Control()
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