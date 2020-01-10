#include <Windows.h>
#include "Engine/Engine.hpp"
#include "Engine/Window.hpp"
#include "Scene/SceneManager.hpp"
<<<<<<< HEAD
#include"../../LoadResources/LoadResources.h"
=======
>>>>>>> BuildSound


int WINAPI WinMain(
	_In_ HINSTANCE hI,
	_In_opt_ HINSTANCE hP,
	_In_ LPSTR lpCmpLine,
	_In_ INT nCmdShow)
{


	Engine engine;
	Window window;
<<<<<<< HEAD
	
=======
	SceneManager sceneManager;

>>>>>>> BuildSound
	
	HWND hW = window.MakeWindow(hI, 1920, 1080, "Update:Yoto");
	
	//エンジンの初期化
	if (engine.InitEngine(hI, hW) == false)
	{
		return 0;
	}

	MSG msg;

<<<<<<< HEAD
	SceneManager sceneManager;

	sceneManager.Init(SceneID::eTitleScene);
	//LoadResources::Load();


	//ゲームループの開始
	while (true)
	{

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				break;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}

		//シーン更新
		sceneManager.Update();

=======
	sceneManager.Init(SceneID::eTitleScene);

	// ゲームループの開始
	while (true)
	{

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				break;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}

		// シーン更新
		sceneManager.Update();

>>>>>>> BuildSound
		sceneManager.Draw();
	}

	sceneManager.End();
	engine.EndEngine();

	return 0;
}