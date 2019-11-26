#pragma once
#include"UI/CalloutUI/CalloutUI.h"
#include"UI/HpUI/HpUI.h"



class TestUpdate {
public:
	void Update();
	void Draw();

private:

	CalloutUI m_callout_ui;
	HpUI m_hp_ui;
};