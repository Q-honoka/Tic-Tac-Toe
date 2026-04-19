#pragma once

/*
	名前：Piece.h
	役割：コマの生成と描画を行うクラスです。
*/

class Piece
{
public:
	Piece();	// コンストラクタ
	~Piece();	// デストラクタ
	void Draw() const;		// 描画
	void SetPosition(int centerX, int centerY);	// 座標を設定する
	void SetIsVisble(bool state, unsigned int clr = 0);		// 表示を切り替える
	bool GetIsVisble() const;			// 表示状態を返す

private:
	int x,y;	// コマの中心座標
	bool isVisible;		// 可視状態（true：可視, false：不可視）
	unsigned int color;	// コマの色
	const int radius;	// コマの半径
};