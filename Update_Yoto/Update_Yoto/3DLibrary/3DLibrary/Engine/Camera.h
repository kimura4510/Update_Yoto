#ifndef CAMERA_H_
#define CAMERA_H_

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
	void InitCamera();
	void ReleaseCamera();
	void UpdateCamera();

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

	Camera() { }		//コンストラクタ
	~Camera() { }		//デストラクタ

	static Camera* p_CameraInstance;	//インスタンス

	CameraParam camera_param;
};
#endif // !CAMERA_H_
