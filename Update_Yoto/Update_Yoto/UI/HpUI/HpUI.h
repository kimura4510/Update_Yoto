#pragma once



class HpUI{
public:

	// 描画方向
	enum class DrawDirection {
		RIGHT,
		LEFT
	};

	// 描画するオブジェクトの種類
	enum class DrawType {
		HP_NONE,
		HP_LITTLE,
		HP_MEDIUM,
		HP_MAX
	};

public:

	HpUI(
		DrawType draw_type,
		DrawDirection dir,
		const float&pos_x = 0.f,
		const float&pos_y = 0.f
	);

public:

	void Update();
	void Draw();

	void ChangeDrawTypeNone() {
		m_draw_type = DrawType::HP_NONE;
	}

	void ChangeDrawTypeLittle() {
		m_draw_type = DrawType::HP_LITTLE;
	}

	void ChangeDrawTypeMedium() {
		m_draw_type = DrawType::HP_MEDIUM;
	}

	void ChangeDrawTypeMax() {
		m_draw_type = DrawType::HP_MAX;
	}

private:

	void ChangeHpType() {

		switch (m_dir) {

		case DrawDirection::LEFT:
			m_split_num_y = 2;
			break;

		case DrawDirection::RIGHT:
			m_split_num_y = 1;
			break;
		}
	}

private:

	DrawType m_draw_type;
	DrawDirection m_dir;

	float m_pos_x = 0.f;
	float m_pos_y = 0.f;
	float m_tu = 0.127f;
	float m_tv = 0.08f;
	float m_width_size = 700.f;
	float m_height_size = 100.f;
	int m_split_num_x = 1;
	int m_split_num_y = 1;
};