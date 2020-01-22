#include "CutIn.h"
#include "../../3DLibrary/3DLibrary/Engine/Graphics.hpp"

CutIn::CutIn(DrawMethod method_, CutInType type_)
{
	m_method = method_;
	m_type = type_;
	m_x = 0.0f;
	m_y = 0.0f;
	m_p_tex = cTexture::GetTextureInstance()->GetTexture(r_cutin_fox_tex);
	m_tu = 0.1953125;				// (1/8192)*1600
	m_tv = 0.5f;					// 1/2
	m_sprite_width = 1600.0f;		//38.4
	m_sprite_height = 1024.0f;
	m_sprite_x = 5;
	m_sprite_y = 2;

	m_ison = false;
	m_count = 0.0f;
}

void CutIn::Update()
{
	m_ison = true;
	if (m_ison == true)
	{
		m_count += 0.2f;
		if (m_count >= 9.0f)
		{
			m_ison = false;
			m_count = 0.0f;
		}
	}
}

void CutIn::Draw()
{
	if (m_method == DrawMethod::RIGHT)
	{
		m_x = 320.0f;
		switch (m_type)
		{
		case CutInType::PLAYER:
			m_p_tex = cTexture::GetTextureInstance()->GetTexture(r_cutin_player_tex);
			break;
		case CutInType::DRAWER:
			m_p_tex = cTexture::GetTextureInstance()->GetTexture(r_cutin_drawer_tex);
			break;
		case CutInType::PERRY:
			m_p_tex = cTexture::GetTextureInstance()->GetTexture(r_cutin_perry_tex);
			break;
		case CutInType::HERMIT:
			m_p_tex = cTexture::GetTextureInstance()->GetTexture(r_cutin_hermit_tex);
			break;
		case CutInType::SINSENGUMI:
			m_p_tex = cTexture::GetTextureInstance()->GetTexture(r_cutin_sinsengumi_tex);
			break;
		case CutInType::FOX:
			m_p_tex = cTexture::GetTextureInstance()->GetTexture(r_cutin_fox_tex);
			break;
		default:
			break;
		}
	}
	else
	{
		switch (m_type)
		{
		case CutInType::PLAYER:
			m_p_tex = cTexture::GetTextureInstance()->GetTexture(l_cutin_player_tex);
			break;
		case CutInType::DRAWER:
			m_p_tex = cTexture::GetTextureInstance()->GetTexture(l_cutin_drawer_tex);
			break;
		case CutInType::PERRY:
			m_p_tex = cTexture::GetTextureInstance()->GetTexture(l_cutin_perry_tex);
			break;
		case CutInType::HERMIT:
			m_p_tex = cTexture::GetTextureInstance()->GetTexture(l_cutin_hermit_tex);
			break;
		case CutInType::SINSENGUMI:
			m_p_tex = cTexture::GetTextureInstance()->GetTexture(l_cutin_sinsengumi_tex);
			break;
		case CutInType::FOX:
			m_p_tex = cTexture::GetTextureInstance()->GetTexture(l_cutin_fox_tex);
			break;
		default:
			break;
		}
	}

	Graphics* gp = Graphics::GetGraphicInstance();
	cTexture* tex = cTexture::GetTextureInstance();
	if (m_ison == true)
	{
		gp->Animation2D(
			m_x, m_y,
			m_p_tex,
			m_tu, m_tv,
			m_sprite_width, m_sprite_height,
			m_sprite_x, m_sprite_y,
			(int)m_count % 9
		);
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