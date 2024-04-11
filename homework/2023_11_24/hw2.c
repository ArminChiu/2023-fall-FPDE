#include <stdio.h>
#define MAXLEN 100

int main(){
    int mygetline(char s[],int lim);
    void shuffle(char s[],int m);
    char s[MAXLEN];
    int m;
    mygetline(s,MAXLEN);
    scanf("%d",&m);
    shuffle(s,m);
    printf("%s",s);
}

int mygetline(char s[],int lim){
    int i,c;
    i=0;
    while(--lim>0 && (c=getchar())!=EOF && c!='\n')
        s[i++]=c;
    s[i]='\0';
    return i;
}

void shuffle(char s[],int m){
    char t[m];
    char *ps=s;
    char *pt=t;
    int i;
    for(i=0;i<m;i++)
        pt[i]=ps[i];
    for(i=m;ps[i]!='\0';i++)
        ps[i-m]=ps[i];
    for(int j=0;j<m;j++,i++)
        ps[i-m]=pt[j];
}