/**
* @file Window.h
* @brief �E�B���h�E�Ɋ֌W����O�����J�֐��A�萔�̐錾
*/

#ifndef WINDOW_H_
#define WINDOW_H_

#include <Windows.h>

#define WINDOW_CLASS_NAME "Window" //�E�B���h�E�N���X��

/** �E�B���h�E�쐬�Ɋւ���N���X*/
class Window
{
public:
	/** �E�B���h�E���쐬����֐�@n
	* �����Ŏw�肳�ꂽ���e�ŃE�B���h�E���쐬���܂�
	* @return �쐬���ʁA�����̏ꍇ��true
	* @param[in] instance �C���X�^���X�n���h��
	* @param[in] width ����
	* @param[in] height �c��
	* @param[in] title �^�C�g���o�[�ɕ\������镶����
	*/
	HWND MakeWindow(HINSTANCE instance, int width, int height, const char* title);
};

#endif