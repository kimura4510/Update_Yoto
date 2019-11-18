#include "Window.hpp"
#include "Graphics.hpp"
#include "Input.hpp"
#include "Engine.hpp"
#include "../Texture/Texture.hpp"

bool Engine::InitEngine(HINSTANCE hI, HWND hW)
{
	Graphics::CreateGraphicInstance();
	Input::CreateInputInstance();
	cTexture::CreateTextureInstance();

	if (Graphics::GetGraphicInstance()->InitGraphics(hW) == false)
	{
		return false;
	}

	if (Input::GetInputInstance()->InitInput(hI, hW) == false)
	{
		return false;
	}

	return true;
}

void Engine::EndEngine()
{
	cTexture::GetTextureInstance()->AllReleaseTexture();
	cTexture::DestroyTextureInstance();
	Graphics::GetGraphicInstance()->ReleaseGraphics();
	Input::GetInputInstance()->ReleaseInput();
	Graphics::DestroyGraphicInstance();
	Input::DestroyInputInstance();
}