#include"AnimationManager.h"


CharacterAnimationManager::CharacterAnimationManager
(const CharacterAnimationBase::AnimationType& animation_type,
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