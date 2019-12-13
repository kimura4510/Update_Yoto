#ifndef PLAYER_H_
#define PLAYER_H_

#include "../Character.h"

class Player :public Character {
public:
	Player();
	virtual ~Player() {}

public:
	void Init()override;
	void Draw()override;
	void Update()override;

	int GetHp()override;
	void HpDown()override;
	//bool EnemyHpDown()override;

};

#endif