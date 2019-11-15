#include "GameScene.hpp"
#include "../Engine/Graphics.hpp"
#include "../Engine/Input.hpp"
#include "../Texture/Texture.hpp"

void GAMESCENE::InitGameScene()
{
	TEXTURE Texture;
	SCENE Scene;

	Texture.LoadTexture("Res/Map.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameBgTex);

	Scene.ChangeSceneStep(SceneStep::MainStep);
}

void GAMESCENE::UpdateStage()
{

}

void GAMESCENE::MainGameScene()
{
	SCENE Scene;

	if (Input::GetInputInstance()->GetKeyDown(KEY_INFO::ESCAPE_KEY) == true)
	{
		Scene.ChangeSceneStep(SceneStep::EndStep);
	}
}

SceneID GAMESCENE::FinishGameScene()
{
	TEXTURE Texture;

	Texture.ReleaseCategoryTexture(TEXTURE_CATEGORY_GAME);

	return SceneID::TitleScene;
}

SceneID GAMESCENE::UpdateGameScene()
{
	SCENE Scene;
	switch (Scene.GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
			InitGameScene();
			break;
	case SceneStep::MainStep:
		MainGameScene();
		break;
	case SceneStep::EndStep:
		return FinishGameScene();
		break;
	}

	return SceneID::GameScene;
}

void GAMESCENE::DrawGameScene()
{
	TEXTURE Texture;

	Graphics::GetGraphicInstance()->DrawTexture(0, 0, Texture.GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameBgTex));
}