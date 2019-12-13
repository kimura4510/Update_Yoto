#ifndef ENEMY_H_
#define ENEMY_H_

#include "../Character.h"

class Enemy :public Character {
public:
	Enemy() {}
	virtual ~Enemy() {}

public:
	virtual void Init() = 0;
	virtual void Draw() = 0;
	virtual void Update() = 0;

	virtual int GetHp() = 0;
	virtual void HpDown() = 0;
	//virtual bool PlayerHpDown() = 0;

	/*int GetQuickPressFlame();
	void QuickPressFlameDown();*/

protected:
	

};

#endif