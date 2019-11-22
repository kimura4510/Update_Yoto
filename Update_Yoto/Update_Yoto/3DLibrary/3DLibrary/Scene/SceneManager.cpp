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

//�������֐�
void SceneManager::Init(SceneID id)
{
	m_SceneList.push_back(new TitleScene());
	m_SceneList.push_back(new GameScene());
	m_SceneList.push_back(new HelpScene());

	m_SceneID = SceneID::eTitleScene;
}

//�I���֐�
void SceneManager::End()
{
	for (auto scene : m_SceneList)
	{
		BaseScene* base = scene;
		delete base;
	}
	m_SceneList.clear();
}

//�X�V�֐�
void SceneManager::Update()
{
	SceneID id;
	id = m_CurrentScene->Control();
	ChangeScene(id);
}

//�`��֐�
void SceneManager::Draw()
{
	m_CurrentScene->Draw();
}

//�V�[���ύX�֐�
void SceneManager::ChangeScene(SceneID nextScene_)
{
	if (nextScene_ != m_SceneID)
	{
		m_SceneID = nextScene_;
	}
	m_CurrentScene = m_SceneList[(int)m_SceneID];
}

//�Q�[���I���֐�
bool SceneManager::IsGameEnd()
{
	if (Input::GetInputInstance()->GetKey(KEY_INFO::ESCAPE_KEY) == true)
	{
		return true;
	}
	return false;
}