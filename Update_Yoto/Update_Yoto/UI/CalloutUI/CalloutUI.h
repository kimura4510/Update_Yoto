#pragma once


// 吹き出しUI

enum class BUTTOM_UI {
	A,
	B,
	X,
	Y
};

class CalloutUI{
public:

	CalloutUI();

	void Init();
	void Update();
	void Draw();

	bool IsOn();
	void IsNotOn();

private:
	bool m_ison = false;
	float m_x, m_y, m_z;

	int m_time_to_count_out;
	int m_push_flame_count;

	int m_callout_state;

};