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
	WALK,					// ����
	WALK_WAIT,				// ������\����
	WAIT,					// �ҋ@����

	ATTACK_01,				// 1��ڂ̍U������
	RIGHT_ATTACK_02,		// �E����2��ڈȏ�̍U������
	LEFT_ATTACK_02,			// ������2��ڈȏ�̍U������
	ATTACKED,

	DEFENCE_01,				// 1��ڂ̖h�䂷��
	RIGHT_DEFENCE_02,		// �E����2��ڈȏ�̖h�䂷��
	LEFT_DEFENCE_02,		// ������2��ڈȏ�̖h�䂷��
	DEFENCED,

	RIGHT_ATTACK_CROSS,		// �E���ł̂΂��肠��
	LEFT_ATTACK_CROSS,		// �����ł̂΂��肠��

	RIGHT_FRICK,			// �E�ł͂�����
	LEFT_FRICK,				// ���ł͂�����

	RIGHT_KILL,				// �E���ŎE��
	LEFT_KILL,				// �����ŎE��

	RIGHT_KILL_WALK,		// �E���ŎE��
	LEFT_KILL_WALK,			// �����ŎE��

	RIGHT_BACK,				// �E���̎��|�����
	LEFT_BACK,				// �����̎��|�����

	RIGHT_DEATH,			// �E���̎��ɎE�����
	LEFT_DEATH,				// �����̎��ɎE�����

	DETH,					// ����ł�

	STATE_MAX
};

#endif