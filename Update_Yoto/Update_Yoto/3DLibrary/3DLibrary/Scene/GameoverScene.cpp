#include "GameoverScene.hpp"
#include "../Engine/Graphics.hpp"
#include "../Engine/Input.hpp"
#include "../Texture/Texture.hpp"

void GameoverScene::Init()
{
	cTexture* tex = cTexture::GetTextureInstance();
	tex->LoadTexture("Resource/GameEnd/Lose1.png", lose);

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
	return SceneID::eGameoverScene;
}

SceneID GameoverScene::End()
{
	cTexture* tex = cTexture::GetTextureInstance();
	tex->ReleaseTexture(lose);

	m_State = SceneState::eInit;
	return SceneID::eTitleScene;
}

void GameoverScene::Draw()
{
	Graphics* gp = Graphics::GetGraphicInstance();
	cTexture* tex = cTexture::GetTextureInstance();
	gp->DrawTexture(0.0f, 0.0f, tex->GetTexture(lose));
}