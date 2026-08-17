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

	// ゲーム全体の設定
	namespace Game
	{
		// ゲームの状態
		enum State
		{
			TITLE,			// タイトル
			GAME_START,		// ゲームスタート
			GAME_SELECT,	// ゲーム中
			GAME_END,		// ゲーム終了
			RESULT,			// リザルト
		};
		// リザルトの種類
		enum ResultKind
		{
			FIRST_WIN,		// 先手の勝ち
			SECOND_WIN,		// 後手の勝ち
			DRAW,			// 引き分け
			CONTINUE,		// 勝敗なし
		};
		// 手番
		enum Turn
		{
			FIRST,		// 先手
			SECOND,		// 後手
			ALL			// すべて
		};
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
		const int COLOR_FIRST[3] = { 0,0,0 };			// 黒コマの色
		const int COLOR_SECOND[3] = { 255,255,255 };		// 白コマの色
	}
}