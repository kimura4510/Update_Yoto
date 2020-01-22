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

	void SetQuickPressFlame();
	int GetQuickPressFlame();
	void QuickPressFlameDown();

	void Wait();
	void Walk();
	void StopWalk();
	bool HoldWeapon();
	bool Attack();
	void Fall();
	bool Dead();

	float GetPosX();
	float GetPosY();
	float GetWidth();
	float GetHeight();

protected:

	// 追加　アニメーション関連　前川
	/**
	* @brief アニメーションをカウントする関数
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

	float m_reset_count;
	float m_walk_count;
	float m_wait_count;
	float m_attack_count;
	float m_fall_count;

	// 追加　アニメーション関連　前川

	//! 現在アニメーションをしているカウント
	int m_current_anim_num;

	//! アニメーションフレーム数
	int m_anim_frame;

	//! 最大アニメーションフレーム数
	int m_max_anim_frame;

	//! 最大アニメーション枚数(を入れる)
	int m_max_anim_num;

};

#endif