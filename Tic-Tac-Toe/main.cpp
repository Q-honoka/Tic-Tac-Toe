#include "DxLib.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	ChangeWindowMode(TRUE);
	SetGraphMode(640, 480, 32);
	SetDrawScreen(DX_SCREEN_BACK);
	
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();

		DrawPixel(320, 240, GetColor(255, 255, 255));

		ScreenFlip();
	}

	DxLib_End();
	return 0;
}