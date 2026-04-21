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
	isFirstPiece(true),
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
/// 表示を切り替えて、対応するコマの色を設定する
/// </summary>
/// <param name="state"></param>
/// <param name="turn"></param>
void Piece::SetIsVisible(bool state, bool isFirst)
{
	isVisible = state;
	isFirstPiece = isFirst;
	if (isFirst) color = GetColor(Config::Piece::COLOR_FIRST[0], Config::Piece::COLOR_FIRST[1], Config::Piece::COLOR_FIRST[2]);
	else color = GetColor(Config::Piece::COLOR_SECOND[0], Config::Piece::COLOR_SECOND[1], Config::Piece::COLOR_SECOND[2]);
}

/// <summary>
/// 表示状態を返す
/// </summary>
/// <returns>bool[true：可視, false：不可視]</returns>
bool Piece::GetIsVisible() const
{
	return isVisible;
}

/// <summary>
/// コマの持ち主を返す
/// </summary>
/// <returns>true[先手], false[後手]</returns>
bool Piece::GetIsFirstPiece() const
{
	return isFirstPiece;
}