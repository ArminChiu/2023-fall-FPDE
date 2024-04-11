#include <stdio.h>

int main(){
    char s[100];
    void itoh(int x,char s[]);
    int x;
    scanf("%d",&x);
    itoh(x,s);
    printf("0x%s",s);
}

void itoh(int x,char s[]){
    int num=x;
    int i;
    int a[100];
    for(i=0;num>0;i++){
        a[i]=num % 16;
        num-=a[i];
        num/=16;
    }
    for(int j=i;j>=0;j--){
        if(a[j]>=0&&a[j]<=9)
            s[i-j-1]='0'+a[j];
        else if(a[j]>=10&&a[j]<=15)
            s[i-j-1]='a'+a[j]-10;       
    }
    s[i+1]='\0';
}