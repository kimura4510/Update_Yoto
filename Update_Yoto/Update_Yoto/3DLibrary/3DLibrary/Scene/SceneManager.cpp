#include "SceneManager.hpp"
#include "GameScene.hpp"
#include "HelpScene.hpp"
#include "TitleScene.hpp"
#include "..//Engine/Input.hpp"

SceneManager::SceneManager() : m_NextScene(Non_Scene)
{
	m_Scene = (BaseScene*) new TitleScene(this);
}

//�������֐�
void SceneManager::Init()
{
	m_Scene->Init();
}

//�I���֐�
void SceneManager::End()
{
	m_Scene->End();
}

//�X�V�֐�
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

//�`��֐�
void SceneManager::Draw()
{
	m_Scene->Draw();
}

//�V�[���ύX�֐�
void SceneManager::ChangeScene(SceneID nextScene_)
{
	m_NextScene = nextScene_;
}

//�Q�[���I���֐�
bool SceneManager::IsGameEnd()
{
	if (GetInputInstance()->GetKey(KEY_INFO::ESCAPE_KEY) == true)
	{
		return true;
	}
	return false;
}