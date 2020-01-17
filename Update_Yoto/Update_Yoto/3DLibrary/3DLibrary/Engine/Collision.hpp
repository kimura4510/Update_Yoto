#include <math.h>

struct Rect
{
	float m_x;
	float m_y;
	float m_width;
	float m_height;
};

class Collision
{
public:
	bool IsHitCaracter(Rect CharaA, Rect CharaB);
};