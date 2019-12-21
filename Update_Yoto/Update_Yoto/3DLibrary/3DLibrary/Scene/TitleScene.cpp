#include "TitleScene.hpp"
#include "../Engine/Input.hpp"
#include "../Engine/Graphics.hpp"
#include "../Texture/Texture.hpp"

//‰Šú‰»
void TitleScene::Init()
{
	m_DisplayState = DisplayState::Title;
	m_DisplayNum = 0;

	cTexture* tex = cTexture::GetTextureInstance();
	tex->LoadTexture("Resource/Title/title.png", title);
	tex->LoadTexture("Resource/Title/menu.png", menu);

	m_State = SceneState::eMain;
}

//XV
void TitleScene::Update()
{
	Input* inpt = Input::GetInputInstance();

	if (m_DisplayState == DisplayState::Title)
	{
		if (inpt->GetKey(KEY_INFO::ENTER_KEY) == true)
		{
			m_DisplayState = DisplayState::PvE;
			m_DisplayNum = (int)DisplayState::PvE;
		}
	}
	else if (m_DisplayState != DisplayState::Title)
	{
		if (inpt->GetKeyDown(KEY_INFO::UP_KEY) == true)
		{
			if (m_DisplayNum > 1)
			{
				m_DisplayNum--;
				m_DisplayState = static_cast<DisplayState>(m_DisplayNum);
			}
		}
	
		if (inpt->GetKeyDown(KEY_INFO::DOWN_KEY) == true)
		{
			if (m_DisplayNum < 3)
			{
				m_DisplayNum++;
				m_DisplayState = static_cast<DisplayState>(m_DisplayNum);
			}
		}

		if (inpt->GetKey(KEY_INFO::ENTER_KEY) == true)
		{
			m_State = SceneState::eEnd;
		}
	}
}

SceneID TitleScene::End()
{
	cTexture* tex = cTexture::GetTextureInstance();
	tex->ReleaseTexture(title);
	tex->ReleaseTexture(menu);

	m_State = SceneState::eInit;
	return SceneID::eGameScene;
}

SceneID TitleScene::Control()
{
	switch(m_State)
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
	return SceneID::eTitleScene;
}

void TitleScene::Draw()
{
	Graphics* graph = Graphics::GetGraphicInstance();
	cTexture* tex = cTexture::GetTextureInstance();

	switch (m_DisplayState)
	{
	case DisplayState::Title:
		graph->DrawIntegratedImage(0.0f, 0.0f,
			tex->GetTexture(title), 0.9375f, 0.52734375f, 1920.0f, 1080.0f, 1, 1);
		break;
	case DisplayState::PvE:
		graph->DrawIntegratedImage(0.0f, 0.0f,
			tex->GetTexture(menu), 0.234275f, 0.52734375f, 1920.0f, 1080.0f, 1, 1);
		break;
	case DisplayState::PvP:
		graph->DrawIntegratedImage(0.0f, 0.0f,
			tex->GetTexture(menu), 0.234375f, 0.52734375f, 1920.0f, 1080.0f, 2, 1);
		break;
	case DisplayState::Help:
		graph->DrawIntegratedImage(0.0f, 0.0f,
			tex->GetTexture(menu), 0.234375f, 0.52734375f, 1920.0f, 1080.0f, 3, 1);
		break;
	}
}
