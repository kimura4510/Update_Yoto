#ifndef CUT_IN_H_
#define CUT_IN_H_

#include "../../3DLibrary/3DLibrary/Texture/Texture.hpp"

class CutIn {
public:
	enum class DrawMethod {
		RIGHT,
		LEFT,

		METHOD_MAX
	};
	enum class CutInType {
		PLAYER,

		DRAWER,
		PERRY,
		HERMIT,
		SINSENGUMI,
		FOX,

		TYPE_MAX
	};

public:
	CutIn(DrawMethod method_, CutInType type_, float x_, float y_);

public:
	void Update();
	void Draw();

	bool IsOn();
	void IsNotOn();

private:
	DrawMethod m_method;
	CutInType m_type;

	float m_x, m_y;
	Texture* m_p_tex;
	float m_tu, m_tv;
	float m_sprite_width, m_sprite_height;
	int m_sprite_num_x, m_sprite_num_y;

	bool m_ison;
	int m_set_count;
	int m_down_count;

};

#endif