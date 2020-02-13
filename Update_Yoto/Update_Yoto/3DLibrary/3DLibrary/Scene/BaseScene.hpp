#ifndef BASE_SCENE_H_
#define BASE_SCENE_H_

enum class SceneID
{
	eTitleScene,
	eGameScene,
	ePvPScene,
	eHelpScene,
	eClearScene,
	eGameoverScene,
	eTransitionScene,

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
		return SceneID::eTitleScene;
	}

	virtual SceneID Control()
	{
		return SceneID::eTitleScene;
	}

	virtual bool IsMainStep()
	{
		if (m_State == SceneState::eMain)
		{
			return true;
		}
		return false;
	}

protected:
	SceneState m_State;
};


#endif