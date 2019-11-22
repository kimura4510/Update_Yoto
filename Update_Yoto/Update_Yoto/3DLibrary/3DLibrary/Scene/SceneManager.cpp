#include "SceneManager.hpp"
#include "../Engine/Input.hpp"
#include "HelpScene.hpp"
#include "TitleScene.hpp"
#include "GameScene.hpp"
#include "NonScene.hpp"

SceneManager::SceneManager()
{
	m_SceneID = SceneID::eTitleScene;
	m_CurrentScene = new TitleScene;
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
	SceneID id;
	id = m_CurrentScene->Control();
	ChangeScene(id);
}

//描画関数
void SceneManager::Draw()
{
	m_CurrentScene->Draw();
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