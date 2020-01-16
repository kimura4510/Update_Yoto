#include "Collision.hpp"

bool Collision::IsHitCaracter(Rect charaA, Rect charaB)
{
	//!< ’†SÀ•W‚ÌŠ„‚èo‚µ
	float xa, xb, ya, yb;
	//!< ƒLƒƒƒ‰A
	xa = charaA.m_x + charaA.m_width / 2;
	ya = charaA.m_y + charaA.m_height / 2;
	//!< ƒLƒƒƒ‰B
	xb = charaB.m_x + charaB.m_width / 2;
	yb = charaB.m_y + charaB.m_height / 2;

	//!< ’†SÀ•W“¯Žm‚Ì‹——£‚ðX,Y‚»‚ê‚¼‚êŽZo
	float distanceX, distanceY;
	distanceX = fabsf(xa - xb);
	distanceY = fabsf(ya - yb);

	//!< }Œ`‚Ì‘å‚«‚³‚Ì˜a‚ðŽZo
	float SizeX, SizeY;
	SizeX = (charaA.m_width + charaB.m_width) / 2;
	SizeY = (charaA.m_height + charaB.m_height) / 2;

	//!< ‹——£‚Æ‘å‚«‚³‚Ì˜a‚ð”äŠr‚µA“–‚½‚Á‚Ä‚¢‚é‚©‚ð”»’è
	if (distanceX < SizeX && distanceY < SizeY)
	{
		return true;
	}
		return false;
}