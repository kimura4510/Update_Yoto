#include "GameScene.hpp"
#include "../Engine/Graphics.hpp"
#include "../Engine/Input.hpp"
#include "../Engine/Camera.h"

GameScene::GameScene()
{

}

GameScene::~GameScene()
{

}

void GameScene::Init()
{
	m_State = SceneState::eMain;
	Camera::CreateInstance();
	Camera::GetCameraInstance()->InitCamera();
}

void GameScene::Update()
{
	Camera::GetCameraInstance()->UpdateCamera();
}

SceneID GameScene::End()
{
	Camera::GetCameraInstance()->ReleaseCamera();
	Camera::DestroyInstance();
	m_State = SceneState::eInit;
	return SceneID::eTitleScene;
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

}