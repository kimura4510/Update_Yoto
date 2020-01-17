#include "Perry.h"
#include "../../../3DLibrary/3DLibrary/Texture/Texture.hpp"

Perry::Perry() : Enemy()
{
	m_isdeth = false;
	m_x = 128.0f;
	m_y = 100.0f;
	m_z = -256.0f;
	m_width = 150.0f;
	m_height = 170.0f;

	m_hp = 3;
	m_quick_press_flame = 42;
}

void Perry::Draw()
{
	if (m_isdeth == false)
	{
		DrawingData3D perry{
			this->m_x, this->m_y, this->m_z,
			0.0f,0.0f,
			this->m_width, this->m_height,
			0xffff,
			0.0f,180.0f,180.0f,
			0.5f,0.5f,
		};
		Graphics* gp = Graphics::GetGraphicInstance();
		cTexture* tex = cTexture::GetTextureInstance();
		gp->Draw3D(perry, tex->GetTexture(perry_tex));
	}
}