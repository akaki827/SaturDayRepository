#pragma once

#include "Config.h"
#include "Animation.h"
#include "AnimationType.h"
#include "FrameManager.h"

class Game
{
private:
	//==================================
	//フレームマネージャー
	//==================================
	FrameManager frameManager;
	//==================================
	//アニメーション
	//==================================
	Animation animations;
	//==================================
	//分割画像
	//==================================
	int images[Config::PLAYER_TOTAL_FRAMES];
	//==================================
	//現在のアニメーション
	//==================================
	AnimationType currentAnim;
	//==================================
	//前回のスペースキーの状態
	//==================================
	bool oldspace;
	//==================================
	//アニメーション切替
	//==================================
	void PlayerAnimation(AnimationType type);

public:
	//初期化
	void Init();
	//更新
	void Update();
	//描画
	void Draw();
};

