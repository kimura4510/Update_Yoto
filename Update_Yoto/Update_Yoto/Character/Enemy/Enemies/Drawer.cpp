#include "Drawer.h"
#include "../../../3DLibrary/3DLibrary/Texture/Texture.hpp"

Drawer::Drawer()
{
	Init();
}

void Drawer::Init()
{
	m_isdeth			= false;
	m_x					= -256.0f;
	m_y					= 100.0f;//-256.0f;
	m_z					= 256.0f;
	m_hp				= 3;
	m_quick_press_flame = 60;
	m_reset = 0;
	m_reset = m_quick_press_flame;
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

		drawer.m_rotz = 180.f;

		Graphics* gp = Graphics::GetGraphicInstance();
		cTexture* tex = cTexture::GetTextureInstance();
		Texture* p_tex = tex->GetTexture(drawer_tex);

		gp->Draw3D(drawer, p_tex);
	}
}

void Drawer::Update()
{
	/*if (m_reset <= 0)
	{
		m_reset = m_quick_press_flame;
	}*/

	if (this->GetHp() <= 0)
	{
		m_isdeth == true;
		ChangeEnemy(ENEMY_ID::PERRY);
	}
}

int Drawer::GetQuickPressFlame()
{
	return m_quick_press_flame;//m_reset;
}

void Drawer::QuickPressFlameDown()
{
	//m_reset--;
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