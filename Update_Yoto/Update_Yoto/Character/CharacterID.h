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
	IS_WALK,			// ����

	IS_HOLD_WEAPON,		// ������\����
	IS_STAND_BY,		// �ҋ@����

	IS_ATTACK,			// �U������
	IS_DEFEND,			// �h�䂷��

	IS_KILL,			// �E��
	IS_DIE,				// ����

	STATE_MAX
};

#endif