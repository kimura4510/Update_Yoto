#include "TitleScene.hpp"
#include "../Engine/Input.hpp"
#include "../Engine/Graphics.hpp"

TitleScene::TitleScene(I_SceneChanger* changer) : BaseScene(changer)
{

}

//������
void TitleScene::Init()
{

}

//�X�V
void TitleScene::Update()
{
	if (Input::GetInputinstance()->GetKey(KEY_INFO::ENTER_KEY) == true)
	{
		m_SceneChanger->ChangeScene(SceneID::eGameScene);
	}

	if (Input::GetInputinstance()->GetKey(KEY_INFO::SPACE_KEY) == true)
	{
		m_SceneChanger->ChangeScene(SceneID::eHelpScene);
	}
}

void TitleScene::Draw()
{
	Graphics::GetGraphicInstance()->DrawTexture(0.0f, 0.0f, GetTexture())
}