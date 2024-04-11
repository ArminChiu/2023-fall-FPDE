#include "fir.h"
//根据棋型对单一位置进行打分
int Score(int i, int j, int n)
{
	if (n == 1)
	{ // 先手
		int x, y;
		// 记录各种棋形的变量，四个代表四个方向
		int lian1, lian2, lian3, lian4;							  // 连子
		int huo1, huo2, huo3, huo4;								  // 活子
		int tiaothree1, tiaothree2, tiaothree3, tiaothree4;		  // 跳三
		int tiaofour, tiaofour1, tiaofour2, tiaofour3, tiaofour4; // 跳四
		int fakethree1, fakethree2, fakethree3, fakethree4;		  // 假活三
		int mianthree1, mianthree2, mianthree3, mianthree4;	  // 眠三
		int huotwo1, huotwo2, huotwo3, huotwo4;					  // 活二
		int miantwo1, miantwo2, miantwo3, miantwo4;			  // 眠二
		int value;												  // 返回值分数
		value = 0;
		x = i;
		y = j;
		// 竖
		lian1 = 0;
		huo1 = 0;
		while (x + 1 <= 14 && search(x + 1, j) == 1)
		{
			++x;
			++lian1;
		}
		if (x == 14 || search(x + 1, j) == 2)
			++huo1;
		x = i;
		y = j;
		while (x - 1 >= 0 && search(x - 1, j) == 1)
		{
			--x;
			++lian1;
		}
		if (x == 0 || search(x - 1, j) == 2)
			++huo1;
		x = i;
		y = j;
		// 横
		lian2 = 0;
		huo2 = 0;
		while (y + 1 <= 14 && search(i, y + 1) == 1)
		{
			++y;
			++lian2;
		}
		if (y == 14 || search(i, y + 1) == 2)
			++huo2;
		x = i;
		y = j;
		while (y - 1 >= 0 && search(i, y - 1) == 1)
		{
			--y;
			++lian2;
		}
		if (y == 0 || search(i, y - 1) == 2)
			++huo2;
		x = i;
		y = j;
		// 斜1
		lian3 = 0;
		huo3 = 0;
		while (x + 1 <= 14 && y + 1 <= 14 && search(x + 1, y + 1) == 1)
		{
			++x;
			++y;
			++lian3;
		}
		if (x == 14 || y == 14 || search(x + 1, y + 1) == 2)
			++huo3;
		x = i;
		y = j;
		while (x - 1 >= 0 && y - 1 >= 0 && search(x - 1, y - 1) == 1)
		{
			--x;
			--y;
			++lian3;
		}
		if (x == 0 || y == 0 || search(x - 1, y - 1) == 2)
			++huo3;
		x = i;
		y = j;
		// 斜2
		lian4 = 0;
		huo4 = 0;
		while (x + 1 <= 14 && y - 1 >= 0 && search(x + 1, y - 1) == 1)
		{
			++x;
			--y;
			++lian4;
		}
		if (x == 14 || y == 0 || search(x + 1, y - 1) == 2)
			++huo4;
		x = i;
		y = j;
		while (x - 1 >= 0 && y + 1 <= 14 && search(x - 1, y + 1) == 1)
		{
			--x;
			++y;
			++lian4;
		}
		if (x == 0 || y == 14 || search(x - 1, y + 1) == 2)
			++huo4;
		x = i;
		y = j;
		/*活二
			1.001100
			2.011000
			3.001010
			4.010010
		*/
		// 竖
		huotwo1 = 0;
		// 1
		if (search(i - 2, j) == 0 && search(i - 1, j) == 0 && search(i + 2, j) == 0 && search(i + 3, j) == 0 && search(i + 1, j) == 1)
			++huotwo1;
		if (search(i + 2, j) == 0 && search(i + 1, j) == 0 && search(i - 2, j) == 0 && search(i - 3, j) == 0 && search(i - 1, j) == 1)
			++huotwo1;
		// 2
		if (search(i - 1, j) == 0 && search(i + 2, j) == 0 && search(i + 3, j) == 0 && search(i + 4, j) == 0 && search(i + 1, j) == 1)
			++huotwo1;
		if (search(i - 2, j) == 0 && search(i + 1, j) == 0 && search(i + 2, j) == 0 && search(i + 3, j) == 0 && search(i - 1, j) == 1)
			++huotwo1;
		if (search(i + 1, j) == 0 && search(i - 2, j) == 0 && search(i - 3, j) == 0 && search(i - 4, j) == 0 && search(i - 1, j) == 1)
			++huotwo1;
		if (search(i + 2, j) == 0 && search(i - 1, j) == 0 && search(i - 2, j) == 0 && search(i - 3, j) == 0 && search(i + 1, j) == 1)
			++huotwo1;
		// 3
		if (search(i - 2, j) == 0 && search(i - 1, j) == 0 && search(i + 1, j) == 0 && search(i + 3, j) == 0 && search(i + 2, j) == 1)
			++huotwo1;
		if (search(i - 4, j) == 0 && search(i - 3, j) == 0 && search(i - 1, j) == 0 && search(i + 1, j) == 0 && search(i - 2, j) == 1)
			++huotwo1;
		if (search(i + 2, j) == 0 && search(i + 1, j) == 0 && search(i - 1, j) == 0 && search(i - 3, j) == 0 && search(i - 2, j) == 1)
			++huotwo1;
		if (search(i + 4, j) == 0 && search(i + 3, j) == 0 && search(i + 1, j) == 0 && search(i - 1, j) == 0 && search(i + 2, j) == 1)
			++huotwo1;
		// 4
		if (search(i - 1, j) == 0 && search(i + 1, j) == 0 && search(i + 2, j) == 0 && search(i + 4, j) == 0 && search(i + 3, j) == 1)
			++huotwo1;
		if (search(i + 1, j) == 0 && search(i - 1, j) == 0 && search(i - 2, j) == 0 && search(i - 4, j) == 0 && search(i - 3, j) == 1)
			++huotwo1;
		// 横
		huotwo2 = 0;
		// 1
		if (search(i, j - 2) == 0 && search(i, j - 1) == 0 && search(i, j + 2) == 0 && search(i, j + 3) == 0 && search(i, j + 1) == 1)
			++huotwo2;
		if (search(i, j + 2) == 0 && search(i, j + 1) == 0 && search(i, j - 2) == 0 && search(i, j - 3) == 0 && search(i, j - 1) == 1)
			++huotwo2;
		// 2
		if (search(i, j - 1) == 0 && search(i, j + 2) == 0 && search(i, j + 3) == 0 && search(i, j + 4) == 0 && search(i, j + 1) == 1)
			++huotwo2;
		if (search(i, j - 2) == 0 && search(i, j + 1) == 0 && search(i, j + 2) == 0 && search(i, j + 3) == 0 && search(i, j - 1) == 1)
			++huotwo2;
		if (search(i, j + 1) == 0 && search(i, j - 2) == 0 && search(i, j - 3) == 0 && search(i, j - 4) == 0 && search(i, j - 1) == 1)
			++huotwo2;
		if (search(i, j + 2) == 0 && search(i, j - 1) == 0 && search(i, j - 2) == 0 && search(i, j - 3) == 0 && search(i, j + 1) == 1)
			++huotwo2;
		// 3
		if (search(i, j - 2) == 0 && search(i, j - 1) == 0 && search(i, j + 1) == 0 && search(i, j + 3) == 0 && search(i, j + 2) == 1)
			++huotwo2;
		if (search(i, j - 4) == 0 && search(i, j - 3) == 0 && search(i, j - 1) == 0 && search(i, j + 1) == 0 && search(i, j - 2) == 1)
			++huotwo2;
		if (search(i, j + 2) == 0 && search(i, j + 1) == 0 && search(i, j - 1) == 0 && search(i, j - 3) == 0 && search(i, j - 2) == 1)
			++huotwo2;
		if (search(i, j + 4) == 0 && search(i, j + 3) == 0 && search(i, j + 1) == 0 && search(i, j - 1) == 0 && search(i, j + 2) == 1)
			++huotwo2;
		// 4
		if (search(i, j - 1) == 0 && search(i, j + 1) == 0 && search(i, j + 2) == 0 && search(i, j + 4) == 0 && search(i, j + 3) == 1)
			++huotwo2;
		if (search(i, j + 1) == 0 && search(i, j - 1) == 0 && search(i, j - 2) == 0 && search(i, j - 4) == 0 && search(i, j - 3) == 1)
			++huotwo2;
		// 斜1
		huotwo3 = 0;
		// 1
		if (search(i - 2, j - 2) == 0 && search(i - 1, j - 1) == 0 && search(i + 2, j + 2) == 0 && search(i + 3, j + 3) == 0 && search(i + 1, j + 1) == 1)
			++huotwo3;
		if (search(i + 2, j + 2) == 0 && search(i + 1, j + 1) == 0 && search(i - 2, j - 2) == 0 && search(i - 3, j - 3) == 0 && search(i - 1, j - 1) == 1)
			++huotwo3;
		// 2
		if (search(i - 1, j - 1) == 0 && search(i + 2, j + 2) == 0 && search(i + 3, j + 3) == 0 && search(i + 4, j + 4) == 0 && search(i + 1, j + 1) == 1)
			++huotwo3;
		if (search(i - 2, j - 2) == 0 && search(i + 1, j + 1) == 0 && search(i + 2, j + 2) == 0 && search(i + 3, j + 3) == 0 && search(i - 1, j - 1) == 1)
			++huotwo3;
		if (search(i + 1, j + 1) == 0 && search(i - 2, j - 2) == 0 && search(i - 3, j - 3) == 0 && search(i - 4, j - 4) == 0 && search(i - 1, j - 1) == 1)
			++huotwo3;
		if (search(i + 2, j + 2) == 0 && search(i - 1, j - 1) == 0 && search(i - 2, j - 2) == 0 && search(i - 3, j - 3) == 0 && search(i + 1, j + 1) == 1)
			++huotwo3;
		// 3
		if (search(i - 2, j - 2) == 0 && search(i - 1, j - 1) == 0 && search(i + 1, j + 1) == 0 && search(i + 3, j + 3) == 0 && search(i + 2, j + 2) == 1)
			++huotwo3;
		if (search(i - 4, j - 4) == 0 && search(i - 3, j - 3) == 0 && search(i - 1, j - 1) == 0 && search(i + 1, j + 1) == 0 && search(i - 2, j - 2) == 1)
			++huotwo3;
		if (search(i + 2, j + 2) == 0 && search(i + 1, j + 1) == 0 && search(i - 1, j - 1) == 0 && search(i - 3, j - 3) == 0 && search(i - 2, j - 2) == 1)
			++huotwo3;
		if (search(i + 4, j + 4) == 0 && search(i + 3, j + 3) == 0 && search(i + 1, j + 1) == 0 && search(i - 1, j - 1) == 0 && search(i + 2, j + 2) == 1)
			++huotwo3;
		// 4
		if (search(i - 1, j - 1) == 0 && search(i + 1, j + 1) == 0 && search(i + 2, j + 2) == 0 && search(i + 4, j + 4) == 0 && search(i + 3, j + 3) == 1)
			++huotwo3;
		if (search(i + 1, j + 1) == 0 && search(i - 1, j - 1) == 0 && search(i - 2, j - 2) == 0 && search(i - 4, j - 4) == 0 && search(i - 3, j - 3) == 1)
			++huotwo3;
		// 斜2
		huotwo4 = 0;
		// 1
		if (search(i - 2, j + 2) == 0 && search(i - 1, j + 1) == 0 && search(i + 2, j - 2) == 0 && search(i + 3, j - 3) == 0 && search(i + 1, j - 1) == 1)
			++huotwo4;
		if (search(i + 2, j - 2) == 0 && search(i + 1, j - 1) == 0 && search(i - 2, j + 2) == 0 && search(i - 3, j + 3) == 0 && search(i - 1, j + 1) == 1)
			++huotwo4;
		// 2
		if (search(i - 1, j + 1) == 0 && search(i + 2, j - 2) == 0 && search(i + 3, j - 3) == 0 && search(i + 4, j - 4) == 0 && search(i + 1, j - 1) == 1)
			++huotwo4;
		if (search(i - 2, j + 2) == 0 && search(i + 1, j - 1) == 0 && search(i + 2, j - 2) == 0 && search(i + 3, j - 3) == 0 && search(i - 1, j + 1) == 1)
			++huotwo4;
		if (search(i + 1, j - 1) == 0 && search(i - 2, j + 2) == 0 && search(i - 3, j + 3) == 0 && search(i - 4, j + 4) == 0 && search(i - 1, j + 1) == 1)
			++huotwo4;
		if (search(i + 2, j - 2) == 0 && search(i - 1, j + 1) == 0 && search(i - 2, j + 2) == 0 && search(i - 3, j + 3) == 0 && search(i + 1, j - 1) == 1)
			++huotwo4;
		// 3
		if (search(i - 2, j + 2) == 0 && search(i - 1, j + 1) == 0 && search(i + 1, j - 1) == 0 && search(i + 3, j - 3) == 0 && search(i + 2, j - 2) == 1)
			++huotwo4;
		if (search(i - 4, j + 4) == 0 && search(i - 3, j + 3) == 0 && search(i - 1, j + 1) == 0 && search(i + 1, j - 1) == 0 && search(i - 2, j + 2) == 1)
			++huotwo4;
		if (search(i + 2, j - 2) == 0 && search(i + 1, j - 1) == 0 && search(i - 1, j + 1) == 0 && search(i - 3, j + 3) == 0 && search(i - 2, j + 2) == 1)
			++huotwo4;
		if (search(i + 4, j - 4) == 0 && search(i + 3, j - 3) == 0 && search(i + 1, j - 1) == 0 && search(i - 1, j + 1) == 0 && search(i + 2, j - 2) == 1)
			++huotwo4;
		// 4
		if (search(i - 1, j + 1) == 0 && search(i + 1, j - 1) == 0 && search(i + 2, j - 2) == 0 && search(i + 4, j - 4) == 0 && search(i + 3, j - 3) == 1)
			++huotwo4;
		if (search(i + 1, j - 1) == 0 && search(i - 1, j + 1) == 0 && search(i - 2, j + 2) == 0 && search(i - 4, j + 4) == 0 && search(i - 3, j + 3) == 1)
			++huotwo4;
		/*眠2
			1.211000
			2.210100
			3.210010
			4.10001
			5.2001102
			6.2010102
		*/
		// 竖
		miantwo1 = 0;
		// 1
		if (search(i + 2, j) == 0 && search(i + 3, j) == 0 && search(i + 4, j) == 0 && search(i - 1, j) != 0 && search(i - 1, j) != 1 && search(i + 1, j) == 1)
			++miantwo1;
		if (search(i + 1, j) == 0 && search(i + 2, j) == 0 && search(i + 3, j) == 0 && search(i - 2, j) != 0 && search(i - 2, j) != 1 && search(i - 1, j) == 1)
			++miantwo1;
		if (search(i - 2, j) == 0 && search(i - 3, j) == 0 && search(i - 4, j) == 0 && search(i + 1, j) != 0 && search(i + 1, j) != 1 && search(i - 1, j) == 1)
			++miantwo1;
		if (search(i - 1, j) == 0 && search(i - 2, j) == 0 && search(i - 3, j) == 0 && search(i + 2, j) != 0 && search(i + 2, j) != 1 && search(i + 1, j) == 1)
			++miantwo1;
		// 2
		if (search(i + 1, j) == 0 && search(i + 3, j) == 0 && search(i + 4, j) == 0 && search(i - 1, j) != 0 && search(i - 1, j) != 1 && search(i + 2, j) == 1)
			++miantwo1;
		if (search(i - 1, j) == 0 && search(i + 1, j) == 0 && search(i + 2, j) == 0 && search(i - 3, j) != 0 && search(i - 3, j) != 1 && search(i - 2, j) == 1)
			++miantwo1;
		if (search(i - 1, j) == 0 && search(i - 3, j) == 0 && search(i - 4, j) == 0 && search(i + 1, j) != 0 && search(i + 1, j) != 1 && search(i - 2, j) == 1)
			++miantwo1;
		if (search(i + 1, j) == 0 && search(i - 1, j) == 0 && search(i - 2, j) == 0 && search(i + 3, j) != 0 && search(i + 3, j) != 1 && search(i + 2, j) == 1)
			++miantwo1;
		// 3
		if (search(i + 1, j) == 0 && search(i + 2, j) == 0 && search(i + 4, j) == 0 && search(i - 1, j) != 0 && search(i - 1, j) != 1 && search(i + 3, j) == 1)
			++miantwo1;
		if (search(i - 2, j) == 0 && search(i - 1, j) == 0 && search(i + 1, j) == 0 && search(i - 4, j) != 0 && search(i - 4, j) != 1 && search(i - 3, j) == 1)
			++miantwo1;
		if (search(i - 1, j) == 0 && search(i - 2, j) == 0 && search(i - 4, j) == 0 && search(i + 1, j) != 0 && search(i + 1, j) != 1 && search(i - 3, j) == 1)
			++miantwo1;
		if (search(i + 2, j) == 0 && search(i + 1, j) == 0 && search(i - 1, j) == 0 && search(i + 4, j) != 0 && search(i + 4, j) != 1 && search(i + 3, j) == 1)
			++miantwo1;
		// 4
		if (search(i + 1, j) == 0 && search(i + 2, j) == 0 && search(i + 3, j) == 0 && search(i + 4, j) == 1)
			++miantwo1;
		if (search(i - 1, j) == 0 && search(i - 2, j) == 0 && search(i - 3, j) == 0 && search(i - 4, j) == 1)
			++miantwo1;
		// 5
		if (search(i - 2, j) == 0 && search(i - 1, j) == 0 && search(i + 2, j) == 0 && search(i - 3, j) != 0 && search(i - 3, j) != 1 && search(i + 1, j) == 1 && search(i + 3, j) != 0 && search(i + 3, j) != 1)
			++miantwo1;
		if (search(i - 3, j) == 0 && search(i - 2, j) == 0 && search(i + 1, j) == 0 && search(i - 4, j) != 0 && search(i - 4, j) != 1 && search(i - 1, j) == 1 && search(i + 2, j) != 0 && search(i + 2, j) != 1)
			++miantwo1;
		if (search(i + 2, j) == 0 && search(i + 1, j) == 0 && search(i - 2, j) == 0 && search(i + 3, j) != 0 && search(i + 3, j) != 1 && search(i - 1, j) == 1 && search(i - 3, j) != 0 && search(i - 3, j) != 1)
			++miantwo1;
		if (search(i + 3, j) == 0 && search(i + 2, j) == 0 && search(i - 1, j) == 0 && search(i + 4, j) != 0 && search(i + 4, j) != 1 && search(i + 1, j) == 1 && search(i - 2, j) != 0 && search(i - 2, j) != 1)
			++miantwo1;
		// 6
		if (search(i - 1, j) == 0 && search(i + 1, j) == 0 && search(i + 3, j) == 0 && search(i - 2, j) != 0 && search(i - 2, j) != 1 && search(i + 2, j) == 1 && search(i + 4, j) != 0 && search(i + 4, j) != 1)
			++miantwo1;
		if (search(i + 1, j) == 0 && search(i - 1, j) == 0 && search(i - 3, j) == 0 && search(i + 2, j) != 0 && search(i + 2, j) != 1 && search(i - 2, j) == 1 && search(i - 4, j) != 0 && search(i - 4, j) != 1)
			++miantwo1;
		// 横
		miantwo2 = 0;
		// 1
		if (search(i, j + 2) == 0 && search(i, j + 3) == 0 && search(i, j + 4) == 0 && search(i, j - 1) != 0 && search(i, j - 1) != 1 && search(i, j + 1) == 1)
			++miantwo2;
		if (search(i, j + 1) == 0 && search(i, j + 2) == 0 && search(i, j + 3) == 0 && search(i, j - 2) != 0 && search(i, j - 2) != 1 && search(i, j - 1) == 1)
			++miantwo2;
		if (search(i, j - 2) == 0 && search(i, j - 3) == 0 && search(i, j - 4) == 0 && search(i, j + 1) != 0 && search(i, j + 1) != 1 && search(i, j - 1) == 1)
			++miantwo2;
		if (search(i, j - 1) == 0 && search(i, j - 2) == 0 && search(i, j - 3) == 0 && search(i, j + 2) != 0 && search(i, j + 2) != 1 && search(i, j + 1) == 1)
			++miantwo2;
		// 2
		if (search(i, j + 1) == 0 && search(i, j + 3) == 0 && search(i, j + 4) == 0 && search(i, j - 1) != 0 && search(i, j - 1) != 1 && search(i, j + 2) == 1)
			++miantwo2;
		if (search(i, j - 1) == 0 && search(i, j + 1) == 0 && search(i, j + 2) == 0 && search(i, j - 3) != 0 && search(i, j - 3) != 1 && search(i, j - 2) == 1)
			++miantwo2;
		if (search(i, j - 1) == 0 && search(i, j - 3) == 0 && search(i, j - 4) == 0 && search(i, j + 1) != 0 && search(i, j + 1) != 1 && search(i, j - 2) == 1)
			++miantwo2;
		if (search(i, j + 1) == 0 && search(i, j - 1) == 0 && search(i, j - 2) == 0 && search(i, j + 3) != 0 && search(i, j + 3) != 1 && search(i, j + 2) == 1)
			++miantwo2;
		// 3
		if (search(i, j + 1) == 0 && search(i, j + 2) == 0 && search(i, j + 4) == 0 && search(i, j - 1) != 0 && search(i, j - 1) != 1 && search(i, j + 3) == 1)
			++miantwo2;
		if (search(i, j - 2) == 0 && search(i, j - 1) == 0 && search(i, j + 1) == 0 && search(i, j - 4) != 0 && search(i, j - 4) != 1 && search(i, j - 3) == 1)
			++miantwo2;
		if (search(i, j - 1) == 0 && search(i, j - 2) == 0 && search(i, j - 4) == 0 && search(i, j + 1) != 0 && search(i, j + 1) != 1 && search(i, j - 3) == 1)
			++miantwo2;
		if (search(i, j + 2) == 0 && search(i, j + 1) == 0 && search(i, j - 1) == 0 && search(i, j + 4) != 0 && search(i, j + 4) != 1 && search(i, j + 3) == 1)
			++miantwo2;
		// 4
		if (search(i, j + 1) == 0 && search(i, j + 2) == 0 && search(i, j + 3) == 0 && search(i, j + 4) == 1)
			++miantwo2;
		if (search(i, j - 1) == 0 && search(i, j - 2) == 0 && search(i, j - 3) == 0 && search(i, j - 4) == 1)
			++miantwo2;
		// 5
		if (search(i, j - 2) == 0 && search(i, j - 1) == 0 && search(i, j + 2) == 0 && search(i, j - 3) != 0 && search(i, j - 3) != 1 && search(i, j + 1) == 1 && search(i, j + 3) != 0 && search(i, j + 3) != 1)
			++miantwo1;
		if (search(i, j - 3) == 0 && search(i, j - 2) == 0 && search(i, j + 1) == 0 && search(i, j - 4) != 0 && search(i, j - 4) != 1 && search(i, j - 1) == 1 && search(i, j + 2) != 0 && search(i, j + 2) != 1)
			++miantwo1;
		if (search(i, j + 2) == 0 && search(i, j + 1) == 0 && search(i, j - 2) == 0 && search(i, j + 3) != 0 && search(i, j + 3) != 1 && search(i, j - 1) == 1 && search(i, j - 3) != 0 && search(i, j - 3) != 1)
			++miantwo2;
		if (search(i, j + 3) == 0 && search(i, j + 2) == 0 && search(i, j - 1) == 0 && search(i, j + 4) != 0 && search(i, j + 4) != 1 && search(i, j + 1) == 1 && search(i, j - 2) != 0 && search(i, j - 2) != 1)
			++miantwo2;
		// 6
		if (search(i, j - 1) == 0 && search(i, j + 1) == 0 && search(i, j + 3) == 0 && search(i, j - 2) != 0 && search(i, j - 2) != 1 && search(i, j + 2) == 1 && search(i, j + 4) != 0 && search(i, j + 4) != 1)
			++miantwo2;
		if (search(i, j + 1) == 0 && search(i, j - 1) == 0 && search(i, j - 3) == 0 && search(i, j + 2) != 0 && search(i, j + 2) != 1 && search(i, j - 2) == 1 && search(i, j - 4) != 0 && search(i, j - 4) != 1)
			++miantwo2;
		// 斜1
		miantwo3 = 0;
		// 1
		if (search(i + 2, j + 2) == 0 && search(i + 3, j + 3) == 0 && search(i + 4, j + 4) == 0 && search(i - 1, j - 1) != 0 && search(i - 1, j - 1) != 1 && search(i + 1, j + 1) == 1)
			++miantwo3;
		if (search(i + 1, j + 1) == 0 && search(i + 2, j + 2) == 0 && search(i + 3, j + 3) == 0 && search(i - 2, j - 2) != 0 && search(i - 2, j - 2) != 1 && search(i - 1, j - 1) == 1)
			++miantwo3;
		if (search(i - 2, j - 2) == 0 && search(i - 3, j - 3) == 0 && search(i - 4, j - 4) == 0 && search(i + 1, j + 1) != 0 && search(i + 1, j + 1) != 1 && search(i - 1, j - 1) == 1)
			++miantwo3;
		if (search(i - 1, j - 1) == 0 && search(i - 2, j - 2) == 0 && search(i - 3, j - 3) == 0 && search(i + 2, j + 2) != 0 && search(i + 2, j + 2) != 1 && search(i + 1, j + 1) == 1)
			++miantwo3;
		// 2
		if (search(i + 1, j + 1) == 0 && search(i + 3, j + 3) == 0 && search(i + 4, j + 4) == 0 && search(i - 1, j - 1) != 0 && search(i - 1, j - 1) != 1 && search(i + 2, j + 2) == 1)
			++miantwo3;
		if (search(i - 1, j - 1) == 0 && search(i + 1, j + 1) == 0 && search(i + 2, j + 2) == 0 && search(i - 3, j - 3) != 0 && search(i - 3, j - 3) != 1 && search(i - 2, j - 2) == 1)
			++miantwo3;
		if (search(i - 1, j - 1) == 0 && search(i - 3, j - 3) == 0 && search(i - 4, j - 4) == 0 && search(i + 1, j + 1) != 0 && search(i + 1, j + 1) != 1 && search(i - 2, j - 2) == 1)
			++miantwo3;
		if (search(i + 1, j + 1) == 0 && search(i - 1, j - 1) == 0 && search(i - 2, j - 2) == 0 && search(i + 3, j + 3) != 0 && search(i + 3, j + 3) != 1 && search(i + 2, j + 2) == 1)
			++miantwo3;
		// 3
		if (search(i + 1, j + 1) == 0 && search(i + 2, j + 2) == 0 && search(i + 4, j + 4) == 0 && search(i - 1, j - 1) != 0 && search(i - 1, j - 1) != 1 && search(i + 3, j + 3) == 1)
			++miantwo3;
		if (search(i - 2, j - 2) == 0 && search(i - 1, j - 1) == 0 && search(i + 1, j + 1) == 0 && search(i - 4, j - 4) != 0 && search(i - 4, j - 4) != 1 && search(i - 3, j - 3) == 1)
			++miantwo3;
		if (search(i - 1, j - 1) == 0 && search(i - 2, j - 2) == 0 && search(i - 4, j - 4) == 0 && search(i + 1, j + 1) != 0 && search(i + 1, j + 1) != 1 && search(i - 3, j - 3) == 1)
			++miantwo3;
		if (search(i + 2, j + 2) == 0 && search(i + 1, j + 1) == 0 && search(i - 1, j - 1) == 0 && search(i + 4, j + 4) != 0 && search(i + 4, j + 4) != 1 && search(i + 3, j + 3) == 1)
			++miantwo3;
		// 4
		if (search(i + 1, j + 1) == 0 && search(i + 2, j + 2) == 0 && search(i + 3, j + 3) == 0 && search(i + 4, j + 4) == 1)
			++miantwo3;
		if (search(i - 1, j - 1) == 0 && search(i - 2, j - 2) == 0 && search(i - 3, j - 3) == 0 && search(i - 4, j - 4) == 1)
			++miantwo3;
		// 5
		if (search(i - 2, j - 2) == 0 && search(i - 1, j - 1) == 0 && search(i + 2, j + 2) == 0 && search(i - 3, j - 3) != 0 && search(i - 3, j - 3) != 1 && search(i + 1, j + 1) == 1 && search(i + 3, j + 3) != 0 && search(i + 3, j + 3) != 1)
			++miantwo3;
		if (search(i - 3, j - 3) == 0 && search(i - 2, j - 2) == 0 && search(i + 1, j + 1) == 0 && search(i - 4, j - 4) != 0 && search(i - 4, j - 4) != 1 && search(i - 1, j - 1) == 1 && search(i + 2, j + 2) != 0 && search(i + 2, j + 2) != 1)
			++miantwo3;
		if (search(i + 2, j + 2) == 0 && search(i + 1, j + 1) == 0 && search(i - 2, j - 2) == 0 && search(i + 3, j + 3) != 0 && search(i + 3, j + 3) != 1 && search(i - 1, j - 1) == 1 && search(i - 3, j - 3) != 0 && search(i - 3, j - 3) != 1)
			++miantwo3;
		if (search(i + 3, j + 3) == 0 && search(i + 2, j + 2) == 0 && search(i - 1, j - 1) == 0 && search(i + 4, j + 4) != 0 && search(i + 4, j + 4) != 1 && search(i + 1, j + 1) == 1 && search(i - 2, j - 2) != 0 && search(i - 2, j - 2) != 1)
			++miantwo3;
		// 6
		if (search(i - 1, j - 1) == 0 && search(i + 1, j + 1) == 0 && search(i + 3, j + 3) == 0 && search(i - 2, j - 2) != 0 && search(i - 2, j - 2) != 1 && search(i + 2, j + 2) == 1 && search(i + 4, j + 4) != 0 && search(i + 4, j + 4) != 1)
			++miantwo3;
		if (search(i + 1, j + 1) == 0 && search(i - 1, j - 1) == 0 && search(i - 3, j - 3) == 0 && search(i + 2, j + 2) != 0 && search(i + 2, j + 2) != 1 && search(i - 2, j - 2) == 1 && search(i - 4, j - 4) != 0 && search(i - 4, j - 4) != 1)
			++miantwo3;
		// 斜2
		miantwo4 = 0;
		// 1
		if (search(i + 2, j - 2) == 0 && search(i + 3, j - 3) == 0 && search(i + 4, j - 4) == 0 && search(i - 1, j + 1) != 0 && search(i - 1, j + 1) != 1 && search(i + 1, j - 1) == 1)
			++miantwo4;
		if (search(i + 1, j - 1) == 0 && search(i + 2, j - 2) == 0 && search(i + 3, j - 3) == 0 && search(i - 2, j + 2) != 0 && search(i - 2, j + 2) != 1 && search(i - 1, j + 1) == 1)
			++miantwo4;
		if (search(i - 2, j + 2) == 0 && search(i - 3, j + 3) == 0 && search(i - 4, j + 4) == 0 && search(i + 1, j - 1) != 0 && search(i + 1, j - 1) != 1 && search(i - 1, j + 1) == 1)
			++miantwo4;
		if (search(i - 1, j + 1) == 0 && search(i - 2, j + 2) == 0 && search(i - 3, j + 3) == 0 && search(i + 2, j - 2) != 0 && search(i + 2, j - 2) != 1 && search(i + 1, j - 1) == 1)
			++miantwo4;
		// 2
		if (search(i + 1, j - 1) == 0 && search(i + 3, j - 3) == 0 && search(i + 4, j - 4) == 0 && search(i - 1, j + 1) != 0 && search(i - 1, j + 1) != 1 && search(i + 2, j - 2) == 1)
			++miantwo4;
		if (search(i - 1, j + 1) == 0 && search(i + 1, j - 1) == 0 && search(i + 2, j - 2) == 0 && search(i - 3, j + 3) != 0 && search(i - 3, j + 3) != 1 && search(i - 2, j + 2) == 1)
			++miantwo4;
		if (search(i - 1, j + 1) == 0 && search(i - 3, j + 3) == 0 && search(i - 4, j + 4) == 0 && search(i + 1, j - 1) != 0 && search(i + 1, j - 1) != 1 && search(i - 2, j + 2) == 1)
			++miantwo4;
		if (search(i + 1, j - 1) == 0 && search(i - 1, j + 1) == 0 && search(i - 2, j + 2) == 0 && search(i + 3, j - 3) != 0 && search(i + 3, j - 3) != 1 && search(i + 2, j - 2) == 1)
			++miantwo4;
		// 3
		if (search(i + 1, j - 1) == 0 && search(i + 2, j - 2) == 0 && search(i + 4, j - 4) == 0 && search(i - 1, j + 1) != 0 && search(i - 1, j + 1) != 1 && search(i + 3, j - 3) == 1)
			++miantwo4;
		if (search(i - 2, j + 2) == 0 && search(i - 1, j + 1) == 0 && search(i + 1, j - 1) == 0 && search(i - 4, j + 4) != 0 && search(i - 4, j + 4) != 1 && search(i - 3, j + 3) == 1)
			++miantwo4;
		if (search(i - 1, j + 1) == 0 && search(i - 2, j + 2) == 0 && search(i - 4, j + 4) == 0 && search(i + 1, j - 1) != 0 && search(i + 1, j - 1) != 1 && search(i - 3, j + 3) == 1)
			++miantwo4;
		if (search(i + 2, j - 2) == 0 && search(i + 1, j - 1) == 0 && search(i - 1, j + 1) == 0 && search(i + 4, j - 4) != 0 && search(i + 4, j - 4) != 1 && search(i + 3, j - 3) == 1)
			++miantwo4;
		// 4
		if (search(i + 1, j - 1) == 0 && search(i + 2, j - 2) == 0 && search(i + 3, j - 3) == 0 && search(i + 4, j - 4) == 1)
			++miantwo4;
		if (search(i - 1, j + 1) == 0 && search(i - 2, j + 2) == 0 && search(i - 3, j + 3) == 0 && search(i - 4, j + 4) == 1)
			++miantwo4;
		// 5
		if (search(i - 2, j + 2) == 0 && search(i - 1, j + 1) == 0 && search(i + 2, j - 2) == 0 && search(i - 3, j + 3) != 0 && search(i - 3, j + 3) != 1 && search(i + 1, j - 1) == 1 && search(i + 3, j - 3) != 0 && search(i + 3, j - 3) != 1)
			++miantwo4;
		if (search(i - 3, j + 3) == 0 && search(i - 2, j + 2) == 0 && search(i + 1, j - 1) == 0 && search(i - 4, j + 4) != 0 && search(i - 4, j + 4) != 1 && search(i - 1, j + 1) == 1 && search(i + 2, j - 2) != 0 && search(i + 2, j - 2) != 1)
			++miantwo4;
		if (search(i + 2, j - 2) == 0 && search(i + 1, j - 1) == 0 && search(i - 2, j + 2) == 0 && search(i + 3, j - 3) != 0 && search(i + 3, j - 3) != 1 && search(i - 1, j + 1) == 1 && search(i - 3, j + 3) != 0 && search(i - 3, j + 3) != 1)
			++miantwo4;
		if (search(i + 3, j - 3) == 0 && search(i + 2, j - 2) == 0 && search(i - 1, j + 1) == 0 && search(i + 4, j - 4) != 0 && search(i + 4, j - 4) != 1 && search(i + 1, j - 1) == 1 && search(i - 2, j + 2) != 0 && search(i - 2, j + 2) != 1)
			++miantwo4;
		// 6
		if (search(i - 1, j + 1) == 0 && search(i + 1, j - 1) == 0 && search(i + 3, j - 3) == 0 && search(i - 2, j + 2) != 0 && search(i - 2, j + 2) != 1 && search(i + 2, j - 2) == 1 && search(i + 4, j - 4) != 0 && search(i + 4, j - 4) != 1)
			++miantwo4;
		if (search(i + 1, j - 1) == 0 && search(i - 1, j + 1) == 0 && search(i - 3, j + 3) == 0 && search(i + 2, j - 2) != 0 && search(i + 2, j - 2) != 1 && search(i - 2, j + 2) == 1 && search(i - 4, j + 4) != 0 && search(i - 4, j + 4) != 1)
			++miantwo4;
		// 跳三
		tiaothree1 = 0;
		if (huo1 == 0)
		{
			if (lian1 == 0)
			{
				if (search(i - 2, j) == 1 && search(i - 3, j) == 1 && search(i - 4, j) != 2 && search(i - 4, j) != 1 && i != 3 && search(i - 4, j) == 0)
					++tiaothree1;
				if (search(i + 2, j) == 1 && search(i + 3, j) == 1 && search(i + 4, j) != 2 && search(i + 4, j) != 1 && i != 11 && search(i + 4, j) == 0)
					++tiaothree1;
			}
			if (lian1 == 1)
			{
				if (search(i - 1, j) == 1)
				{
					if (search(i - 3, j) == 1 && search(i - 4, j) != 2 && search(i - 4, j) != 1 && i != 3 && search(i - 4, j) == 0)
						++tiaothree1;
					if (search(i + 2, j) == 1 && search(i + 3, j) != 2 && search(i + 3, j) != 1 && i != 12 && search(i + 3, j) == 0)
						++tiaothree1;
				}
				if (search(i + 1, j) == 1)
				{
					if (search(i + 3, j) == 1 && search(i + 4, j) != 2 && search(i + 4, j) != 1 && i != 11 && search(i + 4, j) == 0)
						++tiaothree1;
					if (search(i - 2, j) == 1 && search(i - 3, j) != 2 && search(i - 3, j) != 1 && i != 2 && search(i - 3, j) == 0)
						++tiaothree1;
				}
			}
		}
		tiaothree2 = 0;
		if (huo2 == 0)
		{
			if (lian2 == 0)
			{
				if (search(i, j - 2) == 1 && search(i, j - 3) == 1 && search(i, j - 4) != 2 && search(i, j - 4) != 1 && i != 3 && search(i, j - 4) == 0)
					++tiaothree2;
				if (search(i, j + 2) == 1 && search(i, j + 3) == 1 && search(i, j + 4) != 2 && search(i, j + 4) != 1 && i != 11 && search(i, j + 4) == 0)
					++tiaothree2;
			}
			if (lian2 == 1)
			{
				if (search(i, j - 1) == 1)
				{
					if (search(i, j - 3) == 1 && search(i, j - 4) != 2 && search(i, j - 4) != 1 && i != 3 && search(i, j - 4) == 0)
						++tiaothree2;
					if (search(i, j + 2) == 1 && search(i, j + 3) != 2 && search(i, j + 3) != 1 && i != 12 && search(i, j + 3) == 0)
						++tiaothree2;
				}
				if (search(i, j + 1) == 1)
				{
					if (search(i, j + 3) == 1 && search(i, j + 4) != 2 && search(i, j + 4) != 1 && i != 11 && search(i, j + 4) == 0)
						++tiaothree2;
					if (search(i, j - 2) == 1 && search(i, j - 3) != 2 && search(i, j - 3) != 1 && i != 2 && search(i, j - 3) == 0)
						++tiaothree2;
				}
			}
		}
		tiaothree3 = 0;
		if (huo3 == 0)
		{
			if (lian3 == 0)
			{
				if (search(i - 2, j - 2) == 1 && search(i - 3, j - 3) == 1 && search(i - 4, j - 4) != 2 && search(i - 4, j - 4) != 1 && i != 3 && j != 3 && search(i - 4, j - 4) == 0)
					++tiaothree3;
				if (search(i + 2, j + 2) == 1 && search(i + 3, j + 3) == 1 && search(i + 4, j + 4) != 2 && search(i + 4, j + 4) != 1 && i != 11 && j != 11 && search(i + 4, j + 4) == 0)
					++tiaothree3;
			}
			if (lian3 == 1)
			{
				if (search(i - 1, j - 1) == 1)
				{
					if (search(i - 3, j - 3) == 1 && search(i - 4, j - 4) != 2 && search(i - 4, j - 4) != 1 && i != 3 && j != 3 && search(i - 4, j - 4) == 0)
						++tiaothree3;
					if (search(i + 2, j + 2) == 1 && search(i + 3, j + 3) != 2 && search(i + 3, j + 3) != 1 && i != 12 && j != 12 && search(i + 3, j + 3) == 0)
						++tiaothree3;
				}
				if (search(i + 1, j + 1) == 1)
				{
					if (search(i + 3, j + 3) == 1 && search(i + 4, j + 4) != 2 && search(i + 4, j + 4) != 1 && i != 11 && j != 11 && search(i + 4, j + 4) == 0)
						++tiaothree3;
					if (search(i - 2, j - 2) == 1 && search(i - 3, j - 3) != 2 && search(i - 3, j - 3) != 1 && i != 2 && j != 2 && search(i - 3, j - 3) == 0)
						++tiaothree3;
				}
			}
		}
		tiaothree4 = 0;
		if (huo4 == 0)
		{
			if (lian4 == 0)
			{
				if (search(i - 2, j + 2) == 1 && search(i - 3, j + 3) == 1 && search(i - 4, j + 4) != 2 && search(i - 4, j + 4) != 1 && i != 3 && j != 11 && search(i - 4, j + 4) == 0)
					++tiaothree4;
				if (search(i + 2, j - 2) == 1 && search(i + 3, j - 3) == 1 && search(i + 4, j - 4) != 2 && search(i + 4, j - 4) != 1 && i != 11 && j != 3 && search(i + 4, j - 4) == 0)
					++tiaothree4;
			}
			if (lian4 == 1)
			{
				if (search(i - 1, j + 1) == 1)
				{
					if (search(i - 3, j + 3) == 1 && search(i - 4, j + 4) != 2 && search(i - 4, j + 4) != 1 && i != 3 && j != 11 && search(i - 4, j + 4) == 0)
						++tiaothree4;
					if (search(i + 2, j - 2) == 1 && search(i + 3, j - 3) != 2 && search(i + 3, j - 3) != 1 && i != 12 && j != 2 && search(i + 3, j - 3) == 0)
						++tiaothree4;
				}
				if (search(i + 1, j - 1) == 1)
				{
					if (search(i + 3, j - 3) == 1 && search(i + 4, j - 4) != 2 && search(i + 4, j - 4) != 1 && i != 11 && j != 3 && search(i + 4, j - 4) == 0)
						++tiaothree4;
					if (search(i - 2, j + 2) == 1 && search(i - 3, j + 3) != 2 && search(i - 3, j + 3) != 1 && i != 2 && j != 12 && search(i - 3, j + 3) == 0)
						++tiaothree4;
				}
			}
		}
		// 假活三
		fakethree1 = 0;
		if (lian1 == 2 && huo1 == 0)
		{
			if (search(i - 1, j) == 1 && search(i + 1, j) == 1 && (search(i - 3, j) == 2 || i == 2) && (search(i + 3, j) == 2 || i == 12))
				fakethree1 = 2;
			else if (search(i - 1, j) == 1 && search(i - 2, j) == 1 && (search(i - 4, j) == 2 || i == 3) && (search(i + 2, j) == 2 || i == 13))
				fakethree1 = 2;
			else if (search(i + 1, j) == 1 && search(i + 2, j) == 1 && (search(i - 2, j) == 2 || i == 1) && (search(i + 4, j) == 2 || i == 11))
				fakethree1 = 2;
			else if (search(i - 1, j) == 1 && search(i + 1, j) == 1 && search(i - 3, j) != 1 && search(i + 3, j) != 1)
				fakethree1 = 1;
			else if (search(i + 1, j) == 1 && search(i + 2, j) == 1 && search(i - 2, j) != 1 && search(i + 4, j) != 1)
				fakethree1 = 1;
			else if (search(i - 1, j) == 1 && search(i - 2, j) == 1 && search(i + 2, j) != 1 && search(i - 4, j) != 1)
				fakethree1 = 1;
		}
		fakethree2 = 0;
		if (lian2 == 2 && huo2 == 0)
		{
			if (search(i, j - 1) == 1 && search(i, j + 1) == 1 && (search(i, j - 3) == 2 || j == 2) && (search(i, j + 3) == 2 || j == 12))
				fakethree2 = 2;
			else if (search(i, j - 1) == 1 && search(i, j - 2) == 1 && (search(i, j - 4) == 2 || j == 3) && (search(i, j + 2) == 2 || j == 13))
				fakethree2 = 2;
			else if (search(i, j + 1) == 1 && search(i, j + 2) == 1 && (search(i, j - 2) == 2 || j == 1) && (search(i, j + 4) == 2 || j == 11))
				fakethree2 = 2;
			else if (search(i, j - 1) == 1 && search(i, j + 1) == 1 && search(i, j - 3) != 1 && search(i, j + 3) != 1)
				fakethree2 = 1;
			else if (search(i, j + 1) == 1 && search(i, j + 2) == 1 && search(i, j - 2) != 1 && search(i, j + 4) != 1)
				fakethree2 = 1;
			else if (search(i, j - 1) == 1 && search(i, j - 2) == 1 && search(i, j + 2) != 1 && search(i, j - 4) != 1)
				fakethree2 = 1;
		}
		fakethree3 = 0;
		if (lian3 == 2 && huo3 == 0)
		{
			if (search(i - 1, j - 1) == 1 && search(i + 1, j + 1) == 1 && (search(i - 3, j - 3) == 2 || i == 2 || j == 2) && (search(i + 3, j + 3) == 2 || i == 12 || j == 12))
				fakethree3 = 2;
			else if (search(i - 1, j - 1) == 1 && search(i - 2, j - 2) == 1 && (search(i - 4, j - 4) == 2 || i == 3 || j == 3) && (search(i + 2, j + 2) == 2 || i == 13 || j == 13))
				fakethree3 = 2;
			else if (search(i + 1, j + 1) == 1 && search(i + 2, j + 2) == 1 && (search(i - 2, j - 2) == 2 || i == 1 || j == 1) && (search(i + 4, j + 4) == 2 || i == 11 || j == 11))
				fakethree3 = 2;
			else if (search(i - 1, j - 1) == 1 && search(i + 1, j + 1) == 1 && search(i - 3, j - 3) != 1 && search(i + 3, j + 3) != 1)
				fakethree3 = 1;
			else if (search(i + 1, j + 1) == 1 && search(i + 2, j + 2) == 1 && search(i - 2, j - 2) != 1 && search(i + 4, j + 4) != 1)
				fakethree3 = 1;
			else if (search(i - 1, j - 1) == 1 && search(i - 2, j - 2) == 1 && search(i + 2, j + 2) != 1 && search(i - 4, j - 4) != 1)
				fakethree3 = 1;
		}
		fakethree4 = 0;
		if (lian4 == 2 && huo4 == 0)
		{
			if (search(i - 1, j + 1) == 1 && search(i + 1, j - 1) == 1 && (search(i - 3, j + 3) == 2 || i == 2 || j == 12) && (search(i + 3, j - 3) == 2 || i == 12 || j == 2))
				fakethree4 = 2;
			else if (search(i - 1, j + 1) == 1 && search(i - 2, j + 2) == 1 && (search(i - 4, j + 4) == 2 || i == 3 || j == 11) && (search(i + 2, j - 2) == 2 || i == 13 || j == 1))
				fakethree4 = 2;
			else if (search(i + 1, j - 1) == 1 && search(i + 2, j - 2) == 1 && (search(i - 2, j + 2) == 2 || i == 1 || j == 13) && (search(i + 4, j - 3) == 2 || i == 11 || j == 3))
				fakethree4 = 2;
			else if (search(i - 1, j + 1) == 1 && search(i + 1, j - 1) == 1 && search(i - 3, j + 3) != 1 && search(i + 3, j - 3) != 1)
				fakethree4 = 1;
			else if (search(i + 1, j - 1) == 1 && search(i + 2, j - 2) == 1 && search(i - 2, j + 2) != 1 && search(i + 4, j - 4) != 1)
				fakethree4 = 1;
			else if (search(i - 1, j + 1) == 1 && search(i - 2, j + 2) == 1 && search(i + 2, j - 2) != 1 && search(i - 4, j + 4) != 1)
				fakethree4 = 1;
		}
		/*眠三
			1.211100
			2.211010
			3.210110
			4.11001
			5.10101
		*/
		// 竖
		mianthree1 = 0;
		// 1
		if (search(i - 1, j) != 0 && search(i - 1, j) != 1 && search(i + 1, j) == 1 && search(i + 2, j) == 1 && search(i + 3, j) == 0 && search(i + 4, j) == 0)
			++mianthree1;
		if (search(i - 2, j) != 0 && search(i - 2, j) != 1 && search(i - 1, j) == 1 && search(i + 1, j) == 1 && search(i + 2, j) == 0 && search(i + 3, j) == 0)
			++mianthree1;
		if (search(i - 3, j) != 0 && search(i - 3, j) != 1 && search(i - 2, j) == 1 && search(i - 1, j) == 1 && search(i + 1, j) == 0 && search(i + 2, j) == 0)
			++mianthree1;
		if (search(i + 3, j) != 0 && search(i + 3, j) != 1 && search(i + 2, j) == 1 && search(i + 1, j) == 1 && search(i - 1, j) == 0 && search(i - 2, j) == 0)
			++mianthree1;
		if (search(i + 1, j) != 0 && search(i + 1, j) != 1 && search(i - 1, j) == 1 && search(i - 2, j) == 1 && search(i - 3, j) == 0 && search(i - 4, j) == 0)
			++mianthree1;
		if (search(i + 2, j) != 0 && search(i + 2, j) != 1 && search(i + 1, j) == 1 && search(i - 1, j) == 1 && search(i - 2, j) == 0 && search(i - 3, j) == 0)
			++mianthree1;
		// 2
		if (search(i - 1, j) != 0 && search(i - 1, j) != 1 && search(i + 1, j) == 1 && search(i + 3, j) == 1 && search(i + 2, j) == 0 && search(i + 4, j) == 0)
			++mianthree1;
		if (search(i - 2, j) != 0 && search(i - 2, j) != 1 && search(i - 1, j) == 1 && search(i + 2, j) == 1 && search(i + 1, j) == 0 && search(i + 3, j) == 0)
			++mianthree1;
		if (search(i - 4, j) != 0 && search(i - 4, j) != 1 && search(i - 3, j) == 1 && search(i - 2, j) == 1 && search(i - 1, j) == 0 && search(i + 1, j) == 0)
			++mianthree1;
		if (search(i + 1, j) != 0 && search(i + 1, j) != 1 && search(i - 1, j) == 1 && search(i - 3, j) == 1 && search(i - 2, j) == 0 && search(i - 4, j) == 0)
			++mianthree1;
		if (search(i + 2, j) != 0 && search(i + 2, j) != 1 && search(i + 1, j) == 1 && search(i - 2, j) == 1 && search(i - 1, j) == 0 && search(i - 3, j) == 0)
			++mianthree1;
		if (search(i + 4, j) != 0 && search(i + 4, j) != 1 && search(i + 3, j) == 1 && search(i + 2, j) == 1 && search(i + 1, j) == 0 && search(i - 1, j) == 0)
			++mianthree1;
		// 3
		if (search(i - 1, j) != 0 && search(i - 1, j) != 1 && search(i + 2, j) == 1 && search(i + 3, j) == 1 && search(i + 1, j) == 0 && search(i + 4, j) == 0)
			++mianthree1;
		if (search(i - 3, j) != 0 && search(i - 3, j) != 1 && search(i - 2, j) == 1 && search(i + 1, j) == 1 && search(i - 1, j) == 0 && search(i + 2, j) == 0)
			++mianthree1;
		if (search(i - 4, j) != 0 && search(i - 4, j) != 1 && search(i - 3, j) == 1 && search(i - 1, j) == 1 && search(i - 2, j) == 0 && search(i + 1, j) == 0)
			++mianthree1;
		if (search(i + 1, j) != 0 && search(i + 1, j) != 1 && search(i - 2, j) == 1 && search(i - 3, j) == 1 && search(i - 1, j) == 0 && search(i - 4, j) == 0)
			++mianthree1;
		if (search(i + 3, j) != 0 && search(i + 3, j) != 1 && search(i + 2, j) == 1 && search(i - 1, j) == 1 && search(i + 1, j) == 0 && search(i - 2, j) == 0)
			++mianthree1;
		if (search(i + 4, j) != 0 && search(i + 4, j) != 1 && search(i + 3, j) == 1 && search(i + 1, j) == 1 && search(i + 2, j) == 0 && search(i - 1, j) == 0)
			++mianthree1;
		// 4
		if (search(i + 1, j) == 1 && search(i + 4, j) == 1 && search(i + 2, j) == 0 && search(i + 3, j) == 0)
			++mianthree1;
		if (search(i - 1, j) == 1 && search(i + 3, j) == 1 && search(i + 1, j) == 0 && search(i + 2, j) == 0)
			++mianthree1;
		if (search(i - 4, j) == 1 && search(i - 3, j) == 1 && search(i - 2, j) == 0 && search(i - 1, j) == 0)
			++mianthree1;
		if (search(i - 1, j) == 1 && search(i - 4, j) == 1 && search(i - 2, j) == 0 && search(i - 3, j) == 0)
			++mianthree1;
		if (search(i + 1, j) == 1 && search(i - 3, j) == 1 && search(i - 1, j) == 0 && search(i - 2, j) == 0)
			++mianthree1;
		if (search(i + 4, j) == 1 && search(i + 3, j) == 1 && search(i + 2, j) == 0 && search(i + 1, j) == 0)
			++mianthree1;
		// 5
		if (search(i + 2, j) == 1 && search(i + 4, j) == 1 && search(i + 1, j) == 0 && search(i + 3, j) == 0)
			++mianthree1;
		if (search(i - 2, j) == 1 && search(i + 2, j) == 1 && search(i - 1, j) == 0 && search(i + 1, j) == 0)
			++mianthree1;
		if (search(i - 4, j) == 1 && search(i - 2, j) == 1 && search(i - 1, j) == 0 && search(i - 3, j) == 0)
			++mianthree1;
		// 横
		mianthree2 = 0;
		// 1
		if (search(i, j - 1) != 0 && search(i, j - 1) != 1 && search(i, j + 1) == 1 && search(i, j + 2) == 1 && search(i, j + 3) == 0 && search(i, j + 4) == 0)
			++mianthree2;
		if (search(i, j - 2) != 0 && search(i, j - 2) != 1 && search(i, j - 1) == 1 && search(i, j + 1) == 1 && search(i, j + 2) == 0 && search(i, j + 3) == 0)
			++mianthree2;
		if (search(i, j - 3) != 0 && search(i, j - 3) != 1 && search(i, j - 2) == 1 && search(i, j - 1) == 1 && search(i, j + 1) == 0 && search(i, j + 2) == 0)
			++mianthree2;
		if (search(i, j + 3) != 0 && search(i, j + 3) != 1 && search(i, j + 2) == 1 && search(i, j + 1) == 1 && search(i, j - 1) == 0 && search(i, j - 2) == 0)
			++mianthree2;
		if (search(i, j + 1) != 0 && search(i, j + 1) != 1 && search(i, j - 1) == 1 && search(i, j - 2) == 1 && search(i, j - 3) == 0 && search(i, j - 4) == 0)
			++mianthree2;
		if (search(i, j + 2) != 0 && search(i, j + 2) != 1 && search(i, j + 1) == 1 && search(i, j - 1) == 1 && search(i, j - 2) == 0 && search(i, j - 3) == 0)
			++mianthree2;
		// 2
		if (search(i, j - 1) != 0 && search(i, j - 1) != 1 && search(i, j + 1) == 1 && search(i, j + 3) == 1 && search(i, j + 2) == 0 && search(i, j + 4) == 0)
			++mianthree2;
		if (search(i, j - 2) != 0 && search(i, j - 2) != 1 && search(i, j - 1) == 1 && search(i, j + 2) == 1 && search(i, j + 1) == 0 && search(i, j + 3) == 0)
			++mianthree2;
		if (search(i, j - 4) != 0 && search(i, j - 4) != 1 && search(i, j - 3) == 1 && search(i, j - 2) == 1 && search(i, j - 1) == 0 && search(i, j + 1) == 0)
			++mianthree2;
		if (search(i, j + 1) != 0 && search(i, j + 1) != 1 && search(i, j - 1) == 1 && search(i, j - 3) == 1 && search(i, j - 2) == 0 && search(i, j - 4) == 0)
			++mianthree2;
		if (search(i, j + 2) != 0 && search(i, j + 2) != 1 && search(i, j + 1) == 1 && search(i, j - 2) == 1 && search(i, j - 1) == 0 && search(i, j - 3) == 0)
			++mianthree2;
		if (search(i, j + 4) != 0 && search(i, j + 4) != 1 && search(i, j + 3) == 1 && search(i, j + 2) == 1 && search(i, j + 1) == 0 && search(i, j - 1) == 0)
			++mianthree2;
		// 3
		if (search(i, j - 1) != 0 && search(i, j - 1) != 1 && search(i, j + 2) == 1 && search(i, j + 3) == 1 && search(i, j + 1) == 0 && search(i, j + 4) == 0)
			++mianthree2;
		if (search(i, j - 3) != 0 && search(i, j - 3) != 1 && search(i, j - 2) == 1 && search(i, j + 1) == 1 && search(i, j - 1) == 0 && search(i, j + 2) == 0)
			++mianthree2;
		if (search(i, j - 4) != 0 && search(i, j - 4) != 1 && search(i, j - 3) == 1 && search(i, j - 1) == 1 && search(i, j - 2) == 0 && search(i, j + 1) == 0)
			++mianthree2;
		if (search(i, j + 1) != 0 && search(i, j + 1) != 1 && search(i, j - 2) == 1 && search(i, j - 3) == 1 && search(i, j - 1) == 0 && search(i, j - 4) == 0)
			++mianthree2;
		if (search(i, j + 3) != 0 && search(i, j + 3) != 1 && search(i, j + 2) == 1 && search(i, j - 1) == 1 && search(i, j + 1) == 0 && search(i, j - 2) == 0)
			++mianthree2;
		if (search(i, j + 4) != 0 && search(i, j + 4) != 1 && search(i, j + 3) == 1 && search(i, j + 1) == 1 && search(i, j + 2) == 0 && search(i, j - 1) == 0)
			++mianthree2;
		// 4
		if (search(i, j + 1) == 1 && search(i, j + 4) == 1 && search(i, j + 2) == 0 && search(i, j + 3) == 0)
			++mianthree2;
		if (search(i, j - 1) == 1 && search(i, j + 3) == 1 && search(i, j + 1) == 0 && search(i, j + 2) == 0)
			++mianthree2;
		if (search(i, j - 4) == 1 && search(i, j - 3) == 1 && search(i, j - 2) == 0 && search(i, j - 1) == 0)
			++mianthree2;
		if (search(i, j - 1) == 1 && search(i, j - 4) == 1 && search(i - 2, j) == 0 && search(i, j - 3) == 0)
			++mianthree2;
		if (search(i, j + 1) == 1 && search(i, j - 3) == 1 && search(i, j - 1) == 0 && search(i, j - 2) == 0)
			++mianthree2;
		if (search(i, j + 4) == 1 && search(i, j + 3) == 1 && search(i, j + 2) == 0 && search(i, j + 1) == 0)
			++mianthree2;
		// 5
		if (search(i, j + 2) == 1 && search(i, j + 4) == 1 && search(i, j + 1) == 0 && search(i, j + 3) == 0)
			++mianthree2;
		if (search(i, j - 2) == 1 && search(i, j + 2) == 1 && search(i, j - 1) == 0 && search(i, j + 1) == 0)
			++mianthree2;
		if (search(i, j - 4) == 1 && search(i, j - 2) == 1 && search(i, j - 1) == 0 && search(i, j - 3) == 0)
			++mianthree2;
		// 斜1
		mianthree3 = 0;
		// 1
		if (search(i - 1, j - 1) != 0 && search(i - 1, j - 1) != 1 && search(i + 1, j + 1) == 1 && search(i + 2, j + 2) == 1 && search(i + 3, j + 3) == 0 && search(i + 4, j + 4) == 0)
			++mianthree3;
		if (search(i - 2, j - 2) != 0 && search(i - 2, j - 2) != 1 && search(i - 1, j - 1) == 1 && search(i + 1, j + 1) == 1 && search(i + 2, j + 2) == 0 && search(i + 3, j + 3) == 0)
			++mianthree3;
		if (search(i - 3, j - 3) != 0 && search(i - 3, j - 3) != 1 && search(i - 2, j - 2) == 1 && search(i - 1, j - 1) == 1 && search(i + 1, j + 1) == 0 && search(i + 2, j + 2) == 0)
			++mianthree3;
		if (search(i + 3, j + 3) != 0 && search(i + 3, j + 3) != 1 && search(i + 2, j + 2) == 1 && search(i + 1, j + 1) == 1 && search(i - 1, j - 1) == 0 && search(i - 2, j - 2) == 0)
			++mianthree3;
		if (search(i + 1, j + 1) != 0 && search(i + 1, j + 1) != 1 && search(i - 1, j - 1) == 1 && search(i - 2, j - 2) == 1 && search(i - 3, j - 3) == 0 && search(i - 4, j - 4) == 0)
			++mianthree3;
		if (search(i + 2, j + 2) != 0 && search(i + 2, j + 2) != 1 && search(i + 1, j + 1) == 1 && search(i - 1, j - 1) == 1 && search(i - 2, j - 2) == 0 && search(i - 3, j - 3) == 0)
			++mianthree3;
		// 2
		if (search(i - 1, j - 1) != 0 && search(i - 1, j - 1) != 1 && search(i + 1, j + 1) == 1 && search(i + 3, j + 3) == 1 && search(i + 2, j + 2) == 0 && search(i + 4, j + 4) == 0)
			++mianthree3;
		if (search(i - 2, j - 2) != 0 && search(i - 2, j - 2) != 1 && search(i - 1, j - 1) == 1 && search(i + 2, j + 2) == 1 && search(i + 1, j + 1) == 0 && search(i + 3, j + 3) == 0)
			++mianthree3;
		if (search(i - 4, j - 4) != 0 && search(i - 4, j - 4) != 1 && search(i - 3, j - 3) == 1 && search(i - 2, j - 2) == 1 && search(i - 1, j - 1) == 0 && search(i + 1, j + 1) == 0)
			++mianthree3;
		if (search(i + 1, j + 1) != 0 && search(i + 1, j + 1) != 1 && search(i - 1, j + 1) == 1 && search(i - 3, j - 3) == 1 && search(i - 2, j - 2) == 0 && search(i - 4, j - 4) == 0)
			++mianthree3;
		if (search(i + 2, j + 2) != 0 && search(i + 2, j + 2) != 1 && search(i + 1, j + 1) == 1 && search(i - 2, j - 2) == 1 && search(i - 1, j - 1) == 0 && search(i - 3, j - 3) == 0)
			++mianthree3;
		if (search(i + 4, j + 4) != 0 && search(i + 4, j + 4) != 1 && search(i + 3, j + 3) == 1 && search(i + 2, j + 2) == 1 && search(i + 1, j + 1) == 0 && search(i - 1, j - 1) == 0)
			++mianthree3;
		// 3
		if (search(i - 1, j - 1) != 0 && search(i - 1, j - 1) != 1 && search(i + 2, j + 2) == 1 && search(i + 3, j + 3) == 1 && search(i + 1, j + 1) == 0 && search(i + 4, j + 4) == 0)
			++mianthree3;
		if (search(i - 3, j - 3) != 0 && search(i - 3, j - 3) != 1 && search(i - 2, j - 3) == 1 && search(i + 1, j + 1) == 1 && search(i - 1, j - 1) == 0 && search(i + 2, j + 2) == 0)
			++mianthree3;
		if (search(i - 4, j - 4) != 0 && search(i - 4, j - 4) != 1 && search(i - 3, j - 3) == 1 && search(i - 1, j - 1) == 1 && search(i - 2, j - 2) == 0 && search(i + 1, j + 1) == 0)
			++mianthree3;
		if (search(i + 1, j + 1) != 0 && search(i + 1, j + 1) != 1 && search(i - 2, j - 2) == 1 && search(i - 3, j - 3) == 1 && search(i - 1, j - 1) == 0 && search(i - 4, j - 4) == 0)
			++mianthree3;
		if (search(i + 3, j + 3) != 0 && search(i + 3, j + 3) != 1 && search(i + 2, j + 2) == 1 && search(i - 1, j - 1) == 1 && search(i + 1, j + 1) == 0 && search(i - 2, j - 2) == 0)
			++mianthree3;
		if (search(i + 4, j + 4) != 0 && search(i + 4, j + 4) != 1 && search(i + 3, j + 3) == 1 && search(i + 1, j + 1) == 1 && search(i + 2, j + 2) == 0 && search(i - 1, j - 1) == 0)
			++mianthree3;
		// 4
		if (search(i + 1, j + 1) == 1 && search(i + 4, j + 4) == 1 && search(i + 2, j + 2) == 0 && search(i + 3, j + 3) == 0)
			++mianthree3;
		if (search(i - 1, j - 1) == 1 && search(i + 3, j + 3) == 1 && search(i + 1, j + 1) == 0 && search(i + 2, j + 2) == 0)
			++mianthree3;
		if (search(i - 4, j - 4) == 1 && search(i - 3, j - 3) == 1 && search(i - 2, j - 2) == 0 && search(i - 1, j - 1) == 0)
			++mianthree3;
		if (search(i - 1, j - 1) == 1 && search(i - 4, j - 4) == 1 && search(i - 2, j - 2) == 0 && search(i - 3, j - 3) == 0)
			++mianthree3;
		if (search(i + 1, j + 1) == 1 && search(i - 3, j - 3) == 1 && search(i - 1, j - 1) == 0 && search(i - 2, j - 2) == 0)
			++mianthree3;
		if (search(i + 4, j + 4) == 1 && search(i + 3, j + 3) == 1 && search(i + 2, j + 2) == 0 && search(i + 1, j + 1) == 0)
			++mianthree3;
		// 5
		if (search(i + 2, j + 2) == 1 && search(i + 4, j + 4) == 1 && search(i + 1, j + 1) == 0 && search(i + 3, j + 3) == 0)
			++mianthree3;
		if (search(i - 2, j - 2) == 1 && search(i + 2, j + 2) == 1 && search(i - 1, j - 1) == 0 && search(i + 1, j + 1) == 0)
			++mianthree3;
		if (search(i - 4, j - 4) == 1 && search(i - 2, j - 2) == 1 && search(i - 1, j - 1) == 0 && search(i - 3, j - 3) == 0)
			++mianthree3;
		// 斜2
		mianthree4 = 0;
		// 1
		if (search(i - 1, j + 1) != 0 && search(i - 1, j + 1) != 1 && search(i + 1, j - 1) == 1 && search(i + 2, j - 2) == 1 && search(i + 3, j - 3) == 0 && search(i + 4, j - 4) == 0)
			++mianthree4;
		if (search(i - 2, j + 2) != 0 && search(i - 2, j + 2) != 1 && search(i - 1, j + 1) == 1 && search(i + 1, j - 1) == 1 && search(i + 2, j - 2) == 0 && search(i + 3, j - 3) == 0)
			++mianthree4;
		if (search(i - 3, j + 3) != 0 && search(i - 3, j + 3) != 1 && search(i - 2, j + 2) == 1 && search(i - 1, j + 1) == 1 && search(i + 1, j - 1) == 0 && search(i + 2, j - 2) == 0)
			++mianthree4;
		if (search(i + 3, j - 3) != 0 && search(i + 3, j - 3) != 1 && search(i + 2, j - 2) == 1 && search(i + 1, j - 1) == 1 && search(i - 1, j + 1) == 0 && search(i - 2, j + 2) == 0)
			++mianthree4;
		if (search(i + 1, j - 1) != 0 && search(i + 1, j - 1) != 1 && search(i - 1, j + 1) == 1 && search(i - 2, j + 2) == 1 && search(i - 3, j + 3) == 0 && search(i - 4, j + 4) == 0)
			++mianthree4;
		if (search(i + 2, j - 2) != 0 && search(i + 2, j - 2) != 1 && search(i + 1, j - 1) == 1 && search(i - 1, j + 1) == 1 && search(i - 2, j + 2) == 0 && search(i - 3, j + 3) == 0)
			++mianthree4;
		// 2
		if (search(i - 1, j + 1) != 0 && search(i - 1, j + 1) != 1 && search(i + 1, j - 1) == 1 && search(i + 3, j - 3) == 1 && search(i + 2, j - 2) == 0 && search(i + 4, j - 4) == 0)
			++mianthree4;
		if (search(i - 2, j + 2) != 0 && search(i - 2, j + 2) != 1 && search(i - 1, j + 1) == 1 && search(i + 2, j - 2) == 1 && search(i + 1, j - 1) == 0 && search(i + 3, j - 3) == 0)
			++mianthree4;
		if (search(i - 4, j + 4) != 0 && search(i - 4, j + 4) != 1 && search(i - 3, j + 3) == 1 && search(i - 2, j + 2) == 1 && search(i - 1, j + 1) == 0 && search(i + 1, j - 1) == 0)
			++mianthree4;
		if (search(i + 1, j - 1) != 0 && search(i + 1, j - 1) != 1 && search(i - 1, j + 1) == 1 && search(i - 3, j + 3) == 1 && search(i - 2, j + 2) == 0 && search(i - 4, j + 4) == 0)
			++mianthree4;
		if (search(i + 2, j - 2) != 0 && search(i + 2, j - 2) != 1 && search(i + 1, j - 1) == 1 && search(i - 2, j + 2) == 1 && search(i - 1, j + 1) == 0 && search(i - 3, j + 3) == 0)
			++mianthree4;
		if (search(i + 4, j - 4) != 0 && search(i + 4, j - 4) != 1 && search(i + 3, j - 3) == 1 && search(i + 2, j - 2) == 1 && search(i + 1, j - 1) == 0 && search(i - 1, j + 1) == 0)
			++mianthree4;
		// 3
		if (search(i - 1, j + 1) != 0 && search(i - 1, j + 1) != 1 && search(i + 2, j - 2) == 1 && search(i + 3, j - 3) == 1 && search(i + 1, j - 1) == 0 && search(i + 4, j - 4) == 0)
			++mianthree4;
		if (search(i - 3, j + 3) != 0 && search(i - 3, j + 3) != 1 && search(i - 2, j + 3) == 1 && search(i + 1, j - 1) == 1 && search(i - 1, j + 1) == 0 && search(i + 2, j - 2) == 0)
			++mianthree4;
		if (search(i - 4, j + 4) != 0 && search(i - 4, j + 4) != 1 && search(i - 3, j + 3) == 1 && search(i - 1, j + 1) == 1 && search(i - 2, j + 2) == 0 && search(i + 1, j - 1) == 0)
			++mianthree4;
		if (search(i + 1, j - 1) != 0 && search(i + 1, j - 1) != 1 && search(i - 2, j + 2) == 1 && search(i - 3, j + 3) == 1 && search(i - 1, j + 1) == 0 && search(i - 4, j + 4) == 0)
			++mianthree4;
		if (search(i + 3, j - 3) != 0 && search(i + 3, j - 3) != 1 && search(i + 2, j - 2) == 1 && search(i - 1, j + 1) == 1 && search(i + 1, j - 1) == 0 && search(i - 2, j + 2) == 0)
			++mianthree4;
		if (search(i - 4, j - 4) != 0 && search(i + 4, j - 4) != 1 && search(i + 3, j - 3) == 1 && search(i + 1, j - 1) == 1 && search(i + 2, j - 2) == 0 && search(i - 1, j + 1) == 0)
			++mianthree4;
		// 4
		if (search(i + 1, j - 1) == 1 && search(i + 4, j - 4) == 1 && search(i + 2, j - 2) == 0 && search(i + 3, j - 3) == 0)
			++mianthree4;
		if (search(i - 1, j + 1) == 1 && search(i + 3, j - 3) == 1 && search(i + 1, j - 1) == 0 && search(i + 2, j - 2) == 0)
			++mianthree4;
		if (search(i - 4, j + 4) == 1 && search(i - 3, j + 3) == 1 && search(i - 2, j + 2) == 0 && search(i - 1, j + 1) == 0)
			++mianthree4;
		if (search(i - 1, j + 1) == 1 && search(i - 4, j + 4) == 1 && search(i - 2, j + 2) == 0 && search(i - 3, j + 3) == 0)
			++mianthree4;
		if (search(i + 1, j - 1) == 1 && search(i - 3, j + 3) == 1 && search(i - 1, j + 1) == 0 && search(i - 2, j + 2) == 0)
			++mianthree4;
		if (search(i + 4, j - 4) == 1 && search(i + 3, j - 3) == 1 && search(i + 2, j - 2) == 0 && search(i + 1, j - 1) == 0)
			++mianthree4;
		// 5
		if (search(i + 2, j - 2) == 1 && search(i + 4, j - 4) == 1 && search(i + 1, j - 1) == 0 && search(i + 3, j - 3) == 0)
			++mianthree4;
		if (search(i - 2, j + 2) == 1 && search(i + 2, j - 2) == 1 && search(i - 1, j + 1) == 0 && search(i + 1, j - 1) == 0)
			++mianthree4;
		if (search(i - 4, j + 4) == 1 && search(i - 2, j + 2) == 1 && search(i - 1, j + 1) == 0 && search(i - 3, j + 3) == 0)
			++mianthree4;
		// 跳4
		tiaofour = 0;
		// 竖
		tiaofour1 = 0;
		if (lian1 == 0)
		{
			if (search(i - 1, j) != 2 && search(i - 2, j) == 1 && search(i - 3, j) == 1 && search(i - 4, j) == 1 && search(i - 5, j) != 1)
				if (search(i - 1, j) == 0)
					++tiaofour1;
			if (search(i + 1, j) != 2 && search(i + 2, j) == 1 && search(i + 3, j) == 1 && search(i + 4, j) == 1 && search(i + 5, j) != 1)
				if (search(i + 1, j) == 0)
					++tiaofour1;
		}
		if (lian1 == 1)
		{
			if (search(i + 1, j) == 1)
			{
				if (search(i + 2, j) != 2 && search(i + 3, j) == 1 && search(i + 4, j) == 1 && search(i + 5, j) != 1)
					if (search(i + 2, j) == 0)
						++tiaofour1;
				if (search(i - 1, j) != 2 && search(i - 2, j) == 1 && search(i - 3, j) == 1 && search(i - 4, j) != 1)
					if (search(i - 1, j) == 0)
						++tiaofour1;
			}
			if (search(i - 1, j) == 1)
			{
				if (search(i - 2, j) != 2 && search(i - 3, j) == 1 && search(i - 4, j) == 1 && search(i - 5, j) != 1)
					if (search(i - 2, j) == 0)
						++tiaofour1;
				if (search(i + 1, j) != 2 && search(i + 2, j) == 1 && search(i + 3, j) == 1 && search(i + 4, j) != 1)
					if (search(i + 1, j) == 0)
						++tiaofour1;
			}
		}
		if (lian1 == 2)
		{
			if (search(i + 1, j) == 1 && search(i + 2, j) == 1 && search(i + 3, j) != 2 && search(i + 4, j) == 1 && search(i + 5, j) != 1)
				if (search(i + 3, j) == 0)
					++tiaofour1;
			if (search(i + 1, j) == 1 && search(i - 1, j) == 1 && search(i - 2, j) != 2 && search(i - 3, j) == 1 && search(i - 4, j) != 1)
				if (search(i + 2, j) == 0)
					++tiaofour1;
			if (search(i - 1, j) == 1 && search(i + 1, j) == 1 && search(i + 2, j) != 2 && search(i + 3, j) == 1 && search(i + 4, j) != 1)
				if (search(i - 2, j) == 0)
					++tiaofour1;
			if (search(i - 1, j) == 1 && search(i - 2, j) == 1 && search(i - 3, j) != 2 && search(i - 4, j) == 1 && search(i - 5, j) != 1)
				if (search(i - 3, j) == 0)
					++tiaofour1;
			if (search(i - 1, j) == 1 && search(i - 2, j) == 1 && search(i + 1, j) != 2 && search(i + 2, j) == 1 && search(i + 3, j) != 1)
				if (search(i + 1, j) == 0)
					++tiaofour1;
			if (search(i + 1, j) == 1 && search(i + 2, j) == 1 && search(i - 1, j) != 2 && search(i - 2, j) == 1 && search(i - 3, j) != 1)
				if (search(i - 1, j) == 0)
					++tiaofour1;
		}
		// 横
		tiaofour2 = 0;
		if (lian2 == 0)
		{
			if (search(i, j - 1) != 2 && search(i, j - 2) == 1 && search(i, j - 3) == 1 && search(i, j - 4) == 1 && search(i, j - 5) != 1)
				if (search(i, j - 1) == 0)
					++tiaofour2;
			if (search(i, j + 1) != 2 && search(i, j + 2) == 1 && search(i, j + 3) == 1 && search(i, j + 4) == 1 && search(i, j + 5) != 1)
				if (search(i, j + 1) == 0)
					++tiaofour2;
		}
		if (lian2 == 1)
		{
			if (search(i, j + 1) == 1)
			{
				if (search(i, j + 2) != 2 && search(i, j + 3) == 1 && search(i, j + 4) == 1 && search(i, j + 5) != 1)
					if (search(i, j + 2) == 0)
						++tiaofour2;
				if (search(i, j - 1) != 2 && search(i, j - 2) == 1 && search(i, j - 3) == 1 && search(i, j - 4) != 1)
					if (search(i, j - 1) == 0)
						++tiaofour2;
			}
			if (search(i, j - 1) == 1)
			{
				if (search(i, j - 2) != 2 && search(i, j - 3) == 1 && search(i, j - 4) == 1 && search(i, j - 5) != 1)
					if (search(i, j - 2) == 0)
						++tiaofour2;
				if (search(i, j + 1) != 2 && search(i, j + 2) == 1 && search(i, j + 3) == 1 && search(i, j + 4) != 1)
					if (search(i, j + 1) == 0)
						++tiaofour2;
			}
		}
		if (lian2 == 2)
		{
			if (search(i, j + 1) == 1 && search(i, j + 2) == 1 && search(i, j + 3) != 2 && search(i, j + 4) == 1 && search(i, j + 5) != 1)
				if (search(i, j + 3) == 0)
					++tiaofour2;
			if (search(i, j + 1) == 1 && search(i, j - 1) == 1 && search(i, j + 2) != 2 && search(i, j + 3) == 1 && search(i, j + 4) != 1)
				if (search(i, j + 2) == 0)
					++tiaofour2;
			if (search(i, j - 1) == 1 && search(i, j + 1) == 1 && search(i, j - 2) != 2 && search(i, j - 3) == 1 && search(i, j - 4) != 1)
				if (search(i, j - 2) == 0)
					++tiaofour2;
			if (search(i, j - 1) == 1 && search(i, j - 2) == 1 && search(i, j - 3) != 2 && search(i, j - 4) == 1 && search(i, j - 5) != 1)
				if (search(i, j - 3) == 0)
					++tiaofour2;
			if (search(i, j - 1) == 1 && search(i, j - 2) == 1 && search(i, j + 1) != 2 && search(i, j + 2) == 1 && search(i, j + 3) != 1)
				if (search(i, j + 1) == 0)
					++tiaofour2;
			if (search(i, j + 1) == 1 && search(i, j + 2) == 1 && search(i, j - 1) != 2 && search(i, j - 2) == 1 && search(i, j - 3) != 1)
				if (search(i, j - 1) == 0)
					++tiaofour2;
		}
		// 斜1
		tiaofour3 = 0;
		if (lian3 == 0)
		{
			if (search(i - 1, j - 1) != 2 && search(i - 2, j - 2) == 1 && search(i - 3, j - 3) == 1 && search(i - 4, j - 4) == 1 && search(i - 5, j - 5) != 1)
				if (search(i - 1, j - 1) == 0)
					++tiaofour3;
			if (search(i + 1, j + 1) != 2 && search(i + 2, j + 2) == 1 && search(i + 3, j + 3) == 1 && search(i + 4, j + 4) == 1 && search(i + 5, j + 5) != 1)
				if (search(i + 1, j + 1) == 0)
					++tiaofour3;
		}
		if (lian3 == 1)
		{
			if (search(i + 1, j + 1) == 1)
			{
				if (search(i + 2, j + 2) != 2 && search(i + 3, j + 3) == 1 && search(i + 4, j + 4) == 1 && search(i + 5, j + 5) != 1)
					if (search(i + 2, j + 2) == 0)
						++tiaofour3;
				if (search(i - 1, j - 1) != 2 && search(i - 2, j - 2) == 1 && search(i - 3, j - 3) == 1 && search(i - 4, j - 4) != 1)
					if (search(i - 1, j - 1) == 0)
						++tiaofour3;
			}
			if (search(i - 1, j - 1) == 1)
			{
				if (search(i - 2, j - 2) != 2 && search(i - 3, j - 3) == 1 && search(i - 4, j - 4) == 1 && search(i - 5, j - 5) != 1)
					if (search(i - 2, j - 2) == 0)
						++tiaofour3;
				if (search(i + 1, j + 1) != 2 && search(i + 2, j + 2) == 1 && search(i + 3, j + 3) == 1 && search(i + 4, j + 4) != 1)
					if (search(i + 1, j + 1) == 0)
						++tiaofour3;
			}
		}
		if (lian3 == 2)
		{
			if (search(i + 1, j + 1) == 1 && search(i + 2, j + 2) == 1 && search(i + 3, j + 3) != 2 && search(i + 4, j + 4) == 1 && search(i + 5, j + 5) != 1)
				if (search(i + 3, j + 3) == 0)
					++tiaofour3;
			if (search(i + 1, j + 1) == 1 && search(i - 1, j - 1) == 1 && search(i - 2, j - 2) != 2 && search(i - 3, j - 3) == 1 && search(i - 4, j - 4) != 1)
				if (search(i - 2, j - 2) == 0)
					++tiaofour3;
			if (search(i - 1, j - 1) == 1 && search(i + 1, j + 1) == 1 && search(i + 2, j + 2) != 2 && search(i + 3, j + 3) == 1 && search(i + 4, j + 4) != 1)
				if (search(i + 2, j + 2) == 0)
					++tiaofour3;
			if (search(i - 1, j - 1) == 1 && search(i - 2, j - 2) == 1 && search(i - 3, j - 3) != 2 && search(i - 4, j - 4) == 1 && search(i - 5, j - 5) != 1)
				if (search(i - 3, j - 3) == 0)
					++tiaofour3;
			if (search(i - 1, j - 1) == 1 && search(i - 2, j - 2) == 1 && search(i + 1, j + 1) != 2 && search(i + 2, j + 2) == 1 && search(i + 3, j + 3) != 1)
				if (search(i + 1, j + 1) == 0)
					++tiaofour3;
			if (search(i + 1, j + 1) == 1 && search(i + 2, j + 2) == 1 && search(i - 1, j - 1) != 2 && search(i - 2, j - 2) == 1 && search(i - 3, j - 3) != 1)
				if (search(i - 1, j - 1) == 0)
					++tiaofour3;
		}
		// 斜2
		tiaofour4 = 0;
		if (lian4 == 0)
		{
			if (search(i + 1, j - 1) != 2 && search(i + 2, j - 2) == 1 && search(i + 3, j - 3) == 1 && search(i + 4, j - 4) == 1 && search(i + 5, j - 5) != 1)
				if (search(i + 1, j - 1) == 0)
					++tiaofour4;
			if (search(i - 1, j + 1) != 2 && search(i - 2, j + 2) == 1 && search(i - 3, j + 3) == 1 && search(i - 4, j + 4) == 1 && search(i - 5, j + 5) != 1)
				if (search(i - 1, j + 1) == 0)
					++tiaofour4;
		}
		if (lian4 == 1)
		{
			if (search(i - 1, j + 1) == 1)
			{
				if (search(i - 2, j + 2) != 2 && search(i - 3, j + 3) == 1 && search(i - 4, j + 4) == 1 && search(i - 5, j + 5) != 1)
					if (search(i - 2, j + 2) == 0)
						++tiaofour4;
				if (search(i + 1, j - 1) != 2 && search(i + 2, j - 2) == 1 && search(i + 3, j - 3) == 1 && search(i + 4, j - 4) != 1)
					if (search(i + 1, j - 1) == 0)
						++tiaofour4;
			}
			if (search(i + 1, j - 1) == 1)
			{
				if (search(i + 2, j - 2) != 2 && search(i + 3, j - 3) == 1 && search(i + 4, j - 4) == 1 && search(i + 5, j - 5) != 1)
					if (search(i + 2, j - 2) == 0)
						++tiaofour4;
				if (search(i - 1, j + 1) != 2 && search(i - 2, j + 2) == 1 && search(i - 3, j + 3) == 1 && search(i - 4, j + 4) != 1)
					if (search(i - 1, j + 1) == 0)
						++tiaofour4;
			}
		}
		if (lian4 == 2)
		{
			if (search(i + 1, j - 1) == 1 && search(i + 2, j - 2) == 1 && search(i + 3, j - 3) != 2 && search(i + 4, j - 4) == 1 && search(i + 5, j - 5) != 1)
				if (search(i + 3, j - 3) == 0)
					++tiaofour4;
			if (search(i + 1, j - 1) == 1 && search(i - 1, j + 1) == 1 && search(i - 2, j + 2) != 2 && search(i - 3, j + 3) == 1 && search(i - 4, j + 4) != 1)
				if (search(i - 2, j + 2) == 0)
					++tiaofour4;
			if (search(i - 1, j + 1) == 1 && search(i + 1, j - 1) == 1 && search(i + 2, j - 2) != 2 && search(i + 3, j - 3) == 1 && search(i + 4, j - 4) != 1)
				if (search(i + 2, j - 2) == 0)
					++tiaofour4;
			if (search(i - 1, j + 1) == 1 && search(i - 2, j + 2) == 1 && search(i - 3, j + 3) != 2 && search(i - 4, j + 4) == 1 && search(i - 5, j + 5) != 1)
				if (search(i - 3, j + 3) == 0)
					++tiaofour4;
			if (search(i - 1, j + 1) == 1 && search(i - 2, j + 2) == 1 && search(i + 1, j - 1) != 2 && search(i + 2, j - 2) == 1 && search(i + 3, j - 3) != 1)
				if (search(i + 1, j - 1) == 0)
					++tiaofour4;
			if (search(i + 1, j - 1) == 1 && search(i + 2, j - 2) == 1 && search(i - 1, j + 1) != 2 && search(i - 2, j + 2) == 1 && search(i - 3, j + 3) != 1)
				if (search(i - 1, j + 1) == 0)
					++tiaofour4;
		}
		tiaofour = tiaofour1 + tiaofour2 + tiaofour3 + tiaofour4; // 计算各个方向的和
		// 计算分数
		// 五连
		if (lian1 == 4)
			value += WULIAN;
		if (lian2 == 4)
			value += WULIAN;
		if (lian3 == 4)
			value += WULIAN;
		if (lian4 == 4)
			value += WULIAN;
		// 活四
		if (lian1 == 3 && huo1 == 0)
			value += HUOSI;
		if (lian2 == 3 && huo2 == 0)
			value += HUOSI;
		if (lian3 == 3 && huo3 == 0)
			value += HUOSI;
		if (lian4 == 3 && huo4 == 0)
			value += HUOSI;
		// 连四
		if (lian1 == 3 && huo1 == 1)
			value += LIANSI;
		if (lian2 == 3 && huo2 == 1)
			value += LIANSI;
		if (lian3 == 3 && huo3 == 1)
			value += LIANSI;
		if (lian4 == 3 && huo4 == 1)
			value += LIANSI;
		// 跳四
		value += tiaofour * TIAOSI;
		// 活三
		if (lian1 == 2 && fakethree1 == 1)
			value += LIANHUOSAN;
		if (lian2 == 2 && fakethree2 == 1)
			value += LIANHUOSAN;
		if (lian3 == 2 && fakethree3 == 1)
			value += LIANHUOSAN;
		if (lian4 == 2 && fakethree4 == 1)
			value += LIANHUOSAN;
		// 假活三
		if (lian1 == 2 && fakethree1 == 2)
			value += JIAHUOSAN;
		if (lian2 == 2 && fakethree2 == 2)
			value += JIAHUOSAN;
		if (lian3 == 2 && fakethree3 == 2)
			value += JIAHUOSAN;
		if (lian4 == 2 && fakethree4 == 2)
			value += JIAHUOSAN;
		// 跳三
		if (tiaothree1 > 0)
			value += TIAOHUOSAN;
		if (tiaothree2 > 0)
			value += TIAOHUOSAN;
		if (tiaothree3 > 0)
			value += TIAOHUOSAN;
		if (tiaothree4 > 0)
			value += TIAOHUOSAN;
		// 冲三
		if (mianthree1 > 0)
			value += mianthree1 * MIANSAN;
		if (mianthree2 > 0)
			value += mianthree2 * MIANSAN;
		if (mianthree3 > 0)
			value += mianthree3 * MIANSAN;
		if (mianthree4 > 0)
			value += mianthree4 * MIANSAN;
		// 活二
		if (huotwo1 > 0)
			value += huotwo1 * HUOER;
		if (huotwo2 > 0)
			value += huotwo2 * HUOER;
		if (huotwo3 > 0)
			value += huotwo3 * HUOER;
		if (huotwo4 > 0)
			value += huotwo4 * HUOER;
		// 冲二
		if (miantwo1 > 0)
			value += miantwo1 * MIANER;
		if (miantwo2 > 0)
			value += miantwo2 * MIANER;
		if (miantwo3 > 0)
			value += miantwo3 * MIANER;
		if (miantwo4 > 0)
			value += miantwo4 * MIANER;
		return value; // 返回分数
	}
	if (n == 2)//后手情况类似，不再注释
	{ // 后手
		int x, y;
		int lian1, lian2, lian3, lian4;
		int huo1, huo2, huo3, huo4;
		int tiaothree1, tiaothree2, tiaothree3, tiaothree4;
		int tiaofour1, tiaofour2, tiaofour3, tiaofour4, tiaofour;
		int fakethree1, fakethree2, fakethree3, fakethree4;
		int mianthree1, mianthree2, mianthree3, mianthree4;
		int huotwo1, huotwo2, huotwo3, huotwo4;
		int miantwo1, miantwo2, miantwo3, miantwo4;
		int g1, g2, g3, g4;
		int value;
		value = 0;
		x = i;
		y = j;
		// 连子
		// 竖
		lian1 = 0;
		huo1 = 0;
		while (search(x + 1, j) == 2)
		{
			++x;
			++lian1;
		}
		if (search(x + 1, j) == 1 || x == 14)
			++huo1;
		x = i;
		y = j;
		while (search(x - 1, j) == 2)
		{
			--x;
			++lian1;
		}
		if (search(x - 1, j) == 1 || x == 0)
			++huo1;
		x = i;
		y = j;
		// 横
		lian2 = 0;
		huo2 = 0;
		while (search(i, y + 1) == 2)
		{
			++y;
			++lian2;
		}
		if (search(i, y + 1) == 1 || y == 14)
			++huo2;
		x = i;
		y = j;
		while (search(i, y - 1) == 2)
		{
			--y;
			++lian2;
		}
		if (search(i, y - 1) == 1 || y == 0)
			++huo2;
		x = i;
		y = j;
		// 斜1
		lian3 = 0;
		huo3 = 0;
		while (search(x + 1, y + 1) == 2)
		{
			++x;
			++y;
			++lian3;
		}
		if (search(x + 1, y + 1) == 1 || x == 14 || y == 14)
			++huo3;
		x = i;
		y = j;
		while (search(x - 1, y - 1) == 2)
		{
			--x;
			--y;
			++lian3;
		}
		if (search(x - 1, y - 1) == 1 || x == 0 || y == 0)
			++huo3;
		x = i;
		y = j;
		// 斜2
		lian4 = 0;
		huo4 = 0;
		while (search(x + 1, y - 1) == 2)
		{
			++x;
			--y;
			++lian4;
		}
		if (search(x + 1, y - 1) == 1 || x == 14 || y == 0)
			++huo4;
		x = i;
		y = j;
		while (search(x - 1, y + 1) == 2)
		{
			--x;
			++y;
			++lian4;
		}
		if (search(x - 1, y + 1) == 1 || x == 0 || y == 14)
			++huo4;
		x = i;
		y = j;
		// 活二
		// 竖
		huotwo1 = 0;
		// 1
		if (search(i - 2, j) == 0 && search(i - 1, j) == 0 && search(i + 2, j) == 0 && search(i + 3, j) == 0 && search(i + 1, j) == 2)
			++huotwo1;
		if (search(i + 2, j) == 0 && search(i + 1, j) == 0 && search(i - 2, j) == 0 && search(i - 3, j) == 0 && search(i - 1, j) == 2)
			++huotwo1;
		// 2
		if (search(i - 1, j) == 0 && search(i + 2, j) == 0 && search(i + 3, j) == 0 && search(i + 4, j) == 0 && search(i + 1, j) == 2)
			++huotwo1;
		if (search(i - 2, j) == 0 && search(i + 1, j) == 0 && search(i + 2, j) == 0 && search(i + 3, j) == 0 && search(i - 1, j) == 2)
			++huotwo1;
		if (search(i + 1, j) == 0 && search(i - 2, j) == 0 && search(i - 3, j) == 0 && search(i - 4, j) == 0 && search(i - 1, j) == 2)
			++huotwo1;
		if (search(i + 2, j) == 0 && search(i - 1, j) == 0 && search(i - 2, j) == 0 && search(i - 3, j) == 0 && search(i + 1, j) == 2)
			++huotwo1;
		// 3
		if (search(i - 2, j) == 0 && search(i - 1, j) == 0 && search(i + 1, j) == 0 && search(i + 3, j) == 0 && search(i + 2, j) == 2)
			++huotwo1;
		if (search(i - 4, j) == 0 && search(i - 3, j) == 0 && search(i - 1, j) == 0 && search(i + 1, j) == 0 && search(i - 2, j) == 2)
			++huotwo1;
		if (search(i + 2, j) == 0 && search(i + 1, j) == 0 && search(i - 1, j) == 0 && search(i - 3, j) == 0 && search(i - 2, j) == 2)
			++huotwo1;
		if (search(i + 4, j) == 0 && search(i + 3, j) == 0 && search(i + 1, j) == 0 && search(i - 1, j) == 0 && search(i + 2, j) == 2)
			++huotwo1;
		// 4
		if (search(i - 1, j) == 0 && search(i + 1, j) == 0 && search(i + 2, j) == 0 && search(i + 4, j) == 0 && search(i + 3, j) == 2)
			++huotwo1;
		if (search(i + 1, j) == 0 && search(i - 1, j) == 0 && search(i - 2, j) == 0 && search(i - 4, j) == 0 && search(i - 3, j) == 2)
			++huotwo1;
		// 横
		huotwo2 = 0;
		// 1
		if (search(i, j - 2) == 0 && search(i, j - 1) == 0 && search(i, j + 2) == 0 && search(i, j + 3) == 0 && search(i, j + 1) == 2)
			++huotwo2;
		if (search(i, j + 2) == 0 && search(i, j + 1) == 0 && search(i, j - 2) == 0 && search(i, j - 3) == 0 && search(i, j - 1) == 2)
			++huotwo2;
		// 2
		if (search(i, j - 1) == 0 && search(i, j + 2) == 0 && search(i, j + 3) == 0 && search(i, j + 4) == 0 && search(i, j + 1) == 2)
			++huotwo2;
		if (search(i, j - 2) == 0 && search(i, j + 1) == 0 && search(i, j + 2) == 0 && search(i, j + 3) == 0 && search(i, j - 1) == 2)
			++huotwo2;
		if (search(i, j + 1) == 0 && search(i, j - 2) == 0 && search(i, j - 3) == 0 && search(i, j - 4) == 0 && search(i, j - 1) == 2)
			++huotwo2;
		if (search(i, j + 2) == 0 && search(i, j - 1) == 0 && search(i, j - 2) == 0 && search(i, j - 3) == 0 && search(i, j + 1) == 2)
			++huotwo2;
		// 3
		if (search(i, j - 2) == 0 && search(i, j - 1) == 0 && search(i, j + 1) == 0 && search(i, j + 3) == 0 && search(i, j + 2) == 2)
			++huotwo2;
		if (search(i, j - 4) == 0 && search(i, j - 3) == 0 && search(i, j - 1) == 0 && search(i, j + 1) == 0 && search(i, j - 2) == 2)
			++huotwo2;
		if (search(i, j + 2) == 0 && search(i, j + 1) == 0 && search(i, j - 1) == 0 && search(i, j - 3) == 0 && search(i, j - 2) == 2)
			++huotwo2;
		if (search(i, j + 4) == 0 && search(i, j + 3) == 0 && search(i, j + 1) == 0 && search(i, j - 1) == 0 && search(i, j + 2) == 2)
			++huotwo2;
		// 4
		if (search(i, j - 1) == 0 && search(i, j + 1) == 0 && search(i, j + 2) == 0 && search(i, j + 4) == 0 && search(i, j + 3) == 2)
			++huotwo2;
		if (search(i, j + 1) == 0 && search(i, j - 1) == 0 && search(i, j - 2) == 0 && search(i, j - 4) == 0 && search(i, j - 3) == 2)
			++huotwo2;
		// 斜1
		huotwo3 = 0;
		// 1
		if (search(i - 2, j - 2) == 0 && search(i - 1, j - 1) == 0 && search(i + 2, j + 2) == 0 && search(i + 3, j + 3) == 0 && search(i + 1, j + 1) == 2)
			++huotwo3;
		if (search(i + 2, j + 2) == 0 && search(i + 1, j + 1) == 0 && search(i - 2, j - 2) == 0 && search(i - 3, j - 3) == 0 && search(i - 1, j - 1) == 2)
			++huotwo3;
		// 2
		if (search(i - 1, j - 1) == 0 && search(i + 2, j + 2) == 0 && search(i + 3, j + 3) == 0 && search(i + 4, j + 4) == 0 && search(i + 1, j + 1) == 2)
			++huotwo3;
		if (search(i - 2, j - 2) == 0 && search(i + 1, j + 1) == 0 && search(i + 2, j + 2) == 0 && search(i + 3, j + 3) == 0 && search(i - 1, j - 1) == 2)
			++huotwo3;
		if (search(i + 1, j + 1) == 0 && search(i - 2, j - 2) == 0 && search(i - 3, j - 3) == 0 && search(i - 4, j - 4) == 0 && search(i - 1, j - 1) == 2)
			++huotwo3;
		if (search(i + 2, j + 2) == 0 && search(i - 1, j - 1) == 0 && search(i - 2, j - 2) == 0 && search(i - 3, j - 3) == 0 && search(i + 1, j + 1) == 2)
			++huotwo3;
		// 3
		if (search(i - 2, j - 2) == 0 && search(i - 1, j - 1) == 0 && search(i + 1, j + 1) == 0 && search(i + 3, j + 3) == 0 && search(i + 2, j + 2) == 2)
			++huotwo3;
		if (search(i - 4, j - 4) == 0 && search(i - 3, j - 3) == 0 && search(i - 1, j - 1) == 0 && search(i + 1, j + 1) == 0 && search(i - 2, j - 2) == 2)
			++huotwo3;
		if (search(i + 2, j + 2) == 0 && search(i + 1, j + 1) == 0 && search(i - 1, j - 1) == 0 && search(i - 3, j - 3) == 0 && search(i - 2, j - 2) == 2)
			++huotwo3;
		if (search(i + 4, j + 4) == 0 && search(i + 3, j + 3) == 0 && search(i + 1, j + 1) == 0 && search(i - 1, j - 1) == 0 && search(i + 2, j + 2) == 2)
			++huotwo3;
		// 4
		if (search(i - 1, j - 1) == 0 && search(i + 1, j + 1) == 0 && search(i + 2, j + 2) == 0 && search(i + 4, j + 4) == 0 && search(i + 3, j + 3) == 2)
			++huotwo3;
		if (search(i + 1, j + 1) == 0 && search(i - 1, j - 1) == 0 && search(i - 2, j - 2) == 0 && search(i - 4, j - 4) == 0 && search(i - 3, j - 3) == 2)
			++huotwo3;
		// 斜2
		huotwo4 = 0;
		// 1
		if (search(i - 2, j + 2) == 0 && search(i - 1, j + 1) == 0 && search(i + 2, j - 2) == 0 && search(i + 3, j - 3) == 0 && search(i + 1, j - 1) == 2)
			++huotwo4;
		if (search(i + 2, j - 2) == 0 && search(i + 1, j - 1) == 0 && search(i - 2, j + 2) == 0 && search(i - 3, j + 3) == 0 && search(i - 1, j + 1) == 2)
			++huotwo4;
		// 2
		if (search(i - 1, j + 1) == 0 && search(i + 2, j - 2) == 0 && search(i + 3, j - 3) == 0 && search(i + 4, j - 4) == 0 && search(i + 1, j - 1) == 2)
			++huotwo4;
		if (search(i - 2, j + 2) == 0 && search(i + 1, j - 1) == 0 && search(i + 2, j - 2) == 0 && search(i + 3, j - 3) == 0 && search(i - 1, j + 1) == 2)
			++huotwo4;
		if (search(i + 1, j - 1) == 0 && search(i - 2, j + 2) == 0 && search(i - 3, j + 3) == 0 && search(i - 4, j + 4) == 0 && search(i - 1, j + 1) == 2)
			++huotwo4;
		if (search(i + 2, j - 2) == 0 && search(i - 1, j + 1) == 0 && search(i - 2, j + 2) == 0 && search(i - 3, j + 3) == 0 && search(i + 1, j - 1) == 2)
			++huotwo4;
		// 3
		if (search(i - 2, j + 2) == 0 && search(i - 1, j + 1) == 0 && search(i + 1, j - 1) == 0 && search(i + 3, j - 3) == 0 && search(i + 2, j - 2) == 2)
			++huotwo4;
		if (search(i - 4, j + 4) == 0 && search(i - 3, j + 3) == 0 && search(i - 1, j + 1) == 0 && search(i + 1, j - 1) == 0 && search(i - 2, j + 2) == 2)
			++huotwo4;
		if (search(i + 2, j - 2) == 0 && search(i + 1, j - 1) == 0 && search(i - 1, j + 1) == 0 && search(i - 3, j + 3) == 0 && search(i - 2, j + 2) == 2)
			++huotwo4;
		if (search(i + 4, j - 4) == 0 && search(i + 3, j - 3) == 0 && search(i + 1, j - 1) == 0 && search(i - 1, j + 1) == 0 && search(i + 2, j - 2) == 2)
			++huotwo4;
		// 4
		if (search(i - 1, j + 1) == 0 && search(i + 1, j - 1) == 0 && search(i + 2, j - 2) == 0 && search(i + 4, j - 4) == 0 && search(i + 3, j - 3) == 2)
			++huotwo4;
		if (search(i + 1, j - 1) == 0 && search(i - 1, j + 1) == 0 && search(i - 2, j + 2) == 0 && search(i - 4, j + 4) == 0 && search(i - 3, j + 3) == 2)
			++huotwo4;
		// 眠二
		miantwo1 = miantwo2 = miantwo3 = miantwo4 = 0;
		// 竖
		miantwo1 = 0;
		// 1
		if (search(i + 2, j) == 0 && search(i + 3, j) == 0 && search(i + 4, j) == 0 && search(i - 1, j) != 0 && search(i - 1, j) != 2 && search(i + 1, j) == 2)
			++miantwo1;
		if (search(i + 1, j) == 0 && search(i + 2, j) == 0 && search(i + 3, j) == 0 && search(i - 2, j) != 0 && search(i - 2, j) != 2 && search(i - 1, j) == 2)
			++miantwo1;
		if (search(i - 2, j) == 0 && search(i - 3, j) == 0 && search(i - 4, j) == 0 && search(i + 1, j) != 0 && search(i + 1, j) != 2 && search(i - 1, j) == 2)
			++miantwo1;
		if (search(i - 1, j) == 0 && search(i - 2, j) == 0 && search(i - 3, j) == 0 && search(i + 2, j) != 0 && search(i + 2, j) != 2 && search(i + 1, j) == 2)
			++miantwo1;
		// 2
		if (search(i + 1, j) == 0 && search(i + 3, j) == 0 && search(i + 4, j) == 0 && search(i - 1, j) != 0 && search(i - 1, j) != 2 && search(i + 2, j) == 2)
			++miantwo1;
		if (search(i - 1, j) == 0 && search(i + 1, j) == 0 && search(i + 2, j) == 0 && search(i - 3, j) != 0 && search(i - 3, j) != 2 && search(i - 2, j) == 2)
			++miantwo1;
		if (search(i - 1, j) == 0 && search(i - 3, j) == 0 && search(i - 4, j) == 0 && search(i + 1, j) != 0 && search(i + 1, j) != 2 && search(i - 2, j) == 2)
			++miantwo1;
		if (search(i + 1, j) == 0 && search(i - 1, j) == 0 && search(i - 2, j) == 0 && search(i + 3, j) != 0 && search(i + 3, j) != 2 && search(i + 2, j) == 2)
			++miantwo1;
		// 3
		if (search(i + 1, j) == 0 && search(i + 2, j) == 0 && search(i + 4, j) == 0 && search(i - 1, j) != 0 && search(i - 1, j) != 2 && search(i + 3, j) == 2)
			++miantwo1;
		if (search(i - 2, j) == 0 && search(i - 1, j) == 0 && search(i + 1, j) == 0 && search(i - 4, j) != 0 && search(i - 4, j) != 2 && search(i - 3, j) == 2)
			++miantwo1;
		if (search(i - 1, j) == 0 && search(i - 2, j) == 0 && search(i - 4, j) == 0 && search(i + 1, j) != 0 && search(i + 1, j) != 2 && search(i - 3, j) == 2)
			++miantwo1;
		if (search(i + 2, j) == 0 && search(i + 1, j) == 0 && search(i - 1, j) == 0 && search(i + 4, j) != 0 && search(i + 4, j) != 2 && search(i + 3, j) == 2)
			++miantwo1;
		// 4
		if (search(i + 1, j) == 0 && search(i + 2, j) == 0 && search(i + 3, j) == 0 && search(i + 4, j) == 2)
			++miantwo1;
		if (search(i - 1, j) == 0 && search(i - 2, j) == 0 && search(i - 3, j) == 0 && search(i - 4, j) == 2)
			++miantwo1;
		// 5
		if (search(i - 2, j) == 0 && search(i - 1, j) == 0 && search(i + 2, j) == 0 && search(i - 3, j) != 0 && search(i - 3, j) != 2 && search(i + 1, j) == 2 && search(i + 3, j) != 0 && search(i + 3, j) != 2)
			++miantwo1;
		if (search(i - 3, j) == 0 && search(i - 2, j) == 0 && search(i + 1, j) == 0 && search(i - 4, j) != 0 && search(i - 4, j) != 2 && search(i - 1, j) == 2 && search(i + 2, j) != 0 && search(i + 2, j) != 2)
			++miantwo1;
		if (search(i + 2, j) == 0 && search(i + 1, j) == 0 && search(i - 2, j) == 0 && search(i + 3, j) != 0 && search(i + 3, j) != 2 && search(i - 1, j) == 2 && search(i - 3, j) != 0 && search(i - 3, j) != 2)
			++miantwo1;
		if (search(i + 3, j) == 0 && search(i + 2, j) == 0 && search(i - 1, j) == 0 && search(i + 4, j) != 0 && search(i + 4, j) != 2 && search(i + 1, j) == 2 && search(i - 2, j) != 0 && search(i - 2, j) != 2)
			++miantwo1;
		// 6
		if (search(i - 1, j) == 0 && search(i + 1, j) == 0 && search(i + 3, j) == 0 && search(i - 2, j) != 0 && search(i - 2, j) != 2 && search(i + 2, j) == 2 && search(i + 4, j) != 0 && search(i + 4, j) != 2)
			++miantwo1;
		if (search(i + 1, j) == 0 && search(i - 1, j) == 0 && search(i - 3, j) == 0 && search(i + 2, j) != 0 && search(i + 2, j) != 2 && search(i - 2, j) == 2 && search(i - 4, j) != 0 && search(i - 4, j) != 2)
			++miantwo1;
		// 横
		miantwo2 = 0;
		// 1
		if (search(i, j + 2) == 0 && search(i, j + 3) == 0 && search(i, j + 4) == 0 && search(i, j - 1) != 0 && search(i, j - 1) != 2 && search(i, j + 1) == 2)
			++miantwo2;
		if (search(i, j + 1) == 0 && search(i, j + 2) == 0 && search(i, j + 3) == 0 && search(i, j - 2) != 0 && search(i, j - 2) != 2 && search(i, j - 1) == 2)
			++miantwo2;
		if (search(i, j - 2) == 0 && search(i, j - 3) == 0 && search(i, j - 4) == 0 && search(i, j + 1) != 0 && search(i, j + 1) != 2 && search(i, j - 1) == 2)
			++miantwo2;
		if (search(i, j - 1) == 0 && search(i, j - 2) == 0 && search(i, j - 3) == 0 && search(i, j + 2) != 0 && search(i, j + 2) != 2 && search(i, j + 1) == 2)
			++miantwo2;
		// 2
		if (search(i, j + 1) == 0 && search(i, j + 3) == 0 && search(i, j + 4) == 0 && search(i, j - 1) != 0 && search(i, j - 1) != 2 && search(i, j + 2) == 2)
			++miantwo2;
		if (search(i, j - 1) == 0 && search(i, j + 1) == 0 && search(i, j + 2) == 0 && search(i, j - 3) != 0 && search(i, j - 3) != 2 && search(i, j - 2) == 2)
			++miantwo2;
		if (search(i, j - 1) == 0 && search(i, j - 3) == 0 && search(i, j - 4) == 0 && search(i, j + 1) != 0 && search(i, j + 1) != 2 && search(i, j - 2) == 2)
			++miantwo2;
		if (search(i, j + 1) == 0 && search(i, j - 1) == 0 && search(i, j - 2) == 0 && search(i, j + 3) != 0 && search(i, j + 3) != 2 && search(i, j + 2) == 2)
			++miantwo2;
		// 3
		if (search(i, j + 1) == 0 && search(i, j + 2) == 0 && search(i, j + 4) == 0 && search(i, j - 1) != 0 && search(i, j - 1) != 2 && search(i, j + 3) == 2)
			++miantwo2;
		if (search(i, j - 2) == 0 && search(i, j - 1) == 0 && search(i, j + 1) == 0 && search(i, j - 4) != 0 && search(i, j - 4) != 2 && search(i, j - 3) == 2)
			++miantwo2;
		if (search(i, j - 1) == 0 && search(i, j - 2) == 0 && search(i, j - 4) == 0 && search(i, j + 1) != 0 && search(i, j + 1) != 2 && search(i, j - 3) == 2)
			++miantwo2;
		if (search(i, j + 2) == 0 && search(i, j + 1) == 0 && search(i, j - 1) == 0 && search(i, j + 4) != 0 && search(i, j + 4) != 2 && search(i, j + 3) == 2)
			++miantwo2;
		// 4
		if (search(i, j + 1) == 0 && search(i, j + 2) == 0 && search(i, j + 3) == 0 && search(i, j + 4) == 2)
			++miantwo2;
		if (search(i, j - 1) == 0 && search(i, j - 2) == 0 && search(i, j - 3) == 0 && search(i, j - 4) == 2)
			++miantwo2;
		// 5
		if (search(i, j - 2) == 0 && search(i, j - 1) == 0 && search(i, j + 2) == 0 && search(i, j - 3) != 0 && search(i, j - 3) != 2 && search(i, j + 1) == 2 && search(i, j + 3) != 0 && search(i, j + 3) != 2)
			++miantwo1;
		if (search(i, j - 3) == 0 && search(i, j - 2) == 0 && search(i, j + 1) == 0 && search(i, j - 4) != 0 && search(i, j - 4) != 2 && search(i, j - 1) == 2 && search(i, j + 2) != 0 && search(i, j + 2) != 2)
			++miantwo1;
		if (search(i, j + 2) == 0 && search(i, j + 1) == 0 && search(i, j - 2) == 0 && search(i, j + 3) != 0 && search(i, j + 3) != 2 && search(i, j - 1) == 2 && search(i, j - 3) != 0 && search(i, j - 3) != 2)
			++miantwo2;
		if (search(i, j + 3) == 0 && search(i, j + 2) == 0 && search(i, j - 1) == 0 && search(i, j + 4) != 0 && search(i, j + 4) != 2 && search(i, j + 1) == 2 && search(i, j - 2) != 0 && search(i, j - 2) != 2)
			++miantwo2;
		// 6
		if (search(i, j - 1) == 0 && search(i, j + 1) == 0 && search(i, j + 3) == 0 && search(i, j - 2) != 0 && search(i, j - 2) != 2 && search(i, j + 2) == 2 && search(i, j + 4) != 0 && search(i, j + 4) != 2)
			++miantwo2;
		if (search(i, j + 1) == 0 && search(i, j - 1) == 0 && search(i, j - 3) == 0 && search(i, j + 2) != 0 && search(i, j + 2) != 2 && search(i, j - 2) == 2 && search(i, j - 4) != 0 && search(i, j - 4) != 2)
			++miantwo2;
		// 斜1
		miantwo3 = 0;
		// 1
		if (search(i + 2, j + 2) == 0 && search(i + 3, j + 3) == 0 && search(i + 4, j + 4) == 0 && search(i - 1, j - 1) != 0 && search(i - 1, j - 1) != 2 && search(i + 1, j + 1) == 2)
			++miantwo3;
		if (search(i + 1, j + 1) == 0 && search(i + 2, j + 2) == 0 && search(i + 3, j + 3) == 0 && search(i - 2, j - 2) != 0 && search(i - 2, j - 2) != 2 && search(i - 1, j - 1) == 2)
			++miantwo3;
		if (search(i - 2, j - 2) == 0 && search(i - 3, j - 3) == 0 && search(i - 4, j - 4) == 0 && search(i + 1, j + 1) != 0 && search(i + 1, j + 1) != 2 && search(i - 1, j - 1) == 2)
			++miantwo3;
		if (search(i - 1, j - 1) == 0 && search(i - 2, j - 2) == 0 && search(i - 3, j - 3) == 0 && search(i + 2, j + 2) != 0 && search(i + 2, j + 2) != 2 && search(i + 1, j + 1) == 2)
			++miantwo3;
		// 2
		if (search(i + 1, j + 1) == 0 && search(i + 3, j + 3) == 0 && search(i + 4, j + 4) == 0 && search(i - 1, j - 1) != 0 && search(i - 1, j - 1) != 2 && search(i + 2, j + 2) == 2)
			++miantwo3;
		if (search(i - 1, j - 1) == 0 && search(i + 1, j + 1) == 0 && search(i + 2, j + 2) == 0 && search(i - 3, j - 3) != 0 && search(i - 3, j - 3) != 2 && search(i - 2, j - 2) == 2)
			++miantwo3;
		if (search(i - 1, j - 1) == 0 && search(i - 3, j - 3) == 0 && search(i - 4, j - 4) == 0 && search(i + 1, j + 1) != 0 && search(i + 1, j + 1) != 2 && search(i - 2, j - 2) == 2)
			++miantwo3;
		if (search(i + 1, j + 1) == 0 && search(i - 1, j - 1) == 0 && search(i - 2, j - 2) == 0 && search(i + 3, j + 3) != 0 && search(i + 3, j + 3) != 2 && search(i + 2, j + 2) == 2)
			++miantwo3;
		// 3
		if (search(i + 1, j + 1) == 0 && search(i + 2, j + 2) == 0 && search(i + 4, j + 4) == 0 && search(i - 1, j - 1) != 0 && search(i - 1, j - 1) != 2 && search(i + 3, j + 3) == 2)
			++miantwo3;
		if (search(i - 2, j - 2) == 0 && search(i - 1, j - 1) == 0 && search(i + 1, j + 1) == 0 && search(i - 4, j - 4) != 0 && search(i - 4, j - 4) != 2 && search(i - 3, j - 3) == 2)
			++miantwo3;
		if (search(i - 1, j - 1) == 0 && search(i - 2, j - 2) == 0 && search(i - 4, j - 4) == 0 && search(i + 1, j + 1) != 0 && search(i + 1, j + 1) != 2 && search(i - 3, j - 3) == 2)
			++miantwo3;
		if (search(i + 2, j + 2) == 0 && search(i + 1, j + 1) == 0 && search(i - 1, j - 1) == 0 && search(i + 4, j + 4) != 0 && search(i + 4, j + 4) != 2 && search(i + 3, j + 3) == 2)
			++miantwo3;
		// 4
		if (search(i + 1, j + 1) == 0 && search(i + 2, j + 2) == 0 && search(i + 3, j + 3) == 0 && search(i + 4, j + 4) == 2)
			++miantwo3;
		if (search(i - 1, j - 1) == 0 && search(i - 2, j - 2) == 0 && search(i - 3, j - 3) == 0 && search(i - 4, j - 4) == 2)
			++miantwo3;
		// 5
		if (search(i - 2, j - 2) == 0 && search(i - 1, j - 1) == 0 && search(i + 2, j + 2) == 0 && search(i - 3, j - 3) != 0 && search(i - 3, j - 3) != 2 && search(i + 1, j + 1) == 2 && search(i + 3, j + 3) != 0 && search(i + 3, j + 3) != 2)
			++miantwo3;
		if (search(i - 3, j - 3) == 0 && search(i - 2, j - 2) == 0 && search(i + 1, j + 1) == 0 && search(i - 4, j - 4) != 0 && search(i - 4, j - 4) != 2 && search(i - 1, j - 1) == 2 && search(i + 2, j + 2) != 0 && search(i + 2, j + 2) != 2)
			++miantwo3;
		if (search(i + 2, j + 2) == 0 && search(i + 1, j + 1) == 0 && search(i - 2, j - 2) == 0 && search(i + 3, j + 3) != 0 && search(i + 3, j + 3) != 2 && search(i - 1, j - 1) == 2 && search(i - 3, j - 3) != 0 && search(i - 3, j - 3) != 2)
			++miantwo3;
		if (search(i + 3, j + 3) == 0 && search(i + 2, j + 2) == 0 && search(i - 1, j - 1) == 0 && search(i + 4, j + 4) != 0 && search(i + 4, j + 4) != 2 && search(i + 1, j + 1) == 2 && search(i - 2, j - 2) != 0 && search(i - 2, j - 2) != 2)
			++miantwo3;
		// 6
		if (search(i - 1, j - 1) == 0 && search(i + 1, j + 1) == 0 && search(i + 3, j + 3) == 0 && search(i - 2, j - 2) != 0 && search(i - 2, j - 2) != 2 && search(i + 2, j + 2) == 2 && search(i + 4, j + 4) != 0 && search(i + 4, j + 4) != 2)
			++miantwo3;
		if (search(i + 1, j + 1) == 0 && search(i - 1, j - 1) == 0 && search(i - 3, j - 3) == 0 && search(i + 2, j + 2) != 0 && search(i + 2, j + 2) != 2 && search(i - 2, j - 2) == 2 && search(i - 4, j - 4) != 0 && search(i - 4, j - 4) != 2)
			++miantwo3;
		// 斜2
		miantwo4 = 0;
		// 1
		if (search(i + 2, j - 2) == 0 && search(i + 3, j - 3) == 0 && search(i + 4, j - 4) == 0 && search(i - 1, j + 1) != 0 && search(i - 1, j + 1) != 2 && search(i + 1, j - 1) == 2)
			++miantwo4;
		if (search(i + 1, j - 1) == 0 && search(i + 2, j - 2) == 0 && search(i + 3, j - 3) == 0 && search(i - 2, j + 2) != 0 && search(i - 2, j + 2) != 2 && search(i - 1, j + 1) == 2)
			++miantwo4;
		if (search(i - 2, j + 2) == 0 && search(i - 3, j + 3) == 0 && search(i - 4, j + 4) == 0 && search(i + 1, j - 1) != 0 && search(i + 1, j - 1) != 2 && search(i - 1, j + 1) == 2)
			++miantwo4;
		if (search(i - 1, j + 1) == 0 && search(i - 2, j + 2) == 0 && search(i - 3, j + 3) == 0 && search(i + 2, j - 2) != 0 && search(i + 2, j - 2) != 2 && search(i + 1, j - 1) == 2)
			++miantwo4;
		// 2
		if (search(i + 1, j - 1) == 0 && search(i + 3, j - 3) == 0 && search(i + 4, j - 4) == 0 && search(i - 1, j + 1) != 0 && search(i - 1, j + 1) != 2 && search(i + 2, j - 2) == 2)
			++miantwo4;
		if (search(i - 1, j + 1) == 0 && search(i + 1, j - 1) == 0 && search(i + 2, j - 2) == 0 && search(i - 3, j + 3) != 0 && search(i - 3, j + 3) != 2 && search(i - 2, j + 2) == 2)
			++miantwo4;
		if (search(i - 1, j + 1) == 0 && search(i - 3, j + 3) == 0 && search(i - 4, j + 4) == 0 && search(i + 1, j - 1) != 0 && search(i + 1, j - 1) != 2 && search(i - 2, j + 2) == 2)
			++miantwo4;
		if (search(i + 1, j - 1) == 0 && search(i - 1, j + 1) == 0 && search(i - 2, j + 2) == 0 && search(i + 3, j - 3) != 0 && search(i + 3, j - 3) != 2 && search(i + 2, j - 2) == 2)
			++miantwo4;
		// 3
		if (search(i + 1, j - 1) == 0 && search(i + 2, j - 2) == 0 && search(i + 4, j - 4) == 0 && search(i - 1, j + 1) != 0 && search(i - 1, j + 1) != 2 && search(i + 3, j - 3) == 2)
			++miantwo4;
		if (search(i - 2, j + 2) == 0 && search(i - 1, j + 1) == 0 && search(i + 1, j - 1) == 0 && search(i - 4, j + 4) != 0 && search(i - 4, j + 4) != 2 && search(i - 3, j + 3) == 2)
			++miantwo4;
		if (search(i - 1, j + 1) == 0 && search(i - 2, j + 2) == 0 && search(i - 4, j + 4) == 0 && search(i + 1, j - 1) != 0 && search(i + 1, j - 1) != 2 && search(i - 3, j + 3) == 2)
			++miantwo4;
		if (search(i + 2, j - 2) == 0 && search(i + 1, j - 1) == 0 && search(i - 1, j + 1) == 0 && search(i + 4, j - 4) != 0 && search(i + 4, j - 4) != 2 && search(i + 3, j - 3) == 2)
			++miantwo4;
		// 4
		if (search(i + 1, j - 1) == 0 && search(i + 2, j - 2) == 0 && search(i + 3, j - 3) == 0 && search(i + 4, j - 4) == 2)
			++miantwo4;
		if (search(i - 1, j + 1) == 0 && search(i - 2, j + 2) == 0 && search(i - 3, j + 3) == 0 && search(i - 4, j + 4) == 2)
			++miantwo4;
		// 5
		if (search(i - 2, j + 2) == 0 && search(i - 1, j + 1) == 0 && search(i + 2, j - 2) == 0 && search(i - 3, j + 3) != 0 && search(i - 3, j + 3) != 2 && search(i + 1, j - 1) == 2 && search(i + 3, j - 3) != 0 && search(i + 3, j - 3) != 2)
			++miantwo4;
		if (search(i - 3, j + 3) == 0 && search(i - 2, j + 2) == 0 && search(i + 1, j - 1) == 0 && search(i - 4, j + 4) != 0 && search(i - 4, j + 4) != 2 && search(i - 1, j + 1) == 2 && search(i + 2, j - 2) != 0 && search(i + 2, j - 2) != 2)
			++miantwo4;
		if (search(i + 2, j - 2) == 0 && search(i + 1, j - 1) == 0 && search(i - 2, j + 2) == 0 && search(i + 3, j - 3) != 0 && search(i + 3, j - 3) != 2 && search(i - 1, j + 1) == 2 && search(i - 3, j + 3) != 0 && search(i - 3, j + 3) != 2)
			++miantwo4;
		if (search(i + 3, j - 3) == 0 && search(i + 2, j - 2) == 0 && search(i - 1, j + 1) == 0 && search(i + 4, j - 4) != 0 && search(i + 4, j - 4) != 2 && search(i + 1, j - 1) == 2 && search(i - 2, j + 2) != 0 && search(i - 2, j + 2) != 2)
			++miantwo4;
		// 6
		if (search(i - 1, j + 1) == 0 && search(i + 1, j - 1) == 0 && search(i + 3, j - 3) == 0 && search(i - 2, j + 2) != 0 && search(i - 2, j + 2) != 2 && search(i + 2, j - 2) == 2 && search(i + 4, j - 4) != 0 && search(i + 4, j - 4) != 2)
			++miantwo4;
		if (search(i + 1, j - 1) == 0 && search(i - 1, j + 1) == 0 && search(i - 3, j + 3) == 0 && search(i + 2, j - 2) != 0 && search(i + 2, j - 2) != 2 && search(i - 2, j + 2) == 2 && search(i - 4, j + 4) != 0 && search(i - 4, j + 4) != 2)
			++miantwo4;
		// 跳三
		tiaothree1 = 0;
		if (huo1 == 0)
		{
			if (lian1 == 0)
			{
				if (search(i - 2, j) == 2 && search(i - 3, j) == 2 && search(i - 4, j) != 1 && search(i - 4, j) != 2 && i != 3 && search(i - 4, j) == 0)
					++tiaothree1;
				if (search(i + 2, j) == 2 && search(i + 3, j) == 2 && search(i + 4, j) != 1 && search(i + 4, j) != 2 && i != 11 && search(i + 4, j) == 0)
					++tiaothree1;
			}
			if (lian1 == 1)
			{
				if (search(i - 1, j) == 2)
				{
					if (search(i - 3, j) == 2 && search(i - 4, j) != 1 && search(i - 4, j) != 2 && i != 3 && search(i - 4, j) == 0)
						++tiaothree1;
					if (search(i + 2, j) == 2 && search(i + 3, j) != 1 && search(i + 3, j) != 2 && i != 12 && search(i + 3, j) == 0)
						++tiaothree1;
				}
				if (search(i + 1, j) == 2)
				{
					if (search(i + 3, j) == 2 && search(i + 4, j) != 1 && search(i + 4, j) != 2 && i != 11 && search(i + 4, j) == 0)
						++tiaothree1;
					if (search(i - 2, j) == 2 && search(i - 3, j) != 1 && search(i - 3, j) != 2 && i != 2 && search(i - 3, j) == 0)
						++tiaothree1;
				}
			}
		}
		tiaothree2 = 0;
		if (huo2 == 0)
		{
			if (lian2 == 0)
			{
				if (search(i, j - 2) == 2 && search(i, j - 3) == 2 && search(i, j - 4) != 1 && search(i, j - 4) != 2 && i != 3 && search(i, j - 4) == 0)
					++tiaothree2;
				if (search(i, j + 2) == 2 && search(i, j + 3) == 2 && search(i, j + 4) != 1 && search(i, j + 4) != 2 && i != 11 && search(i, j + 4) == 0)
					++tiaothree2;
			}
			if (lian2 == 1)
			{
				if (search(i, j - 1) == 2)
				{
					if (search(i, j - 3) == 2 && search(i, j - 4) != 1 && search(i, j - 4) != 2 && i != 3 && search(i, j - 4) == 0)
						++tiaothree2;
					if (search(i, j + 2) == 2 && search(i, j + 3) != 1 && search(i, j + 3) != 2 && i != 12 && search(i, j + 3) == 0)
						++tiaothree2;
				}
				if (search(i, j + 1) == 2)
				{
					if (search(i, j + 3) == 2 && search(i, j + 4) != 1 && search(i, j + 4) != 2 && i != 11 && search(i, j + 4) == 0)
						++tiaothree2;
					if (search(i, j - 2) == 2 && search(i, j - 3) != 1 && search(i, j - 3) != 2 && i != 2 && search(i, j - 3) == 0)
						++tiaothree2;
				}
			}
		}
		tiaothree3 = 0;
		if (huo3 == 0)
		{
			if (lian3 == 0)
			{
				if (search(i - 2, j - 2) == 2 && search(i - 3, j - 3) == 2 && search(i - 4, j - 4) != 1 && search(i - 4, j - 4) != 2 && i != 3 && j != 3 && search(i - 4, j - 4) == 0)
					++tiaothree3;
				if (search(i + 2, j + 2) == 2 && search(i + 3, j + 3) == 2 && search(i + 4, j + 4) != 1 && search(i + 4, j + 4) != 2 && i != 11 && j != 11 && search(i + 4, j + 4) == 0)
					++tiaothree3;
			}
			if (lian3 == 1)
			{
				if (search(i - 1, j - 1) == 2)
				{
					if (search(i - 3, j - 3) == 2 && search(i - 4, j - 4) != 1 && search(i - 4, j - 4) != 2 && i != 3 && j != 3 && search(i - 4, j - 4) == 0)
						++tiaothree3;
					if (search(i + 2, j + 2) == 2 && search(i + 3, j + 3) != 1 && search(i + 3, j + 3) != 2 && i != 12 && j != 12 && search(i + 3, j + 3) == 0)
						++tiaothree3;
				}
				if (search(i + 1, j + 1) == 2)
				{
					if (search(i + 3, j + 3) == 2 && search(i + 4, j + 4) != 1 && search(i + 4, j + 4) != 2 && i != 11 && j != 11 && search(i + 4, j + 4) == 0)
						++tiaothree3;
					if (search(i - 2, j - 2) == 2 && search(i - 3, j - 3) != 1 && search(i - 3, j - 3) != 2 && i != 2 && j != 2 && search(i - 3, j - 3) == 0)
						++tiaothree3;
				}
			}
		}
		tiaothree4 = 0;
		if (huo4 == 0)
		{
			if (lian4 == 0)
			{
				if (search(i - 2, j + 2) == 2 && search(i - 3, j + 3) == 2 && search(i - 4, j + 4) != 1 && search(i - 4, j + 4) != 2 && i != 3 && j != 11 && search(i - 4, j + 4) == 0)
					++tiaothree4;
				if (search(i + 2, j - 2) == 2 && search(i + 3, j - 3) == 2 && search(i + 4, j - 4) != 1 && search(i + 4, j - 4) != 2 && i != 11 && j != 3 && search(i + 4, j - 4) == 0)
					++tiaothree4;
			}
			if (lian4 == 1)
			{
				if (search(i - 1, j + 1) == 2)
				{
					if (search(i - 3, j + 3) == 2 && search(i - 4, j + 4) != 1 && search(i - 4, j + 4) != 2 && i != 3 && j != 11 && search(i - 4, j + 4) == 0)
						++tiaothree4;
					if (search(i + 2, j - 2) == 2 && search(i + 3, j - 3) != 1 && search(i + 3, j - 3) != 2 && i != 12 && j != 2 && search(i + 3, j - 3) == 0)
						++tiaothree4;
				}
				if (search(i + 1, j - 1) == 2)
				{
					if (search(i + 3, j - 3) == 2 && search(i + 4, j - 4) != 1 && search(i + 4, j - 4) != 2 && i != 11 && j != 3 && search(i + 4, j - 4) == 0)
						++tiaothree4;
					if (search(i - 2, j + 2) == 2 && search(i - 3, j + 3) != 1 && search(i - 3, j + 3) != 2 && i != 2 && j != 12 && search(i - 3, j + 3) == 0)
						++tiaothree4;
				}
			}
		}
		// 假活三
		fakethree1 = 0;
		if (lian1 == 2 && huo1 == 0)
		{
			if (search(i - 1, j) == 2 && search(i + 1, j) == 2 && (search(i - 3, j) == 1 || i == 2) && (search(i + 3, j) == 1 || i == 12))
				fakethree1 = 2;
			else if (search(i - 1, j) == 2 && search(i - 2, j) == 2 && (search(i - 4, j) == 1 || i == 3) && (search(i + 2, j) == 1 || i == 13))
				fakethree1 = 2;
			else if (search(i + 1, j) == 2 && search(i + 2, j) == 2 && (search(i - 2, j) == 1 || i == 1) && (search(i + 4, j) == 1 || i == 11))
				fakethree1 = 2;
			else if (search(i - 1, j) == 2 && search(i + 1, j) == 2 && search(i - 3, j) != 2 && search(i + 3, j) != 2)
				fakethree1 = 1;
			else if (search(i + 1, j) == 2 && search(i + 2, j) == 2 && search(i - 2, j) != 2 && search(i + 4, j) != 2)
				fakethree1 = 1;
			else if (search(i - 1, j) == 2 && search(i - 2, j) == 2 && search(i + 2, j) != 2 && search(i - 4, j) != 2)
				fakethree1 = 1;
		}
		fakethree2 = 0;
		if (lian2 == 2 && huo2 == 0)
		{
			if (search(i, j - 1) == 2 && search(i, j + 1) == 2 && (search(i, j - 3) == 1 || j == 2) && (search(i, j + 3) == 1 || j == 12))
				fakethree2 = 2;
			else if (search(i, j - 1) == 2 && search(i, j - 2) == 2 && (search(i, j - 4) == 1 || j == 3) && (search(i, j + 2) == 1 || j == 13))
				fakethree2 = 2;
			else if (search(i, j + 1) == 2 && search(i, j + 2) == 2 && (search(i, j - 2) == 1 || j == 1) && (search(i, j + 4) == 1 || j == 11))
				fakethree2 = 2;
			else if (search(i, j - 1) == 2 && search(i, j + 1) == 2 && search(i, j - 3) != 2 && search(i, j + 3) != 2)
				fakethree2 = 1;
			else if (search(i, j + 1) == 2 && search(i, j + 2) == 2 && search(i, j - 2) != 2 && search(i, j + 4) != 2)
				fakethree2 = 1;
			else if (search(i, j - 1) == 2 && search(i, j - 2) == 2 && search(i, j + 2) != 2 && search(i, j - 4) != 2)
				fakethree2 = 1;
		}
		fakethree3 = 0;
		if (lian3 == 2 && huo3 == 0)
		{
			if (search(i - 1, j - 1) == 2 && search(i + 1, j + 1) == 2 && (search(i - 3, j - 3) == 1 || i == 2 || j == 2) && (search(i + 3, j + 3) == 1 || i == 12 || j == 12))
				fakethree3 = 2;
			else if (search(i - 1, j - 1) == 2 && search(i - 2, j - 2) == 2 && (search(i - 4, j - 4) == 1 || i == 3 || j == 3) && (search(i + 2, j + 2) == 1 || i == 13 || j == 13))
				fakethree3 = 2;
			else if (search(i + 1, j + 1) == 2 && search(i + 2, j + 2) == 2 && (search(i - 2, j - 2) == 1 || i == 1 || j == 1) && (search(i + 4, j + 4) == 1 || i == 11 || j == 11))
				fakethree3 = 2;
			else if (search(i - 1, j - 1) == 2 && search(i + 1, j + 1) == 2 && search(i - 3, j - 3) != 2 && search(i + 3, j + 3) != 2)
				fakethree3 = 1;
			else if (search(i + 1, j + 1) == 2 && search(i + 2, j + 2) == 2 && search(i - 2, j - 2) != 2 && search(i + 4, j + 4) != 2)
				fakethree3 = 1;
			else if (search(i - 1, j - 1) == 2 && search(i - 2, j - 2) == 2 && search(i + 2, j + 2) != 2 && search(i - 4, j - 4) != 2)
				fakethree3 = 1;
		}
		fakethree4 = 0;
		if (lian4 == 2 && huo4 == 0)
		{
			if (search(i - 1, j + 1) == 2 && search(i + 1, j - 1) == 2 && (search(i - 3, j + 3) == 1 || i == 2 || j == 12) && (search(i + 3, j - 3) == 1 || i == 12 || j == 2))
				fakethree4 = 2;
			else if (search(i - 1, j + 1) == 2 && search(i - 2, j + 2) == 2 && (search(i - 4, j + 4) == 1 || i == 3 || j == 11) && (search(i + 2, j - 2) == 1 || i == 13 || j == 1))
				fakethree4 = 2;
			else if (search(i + 1, j - 1) == 2 && search(i + 2, j - 2) == 2 && (search(i - 2, j + 2) == 1 || i == 1 || j == 13) && (search(i + 4, j - 3) == 1 || i == 11 || j == 3))
				fakethree4 = 2;
			else if (search(i - 1, j + 1) == 2 && search(i + 1, j - 1) == 2 && search(i - 3, j + 3) != 2 && search(i + 3, j - 3) != 2)
				fakethree4 = 1;
			else if (search(i + 1, j - 1) == 2 && search(i + 2, j - 2) == 2 && search(i - 2, j + 2) != 2 && search(i + 4, j - 4) != 2)
				fakethree4 = 1;
			else if (search(i - 1, j + 1) == 2 && search(i - 2, j + 2) == 2 && search(i + 2, j - 2) != 2 && search(i - 4, j + 4) != 2)
				fakethree4 = 1;
		}
		// 眠三
		// 竖
		mianthree1 = 0;
		// 1
		if (search(i - 1, j) != 0 && search(i - 1, j) != 2 && search(i + 1, j) == 2 && search(i + 2, j) == 2 && search(i + 3, j) == 0 && search(i + 4, j) == 0)
			++mianthree1;
		if (search(i - 2, j) != 0 && search(i - 2, j) != 2 && search(i - 1, j) == 2 && search(i + 1, j) == 2 && search(i + 2, j) == 0 && search(i + 3, j) == 0)
			++mianthree1;
		if (search(i - 3, j) != 0 && search(i - 3, j) != 2 && search(i - 2, j) == 2 && search(i - 1, j) == 2 && search(i + 1, j) == 0 && search(i + 2, j) == 0)
			++mianthree1;
		if (search(i + 3, j) != 0 && search(i + 3, j) != 2 && search(i + 2, j) == 2 && search(i + 1, j) == 2 && search(i - 1, j) == 0 && search(i - 2, j) == 0)
			++mianthree1;
		if (search(i + 1, j) != 0 && search(i + 1, j) != 2 && search(i - 1, j) == 2 && search(i - 2, j) == 2 && search(i - 3, j) == 0 && search(i - 4, j) == 0)
			++mianthree1;
		if (search(i + 2, j) != 0 && search(i + 2, j) != 2 && search(i + 1, j) == 2 && search(i - 1, j) == 2 && search(i - 2, j) == 0 && search(i - 3, j) == 0)
			++mianthree1;
		// 2
		if (search(i - 1, j) != 0 && search(i - 1, j) != 2 && search(i + 1, j) == 2 && search(i + 3, j) == 2 && search(i + 2, j) == 0 && search(i + 4, j) == 0)
			++mianthree1;
		if (search(i - 2, j) != 0 && search(i - 2, j) != 2 && search(i - 1, j) == 2 && search(i + 2, j) == 2 && search(i + 1, j) == 0 && search(i + 3, j) == 0)
			++mianthree1;
		if (search(i - 4, j) != 0 && search(i - 4, j) != 2 && search(i - 3, j) == 2 && search(i - 2, j) == 2 && search(i - 1, j) == 0 && search(i + 1, j) == 0)
			++mianthree1;
		if (search(i + 1, j) != 0 && search(i + 1, j) != 2 && search(i - 1, j) == 2 && search(i - 3, j) == 2 && search(i - 2, j) == 0 && search(i - 4, j) == 0)
			++mianthree1;
		if (search(i + 2, j) != 0 && search(i + 2, j) != 2 && search(i + 1, j) == 2 && search(i - 2, j) == 2 && search(i - 1, j) == 0 && search(i - 3, j) == 0)
			++mianthree1;
		if (search(i + 4, j) != 0 && search(i + 4, j) != 2 && search(i + 3, j) == 2 && search(i + 2, j) == 2 && search(i + 1, j) == 0 && search(i - 1, j) == 0)
			++mianthree1;
		// 3
		if (search(i - 1, j) != 0 && search(i - 1, j) != 2 && search(i + 2, j) == 2 && search(i + 3, j) == 2 && search(i + 1, j) == 0 && search(i + 4, j) == 0)
			++mianthree1;
		if (search(i - 3, j) != 0 && search(i - 3, j) != 2 && search(i - 2, j) == 2 && search(i + 1, j) == 2 && search(i - 1, j) == 0 && search(i + 2, j) == 0)
			++mianthree1;
		if (search(i - 4, j) != 0 && search(i - 4, j) != 2 && search(i - 3, j) == 2 && search(i - 1, j) == 2 && search(i - 2, j) == 0 && search(i + 1, j) == 0)
			++mianthree1;
		if (search(i + 1, j) != 0 && search(i + 1, j) != 2 && search(i - 2, j) == 2 && search(i - 3, j) == 2 && search(i - 1, j) == 0 && search(i - 4, j) == 0)
			++mianthree1;
		if (search(i + 3, j) != 0 && search(i + 3, j) != 2 && search(i + 2, j) == 2 && search(i - 1, j) == 2 && search(i + 1, j) == 0 && search(i - 2, j) == 0)
			++mianthree1;
		if (search(i + 4, j) != 0 && search(i + 4, j) != 2 && search(i + 3, j) == 2 && search(i + 1, j) == 2 && search(i + 2, j) == 0 && search(i - 1, j) == 0)
			++mianthree1;
		// 4
		if (search(i + 1, j) == 2 && search(i + 4, j) == 2 && search(i + 2, j) == 0 && search(i + 3, j) == 0)
			++mianthree1;
		if (search(i - 1, j) == 2 && search(i + 3, j) == 2 && search(i + 1, j) == 0 && search(i + 2, j) == 0)
			++mianthree1;
		if (search(i - 4, j) == 2 && search(i - 3, j) == 2 && search(i - 2, j) == 0 && search(i - 1, j) == 0)
			++mianthree1;
		if (search(i - 1, j) == 2 && search(i - 4, j) == 2 && search(i - 2, j) == 0 && search(i - 3, j) == 0)
			++mianthree1;
		if (search(i + 1, j) == 2 && search(i - 3, j) == 2 && search(i - 1, j) == 0 && search(i - 2, j) == 0)
			++mianthree1;
		if (search(i + 4, j) == 2 && search(i + 3, j) == 2 && search(i + 2, j) == 0 && search(i + 1, j) == 0)
			++mianthree1;
		// 5
		if (search(i + 2, j) == 2 && search(i + 4, j) == 2 && search(i + 1, j) == 0 && search(i + 3, j) == 0)
			++mianthree1;
		if (search(i - 2, j) == 2 && search(i + 2, j) == 2 && search(i - 1, j) == 0 && search(i + 1, j) == 0)
			++mianthree1;
		if (search(i - 4, j) == 2 && search(i - 2, j) == 2 && search(i - 1, j) == 0 && search(i - 3, j) == 0)
			++mianthree1;
		// 横
		mianthree2 = 0;
		// 1
		if (search(i, j - 1) != 0 && search(i, j - 1) != 2 && search(i, j + 1) == 2 && search(i, j + 2) == 2 && search(i, j + 3) == 0 && search(i, j + 4) == 0)
			++mianthree2;
		if (search(i, j - 2) != 0 && search(i, j - 2) != 2 && search(i, j - 1) == 2 && search(i, j + 1) == 2 && search(i, j + 2) == 0 && search(i, j + 3) == 0)
			++mianthree2;
		if (search(i, j - 3) != 0 && search(i, j - 3) != 2 && search(i, j - 2) == 2 && search(i, j - 1) == 2 && search(i, j + 1) == 0 && search(i, j + 2) == 0)
			++mianthree2;
		if (search(i, j + 3) != 0 && search(i, j + 3) != 2 && search(i, j + 2) == 2 && search(i, j + 1) == 2 && search(i, j - 1) == 0 && search(i, j - 2) == 0)
			++mianthree2;
		if (search(i, j + 1) != 0 && search(i, j + 1) != 2 && search(i, j - 1) == 2 && search(i, j - 2) == 2 && search(i, j - 3) == 0 && search(i, j - 4) == 0)
			++mianthree2;
		if (search(i, j + 2) != 0 && search(i, j + 2) != 2 && search(i, j + 1) == 2 && search(i, j - 1) == 2 && search(i, j - 2) == 0 && search(i, j - 3) == 0)
			++mianthree2;
		// 2
		if (search(i, j - 1) != 0 && search(i, j - 1) != 2 && search(i, j + 1) == 2 && search(i, j + 3) == 2 && search(i, j + 2) == 0 && search(i, j + 4) == 0)
			++mianthree2;
		if (search(i, j - 2) != 0 && search(i, j - 2) != 2 && search(i, j - 1) == 2 && search(i, j + 2) == 2 && search(i, j + 1) == 0 && search(i, j + 3) == 0)
			++mianthree2;
		if (search(i, j - 4) != 0 && search(i, j - 4) != 2 && search(i, j - 3) == 2 && search(i, j - 2) == 2 && search(i, j - 1) == 0 && search(i, j + 1) == 0)
			++mianthree2;
		if (search(i, j + 1) != 0 && search(i, j + 1) != 2 && search(i, j - 1) == 2 && search(i, j - 3) == 2 && search(i, j - 2) == 0 && search(i, j - 4) == 0)
			++mianthree2;
		if (search(i, j + 2) != 0 && search(i, j + 2) != 2 && search(i, j + 1) == 2 && search(i, j - 2) == 2 && search(i, j - 1) == 0 && search(i, j - 3) == 0)
			++mianthree2;
		if (search(i, j + 4) != 0 && search(i, j + 4) != 2 && search(i, j + 3) == 2 && search(i, j + 2) == 2 && search(i, j + 1) == 0 && search(i, j - 1) == 0)
			++mianthree2;
		// 3
		if (search(i, j - 1) != 0 && search(i, j - 1) != 2 && search(i, j + 2) == 2 && search(i, j + 3) == 2 && search(i, j + 1) == 0 && search(i, j + 4) == 0)
			++mianthree2;
		if (search(i, j - 3) != 0 && search(i, j - 3) != 2 && search(i, j - 2) == 2 && search(i, j + 1) == 2 && search(i, j - 1) == 0 && search(i, j + 2) == 0)
			++mianthree2;
		if (search(i, j - 4) != 0 && search(i, j - 4) != 2 && search(i, j - 3) == 2 && search(i, j - 1) == 2 && search(i, j - 2) == 0 && search(i, j + 1) == 0)
			++mianthree2;
		if (search(i, j + 1) != 0 && search(i, j + 1) != 2 && search(i, j - 2) == 2 && search(i, j - 3) == 2 && search(i, j - 1) == 0 && search(i, j - 4) == 0)
			++mianthree2;
		if (search(i, j + 3) != 0 && search(i, j + 3) != 2 && search(i, j + 2) == 2 && search(i, j - 1) == 2 && search(i, j + 1) == 0 && search(i, j - 2) == 0)
			++mianthree2;
		if (search(i, j + 4) != 0 && search(i, j + 4) != 2 && search(i, j + 3) == 2 && search(i, j + 1) == 2 && search(i, j + 2) == 0 && search(i, j - 1) == 0)
			++mianthree2;
		// 4
		if (search(i, j + 1) == 2 && search(i, j + 4) == 2 && search(i, j + 2) == 0 && search(i, j + 3) == 0)
			++mianthree2;
		if (search(i, j - 1) == 2 && search(i, j + 3) == 2 && search(i, j + 1) == 0 && search(i, j + 2) == 0)
			++mianthree2;
		if (search(i, j - 4) == 2 && search(i, j - 3) == 2 && search(i, j - 2) == 0 && search(i, j - 1) == 0)
			++mianthree2;
		if (search(i, j - 1) == 2 && search(i, j - 4) == 2 && search(i - 2, j) == 0 && search(i, j - 3) == 0)
			++mianthree2;
		if (search(i, j + 1) == 2 && search(i, j - 3) == 2 && search(i, j - 1) == 0 && search(i, j - 2) == 0)
			++mianthree2;
		if (search(i, j + 4) == 2 && search(i, j + 3) == 2 && search(i, j + 2) == 0 && search(i, j + 1) == 0)
			++mianthree2;
		// 5
		if (search(i, j + 2) == 2 && search(i, j + 4) == 2 && search(i, j + 1) == 0 && search(i, j + 3) == 0)
			++mianthree2;
		if (search(i, j - 2) == 2 && search(i, j + 2) == 2 && search(i, j - 1) == 0 && search(i, j + 1) == 0)
			++mianthree2;
		if (search(i, j - 4) == 2 && search(i, j - 2) == 2 && search(i, j - 1) == 0 && search(i, j - 3) == 0)
			++mianthree2;
		// 斜1
		mianthree3 = 0;
		// 1
		if (search(i - 1, j - 1) != 0 && search(i - 1, j - 1) != 2 && search(i + 1, j + 1) == 2 && search(i + 2, j + 2) == 2 && search(i + 3, j + 3) == 0 && search(i + 4, j + 4) == 0)
			++mianthree3;
		if (search(i - 2, j - 2) != 0 && search(i - 2, j - 2) != 2 && search(i - 1, j - 1) == 2 && search(i + 1, j + 1) == 2 && search(i + 2, j + 2) == 0 && search(i + 3, j + 3) == 0)
			++mianthree3;
		if (search(i - 3, j - 3) != 0 && search(i - 3, j - 3) != 2 && search(i - 2, j - 2) == 2 && search(i - 1, j - 1) == 2 && search(i + 1, j + 1) == 0 && search(i + 2, j + 2) == 0)
			++mianthree3;
		if (search(i + 3, j + 3) != 0 && search(i + 3, j + 3) != 2 && search(i + 2, j + 2) == 2 && search(i + 1, j + 1) == 2 && search(i - 1, j - 1) == 0 && search(i - 2, j - 2) == 0)
			++mianthree3;
		if (search(i + 1, j + 1) != 0 && search(i + 1, j + 1) != 2 && search(i - 1, j - 1) == 2 && search(i - 2, j - 2) == 2 && search(i - 3, j - 3) == 0 && search(i - 4, j - 4) == 0)
			++mianthree3;
		if (search(i + 2, j + 2) != 0 && search(i + 2, j + 2) != 2 && search(i + 1, j + 1) == 2 && search(i - 1, j - 1) == 2 && search(i - 2, j - 2) == 0 && search(i - 3, j - 3) == 0)
			++mianthree3;
		// 2
		if (search(i - 1, j - 1) != 0 && search(i - 1, j - 1) != 2 && search(i + 1, j + 1) == 2 && search(i + 3, j + 3) == 2 && search(i + 2, j + 2) == 0 && search(i + 4, j + 4) == 0)
			++mianthree3;
		if (search(i - 2, j - 2) != 0 && search(i - 2, j - 2) != 2 && search(i - 1, j - 1) == 2 && search(i + 2, j + 2) == 2 && search(i + 1, j + 1) == 0 && search(i + 3, j + 3) == 0)
			++mianthree3;
		if (search(i - 4, j - 4) != 0 && search(i - 4, j - 4) != 2 && search(i - 3, j - 3) == 2 && search(i - 2, j - 2) == 2 && search(i - 1, j - 1) == 0 && search(i + 1, j + 1) == 0)
			++mianthree3;
		if (search(i + 1, j + 1) != 0 && search(i + 1, j + 1) != 2 && search(i - 1, j + 1) == 2 && search(i - 3, j - 3) == 2 && search(i - 2, j - 2) == 0 && search(i - 4, j - 4) == 0)
			++mianthree3;
		if (search(i + 2, j + 2) != 0 && search(i + 2, j + 2) != 2 && search(i + 1, j + 1) == 2 && search(i - 2, j - 2) == 2 && search(i - 1, j - 1) == 0 && search(i - 3, j - 3) == 0)
			++mianthree3;
		if (search(i + 4, j + 4) != 0 && search(i + 4, j + 4) != 2 && search(i + 3, j + 3) == 2 && search(i + 2, j + 2) == 2 && search(i + 1, j + 1) == 0 && search(i - 1, j - 1) == 0)
			++mianthree3;
		// 3
		if (search(i - 1, j - 1) != 0 && search(i - 1, j - 1) != 2 && search(i + 2, j + 2) == 2 && search(i + 3, j + 3) == 2 && search(i + 1, j + 1) == 0 && search(i + 4, j + 4) == 0)
			++mianthree3;
		if (search(i - 3, j - 3) != 0 && search(i - 3, j - 3) != 2 && search(i - 2, j - 3) == 2 && search(i + 1, j + 1) == 2 && search(i - 1, j - 1) == 0 && search(i + 2, j + 2) == 0)
			++mianthree3;
		if (search(i - 4, j - 4) != 0 && search(i - 4, j - 4) != 2 && search(i - 3, j - 3) == 2 && search(i - 1, j - 1) == 2 && search(i - 2, j - 2) == 0 && search(i + 1, j + 1) == 0)
			++mianthree3;
		if (search(i + 1, j + 1) != 0 && search(i + 1, j + 1) != 2 && search(i - 2, j - 2) == 2 && search(i - 3, j - 3) == 2 && search(i - 1, j - 1) == 0 && search(i - 4, j - 4) == 0)
			++mianthree3;
		if (search(i + 3, j + 3) != 0 && search(i + 3, j + 3) != 2 && search(i + 2, j + 2) == 2 && search(i - 1, j - 1) == 2 && search(i + 1, j + 1) == 0 && search(i - 2, j - 2) == 0)
			++mianthree3;
		if (search(i + 4, j + 4) != 0 && search(i + 4, j + 4) != 2 && search(i + 3, j + 3) == 2 && search(i + 1, j + 1) == 2 && search(i + 2, j + 2) == 0 && search(i - 1, j - 1) == 0)
			++mianthree3;
		// 4
		if (search(i + 1, j + 1) == 2 && search(i + 4, j + 4) == 2 && search(i + 2, j + 2) == 0 && search(i + 3, j + 3) == 0)
			++mianthree3;
		if (search(i - 1, j - 1) == 2 && search(i + 3, j + 3) == 2 && search(i + 1, j + 1) == 0 && search(i + 2, j + 2) == 0)
			++mianthree3;
		if (search(i - 4, j - 4) == 2 && search(i - 3, j - 3) == 2 && search(i - 2, j - 2) == 0 && search(i - 1, j - 1) == 0)
			++mianthree3;
		if (search(i - 1, j - 1) == 2 && search(i - 4, j - 4) == 2 && search(i - 2, j - 2) == 0 && search(i - 3, j - 3) == 0)
			++mianthree3;
		if (search(i + 1, j + 1) == 2 && search(i - 3, j - 3) == 2 && search(i - 1, j - 1) == 0 && search(i - 2, j - 2) == 0)
			++mianthree3;
		if (search(i + 4, j + 4) == 2 && search(i + 3, j + 3) == 2 && search(i + 2, j + 2) == 0 && search(i + 1, j + 1) == 0)
			++mianthree3;
		// 5
		if (search(i + 2, j + 2) == 2 && search(i + 4, j + 4) == 2 && search(i + 1, j + 1) == 0 && search(i + 3, j + 3) == 0)
			++mianthree3;
		if (search(i - 2, j - 2) == 2 && search(i + 2, j + 2) == 2 && search(i - 1, j - 1) == 0 && search(i + 1, j + 1) == 0)
			++mianthree3;
		if (search(i - 4, j - 4) == 2 && search(i - 2, j - 2) == 2 && search(i - 1, j - 1) == 0 && search(i - 3, j - 3) == 0)
			++mianthree3;
		// 斜2
		mianthree4 = 0;
		// 1
		if (search(i - 1, j + 1) != 0 && search(i - 1, j + 1) != 2 && search(i + 1, j - 1) == 2 && search(i + 2, j - 2) == 2 && search(i + 3, j - 3) == 0 && search(i + 4, j - 4) == 0)
			++mianthree4;
		if (search(i - 2, j + 2) != 0 && search(i - 2, j + 2) != 2 && search(i - 1, j + 1) == 2 && search(i + 1, j - 1) == 2 && search(i + 2, j - 2) == 0 && search(i + 3, j - 3) == 0)
			++mianthree4;
		if (search(i - 3, j + 3) != 0 && search(i - 3, j + 3) != 2 && search(i - 2, j + 2) == 2 && search(i - 1, j + 1) == 2 && search(i + 1, j - 1) == 0 && search(i + 2, j - 2) == 0)
			++mianthree4;
		if (search(i + 3, j - 3) != 0 && search(i + 3, j - 3) != 2 && search(i + 2, j - 2) == 2 && search(i + 1, j - 1) == 2 && search(i - 1, j + 1) == 0 && search(i - 2, j + 2) == 0)
			++mianthree4;
		if (search(i + 1, j - 1) != 0 && search(i + 1, j - 1) != 2 && search(i - 1, j + 1) == 2 && search(i - 2, j + 2) == 2 && search(i - 3, j + 3) == 0 && search(i - 4, j + 4) == 0)
			++mianthree4;
		if (search(i + 2, j - 2) != 0 && search(i + 2, j - 2) != 2 && search(i + 1, j - 1) == 2 && search(i - 1, j + 1) == 2 && search(i - 2, j + 2) == 0 && search(i - 3, j + 3) == 0)
			++mianthree4;
		// 2
		if (search(i - 1, j + 1) != 0 && search(i - 1, j + 1) != 2 && search(i + 1, j - 1) == 2 && search(i + 3, j - 3) == 2 && search(i + 2, j - 2) == 0 && search(i + 4, j - 4) == 0)
			++mianthree4;
		if (search(i - 2, j + 2) != 0 && search(i - 2, j + 2) != 2 && search(i - 1, j + 1) == 2 && search(i + 2, j - 2) == 2 && search(i + 1, j - 1) == 0 && search(i + 3, j - 3) == 0)
			++mianthree4;
		if (search(i - 4, j + 4) != 0 && search(i - 4, j + 4) != 2 && search(i - 3, j + 3) == 2 && search(i - 2, j + 2) == 2 && search(i - 1, j + 1) == 0 && search(i + 1, j - 1) == 0)
			++mianthree4;
		if (search(i + 1, j - 1) != 0 && search(i + 1, j - 1) != 2 && search(i - 1, j + 1) == 2 && search(i - 3, j + 3) == 2 && search(i - 2, j + 2) == 0 && search(i - 4, j + 4) == 0)
			++mianthree4;
		if (search(i + 2, j - 2) != 0 && search(i + 2, j - 2) != 2 && search(i + 1, j - 1) == 2 && search(i - 2, j + 2) == 2 && search(i - 1, j + 1) == 0 && search(i - 3, j + 3) == 0)
			++mianthree4;
		if (search(i + 4, j - 4) != 0 && search(i + 4, j - 4) != 2 && search(i + 3, j - 3) == 2 && search(i + 2, j - 2) == 2 && search(i + 1, j - 1) == 0 && search(i - 1, j + 1) == 0)
			++mianthree4;
		// 3
		if (search(i - 1, j + 1) != 0 && search(i - 1, j + 1) != 2 && search(i + 2, j - 2) == 2 && search(i + 3, j - 3) == 2 && search(i + 1, j - 1) == 0 && search(i + 4, j - 4) == 0)
			++mianthree4;
		if (search(i - 3, j + 3) != 0 && search(i - 3, j + 3) != 2 && search(i - 2, j + 3) == 2 && search(i + 1, j - 1) == 2 && search(i - 1, j + 1) == 0 && search(i + 2, j - 2) == 0)
			++mianthree4;
		if (search(i - 4, j + 4) != 0 && search(i - 4, j + 4) != 2 && search(i - 3, j + 3) == 2 && search(i - 1, j + 1) == 2 && search(i - 2, j + 2) == 0 && search(i + 1, j - 1) == 0)
			++mianthree4;
		if (search(i + 1, j - 1) != 0 && search(i + 1, j - 1) != 2 && search(i - 2, j + 2) == 2 && search(i - 3, j + 3) == 2 && search(i - 1, j + 1) == 0 && search(i - 4, j + 4) == 0)
			++mianthree4;
		if (search(i + 3, j - 3) != 0 && search(i + 3, j - 3) != 2 && search(i + 2, j - 2) == 2 && search(i - 1, j + 1) == 2 && search(i + 1, j - 1) == 0 && search(i - 2, j + 2) == 0)
			++mianthree4;
		if (search(i - 4, j - 4) != 0 && search(i + 4, j - 4) != 2 && search(i + 3, j - 3) == 2 && search(i + 1, j - 1) == 2 && search(i + 2, j - 2) == 0 && search(i - 1, j + 1) == 0)
			++mianthree4;
		// 4
		if (search(i + 1, j - 1) == 2 && search(i + 4, j - 4) == 2 && search(i + 2, j - 2) == 0 && search(i + 3, j - 3) == 0)
			++mianthree4;
		if (search(i - 1, j + 1) == 2 && search(i + 3, j - 3) == 2 && search(i + 1, j - 1) == 0 && search(i + 2, j - 2) == 0)
			++mianthree4;
		if (search(i - 4, j + 4) == 2 && search(i - 3, j + 3) == 2 && search(i - 2, j + 2) == 0 && search(i - 1, j + 1) == 0)
			++mianthree4;
		if (search(i - 1, j + 1) == 2 && search(i - 4, j + 4) == 2 && search(i - 2, j + 2) == 0 && search(i - 3, j + 3) == 0)
			++mianthree4;
		if (search(i + 1, j - 1) == 2 && search(i - 3, j + 3) == 2 && search(i - 1, j + 1) == 0 && search(i - 2, j + 2) == 0)
			++mianthree4;
		if (search(i + 4, j - 4) == 2 && search(i + 3, j - 3) == 2 && search(i + 2, j - 2) == 0 && search(i + 1, j - 1) == 0)
			++mianthree4;
		// 5
		if (search(i + 2, j - 2) == 2 && search(i + 4, j - 4) == 2 && search(i + 1, j - 1) == 0 && search(i + 3, j - 3) == 0)
			++mianthree4;
		if (search(i - 2, j + 2) == 2 && search(i + 2, j - 2) == 2 && search(i - 1, j + 1) == 0 && search(i + 1, j - 1) == 0)
			++mianthree4;
		if (search(i - 4, j + 4) == 2 && search(i - 2, j + 2) == 2 && search(i - 1, j + 1) == 0 && search(i - 3, j + 3) == 0)
			++mianthree4;
		// 跳四
		tiaofour = 0;
		// 竖
		tiaofour1 = 0;
		if (lian1 == 0)
		{
			if (search(i - 1, j) != 1 && search(i - 2, j) == 2 && search(i - 3, j) == 2 && search(i - 4, j) == 2 && search(i - 5, j) != 2)
				if (search(i - 1, j) == 0)
					++tiaofour1;
			if (search(i + 1, j) != 1 && search(i + 2, j) == 2 && search(i + 3, j) == 2 && search(i + 4, j) == 2 && search(i + 5, j) != 2)
				if (search(i + 1, j) == 0)
					++tiaofour1;
		}
		if (lian1 == 1)
		{
			if (search(i + 1, j) == 2)
			{
				if (search(i + 2, j) != 1 && search(i + 3, j) == 2 && search(i + 4, j) == 2 && search(i + 5, j) != 2)
					if (search(i + 2, j) == 0)
						++tiaofour1;
				if (search(i - 1, j) != 1 && search(i - 2, j) == 2 && search(i - 3, j) == 2 && search(i - 4, j) != 2)
					if (search(i - 1, j) == 0)
						++tiaofour1;
			}
			if (search(i - 1, j) == 2)
			{
				if (search(i - 2, j) != 1 && search(i - 3, j) == 2 && search(i - 4, j) == 2 && search(i - 5, j) != 2)
					if (search(i - 2, j) == 0)
						++tiaofour1;
				if (search(i + 1, j) != 1 && search(i + 2, j) == 2 && search(i + 3, j) == 2 && search(i + 4, j) != 2)
					if (search(i + 1, j) == 0)
						++tiaofour1;
			}
		}
		if (lian1 == 2)
		{
			if (search(i + 1, j) == 2 && search(i + 2, j) == 2 && search(i + 3, j) != 1 && search(i + 4, j) == 2 && search(i + 5, j) != 2)
				if (search(i + 3, j) == 0)
					++tiaofour1;
			if (search(i + 1, j) == 2 && search(i - 1, j) == 2 && search(i - 2, j) != 1 && search(i - 3, j) == 2 && search(i - 4, j) != 2)
				if (search(i + 2, j) == 0)
					++tiaofour1;
			if (search(i - 1, j) == 2 && search(i + 1, j) == 2 && search(i + 2, j) != 1 && search(i + 3, j) == 2 && search(i + 4, j) != 2)
				if (search(i - 2, j) == 0)
					++tiaofour1;
			if (search(i - 1, j) == 2 && search(i - 2, j) == 2 && search(i - 3, j) != 1 && search(i - 4, j) == 2 && search(i - 5, j) != 2)
				if (search(i - 3, j) == 0)
					++tiaofour1;
			if (search(i - 1, j) == 2 && search(i - 2, j) == 2 && search(i + 1, j) != 1 && search(i + 2, j) == 2 && search(i + 3, j) != 2)
				if (search(i + 1, j) == 0)
					++tiaofour1;
			if (search(i + 1, j) == 2 && search(i + 2, j) == 2 && search(i - 1, j) != 1 && search(i - 2, j) == 2 && search(i - 3, j) != 2)
				if (search(i - 1, j) == 0)
					++tiaofour1;
		}
		// 横
		tiaofour2 = 0;
		if (lian2 == 0)
		{
			if (search(i, j - 1) != 1 && search(i, j - 2) == 2 && search(i, j - 3) == 2 && search(i, j - 4) == 2 && search(i, j - 5) != 2)
				if (search(i, j - 1) == 0)
					++tiaofour2;
			if (search(i, j + 1) != 1 && search(i, j + 2) == 2 && search(i, j + 3) == 2 && search(i, j + 4) == 2 && search(i, j + 5) != 2)
				if (search(i, j + 1) == 0)
					++tiaofour2;
		}
		if (lian2 == 1)
		{
			if (search(i, j + 1) == 2)
			{
				if (search(i, j + 2) != 1 && search(i, j + 3) == 2 && search(i, j + 4) == 2 && search(i, j + 5) != 2)
					if (search(i, j + 2) == 0)
						++tiaofour2;
				if (search(i, j - 1) != 1 && search(i, j - 2) == 2 && search(i, j - 3) == 2 && search(i, j - 4) != 2)
					if (search(i, j - 1) == 0)
						++tiaofour2;
			}
			if (search(i, j - 1) == 2)
			{
				if (search(i, j - 2) != 1 && search(i, j - 3) == 2 && search(i, j - 4) == 2 && search(i, j - 5) != 2)
					if (search(i, j - 2) == 0)
						++tiaofour2;
				if (search(i, j + 1) != 1 && search(i, j + 2) == 2 && search(i, j + 3) == 2 && search(i, j + 4) != 2)
					if (search(i, j + 1) == 0)
						++tiaofour2;
			}
		}
		if (lian2 == 2)
		{
			if (search(i, j + 1) == 2 && search(i, j + 2) == 2 && search(i, j + 3) != 1 && search(i, j + 4) == 2 && search(i, j + 5) != 2)
				if (search(i, j + 3) == 0)
					++tiaofour2;
			if (search(i, j + 1) == 2 && search(i, j - 1) == 2 && search(i, j + 2) != 1 && search(i, j + 3) == 2 && search(i, j + 4) != 2)
				if (search(i, j + 2) == 0)
					++tiaofour2;
			if (search(i, j - 1) == 2 && search(i, j + 1) == 2 && search(i, j - 2) != 1 && search(i, j - 3) == 2 && search(i, j - 4) != 2)
				if (search(i, j - 2) == 0)
					++tiaofour2;
			if (search(i, j - 1) == 2 && search(i, j - 2) == 2 && search(i, j - 3) != 1 && search(i, j - 4) == 2 && search(i, j - 5) != 2)
				if (search(i, j - 3) == 0)
					++tiaofour2;
			if (search(i, j - 1) == 2 && search(i, j - 2) == 2 && search(i, j + 1) != 1 && search(i, j + 2) == 2 && search(i, j + 3) != 2)
				if (search(i, j + 1) == 0)
					++tiaofour2;
			if (search(i, j + 1) == 2 && search(i, j + 2) == 2 && search(i, j - 1) != 1 && search(i, j - 2) == 2 && search(i, j - 3) != 2)
				if (search(i, j - 1) == 0)
					++tiaofour2;
		}
		// 斜2
		tiaofour3 = 0;
		if (lian3 == 0)
		{
			if (search(i - 1, j - 1) != 1 && search(i - 2, j - 2) == 2 && search(i - 3, j - 3) == 2 && search(i - 4, j - 4) == 2 && search(i - 5, j - 5) != 2)
				if (search(i - 1, j - 1) == 0)
					++tiaofour3;
			if (search(i + 1, j + 1) != 1 && search(i + 2, j + 2) == 2 && search(i + 3, j + 3) == 2 && search(i + 4, j + 4) == 2 && search(i + 5, j + 5) != 2)
				if (search(i + 1, j + 1) == 0)
					++tiaofour3;
		}
		if (lian3 == 1)
		{
			if (search(i + 1, j + 1) == 2)
			{
				if (search(i + 2, j + 2) != 1 && search(i + 3, j + 3) == 2 && search(i + 4, j + 4) == 2 && search(i + 5, j + 5) != 2)
					if (search(i + 2, j + 2) == 0)
						++tiaofour3;
				if (search(i - 1, j - 1) != 1 && search(i - 2, j - 2) == 2 && search(i - 3, j - 3) == 2 && search(i - 4, j - 4) != 2)
					if (search(i - 1, j - 1) == 0)
						++tiaofour3;
			}
			if (search(i - 1, j - 1) == 2)
			{
				if (search(i - 2, j - 2) != 1 && search(i - 3, j - 3) == 2 && search(i - 4, j - 4) == 2 && search(i - 5, j - 5) != 2)
					if (search(i - 2, j - 2) == 0)
						++tiaofour3;
				if (search(i + 1, j + 1) != 1 && search(i + 2, j + 2) == 2 && search(i + 3, j + 3) == 2 && search(i + 4, j + 4) != 2)
					if (search(i + 1, j + 1) == 0)
						++tiaofour3;
			}
		}
		if (lian3 == 2)
		{
			if (search(i + 1, j + 1) == 2 && search(i + 2, j + 2) == 2 && search(i + 3, j + 3) != 1 && search(i + 4, j + 4) == 2 && search(i + 5, j + 5) != 2)
				if (search(i + 3, j + 3) == 0)
					++tiaofour3;
			if (search(i + 1, j + 1) == 2 && search(i - 1, j - 1) == 2 && search(i - 2, j - 2) != 1 && search(i - 3, j - 3) == 2 && search(i - 4, j - 4) != 2)
				if (search(i - 2, j - 2) == 0)
					++tiaofour3;
			if (search(i - 1, j - 1) == 2 && search(i + 1, j + 1) == 2 && search(i + 2, j + 2) != 1 && search(i + 3, j + 3) == 2 && search(i + 4, j + 4) != 2)
				if (search(i + 2, j + 2) == 0)
					++tiaofour3;
			if (search(i - 1, j - 1) == 2 && search(i - 2, j - 2) == 2 && search(i - 3, j - 3) != 1 && search(i - 4, j - 4) == 2 && search(i - 5, j - 5) != 2)
				if (search(i - 3, j - 3) == 0)
					++tiaofour3;
			if (search(i - 1, j - 1) == 2 && search(i - 2, j - 2) == 2 && search(i + 1, j + 1) != 1 && search(i + 2, j + 2) == 2 && search(i + 3, j + 3) != 2)
				if (search(i + 1, j + 1) == 0)
					++tiaofour3;
			if (search(i + 1, j + 1) == 2 && search(i + 2, j + 2) == 2 && search(i - 1, j - 1) != 1 && search(i - 2, j - 2) == 2 && search(i - 3, j - 3) != 2)
				if (search(i - 1, j - 1) == 0)
					++tiaofour3;
		}
		// 斜1
		tiaofour4 = 0;
		if (lian4 == 0)
		{
			if (search(i + 1, j - 1) != 1 && search(i + 2, j - 2) == 2 && search(i + 3, j - 3) == 2 && search(i + 4, j - 4) == 2 && search(i + 5, j - 5) != 2)
				if (search(i + 1, j - 1) == 0)
					++tiaofour4;
			if (search(i - 1, j + 1) != 1 && search(i - 2, j + 2) == 2 && search(i - 3, j + 3) == 2 && search(i - 4, j + 4) == 2 && search(i - 5, j + 5) != 2)
				if (search(i - 1, j + 1) == 0)
					++tiaofour4;
		}
		if (lian4 == 1)
		{
			if (search(i - 1, j + 1) == 2)
			{
				if (search(i - 2, j + 2) != 1 && search(i - 3, j + 3) == 2 && search(i - 4, j + 4) == 2 && search(i - 5, j + 5) != 2)
					if (search(i - 2, j + 2) == 0)
						++tiaofour4;
				if (search(i + 1, j - 1) != 1 && search(i + 2, j - 2) == 2 && search(i + 3, j - 3) == 2 && search(i + 4, j - 4) != 2)
					if (search(i + 1, j - 1) == 0)
						++tiaofour4;
			}
			if (search(i + 1, j - 1) == 2)
			{
				if (search(i + 2, j - 2) != 1 && search(i + 3, j - 3) == 2 && search(i + 4, j - 4) == 2 && search(i + 5, j - 5) != 2)
					if (search(i + 2, j - 2) == 0)
						++tiaofour4;
				if (search(i - 1, j + 1) != 1 && search(i - 2, j + 2) == 2 && search(i - 3, j + 3) == 2 && search(i - 4, j + 4) != 2)
					if (search(i - 1, j + 1) == 0)
						++tiaofour4;
			}
		}
		if (lian4 == 2)
		{
			if (search(i + 1, j - 1) == 2 && search(i + 2, j - 2) == 2 && search(i + 3, j - 3) != 1 && search(i + 4, j - 4) == 2 && search(i + 5, j - 5) != 2)
				if (search(i + 3, j - 3) == 0)
					++tiaofour4;
			if (search(i + 1, j - 1) == 2 && search(i - 1, j + 1) == 2 && search(i - 2, j + 2) != 1 && search(i - 3, j + 3) == 2 && search(i - 4, j + 4) != 2)
				if (search(i - 2, j + 2) == 0)
					++tiaofour4;
			if (search(i - 1, j + 1) == 2 && search(i + 1, j - 1) == 2 && search(i + 2, j - 2) != 1 && search(i + 3, j - 3) == 2 && search(i + 4, j - 4) != 2)
				if (search(i + 2, j - 2) == 0)
					++tiaofour4;
			if (search(i - 1, j + 1) == 2 && search(i - 2, j + 2) == 2 && search(i - 3, j + 3) != 1 && search(i - 4, j + 4) == 2 && search(i - 5, j + 5) != 2)
				if (search(i - 3, j + 3) == 0)
					++tiaofour4;
			if (search(i - 1, j + 1) == 2 && search(i - 2, j + 2) == 2 && search(i + 1, j - 1) != 1 && search(i + 2, j - 2) == 2 && search(i + 3, j - 3) != 2)
				if (search(i + 1, j - 1) == 0)
					++tiaofour4;
			if (search(i + 1, j - 1) == 2 && search(i + 2, j - 2) == 2 && search(i - 1, j + 1) != 1 && search(i - 2, j + 2) == 2 && search(i - 3, j + 3) != 2)
				if (search(i - 1, j + 1) == 0)
					++tiaofour4;
		}
		tiaofour = tiaofour1 + tiaofour2 + tiaofour3 + tiaofour4;
		// 计算分数
		// 五连
		if (lian1 >= 4)
			value += WULIAN;
		if (lian2 >= 4)
			value += WULIAN;
		if (lian3 >= 4)
			value += WULIAN;
		if (lian4 >= 4)
			value += WULIAN;
		// 活四
		if (lian1 == 3 && huo1 == 0)
			value += HUOSI;
		if (lian2 == 3 && huo2 == 0)
			value += HUOSI;
		if (lian3 == 3 && huo3 == 0)
			value += HUOSI;
		if (lian4 == 3 && huo4 == 0)
			value += HUOSI;
		// 连四
		if (lian1 == 3 && huo1 == 1)
			value += LIANSI;
		if (lian2 == 3 && huo2 == 1)
			value += LIANSI;
		if (lian3 == 3 && huo3 == 1)
			value += LIANSI;
		if (lian4 == 3 && huo4 == 1)
			value += LIANSI;
		// 跳四
		value += tiaofour * TIAOSI;
		// 活三
		if (lian1 == 2 && fakethree1 == 1)
			value += LIANHUOSAN;
		if (lian2 == 2 && fakethree2 == 1)
			value += LIANHUOSAN;
		if (lian3 == 2 && fakethree3 == 1)
			value += LIANHUOSAN;
		if (lian4 == 2 && fakethree4 == 1)
			value += LIANHUOSAN;
		// 假活三
		if (lian1 == 2 && fakethree1 == 2)
			value += JIAHUOSAN;
		if (lian2 == 2 && fakethree2 == 2)
			value += JIAHUOSAN;
		if (lian3 == 2 && fakethree3 == 2)
			value += JIAHUOSAN;
		if (lian4 == 2 && fakethree4 == 2)
			value += JIAHUOSAN;
		// 跳三
		if (tiaothree1 > 0)
			value += TIAOHUOSAN;
		if (tiaothree2 > 0)
			value += TIAOHUOSAN;
		if (tiaothree3 > 0)
			value += TIAOHUOSAN;
		if (tiaothree4 > 0)
			value += TIAOHUOSAN;
		// 冲三
		if (mianthree1 > 0)
			value += mianthree1 * MIANSAN;
		if (mianthree2 > 0)
			value += mianthree2 * MIANSAN;
		if (mianthree3 > 0)
			value += mianthree3 * MIANSAN;
		if (mianthree4 > 0)
			value += mianthree4 * MIANSAN;
		// 活二
		if (huotwo1 > 0)
			value += huotwo1 * HUOER;
		if (huotwo2 > 0)
			value += huotwo2 * HUOER;
		if (huotwo3 > 0)
			value += huotwo3 * HUOER;
		if (huotwo4 > 0)
			value += huotwo4 * HUOER;
		// 冲二
		if (miantwo1 > 0)
			value += miantwo1 * MIANER;
		if (miantwo2 > 0)
			value += miantwo2 * MIANER;
		if (miantwo3 > 0)
			value += miantwo3 * MIANER;
		if (miantwo4 > 0)
			value += miantwo4 * MIANER;
		return value; // 返回分数
	}
	return 0;
}