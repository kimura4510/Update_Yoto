#include "Input.hpp"
#include <dinput.h>
#include <functional>

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")
Input* Input::p_InputInstance = NULL;

struct DeviceEnumParam
{
	LPDIRECTINPUTDEVICE8* GamePadDevList;
	int FindCount;
};

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
	DeviceEnumParam* param = dynamic_cast<DeviceEnumParam*>(pContext);
	HRESULT hr;

	hr = param->GamePadDevList->CreateDevice(pDevIns->guidInstance, &pDIDev, NULL);
	if (FAILED(hr))
	{
		return DIENUM_CONTINUE;
	}

	pDIDevCap.dwSize = sizeof(DIDEVCAPS);
	hr = pDIDev->GetCapabilities(&pDIDevCap);
	if (FAILED(hr))
	{
		pDIDev->Release();
		pDIDev = nullptr;
		return DIENUM_CONTINUE;
	}

	return DIENUM_STOP;
}

BOOL CALLBACK Input::EnumAxesCallback(const LPDIDEVICEOBJECTINSTANCE pdevobjins, LPVOID pContext, LPDIRECTINPUTDEVICE8 pDIDev)
{
	HRESULT hr;
	DIPROPRANGE diprop;

	diprop.diph.dwSize = sizeof(DIPROPRANGE);
	diprop.diph.dwHeaderSize = sizeof(DIPROPHEADER);
	diprop.diph.dwHow = DIPH_BYID;
	diprop.diph.dwObj = pdevobjins->dwType;
	diprop.lMin = -1000;
	diprop.lMax = 1000;

	hr = pDIDev->SetProperty(DIPROP_RANGE, &diprop.diph);
	if (FAILED(hr))
	{
		return DIENUM_STOP;
	}

	return DIENUM_STOP;
}


bool Input::InitJoystick(HWND hw)
{
	HRESULT hr = g_InputInterface->EnumDevices(DI8DEVCLASS_GAMECTRL, EnumJoysticksCallback, this, DIEDFL_ATTACHEDONLY);
	if (FAILED(hr) || m_JoyDevice == nullptr)
	{
		return false;
	}

	hr = m_JoyDevice->SetDataFormat(&c_dfDIJoystick);
	if (FAILED(hr))
	{
		return false;
	}

	hr = m_JoyDevice->SetCooperativeLevel(hw, DISCL_BACKGROUND | DISCL_NONEXCLUSIVE);
	if (FAILED(hr))
	{
		return false;
	}

	hr = m_JoyDevice->EnumObjects(EnumAxesCallback, (LPVOID)hw, DIDFT_AXIS);
	if (FAILED(hr))
	{
		return false;
	}

	hr = m_JoyDevice->Poll();
	if (FAILED(hr))
	{
		return false;
	}

	hr = m_JoyDevice->Acquire();
	if (FAILED(hr))
	{
		return false;
	}

	return true;
}

void Input::ReleaseInput()
{
	g_KeyDevice->Unacquire();
	m_JoyDevice->Unacquire();
	g_KeyDevice->Release();
	m_JoyDevice->Release();
	g_InputInterface->Release();
}

void Input::UpdateJoystickState()
{
	DIJOYSTATE joy;
	ZeroMemory(&joy, sizeof(joy));
	HRESULT hr = m_JoyDevice->GetDeviceState(sizeof(joy), &joy);
	if (FAILED(hr))
	{
		return;
	}

	
}

void Input::UpdateKeyState()
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