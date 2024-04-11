#include "fir.h"

// 全局变量定义
struct point answer;

int playx, playy = 0;  // 全局变量表示棋子在xx行yy列，用叠词词是为了防止重名，本质上只是个中转区，将player中的行列参数传出。
int pattern, turn; // 全局变量模式，先后手
int arrayForInnerBoardLayout[SIZE][SIZE];
// 空棋盘
char arrayForEmptyBoard[SIZE][SIZE * CHARSIZE + 1] = {
    "┗┷┷┷┷┷┷┷┷┷┷┷┷┷┛",
    "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
    "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
    "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
    "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
    "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
    "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
    "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
    "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
    "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
    "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
    "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
    "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
    "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
    "┏┯┯┯┯┯┯┯┯┯┯┯┯┯┓"};
// 此数组存储用于显示的棋盘
char arrayForDisplayBoard[SIZE][SIZE * CHARSIZE + 1];

char play1Pic[] = "●"; // 黑棋子;
char play1CurrentPic[] = "▲";

char play2Pic[] = "◎"; // 白棋子;
char play2CurrentPic[] = "△";

// 主要函数定义
int main()
{
    int x, y; // 主函数内将player函数行列值传出
    initRecordBorard();
    system("clear"); // 清屏
    // 空棋盘展示,作者展示
    printf("Work of 邱明阳\n");
    for (int i = 0; i < SIZE; ++i)
    {
        printf("%3d %s\n", 15 - i, arrayForEmptyBoard[15 - i - 1]);
    }
    printf("     A B C D E F G H I J K L M N O\n");
    // 选择模式
    printf("请选择游玩模式:1.人人对战 2.人机对战\n");
    scanf("%d", &pattern);
    getchar();
    while (pattern == 1)
    {              // 人人对战
        player(1); // 落子
        x = playx;
        y = playy;
        innerLayoutToDisplayArray(x, y); // 转换
        printf("Work of 邱明阳\n");
        displayBoard(); // 打印
        player(2);
        x = playx;
        y = playy;
        innerLayoutToDisplayArray(x, y);
        printf("Work of 邱明阳\n");
        displayBoard();
    }
    if (pattern == 2)
    { // 人机对战
        printf("请玩家选择先后手:1.先手 2.后手\n");
        scanf("%d", &turn);
        getchar();
        while (turn == 1)
        {
            player(1); // 落子
            x = playx;
            y = playy;
            innerLayoutToDisplayArray(x, y); // 转换
            printf("Work of 邱明阳\n");
            displayBoard(); // 打印
            answer = bestanswer(2);
            x = answer.x;
            y = answer.y;
            ai(x, y, 2);
        }
        while (turn == 2)
        {
            answer = bestanswer(1);
            x = answer.x;
            y = answer.y;
            ai(x, y, 1);
            player(2);
            x = playx;
            y = playy;
            innerLayoutToDisplayArray(x, y);
            printf("Work of 邱明阳\n");
            displayBoard();
        }
    }
    return 0;
}

// 初始化棋盘
void initRecordBorard(void)
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            arrayForInnerBoardLayout[i][j] = 0;
        }
    }
}

// 将棋子位置转化到棋盘中
void innerLayoutToDisplayArray(int x, int y)
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE * CHARSIZE + 1; ++j)
        {
            arrayForDisplayBoard[i][j] = arrayForEmptyBoard[i][j];
        }
    }
    // 第二步：扫描arrayForInnerBoardLayout，当遇到非0的元素，将●或者◎复制到arrayForDisplayBoard的相应位置上
    // 注意：arrayForDisplayBoard所记录的字符是中文字符，每个字符占2个字节。●和◎也是中文字符，每个也占2个字节。
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            if (arrayForInnerBoardLayout[i][j] == 1)
            {
                arrayForDisplayBoard[i][j * CHARSIZE] = play1Pic[0];
                arrayForDisplayBoard[i][j * CHARSIZE + 1] = play1Pic[1];
                arrayForDisplayBoard[i][j * CHARSIZE + 2] = play1Pic[2];
            }
            if (arrayForInnerBoardLayout[i][j] == 2)
            {
                arrayForDisplayBoard[i][j * CHARSIZE] = play2Pic[0];
                arrayForDisplayBoard[i][j * CHARSIZE + 1] = play2Pic[1];
                arrayForDisplayBoard[i][j * CHARSIZE + 2] = play2Pic[2];
            }
        }
    }
    // 把最后一子改成三角形
    if (arrayForInnerBoardLayout[x][y] == 1)
    {
        arrayForDisplayBoard[x][y * CHARSIZE] = play1CurrentPic[0];
        arrayForDisplayBoard[x][y * CHARSIZE + 1] = play1CurrentPic[1];
        arrayForDisplayBoard[x][y * CHARSIZE + 2] = play1CurrentPic[2];
    }
    if (arrayForInnerBoardLayout[x][y] == 2)
    {
        arrayForDisplayBoard[x][y * CHARSIZE] = play2CurrentPic[0];
        arrayForDisplayBoard[x][y * CHARSIZE + 1] = play2CurrentPic[1];
        arrayForDisplayBoard[x][y * CHARSIZE + 2] = play2CurrentPic[2];
    }
}

