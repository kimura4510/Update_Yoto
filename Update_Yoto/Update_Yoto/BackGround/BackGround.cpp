#include "BackGround.h"
#include "../3DLibrary/3DLibrary/Texture/Texture.hpp"

BackGround::BackGround()
{
	m_x = 1920.0f;
	m_y = 0.0f;

	// Œã‚ë
	m_bg[0] = {
		0.0f,0.0f,1024.0f,
		0.0f,0.0f,
		1024.0f,1024.0f,
		0xffff,
		0.0f,0.0f,0.0f,
		1.0f,1.0f,
	};
	// ‰º
	m_bg[1] = {
		0.0f,0.0f,0.0f,
		0.0f,0.0f,
		1024.0f,1024.0f,
		0xffff,
		90.0f,0.0f,0.0f,
		1.0f,1.0f,
	};
	// ¶
	m_bg[2] = {
		0.0f,0.0f,0.0f,
		0.0f,0.0f,
		1024.0f,1024.0f,
		0xffff,
		0.0f,-90.0f,0.0f,
		1.0f,1.0f,
	};
	// ‰E
	m_bg[3] = {
		0.0f,0.0f,0.0f,
		0.0f,0.0f,
		1024.0f,1024.0f,
		0xffff,
		0.0f,90.0f,0.0f,
		1.0f,1.0f,
	};
}

void BackGround::Draw()
{
	Graphics* gp = Graphics::GetGraphicInstance();
	cTexture* tex = cTexture::GetTextureInstance();
	gp->Draw3D(m_bg[0], tex->GetTexture(background));
	gp->Draw3D(m_bg[1], tex->GetTexture(ground));
	//gp->Draw3D(m_bg[2], tex->GetTexture(background));
	//gp->Draw3D(m_bg[3], tex->GetTexture(background));

	gp->DrawTexture(m_x, m_y, tex->GetTexture(transition));
}

void BackGround::Update()
{
	if (m_x > 0.0f)
	{
		m_x -= 10.0f;
	}
}

bool BackGround::TransitionSceneInstall()
{
	if (m_x <= 0.0f)
	{
		return true;	// Ý’u‚Å‚«‚Ä‚¢‚é
	}
	else
	{
		return false;	// Ý’u‚Å‚«‚Ä‚¢‚È‚¢
	}
}