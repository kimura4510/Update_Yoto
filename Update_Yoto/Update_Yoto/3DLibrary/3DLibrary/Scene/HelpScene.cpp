#include "HelpScene.hpp"
#include "../Engine/Graphics.hpp"
#include "../Engine/Input.hpp"
#include "../Texture/Texture.hpp"

void HelpScene::Init()
{
	cTexture* tex = cTexture::GetTextureInstance();
	tex->LoadTexture("Resource/Help/help_base.png", help_base);
	tex->LoadTexture("Resource/Help/help1.png", help1);
	tex->LoadTexture("Resource/Help/help2.png", help2);
	tex->LoadTexture("Resource/Help/help3.png", help3);
	tex->LoadTexture("Resource/Help/help4.png", help4);

	m_counter = 0;
	m_State = SceneState::eMain;
}

void HelpScene::Update()
{
	m_counter++;
	if (m_counter > 360)
	{
		m_counter = 0;
	}

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
	Graphics* gra = Graphics::GetGraphicInstance();
	cTexture* tex = cTexture::GetTextureInstance();

	gra->DrawTexture(0, 0, tex->GetTexture(help_base));

	if (m_counter < 90)
	{
		gra->DrawIntegratedImage(250, 180, tex->GetTexture(help1), 1, 1, 1432, 796, 1, 1);
	}
	else if (m_counter < 180)
	{
		gra->DrawIntegratedImage(250, 180, tex->GetTexture(help2), 1, 1, 1432, 796, 1, 1);
	}
	else if (m_counter < 270)
	{
		gra->DrawIntegratedImage(250, 180, tex->GetTexture(help3), 1, 1, 1432, 796, 1, 1);
	}
	else
	{
		gra->DrawIntegratedImage(450, 180, tex->GetTexture(help4), 1, 1, 1432, 796, 1, 1);
	}
}

SceneID HelpScene::End()
{
	cTexture* tex = cTexture::GetTextureInstance();
	tex->ReleaseTexture(help_base);
	tex->ReleaseTexture(help1);
	tex->ReleaseTexture(help2);
	tex->ReleaseTexture(help3);
	tex->ReleaseTexture(help4);

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