#include "DataBank.h"

void DataBank::SetEnemyType(int enemy_type_)
{
	m_enemy_type = enemy_type_;
}

int DataBank::GetEnemyType()
{
	return m_enemy_type;
}

void DataBank::SetCutInType(int cutin_type_)
{
	m_cutin_type = cutin_type_;
}

int DataBank::GetCutInType()
{
	return m_cutin_type;
}