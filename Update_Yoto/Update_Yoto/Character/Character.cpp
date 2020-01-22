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

	m_walk = false;
	m_walk_to_standby = false;
	m_wait = false;
	m_attacked = false;
	m_attack1 = false;

	m_reset_count = 0;
	m_walk_count = 0;
	m_wait_count = 0;
	m_attack_count = 0;
	m_fall_count = 0;
	


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

// 待機する
void Character::Wait()
{
	m_wait = true;
}
// 近づく
void Character::Walk()
{
	m_walk = true;
}
// 近づくのをやめる
void Character::StopWalk()
{
	m_walk_count = m_reset_count;
	m_walk = false;
}
// 武器を構える
bool Character::HoldWeapon()
{
	if (m_wait == false)
	{
		m_walk_to_standby = true;
		return false;
	}
	else
	{
		return true;
	}
}
// 攻撃する(1回目の予定)
bool Character::Attack()
{
	if (m_attacked == true)
	{
		m_attacked = false;
		return true;
	}
	else
	{
		m_attack1 = true;
		return false;
	}
}

// 倒れる
void Character::Fall()
{
	m_fall_count++;
}

// 死んだかどうか
bool Character::Dead()
{
	return m_isdeth;
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