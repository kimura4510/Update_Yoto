/**
* @file Input.h
* @brief 入力に関係する関数、定数の宣言
*/

#ifndef DIRECTINPUT_H_
#define DIRECTINPUT_H_

#include <dinput.h>
#include <vector>

// @brife キーの種類
enum KEY_INFO
{
	UP_KEY,
	DOWN_KEY,
	RIGHT_KEY,
	LEFT_KEY,
	ENTER_KEY,
	ESCAPE_KEY,
	SPACE_KEY,
	W_KEY,
	A_KEY,
	S_KEY,
	D_KEY,
	MAX_KEY_INFO,
};

//!< @brief ゲームパッドの入力種類
enum class GAMEPAD_BUTTONS
{
	A,
	B,
	X,
	Y,
	R1,
	R2,
	L1,
	L2, 
	lUp,
	lDown,
	lLeft,
	lRight,
	rUp,
	rDown,
	rLeft,
	rRight,
	UpArrow,
	DownArrow,
	LeftArrow,
	RightArrow,
	MAX_INFO,
};

//	@brief 入力状態の種類
enum INPUT_STATE
{
	NOT_PUSH,		//押されていない
	PUSH_DOWN,		//押された瞬間
	PUSH,			//押されている
	RELEASE,		//離した瞬間
};


class Input
{
public:
	/**
	* @brief Input機能の初期化関数@n
	* デバイスの入力取得に必要な初期化を行います
	* InitEngineで実行されるので開発側が実行する必要はありません
	* @return 初期化結果、成功の場合はtrue
	* @param[in] hInstance インスタンスハンドル
	* @param[in] hWindow ウィンドウハンドル
	*/
	bool InitInput(HINSTANCE hInstance, HWND hWindow);

	/**
	* @brief Input機能の終了関数@n
	* Input機能を終了させます@n
	* EndEngineで実行されるので開発側が実行する必要はありません
	*/
	void ReleaseInput();

	/**
	* @brief Joystickの初期化関数
	* ジョイスティックを使用可能にする処理を行います
	* @return 初期化結果、成功の場合はtrue
	*/
	bool CreateGamePadDevice(HWND hw);

	/**
	* @brief キーボードの入力情報の更新@n
	* デバイスの入力情報の更新を行います@n
	* 毎フレームに1度必ず実行する必要があります
	*/
	void UpdateKeyState();

	/**
	* @brief Joystickの入力情報の更新
	* ジョイスティックの入力情報の更新を行います
	*/
	void UpdateGamePad();

	/**
	* @brief キーが押されている状態の判定関数@n
	* 指定したキーが押されているかを判定します
	* @return 判定結果、押されているならtrue
	* @param[in] key 判定したいキー
	*/
	bool GetKey(KEY_INFO key);

	/**
	* @brief キーが押された瞬間の判定関数@n
	* 指定したキーが押された瞬間化を判定します
	* @return 判定結果、押された瞬間ならtrue
	* @param[in] key 判定したいキー
	*/
	bool GetKeyDown(KEY_INFO key);

	/**
	* @brief キーが離された瞬間の判定関数@n
	* 指定したキーが離された瞬間化を判定します
	* @return 判定結果、離されたならtrue
	* @param[in] key 判定したいキー
	*/
	bool GetKeyRelease(KEY_INFO key);

	/**
	* @biref ゲームパッドの入力状態取得関数
	* 指定した番号のゲームパッドのボタンの入力状態を返します
	* @return 
	*/
	INPUT_STATE GetGamePadBottonState(int num, GAMEPAD_BUTTONS button);

	//シングルトン
		/**
	* @brief インスタンス生成関数@n
	* Inputクラスのインスタンスを生成する関数です@n
	*/
	static void CreateInputInstance()
	{
		if (IsInputInstance_NULL() == true)
		{
			p_InputInstance = new Input;
		}
	}

	/**
	* @brief インスタンス破棄関数@n
	* Inputクラスのインスタンスを破棄する関数です@n
	*/
	static void DestroyInputInstance()
	{
		if (IsInputInstance_NULL() == false)
		{
			delete p_InputInstance;
			p_InputInstance = NULL;
		}
	}

	/**
	* @brief インスタンス確認関数@n
	* Inputクラスのインスタンスの有無を確認する関数です@n
	*/
	static bool IsInputInstance_NULL()
	{
		return p_InputInstance == NULL;
	}

	/**
	* @brief インスタンス取得関数@n
	* Inputクラスのインスタンスを取得する関数です@n
	*/
	static Input* GetInputInstance()
	{
		return p_InputInstance;
	}

private:
	static BOOL CALLBACK EnumJoysticksCallback(const LPCDIDEVICEINSTANCE pdevins, LPVOID pContext);

	static bool SetGamePadPropaty(LPDIRECTINPUTDEVICE8 device);

	bool RestartGamePad(LPDIRECTINPUTDEVICE8 device, int num);

private:
	static const int MaxGamePadNum = 2;
	static const int Unresponsive_Range = 200;

	static LPDIRECTINPUT8 m_InputInterface;	// インプットインターフェイス
	LPDIRECTINPUTDEVICE8 m_KeyDevice;	// インプットデバイス(キーボード)
	LPDIRECTINPUTDEVICE8 m_GamePadDevices[MaxGamePadNum];	// インプットデバイス(ジョイスティック)

	INPUT_STATE g_InputState[KEY_INFO::MAX_KEY_INFO];
	int g_KeyInfo[11] = {
		DIK_UP,
		DIK_DOWN,
		DIK_RIGHT,
		DIK_LEFT,
		DIK_RETURN,
		DIK_ESCAPE,
		DIK_SPACE,
		DIK_W,
		DIK_A,
		DIK_S,
		DIK_D,
	};

	//!< ゲームパッドの入力状態保持配列
	INPUT_STATE m_GamePadState[MaxGamePadNum][static_cast<int>(GAMEPAD_BUTTONS::MAX_INFO)];

	private:
	//シングルトン
	Input();		//コンストラクタ
	~Input();	//デストラクタ

	static Input* p_InputInstance;

};

#endif