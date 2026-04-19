#include "Board.h"
#include "DxLib.h"

/// <summary>
/// コンストラクタ
/// </summary>
Board::Board() :
	x(Config::Board::CENTER_X),
	y(Config::Board::CENTER_Y),
	handle(-1),
	size(Config::Board::SIZE),
	baseColor(GetColor(Config::Board::BOARD_COLOR[0], Config::Board::BOARD_COLOR[1], Config::Board::BOARD_COLOR[2])),
	frameColor(GetColor(Config::Board::LINE_COLOR[0], Config::Board::LINE_COLOR[1], Config::Board::LINE_COLOR[2]))
{
	// ボードの画像ハンドルを作成
	MakeBoardHandle();
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

/// <summary>
/// 引数の座標が示すマスの番号を返す（-1は盤外）
/// </summary>
/// <param name="posX">座標X</param>
/// <param name="posY">座標Y</param>
/// <returns>左上から右へ順に0,1,2...と増える。-1は盤の外</returns>
int Board::GetSpaceNumber(int posX, int posY) const
{
	const int startX = x - size / 2;
	const int startY = y - size / 2;
	// 盤の外なら-1を返す
	if (posX < startX || startX + size < posX) return -1;
	if (posY < startY || startY + size < posY) return -1;

	// 該当するマスの番号を返す
	const int split = Config::Board::SPLIT_NUM;
	const int step = size / split;
	int col = (posX - startX) / step;
	int row = (posY - startY) / step;

	return row * split + col;
}

/// <summary>
/// ボードの画像ハンドルを作成する
/// </summary>
void Board::MakeBoardHandle()
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