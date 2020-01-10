#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "CharacterID.h"

class Character {
public:

	Character();
	virtual ~Character() {}

public:
	virtual void Init() = 0;
	virtual void Draw() = 0;
	virtual void Update() = 0;

	int GetHp();
	void HpDown();

	void SetQuickPressFlame();
	int GetQuickPressFlame();
	void QuickPressFlameDown();
protected:

	// �ǉ��@�A�j���[�V�����֘A�@�O��
	/**
	* @brief �A�j���[�V�������J�E���g����֐�
	*/
	void AnimationCount();

protected:
	bool m_isdeth;
	float m_x, m_y, m_z;
	int m_hp;

	float m_quick_press_flame;
	float m_quick_press_flame_down;


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