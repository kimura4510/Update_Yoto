/**
* @file Input.h
* @brief ���͂Ɋ֌W����֐��A�萔�̐錾
*/

#ifndef DIRECTINPUT_H_
#define DIRECTINPUT_H_

#include <dinput.h>
#include <vector>

// @brife �L�[�̎��
enum KEY_INFO
{
	UP_KEY,
	DOWN_KEY,
	RIGHT_KEY,
	LEFT_KEY,
	ENTER_KEY,
	ESCAPE_KEY,
	SPACE_KEY,
	MAX_KEY_INFO,
};

//	@brief ���͏�Ԃ̎��
enum INPUT_STATE
{
	NOT_PUSH,		//������Ă��Ȃ�
	PUSH_DOWN,		//�����ꂽ�u��
	PUSH,			//������Ă���
	RELEASE,		//�������u��
};


class Input
{
public:
	/**
	* @brief Input�@�\�̏������֐�@n
	* �f�o�C�X�̓��͎擾�ɕK�v�ȏ��������s���܂�
	* InitEngine�Ŏ��s�����̂ŊJ���������s����K�v�͂���܂���
	* @return ���������ʁA�����̏ꍇ��true
	* @param[in] hInstance �C���X�^���X�n���h��
	* @param[in] hWindow �E�B���h�E�n���h��
	*/
	bool InitInput(HINSTANCE hInstance, HWND hWindow);

	/**
	* @brief Input�@�\�̏I���֐�@n
	* Input�@�\���I�������܂�@n
	* EndEngine�Ŏ��s�����̂ŊJ���������s����K�v�͂���܂���
	*/
	void ReleaseInput();

	/**
	* @brief Joystick�̏������֐�
	* �W���C�X�e�B�b�N���g�p�\�ɂ��鏈�����s���܂�
	* @return ���������ʁA�����̏ꍇ��true
	*/
	bool InitJoystick(HWND hw);

	/**
	* @brief �L�[�{�[�h�̓��͏��̍X�V@n
	* �f�o�C�X�̓��͏��̍X�V���s���܂�@n
	* ���t���[����1�x�K�����s����K�v������܂�
	*/
	void UpdateKeyState();

	/**
	* @brief Joystick�̓��͏��̍X�V
	* �W���C�X�e�B�b�N�̓��͏��̍X�V���s���܂�
	*/
	void UpdateJoystickState();

	/**
	* @brief �L�[��������Ă����Ԃ̔���֐�@n
	* �w�肵���L�[��������Ă��邩�𔻒肵�܂�
	* @return ���茋�ʁA������Ă���Ȃ�true
	* @param[in] key ���肵�����L�[
	*/
	bool GetKey(KEY_INFO key);

	/**
	* @brief �L�[�������ꂽ�u�Ԃ̔���֐�@n
	* �w�肵���L�[�������ꂽ�u�ԉ��𔻒肵�܂�
	* @return ���茋�ʁA�����ꂽ�u�ԂȂ�true
	* @param[in] key ���肵�����L�[
	*/
	bool GetKeyDown(KEY_INFO key);

	/**
	* @brief �L�[�������ꂽ�u�Ԃ̔���֐�@n
	* �w�肵���L�[�������ꂽ�u�ԉ��𔻒肵�܂�
	* @return ���茋�ʁA�����ꂽ�Ȃ�true
	* @param[in] key ���肵�����L�[
	*/
	bool GetKeyRelease(KEY_INFO key);

	//�V���O���g��
		/**
	* @brief �C���X�^���X�����֐�@n
	* Input�N���X�̃C���X�^���X�𐶐�����֐��ł�@n
	*/
	static void CreateInputInstance()
	{
		if (IsInputInstance_NULL() == true)
		{
			p_InputInstance = new Input;
		}
	}

	/**
	* @brief �C���X�^���X�j���֐�@n
	* Input�N���X�̃C���X�^���X��j������֐��ł�@n
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
	* @brief �C���X�^���X�m�F�֐�@n
	* Input�N���X�̃C���X�^���X�̗L�����m�F����֐��ł�@n
	*/
	static bool IsInputInstance_NULL()
	{
		return p_InputInstance == NULL;
	}

	/**
	* @brief �C���X�^���X�擾�֐�@n
	* Input�N���X�̃C���X�^���X���擾����֐��ł�@n
	*/
	static Input* GetInputInstance()
	{
		return p_InputInstance;
	}

private:
	static BOOL CALLBACK EnumJoysticksCallback(const LPCDIDEVICEINSTANCE pdevins, LPVOID pContext);

	static BOOL CALLBACK EnumAxesCallback(const LPDIDEVICEOBJECTINSTANCE pdevobjins, LPVOID pContext);

private:
	LPDIRECTINPUT8 g_InputInterface;	// �C���v�b�g�C���^�[�t�F�C�X
	LPDIRECTINPUTDEVICE8 g_KeyDevice;	// �C���v�b�g�f�o�C�X(�L�[�{�[�h)
	LPDIRECTINPUTDEVICE8 m_JoyDevice;	// �C���v�b�g�f�o�C�X(�W���C�X�e�B�b�N)
	DIDEVCAPS m_DiDevCaps;				// �W���C�X�e�B�b�N�̔\�͏��

	INPUT_STATE g_InputState[KEY_INFO::MAX_KEY_INFO];

	int g_KeyInfo[7] = {
		DIK_UP,
		DIK_DOWN,
		DIK_RIGHT,
		DIK_LEFT,
		DIK_RETURN,
		DIK_ESCAPE,
		DIK_SPACE,
	};

	//�V���O���g��
	Input();		//�R���X�g���N�^
	~Input();	//�f�X�g���N�^

	static Input* p_InputInstance;

};

#endif