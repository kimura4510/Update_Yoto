#ifndef PLAYER_H_
#define PLAYER_H_

#include "../Character.h"

class Player :public Character {
public:
	Player();
	virtual ~Player() {}

public:
	void Draw()override;

};

#endif