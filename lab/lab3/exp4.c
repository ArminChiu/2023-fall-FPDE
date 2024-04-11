#include<stdio.h>

void print(int x){
    printf("%d",x);
    for(int i=1;i<x;i++){
        if(x%i==0) printf(" %d",i);
    }
    printf("\n");
}

int main(){
    for(int i=6;i<=1000;i++){
        int sum=0;
        for(int j=1;j<i;j++){
            if(i%j==0) sum=sum+j;
        }
        if(sum==i) print(i);
    }
    return 0;
}