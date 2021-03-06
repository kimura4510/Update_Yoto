#include "GameScene.hpp"
#include "../Engine/Graphics.hpp"
#include "../Engine/Input.hpp"
#include "../Engine/Camera.h"
#include "../Texture/Texture.hpp"
#include "../GameDefinition.h"
#include "../../../LoadResources/LoadResources.h"
#include "../../../DataBank/DataBank.h"

void GameScene::Init()
{
	m_end_scene = END_SCENE::GAME_NONE;

	m_State = SceneState::eMain;
	Camera::CreateInstance();
	Camera::GetCameraInstance()->InitCamera(512.0f, 192.0f, 128.0f, 512.0f, 32.0f, 1024.0f);

	LoadResources::Load();

	m_chmanager.Init();
}

void GameScene::Update()
{
	Camera::GetCameraInstance()->UpdateCamera();

	Input* input = Input::GetInputInstance();

	m_chmanager.Update();
	if (m_chmanager.IsBattleFinish() == false)
	{
		// トランジションシーン画像が画面外(左側)に出たかどうか判定
		if (m_bg.TransitionSceneLower() == true)
		{
			if (m_chmanager.StandBy() == false)
			{
				m_chmanager.PlayerStandBy();
			}
		}
		else
		{
			m_bg.MoveTransitionScene();	// 左に動かす
		}
	}
	

	if (m_chmanager.IsBattleFinish() == true)
	{
		m_bg.TransitionSceneSetToRight();
		if (m_bg.TransitionSceneInstall() == false)
		{
			m_bg.MoveTransitionScene();	// 左に動かす
		}
		else
		{
			switch (m_chmanager.GetGameEnd())
			{
			case GAME_END::GAME_CLEAR:
				// ゲームクリアシーンに移行
				m_end_scene = END_SCENE::GAME_CLEAR;
				m_State = SceneState::eEnd;
				break;
			case GAME_END::GAME_OVER:
				// ゲームオーバーシーンに移行
				m_end_scene = END_SCENE::GAME_OVER;
				m_State = SceneState::eEnd;
				break;
			case GAME_END::GAME_NONE:
				// トランジションシーンに移行
				m_end_scene = END_SCENE::GAME_NONE;
				m_State = SceneState::eEnd;
				m_chmanager.ChangeNextEnemy();
				break;
			}
			m_chmanager.DeleteCheck();
		}
	}
}

SceneID GameScene::End()
{
	Camera::GetCameraInstance()->ReleaseCamera();
	Camera::DestroyInstance();

	m_State = SceneState::eInit;

	// GameEnd処理
	if (m_end_scene == END_SCENE::GAME_CLEAR)
	{
		return SceneID::eClearScene;
	}
	if (m_end_scene == END_SCENE::GAME_OVER)
	{
		return SceneID::eGameoverScene;
	}
	if (m_end_scene == END_SCENE::GAME_NONE)
	{
		return SceneID::eTransitionScene;
	}
}

SceneID GameScene::Control()
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
	return SceneID::eGameScene;
}

void GameScene::Draw()
{
	if (m_State != SceneState::eMain)
	{
		return;
	}
	m_bg.Draw();
	m_chmanager.Draw();
	m_bg.TransitionDraw();
}