#include "GameScene.hpp"
#include "../Engine/Graphics.hpp"
#include "../Engine/Input.hpp"
#include "../Engine/Camera.h"
#include "../Texture/Texture.hpp"
#include "../GameDefinition.h"
#include "../../../LoadResources/LoadResources.h"

void GameScene::Init()
{
	m_end_scene = END_SCENE::GAME_NONE;

	m_State = SceneState::eMain;
	Camera::CreateInstance();
	Camera::GetCameraInstance()->InitCamera();
	
	LoadResources::Load();

	m_bg.Init();
	m_chmanager.Init();
}

void GameScene::Update()
{
	Camera::GetCameraInstance()->UpdateCamera();

	m_chmanager.Update();

	if (m_chmanager.IsBattleFinish() == true)
	{
		switch (m_chmanager.GetGameEnd())
		{
		case GAME_END::GAME_CLEAR:
			// �Q�[���N���A�V�[���Ɉڍs
			m_end_scene = END_SCENE::GAME_CLEAR;
			m_State = SceneState::eEnd;
			break;
		case GAME_END::GAME_OVER:
			// �Q�[���I�[�o�[�V�[���Ɉڍs
			m_end_scene = END_SCENE::GAME_OVER;
			m_State = SceneState::eEnd;
			break;
		case GAME_END::GAME_NONE:
			// �X�e�[�W�ڍs�V�[���Ɉڍs
			// �g�����W�V�����V�[���Ɉڍs
			m_chmanager.ChangeNextEnemy();

			break;
		}
	}

	m_chmanager.DeleteCheck();
}

SceneID GameScene::End()
{
	Camera::GetCameraInstance()->ReleaseCamera();
	Camera::DestroyInstance();

	// GameEnd����
	if (m_end_scene == END_SCENE::GAME_CLEAR)
	{
		return SceneID::eClearScene;
	}
	if (m_end_scene == END_SCENE::GAME_OVER)
	{
		return SceneID::eGameoverScene;
	}
	 
	//m_State = SceneState::eInit;

	//return SceneID::eTitleScene;
}

SceneID GameScene::Control()
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
	return SceneID::eGameScene;
}

void GameScene::Draw()
{
	if (m_State != SceneState::eMain)
	{
		return;
	}
	// �o�b�N�O���E���h
	m_bg.Draw();

	m_chmanager.Draw();
}