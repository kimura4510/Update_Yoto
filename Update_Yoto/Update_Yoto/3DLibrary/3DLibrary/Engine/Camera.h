#ifndef CAMERA_H_
#define CAMERA_H_

#include "../GameDefinition.h"

struct CameraParam
{
	float m_eye_x;	//視点x
	float m_eye_y;	//視点y
	float m_eye_z;	//視点z

	float m_pos_x;	//位置x
	float m_pos_y;	//位置y
	float m_pos_z;	//位置z
};

class Camera
{
public:

	/**
	* @brief カメラの初期化関数
	* カメラのパラメータ(座標と注視点)を初期化します
	* @param[in] x_ x座標
	* @param[in] y_ y座標
	* @param[in] z_ z座標
	* @param[in] ex 注視点x座標
	* @param[in] ey 注視点y座標
	* @param[in] ez 注視点z座標
	*/
	void InitCamera(float x_, float y_, float z_, float ex=0.0f, float ey=0.0f, float ez=0.0f);
	
	/**
	* @biref カメラの開放関数
	*/
	void ReleaseCamera();

	/**
	* @biref カメラの更新関数
	* カメラの座標や注視点の更新を行います。毎フレーム実行してください。
	*/
	void UpdateCamera();

	/**
	* @biref カメラの座標変更関数
	* 状態に応じてカメラの座標を変更します
	* param[in] state_ 変更したいカメラの状態
	*/
	void ChangeCameraPos(CameraState state_);

private:
	void ChangeBattleMovement();
	void ChangeWinPos();
	void ChangeLosePos();
	void ChangeClearMovement();
	void ChangeGameoverMovement();

public:
	//シングルトン
	//実体を生成する関数
	static void CreateInstance()
	{
		if (IsCameraNull() == true)
		{
			p_CameraInstance = new Camera;
		}
	}

	//実体を破棄する関数
	static void DestroyInstance()
	{
		if (IsCameraNull() == false)
		{
			delete p_CameraInstance;
			p_CameraInstance = nullptr;
		}
	}

	//実体の存在を確認する関数
	static bool IsCameraNull()
	{
		return p_CameraInstance == nullptr;
	}

	//実体を取得する関数
	static Camera* GetCameraInstance()
	{
		return p_CameraInstance;
	}

private:
	void MoveCamera();

	Camera();		//コンストラクタ
	~Camera() { }		//デストラクタ

	static Camera* p_CameraInstance;	//インスタンス

	CameraParam camera_param;
	CameraState camera_state;
	int counter;
	const float Length;
	float angle;
	const float setAngle;
};
#endif // !CAMERA_H_
