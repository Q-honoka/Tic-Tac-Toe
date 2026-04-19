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
	void Draw() const;		// 描画
	int GetSpaceNumber(int posX, int posY) const;		// 引数の座標が示すマスの番号を返す（-1は盤外）

private:
	int x, y;	// ボードの中心座標
	int handle;	// 画像ハンドル

	const int size;					// ボードの大きさ
	const unsigned int baseColor;	// ボードのベース色
	const unsigned int frameColor;	// ボードの枠色

	void MakeBoardHandle();			// ボードの画像ハンドル作成
};