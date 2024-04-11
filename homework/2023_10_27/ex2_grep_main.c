#include <stdio.h>
#define MAXLINE 100
char pattern[]="ould";

int main(){
    char line[MAXLINE];
    int found=0;
    int strindex(char s[],char t[]);
    int mygetline(char s[],int lim);
    while(mygetline(line,MAXLINE)>0)
        if(strindex(line,pattern)>=0){
            printf("%s",line);
            found++;
        }
    return found;
}