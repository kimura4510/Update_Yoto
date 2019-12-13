#include "Perry.h"
#include "../../../3DLibrary/3DLibrary/Texture/Texture.hpp"

Perry::Perry()
{
	Init();
}

void Perry::Init()
{
	m_isdeth			= false;
	m_x					= 128.0f;
	m_y					= -256.0f;
	m_z					= 100.0f;
	m_hp				= 3;
	m_quick_press_flame = 42;
}

void Perry::Draw()
{
	if (m_isdeth == false)
	{
		DrawingData3D perry{
			this->m_x, this->m_y, this->m_z,
			0.0f,0.0f,
			128.0f,128.0f,
			0xffff,
			0.0f,0.0f,0.0f,
			0.5f,0.5f,
		};
		Graphics* gp = Graphics::GetGraphicInstance();
		cTexture* tex = cTexture::GetTextureInstance();
		gp->Draw3D(perry, tex->GetTexture(perry_tex));
	}
}

void Perry::Update()
{
	if (GetHp() <= 0)
	{
		m_isdeth == true;
		ChangeEnemy(ENEMY_ID::HERMIT);
	}
}

int Perry::GetQuickPressFlame()
{
	return m_quick_press_flame;
}

void Perry::QuickPressFlameDown()
{
	m_quick_press_flame--;
}

int Perry::GetHp()
{
	return m_hp;
}

void Perry::HpDown()
{
	m_hp--;
}

//bool Perry::PlayerHpDown()
//{
//	return true;
//}