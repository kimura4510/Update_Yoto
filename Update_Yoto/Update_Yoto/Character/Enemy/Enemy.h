#ifndef ENEMY_H_
#define ENEMY_H_

#include "../Character.h"

class Enemy : public Character {
public:
	Enemy() :Character() {}
	virtual ~Enemy() {}

public:
	//void Update()override;
	virtual void Draw() = 0;

};

#endif