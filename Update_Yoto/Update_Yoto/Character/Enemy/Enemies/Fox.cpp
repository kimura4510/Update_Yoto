#include "Fox.h"
#include "../../../3DLibrary/3DLibrary/Texture/Texture.hpp"

Fox::Fox() : Enemy()
{
	m_isdeth = false;
	m_x = 256.0f;
	m_y = 0.0f;
	m_z = 512.0f;
	m_width = 256.0f;
	m_height = 256.0f;

	m_hp = 4;
	m_quick_press_flame = 12;
}

void Fox::Draw()
{
	if (m_isdeth == false)
	{
		DrawingData3D fox{
			this->m_x, this->m_y, this->m_z,
			0.0f,0.0f,
			this->m_width, this->m_height,
			0xffff,
			0.0f,0.0f,0.0f,
			0.5f,0.5f,
		};
		Graphics* gp = Graphics::GetGraphicInstance();
		cTexture* tex = cTexture::GetTextureInstance();
		gp->Draw3D(fox, tex->GetTexture(fox_tex));
	}
}