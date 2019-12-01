

#ifndef CHARACTER_ANIMATION_H_
#define CHARACTER_ANIMATION_H_

#include"../../3DLibrary/3DLibrary/Engine/Graphics.hpp"
#include"../../3DLibrary/3DLibrary/Engine/Graphics.hpp"


struct AnimationParameter {

	AnimationParameter() {
		pos_x = 0.f;
		pos_y = 0.f;
		p_texture = nullptr;
		frame = 0.f;
	}

	float pos_x;
	float pos_y;
	Texture* p_texture;
	int frame;
};


// 基底のアニメーション
class CharacterAnimation{
public:

	CharacterAnimation(const AnimationParameter &anim_parameter) {

		m_animation_parameter.pos_x = 0.f;
		m_animation_parameter.pos_y = 0.f;
		m_animation_parameter.frame = 0.f;
		m_animation_parameter.p_texture = nullptr;

		m_animation_parameter = anim_parameter;
	};

	void Update() {

	}

	void Draw() {

		//Graphics::GetGraphicInstance()->DrawTexture(
		//	m_animation_parameter.pos_x,
		//	m_animation_parameter.pos_y,
		//	m_animation_parameter.p_texture
		//);

		// 描画
		Graphics::GetGraphicInstance()->DrawIntegratedImage(
			m_animation_parameter.pos_x,
			m_animation_parameter.pos_y,
			m_animation_parameter.p_texture,
			0.f,
			0.f,
			100.f,
			100.f,
			1,
			1
		);
	}


	void AddPosX(const float &add_pos_x) {
		m_animation_parameter.pos_x += add_pos_x;
	}

	void AddPosY(const float& add_pos_y) {
		m_animation_parameter.pos_y += add_pos_y;
	}

private:
	AnimationParameter m_animation_parameter;
};

#endif