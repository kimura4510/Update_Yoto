#include "TitleScene.hpp"
#include "Texture.hpp"
#include "../Engine/Input.hpp"
#include "../Engine/Graphics.hpp"

// �^�C�g���V�[���̏�����
void TITLESCENE::InitTitleScene()
{
	TEXTURE Texture;
	SCENE Scene;

	Texture.LoadTexture("Res/title.png", TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleBgTex);
	Texture.LoadTexture("Res/frame.png", TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleObject);

	Scene.ChangeSceneStep(SceneStep::MainStep);
};

//�^�C�g���V�[���̃��C������
void TITLESCENE::MainTitleScene()
{
	SCENE Scene;

	if (Input::GetInputInstance()->GetKeyDown(KEY_INFO::UP_KEY) == true)
	{
		IsNextScene = true;
	}
	if (Input::GetInputInstance()->GetKeyDown(KEY_INFO::DOWN_KEY) == true)
	{
		IsNextScene = false;
	}

	if (Input::GetInputInstance()->GetKeyDown(KEY_INFO::SPACE_KEY) == true)
	{
		Scene.ChangeSceneStep(SceneStep::EndStep);
	}

	if (Input::GetInputInstance()->GetKeyDown(KEY_INFO::ESCAPE_KEY) == true)
	{
		IsGameEnd = true;
		Scene.ChangeSceneStep(SceneStep::EndStep);
	}
}

//�^�C�g���V�[���̏I��
SceneID TITLESCENE::FinishTitleScene()
{
	TEXTURE Texture;
	Texture.ReleaseCategoryTexture(TEXTURE_CATEGORY_TITLE);

	if (IsNextScene == true)
		return SceneID::GameScene;
	else
		return SceneID::HelpScene;

}

SceneID TITLESCENE::UpdateTitleScene()
{
	SCENE Scene;

	switch (Scene.GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitTitleScene();
		break;
	case SceneStep::MainStep:
		MainTitleScene();
		break;
	case SceneStep::EndStep:
		return FinishTitleScene();
		break;
	}

	return SceneID::TitleScene;
}

void TITLESCENE::DrawTitleScene()
{
	TEXTURE Texture;

	Graphics::GetGraphicInstance()->DrawTexture(0.0f, 0.0f, Texture.GetTexture(TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleBgTex));
}

bool TITLESCENE::EndCheck()
{
	if (IsGameEnd == true)
	{
		return true;
	}
	return false;
}