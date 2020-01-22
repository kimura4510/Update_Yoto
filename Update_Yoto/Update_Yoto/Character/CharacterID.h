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
	WALK,					// 歩く
	WALK_WAIT,				// 武器を構える
	WAIT,					// 待機する

	ATTACK_01,				// 1回目の攻撃する
	RIGHT_ATTACK_02,		// 右足で2回目以上の攻撃する
	LEFT_ATTACK_02,			// 左足で2回目以上の攻撃する
	ATTACKED,

	DEFENCE_01,				// 1回目の防御する
	RIGHT_DEFENCE_02,		// 右足で2回目以上の防御する
	LEFT_DEFENCE_02,		// 左足で2回目以上の防御する
	DEFENCED,

	RIGHT_ATTACK_CROSS,		// 右足でのつばぜりあい
	LEFT_ATTACK_CROSS,		// 左足でのつばぜりあい

	RIGHT_FRICK,			// 右ではじく側
	LEFT_FRICK,				// 左ではじく側

	RIGHT_KILL,				// 右足で殺す
	LEFT_KILL,				// 左足で殺す

	RIGHT_KILL_WALK,		// 右足で殺す
	LEFT_KILL_WALK,			// 左足で殺す

	RIGHT_BACK,				// 右足の時倒される
	LEFT_BACK,				// 左足の時倒される

	RIGHT_DEATH,			// 右足の時に殺される
	LEFT_DEATH,				// 左足の時に殺される

	DETH,					// 死んでる

	STATE_MAX
};

#endif