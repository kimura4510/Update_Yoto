#include "GameScene.hpp"
#include "../Engine/Graphics.hpp"
#include "../Engine/Input.hpp"
#include "../Engine/Camera.h"
#include "../Texture/Texture.hpp"
#include "../GameDefinition.h"
#include "../../../LoadResources/LoadResources.h"

void GameScene::Init()
{
	m_State = SceneState::eMain;
	Camera::CreateInstance();
	Camera::GetCameraInstance()->InitCamera();
	
	LoadResources::Load();

	chmanager.Init();
}

void GameScene::Update()
{
	Camera::GetCameraInstance()->UpdateCamera();

	chmanager.Create();
	chmanager.Update();

	//chmanager.Release();

	//chmanager.GameEnd();
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
	if (m_State != SceneState::eMain)
	{
		return;
	}
	// バックグラウンド
	DrawingData3D bg[4];
	// 後ろ
	bg[0] = {
		-256.0f,-128.0f,512.0f,
		0.0f,0.0f,
		512.0f,512.0f,
		0xffff,
		0.0f,0.0f,0.0f,
		1.0f,1.0f,
	};
	// 下
	bg[1] = {
		-256.0f,0.0f,128.0f,
		0.0f,0.0f,
		512.0f,512.0f,
		0xffff,
		90.0f,0.0f,0.0f,
		1.0f,1.0f,
	};
	// 左
	bg[2] = {
		0.0f,-128.0f,256.0f,
		0.0f,0.0f,
		512.0f,512.0f,
		0xffff,
		0.0f,-90.0f,0.0f,
		1.0f,1.0f,
	};
	// 右
	bg[3] = {
		-512.f,-128.f,256.0f,
		0.0f,0.0f,
		512.0f,512.0f,
		0xffff,
		0.0f,90.0f,0.0f,
		1.0f,1.0f,
	};
	Graphics* gp = Graphics::GetGraphicInstance();
	cTexture* tex = cTexture::GetTextureInstance();
	gp->Draw3D(bg[0], tex->GetTexture(background));
	gp->Draw3D(bg[1], tex->GetTexture(background));
	gp->Draw3D(bg[2], tex->GetTexture(background));
	gp->Draw3D(bg[3], tex->GetTexture(background));

	DrawingData3D data;

	chmanager.Draw();
}