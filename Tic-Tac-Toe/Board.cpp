#include "Board.h"
#include "DxLib.h"

/// <summary>
/// コンストラクタ
/// </summary>
Board::Board() :
	x(Config::Window::WIDTH / 2),
	y(Config::Window::HEIGHT / 2),
	handle(-1)
{
	// インスタンスと同時に初期化
	InitializeBoard();
}

/// <summary>
/// デストラクタ
/// </summary>
Board::~Board()
{
	FinalizeBoard();
}

/// <summary>
/// 更新処理
/// </summary>
void Board::Update()
{

}

/// <summary>
/// 描画処理
/// </summary>
void Board::Draw() const
{
	DrawGraph(x - Config::Board::SIZE / 2, y - Config::Board::SIZE / 2, handle, TRUE);
}

/// <summary>
/// 初期化処理
/// </summary>
void Board::InitializeBoard()
{
	const int size = Config::Board::SIZE;
	const unsigned int boardClr = GetColor(Config::Board::BOARD_COLOR[0], Config::Board::BOARD_COLOR[1], Config::Board::BOARD_COLOR[2]);
	const unsigned int lineClr = GetColor(Config::Board::LINE_COLOR[0], Config::Board::LINE_COLOR[1], Config::Board::LINE_COLOR[2]);
	const int split = Config::Board::SPLIT_NUM;

	// ボードの作成
	handle = MakeScreen(size, size, FALSE);
	SetDrawScreen(handle);	// 描画先を設定
	DrawBox(0, 0, size, size, boardClr, TRUE);
	
	// マスを縁取る線の描画
	for (int i = 0; i < split + 1; i++)
	{
		DrawLine(size / split * i, 0, size / split * i, size, lineClr, split);	// 縦線
		DrawLine(0, size / split * i, size, size / split * i, lineClr, split);	// 横線
	}

	// 描画先を戻す
	SetDrawScreen(DX_SCREEN_BACK);
}

/// <summary>
/// 終了処理
/// </summary>
void Board::FinalizeBoard() const
{
	// 画像ハンドルを消去する
	DeleteGraph(handle);
}