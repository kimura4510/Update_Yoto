#ifndef SINSENGUMI_H_
#define SINSENGUMI_H_

#include "../Enemy.h"

class Sinsengumi :public Enemy {
public:
	Sinsengumi();
	virtual ~Sinsengumi() {}

public:
	void Draw()override;

};

#endif