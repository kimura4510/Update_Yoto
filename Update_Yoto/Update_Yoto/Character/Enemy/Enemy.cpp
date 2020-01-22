#include "Enemy.h"

void Enemy::Update()
{
	if (m_character_state[static_cast<int>(CHARACTER_STATE::IS_WAIT)] == true)
	{
		m_wait_count += 0.5f;
	}
	
	// UŒ‚1‰ñ–Ú
	if (m_character_state[static_cast<int>(CHARACTER_STATE::IS_ATTACK_01)] == true)
	{
		m_character_state[static_cast<int>(CHARACTER_STATE::IS_WAIT)] = false;
		m_attack_count += 0.5f;
		if (m_attack_count >= 10.0f)
		{
			m_character_state[static_cast<int>(CHARACTER_STATE::IS_ATTACKED)] = true;
			m_attack_count = m_reset_count;
			m_character_state[static_cast<int>(CHARACTER_STATE::IS_ATTACK_01)] = false;
		}
	}

	if (m_fall_count >= 55.0f)
	{
		m_isdeth = true;
	}
}