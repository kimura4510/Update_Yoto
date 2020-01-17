#ifndef FOX_H_
#define FOX_H_

#include "../Enemy.h"

class Fox :public Enemy {
public:
	Fox();
	virtual ~Fox() {}

public:
	void Draw()override;

};

#endif