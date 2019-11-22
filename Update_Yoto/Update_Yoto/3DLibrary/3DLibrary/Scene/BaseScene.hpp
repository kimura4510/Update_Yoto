#ifndef BASE_SCENE_H_
#define BASE_SCENE_H_

enum class SceneID
{
	eTitleScene,
	eGameScene,
	eHelpScene,
	eClearScene,
	eGameoverScene,

	eSceneIDMax,
	eNon_Scene,

};

enum class SceneState
{
	eInit,
	eMain,
	eEnd,
};

class BaseScene
{
public:
	BaseScene()
	{
		m_State = SceneState::eInit;
	}
	virtual ~BaseScene() { }


	virtual void Update() = 0;
	virtual void Draw() { };
	virtual void Init() = 0;
	virtual SceneID End()
	{
		return SceneID::eNon_Scene;
	}

	virtual SceneID Control()
	{
		return SceneID::eNon_Scene;
	}

protected:
	SceneState m_State;	///< ƒV[ƒ“‚Ìó‘Ô
};


#endif