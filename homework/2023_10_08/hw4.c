#include <stdio.h>
#define MAXLINE 1000
char line[MAXLINE];

int mygetline(int x){
    int c,i;
    for(i=0;i<MAXLINE-1&&(c=getchar())!=EOF&&c!='\n';i++)
        line[i]=c;
    if(c=='\n'){
        line[i]='\n';
        i++;
    }
    line[i]='\0';
    if(i>=x)
        printf("%s",line);
    return i;
}

int main(){
    int n;
    scanf("%d",&n);
    while((mygetline(n))>0){}
    return 0;
}