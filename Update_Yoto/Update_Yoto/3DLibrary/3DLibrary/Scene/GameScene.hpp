#ifndef GAMESCENE_H_
#define GAMESCENE_H_

#include "BaseScene.hpp"
#include "../../../Character/CharacterManager.h"
#include "../../../BackGround/BackGround.h"

class GameScene : public BaseScene
{
public:
	enum class END_SCENE {
		GAME_NONE,

		GAME_CLEAR,
		GAME_OVER,

		GAME_MAX
	};

public:
	//デストラクタ
	~GameScene() override { }
	void Init() override;
	SceneID End() override;
	void Update() override;
	SceneID Control() override;
	void Draw() override;

private:
	BackGround m_bg;
	CharacterManager m_chmanager;
	END_SCENE m_end_scene;
};

#endif