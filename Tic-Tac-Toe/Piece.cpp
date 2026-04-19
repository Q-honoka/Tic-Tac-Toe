#include "Piece.h"
#include "DxLib.h"
#include "Config.h"

/// <summary>
/// コンストラクタ
/// </summary>
Piece::Piece() :
	x(0),
	y(0),
	isVisible(false),
	color(0),
	radius(Config::Piece::RADIUS)
{ }

/// <summary>
/// デストラクタ
/// </summary>
Piece::~Piece()
{
	
}

/// <summary>
/// 描画処理
/// </summary>
void Piece::Draw() const
{
	if (isVisible == false) return;
	
	DrawCircle(x, y, radius, color, TRUE);
}

/// <summary>
/// 座標を設定する
/// </summary>
/// <param name="centerX">int[中心座標X]</param>
/// <param name="centerY">int[中心座標Y]</param>
void Piece::SetPosition(int centerX, int centerY)
{
	x = centerX;
	y = centerY;
}

/// <summary>
/// 表示を切り替える。色を設定する
/// </summary>
/// <param name="state">bool[true：可視, false：不可視]</param>
/// <param name="clr">unsigned int[コマの色]</param>
void Piece::SetIsVisble(bool state, unsigned int clr)
{
	isVisible = state;
	color = clr;
}

/// <summary>
/// 表示状態を返す
/// </summary>
/// <returns>bool[true：可視, false：不可視]</returns>
bool Piece::GetIsVisble() const
{
	return isVisible;
}