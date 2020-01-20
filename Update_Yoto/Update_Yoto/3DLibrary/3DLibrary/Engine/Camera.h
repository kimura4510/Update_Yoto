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
	void InitCamera(float x_, float y_, float z_);
	void ReleaseCamera();
	void UpdateCamera();

	void ChangeCameraPos(CameraState state_);
	void ChangeBattlePos();
	void ChangeWinPos();
	void ChangeLosePos();
	void ChangeClearPos();

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

	Camera() { }		//�R���X�g���N�^
	~Camera() { }		//�f�X�g���N�^

	static Camera* p_CameraInstance;	//�C���X�^���X

	CameraParam camera_param;
};
#endif // !CAMERA_H_
