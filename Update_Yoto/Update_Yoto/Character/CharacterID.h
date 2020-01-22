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
	IS_WALK,				// ����

	IS_HOLD_WEAPON,			// ������\����
	IS_WAIT,				// �ҋ@����

	IS_ATTACK_01,			// 1��ڂ̍U������
	IS_ATTACK_02,			// 2��ڂ̍U������
	IS_ATTACK_03,			// 3��ڂ̍U������
	IS_ATTACKED,

	IS_DEFEND_01,			// 1��ڂ̖h�䂷��
	IS_DEFEND_02,			// 2��ڂ̖h�䂷��
	IS_DEFEND_03,			// 3��ڂ̖h�䂷��
	IS_DEFENDED,

	IS_KILL,				// �E��(�E���Ƃ�)
	IS_DIE,					// ����(�E�����Ƃ�)
	IS_DETH,				// ����ł�

	STATE_MAX
};

#endif