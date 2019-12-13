#include "Character.h"

static ENEMY_ID g_enemy_id = ENEMY_ID::DRAWER;

ENEMY_ID Character::GetEnemyID()
{
	return g_enemy_id;
}

void Character::ChangeEnemy(ENEMY_ID next_id_)
{
	g_enemy_id = next_id_;
}

//CHARACTER_HP Character::GetHp()
//{
//	return m_character_hp;
//

//int Character::OpponetHpDown(HP_DOWN hp_down_chara_)
//{
//	if (hp_down_chara_ == HP_DOWN::PLAYER_HP_DOWN)
//	{
//		return 1;
//	}
//	if (hp_down_chara_ == ENEMY_HP_DOWN)
//	{
//		return 2;
//	}
//}

//void Character::QuickPressFlameReset()
//{
//	m_quick_press_flame
//}

Character::GAME_END Character::GameClear()
{
	return Character::GAME_END::GAME_CLEAR;
}

Character::GAME_END Character::GameOver()
{
	return Character::GAME_END::GAME_OVER;
}

//bool Character::PlayerHpDown()
//{
//	return true;
//}
//
//bool Character::EnemyHpDown()
//{
//	return true;
//}