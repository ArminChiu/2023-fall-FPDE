#include "fir.h"
/*对一个点判断完所有禁手情况后，方可确认没有触发禁手
基本禁手：长连、三三、四四。
组合禁手：（三三）活四、冲四。（四四）活三。*/

//心中数组声明
extern int arrayForInnerBoardLayout[SIZE][SIZE];
// 函数声明
//第一层禁手判断(第25行开始)
int changlian(int x, int y);      // 长连
int sisi(int x, int y);           // 四四
int sansan(int x, int y);         // 三三
int huosi(int n, int x, int y);   // 活四
int chongsi(int n, int x, int y); // 冲四
int huosan(int n, int x, int y);  // 活三
//第二层复杂禁手判断(第825行开始)
int finalban(int x, int y);            // 第二层判断函数
int finalchanglian(int x, int y);      // 长连
int finalsisi(int x, int y);           // 四四
int finalsansan(int x, int y);         // 三三
int finalhuosi(int n, int x, int y);   // 活四
int finalchongsi(int n, int x, int y); // 冲四
int finalhuosan(int n, int x, int y);  // 活三

int ban(int x, int y)
{ // 返回值为1时触发禁手，数组中1为先手黑子，2为后手白子
    int orig = arrayForInnerBoardLayout[x][y];
    arrayForInnerBoardLayout[x][y] = 1; // 判断时还未落子，先落上再进行判断
    if (changlian(x, y) == 1)
    {
        arrayForInnerBoardLayout[x][y] = orig;
        return 1;
    }
    if (sansan(x, y) == 1)
    {
        arrayForInnerBoardLayout[x][y] = orig;
        return 1;
    }
    if (sisi(x, y) == 1)
    {
        arrayForInnerBoardLayout[x][y] = orig;
        return 1;
    }
    arrayForInnerBoardLayout[x][y] = orig;
    return 0;
}

// 判断长连
int changlian(int x, int y)
{
    int side1, side2;
    // 横
    for (side1 = 1; search(x - side1, y) == 1; side1++)
        ;
    for (side2 = 1; search(x + side2, y) == 1; side2++)
        ;
    if (side1 + side2 >= 7)
        return 1;
    // 竖
    for (side1 = 1; search(x, y - side1) == 1; side1++)
        ;
    for (side2 = 1; y + side2 < 15 && search(x, y + side2) == 1; side2++)
        ;
    if (side1 + side2 >= 7)
        return 1;
    // 左斜
    for (side1 = 1; search(x + side1, y - side1) == 1; side1++)
        ;
    for (side2 = 1; search(x - side2, y + side2) == 1; side2++)
        ;
    if (side1 + side2 >= 7)
        return 1;
    // 右斜
    for (side1 = 1; search(x - side1, y - side1) == 1; side1++)
        ;
    for (side2 = 1; search(x + side2, y + side2) == 1; side2++)
        ;
    if (side1 + side2 >= 7)
        return 1;
    return 0;
}

// 判断四四
int sisi(int x, int y)
{
    int sum = 0;
    for (int side = 1; side < 5; side++)
    {
        sum += chongsi(side, x, y);
        sum += huosi(side, x, y);
    }
    if (sum >= 2)
        return 1;
    return 0;
}

// 判断三三
int sansan(int x, int y)
{
    int sum = 0;
    for (int side = 1; side < 5; side++)
        sum += huosan(side, x, y);
    if (sum >= 2)
        return 1;
    return 0;
}

// 判断活四
int huosi(int n, int x, int y)
{
    if (search(x, y) == 2)
        return 0;
    int i = 1;
    int j = 1;
    int side1, side2;
    int flag = 0;
    if (search(x, y) != 1)
        flag = 1;
    arrayForInnerBoardLayout[x][y] = 1;
    if (n == 1)
    {
        while (y - i >= 0 && search(x, y - i) == 1)
            i++;
        while (y + j <= 14 && search(x, y + j) == 1)
            j++;
        side1 = y - i + 1;
        side2 = y + j - 1;
        if (i + j != 5)
        {
            if (flag == 1)
                arrayForInnerBoardLayout[x][y] = 0;
            return 0;
        }
        if (i + j == 5)
        {
            if ((side1 - 1 >= 0 && search(x, side1 - 1) == 0 && (!(finalban(x, side1 - 1) == 1))) && (side2 + 1 <= 14 && search(x, side2 + 1) == 0 && (!(finalban(x, side2 + 1) == 1))))
            {
                if (flag == 1)
                    arrayForInnerBoardLayout[x][y] = 0;
                return 1;
            }
        }
    }
    if (n == 2)
    {
        while (x - i >= 0 && search(x - i, y) == 1)
            i++;
        while (y + j <= 14 && search(x + j, y) == 1)
            j++;
        if (i + j != 5)
        {
            if (flag == 1)
                arrayForInnerBoardLayout[x][y] = 0;
            return 0;
        }
        side1 = x - i + 1;
        side2 = x + j - 1;
        if (i + j == 5)
        {
            if ((side1 - 1 >= 0 && search(side1 - 1, y) == 0 && (!(finalban(side1 - 1, y) == 1))) && (side2 + 1 <= 14 && search(side2 + 1, y) == 0 && (!(finalban(side2 + 1, y) == 1))))
            {
                if (flag == 1)
                    arrayForInnerBoardLayout[x][y] = 0;
                return 1;
            }
        }
    }
    int side1_x, side1_y, side2_x, side2_y;
    if (n == 3)
    {
        while (y - i >= 0 && x - i >= 0 && search(x - i, y - i) == 1)
            i++;
        while (y + j <= 14 && x + j <= 14 && search(x + j, y + j) == 1)
            j++;
        side1_x = x - i + 1;
        side2_x = x + j - 1;
        side1_y = y - i + 1;
        side2_y = y + j - 1;
        if (i + j != 5)
        {
            if (flag == 1)
                arrayForInnerBoardLayout[x][y] = 0;
            return 0;
        }
        if (i + j == 5)
        {
            if ((side1_x - 1 >= 0 && side1_y - 1 >= 0 && search(side1_x - 1, side1_y - 1) == 0 && (!(finalban(side1_x - 1, side1_y - 1) == 1))) &&
                (side2_x + 1 <= 14 && side2_y + 1 <= 14 && search(side2_x + 1, side2_y + 1) == 0 && (!(finalban(side2_x + 1, side2_y + 1) == 1))))
            {
                if (flag == 1)
                    arrayForInnerBoardLayout[x][y] = 0;
                return 1;
            }
        }
    }
    if (n == 4)
    {
        while (y - i >= 0 && x + i <= 14 && search(x + i, y - i) == 1)
        {
            i++;
        }
        while (y + j <= 14 && x - j >= 0 && search(x - j, y + j) == 1)
        {
            j++;
        }
        side1_x = x + i - 1;
        side2_x = x - j + 1;
        side1_y = y - i + 1;
        side2_y = y + j - 1;
        if (i + j != 5)
        {
            if (flag == 1)
                arrayForInnerBoardLayout[x][y] = 0;
            return 0;
        }
        if (i + j == 5)
        {
            if ((side1_x + 1 <= 14 && side1_y - 1 >= 0 && search(side1_x + 1, side1_y - 1) == 0 && (!(finalban(side1_x + 1, side1_y - 1) == 1))) &&
                (side2_x - 1 >= 0 && side2_y + 1 <= 14 && search(side2_x - 1, side2_y + 1) == 0 && (!(finalban(side2_x - 1, side2_y + 1) == 1))))
            {
                if (flag == 1)
                    arrayForInnerBoardLayout[x][y] = 0;
                return 1;
            }
        }
    }
    if (flag == 1)
        arrayForInnerBoardLayout[x][y] = 0;
    return 0;
}

