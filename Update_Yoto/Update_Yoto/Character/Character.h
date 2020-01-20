#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "CharacterID.h"

class Character {
public:
	Character();
	virtual ~Character() {}

public:
	virtual void Draw() = 0;
	virtual void Update() = 0;

	int GetHp();
	void HpDown();
	bool Dead();

	void SetQuickPressFlame();
	int GetQuickPressFlame();
	void QuickPressFlameDown();

	void Wait();
	void GoToApproach();
	void StopApproach();
	void HoldWeapon();

	float GetPosX();
	float GetPosY();
	float GetWidth();
	float GetHeight();

protected:

	// �ǉ��@�A�j���[�V�����֘A�@�O��
	/**
	* @brief �A�j���[�V�������J�E���g����֐�
	*/
	void AnimationCount();
protected:
	bool m_isdeth;
	float m_x, m_y, m_z;
	float m_width, m_height;

	int m_hp;
	bool m_dead;

	float m_quick_press_flame;
	float m_quick_press_flame_down;


	//bool m_motion_state[static_cast<int>(CHARACTER_STATE::STATE_MAX)];

	bool m_approach;
	float m_reset_count;
	float m_up_count;
	float m_fall_count;
	bool m_walk_to_standby;
	bool m_standby;

	// �ǉ��@�A�j���[�V�����֘A�@�O��

	//! ���݃A�j���[�V���������Ă���J�E���g
	int m_current_anim_num;

	//! �A�j���[�V�����t���[����
	int m_anim_frame;

	//! �ő�A�j���[�V�����t���[����
	int m_max_anim_frame;

	//! �ő�A�j���[�V��������(������)
	int m_max_anim_num;

};

#endif