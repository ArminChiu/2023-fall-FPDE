#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 15
#define CHARSIZE 3

//函数声明
void initRecordBorard(void);//初始化棋盘
void innerLayoutToDisplayArray(void);//读取心中棋盘，写入实际棋盘
void displayBoard(void);//展示实际棋盘
void player(int n);//玩家下棋函数
int win(int n,int x,int y);//判胜函数
void ai(int n);//ai函数


//变量声明
int x,y;//全局变量表示棋子在X行Y列

struct SingleInfo{
    int linkNum;
    int oppNum;
};

struct SingleScore{
    struct SingleInfo info[4];
    int score;
};



//空棋盘 
char arrayForEmptyBoard[SIZE][SIZE*CHARSIZE+1]={
		"┏┯┯┯┯┯┯┯┯┯┯┯┯┯┓",
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
		"┗┷┷┷┷┷┷┷┷┷┷┷┷┷┛"
};
//此数组存储用于显示的棋盘 
char arrayForDisplayBoard[SIZE][SIZE*CHARSIZE+1];
 
char play1Pic[]="●";//黑棋子;
char play1CurrentPic[]="▲"; 

char play2Pic[]="◎";//白棋子;
char play2CurrentPic[]="△";

//此数组用于记录当前的棋盘的格局 
int arrayForInnerBoardLayout[SIZE][SIZE];


//函数定义
int main(){
    initRecordBorard();
    printf("请选择游玩模式:1.人人对战 2.人机对战\n");
    int pattern,turn;//模式，先后手
    scanf("%d",&pattern);
    getchar();
    innerLayoutToDisplayArray();//空棋盘展示
    while(pattern==1){//人人对战
        player(1);//落子
        innerLayoutToDisplayArray();//转换
        displayBoard();//打印
        if(win(1,x,y)==1){//判胜
            printf("先手胜！\n");
            break;
        }
        player(2);
        innerLayoutToDisplayArray();
        displayBoard();
        if(win(2,x,y)==1){
            printf("后手胜！\n");
            break;
        }
    }
    if(pattern==2){//人机对战
        printf("请选择玩家先后手:1.先手 2.后手\n");
        scanf("%d",&turn);
        getchar();
        innerLayoutToDisplayArray();
        while(turn==1){
            player(1);//落子
            innerLayoutToDisplayArray();//转换
            displayBoard();//打印
            if(win(1,x,y)==1){//判胜
                printf("玩家胜！\n");
                break;
            }
            ai(2);
            innerLayoutToDisplayArray();
            displayBoard();
            if(win(2,x,y)==1){
                printf("AI胜！\n");
                break;
            }
        }
        while(turn==2){
            ai(1);
            innerLayoutToDisplayArray();
            displayBoard();
            if(win(1,x,y)==1){
                printf("AI胜！\n");
                break;
            }
            player(2);
            innerLayoutToDisplayArray();
            displayBoard();
            if(win(2,x,y)==1){
                printf("玩家胜！\n");
                break;
            }
        }
    }
    return 0;
}

//初始化棋盘
void initRecordBorard(void){
    for(int i=0;i<SIZE;++i){
        for(int j=0;j<SIZE;++j){
            arrayForInnerBoardLayout[i][j]=0;
        }
    }
}

//将棋子位置转化到棋盘中
void innerLayoutToDisplayArray(void){
    for(int i=0;i<SIZE;++i){
        for(int j=0;j<SIZE*CHARSIZE+1;++j){
            arrayForDisplayBoard[i][j]=arrayForEmptyBoard[i][j];
        }
    }
	//第二步：扫描arrayForInnerBoardLayout，当遇到非0的元素，将●或者◎复制到arrayForDisplayBoard的相应位置上
	//注意：arrayForDisplayBoard所记录的字符是中文字符，每个字符占2个字节。●和◎也是中文字符，每个也占2个字节。
    for(int i=0;i<SIZE;++i){
        for(int j=0;j<SIZE;++j){
            if(arrayForInnerBoardLayout[i][j]==1){
                arrayForDisplayBoard[i][j*CHARSIZE]=play1Pic[0];
                arrayForDisplayBoard[i][j*CHARSIZE+1]=play1Pic[1];
                arrayForDisplayBoard[i][j*CHARSIZE+2]=play1Pic[2];
            }
            if(arrayForInnerBoardLayout[i][j]==2){
                arrayForDisplayBoard[i][j*CHARSIZE]=play2Pic[0];
                arrayForDisplayBoard[i][j*CHARSIZE+1]=play2Pic[1];
                arrayForDisplayBoard[i][j*CHARSIZE+2]=play2Pic[2];
            }
        }
    }
    //把最后一子改成三角形
    if(arrayForInnerBoardLayout[x][y]==1){
        arrayForDisplayBoard[x][y*CHARSIZE]=play1CurrentPic[0];
        arrayForDisplayBoard[x][y*CHARSIZE+1]=play1CurrentPic[1];
        arrayForDisplayBoard[x][y*CHARSIZE+2]=play1CurrentPic[2];
    }
    if(arrayForInnerBoardLayout[x][y]==2){
        arrayForDisplayBoard[x][y*CHARSIZE]=play2CurrentPic[0];
        arrayForDisplayBoard[x][y*CHARSIZE+1]=play2CurrentPic[1];
        arrayForDisplayBoard[x][y*CHARSIZE+2]=play2CurrentPic[2];
    }
}


