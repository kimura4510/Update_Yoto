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

	// 追加　アニメーション関連　前川
	/**
	* @brief アニメーションをカウントする関数
	*/
	void AnimationCount();

protected:
	bool m_isdeth;
	float m_x, m_y, m_z;
	int m_hp;

	float m_quick_press_flame;
	float m_quick_press_flame_down;


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