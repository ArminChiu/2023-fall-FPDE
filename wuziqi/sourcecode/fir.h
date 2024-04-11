#ifndef _FIR_H
#define _FIR_H
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define SIZE 15
#define CHARSIZE 3 // UTF8编码

// 分数宏定义
#define FIVE 1000000   // 一？五！
#define FOUR 10000     // 活四
#define DEAD_FOUR 1000 // 冲四
#define THREE 1000     // 活三
#define DEAD_THREE 100 // 冲三
#define TWO 100        // 活二
#define DEAD_TWO 10    // 冲二
#define ONE 10         // 活一
#define DEAD_ONE 1     // 冲一

#define WULIAN 100000   //五连
#define HUOSI 10000     //活四
#define LIANSI 1000     //连四
#define TIAOSI 1000     //跳四
#define LIANHUOSAN 1000 //连活三
#define TIAOHUOSAN 1000 //跳活三
#define JIAHUOSAN 100   //假活三
#define MIANSAN 100     //眠三
#define HUOER 100       //活二
#define MIANER 10       //眠二

// 结构体
struct SingleInfo
{
    int linkNum; // 连子数
    int oppNum;  // 对手棋子数
};
struct SingleScore
{ // 每一个位置的信息和得分
    struct SingleInfo info[4]; //记录四个方向的信息
    int score; // 得分
};
struct point
{ // 坐标值
    int x;
    int y;
};

// 函数声明
void initRecordBorard(void);                  // 初始化棋盘
void innerLayoutToDisplayArray(int x, int y); // 读取心中棋盘，写入实际棋盘
void displayBoard(void);                      // 展示实际棋盘
void player(int n);                           // 玩家落子函数
int win(int x, int y, int n);                 // 判胜函数
int ban(int x, int y);                        // 判断禁手函数
int search(int x, int y);                     // 访问该坐标落子状态
int Score(int x, int y, int n);               // 计算一个位置得分
struct point bestanswer(int n);               // ai函数
void ai(int x, int y, int n);                 // ai落子函数
#endif