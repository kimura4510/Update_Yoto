#ifndef CAMERA_H_
#define CAMERA_H_

#include "../GameDefinition.h"

struct CameraParam
{
	float m_eye_x;	//���_x
	float m_eye_y;	//���_y
	float m_eye_z;	//���_z

	float m_pos_x;	//�ʒux
	float m_pos_y;	//�ʒuy
	float m_pos_z;	//�ʒuz
};

class Camera
{
public:

	/**
	* @brief �J�����̏������֐�
	* �J�����̃p�����[�^(���W�ƒ����_)�����������܂�
	* @param[in] x_ x���W
	* @param[in] y_ y���W
	* @param[in] z_ z���W
	* @param[in] ex �����_x���W
	* @param[in] ey �����_y���W
	* @param[in] ez �����_z���W
	*/
	void InitCamera(float x_, float y_, float z_, float ex=0.0f, float ey=0.0f, float ez=0.0f);
	
	/**
	* @biref �J�����̊J���֐�
	*/
	void ReleaseCamera();

	/**
	* @biref �J�����̍X�V�֐�
	* �J�����̍��W�⒍���_�̍X�V���s���܂��B���t���[�����s���Ă��������B
	*/
	void UpdateCamera();

	/**
	* @biref �J�����̍��W�ύX�֐�
	* ��Ԃɉ����ăJ�����̍��W��ύX���܂�
	* param[in] state_ �ύX�������J�����̏��
	*/
	void ChangeCameraPos(CameraState state_);

private:
	void ChangeBattleMovement();
	void ChangeWinPos();
	void ChangeLosePos();
	void ChangeClearMovement();
	void ChangeGameoverMovement();

public:
	//�V���O���g��
	//���̂𐶐�����֐�
	static void CreateInstance()
	{
		if (IsCameraNull() == true)
		{
			p_CameraInstance = new Camera;
		}
	}

	//���̂�j������֐�
	static void DestroyInstance()
	{
		if (IsCameraNull() == false)
		{
			delete p_CameraInstance;
			p_CameraInstance = nullptr;
		}
	}

	//���̂̑��݂��m�F����֐�
	static bool IsCameraNull()
	{
		return p_CameraInstance == nullptr;
	}

	//���̂��擾����֐�
	static Camera* GetCameraInstance()
	{
		return p_CameraInstance;
	}

private:
	void MoveCamera();

	Camera();		//�R���X�g���N�^
	~Camera() { }		//�f�X�g���N�^

	static Camera* p_CameraInstance;	//�C���X�^���X

	CameraParam camera_param;
	CameraState camera_state;
	int counter;
	const float Length;
	float angle;
	const float setAngle;
};
#endif // !CAMERA_H_
