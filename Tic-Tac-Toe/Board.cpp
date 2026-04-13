#include "Board.h"
#include "DxLib.h"

/// <summary>
/// コンストラクタ
/// </summary>
Board::Board() :
	x(Config::Window::WIDTH / 2),
	y(Config::Window::HEIGHT / 2),
	handle(-1),
	size(Config::Board::SIZE),
	baseColor(GetColor(Config::Board::BOARD_COLOR[0], Config::Board::BOARD_COLOR[1], Config::Board::BOARD_COLOR[2])),
	frameColor(GetColor(Config::Board::LINE_COLOR[0], Config::Board::LINE_COLOR[1], Config::Board::LINE_COLOR[2])),
	pieces(0)
{
	// ボードの画像ハンドルを作成する
	const int split = Config::Board::SPLIT_NUM;

	// ボードの作成
	handle = MakeScreen(size, size, FALSE);
	SetDrawScreen(handle);	// 描画先を設定
	DrawBox(0, 0, size, size, baseColor, TRUE);

	// マスを縁取る線の描画
	for (int i = 0; i < split + 1; i++)
	{
		DrawLine(size / split * i, 0, size / split * i, size, frameColor, split);	// 縦線
		DrawLine(0, size / split * i, size, size / split * i, frameColor, split);	// 横線
	}

	// 描画先を戻す
	SetDrawScreen(DX_SCREEN_BACK);
}

/// <summary>
/// デストラクタ
/// </summary>
Board::~Board()
{
	// 画像ハンドルを消去する
	DeleteGraph(handle);
}

/// <summary>
/// 描画処理
/// </summary>
void Board::Draw() const
{
	// ボードの描画
	DrawGraph(x - Config::Board::SIZE / 2, y - Config::Board::SIZE / 2, handle, TRUE);
}