#include "GameManager.h"
#include "DxLib.h"

GameManager::GameManager() :
	inputManager(InputManager()),
	board(Board()),
	pieces(Piece())
{
	Initialize();
}

/// <summary>
/// 初期化
/// </summary>
void GameManager::Initialize()
{
	// すべてのコマの座標を設定する
	const int split = Config::Board::SPLIT_NUM;
	const int startX = Config::Board::CENTER_X - Config::Board::SIZE / 2;
	const int startY = Config::Board::CENTER_Y - Config::Board::SIZE / 2;
	const int step = Config::Board::SIZE / split;
	for (int i = 0; i < split; i++)
	{
		for (int j = 0; j < split; j++)
		{
			int x = startX + step * j + step / 2;
			int y = startY + step * i + step / 2;
			pieces[i * split + j].SetPosition(x, y);
		}
	}
}

/// <summary>
/// 更新
/// </summary>
void GameManager::Update()
{
	// 入力データ取得
	inputManager.Update();

	// 盤面の更新
	int putNum = -1;
	if (inputManager.GetMouseState(MouseState::PRESS))
	{
		// マウスカーソルの位置を取得して判定する
		int x, y;
		GetMousePoint(&x, &y);
		putNum = board.GetSpaceNumber(x, y);
	}

	// コマの表示
	if (putNum != -1)
	{
		// 非表示なら色を設定して可視化する
		if (pieces[putNum].GetIsVisble() == false)
		{
			pieces[putNum].SetIsVisble(true, GetColor(0, 0, 0));
		}
	}
}

/// <summary>
/// 描画
/// </summary>
void GameManager::Draw() const
{
	// ボードの描画
	board.Draw();

	// コマの描画
	for (int i = 0; i < Config::Board::SPLIT_NUM * Config::Board::SPLIT_NUM; i++)
	{
		pieces[i].Draw();
	}
}

/// <summary>
/// 終了
/// </summary>
void GameManager::Finalize()
{

}