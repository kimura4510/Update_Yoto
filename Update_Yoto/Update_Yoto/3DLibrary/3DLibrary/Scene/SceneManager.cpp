#include "SceneManager.hpp"
#include "../Engine/Graphics.hpp"
#include "../Engine/Input.hpp"
#include "HelpScene.hpp"
#include "TitleScene.hpp"
#include "GameScene.hpp"
#include "../Texture/Texture.hpp"


SceneManager::SceneManager()
{
	cTexture::GetTextureInstance()->LoadTexture("Resource/Character/walk.png","walk");
	Init(SceneID::eTitleScene);
	m_CurrentScene = m_SceneList[(int)m_SceneID];
	
}

SceneManager::~SceneManager()
{

}

//初期化関数
void SceneManager::Init(SceneID id)
{
	m_SceneList.push_back(new TitleScene());
	m_SceneList.push_back(new GameScene());
	m_SceneList.push_back(new HelpScene());

	m_SceneID = SceneID::eTitleScene;
}

//終了関数
void SceneManager::End()
{
	for (auto scene : m_SceneList)
	{
		BaseScene* base = scene;
		delete base;
	}
	m_SceneList.clear();
}

//更新関数
void SceneManager::Update()
{
	Input::GetInputInstance()->KeyStateUpdate();

	SceneID id;
	id = m_CurrentScene->Control();
	ChangeScene(id);
}

//描画関数
void SceneManager::Draw()
{
	if (m_CurrentScene->IsMainStep() == false)
	{
		return;
	}
	if (Graphics::GetGraphicInstance()->DrawStart() == false)
	{
		return;
	}




	m_CurrentScene->Draw();

	Graphics::GetGraphicInstance()->DrawEnd();
}

//シーン変更関数
void SceneManager::ChangeScene(SceneID nextScene_)
{
	if (nextScene_ != m_SceneID)
	{
		m_SceneID = nextScene_;
	}
	m_CurrentScene = m_SceneList[(int)m_SceneID];
}

//ゲーム終了関数
bool SceneManager::IsGameEnd()
{
	if (Input::GetInputInstance()->GetKey(KEY_INFO::ESCAPE_KEY) == true)
	{
		return true;
	}
	return false;
}