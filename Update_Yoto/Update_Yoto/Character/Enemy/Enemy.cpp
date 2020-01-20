#include "Enemy.h"

void Enemy::Update()
{
	m_up_count += 0.5f;

	if (GetHp() <= 0)
	{
		m_isdeth == true;
		m_fall_count += 0.5f;
		if (m_fall_count >= 55.0f)
		{
			m_dead = true;
			m_fall_count = m_reset_count;
		}
	}
}