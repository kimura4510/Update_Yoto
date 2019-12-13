#include "Fox.h"
#include "../../../3DLibrary/3DLibrary/Texture/Texture.hpp"

Fox::Fox()
{
	Init();
}

void Fox::Init()
{
	m_isdeth			= false;
	m_x					= 128.0f;
	m_y					= -256.0f;
	m_z					= 100.0f;
	m_hp				= 4;
	m_quick_press_flame = 12;
}

void Fox::Draw()
{
	if (m_isdeth == false)
	{
		DrawingData3D fox{
			this->m_x, this->m_y, this->m_z,
			0.0f,0.0f,
			150.0f,170.0f,
			0xffff,
			0.0f,0.0f,0.0f,
			0.5f,0.5f,
		};
		Graphics* gp = Graphics::GetGraphicInstance();
		cTexture* tex = cTexture::GetTextureInstance();
		gp->Draw3D(fox, tex->GetTexture(fox_tex));
	}
}

void Fox::Update()
{
	if (GetHp() <= 0)
	{
		m_isdeth == true;
		GameClear();
	}
}

int Fox::GetQuickPressFlame()
{
	return m_quick_press_flame;
}

void Fox::QuickPressFlameDown()
{
	m_quick_press_flame--;
}

int Fox::GetHp()
{
	return m_hp;
}

void Fox::HpDown()
{
	m_hp--;
}

//bool Fox::PlayerHpDown()
//{
//	return true;
//}