#ifndef SCENEMANAGER_H_
#define SCENEMANAGER_H_

#include "I_SceneChanger.hpp"
#include "BaseScene.hpp"

class SceneManager : public I_SceneChanger, Task
{
private:
	BaseScene* m_Scene;
	SceneID m_NextScene;

public:
	//コンストラクタ
	SceneManager();

	//デストラクタ
	~SceneManager();

	//初期化関数
	void Init() override;

	//終了関数
	void End() override;
	
	//更新関数
	void Update() override;

	//描画関数
	void Draw() override;

	//シーン変更関数
	void ChangeScene(SceneID nextScene) override;

	bool IsGameEnd();
};



#endif