#include "Animation.h"
#include "DxLib.h"

//==================================
//コンストラクタ
//==================================
Animation::Animation()
{
	//分割画像をNullポインターとして初期化
	images = nullptr;
	//開始フレーム
	startFrame = 0;
	//再生フレーム
	frameCount = 1;
	//idleのスピード
	speed = 10;
	//再生開始時間
	startTime = 0;
}
//==================================
//分割画像設定
//==================================
void Animation::SetImages(int* img)
{
	//分割の画像を取り込み
	images = img;
}

//==================================
//アニメーション再生
//==================================
void Animation::Play(int start, int flame, int spd)
{
	//アニメーションの開始位置設定
	startFrame = start;
	//再生するフレーム数を設定
	frameCount = flame;
	//アニメーション速度を設定
	speed = spd;
}

//==================================
//現在描画する画像取得
//==================================
int Animation::GetImage(int currentTime)
{

	//==================================
	//アニメーション番号計算
	//==================================

	int fram = (currentTime / speed) % frameCount;
	return images[startFrame + fram];
}