#include "Character.h"

Character::Character()
{
	m_isdeth = true;
	m_x = 0;
	m_y = 0;
	m_z = 0;
	m_width = 0.0f;
	m_height = 0.0f;

	m_hp = 0;

	m_quick_press_flame = 0;
	m_quick_press_flame_down = 0;

	for (int i = 0; i < static_cast<int>(CHARACTER_STATE::STATE_MAX); i++)
	{
		m_character_state[i] = false;
	}
	m_anime_count = 0;
	m_reset_count = 0;


	//m_chara_state = CHARACTER_STATE::STATE_MAX;

	/*m_walk_count = 0;
	m_wait_count = 0;
	m_attack_count = 0;
	m_fall_count = 0;*/
	



	// 追加　アニメーション関連　前川
	//! 現在アニメーションをしているカウント
	m_current_anim_num = 0;

	//! アニメーションフレーム数
	m_anim_frame = 0;

	//! アニメーション最大フレーム数
	m_max_anim_frame = 0;

	//! 最大アニメーション枚数(を入れる)
	m_max_anim_num = 0;
}

void Character::AnimationCount() {


	// 最大アニメーションフレームを超えたら
	if (m_anim_frame >= m_max_anim_frame) {

		// 現在アニメーション枚数を加算
		m_current_anim_num++;
	}
	// アニメーション枚数が最大アニメーション枚数を超えたら
	else if (m_current_anim_num >= m_max_anim_num) {

		// アニメーション枚数を元に戻す
		m_current_anim_num = 0;
	}
}

int Character::GetHp()
{
	return m_hp;
}

void Character::HpDown()
{
	m_hp--;
}

void Character::SetQuickPressFlame()
{
	m_quick_press_flame_down = m_quick_press_flame;
}

int Character::GetQuickPressFlame()
{
	return m_quick_press_flame_down;
}

void Character::QuickPressFlameDown()
{
	m_quick_press_flame_down--;
}

void Character::CharacterState(CHARACTER_STATE ch_state_)
{
	for (int i = 0; i < static_cast<int>(CHARACTER_STATE::STATE_MAX); i++)
	{
		if (i == static_cast<int>(ch_state_))
		{
			m_character_state[i] = true;
		}
		m_character_state[i] = false;
	}
	/*switch (ch_state_)
	{
	case CHARACTER_STATE::WALK:
		m_character_state[static_cast<int>(CHARACTER_STATE::WALK)] = true;
		break;
	case CHARACTER_STATE::WALK_WAIT:
		m_character_state[static_cast<int>(CHARACTER_STATE::WALK_WAIT)] = true;
		break;
	case CHARACTER_STATE::WAIT:
		m_character_state[static_cast<int>(CHARACTER_STATE::WAIT)] = true;
		break;
	case CHARACTER_STATE::ATTACK_01:
		m_character_state[static_cast<int>(CHARACTER_STATE::ATTACK_01)] = true;
		break;
	case CHARACTER_STATE::RIGHT_ATTACK_02:
		m_character_state[static_cast<int>(CHARACTER_STATE::RIGHT_ATTACK_02)] = true;
		break;
	case CHARACTER_STATE::LEFT_ATTACK_02:
		m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_ATTACK_02)] = true;
		break;
	case CHARACTER_STATE::ATTACKED:
		m_character_state[static_cast<int>(CHARACTER_STATE::ATTACKED)] = true;
		break;
	case CHARACTER_STATE::DEFENCE_01:
		m_character_state[static_cast<int>(CHARACTER_STATE::DEFENCE_01)] = true;
		break;
	case CHARACTER_STATE::RIGHT_DEFENCE_02:
		m_character_state[static_cast<int>(CHARACTER_STATE::RIGHT_DEFENCE_02)] = true;
		break;
	case CHARACTER_STATE::LEFT_DEFENCE_02:
		m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_DEFENCE_02)] = true;
		break;
	case CHARACTER_STATE::DEFENCED:
		m_character_state[static_cast<int>(CHARACTER_STATE::DEFENCED)] = true;
		break;
	case CHARACTER_STATE::RIGHT_ATTACK_CROSS:
		m_character_state[static_cast<int>(CHARACTER_STATE::RIGHT_ATTACK_CROSS)] = true;
		break;
	case CHARACTER_STATE::LEFT_ATTACK_CROSS:
		m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_ATTACK_CROSS)] = true;
		break;
	case CHARACTER_STATE::RIGHT_FRICK:
		m_character_state[static_cast<int>(CHARACTER_STATE::RIGHT_FRICK)] = true;
		break;
	case CHARACTER_STATE::LEFT_FRICK:
		m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_FRICK)] = true;
		break;
	case CHARACTER_STATE::RIGHT_KILL:
		m_character_state[static_cast<int>(CHARACTER_STATE::RIGHT_KILL)] = true;
		break;
	case CHARACTER_STATE::LEFT_KILL:
		m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_KILL)] = true;
		break;
	case CHARACTER_STATE::RIGHT_KILL_WALK:
		m_character_state[static_cast<int>(CHARACTER_STATE::RIGHT_KILL_WALK)] = true;
		break;
	case CHARACTER_STATE::LEFT_KILL_WALK:
		m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_KILL_WALK)] = true;
		break;
	case CHARACTER_STATE::RIGHT_BACK:
		m_character_state[static_cast<int>(CHARACTER_STATE::RIGHT_BACK)] = true;
		break;
	case CHARACTER_STATE::LEFT_BACK:
		m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_BACK)] = true;
		break;
	case CHARACTER_STATE::RIGHT_DEATH:
		m_character_state[static_cast<int>(CHARACTER_STATE::RIGHT_DEATH)] = true;
		break;
	case CHARACTER_STATE::LEFT_DEATH:
		m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_DEATH)] = true;
		break;
	case CHARACTER_STATE::DETH:
		m_character_state[static_cast<int>(CHARACTER_STATE::DETH)] = true;
		break;
	case CHARACTER_STATE::STATE_MAX:
		break;
	default:
		break;
	}*/
}

