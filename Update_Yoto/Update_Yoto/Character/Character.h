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
	CHARACTER_STATE m_chara_state;
	float m_anime_count[static_cast<int>(CHARACTER_STATE::STATE_MAX)];
	float m_reset_count;

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