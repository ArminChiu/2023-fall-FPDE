#include <stdio.h>

int main(){
    int prime(int x);
    float sum=0;
    float term;
    for(int i=2;i<1000;i++){
        if(prime(i)==1){
        term=1.0/i;
        sum=sum+term;
        }
    }
    printf("sum = %f \n",sum);
    return 0;
}

int prime(int x){
    for(int i=2;i<x;i++){
        if(x%i==0)
            return 0;
    }
    return 1;
}