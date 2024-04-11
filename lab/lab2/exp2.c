#include <stdio.h>

int main(){
    int m,n,max,min,lcm,gcd;
    scanf("%d %d",&m,&n);
    if(m>n){
        max=m;
        min=n;
    }
    else{
        max=n;
        min=m;
    }
    gcd=1;
    lcm=min;
    for(int i=2;i<=min;i++){
        if(m%i==0&&n%i==0)
        gcd=i;
    }
    lcm=m*n/gcd;
    printf("%d %d\n",gcd,lcm);
    return 0;
}