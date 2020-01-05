#ifndef HERMIT_H_
#define HERMIT_H_

#include "../Enemy.h"

class Hermit :public Enemy {
public:
	Hermit();
	virtual ~Hermit() {}

public:
	void Init()override;
	void Draw()override;
	void Update()override;

};

#endif