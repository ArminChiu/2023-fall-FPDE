#include <stdio.h>

int main(){
    int prime(int x);
    for(int i=2;i<=1000;i++){
        if(prime(i)==1)
        printf("%d\n",i);
    }
    return 0;
}

int prime(int x){
    for(int i=2;i<x;i++){
        if(x%i==0)
            return 0;
    }
    return 1;
}