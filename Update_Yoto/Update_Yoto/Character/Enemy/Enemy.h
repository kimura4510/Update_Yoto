#ifndef ENEMY_H_
#define ENEMY_H_

#include "../Character.h"

class Enemy : public Character {
public:
	Enemy() :Character() {}
	virtual ~Enemy() {}

public:
	virtual void Draw() = 0;

};

#endif