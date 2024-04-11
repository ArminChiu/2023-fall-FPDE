#include <stdio.h>
int main()
{
    int caculate(int x,int y);
    int a,b,c;
    a=10;
    b=8;
    c=caculate(a,b);
    printf("c=%d\n",c);
    a=7;
    b=12;
    c=caculate(a,b);
    printf("c=%d\n",c);
    return 0;
}

int caculate(int x, int y)
{
    int z;
    if(x>y)
        z=x-y;
    else
        z=x*y;
    return z;
}
/*第6行，将变量a赋值为10。
第7行，将变量b赋值为8。
第8行，程序调用函数caculate，实参a是10，b是8。
第17行，程序执行至函数caculate入口，形参x是10，y是8。
第20行，程序执行x>y判断，条件成立，跳转到第21行。
第21行，将变量z赋值为x-y的值2。
第24行，返回变量z的值2。
第8行，将变量c赋值为caculate函数的返回值2。
第9行，利用系统库函数printf打印出变量c的值2。
第10行，将变量a赋值为7。
第11行，将变量b赋值为12。
第12行，程序调用函数caculate，实参a是7，b是12。
第17行，程序执行至函数caculate入口，形参x是7，y是12。
第20行，程序执行x>y判断，条件不成立，跳转到第23行。
第23行，将变量z赋值为x*y的值84。
第24行，返回变量z的值84。
第8行，将变量c赋值为caculate函数的返回值84。
第9行，利用系统库函数printf打印出变量c的值84。*/