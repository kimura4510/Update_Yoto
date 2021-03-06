#include "Camera.h"
#include "Graphics.hpp"
#include "Input.hpp"
#include <d3d9.h>
#include <d3dx9.h>

Camera* Camera::p_CameraInstance = nullptr;

void Camera::UpdateCamera()
{
	D3DXMATRIX matProj, matView;

	//View座標変換用の行列算出開始
	D3DXVECTOR3 camera_pos(camera_param.m_pos_x, camera_param.m_pos_y, camera_param.m_pos_z);	//カメラの位置
	D3DXVECTOR3 eye_pos(camera_param.m_eye_x, camera_param.m_eye_y, camera_param.m_eye_z);		//注視点
	D3DXVECTOR3 up_vector(0.0f, 1.0f, 0.0f);													//カメラの向き

	D3DXMatrixIdentity(&matView);
	D3DXMatrixLookAtLH(&matView, &camera_pos, &eye_pos, &up_vector);
	Graphics::GetGraphicInstance()->SetView(matView);
	//View座標変換用の行列算出終了

	//射影座標変換用の行列算出開始
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
	//射影座標変換用の行列算出終了
}

void Camera::InitCamera(float x_, float y_, float z_, float ex, float ey, float ez)
{
	camera_param.m_eye_x = ex;
	camera_param.m_eye_y = ey;
	camera_param.m_eye_z = ez;
	camera_param.m_pos_x = x_;
	camera_param.m_pos_y = y_;
	camera_param.m_pos_z = z_;

	camera_state = CameraState::Battle;
	counter = 0;
	angle = setAngle;
}

void Camera::MoveCamera()
{
	const float speed = 3.0f;
	Input* INP = Input::GetInputInstance();
	if (INP->GetGamePadBottonState(0, GAMEPAD_BUTTONS::lUp) == INPUT_STATE::PUSH || INP->GetKey(KEY_INFO::UP_KEY) == true)
	{
		camera_param.m_pos_z += speed;
		camera_param.m_eye_z += speed;
	}
	if (INP->GetGamePadBottonState(0, GAMEPAD_BUTTONS::lDown) == INPUT_STATE::PUSH || INP->GetKey(KEY_INFO::DOWN_KEY) == true)
	{
		camera_param.m_pos_z -= speed;
		camera_param.m_eye_z -= speed;
	}
	if (INP->GetGamePadBottonState(0, GAMEPAD_BUTTONS::lRight) == INPUT_STATE::PUSH || INP->GetKey(KEY_INFO::RIGHT_KEY) == true)
	{
		camera_param.m_pos_x += speed;
		camera_param.m_eye_x += speed;
	}
	if (INP->GetGamePadBottonState(0, GAMEPAD_BUTTONS::lLeft) == INPUT_STATE::PUSH || INP->GetKey(KEY_INFO::LEFT_KEY) == true)
	{
		camera_param.m_pos_x -= speed;
		camera_param.m_eye_x -= speed;
	}

	if (INP->GetGamePadBottonState(0, GAMEPAD_BUTTONS::rRight) == INPUT_STATE::PUSH || INP->GetKey(KEY_INFO::D_KEY) == true)
	{
		camera_param.m_eye_x += speed;
	}
	if (INP->GetGamePadBottonState(0, GAMEPAD_BUTTONS::rLeft) == INPUT_STATE::PUSH || INP->GetKey(KEY_INFO::A_KEY) == true)
	{
		camera_param.m_eye_x -= speed;
	}
	if (INP->GetGamePadBottonState(0, GAMEPAD_BUTTONS::rUp) == INPUT_STATE::PUSH || INP->GetKey(KEY_INFO::W_KEY) == true)
	{
		camera_param.m_eye_y += speed;
	}
	if (INP->GetGamePadBottonState(0, GAMEPAD_BUTTONS::rDown) == INPUT_STATE::PUSH || INP->GetKey(KEY_INFO::S_KEY) == true)
	{
		camera_param.m_eye_y -= speed;
	}
}

void Camera::ChangeCameraPos(CameraState state_)
{
	switch (state_)
	{
	case CameraState::Battle:
		ChangeBattleMovement();
		break;
	case CameraState::WinningPlayer:
		ChangeWinPos();
		break;
	case CameraState::LosingPlayer:
		ChangeLosePos();
		break;
	case CameraState::GameClear:
		ChangeClearMovement();
		break;
	case CameraState::Gameover:
		ChangeGameoverMovement();
		break;
	}
}

void Camera::ChangeBattleMovement()
{
}

void Camera::ChangeWinPos()
{
	//!< 注視点をフィールドの中心に変更
	camera_param.m_eye_x = 512.0f;
	camera_param.m_eye_z = 512.0f;

	//!< 中心点から半径300の球の表面上に位置情報を変更
	camera_param.m_pos_x = camera_param.m_eye_x - Length * cos(D3DXToRadian(setAngle));
	camera_param.m_pos_z = camera_param.m_eye_z - Length * sin(D3DXToRadian(setAngle));
	if (camera_state == CameraState::Battle)
	{
		camera_param.m_pos_y += 20.0f;
	}
	camera_state = CameraState::WinningPlayer;
}

void Camera::ChangeLosePos()
{
	camera_param.m_eye_x = 512.0f;
	camera_param.m_eye_z = 512.0f;

	camera_param.m_pos_x = camera_param.m_eye_x + Length * cos(D3DXToRadian(setAngle));
	camera_param.m_pos_z = camera_param.m_eye_z - Length * sin(D3DXToRadian(setAngle));
	if (camera_state == CameraState::Battle)
	{
		camera_param.m_pos_y += 20.0f;
	}
	camera_state = CameraState::LosingPlayer;
}

void Camera::ChangeClearMovement()
{
	counter++;
	if (counter >= 51)
	{
		camera_state = CameraState::Battle;
	}
	else if (counter >= 40)
	{
		const float add_rot = 5.5 / 60.0f;
		angle += add_rot;
		camera_param.m_pos_x = camera_param.m_eye_x - Length * cos(D3DXToRadian(angle));
		camera_param.m_pos_z = camera_param.m_eye_z - Length * sin(D3DXToRadian(angle));
	}
	else
	{
		const float add_rot = 54.5 / 60.0f;
		angle += add_rot;
		camera_param.m_pos_x = camera_param.m_eye_x - Length * cos(D3DXToRadian(angle));
		camera_param.m_pos_z = camera_param.m_eye_z - Length * sin(D3DXToRadian(angle));
	}
	camera_state = CameraState::GameClear;
}

void Camera::ChangeGameoverMovement()
{
	counter++;
	if (counter >= 102)
	{
		camera_state = CameraState::Battle;
	}
	else if (counter >= 80)
	{
		const float add_rot = -5.5 / 60.0f;
		angle += add_rot;
		camera_param.m_pos_x = camera_param.m_eye_x - Length * cos(D3DXToRadian(angle));
		camera_param.m_pos_z = camera_param.m_eye_z + Length * sin(D3DXToRadian(angle));
	}
	else
	{
		const float add_rot = -54.5 / 60.0f;
		angle += add_rot;
		camera_param.m_pos_x = camera_param.m_eye_x - Length * cos(D3DXToRadian(angle));
		camera_param.m_pos_z = camera_param.m_eye_z + Length * sin(D3DXToRadian(angle));
	}
}


void Camera::ReleaseCamera()
{
}

Camera::Camera() : Length(200.0f), angle(0.0f), setAngle(60.0f), counter(0)
{
}