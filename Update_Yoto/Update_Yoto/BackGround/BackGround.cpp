#include "BackGround.h"
#include "../3DLibrary/3DLibrary/Texture/Texture.hpp"

BackGround::BackGround()
{
	m_transition_x = 0.0f;
	m_transition_y = 0.0f;

	// 後ろ
	m_bg[0] = {
		0.0f,0.0f,1024.0f,
		0.0f,0.0f,
		1024.0f,1024.0f,
		0xffff,
		0.0f,0.0f,0.0f,
		1.0f,1.0f,
	};
	// 下
	m_bg[1] = {
		0.0f,0.0f,0.0f,
		0.0f,0.0f,
		1024.0f,1024.0f,
		0xffff,
		90.0f,0.0f,0.0f,
		1.0f,1.0f,
	};
	// 左
	m_bg[2] = {
		0.0f,0.0f,0.0f,
		0.0f,0.0f,
		1024.0f,1024.0f,
		0xffff,
		0.0f,-90.0f,0.0f,
		1.0f,1.0f,
	};
	// 右
	m_bg[3] = {
		-1024.0f,0.0f,1024.0f,
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
	gp->Draw3D(m_bg[2], tex->GetTexture(background));
	gp->Draw3D(m_bg[3], tex->GetTexture(background));
}

void BackGround::TransitionDraw()
{
	Graphics* gp = Graphics::GetGraphicInstance();
	cTexture* tex = cTexture::GetTextureInstance();
	gp->DrawTexture(m_transition_x, m_transition_y, tex->GetTexture(transition));
}

void BackGround::MoveTransitionScene()
{
	m_transition_x -= 10.0f;
}

bool BackGround::TransitionSceneLower()
{
	if (m_transition_x <= -2048.0f)
	{
		return true;	// 設置できている
	}
	else
	{
		return false;	// 設置できていない
	}
}

void BackGround::TransitionSceneSetToRight()
{
	if (m_transition_x <= -2048)
	{
		m_transition_x = 2048.0f;
	}
}

bool BackGround::TransitionSceneInstall()
{
	if (m_transition_x <= 0.0f)
	{
		return true;	// 設置できている
	}
	else
	{
		return false;	// 設置できていない
	}
}