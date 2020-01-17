#include "Enemy.h"

void Enemy::Update()
{
	if (m_approach == true)
	{
		m_x -= 3.0f;
		m_count += 0.5f;
	}

	if (GetHp() <= 0)
	{
		m_isdeth == true;
	}
}