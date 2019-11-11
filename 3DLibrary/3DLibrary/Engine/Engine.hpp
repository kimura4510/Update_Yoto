/**
* @file Engine.h
* @brief �G���W������(�`��A����)�Ɋւ���֐��A�萔�̐錾
*/
#ifndef ENGINE_H_
#define ENGINE_H_

class Engine
{
public:
	/**
* @brief �G���W���������̊֐�@n
* �Q�[���Ŏg���G���W������(�`��A����)�̏��������s���܂�@n
* ���̊֐��̓Q�[�����[�v�̊J�n�O��1�x�������s���Ă�������
* @return ���������ʁA�����̏ꍇ��true
*/
	bool InitEngine(HINSTANCE hInstance, HWND hW);

	/**
	* @brief �G���W���I���̊֐�@n
	* �Q�[���I����ɃG���W�������̏I�����s���܂�@n
	* ���̊֐��̓Q�[�����[�v�I�����1�x�������s���Ă�������
	*/
	void EndEngine();
};

#endif
