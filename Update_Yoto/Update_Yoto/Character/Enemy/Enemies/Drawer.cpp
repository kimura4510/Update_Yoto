#include "Drawer.h"
#include "../../../3DLibrary/3DLibrary/Texture/Texture.hpp"

Drawer::Drawer()
{
	Init();
}

void Drawer::Init()
{
	m_isdeth			= false;
	m_x					= 128.0f;
	m_y					= -256.0f;
	m_z					= 256.0f;
	m_hp				= 3;
	m_quick_press_flame = 60;
}

void Drawer::Draw()
{
	if (m_isdeth == false)
	{
		DrawingData3D drawer = {
			this->m_x, this->m_y, this->m_z,
			0.0f,0.0f,
			150.0f,170.0f,
			0xffff,
			0.0f,0.0f,0.0f,
			0.5f,0.5f,
		};
		Graphics* gp = Graphics::GetGraphicInstance();
		cTexture* tex = cTexture::GetTextureInstance();
		Texture* p_tex = tex->GetTexture(drawer_tex);

		gp->Draw3D(drawer, p_tex);
	}
}

void Drawer::Update()
{
	if (GetHp() <= 0)
	{
		m_isdeth == true;
		ChangeEnemy(ENEMY_ID::PERRY);
	}
}

int Drawer::GetQuickPressFlame()
{
	return m_quick_press_flame;
}

void Drawer::QuickPressFlameDown()
{
	m_quick_press_flame--;
}

int Drawer::GetHp()
{
	return m_hp;
}

void Drawer::HpDown()
{
	m_hp--;
}

//bool Drawer::PlayerHpDown()
//{
//	return true;
//}