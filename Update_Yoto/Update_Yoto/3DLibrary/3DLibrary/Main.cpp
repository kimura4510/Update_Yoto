#include <Windows.h>
#include "Engine/Engine.hpp"
#include "Engine/Window.hpp"
#include "../../TestUpdate.h"
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
	TestUpdate tu;
	
	HWND hW = window.MakeWindow(hI, 1920, 1080, "Update:Yoto");
	
	//�G���W���̏�����
	if (engine.InitEngine(hI, hW) == false)
	{
		return 0;
	}

	MSG msg;

	//sceneManager.Init(SceneID::eTitleScene);
	LoadResources::Load();

	//�Q�[�����[�v�̊J�n
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

		//�V�[���X�V
		tu.Update();
		//sceneManager.Update();

		tu.Draw();
		//sceneManager.Draw();
	}

	//sceneManager.End();
	engine.EndEngine();

	return 0;
}