#include "Scene.hpp"
#include "../Engine/Graphics.hpp"
#include "../Engine/Input.hpp"
#include "TitleScene.hpp"
#include "GameScene.hpp"
#include "HelpScene.hpp"

SceneID SCENE::GetCurrentSceneID()
{
	return g_CurrentSceneID;
}

SceneStep SCENE::GetCurrentSceneStep()
{
	return g_CurrentSceneStep;
}

void SCENE::ChangeSceneStep(SceneStep next_step)
{
	g_CurrentSceneStep = next_step;
}

void SCENE::UpdateScene()
{
	GAMESCENE Game;
	TITLESCENE Title;
	HELPSCENE Help;

	Input::GetInputInstance()->KeyStateUpdate();

	SceneID scene_id = g_CurrentSceneID;
	switch (g_CurrentSceneID)
	{
	case SceneID::TitleScene:
		scene_id = Title.UpdateTitleScene();
		break;
	case SceneID::GameScene:
		scene_id = Game.UpdateGameScene();
		break;
	case SceneID::HelpScene:
		scene_id = Help.UpdateHelpScene();
		break;
	}

	DrawScene();

	if (scene_id != g_CurrentSceneID)
	{
		g_CurrentSceneID = scene_id;
		ChangeSceneStep(SceneStep::InitStep);
	}
}

void SCENE::DrawScene()
{
	GAMESCENE Game;
	TITLESCENE Title;
	HELPSCENE Help;

	if (Graphics::GetGraphicInstance()->DrawStart() == false)
	{
		return;
	}
	if (g_CurrentSceneStep == SceneStep::MainStep)
	{
		switch (g_CurrentSceneID)
		{
		case SceneID::TitleScene:
			Title.DrawTitleScene();
			break;
		case SceneID::GameScene:
			Game.DrawGameScene();
			break;
		case SceneID::HelpScene:
			Help.DrawHelpScene();
			break;
		}
	}

	Graphics::GetGraphicInstance()->DrawEnd();
}