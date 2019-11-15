#include "SceneManager.hpp"
#include "GameScene.hpp"
#include "HelpScene.hpp"
#include "TitleScene.hpp"
#include "..//Engine/Input.hpp"

SceneManager::SceneManager() : m_NextScene(Non_Scene)
{
	m_Scene = (BaseScene*) new TitleScene(this);
}

//初期化関数
void SceneManager::Init()
{
	m_Scene->Init();
}

//終了関数
void SceneManager::End()
{
	m_Scene->End();
}

//更新関数
void SceneManager::Update()
{
	if (m_NextScene != Non_Scene)
	{
		m_Scene->End();
		switch (m_NextScene)
		{
		case SceneID::eTitleScene:
			m_Scene = (BaseScene*) new TitleScene(this);
			break;
		case SceneID::eGameScene:
			m_Scene = (BaseScene*) new GameScene(this);
			break;
		case SceneID::eHelpScene:
			m_Scene = (BaseScene*) new HelpScene(this);
			break;
		//case SceneID::eGameoverScene:
		//	m_Scene = (BaseScene*) new GameoverScene(this);
		//	break;
		}
		m_NextScene = SceneID::eNon_Scene;
		m_Scene->Init();
	}

	m_Scene->Update();
}

//描画関数
void SceneManager::Draw()
{
	m_Scene->Draw();
}

//シーン変更関数
void SceneManager::ChangeScene(SceneID nextScene_)
{
	m_NextScene = nextScene_;
}

//ゲーム終了関数
bool SceneManager::IsGameEnd()
{
	if (GetInputInstance()->GetKey(KEY_INFO::ESCAPE_KEY) == true)
	{
		return true;
	}
	return false;
}