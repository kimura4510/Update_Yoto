#include"TestUpdate.h"
#include"3DLibrary/3DLibrary/Engine/Graphics.hpp"



void TestUpdate::Update() {

	m_callout_ui.Update();
	m_hp_ui.Update();
}

void TestUpdate::Draw() {

	//シーン描画
	if (Graphics::GetGraphicInstance()->DrawStart() == false)
	{
		return;
	}

	m_callout_ui.Draw();
	m_hp_ui.Draw();


	Graphics::GetGraphicInstance()->DrawEnd();

}