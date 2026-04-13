#include "DxLib.h"
#include "Config.h"
#include "GameManager.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	ChangeWindowMode(TRUE);
	SetGraphMode(Config::Window::WIDTH, Config::Window::HEIGHT, Config::Window::COLOR_BIT_DEPTH);
	SetDrawScreen(DX_SCREEN_BACK);
	
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	static GameManager gameManager;

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();

		// 更新
		gameManager.Update();

		// 表示
		gameManager.Draw();

		ScreenFlip();
	}

	DxLib_End();
	return 0;
}