//// 待機する
//void Character::Wait()
//{
//	m_character_state[static_cast<int>(CHARACTER_STATE::IS_WAIT)] = true;
//}
//// 歩く
//void Character::Walk()
//{
//	m_character_state[static_cast<int>(CHARACTER_STATE::IS_WALK)] = true;
//}
//// 近づくのをやめる
//void Character::StopWalk()
//{
//	m_walk_count = m_reset_count;
//	m_character_state[static_cast<int>(CHARACTER_STATE::IS_WALK)] = false;
//}
//// 武器を構える
//bool Character::HoldWeapon()
//{
//	if (m_character_state[static_cast<int>(CHARACTER_STATE::IS_WAIT)] == false)
//	{
//		m_character_state[static_cast<int>(CHARACTER_STATE::IS_HOLD_WEAPON)] = true;
//		return false;
//	}
//	else
//	{
//		return true;
//	}
//}
//// 攻撃する(1回目の予定)
//bool Character::Attack()
//{
//	if (m_character_state[static_cast<int>(CHARACTER_STATE::IS_ATTACKED)] == true)
//	{
//		m_character_state[static_cast<int>(CHARACTER_STATE::IS_ATTACKED)] = false;
//		return true;
//	}
//	else
//	{
//		m_character_state[static_cast<int>(CHARACTER_STATE::IS_ATTACK_01)] = true;
//		return false;
//	}
//}
//
//// 倒れる
//void Character::Fall()
//{
//	m_fall_count++;
//}
//
//// 死んだかどうか
//bool Character::Dead()
//{
//	return m_isdeth;
//}

void Character::Update()
{
	/*if (m_character_state[static_cast<int>(CHARACTER_STATE::WALK)] == true) {
		m_x += 1.0f;
		m_anime_count += 0.5f;
	}
	if (m_character_state[static_cast<int>(CHARACTER_STATE::WALK_WAIT)] == true) {
		m_anime_count += 0.5f;
	}*/
	for (int i = 0; i < static_cast<int>(CHARACTER_STATE::STATE_MAX); i++)
	{
		if (m_character_state[i] == true)
		{
			if (m_character_state[static_cast<int>(CHARACTER_STATE::WALK)] == true) 
			{
				m_x += 1.0f;
			}
			m_anime_count += 0.5f;
		}
	}
}



// キャラクターの座標と幅の情報
float Character::GetPosX()
{
	return m_x;
}
float Character::GetPosY()
{
	return m_y;
}
float Character::GetWidth()
{
	return m_width;
}
float Character::GetHeight()
{
	return m_height;
}