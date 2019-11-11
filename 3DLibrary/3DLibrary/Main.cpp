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
	
	//�G���W���̏�����
	if (Engine.InitEngine(hI, hW) == false)
	{
		return 0;
	}

	MSG msg;

	sceneManager.Init();

	//�Q�[�����[�v�̊J�n
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
			//�V�[���X�V
			sceneManager.Update();
			//�V�[���`��
			sceneManager.Draw();
		}
	}

	sceneManager.End();
	Engine.EndEngine();
}