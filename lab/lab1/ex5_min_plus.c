#include <stdio.h>

int main()
{
    int min(int x,int y,int z);
    int a, b, c, d;
    scanf("%d,%d,%d",&a,&b,&c);
    d=min(a,b,c);
    printf("min=%d\n",d);
    return 0;
}

int min(int x,int y,int z)
{
    int w;
    if(x<=y&&x<=z)
        w=x;
    else
    {
        if(y<=x&&y<=z)
            w=y;
        else
            w=z;
    }
    return w;
}