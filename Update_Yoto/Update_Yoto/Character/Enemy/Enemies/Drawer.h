#ifndef DRAWER_H_
#define DRAWER_H_

#include "../Enemy.h"

class Drawer :public Enemy {
public:
	Drawer();
	virtual ~Drawer(){}

public:
	void Init()override;
	void Draw()override;
	void Update()override;

	int GetQuickPressFlame()override;
	void QuickPressFlameDown()override;

	int GetHp()override;
	void HpDown()override;
	//bool PlayerHpDown()override;

};

#endif