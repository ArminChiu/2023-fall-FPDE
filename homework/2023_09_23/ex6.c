#include <stdio.h>

int main(){
    int power(int x,int y);
    int m,n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        printf("%3d %6d %6d\n",i,power(2,i),power(-3,i));
    return 0;
}

int power(int x,int y){
    int z=1;
    for(int i=1;i<=y;i++)
        z*=x;
    return z;
}