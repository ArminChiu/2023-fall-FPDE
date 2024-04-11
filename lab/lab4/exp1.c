#include <stdio.h>

int main(){
    int plusit(int a[],int len);
    int a[31];
    for(int i=0;i<=31;i++){
        a[i]=0;
    }
    a[1]=1;
    int num;
    scanf("%d",&num);
    if(num!=0){
        printf("1\n");
    }
    for(int i=1;i<num;i++){
        plusit(a,i);
    }
    return 0;
}

int plusit(int a[],int len){
    for(int i=len+1;i>0;i--){
        a[i]+=a[i-1];
    }
    for(int i=1;i<=len+1;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}