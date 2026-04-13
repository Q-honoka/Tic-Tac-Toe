#pragma once
#include "Board.h"
#include "InputManager.h"

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
	InputManager inputManager;
	Board board;
};