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
		// 各マスの状態
		enum State
		{
			NONE,	// 何も置かれてない
			BLACK,	// 黒コマが置かれている
			WHITE,	// 白コマが置かれている
		};
		const int CENTER_X = Config::Window::WIDTH / 2;
		const int CENTER_Y = Config::Window::HEIGHT / 2;
		const int SIZE = Config::Window::WIDTH / 4 * 2;		// ボードの大きさ
		const int SPLIT_NUM = 3;		// ボードの分割数
		const int BOARD_COLOR[3] = { 255,255,100 };	// ボードの色
		const int LINE_COLOR[3] = { 0,100,255 };	// ラインの色
	}

	// コマの設定
	namespace Piece
	{
		const int RADIUS = Config::Board::SIZE / 6;	// コマの半径
		const int COLOR_BLACK[3] = { 0,0,0 };			// 黒コマの色
		const int COLOR_WHITE[3] = { 255,255,255 };		// 白コマの色
	}
}