#ifndef SCENEMANAGER_H_
#define SCENEMANAGER_H_

#include "BaseScene.hpp"
#include "I_SceneChanger.hpp"

class SceneManager : public I_SceneChanger
{
public:
	//コンストラクタ
	SceneManager();

	//デストラクタ
	~SceneManager();

	//初期化関数
	void Init();

	//終了関数
	void End();
	
	//更新関数
	void Update();

	//描画関数
	void Draw();

	//シーン変更関数
	void ChangeScene(SceneID nextScene) override;

	bool IsGameEnd();

private:
	BaseScene* m_Scene;
	SceneID m_NextScene;
};

#endif