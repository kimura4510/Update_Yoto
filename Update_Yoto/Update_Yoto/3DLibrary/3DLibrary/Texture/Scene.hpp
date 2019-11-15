/**
* @file Scene.h
* @brief シーン全体を実行、描画する関数の宣言
*/

#ifndef SCENE_H_
#define SCENE_H_

// @brief シーンID
enum SceneID
{
	TitleScene,			//!<タイトルシーン
	HelpScene,			//!<ヘルプシーン
	GameScene,			//!<ゲーム本編シーン
	GameClearScene,		//!<ゲームクリアシーン
	GameEndScene,		//!<ゲーム終了シーン
	SceneIDMax			//!<シーンID最大
};

// @brief シーンステップ
enum SceneStep
{
	InitStep,		//!< 初期化
	MainStep,		//!< メイン
	EndStep,		//!< 終了
};

class SCENE
{
public:
	SCENE()
	{
		g_CurrentSceneID = SceneID::TitleScene;
		g_CurrentSceneStep = SceneStep::InitStep;
	};

	// @brief 現在実行中のシーンIDの取得関数
	SceneID GetCurrentSceneID();

	// @brief 現在実行中のシーンステップの取得関数
	SceneStep GetCurrentSceneStep();

	/**
	* @brief シーンステップ変更関数@n
	* 非k数で指定したステップに切り替えます
	* @param[in] next_step　次のステップ
	*/
	void ChangeSceneStep(SceneStep next_step);

	/**
	* @brief シーン実行関数@n
	* シーン処理を実行する@n
	* 内部で各シーンを動かすため、使用者がUpdateTitleScene等を実行する必要はありません
	*/
	void UpdateScene();

	/**
	* @brief シーン描画関数@n
	* シーンのオブジェクトを描画します@n
	* 内部で各シーンの描画を行うため、使用者がDrawTitileScene等を実行する必要はありません
	*/
	void DrawScene();

private:
	SceneID g_CurrentSceneID;		// 動作中シーンID
	SceneStep g_CurrentSceneStep;	// 動作中シーンのステップ
};

#endif