
#include "BackGround.h"
#include "DxLib.h"

//=======================================
//èâä˙âª
//=======================================
void BackGround::Init()
{
	imageHandle = LoadGraph("img/Background.png");
}
//=======================================
//ï`âÊ
//=======================================
void BackGround::Draw(float cameraX)
{
	DrawGraph(-(int)(cameraX * 0.5f), 0, imageHandle, TRUE);
}