#include <Windows.h>
#include "Engine/Engine.hpp"
#include "Engine/Window.hpp"
//#include "Scene/SceneManager.hpp"
#include"../../LoadResources/LoadResources.h"



int WINAPI WinMain(
	_In_ HINSTANCE hI,
	_In_opt_ HINSTANCE hP,
	_In_ LPSTR lpCmpLine,
	_In_ INT nCmdShow)
{
	Engine engine;
	Window window;
	//SceneManager sceneManager;

	
	HWND hW = window.MakeWindow(hI, 1920, 1080, "Update:Yoto");
	
	//エンジンの初期化
	if (engine.InitEngine(hI, hW) == false)
	{
		return 0;
	}

	MSG msg;

	//sceneManager.Init(SceneID::eTitleScene);
	//LoadResources::Load();

	std::string texname = "title";
	cTexture::GetTextureInstance()->LoadTexture("3DLibrary/3DLibrary/Res/title.png", texname);

	//ゲームループの開始
	//while (true)
	//{

	//	if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	//	{
	//		if (msg.message == WM_QUIT)
	//		{
	//			break;
	//		}
	//		else
	//		{
	//			TranslateMessage(&msg);
	//			DispatchMessage(&msg);
	//		}
	//	}

		//シーン更新
		//sceneManager.Update();

		//sceneManager.Draw();
	//}

	//sceneManager.End();
	engine.EndEngine();

	return 0;
}