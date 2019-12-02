#pragma once
#include"../Animation/CharacterAnimation.h"
#include<memory>


// ライブラリのような印象


class CharacterAnimationManager {
public:
	
	/**
	* @brief アニメーション指定コンストラクタ
	* @param[in] animation_state アニメーションをする状態
	*/
	CharacterAnimationManager(
		const AnimationParameter &anim_param
	);


	// 更新
	void Update();

	// 描画
	void Draw();

	// アニメーションを新たにセット
	void SetAnimation(
		const AnimationParameter& animation_parameter
	);

	void AddPosXSet(const float& pos_x);
	void AddPosYSet(const float& pos_y);

private:

	// アニメーション選択
	void ChangeAnimation(
		const AnimationParameter& animation_parameter
	);

private:

	// 今のアニメーション状態
	CharacterAnimation * m_p_anim;

};