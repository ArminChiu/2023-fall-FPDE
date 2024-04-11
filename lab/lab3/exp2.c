#include <stdio.h>
#define minLINE 1000

int mygetline(char line[],int minline);
void copy(char to[],char from[]);

int main(){
    int len,min1,min2;
    char line[minLINE];
    char shortest1[minLINE];
    char shortest2[minLINE];
    min1=1000;
    min2=1000;
    while((len=mygetline(line,minLINE))>0){
    if(len<min2&&len>=min1){
        min2=len;
        copy(shortest2,line);
    }
    if(len<min1){
        min2=min1;
        min1=len;
        copy(shortest2,shortest1);
        copy(shortest1,line);
    }
    }
    if(min1>0){
        printf("%s%s",shortest1,shortest2);
    }
    return 0;
}

int mygetline(char s[],int lim){
    int c,i;
    for(i=0;i<lim-1&&(c=getchar())!=EOF&&c!='\n';++i){
        s[i]=c;
    }
if(c=='\n'){
    s[i]=c;
    ++i;
}
s[i]='\0';
return i;
}

void copy(char to[],char from[]){
    int i;
    i=0;
    while((to[i]=from[i])!='\0'){
    ++i;}
}