#pragma once
#include "Config.h"



class Board
{
public:
	Board();		// コンストラクタ
	~Board();		// デストラクタ
	void Update();			// 更新
	void Draw() const;		// 描画

private:
	int x, y;	// 中心座標
	int handle;	// 画像ハンドル

	void InitializeBoard();		// 初期化
	void FinalizeBoard() const;		// 終了処理
};