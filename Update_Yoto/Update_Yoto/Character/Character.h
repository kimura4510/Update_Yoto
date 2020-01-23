#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "CharacterID.h"

class Character {
public:
	Character();
	virtual ~Character() {}

public:
	virtual void Draw() = 0;
	void Update();

	int GetHp();
	void HpDown();

	void SetQuickPressFlame();
	int GetQuickPressFlame();
	void QuickPressFlameDown();

	void CharacterState(CHARACTER_STATE chara_state_);
	CHARACTER_STATE GetCharacterState();
	bool CheckCharacterState(CHARACTER_STATE ch_chara_state_);
	
	bool PBattlePos();
	bool EBattlePos();
	void PSetBattlePos();
	void ESetBattlePos();

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

	float m_quick_press_flame;
	float m_quick_press_flame_down;

	bool m_character_state[static_cast<int>(CHARACTER_STATE::STATE_MAX)];
	CHARACTER_STATE m_chara_state;
	float m_anime_count[static_cast<int>(CHARACTER_STATE::STATE_MAX)];
	float m_reset_count;

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