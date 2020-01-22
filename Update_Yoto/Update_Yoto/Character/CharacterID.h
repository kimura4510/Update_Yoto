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
	IS_WALK,				// •à‚­

	IS_HOLD_WEAPON,			// •Ší‚ð\‚¦‚é
	IS_WAIT,				// ‘Ò‹@‚·‚é

	IS_ATTACK_01,			// 1‰ñ–Ú‚ÌUŒ‚‚·‚é
	IS_ATTACK_02,			// 2‰ñ–Ú‚ÌUŒ‚‚·‚é
	IS_ATTACK_03,			// 3‰ñ–Ú‚ÌUŒ‚‚·‚é
	IS_ATTACKED,

	IS_DEFEND_01,			// 1‰ñ–Ú‚Ì–hŒä‚·‚é
	IS_DEFEND_02,			// 2‰ñ–Ú‚Ì–hŒä‚·‚é
	IS_DEFEND_03,			// 3‰ñ–Ú‚Ì–hŒä‚·‚é
	IS_DEFENDED,

	IS_KILL,				// ŽE‚·(ŽE‚·‚Æ‚«)
	IS_DIE,					// Ž€‚Ê(ŽE‚³‚ê‚é‚Æ‚«)
	IS_DETH,				// Ž€‚ñ‚Å‚é

	STATE_MAX
};

#endif