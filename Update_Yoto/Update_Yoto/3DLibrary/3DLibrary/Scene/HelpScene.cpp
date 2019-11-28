#include "HelpScene.hpp"
#include "../Engine/Graphics.hpp"
#include "../Engine/Input.hpp"

HelpScene::~HelpScene()
{

}

void HelpScene::Init()
{
	m_State = SceneState::eMain;
}

void HelpScene::Update()
{
	m_State = SceneState::eEnd;
}

void HelpScene::Draw()
{

}

SceneID HelpScene::End()
{
	return SceneID::eTitleScene;
}