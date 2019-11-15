#include "Texture.hpp"
#include "../Engine/Graphics.hpp"
#include "../Engine/Input.hpp"
#include "HelpScene.hpp"

//�w���v�V�[���̏�����
void HELPSCENE::InitHelpScene()
{
	TEXTURE Texture;
	SCENE Scene;

	Texture.LoadTexture("Res/help1.png", TEXTURE_CATEGORY_HELP, HelpCategoryTextureList::Help1);

	Scene.ChangeSceneStep(SceneStep::MainStep);
}

//�w���v�V�[���̃��C��
void HELPSCENE::MainHelpScene()
{
	SCENE Scene;

	if (Input::GetInputInstance()->GetKeyDown(KEY_INFO::ESCAPE_KEY) == true)
	{
		Scene.ChangeSceneStep(SceneStep::EndStep);
	}
}

//�w���v�V�[���̏I��
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