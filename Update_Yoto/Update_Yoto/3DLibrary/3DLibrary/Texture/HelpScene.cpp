#include "Texture.hpp"
#include "../Engine/Graphics.hpp"
#include "../Engine/Input.hpp"
#include "HelpScene.hpp"

//ヘルプシーンの初期化
void HELPSCENE::InitHelpScene()
{
	TEXTURE Texture;
	SCENE Scene;

	Texture.LoadTexture("Res/help1.png", TEXTURE_CATEGORY_HELP, HelpCategoryTextureList::Help1);

	Scene.ChangeSceneStep(SceneStep::MainStep);
}

//ヘルプシーンのメイン
void HELPSCENE::MainHelpScene()
{
	SCENE Scene;

	if (Input::GetInputInstance()->GetKeyDown(KEY_INFO::ESCAPE_KEY) == true)
	{
		Scene.ChangeSceneStep(SceneStep::EndStep);
	}
}

//ヘルプシーンの終了
SceneID HELPSCENE::FinishHelpScene()
{
	TEXTURE Texture;

	Texture.ReleaseCategoryTexture(TEXTURE_CATEGORY_HELP);

	return SceneID::TitleScene;
}

SceneID HELPSCENE::UpdateHelpScene()
{
	SCENE Scene;

	switch (Scene.GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitHelpScene();
		break;
	case SceneStep::MainStep:
		MainHelpScene();
		break;
	case SceneStep::EndStep:
		return FinishHelpScene();
		break;
	}

	return SceneID::HelpScene;
}

void HELPSCENE::DrawHelpScene()
{
	TEXTURE Texture;

	Graphics::GetGraphicInstance()->DrawTexture(0, 0, Texture.GetTexture(TEXTURE_CATEGORY_HELP, HelpCategoryTextureList::Help1));
}