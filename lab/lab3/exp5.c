#include <stdio.h>

int main(){
    for(int i=100;i<=999;i++){
        int a1=i%10;
        int a2=(i-a1)/10%10;
        int a3=(i-a1-10*a2)/100%10;
        if(a1*a1*a1+a2*a2*a2+a3*a3*a3==i) printf("%d\n",i);
    }
    return 0;
}