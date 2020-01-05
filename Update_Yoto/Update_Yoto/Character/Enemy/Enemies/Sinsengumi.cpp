#include "Sinsengumi.h"
#include "../../../3DLibrary/3DLibrary/Texture/Texture.hpp"

Sinsengumi::Sinsengumi()
{
	Init();
}

void Sinsengumi::Init()
{
	m_isdeth			= false;
	m_x					= -256.0f;
	m_y					= 100.0f;
	m_z					= 256.0f;
	m_hp				= 4;
	m_quick_press_flame = 18;
}

void Sinsengumi::Draw()
{
	if (m_isdeth == false)
	{
		DrawingData3D sinsengumi{
			this->m_x, this->m_y, this->m_z,
			0.0f,0.0f,
			150.0f,170.0f,
			0xffff,
			0.0f,0.0f,180.0f,
			0.5f,0.5f,
		};
		Graphics* gp = Graphics::GetGraphicInstance();
		cTexture* tex = cTexture::GetTextureInstance();
		gp->Draw3D(sinsengumi, tex->GetTexture(sinsengumi_tex));
	}
}

void Sinsengumi::Update()
{
	if (GetHp() <= 0)
	{
		m_isdeth == true;
	}
}