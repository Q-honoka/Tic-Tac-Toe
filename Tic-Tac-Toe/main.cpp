#include "DxLib.h"
#include "Config.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	ChangeWindowMode(TRUE);
	SetGraphMode(Config::Window::width, Config::Window::height, Config::Window::colorBitDepth);
	SetDrawScreen(DX_SCREEN_BACK);
	
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	// ボードの作成
	int boardHandle = -1;
	boardHandle = MakeScreen(Config::Board::size, Config::Board::size, FALSE);
	SetDrawScreen(boardHandle);
	DrawBox(0, 0, Config::Board::size, Config::Board::size, GetColor(Config::Board::boardColor[0], Config::Board::boardColor[1], Config::Board::boardColor[2]), TRUE);
	for (int i = 0; i < 4; i++)
	{
		DrawLine(Config::Board::size / 3 * i, 0, Config::Board::size / 3 * i, Config::Board::size, GetColor(Config::Board::lineColor[0], Config::Board::lineColor[1], Config::Board::lineColor[2]), 3);
		DrawLine(0, Config::Board::size / 3 * i, Config::Board::size, Config::Board::size / 3 * i, GetColor(Config::Board::lineColor[0], Config::Board::lineColor[1], Config::Board::lineColor[2]), 3);
	}

	// 描画先を戻す
	SetDrawScreen(DX_SCREEN_BACK);

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();

		// ボードの表示
		DrawGraph(Config::Window::width / 4, Config::Window::height / 4, boardHandle, TRUE);

		ScreenFlip();
	}

	DxLib_End();
	return 0;
}