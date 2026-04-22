#include "Board.h"
#include "DxLib.h"

/// <summary>
/// コンストラクタ
/// </summary>
Board::Board() :
	x(Config::Board::CENTER_X),
	y(Config::Board::CENTER_Y),
	handle(-1),
	checkResult(Config::Game::ResultKind::CONTINUE),
	pieces(Piece()),
	size(Config::Board::SIZE),
	split(Config::Board::SPLIT_NUM),
	baseColor(GetColor(Config::Board::BOARD_COLOR[0], Config::Board::BOARD_COLOR[1], Config::Board::BOARD_COLOR[2])),
	frameColor(GetColor(Config::Board::LINE_COLOR[0], Config::Board::LINE_COLOR[1], Config::Board::LINE_COLOR[2])),
	checkPatterns(
		{0,3,6},	// 左列
		{1,4,7},	// 中列
		{2,5,8},	// 右列
		{0,1,2},	// 上行
		{3,4,5},	// 中行
		{6,7,8},	// 下行
		{0,4,8},	// 斜め（左上から右下）
		{2,4,6}		// 斜め（右上から左下）
		)
{
	// ボードの画像ハンドルを作成
	MakeBoardHandle();

	// コマの初期化
	SetPieceInitPos();
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
/// 更新処理
/// </summary>
void Board::Update()
{
	// 勝敗を調べる
	CheckBoard();
}

/// <summary>
/// 描画処理
/// </summary>
void Board::Draw() const
{
	// ボードの描画
	DrawGraph(x - Config::Board::SIZE / 2, y - Config::Board::SIZE / 2, handle, TRUE);

	// コマの描画
	for (int i = 0; i < split * split; i++)
	{
		pieces[i].Draw();
	}
}

/// <summary>
/// 指定された場所にコマを置く
/// </summary>
/// <param name="num">置きたい場所</param>
/// <param name="turn">コマを置くプレイヤーの手番</param>
/// <returns>true[成功], false[失敗]</returns>
bool Board::PutPiece(int posX, int posY, Config::Game::Turn turn)
{
	// ボード内の座標が盤の外なら、falseを返す
	int num = GetSpaceNumber(posX, posY);
	if (num == -1) return false;

	// すでに置かれているなら、falseを返す
	if (pieces[num].GetIsVisible()) return false;

	// そうでないなら、コマを置いてtrueを返す
	if(turn == Config::Game::Turn::FIRST) pieces[num].SetIsVisible(true, true);
	if(turn == Config::Game::Turn::SECOND) pieces[num].SetIsVisible(true, false);
	
	return true;
}

/// <summary>
/// 判定結果を返す
/// </summary>
/// <returns>ResultKind[判定結果]</returns>
Config::Game::ResultKind Board::GetCheckResult() const
{
	return checkResult;
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

/// <summary>
/// コマの初期位置を設定する
/// </summary>
void Board::SetPieceInitPos()
{
	const int startX = x - size / 2;
	const int startY = y - size / 2;
	const int spaceSize = size / split;
	for (int i = 0; i < split; i++)
	{
		for (int j = 0; j < split; j++)
		{
			int x = startX + spaceSize * j + spaceSize / 2;
			int y = startY + spaceSize * i + spaceSize / 2;
			pieces[i * split + j].SetPosition(x, y);
		}
	}
}

/// <summary>
/// ボードの勝敗を判定する
/// </summary>
void Board::CheckBoard()
{
	// 縦・横・斜めのどれか一列が揃っているか判定をする
	for (int i = 0; i < 8; i++)
	{
		// 表示されているか調べる
		bool isVisible = true;
		for (int j = 0; j < split; j++)
		{
			// 表示されていないコマがあるなら、falseにする
			if (!pieces[checkPatterns[i][j]].GetIsVisible()) isVisible = false;
		}

		// １つでも表示されていないなら、以降の処理をとばす
		if (isVisible == false) continue;

		// 揃っているか調べる
		bool isFirstPiece = pieces[checkPatterns[i][0]].GetIsFirstPiece();
		bool isMatch = true;
		for (int j = 0; j < split - 1; j++)
		{
			// １つでも異なるコマがあるなら、falseにする
			if (isFirstPiece ^ pieces[checkPatterns[i][j + 1]].GetIsFirstPiece()) isMatch = false;
		}

		// 揃っていてかつ表示されているなら、結果を代入して終了する
		if (isMatch && isVisible)
		{
			if (isFirstPiece) checkResult = Config::Game::ResultKind::FIRST_WIN;
			else checkResult = Config::Game::ResultKind::SECOND_WIN;
			return;
		}
	}


	// すべてのコマが置かれているなら引き分け
	bool isDraw = true;
	for (int i = 0; i < split * split; i++)
	{
		if (pieces[i].GetIsVisible() == false)
		{
			isDraw = false;
		}
	}
	if (isDraw)
	{
		checkResult = Config::Game::ResultKind::DRAW;
		return;
	}
	
	// すべての条件に合わないなら続行
	checkResult = Config::Game::ResultKind::CONTINUE;
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
	const int spaceSize = size / split;
	int col = (posX - startX) / spaceSize;
	int row = (posY - startY) / spaceSize;

	return row * split + col;
}