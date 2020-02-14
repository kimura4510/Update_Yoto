#include "ClearScene.hpp"
#include "../Engine/Input.hpp"
#include "../Engine/Graphics.hpp"
#include "../Texture/Texture.hpp"

void ClearScene::Init()
{
	cTexture* tex = cTexture::GetTextureInstance();
	tex->LoadTexture("Resource/GameEnd/Win1.png", win);

	m_State = SceneState::eMain;
}

void ClearScene::Update()
{
	Input* input = Input::GetInputInstance();
	if (input->GetGamePadBottonState(0, GAMEPAD_BUTTONS::A) == INPUT_STATE::PUSH_DOWN ||
		input->GetGamePadBottonState(0, GAMEPAD_BUTTONS::B) == INPUT_STATE::PUSH_DOWN ||
		input->GetGamePadBottonState(0, GAMEPAD_BUTTONS::X) == INPUT_STATE::PUSH_DOWN ||
		input->GetGamePadBottonState(0, GAMEPAD_BUTTONS::Y) == INPUT_STATE::PUSH_DOWN)
	{
		m_State = SceneState::eEnd;
	}
}

SceneID ClearScene::End()
{
	cTexture* tex = cTexture::GetTextureInstance();
	tex->ReleaseTexture(win);

	m_State = SceneState::eInit;
	return SceneID::eTitleScene;
}

SceneID ClearScene::Control()
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
	return SceneID::eClearScene;
}

void ClearScene::Draw()
{
	Graphics* gp = Graphics::GetGraphicInstance();
	cTexture* tex = cTexture::GetTextureInstance();
	gp->DrawTexture(0.0f, 0.0f, tex->GetTexture(win));
}