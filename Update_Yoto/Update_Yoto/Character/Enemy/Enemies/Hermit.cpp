#include "Hermit.h"
#include "../../../3DLibrary/3DLibrary/Texture/Texture.hpp"

Hermit::Hermit()
{
	Init();
}

void Hermit::Init()
{
	m_isdeth			= false;
	m_x					= -256.0f;
	m_y					= 100.0f;
	m_z					= 256.0f;
	m_hp				= 3;
	m_quick_press_flame = 30;
}

void Hermit::Draw()
{
	if (m_isdeth == false)
	{
		DrawingData3D hermit{
			this->m_x, this->m_y, this->m_z,
			0.0f,0.0f,
			150.0f,170.0f,
			0xffff,
			0.0f,0.0f,180.0f,
			0.5f,0.5f,
		};
		Graphics* gp = Graphics::GetGraphicInstance();
		cTexture* tex = cTexture::GetTextureInstance();
		gp->Draw3D(hermit, tex->GetTexture(hermit_tex));
	}
}

void Hermit::Update()
{
	if (GetHp() <= 0)
	{
		m_isdeth == true;
	}
}