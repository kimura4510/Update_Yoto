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
	m_chara_state = CHARACTER_STATE::STATE_MAX;
	for (int i = 0; i < static_cast<int>(CHARACTER_STATE::STATE_MAX); i++)
	{
		m_anime_count[i] = 0;
	}
	m_reset_count = 0;

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

void Character::CharacterState(CHARACTER_STATE ch_state_)
{
	for (int i = 0; i < static_cast<int>(CHARACTER_STATE::STATE_MAX); i++)
	{
		if (i == static_cast<int>(ch_state_))
		{
			m_character_state[i] = true;
		}
		else
		{
			m_character_state[i] = false;
		}
	}
	m_chara_state = ch_state_;
}

CHARACTER_STATE Character::GetCharacterState()
{
	return m_chara_state;
}

bool Character::CheckCharacterState(CHARACTER_STATE ch_chara_state_)
{
	if (GetCharacterState() == ch_chara_state_)
	{
		return true;
	}
	else {
		return false;
	}
}

void Character::Update()
{
	for (int i = 0; i < static_cast<int>(CHARACTER_STATE::STATE_MAX); i++)
	{
		if (m_character_state[i] == true)
		{
			// �����Ă���
			if (m_character_state[static_cast<int>(CHARACTER_STATE::WALK)] == true) 
			{
				m_anime_count[static_cast<int>(CHARACTER_STATE::WALK)] += 0.5f;
				m_x += 2.0f;
			}
			// ������o���č\����
			if (m_character_state[static_cast<int>(CHARACTER_STATE::WALK_WAIT)] == true)
			{
				m_anime_count[static_cast<int>(CHARACTER_STATE::WALK_WAIT)] += 0.5f;
				if (m_anime_count[static_cast<int>(CHARACTER_STATE::WALK_WAIT)] >= 18.0f)
				{
					m_character_state[static_cast<int>(CHARACTER_STATE::WALK_WAIT)] = false;
					m_anime_count[static_cast<int>(CHARACTER_STATE::WALK_WAIT)] = 0.0f;
					CharacterState(CHARACTER_STATE::WAIT);
				}
			}


			// �ҋ@���
			if (m_character_state[static_cast<int>(CHARACTER_STATE::WAIT)] == true)
			{
				m_anime_count[static_cast<int>(CHARACTER_STATE::WAIT)] += 0.5f;
			}


			// �U��1���
			if (m_character_state[static_cast<int>(CHARACTER_STATE::ATTACK_01)] == true)
			{
				m_anime_count[static_cast<int>(CHARACTER_STATE::ATTACK_01)] += 0.5f;
				if (m_anime_count[static_cast<int>(CHARACTER_STATE::ATTACK_01)] >= 10.0f)
				{
					m_character_state[static_cast<int>(CHARACTER_STATE::ATTACK_01)] = false;
					m_anime_count[static_cast<int>(CHARACTER_STATE::ATTACK_01)] = 0.0f;
					CharacterState(CHARACTER_STATE::LEFT_ATTACK_CROSS);
				}
			}
			// �U��1��ڈȍ~
			if (m_character_state[static_cast<int>(CHARACTER_STATE::RIGHT_ATTACK_02)] == true)
			{
				m_anime_count[static_cast<int>(CHARACTER_STATE::RIGHT_ATTACK_02)] += 0.5f;
				if (m_anime_count[static_cast<int>(CHARACTER_STATE::RIGHT_ATTACK_02)] >= 10.0f)
				{
					m_character_state[static_cast<int>(CHARACTER_STATE::RIGHT_ATTACK_02)] = false;
					m_anime_count[static_cast<int>(CHARACTER_STATE::RIGHT_ATTACK_02)] = 0.0f;
					CharacterState(CHARACTER_STATE::RIGHT_ATTACK_CROSS);
				}
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_ATTACK_02)] == true)
			{
				m_anime_count[static_cast<int>(CHARACTER_STATE::LEFT_ATTACK_02)] += 0.5f;
				if (m_anime_count[static_cast<int>(CHARACTER_STATE::LEFT_ATTACK_02)] >= 10.0f)
				{
					m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_ATTACK_02)] = false;
					m_anime_count[static_cast<int>(CHARACTER_STATE::LEFT_ATTACK_02)] = 0.0f;
					CharacterState(CHARACTER_STATE::LEFT_ATTACK_CROSS);
				}
			}
			// �U��������ɂ�����΂��荇��
			if (m_character_state[static_cast<int>(CHARACTER_STATE::RIGHT_ATTACK_CROSS)] == true)
			{
				m_anime_count[static_cast<int>(CHARACTER_STATE::RIGHT_ATTACK_CROSS)] += 0.5f;
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_ATTACK_CROSS)] == true)
			{
				m_anime_count[static_cast<int>(CHARACTER_STATE::LEFT_ATTACK_CROSS)] += 0.5f;
			}


			// �h��1���
			if (m_character_state[static_cast<int>(CHARACTER_STATE::DEFENCE_01)] == true)
			{
				m_anime_count[static_cast<int>(CHARACTER_STATE::DEFENCE_01)] += 0.5f;
				if (m_anime_count[static_cast<int>(CHARACTER_STATE::DEFENCE_01)] >= 10.0f)
				{
					m_character_state[static_cast<int>(CHARACTER_STATE::DEFENCE_01)] = false;
					m_anime_count[static_cast<int>(CHARACTER_STATE::DEFENCE_01)] = 0.0f;
					CharacterState(CHARACTER_STATE::LEFT_DEFENCE_CROSS);
				}
			}
			// �h��1��ڈȍ~
			if (m_character_state[static_cast<int>(CHARACTER_STATE::RIGHT_DEFENCE_02)] == true)
			{
				m_anime_count[static_cast<int>(CHARACTER_STATE::RIGHT_DEFENCE_02)] += 0.5f;
				if (m_anime_count[static_cast<int>(CHARACTER_STATE::RIGHT_DEFENCE_02)] >= 10.0f)
				{
					m_character_state[static_cast<int>(CHARACTER_STATE::RIGHT_DEFENCE_02)] = false;
					m_anime_count[static_cast<int>(CHARACTER_STATE::RIGHT_DEFENCE_02)] = 0.0f;
					CharacterState(CHARACTER_STATE::RIGHT_DEFENCE_CROSS);
				}
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_DEFENCE_02)] == true)
			{
				m_anime_count[static_cast<int>(CHARACTER_STATE::LEFT_DEFENCE_02)] += 0.5f;
				if (m_anime_count[static_cast<int>(CHARACTER_STATE::LEFT_DEFENCE_02)] >= 10.0f)
				{
					m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_DEFENCE_02)] = false;
					m_anime_count[static_cast<int>(CHARACTER_STATE::LEFT_DEFENCE_02)] = 0.0f;
					CharacterState(CHARACTER_STATE::LEFT_DEFENCE_CROSS);
				}
			}
			// �h�䂵����ɂ�����΂��荇��
			if (m_character_state[static_cast<int>(CHARACTER_STATE::RIGHT_DEFENCE_CROSS)] == true)
			{
				m_anime_count[static_cast<int>(CHARACTER_STATE::RIGHT_DEFENCE_CROSS)] += 0.5f;
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_DEFENCE_CROSS)] == true)
			{
				m_anime_count[static_cast<int>(CHARACTER_STATE::LEFT_DEFENCE_CROSS)] += 0.5f;
			}


			// �΂��荇���ɏ������ꍇ
			if (m_character_state[static_cast<int>(CHARACTER_STATE::RIGHT_FRICK)] == true)
			{
				m_anime_count[static_cast<int>(CHARACTER_STATE::RIGHT_FRICK)] += 0.5f;
				if (m_anime_count[static_cast<int>(CHARACTER_STATE::RIGHT_FRICK)] >= 10.0f)
				{
					m_character_state[static_cast<int>(CHARACTER_STATE::RIGHT_FRICK)] = false;
					m_anime_count[static_cast<int>(CHARACTER_STATE::RIGHT_FRICK)] = 0.0f;
					CharacterState(CHARACTER_STATE::LEFT_ATTACK_02);
				}
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_FRICK)] == true)
			{
				m_anime_count[static_cast<int>(CHARACTER_STATE::LEFT_FRICK)] += 0.5f;
				if (m_anime_count[static_cast<int>(CHARACTER_STATE::LEFT_FRICK)] >= 10.0f)
				{
					m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_FRICK)] = false;
					m_anime_count[static_cast<int>(CHARACTER_STATE::LEFT_FRICK)] = 0.0f;
					//CharacterState(CHARACTER_STATE::RIGHT_ATTACK_02);
					CharacterState(CHARACTER_STATE::LEFT_ATTACK_02);
				}
			}
			// �΂��荇���ɕ������ꍇ
			if (m_character_state[static_cast<int>(CHARACTER_STATE::RIGHT_BACK)] == true)
			{
				m_anime_count[static_cast<int>(CHARACTER_STATE::RIGHT_BACK)] += 0.5f;
				if (m_anime_count[static_cast<int>(CHARACTER_STATE::RIGHT_BACK)] >= 10.0f)
				{
					m_character_state[static_cast<int>(CHARACTER_STATE::RIGHT_BACK)] = false;
					m_anime_count[static_cast<int>(CHARACTER_STATE::RIGHT_BACK)] = 0.0f;
					CharacterState(CHARACTER_STATE::LEFT_DEFENCE_02);
				}
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_BACK)] == true)
			{
				m_anime_count[static_cast<int>(CHARACTER_STATE::LEFT_BACK)] += 0.5f;
				if (m_anime_count[static_cast<int>(CHARACTER_STATE::LEFT_BACK)] >= 10.0f)
				{
					m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_BACK)] = false;
					m_anime_count[static_cast<int>(CHARACTER_STATE::LEFT_BACK)] = 0.0f;
					//CharacterState(CHARACTER_STATE::RIGHT_DEFENCE_02);
					CharacterState(CHARACTER_STATE::LEFT_DEFENCE_02);
				}
			}

			// �G���E���Ƃ�(�v���C���[��)
			if (m_character_state[static_cast<int>(CHARACTER_STATE::RIGHT_KILL)] == true)
			{
				m_anime_count[static_cast<int>(CHARACTER_STATE::RIGHT_KILL)] += 0.5f;
				if (m_anime_count[static_cast<int>(CHARACTER_STATE::RIGHT_KILL)] >= 40.0f)
				{
					m_character_state[static_cast<int>(CHARACTER_STATE::RIGHT_KILL)] = false;
					m_anime_count[static_cast<int>(CHARACTER_STATE::RIGHT_KILL)] = 0.0f;
					CharacterState(CHARACTER_STATE::RIGHT_KILL_WALK);
				}
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_KILL)] == true)
			{
				m_anime_count[static_cast<int>(CHARACTER_STATE::LEFT_KILL)] += 0.5f;
				if (m_anime_count[static_cast<int>(CHARACTER_STATE::LEFT_KILL)] >= 40.0f)
				{
					m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_KILL)] = false;
					m_anime_count[static_cast<int>(CHARACTER_STATE::LEFT_KILL)] = 0.0f;
					CharacterState(CHARACTER_STATE::LEFT_KILL_WALK);
				}
			}
			// �G���E���Ƃ��i�G�l�~�[���j
			/*if (m_character_state[static_cast<int>(CHARACTER_STATE::RIGHT_KILL)] == true)
			{
				m_anime_count[static_cast<int>(CHARACTER_STATE::RIGHT_KILL)] += 0.5f;
				if (m_anime_count[static_cast<int>(CHARACTER_STATE::RIGHT_KILL)] >= 40.0f)
				{
					m_character_state[static_cast<int>(CHARACTER_STATE::RIGHT_KILL)] = false;
					m_anime_count[static_cast<int>(CHARACTER_STATE::RIGHT_KILL)] = 0.0f;
					CharacterState(CHARACTER_STATE::RIGHT_KILL_STAND);
				}
			}
			if (m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_KILL)] == true)
			{
				m_anime_count[static_cast<int>(CHARACTER_STATE::LEFT_KILL)] += 0.5f;
				if (m_anime_count[static_cast<int>(CHARACTER_STATE::LEFT_KILL)] >= 40.0f)
				{
					m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_KILL)] = false;
					m_anime_count[static_cast<int>(CHARACTER_STATE::LEFT_KILL)] = 0.0f;
					CharacterState(CHARACTER_STATE::LEFT_KILL_STAND);
				}
			}*/


			// �����Ŏ���
			if (m_character_state[static_cast<int>(CHARACTER_STATE::LEFT_DEATH)] == true)
			{
				m_anime_count[static_cast<int>(CHARACTER_STATE::LEFT_DEATH)] += 0.5f;
				if (m_anime_count[static_cast<int>(CHARACTER_STATE::LEFT_DEATH)] >= 55.0f)
				{
					m_anime_count[static_cast<int>(CHARACTER_STATE::LEFT_DEATH)] = 0.0f;
					m_isdeth = true;
					CharacterState(CHARACTER_STATE::DETH);
				}
			}
			// ����ł���
			if (m_character_state[static_cast<int>(CHARACTER_STATE::DETH)] == true)
			{
				m_anime_count[static_cast<int>(CHARACTER_STATE::DETH)] = 55.0f;
			}
		}
	}
}


bool Character::PBattlePos()
{
	if (GetPosX() >= 512.0f - 256.0f + 64.0f + 8.0f)
	{
		return true;
	}
	else {
		return false;
	}
}
bool Character::EBattlePos()
{
	if (GetPosX() >= 512.0f - 64.0f - 8.0f)
	{
		return true;
	}
	else {
		return false;
	}
}
void Character::PSetBattlePos()
{
	m_x = 512.0f - 256.0f + 64.0f + 8.0f;
}
void Character::ESetBattlePos()
{
	m_x = 512.0f - 64.0f - 8.0f;
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