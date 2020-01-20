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
	IS_WALK,			// ï‡Ç≠

	IS_HOLD_WEAPON,		// ïêäÌÇç\Ç¶ÇÈ
	IS_STAND_BY,		// ë“ã@Ç∑ÇÈ

	IS_ATTACK,			// çUåÇÇ∑ÇÈ
	IS_DEFEND,			// ñhå‰Ç∑ÇÈ

	IS_KILL,			// éEÇ∑
	IS_DIE,				// éÄÇ 

	STATE_MAX
};

#endif