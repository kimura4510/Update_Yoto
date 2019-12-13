#include "Player.h"
#include "../../3DLibrary/3DLibrary/Texture/Texture.hpp"
#include "../../3DLibrary/3DLibrary/Engine/Input.hpp"

Player::Player()
{
	Init();
}



void Player::Init()
{
	m_isdeth	= false;
	m_x			= 128.0f;
	m_y			= 100.0f;
	m_z			= 256.0f;
	m_hp		= 3;
}

void Player::Draw()
{
	if (m_isdeth == false)
	{
		DrawingData3D player{
			this->m_x, this->m_y, this->m_z,
			0.0f,0.0f,
			150.0f,170.0f,
			0xffff,
			0.0f,0.0f,0.0f,
			0.5f,0.5f,
		};
		player.m_rotz = 180.f;

		Graphics* gp = Graphics::GetGraphicInstance();
		cTexture* tex = cTexture::GetTextureInstance();
		gp->Draw3D(player, tex->GetTexture(player_tex));
	}
}

void Player::Update()
{
	/*if (GetHp() <= 0)
	{
		m_isdeth = true;
		GameOver();
	}*/
}

int Player::GetHp()
{
	return m_hp;
}

void Player::HpDown()
{
	m_hp--;
}

//bool Player::EnemyHpDown()
//{
//	return true;
//}