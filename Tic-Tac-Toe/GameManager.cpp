#include "GameManager.h"
#include "DxLib.h"

GameManager::GameManager() :
	inputManager(InputManager()),
	board(Board())
{ }

/// <summary>
/// 初期化
/// </summary>
void GameManager::Initialize()
{

}

/// <summary>
/// 更新
/// </summary>
void GameManager::Update()
{
	// 入力データ取得
	inputManager.Update();

	// 盤面の更新
	if (inputManager.GetMouseState(MouseState::PRESS))
	{
		printfDx("押した\n");
	}

}

/// <summary>
/// 描画
/// </summary>
void GameManager::Draw() const
{
	// ボードの描画
	board.Draw();
}

/// <summary>
/// 終了
/// </summary>
void GameManager::Finalize()
{

}