//显示棋盘格局 
void displayBoard(void){
	int i;
	system("clear");   //清屏  
    for(int i=0;i<SIZE;++i){
        printf("%3d %s\n",i+1,arrayForDisplayBoard[i]);
    }
    printf("     A B C D E F G H I J K L M N O\n");
}

//玩家落子
void player(int n){
    int i;
    char line[100];
    int mygetline(char s[],int lim);
    if(n==1){
        printf("先手请落子\n");
    }else if(n==2){
        printf("后手请落子\n");
    }
    i=mygetline(line,100);
    if(line[0]=='q' && line[1]=='u' && line[2]=='i' && line[3]=='t'){//quit
        exit(0);
    }
    if(line[0]>='a' && line[0]<='o'){//小写字母在前，数字在后
        y=line[0]-'a';
        if(line[1]>='0' && line[1]<='9'){
            x=line[1]-'1';
            if(line[2]>='0' && line[2]<='9'){
                x=10+line[2]-'1';
            }
        }
    }
    if(line[0]>='A' && line[0]<='O'){//大写字母在前，数字在后
        y=line[0]-'A';
        if(line[1]>='0' && line[1]<='9'){
            x=line[1]-'1';
            if(line[2]>='0' && line[2]<='9'){
                x=10+line[2]-'1';
            }
        }
    }
    if(line[0]>='0' && line[0]<='9'){//数字在前，小写字母在后
        x=line[0]-'1';
        if(line[1]>='a' && line[1]<='o')
            y=line[1]-'a';
        if(line[1]>='0' && line[1]<='9'){
            x=10+line[1]-'1';
            if(line[2]>='a' && line[2]<='o')
                y=line[2]-'a';
        }
    }
    if(line[0]>='0' && line[0]<='9'){//数字在前，大写字母在后
        x=line[0]-'1';
        if(line[1]>='A' && line[1]<='O')
            y=line[1]-'A';
        if(line[1]>='0' && line[1]<='9'){
            x=10+line[1]-'1';
            if(line[2]>='A' && line[2]<='O')
                y=line[2]-'A';
        }
    }
    if(arrayForInnerBoardLayout[x][y]!=0){
        printf("此处已有子，请重新落子\n");
        player(n);//重新进入函数
    }else{
        arrayForInnerBoardLayout[x][y]=n;
    }
}

int mygetline(char s[],int lim){
    int i,c;
    i=0;
    while(--lim>0 && (c=getchar())!=EOF && c!='\n')
        s[i++]=c;
    if(c=='\n')
        s[i++]='\n';
    s[i]='\0';
    return i;
}

int win(int n,int x,int y){
    int i,j,sum;
    //竖
    i=x;
    j=y;
    sum=0;
    while(i>=0 && i<=14 && j>=0 && j<= 14 && arrayForInnerBoardLayout[i][j]==n){
        ++sum;
        --i;
    }
    i=x+1;
    j=y;
    while(i>=0 && i<=14 && j>=0 && j<= 14 && arrayForInnerBoardLayout[i][j]==n){
        ++sum;
        ++i;
    }
    if(sum>=5){//胜利
        return 1;
    }

    //横
    i=x;
    j=y;
    sum=0;
    while(i>=0 && i<=14 && j>=0 && j<= 14 && arrayForInnerBoardLayout[i][j]==n){
        ++sum;
        --j;
    }
    i=x;
    j=y+1;
    while(i>=0 && i<=14 && j>=0 && j<= 14 && arrayForInnerBoardLayout[i][j]==n){
        ++sum;
        ++j;
    }
    if(sum>=5){//胜利
        return 1;
    }

    //斜1
    i=x;
    j=y;
    sum=0;
    while(i>=0 && i<=14 && j>=0 && j<= 14 && arrayForInnerBoardLayout[i][j]==n){
        ++sum;
        --i;
        --j;
    }
    i=x+1;
    j=y+1;
    while(i>=0 && i<=14 && j>=0 && j<= 14 && arrayForInnerBoardLayout[i][j]==n){
        ++sum;
        ++i;
        ++j;
    }
    if(sum>=5){//胜利
        return 1;
    }

    //斜2
    i=x;
    j=y;
    sum=0;
    while(i>=0 && i<=14 && j>=0 && j<= 14 && arrayForInnerBoardLayout[i][j]==n){
        ++sum;
        --i;
        ++j;
    }
    i=x+1;
    j=y-1;
    while(i>=0 && i<=14 && j>=0 && j<= 14 && arrayForInnerBoardLayout[i][j]==n){
        ++sum;
        ++i;
        --j;
    }
    if(sum>=5){//胜利
        return 1;
    }

    //四个方向全部判断完，说明没有胜利
    return 0;
}