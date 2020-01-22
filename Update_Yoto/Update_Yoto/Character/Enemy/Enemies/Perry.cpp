#include "Perry.h"
#include "../../../3DLibrary/3DLibrary/Texture/Texture.hpp"

Perry::Perry() : Enemy()
{
	m_isdeth = false;
	m_x = 512.0f;
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
			0.0f, 0.0f,0.0f,
			0.5f,0.5f,
	};
	cTexture* ctex = cTexture::GetTextureInstance();
	if (m_isdeth == false)
	{
		if (GetHp() >= 1)
		{
			if (m_wait == true)
			{
				cTexture* ctex = cTexture::GetTextureInstance();
				Texture* tex = ctex->GetTexture(perry_wait_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					perry,
					tex,
					0.25, 0.0625,
					this->m_width, this->m_height,
					4,
					(int)m_wait_count % ((4 * 8) + 2)
				);
			}
			if (m_attack1 == true)
			{
				Texture* tex = ctex->GetTexture(perry_attack1_anime);
				Graphics::GetGraphicInstance()->Animation3D(
					perry,
					tex,
					0.25f, 0.25f,
					this->m_width, this->m_height,
					4,
					(int)m_attack_count % ((4 * 2) + 2)
				);
			}
		}
		else
		{
			Texture* tex = ctex->GetTexture(perry_die_anime);
			Graphics::GetGraphicInstance()->Animation3D(
				perry,
				tex,
				0.25, 0.0625,
				this->m_width, this->m_height,
				4,
				(int)m_fall_count % ((4 * 13) + 3)
			);
		}
	}
	else
	{
		
	}
}