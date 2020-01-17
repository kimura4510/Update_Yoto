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
	m_count = 0;

	m_quick_press_flame = 0;
	m_quick_press_flame_down = 0;

	m_approach = false;
	m_approach_count = 0;
}

void Character::Update()
{
	if (m_approach == true)
	{
		m_x += 3.0f;
		m_count += 0.5f;
		/*if (m_x >= 0.0f)
		{
			m_approach = false;
		}*/
	}

	if (GetHp() <= 0)
	{
		m_isdeth == true;
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

void Character::GoToApproach()
{
	m_approach = true;
}

void Character::StopApproach()
{
	m_approach = false;
}

float Character::GetPos()
{
	return m_x;
}