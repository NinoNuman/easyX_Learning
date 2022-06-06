#include "utils.hpp"
#include "global.hpp"

void animation::ClearScreen(DWORD* pScreen, int screenW, int screenH)
{
	int i = 0;
	for (; i < screenW; i++)
	{
		pScreen[i] = 0;
	}
	for (; i < screenW * (screenH - 1); i++)
	{
		int left = i - 1;		// 左
		int right = i + 1;		// 右
		int up = i - screenW;	// 上
		int bottom = i + screenW;	// 下

		int r = int(((double)GetRValue(pScreen[i]) + (double)GetRValue(pScreen[left]) + (double)GetRValue(pScreen[right]) + (double)GetRValue(pScreen[up]) + (double)GetRValue(pScreen[bottom])) / 5.8);
		int g = int(((double)GetGValue(pScreen[i]) + (double)GetGValue(pScreen[left]) + (double)GetGValue(pScreen[right]) + (double)GetGValue(pScreen[up]) + (double)GetGValue(pScreen[bottom])) / 5.8);
		int b = int(((double)GetBValue(pScreen[i]) + (double)GetBValue(pScreen[left]) + (double)GetBValue(pScreen[right]) + (double)GetBValue(pScreen[up]) + (double)GetBValue(pScreen[bottom])) / 5.8);

		pScreen[i] = RGB(r, g, b);
	}
	for (; i < screenW * screenH; i++)
	{
		pScreen[i] = 0;
	}
}


// 设置坐标系统
void animation::InitPositionSystem()
{
	setaspectratio(static_cast<float>(animation::asp), static_cast<float>(-animation::asp));	// 设置缩放比例 以及坐标方向
	setorigin(0, animation::scrH);				// 设置坐标原点
}

// 显示帧数
void animation::DrawFrame(int Value, int x = 200, int y = 300)
{
	setbkmode(TRANSPARENT);			// 透明文字
	settextcolor(RGB(255, 228, 181));
	settextstyle(30, 20, TEXT("新宋体"));


	setaspectratio(1.0, 1.0);		// 设置缩放比例 以及坐标方向， 在这里不设置回来的话，文字输出是镜面反转的
	setorigin(0, 0);				// 设置坐标原点
	TCHAR buff[256];
	//wsprintf(buff, _T("%s"), "HAPPY BRITHDAY!!");

	outtextxy(x, y, _T("HAPPY BRITHDAY!!"));
	outtextxy(x + 50, y + 50, _T("by Nino·Neumann"));
	outtextxy(x + 100, y + 100, _T("powered by EasyX"));

	InitPositionSystem();
}