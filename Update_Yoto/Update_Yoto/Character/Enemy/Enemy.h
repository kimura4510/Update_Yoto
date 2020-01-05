#ifndef ENEMY_H_
#define ENEMY_H_

#include "../Character.h"

class Enemy :public Character {
public:
	virtual ~Enemy() {}

public:
	virtual void Init() = 0;
	virtual void Draw() = 0;
	virtual void Update() = 0;


};

#endif