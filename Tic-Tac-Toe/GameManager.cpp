#include "GameManager.h"
#include "DxLib.h"

/// <summary>
/// コンストラクタ
/// </summary>
GameManager::GameManager() :
	pieceColorFirst(GetColor(0,0,0)),
	pieceColorSecond(GetColor(255,255,255)),
	isEnd(false),
	turn(Config::Game::Turn::FIRST),
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
	if (isEnd)
	{
		Config::Game::ResultKind result = board.GetCheckResult();

		switch (result)
		{
		case Config::Game::FIRST_WIN:
			printfDx("１の勝ち\n");
			break;
		case Config::Game::SECOND_WIN:
			printfDx("２の勝ち\n");
			break;
		case Config::Game::DRAW:
			printfDx("引き分け\n");
			break;
		case Config::Game::CONTINUE:
			break;
		default:
			break;
		}

		WaitKey();
	}

	// 入力データ取得
	inputManager.Update();

	// コマの配置
	if (inputManager.GetMouseState(MouseState::PRESS))
	{
		// マウスカーソルの位置を取得して判定する
		int x, y;
		GetMousePoint(&x, &y);

		// 座標のマスにコマが置けたら手番を進める
		if (board.PutPiece(x, y, turn))
		{
			turn = (Config::Game::Turn)(((int)turn + 1) % (int)Config::Game::Turn::ALL);
		}
	}

	// ボードの更新
	board.Update();

	// 終わっているか調べる
	if (board.GetCheckResult() != Config::Game::ResultKind::CONTINUE)
	{
		isEnd = true;
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