#include"DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	ChangeWindowMode(TRUE);
	ChangeWindowMode(TRUE);
	DxLib_Init();
	SetGraphMode(800, 600, 32);
	if (DxLib_Init() == -1) return -1;

	int R = 255, G = 0, B = 0;


	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();

		int fontColor = GetColor(R, G, B);

		if (R == 255 and G != 255 and B == 0)G++;
		if (R != 0 and G == 255 and B == 0)R--;
		if (G == 255 and B != 255 and R == 0)B++;
		if (G != 0 and B == 255 and R == 0)G--;
		if (B == 255 and R != 255 and G == 0)R++;
		if (B != 0 and R == 255 and G == 0)B--;

		SetFontSize(100);
		DrawFormatString(75, 250, fontColor, "I'am person...",R,G,B);

		ScreenFlip();
	}

	DxLib_End();

	return 0;
}