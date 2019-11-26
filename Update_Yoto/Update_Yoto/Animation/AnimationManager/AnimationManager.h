#pragma once
#include"../AnimationBase/AnimationBase.h"
#include"../WaitAnimation/WaitAnimation.h"
#include"../../Animation/AttackAnimation/AttackAnimation.h"
#include<memory>



class CharacterAnimationManager {
public:
	
	CharacterAnimationManager(const CharacterAnimationBase::AnimationType &animation_type,
	//Sprite2DData&attack_data,
	//	Sprite2DData&wait_data
	) {

		// 現在のアニメーションに選択したアニメーションを代入
		m_current_animation_type = animation_type;

		m_attack_data = attack_data;
		m_wait_data = wait_data;

		// アニメーション選択
		AnimationSelect(animation_type);
	}


	void AnimationChange(const CharacterAnimationBase::AnimationType &animation_type) {

		// 現在のシーンと同じなら返す
		if (animation_type == m_current_animation_type) {
			return;
		}

		// アニメーション選択
		AnimationSelect(animation_type);

		// アニメーションの状態を切り替え
		m_current_animation_type = animation_type;
	}


	void Update() {

		if (m_p_anim == nullptr) {
			return;
		}

		m_p_anim->Update();
	}

	void Draw() {

		if (m_p_anim == nullptr) {
			return;
		}

		m_p_anim->Draw();
	}


private:

	// アニメーション選択
	void AnimationSelect(const CharacterAnimationBase::AnimationType &animation_type) {

		// メモリが存在するなら削除
		if (m_p_anim != nullptr) {
			delete m_p_anim;
		}

		// アニメーション選択
		switch (animation_type) {

		case CharacterAnimationBase::WAIT:

			m_p_anim = new WaitAnimation(m_wait_data);
			break;

		case CharacterAnimationBase::ATTACK:

			m_p_anim = new AttackAnimation(m_attack_data);
		}
	}


private:

	// 現在のアニメーションを識別するナンバー
	CharacterAnimationBase::AnimationType m_current_animation_type;

	// 今のアニメーション状態
	CharacterAnimationBase * m_p_anim;

	// 待機中のデータ
	//Sprite2DData m_wait_data;

	// 攻撃中のデータ
	//Sprite2DData m_attack_data;
	
};