// 判断冲四
int chongsi(int n, int x, int y)
{
    if (search(x, y) == 2)
        return 0;
    int i = 1;
    int j = 1;
    int side1, side2;
    int flag = 0;
    if (search(x, y) != 1)
    {
        flag = 1;
    }
    arrayForInnerBoardLayout[x][y] = 1;
    int count = 0;
    if (n == 1)
    {
        while (y - i >= 0 && search(x, y - i) == 1)
            i++;
        while (y + j <= 14 && search(x, y + j) == 1)
            j++;
        side1 = y - i + 1;
        side2 = y + j - 1;
        if (i + j == 2)
        {
            if (side1 - 4 >= 0 && search(x, side1 - 2) == 1 && search(x, side1 - 3) == 1 && search(x, side1 - 4) == 1 && search(x, side1 - 1) == 0)
            {
                if (!finalban(x, side1 - 1))
                    count++;
            }
            if (side2 + 4 <= 14 && search(x, side2 + 2) == 1 && search(x, side2 + 3) == 1 && search(x, side2 + 4) == 1 && search(x, side2 + 1) == 0)
            {
                if (!finalban(x, side2 + 1))
                    count++;
            }
            if (count != 0)
            {
                if (flag == 1)
                    arrayForInnerBoardLayout[x][y] = 0;
                return count;
            }
        }
        if (i + j == 3)
        {
            if (side1 - 3 >= 0 && search(x, side1 - 3) == 1 && search(x, side1 - 2) == 1 && search(x, side1 - 1) == 0)
            {
                if (!finalban(x, side1 - 1))
                    count++;
            }
            if (side2 + 3 <= 14 && search(x, side2 + 3) == 1 && search(x, side2 + 2) == 1 && search(x, side2 + 1) == 0)
            {
                if (!finalban(x, side2 + 1))
                    count++;
            }
            if (count != 0)
            {
                if (flag == 1)
                    arrayForInnerBoardLayout[x][y] = 0;
                return count;
            }
        }
        if (i + j == 4)
        {
            if (side1 - 2 >= 0 && search(x, side1 - 2) == 1 && search(x, side1 - 1) == 0)
            {
                if (!finalban(x, side1 - 1))
                    count++;
            }
            if (side2 + 2 <= 14 && search(x, side2 + 2) == 1 && search(x, side2 + 1) == 0)
            {
                if (!finalban(x, side2 + 1))
                    count++;
            }
            if (count != 0)
            {
                if (flag == 1)
                    arrayForInnerBoardLayout[x][y] = 0;
                return count;
            }
        }
        if (i + j == 5)
        {
            if ((side1 - 1 >= 0 && search(x, side1 - 1) == 0 && !(finalban(x, side1 - 1) == 1)) ^ (side2 + 1 <= 14 && search(x, side2 + 1) == 0 && !(finalban(x, side2 + 1) == 1)))
            {
                if (flag == 1)
                    arrayForInnerBoardLayout[x][y] = 0;
                return 1;
            }
        }
        if (flag == 1)
        {
            arrayForInnerBoardLayout[x][y] = 0;
        }
        return 0;
    }
    if (n == 2)
    {
        while (x - i >= 0 && search(x - i, y) == 1)
            i++;
        while (x + j <= 14 && search(x + j, y) == 1)
            j++;
        side1 = x - i + 1;
        side2 = x + j - 1;
        if (i + j == 2)
        {
            if (side1 - 4 >= 0 && search(side1 - 2, y) == 1 && search(side1 - 3, y) == 1 && search(side1 - 4, y) == 1 && search(side1 - 1, y) == 0)
            {
                if (!finalban(side1 - 1, y))
                    count++;
            }
            if (side2 + 4 <= 14 && search(side2 + 2, y) == 1 && search(side2 + 3, y) == 1 && search(side2 + 4, y) == 1 && search(side2 + 1, y) == 0)
            {
                if (!finalban(side2 + 1, y))
                    count++;
            }
            if (count != 0)
            {
                if (flag == 1)
                    arrayForInnerBoardLayout[x][y] = 0;
                return count;
            }
            count = 0;
        }
        if (i + j == 3)
        {
            if (side1 - 3 >= 0 && search(side1 - 3, y) == 1 && search(side1 - 2, y) == 1 && search(side1 - 1, y) == 0)
            {
                if (!finalban(side1 - 1, y))
                    count++;
            }
            if (side2++ <= 14 && search(side2 + 3, y) == 1 && search(side2 + 2, y) && search(side2 + 1, y) == 0)
            {
                if (!finalban(side2 + 1, y))
                    count++;
            }
            if (count != 0)
            {
                if (flag == 1)
                    arrayForInnerBoardLayout[x][y] = 0;
                return count;
            }
            count = 0;
        }
        if (i + j == 4)
        {
            if (side1 - 2 >= 0 && search(side1 - 2, y) == 1 && search(side1 - 1, y) == 0)
            {
                if (!finalban(side1 - 1, y))
                    count++;
            }
            if (side2 + 2 <= 14 && search(side2 + 2, y) == 1 && search(side2 + 1, y) == 0)
            {
                if (!finalban(side2 + 1, y))
                    count++;
            }
            if (count != 0)
            {
                if (flag == 1)
                    arrayForInnerBoardLayout[x][y] = 0;
                return count;
            }
            count = 0;
        }
        if (i + j == 5)
        {
            if ((side1 - 1 >= 0 && search(side1 - 1, y) == 0 && !(finalban(side1 - 1, y) == 1)) ^
                (side2 + 1 <= 14 && search(side2 + 1, y) == 0 && !(finalban(side2 + 1, y) == 1)))
            {
                if (flag == 1)
                    arrayForInnerBoardLayout[x][y] = 0;
                return 1;
            }
        }
        if (flag == 1)
        {
            arrayForInnerBoardLayout[x][y] = 0;
        }
        return 0;
    }
    int side1_x, side1_y, side2_x, side2_y;
    if (n == 3)
    {
        while (x - i >= 0 && y - i >= 0 && search(x - i, y - i) == 1)
            i++;
        while (x + j <= 14 && y + j <= 14 && search(x + j, y + j) == 1)
            j++;
        side1_x = x - i + 1;
        side2_x = x + j - 1;
        side1_y = y - i + 1;
        side2_y = y + j - 1;
        if (i + j == 2)
        {
            if (side1_x - 4 >= 0 && side1_y - 4 >= 0 && search(side1_x - 2, side1_y - 2) == 1 && search(side1_x - 3, side1_y - 3) == 1 &&
                search(side1_x - 4, side1_y - 4) == 1 && search(side1_x - 1, side1_y - 1) == 0)
            {
                if (!finalban(side1_x - 1, side1_y - 1))
                    count++;
            }
            if (side2_x + 4 <= 14 && side2_y + 4 <= 14 && search(side2_x + 2, side2_y + 2) == 1 && search(side2_x + 3, side2_y + 3) == 1 &&
                search(side2_x + 4, side2_y + 4) == 1 && search(side2_x + 1, side2_y + 1) == 0)
            {
                if (!finalban(side2_x + 1, side2_y + 1))
                    count++;
            }
            if (count != 0)
            {
                if (flag == 1)
                    arrayForInnerBoardLayout[x][y] = 0;
                return count;
            }
            count = 0;
        }
        if (i + j == 3)
        {
            if (side1_x - 3 >= 0 && side1_y - 3 >= 0 && search(side1_x - 3, side1_y - 3) == 1 && search(side1_x - 2, side1_y - 2) == 1 && search(side1_x - 1, side1_y - 1) == 0)
            {
                if (!finalban(side1_x - 1, side1_y - 1))
                    count++;
            }
            if (side2_x + 3 <= 14 && side2_y + 3 <= 14 && search(side2_x + 3, side2_y + 3) == 1 && search(side2_x + 2, side2_y + 2) && search(side2_x + 1, side2_y + 1) == 0)
            {
                if (!finalban(side2_x + 1, side2_y + 1))
                    count++;
            }
            if (count != 0)
            {
                if (flag == 1)
                    arrayForInnerBoardLayout[x][y] = 0;
                return count;
            }
            count = 0;
        }
        if (i + j == 4)
        {
            if (side1_x - 2 >= 0 && side1_y - 2 >= 0 && search(side1_x - 2, side1_y - 2) == 1 && search(side1_x - 1, side1_y - 1) == 0)
            {
                if (!finalban(side1_x - 1, side1_y - 1))
                    count++;
            }
            if (side2_x + 2 <= 14 && side2_y + 2 <= 14 && search(side2_x + 2, side2_y + 2) == 1 && search(side2_x + 1, side2_y + 1) == 0)
            {
                if (!finalban(side2_x + 1, side2_y + 1))
                    count++;
            }
            if (count != 0)
            {
                if (flag == 1)
                    arrayForInnerBoardLayout[x][y] = 0;
                return count;
            }
            count = 0;
        }
        if (i + j == 5)
        {
            if ((side1_x - 1 >= 0 && side1_y - 1 >= 0 && search(side1_x - 1, side1_y - 1) == 0 && !(finalban(side1_x - 1, side1_y - 1) == 1)) ^
                (side2_x + 1 <= 14 && side2_y + 1 <= 14 && search(side2_x + 1, side2_y + 1) == 0 && !(finalban(side2_x + 1, side2_y + 1) == 1)))
            {
                if (flag == 1)
                    arrayForInnerBoardLayout[x][y] = 0;
                return 1;
            }
        }
        if (flag == 1)
            arrayForInnerBoardLayout[x][y] = 0;
        return 0;
    }
    if (n == 4)
    {
        while (x + i <= 14 && y - i >= 0 && search(x + i, y - i) == 1)
            i++;
        while (x - j >= 0 && y + j <= 14 && search(x - j, y + j) == 1)
            j++;
        side1_x = x + i - 1;
        side2_x = x - j + 1;
        side1_y = y - i + 1;
        side2_y = y + j - 1;
        if (i + j == 2)
        {
            if (side1_x + 4 <= 14 && side1_y - 4 >= 0 && search(side1_x + 2, side1_y - 2) == 1 && search(side1_x + 3, side1_y - 3) == 1 && search(side1_x + 4, side1_y - 4) == 1 && search(side1_x + 1, side1_y - 1) == 0)
            {
                if (!finalban(side1_x + 1, side1_y - 1))
                    count++;
            }
            if (side2_x - 4 >= 0 && side2_y + 4 <= 14 && search(side2_x - 2, side2_y + 2) == 1 && search(side2_x - 3, side2_y + 3) == 1 && search(side2_x - 4, side2_y + 4) == 1 && search(side2_x - 1, side2_y + 1) == 0)
            {
                if (!finalban(side2_x - 1, side2_y + 1))
                    count++;
            }
            if (count != 0)
            {
                if (flag == 1)
                    arrayForInnerBoardLayout[x][y] = 0;
                return count;
            }
            count = 0;
        }
        if (i + j == 3)
        {
            if (side1_x + 3 <= 0 && side1_y - 3 >= 0 && search(side1_x + 3, side1_y - 3) == 1 && search(side1_x + 2, side1_y - 2) == 1 && search(side1_x + 1, side1_y - 1) == 0)
            {
                if (!finalban(side1_x + 1, side1_y - 1))
                    count++;
            }
            if (side2_x - 3 >= 0 && side2_y + 3 <= 14 && search(side2_x - 3, side2_y + 3) == 1 && search(side2_x - 2, side2_y + 2) && search(side2_x - 1, side2_y + 1) == 0)
            {
                if (!finalban(side2_x - 1, side2_y + 1))
                    count++;
            }
            if (count != 0)
            {
                if (flag == 1)
                    arrayForInnerBoardLayout[x][y] = 0;
                return count;
            }
            count = 0;
        }
        if (i + j == 4)
        {
            if (side1_x + 2 >= 0 && side1_y - 2 >= 0 && search(side1_x + 2, side1_y - 2) == 1 && search(side1_x + 1, side1_y - 1) == 0)
            {
                if (!finalban(side1_x + 1, side1_y - 1))
                    count++;
            }
            if (side2_x - 2 >= 0 && side2_y + 2 <= 14 && search(side2_x - 2, side2_y + 2) == 1 && search(side2_x - 1, side2_y + 1) == 0)
            {
                if (!finalban(side2_x - 1, side2_y + 1))
                    count++;
            }
            if (count != 0)
            {
                if (flag == 1)
                    arrayForInnerBoardLayout[x][y] = 0;
                return count;
            }
            count = 0;
        }
        if (i + j == 5)
        {
            if ((side1_x + 1 <= 14 && side1_y - 1 >= 0 && search(side1_x + 1, side1_y - 1) == 0 && !(finalban(side1_x + 1, side1_y - 1) == 1)) ^
                (side2_x - 1 >= 0 && side2_y + 1 <= 14 && search(side2_x - 1, side2_y + 1) == 0 && !(finalban(side2_x - 1, side2_y + 1) == 1)))
            {
                if (flag == 1)
                    arrayForInnerBoardLayout[x][y] = 0;
                return 1;
            }
        }
        if (flag == 1)
            arrayForInnerBoardLayout[x][y] = 0;
        return 0;
    }
    if (flag == 1)
        arrayForInnerBoardLayout[x][y] = 0;
    return 0;
}

