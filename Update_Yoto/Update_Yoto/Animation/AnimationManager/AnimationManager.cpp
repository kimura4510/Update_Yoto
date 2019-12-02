#include"AnimationManager.h"


CharacterAnimationManager::CharacterAnimationManager(
	const AnimationParameter& anim_param
) {

	// アニメーション選択
	ChangeAnimation(anim_param);
}



void CharacterAnimationManager::ChangeAnimation(
	const AnimationParameter& animation_parameter

) {

	// アニメーション選択
	SetAnimation(animation_parameter);
}



void CharacterAnimationManager::Update() {

	if (m_p_anim == nullptr) {
		return;
	}

	m_p_anim->Update();
}


void CharacterAnimationManager::Draw() {

	if (m_p_anim == nullptr) {
		return;
	}

	m_p_anim->Draw();
}


void CharacterAnimationManager::SetAnimation(
	const AnimationParameter&animation_parameter
) {

	// メモリが存在するなら削除
	if (m_p_anim != nullptr) {

		delete &m_p_anim;
	}

	// アニメーション生成
	m_p_anim = new CharacterAnimation(animation_parameter);
}


void CharacterAnimationManager::AddPosXSet(const float& pos_x) {
	m_p_anim->AddPosX(pos_x);
}


void CharacterAnimationManager::AddPosYSet(const float& pos_y) {
	m_p_anim->AddPosY(pos_y);
}
