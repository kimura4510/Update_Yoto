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

enum class CHARACTER_STATE {
	IS_WALK,			// 歩く

	IS_HOLD_WEAPON,		// 武器を構える
	IS_STAND_BY,		// 待機する

	IS_ATTACK,			// 攻撃する
	IS_DEFEND,			// 防御する

	IS_KILL,			// 殺す
	IS_DIE,				// 死ぬ

	STATE_MAX
};

#endif