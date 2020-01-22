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
	//// 歩く時のカウント
	//if (m_character_state[static_cast<int>(CHARACTER_STATE::IS_WALK)] == true)
	//{
	//	m_character_state[static_cast<int>(CHARACTER_STATE::IS_HOLD_WEAPON)] = false;
	//	m_character_state[static_cast<int>(CHARACTER_STATE::IS_WAIT)] = false;
	//	m_x += 1.0f;
	//	m_walk_count += 0.5f;
	//}
	//// 歩いてきて待機するまでのカウント
	//if (m_character_state[static_cast<int>(CHARACTER_STATE::IS_HOLD_WEAPON)] == true/* &&
	//	m_character_state[static_cast<int>(CHARACTER_STATE::IS_WAIT)] == false*/)
	//{
	//	m_character_state[static_cast<int>(CHARACTER_STATE::IS_WALK)] = false;
	//	m_standby_count += 0.5f;
	//	if (m_standby_count >= 18.0f)
	//	{
	//		m_standby_count = m_reset_count;
	//		m_character_state[static_cast<int>(CHARACTER_STATE::IS_WAIT)] = true;
	//	}
	//}
	//// 待機中の時のカウント
	//if (/*m_character_state[static_cast<int>(CHARACTER_STATE::IS_HOLD_WEAPON)] == true &&*/
	//	m_character_state[static_cast<int>(CHARACTER_STATE::IS_WAIT)] == true)
	//{
	//	m_standby_count = m_reset_count;
	//	m_wait_count += 0.5f;
	//}
	//// 攻撃1回目
	//if (m_character_state[static_cast<int>(CHARACTER_STATE::IS_ATTACK_01)] == true)
	//{
	//	// 攻撃モーションするためのカウント
	//	m_attack_count += 0.5f;
	//	if (m_attack_count >= 10.0f)
	//	{
	//		m_character_state[static_cast<int>(CHARACTER_STATE::IS_ATTACKED)] = true;
	//		m_attack_count = m_reset_count;
	//		m_character_state[static_cast<int>(CHARACTER_STATE::IS_ATTACK_01)] = false;
	//	}
	//}
	//switch ()
	//{
	///*case CHARACTER_STATE::IS_WALK:
	//	m_x += 1.0f;
	//	m_walk_count += 0.5f;*/
	//case CHARACTER_STATE::IS_HOLD_WEAPON:
	//	m_standby_count += 0.5f;
	//	if (m_standby_count >= 18.0f)
	//	{
	//		m_standby_count = m_reset_count;
	//		m_chara_state = CHARACTER_STATE::IS_WAIT;
	//	}
	//case CHARACTER_STATE::IS_WAIT:
	//	m_standby_count = m_reset_count;
	//	m_wait_count += 0.5f;
	//case CHARACTER_STATE::IS_ATTACK_01:
	//	m_attack_count += 0.5f;
	//	if (m_attack_count >= 10.0f)
	//	{
	//		m_chara_state=CHARACTER_STATE::
	//		m_attack_count = m_reset_count;
	//	}
	//}
	//default:
	//	break;
	//}

	// 倒れるときのカウント
	/*if (m_fall_count >= 55.0f)
	{
		m_isdeth = true;
	}*/
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
	cTexture* ctex = cTexture::GetTextureInstance();
	//if (m_isdeth == false)
	//{

	//	if (GetHp() >= 1)
	//	{
	//		if (m_character_state[static_cast<int>(CHARACTER_STATE::IS_WALK)] == true)
	//		{
	//			Texture* tex = ctex->GetTexture(walk_anime);
	//			Graphics::GetGraphicInstance()->Animation3D(
	//				player,
	//				tex,
	//				0.25f, 0.0625f,
	//				this->m_width, this->m_height,
	//				4,
	//				(int)m_walk_count % (4 * 9)
	//			);
	//		}
	//		if (m_character_state[static_cast<int>(CHARACTER_STATE::IS_HOLD_WEAPON)] == true/* &&
	//			m_character_state[static_cast<int>(CHARACTER_STATE::IS_WAIT)] == false*/)
	//		{
	//			Texture* tex = ctex->GetTexture(walk_wait_anime);
	//			Graphics::GetGraphicInstance()->Animation3D(
	//				player,
	//				tex,
	//				0.25f, 0.125f,
	//				this->m_width, this->m_height,
	//				4,
	//				(int)m_standby_count % ((4 * 4) + 2)
	//			);
	//		}
	//		if (/*m_character_state[static_cast<int>(CHARACTER_STATE::IS_HOLD_WEAPON)] == true &&*/
	//			m_character_state[static_cast<int>(CHARACTER_STATE::IS_WAIT)] == true)
	//		{
	//			Texture* tex = ctex->GetTexture(wait_anime);
	//			Graphics::GetGraphicInstance()->Animation3D(
	//				player,
	//				tex,
	//				0.25f, 0.0625f,
	//				this->m_width, this->m_height,
	//				4,
	//				(int)m_wait_count % ((4 * 8) + 2)
	//			);
	//		}
	//		if (m_character_state[static_cast<int>(CHARACTER_STATE::IS_ATTACK_01)] == true)
	//		{
	//			Texture* tex = ctex->GetTexture(attack1_anime);
	//			Graphics::GetGraphicInstance()->Animation3D(
	//				player,
	//				tex,
	//				0.25f, 0.25f,
	//				this->m_width, this->m_height,
	//				4,
	//				(int)m_attack_count % ((4 * 2) + 2)
	//			);
	//		}
	//	}
	//	else
	//	{
	//		Texture* tex = ctex->GetTexture(player_die_anime);
	//		Graphics::GetGraphicInstance()->Animation3D(
	//			player,
	//			tex,
	//			0.25, 0.0625,
	//			this->m_width, this->m_height,
	//			4,
	//			(int)m_fall_count % ((4 * 13) + 3)
	//		);
	//	}
	//}
	//else
	//{

	//}
}