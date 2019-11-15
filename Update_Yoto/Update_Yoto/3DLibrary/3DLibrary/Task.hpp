#ifndef TASK_H_
#define TASK_H_


/**
* @brief Taskクラス@n
* 初期化、終了、更新、描画を持つ基底クラス@n
*/
class Task
{
public:
	virtual ~Task() {}

	// 初期化処理
	virtual void Init() {}

	// 終了処理 
	virtual void End()	{}

	// 更新処理、継承先で必ず実装する
	virtual void Update() = 0;

	// 描画処理、継承先で必ず実装する
	virtual void Draw() = 0;
};

#endif