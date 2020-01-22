#ifndef CHARACTER_ID_H_
#define CHARACTER_ID_H_

enum class ENEMY_ID : int {
	DRAWER,
	PERRY,
	HERMIT,
	SINSENGUMI,
	FOX,

	ENMEY_NONE
};

enum class BATTLE_CHARACTER {
	BATTLE_PLAYER,
	BATTLE_ENEMY,

	BATTLE_MAX,
};

enum class GAME_END {
	GAME_NONE,

	GAME_CLEAR,
	GAME_OVER,

	GAME_END_MAX,
};

enum class CHARACTER_STATE : int{
	IS_WALK,				// 歩く

	IS_HOLD_WEAPON,			// 武器を構える
	IS_WAIT,				// 待機する

	IS_ATTACK_01,			// 1回目の攻撃する
	IS_ATTACK_02,			// 2回目の攻撃する
	IS_ATTACK_03,			// 3回目の攻撃する
	IS_ATTACKED,

	IS_DEFEND_01,			// 1回目の防御する
	IS_DEFEND_02,			// 2回目の防御する
	IS_DEFEND_03,			// 3回目の防御する
	IS_DEFENDED,

	IS_KILL,				// 殺す(殺すとき)
	IS_DIE,					// 死ぬ(殺されるとき)
	IS_DETH,				// 死んでる

	STATE_MAX
};

#endif