#include "TitleScene.hpp"
#include "../Engine/Input.hpp"
#include "../Engine/Graphics.hpp"
#include "../Texture/Texture.hpp"

//‰Šú‰»
void TitleScene::Init()
{
	m_State = SceneState::eMain;

	cTexture::GetTextureInstance()->LoadTexture("3DLibrary/3DLibrary/Res/title.png",
		TextureCategory::TitleCategory,
		(int)TitleCategoryTextureList::Background);
}

//XV
void TitleScene::Update()
{
	if (Input::GetInputInstance()
		->GetKey(KEY_INFO::ENTER_KEY) == true)
	{
		m_State = SceneState::eEnd;
	}
}

SceneID TitleScene::End()
{
	cTexture::GetTextureInstance()->ReleaseCategoryTexture((int)TextureCategory::TitleCategory);

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
	Graphics::GetGraphicInstance()->DrawTexture(
		0.0f, 
		0.0f,
		cTexture::GetTextureInstance()
		->GetTexture(
		TextureCategory::TitleCategory,
		(int)TitleCategoryTextureList::Background));
}
