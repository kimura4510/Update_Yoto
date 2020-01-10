#include "Input.hpp"
#include <dinput.h>
#include <functional>

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")
Input* Input::p_InputInstance = NULL;

struct GamePadEnumParam
{
	LPDIRECTINPUTDEVICE8* GamePadDevList;
	int FindCount;
	HWND windowhandle;
};

bool Input::InitInput(HINSTANCE hI, HWND hW)
{
	HRESULT hr = DirectInput8Create(hI, 
		DIRECTINPUT_VERSION,
		IID_IDirectInput8,
		(void**)& m_InputInterface,
		NULL);

	if (FAILED(hr))
	{
		MessageBox(hW, (char*)"error", (char*)"errorA", MB_OK);
		return false;
	}

	hr = m_InputInterface->CreateDevice(GUID_SysKeyboard, &m_KeyDevice, NULL);

	if (FAILED(hr))
	{
		MessageBox(hW, (char*)"error", (char*)"errorB", MB_OK);
		return false;
	}

	hr = m_KeyDevice->SetDataFormat(&c_dfDIKeyboard);

	if (FAILED(hr))
	{
		MessageBox(hW, (char*)"error", (char*)"errorC", MB_OK);
		return false;
	}

	hr = m_KeyDevice->SetCooperativeLevel(hW, DISCL_BACKGROUND | DISCL_NONEXCLUSIVE);

	if (FAILED(hr))
	{
		MessageBox(hW, (char*)"error", (char*)"errorD", MB_OK);
		return false;
	}

	hr = m_KeyDevice->Acquire();

	return true;
}

BOOL CALLBACK Input::EnumJoysticksCallback(LPCDIDEVICEINSTANCE pDevIns, LPVOID pContext)
{
	GamePadEnumParam* param = reinterpret_cast<GamePadEnumParam*>(pContext);

	//!< カウント数が2以上になった場合列挙終了
	if (param->FindCount >= 2)
	{
		return DIENUM_STOP;
	}

	//!< デバイスの作成
	HRESULT hr = m_InputInterface->CreateDevice(
		pDevIns->guidInstance, 
		&param->GamePadDevList[param->FindCount], 
		nullptr);
	if (FAILED(hr))
	{
		return DIENUM_STOP;
	}

	//!< データフォーマットの設定
	hr = param->GamePadDevList[param->FindCount]->SetDataFormat(&c_dfDIJoystick);
	if (FAILED(hr))
	{
		return DIENUM_STOP;
	}

	//!< 協調レベルの設定
	hr = param->GamePadDevList[param->FindCount]->SetCooperativeLevel(
		param->windowhandle,
		DISCL_NONEXCLUSIVE | DISCL_BACKGROUND);
	if (FAILED(hr))
	{
		return DIENUM_STOP;
	}

	hr = param->GamePadDevList[param->FindCount]->Poll();
	if (FAILED(hr))
	{
		return DIENUM_STOP;
	}

	param->FindCount++;

	return DIENUM_STOP;
}

bool Input::SetGamePadPropaty(LPDIRECTINPUTDEVICE8 device)
{
	DIPROPDWORD diprop;
	ZeroMemory(&diprop, sizeof(diprop));

	//!< 軸を絶対値モードに設定
	diprop.diph.dwSize = sizeof(diprop);
	diprop.diph.dwHeaderSize = sizeof(diprop.diph);
	diprop.diph.dwHow = DIPH_DEVICE;
	diprop.diph.dwObj = 0;
	diprop.dwData = DIPROPAXISMODE_ABS;
	if (FAILED(device->SetProperty(DIPROP_AXISMODE, &diprop.diph)))
	{
		return false;
	}

	//!< X軸の値の範囲設定
	DIPROPRANGE dipran;
	ZeroMemory(&dipran, sizeof(dipran));
	dipran.diph.dwSize = sizeof(dipran);
	dipran.diph.dwHeaderSize = sizeof(dipran.diph);
	dipran.diph.dwHow = DIPH_BYOFFSET;
	dipran.diph.dwObj = DIJOFS_X;
	dipran.lMin = -1000;
	dipran.lMax = 1000;
	if (FAILED(device->SetProperty(DIPROP_RANGE, &dipran.diph)));

	//!< Y軸の値の範囲設定
	dipran.diph.dwObj = DIJOFS_Y;
	if (FAILED(device->SetProperty(DIPROP_RANGE, &dipran.diph)));

	//!< BufferSizeの設定
	ZeroMemory(&diprop, sizeof(diprop));
	diprop.diph.dwSize = sizeof(diprop);
	diprop.diph.dwHeaderSize = sizeof(diprop.diph);
	diprop.diph.dwHow = DIPH_DEVICE;
	diprop.diph.dwObj = 0;
	diprop.dwData = 1000;
	if (FAILED(device->SetProperty(DIPROP_BUFFERSIZE, &diprop.diph)))
	{
		return false;
	}

	return true;
}

bool Input::CreateGamePadDevice(HWND hw)
{
	GamePadEnumParam param;
	param.FindCount = 0;		// ゲームパッドの列挙数の初期化
	param.GamePadDevList = m_GamePadDevices;
	param.windowhandle = hw;

	m_InputInterface->EnumDevices(DI8DEVCLASS_GAMECTRL, EnumJoysticksCallback, this, DIEDFL_ATTACHEDONLY);

	if (param.FindCount == 0)
	{
		return false;
	}

	//!< ゲームパッドの起動
	for (int i = 0; i < param.FindCount; i++)
	{
		if (FAILED(m_GamePadDevices[i]->Acquire()))
		{
			return false;
		}
	}

	return true;
}

void Input::ReleaseInput()
{
	for (int i = 0; i < MaxGamePadNum; i++)
	{
		if (m_GamePadDevices[i] != nullptr)
		{
			m_GamePadDevices[i]->Unacquire();
			m_GamePadDevices[i]->Release();
			m_GamePadDevices[i] = nullptr;
		}
	}

	if (m_KeyDevice != nullptr)
	{
		m_KeyDevice->Unacquire();
		m_KeyDevice->Release();
		m_KeyDevice = nullptr;
	}
	
	m_InputInterface->Release();
}

void Input::UpdateGamePad()
{
	DIJOYSTATE joy;

	for (int i = 0; i < MaxGamePadNum; i++)
	{
		if (m_GamePadDevices[i] == nullptr)
		{
			return;
		}

		HRESULT hr = m_GamePadDevices[i]->GetDeviceState(sizeof(DIJOYSTATE), &joy);
		if (FAILED(hr))
		{
			RestartGamePad(m_GamePadDevices[i], i);
		}

	}

	
}

bool Input::RestartGamePad(LPDIRECTINPUTDEVICE8 device, int num)
{
	if (FAILED(device->Acquire()))
	{
		for (int i = 0; i < static_cast<int>(GAMEPAD_INFO::MAX_INFO); i++)
		{
			m_GamePadState[num][i] = INPUT_STATE::NOT_PUSH;
		}

		return false;
	}
	return true;
}


void Input::UpdateKeyState()
{
	BYTE Key[256];

	HRESULT hr = m_KeyDevice->GetDeviceState(256, Key);

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
	m_InputInterface = nullptr;
	m_KeyDevice = nullptr;
}

Input::~Input()
{

}