// 判断活三
int huosan(int n, int x, int y)
{
    int i;
    int j;
    int side1, side2;
    // 活三棋型 011010(和镜像) or 01110
    if (n == 1)
    {
        i = 1;
        j = 1;
        while (y - i >= 0 && search(x, y - i) == 1)
            i++;
        while (y + j <= 14 && search(x, y + j) == 1)
            j++;
        side1 = y - i + 1;
        side2 = y + j - 1;
        if (i + j == 4)
        {
            if ((side1 - 1 >= 0 && huosi(x, side1 - 1, n)) || (side2 + 1 <= 14 && huosi(x, side2 + 1, n)))
                return 1;
        }
        else if (i + j == 2)
        {
            if (y - 1 >= 0 && y + 1 <= 14 && search(x, y - 1) == 0 && search(x, y + 1) == 0)
            {
                if (y - 4 >= 0 && search(x, y - 3) == 1 && search(x, y - 2) == 1 && search(x, y - 4) == 0)
                {
                    if (huosi(n, x, y - 1) == 1)
                    {
                        return 1;
                    }
                }
                if (y + 4 <= 14 && search(x, y + 3) == 1 && search(x, y + 2) == 1 && search(x, y + 4) == 0)
                {
                    if (huosi(n, x, y + 1) == 1)
                    {
                        return 1;
                    }
                }
            }
        }
        else if (i + j == 3)
        {
            if (side1 - 1 >= 0 && side2 + 1 <= 14 && search(x, side1 - 1) == 0 && search(x, side2 + 1) == 0)
            {
                if (side1 - 3 >= 0 && search(x, side1 - 3) == 0 && search(x, side1 - 2) == 1)
                {
                    if (huosi(n, x, side1 - 1))
                    {
                        return 1;
                    }
                }
                if (side2 + 3 >= 0 && search(x, side2 + 3) == 0 && search(x, side2 + 2) == 1)
                {
                    if (huosi(n, x, side2 + 1))
                    {
                        return 1;
                    }
                }
            }
        }
    }
    if (n == 2)
    {
        i = 1;
        j = 1;
        while (x - i >= 0 && search(x - i, y) == 1)
            i++;
        while (x + j <= 14 && search(x + j, y) == 1)
            j++;
        side1 = x - i + 1;
        side2 = x + j - 1;
        if (i + j == 4)
        {
            if ((side1 - 1 >= 0 && huosi(n, side1 - 1, y)) || (side2 + 1 <= 14 && huosi(n, side2 + 1, y)))
            {
                return 1;
            }
        }
        else if (i + j == 2)
        {
            if (x - 1 >= 0 && x + 1 <= 14 && search(x - 1, y) == 0 && search(x + 1, y) == 0)
            {
                if (x - 4 >= 0 && search(x - 3, y) == 1 && search(x - 2, y) == 1 && search(x - 4, y) == 0)
                {
                    if (huosi(n, x - 1, y) == 1)
                        return 1;
                }
                if (x + 4 <= 14 && search(x + 3, y) == 1 && search(x + 2, y) == 1 && search(x + 4, y) == 0)
                {
                    if (huosi(n, x + 1, y) == 1)
                        return 1;
                }
            }
        }
        else if (i + j == 3)
        {
            if (side1 - 1 >= 0 && side2 + 1 <= 14 && search(side1 - 1, y) == 0 && search(side2 + 1, y) == 0)
            {
                if (side1 - 3 >= 0 && search(side1 - 3, y) == 0 && search(side1 - 2, y) == 1)
                {
                    if (huosi(n, side1 - 1, y))
                        return 1;
                }
                if (side2 + 3 >= 0 && search(side2 + 3, y) == 0 && search(side2 + 2, y) == 1)
                {
                    if (huosi(n, side2 + 1, y))
                        return 1;
                }
            }
        }
    }
    if (n == 3)
    {
        i = 1;
        j = 1;
        int side1_x, side1_y, side2_x, side2_y;
        while (y - i >= 0 && x - i >= 0 && search(x - i, y - i) == 1)
            i++;
        while (y + j <= 14 && x + j <= 14 && search(x + j, y + j) == 1)
            j++;
        side1_x = x - i + 1;
        side2_x = x + j - 1;
        side1_y = y - i + 1;
        side2_y = y + j - 1;
        if (i + j == 4)
        {
            if ((side1_x - 1 >= 0 && side1_y - 1 >= 0 && huosi(n, side1_x - 1, side1_y - 1)) || (side2_x + 1 <= 14 && side2_y + 1 <= 14 && huosi(n, side2_x + 1, side2_y + 1)))
            {
                return 1;
            }
        }
        else if (i + j == 2)
        {
            if (y - 1 >= 0 && x - 1 >= 0 && y + 1 <= 14 && x + 1 <= 14 && search(x - 1, y - 1) == 0 && search(x + 1, y + 1) == 0)
            {
                if (y - 4 >= 0 && x - 4 >= 0 && search(x - 3, y - 3) == 1 && search(x - 2, y - 2) == 1 && search(x - 4, y - 4) == 0)
                {
                    if (huosi(n, x - 1, y - 1) == 1)
                        return 1;
                }
                if (y + 4 <= 14 && x + 4 <= 14 && search(x + 3, y + 3) == 1 && search(x + 2, y + 2) == 1 && search(x + 4, y + 4) == 0)
                {
                    if (huosi(n, x + 1, y + 1) == 1)
                        return 1;
                }
            }
        }
        else if (i + j == 3)
        {
            if (side1_x - 1 >= 0 && side1_y - 1 >= 0 && side2_x + 1 <= 14 && side2_y + 1 <= 14 && search(side1_x - 1, side1_y - 1) == 0 && search(side2_x + 1, side2_y + 1) == 0)
            {
                if (side1_x - 3 >= 0 && side1_y - 3 >= 0 && search(side1_x - 3, side1_y - 3) == 0 && search(side1_x - 2, side1_y - 2) == 1)
                {
                    if (huosi(n, side1_x - 1, side1_y - 1))
                    {
                        return 1;
                    }
                }
                if (side2_x + 3 >= 0 && side2_y + 3 >= 0 && search(side2_x + 3, side2_y + 3) == 0 && search(side2_x + 2, side2_y + 2) == 1)
                {
                    if (huosi(n, side2_x + 1, side2_y + 1))
                    {
                        return 1;
                    }
                }
            }
        }
    }
    if (n == 4)
    {
        i = 1;
        j = 1;
        int side1_x, side1_y, side2_x, side2_y;
        while (y - i >= 0 && x + i <= 14 && search(x + i, y - i) == 1)
        {
            i++;
        }
        while (y + j <= 14 && x - j >= 0 && search(x - j, y + j) == 1)
        {
            j++;
        }
        side1_x = x + i - 1;
        side2_x = x - j + 1;
        side1_y = y - i + 1;
        side2_y = y + j - 1;
        if (i + j == 4)
        {
            if ((side1_x + 1 <= 14 && side1_y - 1 >= 0 && huosi(n, side1_x + 1, side1_y - 1)) || (side2_x - 1 >= 0 && side2_y <= 14 && huosi(n, side2_x - 1, side2_y + 1)))
            {
                return 1;
            }
        }
        else if (i + j == 2)
        {
            if (y - 1 >= 0 && x + 1 <= 14 && y + 1 <= 14 && x - 1 >= 0 && search(x + 1, y - 1) == 0 && search(x - 1, y + 1) == 0)
            {
                if (y - 4 >= 0 && x + 4 <= 14 && search(x + 3, y - 3) == 1 && search(x + 2, y - 2) == 1 && search(x + 4, y - 4) == 0)
                {
                    if (huosi(n, x + 1, y - 1) == 1)
                    {
                        return 1;
                    }
                }
                if (y + 4 <= 14 && x - 4 >= 0 && search(x - 3, y + 3) == 1 && search(x - 2, y + 2) == 1 && search(x - 4, y + 4) == 0)
                {
                    if (huosi(n, x - 1, y + 1) == 1)
                    {
                        return 1;
                    }
                }
            }
        }
        else if (i + j == 3)
        {
            if (side1_x + 1 <= 14 && side1_y - 1 >= 0 && side2_x - 1 >= 0 && side2_y + 1 <= 14 && search(side1_x + 1, side1_y - 1) == 0 && search(side2_x - 1, side2_y + 1) == 0)
            {
                if (side1_x + 3 <= 14 && side1_y - 3 >= 0 && search(side1_x + 3, side1_y - 3) == 0 && search(side1_x + 2, side1_y - 2) == 1)
                {
                    if (huosi(n, side1_x + 1, side1_y - 1))
                    {
                        return 1;
                    }
                }
                if (side2_x - 3 >= 0 && side2_y + 3 <= 14 && search(side2_x - 3, side2_y + 3) == 0 && search(side2_x - 2, side2_y + 2) == 1)
                {
                    if (huosi(n, side2_x - 1, side2_y + 1))
                    {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}


int finalban(int x, int y)
{
    int orig = arrayForInnerBoardLayout[x][y];
    arrayForInnerBoardLayout[x][y] = 1; // 判断时还未落子，先落上再进行判断
    if (finalchanglian(x, y) == 1)
    {
        arrayForInnerBoardLayout[x][y] = orig;
        return 1;
    }
    if (finalsansan(x, y) == 1)
    {
        arrayForInnerBoardLayout[x][y] = orig;
        return 1;
    }
    if (finalsisi(x, y) == 1)
    {
        arrayForInnerBoardLayout[x][y] = orig;
        return 1;
    }
    arrayForInnerBoardLayout[x][y] = orig;
    return 0;
}

int finalchanglian(int x, int y)
{
    int side1, side2;
    // 横
    for (side1 = 1; search(x - side1, y) == 1; side1++)
        ;
    for (side2 = 1; search(x + side2, y) == 1; side2++)
        ;
    if (side1 + side2 >= 7)
        return 1;
    // 竖
    for (side1 = 1; search(x, y - side1) == 1; side1++)
        ;
    for (side2 = 1; search(x, y + side2) == 1; side2++)
        ;
    if (side1 + side2 >= 7)
        return 1;
    // 左斜
    for (side1 = 1; search(x + side1, y - side1) == 1; side1++)
        ;
    for (side2 = 1; search(x - side2, y + side2) == 1; side2++)
        ;
    if (side1 + side2 >= 7)
        return 1;
    // 右斜
    for (side1 = 1; search(x - side1, y - side1) == 1; side1++)
        ;
    for (side2 = 1; search(x + side2, y + side2) == 1; side2++)
        ;
    if (side1 + side2 >= 7)
        return 1;
    return 0;
}

int finalsansan(int x, int y)
{
    int sum = 0;
    for (int side = 1; side < 5; side++)
        sum += finalhuosan(side, x, y);
    if (sum >= 2)
        return 1;
    return 0;
}

int finalhuosan(int n, int x, int y)
{
    int i;
    int j;
    int side1, side2;
    if (n == 1)
    {
        i = 1;
        j = 1;
        while (y - i >= 0 && search(x, y - i) == 1)
            i++;
        while (y + j <= 14 && search(x, y + j) == 1)
            j++;
        side1 = y - i + 1;
        side2 = y + j - 1;
        if (i + j == 4)
        {
            if ((side1 - 1 >= 0 && finalhuosi(n, x, side1 - 1)) || (side2 + 1 <= 14 && finalhuosi(n, x, side2 + 1)))
                return 1;
        }
        else if (i + j == 2)
        {
            if (y - 1 >= 0 && y + 1 <= 14 && search(x, y - 1) == 0 && search(x, y + 1) == 0)
            {
                if (y - 4 >= 0 && search(x, y - 3) == 1 && search(x, y - 2) == 1 && search(x, y - 4) == 0)
                {
                    if (finalhuosi(n, x, y - 1) == 1)
                    {
                        return 1;
                    }
                }
                if (y + 4 <= 14 && search(x, y + 3) == 1 && search(x, y + 2) == 1 && search(x, y + 4) == 0)
                {
                    if (finalhuosi(n, x, y + 1) == 1)
                    {
                        return 1;
                    }
                }
            }
        }
        else if (i + j == 3)
        {
            if (side1 - 1 >= 0 && side2 + 1 <= 14 && search(x, side1 - 1) == 0 && search(x, side2 + 1) == 0)
            {
                if (side1 - 3 >= 0 && search(x, side1 - 3) == 0 && search(x, side1 - 2) == 1)
                {
                    if (finalhuosi(n, x, side1 - 1))
                    {
                        return 1;
                    }
                }
                if (side2 + 3 >= 0 && search(x, side2 + 3) == 0 && search(x, side2 + 2) == 1)
                {
                    if (finalhuosi(n, x, side2 + 1))
                    {
                        return 1;
                    }
                }
            }
        }
    }
    if (n == 2)
    {
        i = 1;
        j = 1;
        while (x - i >= 0 && search(x - i, y) == 1)
            i++;
        while (x + j <= 14 && search(x + j, y) == 1)
            j++;
        side1 = x - i + 1;
        side2 = x + j - 1;
        if (i + j == 4)
        {
            if ((side1 - 1 >= 0 && finalhuosi(n, side1 - 1, y)) || (side2 + 1 <= 14 && finalhuosi(n, side2 + 1, y)))
            {
                return 1;
            }
        }
        else if (i + j == 2)
        {
            if (x - 1 >= 0 && x + 1 <= 14 && search(x - 1, y) == 0 && search(x + 1, y) == 0)
            {
                if (x - 4 >= 0 && search(x - 3, y) == 1 && search(x - 2, y) == 1 && search(x - 4, y) == 0)
                {
                    if (finalhuosi(n, x - 1, y) == 1)
                    {
                        return 1;
                    }
                }
                if (x + 4 <= 14 && search(x + 3, y) == 1 && search(x + 2, y) == 1 && search(x + 4, y) == 0)
                {
                    if (finalhuosi(n, x + 1, y) == 1)
                    {
                        return 1;
                    }
                }
            }
        }
        else if (i + j == 3)
        {
            if (side1 - 1 >= 0 && side2 + 1 <= 14 && search(side1 - 1, y) == 0 && search(side2 + 1, y) == 0)
            {
                if (side1 - 3 >= 0 && search(side1 - 3, y) == 0 && search(side1 - 2, y) == 1)
                {
                    if (finalhuosi(n, side1 - 1, y))
                    {
                        return 1;
                    }
                }
                if (side2 + 3 >= 0 && search(side2 + 3, y) == 0 && search(side2 + 2, y) == 1)
                {
                    if (finalhuosi(n, side2 + 1, y))
                    {
                        return 1;
                    }
                }
            }
        }
    }
    if (n == 3)
    {
        i = 1;
        j = 1;
        int side1_x, side1_y, side2_x, side2_y;
        while (y - i >= 0 && x - i >= 0 && search(x - i, y - i) == 1)
            i++;
        while (y + j <= 14 && x + j <= 14 && search(x + j, y + j) == 1)
            j++;
        side1_x = x - i + 1;
        side2_x = x + j - 1;
        side1_y = y - i + 1;
        side2_y = y + j - 1;
        if (i + j == 4)
        {
            if ((side1_x - 1 >= 0 && side1_y - 1 >= 0 && finalhuosi(n, side1_x - 1, side1_y - 1)) ||
                (side2_x + 1 <= 14 && side2_y + 1 <= 14 && finalhuosi(n, side2_x + 1, side2_y + 1)))
            {
                return 1;
            }
        }
        else if (i + j == 2)
        {
            if (y - 1 >= 0 && x - 1 >= 0 && y + 1 <= 14 && x + 1 <= 14 && search(x - 1, y - 1) == 0 && search(x + 1, y + 1) == 0)
            {
                if (y - 4 >= 0 && x - 4 >= 0 && search(x - 3, y - 3) == 1 && search(x - 2, y - 2) == 1 && search(x - 4, y - 4) == 0)
                {
                    if (finalhuosi(n, x - 1, y - 1) == 1)
                    {
                        return 1;
                    }
                }
                if (y + 4 <= 14 && x + 4 <= 14 && search(x + 3, y + 3) == 1 && search(x + 2, y + 2) == 1 && search(x + 4, y + 4) == 0)
                {
                    if (finalhuosi(n, x + 1, y + 1) == 1)
                    {
                        return 1;
                    }
                }
            }
        }
        else if (i + j == 3)
        {
            if (side1_x - 1 >= 0 && side1_y - 1 >= 0 && side2_x + 1 <= 14 && side2_y + 1 <= 14 && search(side1_x - 1, side1_y - 1) == 0 && search(side2_x + 1, side2_y + 1) == 0)
            {
                if (side1_x - 3 >= 0 && side1_y - 3 >= 0 && search(side1_x - 3, side1_y - 3) == 0 && search(side1_x - 2, side1_y - 2) == 1)
                {
                    if (finalhuosi(n, side1_x - 1, side1_y - 1))
                    {
                        return 1;
                    }
                }
                if (side2_x + 3 >= 0 && side2_y + 3 >= 0 && search(side2_x + 3, side2_y + 3) == 0 && search(side2_x + 2, side2_y + 2) == 1)
                {
                    if (finalhuosi(n, side2_x + 1, side2_y + 1))
                    {
                        return 1;
                    }
                }
            }
        }
    }
    if (n == 4)
    {
        i = 1;
        j = 1;
        int side1_x, side1_y, side2_x, side2_y;
        while (y - i >= 0 && x + i <= 14 && search(x + i, y - i) == 1)
            i++;
        while (y + j <= 14 && x - j >= 0 && search(x - j, y + j) == 1)
            j++;
        side1_x = x + i - 1;
        side2_x = x - j + 1;
        side1_y = y - i + 1;
        side2_y = y + j - 1;
        if (i + j == 4)
        {
            if ((side1_x + 1 <= 14 && side1_y - 1 >= 0 && finalhuosi(n, side1_x + 1, side1_y - 1)) ||
                (side2_x - 1 >= 0 && side2_y <= 14 && finalhuosi(n, side2_x - 1, side2_y + 1)))
            {
                return 1;
            }
        }
        else if (i + j == 2)
        {
            if (y - 1 >= 0 && x + 1 <= 14 && y + 1 <= 14 && x - 1 >= 0 && search(x + 1, y - 1) == 0 && search(x - 1, y + 1) == 0)
            {
                if (y - 4 >= 0 && x + 4 <= 14 && search(x + 3, y - 3) == 1 && search(x + 2, y - 2) == 1 && search(x + 4, y - 4) == 0)
                {
                    if (finalhuosi(n, x + 1, y - 1) == 1)
                    {
                        return 1;
                    }
                }
                if (y + 4 <= 14 && x - 4 >= 0 && search(x - 3, y + 3) == 1 && search(x - 2, y + 2) == 1 && search(x - 4, y + 4) == 0)
                {
                    if (finalhuosi(n, x - 1, y + 1) == 1)
                    {
                        return 1;
                    }
                }
            }
        }
        else if (i + j == 3)
        {
            if (side1_x + 1 <= 14 && side1_y - 1 >= 0 && side2_x - 1 >= 0 && side2_y + 1 <= 14 && search(side1_x + 1, side1_y - 1) == 0 && search(side2_x - 1, side2_y + 1) == 0)
            {
                if (side1_x + 3 <= 14 && side1_y - 3 >= 0 && search(side1_x + 3, side1_y - 3) == 0 && search(side1_x + 2, side1_y - 2) == 1)
                {
                    if (finalhuosi(n, side1_x + 1, side1_y - 1))
                    {
                        return 1;
                    }
                }
                if (side2_x - 3 >= 0 && side2_y + 3 <= 14 && search(side2_x - 3, side2_y + 3) == 0 && search(side2_x - 2, side2_y + 2) == 1)
                {
                    if (finalhuosi(n, side2_x - 1, side2_y + 1))
                    {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int finalhuosi(int n, int x, int y)
{
    if (search(x, y) == 2)
        return 0;
    int i = 1;
    int j = 1;
    int side1, side2;
    int flag = 0;
    if (search(x, y) != 1)
        flag = 1;
    arrayForInnerBoardLayout[x][y] = 1;
    if (n == 1)
    {
        while (y - i >= 0 && search(x, y - i) == 1)
            i++;
        while (y + j <= 14 && search(x, y + j) == 1)
            j++;
        side1 = y - i + 1;
        side2 = y + j - 1;
        if (i + j != 5)
        {
            if (flag == 1)
                arrayForInnerBoardLayout[x][y] = 0;
            return 0;
        }
        if (i + j == 5)
        {
            if ((side1 - 1 >= 0 && search(x, side1 - 1) == 0) && (side2 + 1 <= 14 && search(x, side2 + 1) == 0))
            {
                if (flag == 1)
                    arrayForInnerBoardLayout[x][y] = 0;
                return 1;
            }
        }
    }
    if (n == 2)
    {
        while (x - i >= 0 && search(x - i, y) == 1)
            i++;
        while (y + j <= 14 && search(x + j, y) == 1)
            j++;
        if (i + j != 5)
        {
            if (flag == 1)
                arrayForInnerBoardLayout[x][y] = 0;
            return 0;
        }
        side1 = x - i + 1;
        side2 = x + j - 1;
        if (i + j == 5)
        {
            if ((side1 - 1 >= 0 && search(side1 - 1, y) == 0) && (side2 + 1 <= 14 && search(side2 + 1, y) == 0))
            {
                if (flag == 1)
                    arrayForInnerBoardLayout[x][y] = 0;
                return 1;
            }
        }
    }
    int side1_x, side1_y, side2_x, side2_y;
    if (n == 3)
    {
        while (y - i >= 0 && x - i >= 0 && search(x - i, y - i) == 1)
            i++;
        while (y + j <= 14 && x + j <= 14 && search(x + j, y + j) == 1)
            j++;
        side1_x = x - i + 1;
        side2_x = x + j - 1;
        side1_y = y - i + 1;
        side2_y = y + j - 1;
        if (i + j != 5)
        {
            if (flag == 1)
                arrayForInnerBoardLayout[x][y] = 0;
            return 0;
        }
        if (i + j == 5)
        {
            if ((side1_x - 1 >= 0 && side1_y - 1 >= 0 && search(side1_x - 1, side1_y - 1) == 0) && (side2_x + 1 <= 14 && side2_y + 1 <= 14 && search(side2_x + 1, side2_y + 1) == 0))
            {
                if (flag == 1)
                    arrayForInnerBoardLayout[x][y] = 0;
                return 1;
            }
        }
    }
    if (n == 4)
    {
        while (y - i >= 0 && x + i <= 14 && search(x + i, y - i) == 1)
            i++;
        while (y + j <= 14 && x - j >= 0 && search(x - j, y + j) == 1)
            j++;
        side1_x = x + i - 1;
        side2_x = x - j + 1;
        side1_y = y - i + 1;
        side2_y = y + j - 1;
        if (i + j != 5)
        {
            if (flag == 1)
                arrayForInnerBoardLayout[x][y] = 0;
            return 0;
        }
        if (i + j == 5)
        {
            if ((side1_x + 1 <= 14 && side1_y - 1 >= 0 && search(side1_x + 1, side1_y - 1) == 0) && (side2_x - 1 >= 0 && side2_y + 1 <= 14 && search(side2_x - 1, side2_y + 1) == 0))
            {
                if (flag == 1)
                    arrayForInnerBoardLayout[x][y] = 0;
                return 1;
            }
        }
    }
    if (flag == 1)
        arrayForInnerBoardLayout[x][y] = 0;
    return 0;
}

int finalsisi(int x, int y)
{
    int sum = 0;
    for (int side = 1; side < 5; side++)
    {
        sum += finalchongsi(side, x, y);
        sum += finalhuosi(side, x, y);
    }
    if (sum >= 2)
        return 1;
    return 0;
}

int finalchongsi(int n, int x, int y)
{
    if (search(x, y) == 2)
        return 0;
    int i = 1;
    int j = 1;
    int side1, side2;
    int flag = 0;
    if (arrayForInnerBoardLayout[x][y] != 1)
    {
        flag = 1;
    }
    arrayForInnerBoardLayout[x][y] = 1;
    int count = 0;
    if (n == 1)
    {
        while (y - i >= 0 && search(x, y - i) == 1)
            i++;
        while (y + j <= 14 && search(x, y + j) == 1)
            j++;
        side1 = y - i + 1;
        side2 = y + j - 1;
        if (i + j == 2)
        {
            if (side1 - 4 >= 0 && search(x, side1 - 2) == 1 && search(x, side1 - 3) == 1 && search(x, side1 - 4) == 1 && search(x, side1 - 1) == 0)
                count++;
            if (side2 + 4 <= 14 && search(x, side2 + 2) == 1 && search(x, side2 + 3) == 1 && search(x, side2 + 4) == 1 && search(x, side2 + 1) == 0)
                count++;
            if (count != 0)
            {
                if (flag == 1)
                    arrayForInnerBoardLayout[x][y] = 0;
                return count;
            }
        }
        if (i + j == 3)
        {
            if (side1 - 3 >= 0 && search(x, side1 - 3) == 1 && search(x, side1 - 2) == 1 && search(x, side1 - 1) == 0)
                count++;
            if (side2 + 3 <= 14 && search(x, side2 + 3) == 1 && search(x, side2 + 2) == 1 && search(x, side2 + 1) == 0)
                count++;
            if (count != 0)
            {
                if (flag == 1)
                    arrayForInnerBoardLayout[x][y] = 0;
                return count;
            }
        }
        if (i + j == 4)
        {
            if (side1 - 2 >= 0 && search(x, side1 - 2) == 1 && search(x, side1 - 1) == 0)
                count++;
            if (side2 + 2 <= 14 && search(x, side2 + 2) == 1 && search(x, side2 + 1) == 0)
                count++;
            if (count != 0)
            {
                if (flag == 1)
                    arrayForInnerBoardLayout[x][y] = 0;
                return count;
            }
        }
        if (i + j == 5)
        {
            if ((side1 - 1 >= 0 && search(x, side1 - 1) == 0) ^ (side2 + 1 <= 14 && search(x, side2 + 1) == 0))
            {
                if (flag == 1)
                {
                    arrayForInnerBoardLayout[x][y] = 0;
                }
                return 1;
            }
        }
        if (flag == 1)
        {
            arrayForInnerBoardLayout[x][y] = 0;
        }
        return 0;
    }
    if (n == 2)
    {
        while (x - i >= 0 && search(x - i, y) == 1)
            i++;
        while (x + j <= 14 && search(x + j, y) == 1)
            j++;
        side1 = x - i + 1;
        side2 = x + j - 1;
        if (i + j == 2)
        {
            if (side1 - 4 >= 0 && search(side1 - 2, y) == 1 && search(side1 - 3, y) == 1 && search(side1 - 4, y) == 1 && search(side1 - 1, y) == 0)
                count++;
            if (side2 + 4 <= 14 && search(side2 + 2, y) == 1 && search(side2 + 3, y) == 1 && search(side2 + 4, y) == 1 && search(side2 + 1, y) == 0)
                count++;
            if (count != 0)
            {
                if (flag == 1)
                {
                    arrayForInnerBoardLayout[x][y] = 0;
                }
                return count;
            }
            count = 0;
        }
        if (i + j == 3)
        {
            if (side1 - 3 >= 0 && search(side1 - 3, y) == 1 && search(side1 - 2, y) == 1 && search(side1 - 1, y) == 0)
                count++;
            if (side2++ <= 14 && search(side2 + 3, y) == 1 && search(side2 + 2, y) && search(side2 + 1, y) == 0)
                count++;
            if (count != 0)
            {
                if (flag == 1)
                {
                    arrayForInnerBoardLayout[x][y] = 0;
                }
                return count;
            }
            count = 0;
        }
        if (i + j == 4)
        {
            if (side1 - 2 >= 0 && search(side1 - 2, y) == 1 && search(side1 - 1, y) == 0)
                count++;
            if (side2 + 2 <= 14 && search(side2 + 2, y) == 1 && search(side2 + 1, y) == 0)
                count++;
            if (count != 0)
            {
                if (flag == 1)
                {
                    arrayForInnerBoardLayout[x][y] = 0;
                }
                return count;
            }
            count = 0;
        }
        if (i + j == 5)
        {
            if ((side1 - 1 >= 0 && search(side1 - 1, y) == 0) ^ (side2 + 1 <= 14 && search(side2 + 1, y) == 0))
            {
                if (flag == 1)
                {
                    arrayForInnerBoardLayout[x][y] = 0;
                }
                return 1;
            }
        }
        if (flag == 1)
        {
            arrayForInnerBoardLayout[x][y] = 0;
        }
        return 0;
    }
    int side1_x, side1_y, side2_x, side2_y;
    if (n == 3)
    {
        while (x - i >= 0 && y - i >= 0 && search(x - i, y - i) == 1)
            i++;
        while (x + j <= 14 && y + j <= 14 && search(x + j, y + j) == 1)
            j++;
        side1_x = x - i + 1;
        side2_x = x + j - 1;
        side1_y = y - i + 1;
        side2_y = y + j - 1;
        if (i + j == 2)
        {
            if (side1_x - 4 >= 0 && side1_y - 4 >= 0 && search(side1_x - 2, side1_y - 2) == 1 && search(side1_x - 3, side1_y - 3) == 1 && search(side1_x - 4, side1_y - 4) == 1 && search(side1_x - 1, side1_y - 1) == 0)
                count++;
            if (side2_x + 4 <= 14 && side2_y + 4 <= 14 && search(side2_x + 2, side2_y + 2) == 1 && search(side2_x + 3, side2_y + 3) == 1 && search(side2_x + 4, side2_y + 4) == 1 && search(side2_x + 1, side2_y + 1) == 0)
                count++;
            if (count != 0)
            {
                if (flag == 1)
                    arrayForInnerBoardLayout[x][y] = 0;
                return count;
            }
            count = 0;
        }
        if (i + j == 3)
        {
            if (side1_x - 3 >= 0 && side1_y - 3 >= 0 && search(side1_x - 3, side1_y - 3) == 1 && search(side1_x - 2, side1_y - 2) == 1 && search(side1_x - 1, side1_y - 1) == 0)
                count++;
            if (side2_x + 3 <= 14 && side2_y + 3 <= 14 && search(side2_x + 3, side2_y + 3) == 1 && search(side2_x + 2, side2_y + 2) && search(side2_x + 1, side2_y + 1) == 0)
                count++;
            if (count != 0)
            {
                if (flag == 1)
                    arrayForInnerBoardLayout[x][y] = 0;
                return count;
            }
            count = 0;
        }
        if (i + j == 4)
        {
            if (side1_x - 2 >= 0 && side1_y - 2 >= 0 && search(side1_x - 2, side1_y - 2) == 1 && search(side1_x - 1, side1_y - 1) == 0)
            {
                count++;
            }
            if (side2_x + 2 <= 14 && side2_y + 2 <= 14 && search(side2_x + 2, side2_y + 2) == 1 && search(side2_x + 1, side2_y + 1) == 0)
            {
                count++;
            }
            if (count != 0)
            {
                if (flag == 1)
                    arrayForInnerBoardLayout[x][y] = 0;
                return count;
            }
            count = 0;
        }
        if (i + j == 5)
        {
            if ((side1_x - 1 >= 0 && side1_y - 1 >= 0 && search(side1_x - 1, side1_y - 1) == 0) ^ (side2_x + 1 <= 14 && side2_y + 1 <= 14 && search(side2_x + 1, side2_y + 1) == 0))
            {
                if (flag == 1)
                    arrayForInnerBoardLayout[x][y] = 0;
                return 1;
            }
        }
        if (flag == 1)
            arrayForInnerBoardLayout[x][y] = 0;
        return 0;
    }
    if (n == 4)
    {
        while (x + i <= 14 && y - i >= 0 && search(x + i, y - i) == 1)
            i++;
        while (x - j >= 0 && y + j <= 14 && search(x - j, y + j) == 1)
            j++;
        side1_x = x + i - 1;
        side2_x = x - j + 1;
        side1_y = y - i + 1;
        side2_y = y + j - 1;
        if (i + j == 2)
        {
            if (side1_x + 4 <= 14 && side1_y - 4 >= 0 && search(side1_x + 2, side1_y - 2) == 1 && search(side1_x + 3, side1_y - 3) == 1 && search(side1_x + 4, side1_y - 4) == 1 && search(side1_x + 1, side1_y - 1) == 0)
                count++;
            if (side2_x - 4 >= 0 && side2_y + 4 <= 14 && search(side2_x - 2, side2_y + 2) == 1 && search(side2_x - 3, side2_y + 3) == 1 && search(side2_x - 4, side2_y + 4) == 1 && search(side2_x - 1, side2_y + 1) == 0)
                count++;
            if (count != 0)
            {
                if (flag == 1)
                    arrayForInnerBoardLayout[x][y] = 0;
                return count;
            }
            count = 0;
        }
        if (i + j == 3)
        {
            if (side1_x + 3 <= 0 && side1_y - 3 >= 0 && search(side1_x + 3, side1_y - 3) == 1 && search(side1_x + 2, side1_y - 2) == 1 && search(side1_x + 1, side1_y - 1) == 0)
                count++;
            if (side2_x - 3 >= 0 && side2_y + 3 <= 14 && search(side2_x - 3, side2_y + 3) == 1 && search(side2_x - 2, side2_y + 2) && search(side2_x - 1, side2_y + 1) == 0)
                count++;
            if (count != 0)
            {
                if (flag == 1)
                    arrayForInnerBoardLayout[x][y] = 0;
                return count;
            }
            count = 0;
        }
        if (i + j == 4)
        {
            if (side1_x + 2 >= 0 && side1_y - 2 >= 0 && search(side1_x + 2, side1_y - 2) == 1 && search(side1_x + 1, side1_y - 1) == 0)
                count++;
            if (side2_x - 2 >= 0 && side2_y + 2 <= 14 && search(side2_x - 2, side2_y + 2) == 1 && search(side2_x - 1, side2_y + 1) == 0)
                count++;
            if (count != 0)
            {
                if (flag == 1)
                    arrayForInnerBoardLayout[x][y] = 0;
                return count;
            }
            count = 0;
        }
        if (i + j == 5)
        {
            if ((side1_x + 1 <= 14 && side1_y - 1 >= 0 && search(side1_x + 1, side1_y - 1) == 0) ^ (side2_x - 1 >= 0 && side2_y + 1 <= 14 && search(side2_x - 1, side2_y + 1) == 0))
            {
                if (flag == 1)
                    arrayForInnerBoardLayout[x][y] = 0;
                return 1;
            }
        }
        if (flag == 1)
            arrayForInnerBoardLayout[x][y] = 0;
        return 0;
    }
    if (flag == 1)
        arrayForInnerBoardLayout[x][y] = 0;
    return 0;
}