// 显示棋盘格局
void displayBoard(void)
{
    system("clear"); // 清屏
    for (int i = 0; i < SIZE; ++i)
    {
        printf("%3d %s\n", 15 - i, arrayForDisplayBoard[15 - i - 1]);
    }
    printf("     A B C D E F G H I J K L M N O\n");
}

// 玩家落子,并且判断是否五连，再判断是否禁手
void player(int n)
{
    int i;
    char line[100];
    int mygetline(char s[], int lim);
    if (n == 1)
    {
        printf("先手请落子\n");
    }
    else if (n == 2)
    {
        printf("后手请落子\n");
    }
    i = mygetline(line, 100);
    if (line[0] == 'q' && line[1] == 'u' && line[2] == 'i' && line[3] == 't')
    { // quit
        exit(0);
    }
    if (line[0] >= 'a' && line[0] <= 'o')
    { // 小写字母在前，数字在后
        playy = line[0] - 'a';
        if (line[1] >= '0' && line[1] <= '9')
        {
            playx = line[1] - '1';
            if (line[2] >= '0' && line[2] <= '9')
            {
                playx = 10 + line[2] - '1';
            }
        }
    }
    if (line[0] >= 'A' && line[0] <= 'O')
    { // 大写字母在前，数字在后
        playy = line[0] - 'A';
        if (line[1] >= '0' && line[1] <= '9')
        {
            playx = line[1] - '1';
            if (line[2] >= '0' && line[2] <= '9')
            {
                playx = 10 + line[2] - '1';
            }
        }
    }
    if (line[0] >= '0' && line[0] <= '9')
    { // 数字在前，小写字母在后
        playx = line[0] - '1';
        if (line[1] >= 'a' && line[1] <= 'o')
            playy = line[1] - 'a';
        if (line[1] >= '0' && line[1] <= '9')
        {
            playx = 10 + line[1] - '1';
            if (line[2] >= 'a' && line[2] <= 'o')
                playy = line[2] - 'a';
        }
    }
    if (line[0] >= '0' && line[0] <= '9')
    { // 数字在前，大写字母在后
        playx = line[0] - '1';
        if (line[1] >= 'A' && line[1] <= 'O')
            playy = line[1] - 'A';
        if (line[1] >= '0' && line[1] <= '9')
        {
            playx = 10 + line[1] - '1';
            if (line[2] >= 'A' && line[2] <= 'O')
                playy = line[2] - 'A';
        }
    }
    if (arrayForInnerBoardLayout[playx][playy] != 0)
    { // 此处已落子
        printf("此处已有子，请重新落子\n");
        player(n); // 重新进入函数
        return;
    }
    if (pattern == 1 && n == 1)
    { // 先手，先判断是否是五连，然后判断是否有禁手
        if (win(playx, playy, n) == 5)
        {
            arrayForInnerBoardLayout[playx][playy] = n;
            innerLayoutToDisplayArray(playx, playy);
            printf("Work of 邱明阳\n");
            displayBoard();
            printf("先手胜！\n");
            exit(0);
        }
        if (ban(playx, playy) == 1)
        {
            printf("此处为禁手，请重新落子\n");
            player(n);
            return;
        }
        arrayForInnerBoardLayout[playx][playy] = n;
        return;
    }
    if (pattern == 1 && n == 2)
    { // 后手，直接判胜
        if (win(playx, playy, n) != 0)
        {
            arrayForInnerBoardLayout[playx][playy] = n;
            innerLayoutToDisplayArray(playx, playy);
            printf("Work of 邱明阳\n");
            displayBoard();
            printf("后手胜！\n");
            exit(0);
        }
        arrayForInnerBoardLayout[playx][playy] = n;
        return;
    }
    if (pattern == 2 && n == 1)
    { // 先手，先判断是否是五连，然后判断是否有禁手
        if (win(playx, playy, n) == 5)
        {
            arrayForInnerBoardLayout[playx][playy] = n;
            innerLayoutToDisplayArray(playx, playy);
            printf("Work of 邱明阳\n");
            displayBoard();
            printf("玩家胜！\n");
            exit(0);
        }
        if (ban(playx, playy) == 1)
        {
            printf("此处为禁手，请重新落子\n");
            player(n);
            return;
        }
        arrayForInnerBoardLayout[playx][playy] = n;
        return;
    }
    if (pattern == 2 && n == 2)
    { // 后手，直接判胜
        if (win(playx, playy, n) != 0)
        {
            arrayForInnerBoardLayout[playx][playy] = n;
            innerLayoutToDisplayArray(playx, playy);
            printf("Work of 邱明阳\n");
            displayBoard();
            printf("玩家胜！\n");
            exit(0);
        }
        arrayForInnerBoardLayout[playx][playy] = n;
        return;
    }
}

