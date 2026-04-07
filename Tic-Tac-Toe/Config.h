#pragma once

namespace Config
{
	// ウィンドウ設定
	namespace Window
	{
		const int width = 640;
		const int height = 480;
		const int colorBitDepth = 32;
	}

	// ボード設定
	namespace Board
	{
		const int size = Config::Window::width / 4 * 2;
		const unsigned int boardColor[3] = { 255,255,255 };
		const unsigned int lineColor[3] = { 255,0,255 };
	}
}