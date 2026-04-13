#pragma once
#include "Config.h"

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

private:
	int pieces[9];	// 各マスの状態
	int x, y;	// 中心座標
	int handle;	// 画像ハンドル

	const int size;					// ボードの大きさ
	const unsigned int baseColor;	// ボードのベース色
	const unsigned int frameColor;	// ボードの枠色
};