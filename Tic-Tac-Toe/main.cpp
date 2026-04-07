#include "DxLib.h"
#include "Config.h"
#include "Board.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	ChangeWindowMode(TRUE);
	SetGraphMode(Config::Window::WIDTH, Config::Window::HEIGHT, Config::Window::COLOR_BIT_DEPTH);
	SetDrawScreen(DX_SCREEN_BACK);
	
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	static Board board;		// ボードのインスタンス

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();

		// ボードの更新
		board.Update();

		// ボードの表示
		board.Draw();

		ScreenFlip();
	}

	DxLib_End();
	return 0;
}