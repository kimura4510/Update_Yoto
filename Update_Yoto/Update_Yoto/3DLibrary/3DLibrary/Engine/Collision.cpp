#include "Collision.hpp"

bool Collision::IsHitCaracter(Rect charaA, Rect charaB)
{
	//!< ���S���W�̊���o��
	float xa, xb, ya, yb;
	//!< �L����A
	xa = charaA.m_x + charaA.m_width / 2;
	ya = charaA.m_y + charaA.m_height / 2;
	//!< �L����B
	xb = charaB.m_x + charaB.m_width / 2;
	yb = charaB.m_y + charaB.m_height / 2;

	//!< ���S���W���m�̋�����X,Y���ꂼ��Z�o
	float distanceX, distanceY;
	distanceX = fabsf(xa - xb);
	distanceY = fabsf(ya - yb);

	//!< �}�`�̑傫���̘a���Z�o
	float SizeX, SizeY;
	SizeX = (charaA.m_width + charaB.m_width) / 2;
	SizeY = (charaA.m_height + charaB.m_height) / 2;

	//!< �����Ƒ傫���̘a���r���A�������Ă��邩�𔻒�
	if (distanceX < SizeX && distanceY < SizeY)
	{
		return true;
	}
		return false;
}