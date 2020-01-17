#include "CutIn.h"
#include "../../3DLibrary/3DLibrary/Engine/Graphics.hpp"

CutIn::CutIn(DrawMethod method_, CutInType type_, float x_, float y_)
{
	m_method = method_;
	m_type = type_;
	m_x = x_;
	m_y = y_;
	m_p_tex = cTexture::GetTextureInstance()->
		GetTexture(r_cutin_tex);
	m_tu = 0.11621094f;
	m_tv = 0.52441406f;
	m_sprite_width = 952.0f;		// (1/8192)*952	
	m_sprite_height = 537.0f;		// (1/1024)*537
	m_sprite_num_x = 1;
	m_sprite_num_y = 1;

	m_ison = false;
	m_set_count = 60;
	m_down_count = 60;
}

void CutIn::Update()
{
	m_ison = true;
	if (m_ison == true)
	{
		m_down_count--;
		if (m_down_count <= 0)
		{
			m_ison = false;
			m_down_count = m_set_count;
		}
	}
}

void CutIn::Draw()
{
	if (m_method == DrawMethod::RIGHT)
	{
		m_p_tex = cTexture::GetTextureInstance()->GetTexture(r_cutin_tex);
		switch (m_type)
		{
		case CutInType::PLAYER:
			m_sprite_num_x = 1;
			break;
		case CutInType::DRAWER:
			m_sprite_num_x = 2;
			break;
		case CutInType::PERRY:
			m_sprite_num_x = 3;
			break;
		case CutInType::HERMIT:
			m_sprite_num_x = 4;
			break;
		case CutInType::SINSENGUMI:
			m_sprite_num_x = 5;
			break;
		case CutInType::FOX:
			m_sprite_num_x = 6;
			break;
		default:
			break;
		}
	}
	else
	{
		m_p_tex = cTexture::GetTextureInstance()->GetTexture(l_cutin_tex);
		switch (m_type)
		{
		case CutInType::PLAYER:
			m_sprite_num_x = 1;
			break;
		case CutInType::DRAWER:
			m_sprite_num_x = 2;
			break;
		case CutInType::PERRY:
			m_sprite_num_x = 3;
			break;
		case CutInType::HERMIT:
			m_sprite_num_x = 4;
			break;
		case CutInType::SINSENGUMI:
			m_sprite_num_x = 5;
			break;
		case CutInType::FOX:
			m_sprite_num_x = 6;
			break;
		default:
			break;
		}
	}

	Graphics* gp = Graphics::GetGraphicInstance();
	cTexture* tex = cTexture::GetTextureInstance();
	if (m_ison == true)
	{
		gp->DrawIntegratedImage(
			m_x, m_y,
			m_p_tex,
			m_tu, m_tv,
			m_sprite_width, m_sprite_height,
			m_sprite_num_x, m_sprite_num_y);
	}
}

bool CutIn::IsOn()
{
	if (m_ison == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CutIn::IsNotOn()
{
	m_ison = false;
}