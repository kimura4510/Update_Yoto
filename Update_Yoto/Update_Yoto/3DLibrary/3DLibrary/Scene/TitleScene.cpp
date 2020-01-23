#include "TitleScene.hpp"
#include "../Engine/Input.hpp"
#include "../Engine/Graphics.hpp"
#include "../Texture/Texture.hpp"
#include "SceneManager.hpp"

//初期化
void TitleScene::Init()
{
	m_DisplayState = DisplayState::Title;
	m_DisplayNum = 0;
	m_IsExit = 0;
	m_FPScounter = 0;
	m_transparency = 255;
	m_IsChange = false;
	m_BambooPosX = 1920.0f;

	cTexture* tex = cTexture::GetTextureInstance();
	tex->LoadTexture("Resource/Title/master/title_m_base.png", title_base);
	tex->LoadTexture("Resource/Title/master/title_button.png", title_button);
	tex->LoadTexture("Resource/Title/master/menu_master.png", menu);

	m_State = SceneState::eMain;
}

//更新
void TitleScene::Update()
{
	if (m_IsChange == true)
	{
		m_BambooPosX -= 10.0f;
		if (m_BambooPosX < 0)
		{
			m_State = SceneState::eEnd;
		}
		return;
	}

	Input* inpt = Input::GetInputInstance();

	if (m_DisplayState == DisplayState::Title)
	{
		//!< カウント処理
		m_FPScounter++;
		if (m_FPScounter >= 60)
		{
			m_transparency = 255;
			m_FPScounter = 0;
		}
		else if (m_FPScounter >= 30)
		{
			m_transparency = 0;
		}

		//!< タイトル画面のスタート、イグジットのどちらを選択しているかの処理
		if (inpt->GetGamePadBottonState(0, GAMEPAD_BUTTONS::lUp) == INPUT_STATE::PUSH_DOWN || inpt->GetKeyDown(KEY_INFO::UP_KEY) == true
			|| inpt->GetGamePadBottonState(0, GAMEPAD_BUTTONS::lDown) == INPUT_STATE::PUSH_DOWN || inpt->GetKeyDown(KEY_INFO::DOWN_KEY) == true)
		{
			if (m_IsExit == false)
			{
				m_IsExit = true;
				m_transparency = 255;
				m_FPScounter = 0;
			}
			else
			{
				m_IsExit = false;
				m_transparency = 255;
				m_FPScounter = 0;
			}
		}

		//!< メニュー画面もしくはゲーム終了への遷移処理
		if (inpt->GetKey(KEY_INFO::ENTER_KEY) == true || inpt->GetGamePadBottonState(0, GAMEPAD_BUTTONS::A) == INPUT_STATE::PUSH_DOWN)
		{
			if (m_IsExit == false)
			{
				m_DisplayState = DisplayState::PvE;
				m_DisplayNum = (int)DisplayState::PvE;
			}
			else
			{
				PostQuitMessage(0);
			}
		}
	}
	else if (m_DisplayState != DisplayState::Title)
	{
		//!< メニュー画面の処理
		if (inpt->GetKeyDown(KEY_INFO::UP_KEY) == true || inpt->GetGamePadBottonState(0, GAMEPAD_BUTTONS::lUp) == INPUT_STATE::PUSH_DOWN)
		{
			if (m_DisplayNum > 1)
			{
				m_DisplayNum--;
				m_DisplayState = static_cast<DisplayState>(m_DisplayNum);
			}
		}
	
		if (inpt->GetKeyDown(KEY_INFO::DOWN_KEY) == true || inpt->GetGamePadBottonState(0, GAMEPAD_BUTTONS::lDown) == INPUT_STATE::PUSH_DOWN)
		{
			if (m_DisplayNum < 3)
			{
				m_DisplayNum++;
				m_DisplayState = static_cast<DisplayState>(m_DisplayNum);
			}
		}

		if (inpt->GetKey(KEY_INFO::ENTER_KEY) == true || inpt->GetGamePadBottonState(0, GAMEPAD_BUTTONS::A) == INPUT_STATE::PUSH_DOWN)
		{
			if (m_DisplayState != DisplayState::PvP)
			{
				m_IsChange = true;
			}
		}
	}
}

SceneID TitleScene::End()
{
	cTexture* tex = cTexture::GetTextureInstance();
	tex->ReleaseTexture(title_base);
	tex->ReleaseTexture(menu);
	tex->ReleaseTexture(title_button);

	m_State = SceneState::eInit;

	if (m_DisplayState == DisplayState::PvE)
	{
		return SceneID::eGameScene;
	}
	else if (m_DisplayState == DisplayState::Help)
	{
		return SceneID::eHelpScene;
	}

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
			tex->GetTexture(title_base), 0.9375f, 0.52734375f, 1920.0f, 1080.0f, 1, 1);
		if (m_IsExit == 0)
		{
			graph->DrawIntegratedImage(448.0f, 824.0f,
				tex->GetTexture(title_button), 1.0f, 0.5f, 1024.0f, 128.0f, 1, 1, m_transparency);
			graph->DrawIntegratedImage(448.0f, 952.0f,
				tex->GetTexture(title_button), 1.0f, 0.5f, 1024.0f, 128.0f, 1, 2);
		}
		else
		{
			graph->DrawIntegratedImage(448.0f, 824.0f,
				tex->GetTexture(title_button), 1.0f, 0.5f, 1024.0f, 128.0f, 1, 1);
			graph->DrawIntegratedImage(448.0f, 952.0f,
				tex->GetTexture(title_button), 1.0f, 0.5f, 1024.0f, 128.0f, 1, 2, m_transparency);
		}
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

	if (m_IsChange == true)
	{
		graph->DrawTexture(m_BambooPosX, 0.0f,
			tex->GetTexture(transition));
	}
}
