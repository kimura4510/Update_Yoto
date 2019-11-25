#include "Camera.h"
#include "Graphics.hpp"
#include "Input.hpp"
#include <d3d9.h>
#include <d3dx9.h>

Camera* Camera::p_CameraInstance = nullptr;

void Camera::UpdateCamera()
{
	MoveCamera();

	D3DXMATRIX matProj, matView;

	//View���W�ϊ��p�̍s��Z�o�J�n
	D3DXVECTOR3 camera_pos(camera_param.m_pos_x, camera_param.m_pos_y, camera_param.m_pos_z);	//�J�����̈ʒu
	D3DXVECTOR3 eye_pos(camera_param.m_eye_x, camera_param.m_eye_y, camera_param.m_eye_z);		//�����_
	D3DXVECTOR3 up_vector(0.0f, 1.0f, 0.0f);													//�J�����̌���

	D3DXMatrixIdentity(&matView);
	D3DXMatrixLookAtLH(&matView, &camera_pos, &eye_pos, &up_vector);
	Graphics::GetGraphicInstance()->SetView(matView);
	//View���W�ϊ��p�̍s��Z�o�I��

	//�ˉe���W�ϊ��p�̍s��Z�o�J�n
	D3DVIEWPORT9 vp;
	Graphics::GetGraphicInstance()->GetViewport_Camera(&vp);
	float aspect = (float)vp.Width / (float)vp.Height;

	D3DXMatrixPerspectiveFovLH(
		&matProj,
		D3DXToRadian(60),
		aspect, 
		0.f, 
		1000000.f);
	Graphics::GetGraphicInstance()->SetMatProj(matProj);
	//�ˉe���W�ϊ��p�̍s��Z�o�I��
}

void Camera::InitCamera()
{
	camera_param.m_eye_x = 0.0f;
	camera_param.m_eye_y = 0.0f;
	camera_param.m_eye_z = 10.0f;
	camera_param.m_pos_x = 0.0f;
	camera_param.m_pos_y = 0.0f;
	camera_param.m_pos_z = 0.0f;
}

void Camera::MoveCamera()
{
	if (Input::GetInputInstance()->GetKey(KEY_INFO::UP_KEY) == true)
	{
		camera_param.m_pos_z += 1.0f;
	}
	if (Input::GetInputInstance()->GetKey(KEY_INFO::DOWN_KEY) == true)
	{
		camera_param.m_pos_z -= 1.0f;
	}
	if (Input::GetInputInstance()->GetKey(KEY_INFO::RIGHT_KEY) == true)
	{
		camera_param.m_pos_x += 1.0f;
		camera_param.m_eye_x += 1.0f;
	}
	if (Input::GetInputInstance()->GetKey(KEY_INFO::LEFT_KEY) == true)
	{
		camera_param.m_pos_x -= 1.0f;
		camera_param.m_eye_x -= 1.0f;
	}
}

void Camera::ReleaseCamera()
{
}
