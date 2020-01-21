#include "Perry.h"
#include "../../../3DLibrary/3DLibrary/Texture/Texture.hpp"

Perry::Perry() : Enemy()
{
	m_isdeth = false;
	m_x = 1280.0f;
	m_y = 0.0f;
	m_z = 512.0f;
	m_width = 256.0f;
	m_height = 256.0f;

	m_hp = 3;
	m_quick_press_flame = 42;
}

void Perry::Draw()
{
	DrawingData3D perry{
			this->m_x, this->m_y, this->m_z,
			0.0f,0.0f,
			this->m_width, this->m_height,
			0xffff,
			0.0f,180.0f,180.0f,
			0.5f,0.5f,
	};
	if (m_isdeth == false)
	{
		cTexture* ctex = cTexture::GetTextureInstance();
		Texture* tex = ctex->GetTexture(perry_wait_anime);
		Graphics::GetGraphicInstance()->Animation3D(
			perry,
			tex,
			0.25, 0.0625,
			this->m_width, this->m_height,
			4,
			(int)m_up_count % (4 * 8) + 2
		);
	}
	else
	{
		cTexture* ctex = cTexture::GetTextureInstance();
		Texture* tex = ctex->GetTexture(perry_die_anime);
		Graphics::GetGraphicInstance()->Animation3D(
			perry,
			tex,
			0.25, 0.0625,
			this->m_width, this->m_height,
			4,
			(int)m_up_count % (4 * 13) + 3
		);
	}
}