#include <stdio.h>
#include <stdio.h>

int main()
{
    int max_min(int x,int y,int z,int mode);
    int a, b, c, d, e;
    scanf("%d,%d,%d,%d",&a,&b,&c,&d);
    e=max_min(a,b,c,d);
    if(d==0)
        printf("min=%d\n",e);
    else
        printf("max=%d\n",e);
    return 0;
}

int max_min(int x,int y,int z,int mode)//0==min 1==max
{
    int w;
    if(mode==0){
        if(x<=y&&x<=z)
            w=x;
        else
        {
            if(y<=x&&y<=z)
                w=y;
            else
                w=z;
        }
    }
    if(mode==1){
        if(x>=y&&x>=z)
            w=x;
        else
        {
            if(y>=x&&y>=z)
                w=y;
            else
                w=z;
        }
    }
    return w;
}