#pragma once
#include "Config.h"
#include "Piece.h"

/*
	名前：Board.h
	役割：ボードの描画とマスの管理
*/

class Board
{
public:
	Board();		// コンストラクタ
	~Board();		// デストラクタ
	void Update();			// 更新
	void Draw() const;		// 描画
	bool PutPiece(int posX, int posY, Config::Game::Turn turn);	// 指定された場所にコマを置く（true：成功, false：失敗）
	Config::Game::ResultKind GetCheckResult() const;	// 判定した結果を返す

private:
	int x, y;	// ボードの中心座標
	int handle;	// 画像ハンドル
	Config::Game::ResultKind checkResult;	// 判定結果
	Piece pieces[Config::Board::SPLIT_NUM * Config::Board::SPLIT_NUM];		// すべてのコマ

	const int size;					// ボードの大きさ
	const int split;				// ボードの分割数
	const unsigned int baseColor;	// ボードのベース色
	const unsigned int frameColor;	// ボードの枠色
	const int checkPatterns[8][3];		// チェックするパターン

	void MakeBoardHandle();		// ボードの画像ハンドル作成
	void SetPieceInitPos();		// コマの初期位置を設定
	void CheckBoard();			// ボードの勝敗を判定する
	int GetSpaceNumber(int posX, int posY) const;	// 引数の座標が示すマスの番号を返す（-1は盤外）
};