#include<stdio.h>
#include<string.h>
#define MAXLINE 1000

int main(int argc,char *argv[]){
    int c,n=0,k=0;
    if((*++argv)[0]=='-'){
        while(c=*++argv[0]){
            if(c>='0' && c<= '9')
                n=n*10+c-'0';
            else break;
        }
    }
    if((*++argv)[0]=='-'){
        while(c=*++argv[0]){
            if(c>='0' && c<= '9')
                k=k*10+c-'0';
            else break;
        }
    }
    int circle[n+1];
    for(int i=0;i<=n;++i)
        circle[i]=1;
        circle[0]=n;
    for(int i=1,j=1;circle[0]>0;++i){
        while(circle[j]==0){
            if(j==n){
                j=1;
            }else{
                ++j;
            }
        }
        if(i%k==0){
            circle[j]=0;
            --circle[0];
            printf("%d\n",j);
        }
        if(j==n){
            j=1;
        }else{
            ++j;
        }
    }
    return 0;
}
