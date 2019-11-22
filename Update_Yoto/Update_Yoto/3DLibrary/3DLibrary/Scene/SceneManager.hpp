#ifndef SCENEMANAGER_H_
#define SCENEMANAGER_H_

#include "BaseScene.hpp"
#include <vector>

class SceneManager
{
public:
	//コンストラクタ
	SceneManager();

	//デストラクタ
	~SceneManager();

	//初期化関数
	void Init(SceneID id);

	//終了関数
	void End();
	
	//更新関数
	void Update();

	//描画関数
	void Draw();

	//シーン変更関数
	void ChangeScene(SceneID nextScene);

	bool IsGameEnd();

private:
	std::vector<BaseScene*> m_SceneList;
	BaseScene* m_CurrentScene;
	SceneID m_SceneID;
};

#endif