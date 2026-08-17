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
	resultMessage("終了")
{
	Initialize();
}

/// <summary>
/// 初期化
/// </summary>
void GameManager::Initialize()
{ }

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
			resultMessage = "１の勝ち";
			break;
		case Config::Game::SECOND_WIN:
			resultMessage = "２の勝ち";
			break;
		case Config::Game::DRAW:
			resultMessage = "引き分け";
			break;
		case Config::Game::CONTINUE:
		default:
			break;
		}

		// 結果を表示
		return;
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
		return;
	}
}

/// <summary>
/// 描画
/// </summary>
void GameManager::Draw() const
{
	// ボードの描画
	board.Draw();

	if (isEnd)
	{
		DrawString(0, 0, resultMessage.c_str(), GetColor(255, 0, 0));
	}
}

/// <summary>
/// 終了
/// </summary>
void GameManager::Finalize()
{

}