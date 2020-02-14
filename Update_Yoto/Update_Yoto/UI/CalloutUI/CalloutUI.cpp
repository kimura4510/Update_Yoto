#include"../CalloutUI/CalloutUI.h"
#include"../../3DLibrary/3DLibrary/Engine/Graphics.hpp"
#include"../../3DLibrary/3DLibrary/Texture/Texture.hpp"
#include"../../TextureId/TextureId.h"
#include <time.h>

CalloutUI::CalloutUI()
{
	Init();
}

void CalloutUI::Init()
{
	m_ison = false;
	m_x = 0.0f;
	m_y = 0.0f;
	m_z = 256.0f;

	srand((unsigned int)time(NULL));
	m_time_to_count_out = rand() % 180 + 420;
	m_push_flame_count = 0;

	m_callout_state = rand() % 4;
}

void CalloutUI::Update()
{
	m_push_flame_count++;
	if (m_push_flame_count == m_time_to_count_out)
	{
		m_ison = true;
		m_push_flame_count = 0;
	}
}

void CalloutUI::Draw() {
	if (m_ison == true)
	{
		Graphics* gp = Graphics::GetGraphicInstance();
		cTexture* tex = cTexture::GetTextureInstance();
		
		// 分割して描画


		switch (static_cast<BUTTOM_UI>(m_callout_state))
		{
		case BUTTOM_UI::A:
			Graphics::GetGraphicInstance()->DrawIntegratedImage(
				(float)710.f,
				(float)190.f,
				tex->GetTexture(calloutui_tex),
				0.25f,
				0.25f,
				500.f,
				500.f,
				1,
				1
			);
			break;
		case BUTTOM_UI::B:
			Graphics::GetGraphicInstance()->DrawIntegratedImage(
				(float)710.f,
				(float)190.f,
				tex->GetTexture(calloutui_tex),
				0.25f,
				0.25f,
				500.f,
				500.f,
				2,
				1
			);
			break;
		case BUTTOM_UI::X:
			Graphics::GetGraphicInstance()->DrawIntegratedImage(
				(float)710.f,
				(float)190.f,
				tex->GetTexture(calloutui_tex),
				0.25f,
				0.25f,
				500.f,
				500.f,
				3,
				1
			);
			break;
		case BUTTOM_UI::Y:
			Graphics::GetGraphicInstance()->DrawIntegratedImage(
				(float)710.f,
				(float)190.f,
				tex->GetTexture(calloutui_tex),
				0.25f,
				0.25f,
				500.f,
				500.f,
				4,
				1
			);
			break;
		default:
			break;
		}
	}
}

bool CalloutUI::IsOn()
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

void CalloutUI::IsNotOn()
{
	m_ison = false;
}