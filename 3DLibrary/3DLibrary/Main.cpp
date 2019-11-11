#include <Windows.h>
#include "Engine/Engine.hpp"
#include "Engine/Window.hpp"
#include "Scene/SceneManager.hpp"

int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpCmpLine, INT nCmdShow)
{
	Engine engine;
	Window window;
	SceneManager sceneManager;
	
	HWND hW = window.MakeWindow(hI, 1920, 1080, "Update:Yoto");
	
	//エンジンの初期化
	if (Engine.InitEngine(hI, hW) == false)
	{
		return 0;
	}

	MSG msg;

	sceneManager.Init();

	//ゲームループの開始
	while (true)
	{
		if (sceneManager.IsGameEnd() == true)
		{
			break;
		}

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
		else
		{
			//シーン更新
			sceneManager.Update();
			//シーン描画
			sceneManager.Draw();
		}
	}

	sceneManager.End();
	Engine.EndEngine();
}