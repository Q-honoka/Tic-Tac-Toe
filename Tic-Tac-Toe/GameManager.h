#pragma once
#include "Board.h"
#include "InputManager.h"
#include "Piece.h"

/*
	名前：GameManager.h
	役割：ゲーム全体の進行を管理する
*/

class GameManager
{
public:
	GameManager();	// コンストラクタ
	~GameManager() = default;	// デストラクタ
	void Initialize();		// 初期化
	void Update();			// 更新
	void Draw() const;		// 描画
	void Finalize();		// 終了

private:
	const unsigned int pieceColorFirst;		// 先手のコマの色
	const unsigned int pieceColorSecond;	// 後手のコマの色
	bool isEnd;	// 終了フラグ
	Config::Game::Turn turn;	// 手番
	InputManager inputManager;	// 入力管理クラス
	Board board;				// ボード管理クラス
	Piece pieces[Config::Board::SPLIT_NUM * Config::Board::SPLIT_NUM];	// コマの数
};