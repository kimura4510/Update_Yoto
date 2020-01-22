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

	m_character_state[static_cast<int>(CHARACTER_STATE::STATE_MAX)] = false;

	m_reset_count = 0;
	m_walk_count = 0;
	m_wait_count = 0;
	m_attack_count = 0;
	m_fall_count = 0;
	


	// �ǉ��@�A�j���[�V�����֘A�@�O��
	//! ���݃A�j���[�V���������Ă���J�E���g
	m_current_anim_num = 0;

	//! �A�j���[�V�����t���[����
	m_anim_frame = 0;

	//! �A�j���[�V�����ő�t���[����
	m_max_anim_frame = 0;

	//! �ő�A�j���[�V��������(������)
	m_max_anim_num = 0;
}

void Character::AnimationCount() {


	// �ő�A�j���[�V�����t���[���𒴂�����
	if (m_anim_frame >= m_max_anim_frame) {

		// ���݃A�j���[�V�������������Z
		m_current_anim_num++;
	}
	// �A�j���[�V�����������ő�A�j���[�V���������𒴂�����
	else if (m_current_anim_num >= m_max_anim_num) {

		// �A�j���[�V�������������ɖ߂�
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

// �ҋ@����
void Character::Wait()
{
	m_character_state[static_cast<int>(CHARACTER_STATE::IS_WAIT)] = true;
}
// ����
void Character::Walk()
{
	m_character_state[static_cast<int>(CHARACTER_STATE::IS_WALK)] = true;
}
// �߂Â��̂���߂�
void Character::StopWalk()
{
	m_walk_count = m_reset_count;
	m_character_state[static_cast<int>(CHARACTER_STATE::IS_WALK)] = false;
}
// ������\����
bool Character::HoldWeapon()
{
	if (m_character_state[static_cast<int>(CHARACTER_STATE::IS_WAIT)] == false)
	{
		//m_walk_to_standby = true;
		m_character_state[static_cast<int>(CHARACTER_STATE::IS_HOLD_WEAPON)] = true;
		return false;
	}
	else
	{
		return true;
	}
}
// �U������(1��ڂ̗\��)
bool Character::Attack()
{
	if (m_character_state[static_cast<int>(CHARACTER_STATE::IS_ATTACKED)] == true)
	{
		m_character_state[static_cast<int>(CHARACTER_STATE::IS_ATTACKED)] = false;
		return true;
	}
	else
	{
		m_character_state[static_cast<int>(CHARACTER_STATE::IS_ATTACK_01)] = true;
		return false;
	}
}

// �|���
void Character::Fall()
{
	m_fall_count++;
}

// ���񂾂��ǂ���
bool Character::Dead()
{
	return m_isdeth;
}

// �L�����N�^�[�̍��W�ƕ��̏��
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