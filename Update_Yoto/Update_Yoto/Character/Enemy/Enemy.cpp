#include "Enemy.h"

void Enemy::Update()
{
	if (m_wait == true)
	{
		m_up_count += 0.5f;
	}
	
	// UŒ‚1‰ñ–Ú
	if (m_attack1 == true)
	{
		m_wait = false;
		m_attack_count += 0.5f;
		if (m_attack_count >= 10.0f)
		{
			m_attacked = true;
			m_attack_count = m_reset_count;
			m_attack1 = false;
		}
	}

	if (m_fall_count >= 55.0f)
	{
		m_isdeth = true;
	}
}