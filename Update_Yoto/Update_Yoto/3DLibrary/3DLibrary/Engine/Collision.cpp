#include "Collision.hpp"

bool Collision::IsHitCaracter(Rect charaA, Rect charaB)
{
	//!< 中心座標の割り出し
	float xa, xb, ya, yb;
	//!< キャラA
	xa = charaA.m_x + charaA.m_width / 2;
	ya = charaA.m_y + charaA.m_height / 2;
	//!< キャラB
	xb = charaB.m_x + charaB.m_width / 2;
	yb = charaB.m_y + charaB.m_height / 2;

	//!< 中心座標同士の距離をX,Yそれぞれ算出
	float distanceX, distanceY;
	distanceX = fabsf(xa - xb);
	distanceY = fabsf(ya - yb);

	//!< 図形の大きさの和を算出
	float SizeX, SizeY;
	SizeX = (charaA.m_width + charaB.m_width) / 2;
	SizeY = (charaA.m_height + charaB.m_height) / 2;

	//!< 距離と大きさの和を比較し、当たっているかを判定
	if (distanceX < SizeX && distanceY < SizeY)
	{
		return true;
	}
		return false;
}