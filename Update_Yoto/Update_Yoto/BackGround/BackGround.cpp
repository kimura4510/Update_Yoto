#include "BackGround.h"
#include "../3DLibrary/3DLibrary/Texture/Texture.hpp"

BackGround::BackGround()
{

}

BackGround::~BackGround()
{
}

void BackGround::Init()
{
	// Œã‚ë
	m_bg[0] = {
		-256.0f,-128.0f,512.0f,
		0.0f,0.0f,
		512.0f,512.0f,
		0xffff,
		0.0f,0.0f,0.0f,
		1.0f,1.0f,
	};
	// ‰º
	m_bg[1] = {
		-256.0f,0.0f,128.0f,
		0.0f,0.0f,
		512.0f,512.0f,
		0xffff,
		90.0f,0.0f,0.0f,
		1.0f,1.0f,
	};
	// ¶
	m_bg[2] = {
		0.0f,-128.0f,256.0f,
		0.0f,0.0f,
		512.0f,512.0f,
		0xffff,
		0.0f,-90.0f,0.0f,
		1.0f,1.0f,
	};
	// ‰E
	m_bg[3] = {
		-512.f,-128.f,256.0f,
		0.0f,0.0f,
		512.0f,512.0f,
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
	gp->Draw3D(m_bg[2], tex->GetTexture(background));
	gp->Draw3D(m_bg[3], tex->GetTexture(background));
}