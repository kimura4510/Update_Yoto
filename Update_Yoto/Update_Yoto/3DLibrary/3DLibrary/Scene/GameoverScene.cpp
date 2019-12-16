#include "GameoverScene.hpp"
#include "../Engine/Graphics.hpp"
#include "../Engine/Input.hpp"
#include "../Texture/Texture.hpp"

void GameoverScene::Init()
{
	cTexture* tex = cTexture::GetTextureInstance();
	m_State = SceneState::eMain;
}

void GameoverScene::Update()
{
	if (Input::GetInputInstance()->GetKeyDown(KEY_INFO::ENTER_KEY) == true)
	{
		m_State = SceneState::eEnd;
	}
}

SceneID GameoverScene::Control()
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

SceneID GameoverScene::End()
{
	m_State = SceneState::eInit;
	return SceneID::eTitleScene;
}

void GameoverScene::Draw()
{

}