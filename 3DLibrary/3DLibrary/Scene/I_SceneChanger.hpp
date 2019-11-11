#ifndef I_SCENECHANGER_H_
#define I_SCENECHANGER_H_

typedef enum class {
	eTitleScene,
	eGameScene,
	eHelpScene,
	eClearScene,
	eGameoverScene,

	eNon_Scene,
	eSceneIDMax,
}SceneID;

// Scene変更のためのインターフェイスクラス
class I_SceneChanger
{
public:
	virtual ~I_SceneChanger() = 0;

	/**
	* @brief シーン変更関数
	* 指定したシーンに変更する
	* param[in] nextScene　次のシーンID
	*/
	virtual void ChangeScene(SceneID nextScene) = 0;
};

#endif