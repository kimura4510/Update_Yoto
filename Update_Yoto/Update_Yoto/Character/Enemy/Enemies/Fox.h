#ifndef FOX_H_
#define FOX_H_

#include "../Enemy.h"

class Fox :public Enemy {
public:
	Fox();
	virtual ~Fox() {}

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