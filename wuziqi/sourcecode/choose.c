#include "fir.h"
//选取最佳落子位置，使用alphabeta剪枝来缩小搜索范围
extern int playx, playy;
extern int arrayForInnerBoardLayout[SIZE][SIZE];
struct point bestpoint;

struct point bestanswer(int n)
{
    int vaildpoint(int x, int y);
    static int flag = 2; // 起手花月，记录
    int ini1, ini2, ini3; //保存初始状态
    int x1, y1, x2, y2, x3, y3, x4, y4; // 每一层的最优点
    int value1, value2, value3, value4; // 每次迭代的得分
    int Max1, Min2, Max3, Min4;         // minimax算法
    int break1, break2, break3, break4 = 0; // 退出两层！
    if (n == 1 && flag == 2)
    { // 先手第一步下天元！
        bestpoint.x = 7;
        bestpoint.y = 7;
        flag = 1;
    }
    else if(n == 1 && flag == 1 && ((playx == 6 && playy==8)||(playx==8 && playy==8)||(playx==6 && playy==6)||(playx==8 && playy==6)))
    {
        //对手落子斜边，花月开局，否则进入else
        if(playx == 6 && playy==8)
        {
            bestpoint.x = 8;
            bestpoint.y = 8;
        }
        if(playx == 8 && playy==8)
        {
            bestpoint.x = 6;
            bestpoint.y = 8;
        }
        if(playx == 6 && playy==6)
        {
            bestpoint.x = 6;
            bestpoint.y = 8;
        }
        if(playx == 8 && playy==6)
        {
            bestpoint.x = 8;
            bestpoint.y = 8;
        }
        flag = 0;
    }
    else
    {
        flag = 0;
        Max1 = -200000;
        int flag_quit = 0; // 退出
        for (x1 = 0; x1 < SIZE; ++x1)
        { // 进攻
            for (y1 = 0; y1 < SIZE; ++y1)
            {
                if (search(x1, y1) == 0 && vaildpoint(x1, y1))
                { // 有空位且周围不空
                    if (Score(x1, y1, n) >= 100000 && (n == 2 || !ban(x1, y1)))
                    { // 可以获胜（后手或未触发禁手）
                        bestpoint.x = x1;
                        bestpoint.y = y1;
                        return bestpoint; // 存储并返回最优解
                    }
                }
            }
        }
        for (x1 = 0; x1 < SIZE; ++x1)
        { // 防守，同上
            for (y1 = 0; y1 < SIZE; ++y1)
            {
                if (search(x1, y1) == 0 && vaildpoint(x1, y1) && (n == 1 || !ban(x1, y1)))
                {
                    if (Score(x1, y1, 3 - n) >= 100000)
                    {
                        bestpoint.x = x1;
                        bestpoint.y = y1;
                        return bestpoint;
                    }
                }
            }
        }
        // alphabeta剪枝
        if (n == 1)
        { // 先手
            for (x1 = playx - 2; x1 <= playx + 2; ++x1) //在对手落子周围进行搜索
            {
                for (y1 = playy - 2; y1 <= playy + 2; ++y1)
                {
                    if (search(x1, y1) == 0 && vaildpoint(x1, y1))//
                    {
                        Min2 = +200000;
                        ini1 = arrayForInnerBoardLayout[x1][y1];
                        value1 = Score(x1, y1, n);
                        // 判胜立刻退出
                        if (value1 >= 100000)
                        {
                            Max1 = value1;
                            flag_quit = 1;
                            break1 = 1;
                            break;
                        }
                        arrayForInnerBoardLayout[x1][y1] = n;
                        for (x2 = 0; x2 < SIZE; ++x2)
                        {
                            for (y2 = 0; y2 < SIZE; ++y2)
                            {
                                if (search(x2, y2) == 0 && vaildpoint(x2, y2))
                                {
                                    Max3 = -200000;
                                    ini2 = arrayForInnerBoardLayout[x2][y2];
                                    value2 = Score(x2, y2, 3 - n);
                                    // 判胜立刻退出
                                    if (value2 >= 100000)
                                    {
                                        Min2 = value1 - value2;
                                        flag_quit = 1;
                                        break2 = 1;
                                        break;
                                    }
                                    arrayForInnerBoardLayout[x2][y2] = 3 - n;
                                    for (x3 = 0; x3 < SIZE; ++x3)
                                    {
                                        for (y3 = 0; y3 < SIZE; ++y3)
                                        {
                                            if (search(x3, y3) == 0 && vaildpoint(x3, y3))
                                            {
                                                Min4 = +200000;
                                                ini3 = arrayForInnerBoardLayout[x3][y3];
                                                value3 = Score(x3, y3, n);
                                                // 判胜立刻退出
                                                if (value3 >= 100000)
                                                {
                                                    Max3 = value1 - value2 + value3;
                                                    break3 = 1;
                                                    break;
                                                }
                                                arrayForInnerBoardLayout[x3][y3] = n;
                                                for (x4 = 0; x4 < SIZE; ++x4)
                                                {
                                                    for (y4 = 0; y4 < SIZE; ++y4)
                                                    {
                                                        if (search(x4, y4) == 0 && vaildpoint(x4, y4))
                                                        {
                                                            value4 = Score(x4, y4, 3 - n);
                                                            if (Min4 > value1 - value2 + value3 - value4)
                                                            {
                                                                //minimax算法
                                                                Min4 = value1 - value2 + value3 - value4;
                                                            }
                                                            if (Min4 <= Max3)
                                                            {
                                                                // alphabeta剪枝，下同
                                                                Min4 = -200000;
                                                                break4 = 1;
                                                                break;
                                                            }
                                                        }
                                                    }
                                                    if (break4 == 1)
                                                    {
                                                        break4 = 0;
                                                        break;
                                                    }
                                                }
                                                arrayForInnerBoardLayout[x3][y3] = ini3;
                                                if (Max3 < Min4)
                                                {
                                                    Max3 = Min4;
                                                }
                                                if (Min2 <= Max3)
                                                {
                                                    Max3 = +200000;
                                                    break3 = 1;
                                                    break;
                                                }
                                            }
                                        }
                                        if (break3 == 1)
                                        {
                                            break3 = 0;
                                            break;
                                        }
                                    }
                                    arrayForInnerBoardLayout[x2][y2] = ini2;
                                    if (Max3 < Min2)
                                    {
                                        Min2 = Max3;
                                    }
                                    if (Min2 <= Max1)
                                    {
                                        Min2 = -200000;
                                        break2 = 1;
                                        break;
                                    }
                                }
                            }
                            if (break2 == 1)
                            {
                                break2 = 0;
                                break;
                            }
                        }
                        arrayForInnerBoardLayout[x1][y1] = ini1;
                        if (Min2 > Max1)
                        {
                            if (!ban(x1, y1))
                            {
                                bestpoint.x = x1;
                                bestpoint.y = y1;
                                Max1 = Min2;
                            }
                        }
                    }
                }
                if (break1 == 1)
                {
                    break1 = 0;
                    break;
                }
            }
        }
        if (n == 2) // ai后手，与上类似
        {
            for (x1 = playx - 2; x1 <= playx + 2; ++x1)
            {
                for (y1 = playy - 2; y1 <= playy + 2; ++y1)
                {
                    if (search(x1, y1) == 0 && vaildpoint(x1, y1))
                    {
                        Min2 = +200000;
                        ini1 = arrayForInnerBoardLayout[x1][y1];
                        value1 = Score(x1, y1, n);
                        // 判胜立刻退出
                        if (value1 >= 100000)
                        {
                            Max1 = value1;
                            break1 = 1;
                            break;
                        }
                        arrayForInnerBoardLayout[x1][y1] = n;
                        for (x2 = 0; x2 < SIZE; ++x2)
                        {
                            for (y2 = 0; y2 < SIZE; ++y2)
                            {
                                if (search(x2, y2) == 0 && vaildpoint(x2, y2))
                                {
                                    Max3 = -200000;
                                    ini2 = arrayForInnerBoardLayout[x2][y2];
                                    value2 = Score(x2, y2, 3 - n);
                                    // 判胜立刻退出
                                    if (value2 >= 100000)
                                    {
                                        Min2 = value1 - value2;
                                        break2 = 1;
                                        break;
                                    }
                                    arrayForInnerBoardLayout[x2][y2] = 3 - n;
                                    for (x3 = 0; x3 < SIZE; ++x3)
                                    {
                                        for (y3 = 0; y3 < SIZE; ++y3)
                                        {
                                            if (search(x3, y3) == 0 && vaildpoint(x3, y3))
                                            {
                                                Min4 = +200000;
                                                ini3 = arrayForInnerBoardLayout[x3][y3];
                                                value3 = Score(x3, y3, n);
                                                // 判胜立刻退出
                                                if (value3 >= 100000)
                                                {
                                                    Max3 = value1 - value2 + value3;
                                                    break3 = 1;
                                                    break;
                                                }
                                                arrayForInnerBoardLayout[x3][y3] = n;
                                                for (x4 = 0; x4 < SIZE; ++x4)
                                                {
                                                    for (y4 = 0; y4 < SIZE; ++y4)
                                                    {
                                                        if (search(x4, y4) == 0 && vaildpoint(x4, y4))
                                                        {
                                                            value4 = Score(x4, y4, 3 - n);
                                                            if (Min4 > value1 - value2 + value3 - value4)
                                                            {
                                                                // minimax算法
                                                                Min4 = value1 - value2 + value3 - value4;
                                                            }
                                                            if (Min4 <= Max3)
                                                            {
                                                                // alphabeta剪枝，下同
                                                                Min4 = -200000;
                                                                break4 = 1;
                                                                break;
                                                            }
                                                        }
                                                    }
                                                    if (break4 == 1)
                                                    {
                                                        break4 = 0;
                                                        break;
                                                    }
                                                }
                                                arrayForInnerBoardLayout[x3][y3] = ini3;
                                                if (Max3 < Min4)
                                                {
                                                    Max3 = Min4;
                                                }
                                                if (Min2 <= Max3)
                                                {
                                                    Max3 = +200000;
                                                    break3 = 1;
                                                    break;
                                                }
                                            }
                                        }
                                        if (break3 == 1)
                                        {
                                            break3 = 0;
                                            break;
                                        }
                                    }
                                    arrayForInnerBoardLayout[x2][y2] = ini2;
                                    if (Max3 < Min2)
                                    {
                                        Min2 = Max3;
                                    }
                                    if (Min2 <= Max1)
                                    {
                                        Min2 = -200000;
                                        break2 = 1;
                                        break;
                                    }
                                }
                            }
                            if (break2 == 1)
                            {
                                break2 = 0;
                                break;
                            }
                        }
                        arrayForInnerBoardLayout[x1][y1] = ini1;
                        if (Min2 > Max1)
                        {
                            bestpoint.x = x1;
                            bestpoint.y = y1;
                            Max1 = Min2;
                        }
                    }
                }
                if (break1 == 1)
                {
                    break1 = 0;
                    break;
                }
            }
        }
        if (flag_quit == 0)
        {
            for (x1 = 0; x1 < SIZE; ++x1)
            {
                for (y1 = 0; y1 < SIZE; ++y1)
                {
                    if (search(x1, y1) == 0 && vaildpoint(x1, y1))
                    {
                        Min2 = +200000;
                        ini1 = arrayForInnerBoardLayout[x1][y1];
                        value1 = Score(x1, y1, n);
                        // 判胜立刻退出
                        if (value1 >= 100000)
                        {
                            Max1 = value1;
                            bestpoint.x = x1;
                            bestpoint.y = y1;
                            break1 = 1;
                            break;
                        }
                        arrayForInnerBoardLayout[x1][y1] = n;
                        for (x2 = 0; x2 < SIZE; ++x2)
                        {
                            for (y2 = 0; y2 < SIZE; ++y2)
                            {
                                if (search(x2, y2) == 0 && vaildpoint(x2, y2))
                                {
                                    Max3 = -200000;
                                    ini2 = arrayForInnerBoardLayout[x2][y2];
                                    value2 = Score(x2, y2, 3 - n);
                                    // 判胜立刻退出
                                    if (value2 >= 100000)
                                    {
                                        Min2 = value1 - value2;
                                        break2 = 1;
                                        break;
                                    }
                                    arrayForInnerBoardLayout[x2][y2] = 3 - n;
                                    for (x3 = 0; x3 < SIZE; ++x3)
                                    {
                                        for (y3 = 0; y3 < SIZE; ++y3)
                                        {
                                            if (search(x3, y3) == 0 && vaildpoint(x3, y3))
                                            {
                                                Min4 = +200000;
                                                ini3 = arrayForInnerBoardLayout[x3][y3];
                                                value3 = Score(x3, y3, n);
                                                // 判胜立刻退出
                                                if (value3 >= 100000)
                                                {
                                                    Max3 = value1 - value2 + value3;
                                                    break3 = 1;
                                                    break;
                                                }
                                                arrayForInnerBoardLayout[x3][y3] = n;
                                                for (x4 = 0; x4 < SIZE; ++x4)
                                                {
                                                    for (y4 = 0; y4 < SIZE; ++y4)
                                                    {
                                                        if (search(x4, y4) == 0 && vaildpoint(x4, y4))
                                                        {
                                                            value4 = Score(x4, y4, 3 - n);
                                                            if (Min4 > value1 - value2 + value3 - value4)
                                                            {
                                                                // minimax算法
                                                                Min4 = value1 - value2 + value3 - value4;
                                                            }
                                                            if (Min4 <= Max3)
                                                            {
                                                                // alphabeta剪枝
                                                                Min4 = -200000;
                                                                break4 = 1;
                                                                break;
                                                            }
                                                        }
                                                    }
                                                    if (break4 == 1)
                                                    {
                                                        break4 = 0;
                                                        break;
                                                    }
                                                }
                                                arrayForInnerBoardLayout[x3][y3] = ini3;
                                                if (Max3 < Min4)
                                                {
                                                    Max3 = Min4;
                                                }
                                                if (Min2 <= Max3)
                                                {
                                                    Max3 = +200000;
                                                    break3 = 1;
                                                    break;
                                                }
                                            }
                                        }
                                        if (break3 == 1)
                                        {
                                            break3 = 0;
                                            break;
                                        }
                                    }
                                    arrayForInnerBoardLayout[x2][y2] = ini2;
                                    if (Max3 < Min2)
                                    {
                                        Min2 = Max3;
                                    }
                                    if (Min2 <= Max1)
                                    {
                                        Min2 = -200000;
                                        break2 = 1;
                                        break;
                                    }
                                }
                            }
                            if (break2 == 1)
                            {
                                break2 = 0;
                                break;
                            }
                        }
                        arrayForInnerBoardLayout[x1][y1] = ini1;
                        if (Min2 > Max1)
                        {
                            if (n == 2 || !ban(x1, y1))
                            {
                                bestpoint.x = x1;
                                bestpoint.y = y1;
                                Max1 = Min2;
                            }
                        }
                    }
                }
                if (break1 == 1)
                {
                    break1 = 0;
                    break;
                }
            }
        }
        return bestpoint;
    }
    return bestpoint;
}