int mygetline(char s[], int lim)//获取键盘输入并存入字符数组
{
    int i, c;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = '\n';
    s[i] = '\0';
    return i;
}

int win(int x, int y, int n)//判胜函数
{
    int i, j, sum;
    // 竖
    i = x - 1;
    j = y;
    sum = 1;
    while (i >= 0 && i <= 14 && j >= 0 && j <= 14 && arrayForInnerBoardLayout[i][j] == n)
    {
        ++sum;
        --i;
    }
    i = x + 1;
    j = y;
    while (i >= 0 && i <= 14 && j >= 0 && j <= 14 && arrayForInnerBoardLayout[i][j] == n)
    {
        ++sum;
        ++i;
    }
    if (sum >= 5)
    { // 胜利
        return sum;
    }

    // 横
    i = x;
    j = y - 1;
    sum = 1;
    while (i >= 0 && i <= 14 && j >= 0 && j <= 14 && arrayForInnerBoardLayout[i][j] == n)
    {
        ++sum;
        --j;
    }
    i = x;
    j = y + 1;
    while (i >= 0 && i <= 14 && j >= 0 && j <= 14 && arrayForInnerBoardLayout[i][j] == n)
    {
        ++sum;
        ++j;
    }
    if (sum >= 5)
    { // 胜利
        return sum;
    }

    // 斜1
    i = x - 1;
    j = y - 1;
    sum = 1;
    while (i >= 0 && i <= 14 && j >= 0 && j <= 14 && arrayForInnerBoardLayout[i][j] == n)
    {
        ++sum;
        --i;
        --j;
    }
    i = x + 1;
    j = y + 1;
    while (i >= 0 && i <= 14 && j >= 0 && j <= 14 && arrayForInnerBoardLayout[i][j] == n)
    {
        ++sum;
        ++i;
        ++j;
    }
    if (sum >= 5)
    { // 胜利
        return sum;
    }

    // 斜2
    i = x - 1;
    j = y + 1;
    sum = 1;
    while (i >= 0 && i <= 14 && j >= 0 && j <= 14 && arrayForInnerBoardLayout[i][j] == n)
    {
        ++sum;
        --i;
        ++j;
    }
    i = x + 1;
    j = y - 1;
    while (i >= 0 && i <= 14 && j >= 0 && j <= 14 && arrayForInnerBoardLayout[i][j] == n)
    {
        ++sum;
        ++i;
        --j;
    }
    if (sum >= 5)
    { // 胜利
        return sum;
    }
    // 四个方向全部判断完返回0，说明没有胜利
    return 0;
}

int search(int x, int y)//访问某一位置的状态
{
    if (x < 0 || x > 14 || y < 0 || y > 14)//越界
        return -1;
    if (arrayForInnerBoardLayout[x][y] == 1)//黑子
    {
        return 1;
    }
    else if (arrayForInnerBoardLayout[x][y] == 2)//白子
    {
        return 2;
    }
    return 0;//无子
}

void ai(int x, int y, int n)//ai在获取最佳落子位置后进行落子和判胜
{
    arrayForInnerBoardLayout[x][y] = n;
    innerLayoutToDisplayArray(x, y);
    printf("Work of 邱明阳\n");
    displayBoard();
    printf("电脑落子：%d%c\n", x + 1, 'a' + y);
    if (win(x, y, n) != 0)
    {
        printf("电脑胜！\n");
        exit(0);
    }
}