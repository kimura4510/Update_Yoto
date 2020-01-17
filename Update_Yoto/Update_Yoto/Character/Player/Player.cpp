#include "Player.h"
#include "../../3DLibrary/3DLibrary/Texture/Texture.hpp"
#include "../../3DLibrary/3DLibrary/Engine/Input.hpp"
#include "../../3DLibrary/3DLibrary/Engine/Graphics.hpp"

Player::Player() : Character()
{
	m_isdeth = false;
	m_x = -256.0f;		// 「player.png」の描画だけなら→ //128.0f;
	m_y = 100.0f;
	m_z = -256.0f;		// 「player.png」の描画だけなら→ //256.0f;
	m_width = 150.0f;
	m_height = 170.0f;

	m_hp = 3;
	m_count = 0;
}

void Player::Update()
{
	if (m_approach == true)
	{
		m_x += 3.0f;
		m_count += 0.5f;
	}

	if (GetHp() <= 0)
	{
		m_isdeth == true;
	}
}

void Player::Draw()
{
	DrawingData3D player{
			this->m_x, this->m_y, this->m_z,
			0.0f,0.0f,
			this->m_width,this->m_height,
			0xffff,
			0.0f,180.0f,180.0f,
			0.5f,0.5f,
	};
	if (m_isdeth == false)
	{
		cTexture* ctex = cTexture::GetTextureInstance();
		Texture* tex = ctex->GetTexture(chara_anime);

		Graphics::GetGraphicInstance()->Animation3D(
			player,
			tex,
			0.0625f, 0.125f,
			150.0f, 170.0f,
			16,
			(int)m_count % (16 * 2) + 4
		);
	}
}