int vaildpoint(int x, int y)
{ // 判断周围是否有子
    // 周围一圈无空位
    int i = 1;
    if ((x - i >= 0 && search(x - i, y) != 0) || (y - i >= 0 && search(x, y - i) != 0) || (x - i >= 0 && y - i >= 0 && search(x - i, y - i) != 0) || (x + i <= 14 && y - i >= 0 && search(x + i, y - i) != 0))
        return 1;
    i = -1;
    if ((x - i <= 14 && search(x - i, y) != 0) || (y - i <= 14 && search(x, y - i) != 0) || (x - i <= 14 && y - i <= 14 && search(x - i, y - i) != 0) || (x + i >= 0 && y - i <= 14 && search(x + i, y - i) != 0))
        return 1;
    // 周围两圈的直线和斜线上无空位
    i = 2;
    if ((x - i >= 0 && search(x - i, y) != 0) || (y - i >= 0 && search(x, y - i) != 0) || (x - i >= 0 && y - i >= 0 && search(x - i, y - i) != 0) || (x + i <= 14 && y - i >= 0 && search(x + i, y - i) != 0))
        return 1;
    i = -2;
    if ((x - i <= 14 && search(x - i, y) != 0) || (y - i <= 14 && search(x, y - i) != 0) || (x - i <= 14 && y - i <= 14 && search(x - i, y - i) != 0) || (x + i >= 0 && y - i <= 14 && search(x + i, y - i) != 0))
        return 1;
    return 0;
}