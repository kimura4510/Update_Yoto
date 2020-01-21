#include "Player.h"
#include "../../3DLibrary/3DLibrary/Texture/Texture.hpp"
#include "../../3DLibrary/3DLibrary/Engine/Input.hpp"
#include "../../3DLibrary/3DLibrary/Engine/Graphics.hpp"

Player::Player() : Character()
{
	m_isdeth = false;
	m_x = 0.0f;		// 「player.png」の描画だけなら→ //128.0f;
	m_y = 0.0f;
	m_z = 512.0f;			// 「player.png」の描画だけなら→ //256.0f;
	m_width = 256.0f;
	m_height = 256.0f;

	m_hp = 3;

	m_standby_count = 0;
}

void Player::Update()
{
	if (m_approach == true)
	{
		m_x += 2.0f;
		m_up_count += 0.5f;
	}
	if (m_walk_to_standby == true && m_standby == false)
	{
		m_standby_count += 0.5f;
		if (m_standby_count >= 18.0f)
		{
			m_standby_count = m_reset_count;
			m_walk_to_standby = false;
			m_standby = true;
		}
	}
	if (m_walk_to_standby == true && m_standby == true)
	{
		m_standby_count += 0.5f;
	}

	if (GetHp() <= 0)
	{
		m_isdeth == true;
		if (m_up_count <= 55.0f)
		{
			m_up_count += 0.5f;
			m_dead = true;
		}
	}
}

void Player::Draw()
{
	DrawingData3D player{
		this->m_x, this->m_y, this->m_z,
		0.0f,0.0f,
		this->m_width,this->m_height,
		0xffff,
		0.0f,0.0f,0.0f,
		0.5f,0.5f,
	};
	if (m_isdeth == false)
	{
		cTexture* ctex = cTexture::GetTextureInstance();

		if (m_approach == true)
		{
			Texture* tex = ctex->GetTexture(walk_anime);
			Graphics::GetGraphicInstance()->Animation3D(
				player,
				tex,
				0.25f, 0.0625f,
				this->m_width, this->m_height,
				4,
				(int)m_up_count % (4 * 9)
			);
		}
		if (m_walk_to_standby == true && m_standby == false)
		{
			Texture* tex = ctex->GetTexture(walk_to_standby_anime);
			Graphics::GetGraphicInstance()->Animation3D(
				player,
				tex,
				0.25f, 0.125f,
				this->m_width, this->m_height,
				4,
				(int)m_standby_count % (4 * 4) + 2
			);
		}
		if (m_walk_to_standby == true && m_standby == true)
		{
			Texture* tex = ctex->GetTexture(standby_anime);
			Graphics::GetGraphicInstance()->Animation3D(
				player,
				tex,
				0.25f, 0.0625f,
				this->m_width, this->m_height,
				4,
				(int)m_standby_count % (4 * 8) + 2
			);
		}
	}
}