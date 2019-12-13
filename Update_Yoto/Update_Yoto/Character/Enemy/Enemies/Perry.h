#ifndef PERRY_H_
#define PERRY_H_

#include "../Enemy.h"

class Perry :public Enemy {
public:
	Perry();
	virtual ~Perry() {}

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