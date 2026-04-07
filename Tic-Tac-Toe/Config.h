#pragma once

namespace Config
{
	// ウィンドウ設定
	namespace Window
	{
		const int WIDTH = 640;			// 幅
		const int HEIGHT = 480;			// 高さ
		const int COLOR_BIT_DEPTH = 32;	// カラービット数
	}

	// ボード設定
	namespace Board
	{
		const int SIZE = Config::Window::WIDTH / 4 * 2;		// ボードの大きさ
		const int SPLIT_NUM = 3;		// ボードの分割数
		const unsigned int BOARD_COLOR[3] = { 255,255,255 };	// ボードの色
		const unsigned int LINE_COLOR[3] = { 255,0,255 };	// ラインの色
	}
}