#include <stdio.h>
#define MAXLINE 100

int main(){
    char pattern[MAXLINE];
    char line[MAXLINE];
    int found=0;
    int strindex(char s[],char t[]);
    int mygetline(char s[],int lim);
    mygetline(line,MAXLINE);
    mygetline(pattern,MAXLINE);
    printf("%d",strindex(line,pattern));
    return found;
}

int mygetline(char s[],int lim){
    int i,c;
    i=0;
    while(--lim>0 && (c=getchar())!=EOF && c!='\n')
        s[i++]=c;
    if(c=='\n')
        s[i++]='\0';
    return i;
}

int strindex(char s[],char t[]){
    int i,j,k;
    for(i=0;s[i]!='\0';i++){
        for(j=i,k=0;(t[k]!='\0')&&((s[j]==t[k])||((t[k]=='@')&&((s[j]>='a'&&s[j]<='z')||(s[j]>='A'&&s[j]<='Z')))||((t[k]=='*')&&(s[j]>='0'&&s[j]<='9')));j++,k++){
            ;
        }
        if(k>0 && t[k]=='\0')
            return i;
    }
    return -1;
}