#include "ClearScene.hpp"
#include "../Engine/Input.hpp"
#include "../Engine/Graphics.hpp"
#include "../Texture/Texture.hpp"

void ClearScene::Init()
{
	cTexture* tex = cTexture::GetTextureInstance();
	m_State = SceneState::eMain;
}

void ClearScene::Update()
{
	if (Input::GetInputInstance()->GetKeyDown(KEY_INFO::ENTER_KEY) == true)
	{
		m_State = SceneState::eEnd;
	}
}

SceneID ClearScene::End()
{
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
	Graphics* gr = Graphics::GetGraphicInstance();

}