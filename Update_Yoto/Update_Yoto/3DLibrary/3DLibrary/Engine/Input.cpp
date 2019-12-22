#include "Input.hpp"
#include <dinput.h>

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")
Input* Input::p_InputInstance = NULL;

bool Input::InitInput(HINSTANCE hI, HWND hW)
{
	HRESULT hr = DirectInput8Create(hI, 
		DIRECTINPUT_VERSION,
		IID_IDirectInput8,
		(void**)& g_InputInterface,
		NULL);

	if (FAILED(hr))
	{
		MessageBox(hW, (char*)"error", (char*)"errorA", MB_OK);
		return false;
	}

	hr = g_InputInterface->CreateDevice(GUID_SysKeyboard, &g_KeyDevice, NULL);

	if (FAILED(hr))
	{
		MessageBox(hW, (char*)"error", (char*)"errorB", MB_OK);
		return false;
	}

	hr = g_KeyDevice->SetDataFormat(&c_dfDIKeyboard);

	if (FAILED(hr))
	{
		MessageBox(hW, (char*)"error", (char*)"errorC", MB_OK);
		return false;
	}

	hr = g_KeyDevice->SetCooperativeLevel(hW, DISCL_BACKGROUND | DISCL_NONEXCLUSIVE);

	if (FAILED(hr))
	{
		MessageBox(hW, (char*)"error", (char*)"errorD", MB_OK);
		return false;
	}

	hr = g_KeyDevice->Acquire();

	return true;
}

BOOL CALLBACK Input::EnumJoysticksCallback(LPCDIDEVICEINSTANCE pDevIns, LPVOID pContext)
{
	HRESULT hr;
	hr = g_InputInterface->CreateDevice(pDevIns->guidInstance, &m_JoyDevice, NULL);
	if (FAILED(hr))
	{
		return DIENUM_CONTINUE;
	}

	m_DiDevCaps.dwSize = sizeof(DIDEVCAPS);
	hr = m_JoyDevice->GetCapabilities(&m_DiDevCaps);
	if (FAILED(hr))
	{
		m_JoyDevice->Release();
		m_JoyDevice = nullptr;
		return DIENUM_CONTINUE;
	}

	return DIENUM_STOP;
}

bool Input::InitJoystick(HWND hw)
{
	HRESULT hr = g_InputInterface->EnumDevices(DI8DEVCLASS_GAMECTRL, this->EnumJoysticksCallback, NULL, DIEDFL_ATTACHEDONLY);
	if (FAILED(hr) || m_JoyDevice == nullptr)
	{
		return false;
	}
}

void Input::ReleaseInput()
{
	g_KeyDevice->Unacquire();
	g_KeyDevice->Release();
	g_InputInterface->Release();
}

void Input::KeyStateUpdate()
{
	BYTE Key[256];

	HRESULT hr = g_KeyDevice->GetDeviceState(256, Key);

	if (FAILED(hr))
	{
		return;
	}

	for (int i = 0; i < MAX_KEY_INFO; i++)
	{
		if (Key[g_KeyInfo[i]] & 0x80)
		{
			if (g_InputState[i] == INPUT_STATE::NOT_PUSH || g_InputState[i] == INPUT_STATE::RELEASE)
			{
				g_InputState[i] = INPUT_STATE::PUSH_DOWN;
			}
			else
			{
				g_InputState[i] = INPUT_STATE::PUSH;
			}
		}
		else
		{
			if (g_InputState[i] == INPUT_STATE::PUSH || g_InputState[i] == INPUT_STATE::PUSH_DOWN)
			{
				g_InputState[i] = INPUT_STATE::RELEASE;
			}
			else
			{
				g_InputState[i] = INPUT_STATE::NOT_PUSH;
			}
		}
	}

}

bool Input::GetKey(KEY_INFO key)
{
	return (g_InputState[key] == INPUT_STATE::PUSH);
}

bool Input::GetKeyDown(KEY_INFO key)
{
	return (g_InputState[key] == INPUT_STATE::PUSH_DOWN);
}

bool Input::GetKeyRelease(KEY_INFO key)
{
	return (g_InputState[key] == INPUT_STATE::RELEASE);
}

Input::Input()
{
	g_InputInterface = nullptr;
	g_KeyDevice = nullptr;
}

Input::~Input()
{

}