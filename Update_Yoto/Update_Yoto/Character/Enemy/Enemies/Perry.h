#ifndef PERRY_H_
#define PERRY_H_

#include "../Enemy.h"

class Perry :public Enemy {
public:
	Perry();
	virtual ~Perry() {}

public:
	void Draw()override;

};

#endif