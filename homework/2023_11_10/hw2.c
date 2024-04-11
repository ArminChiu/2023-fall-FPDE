#include <stdio.h>

int num=0;

int main(){
    char s[100];
    int i=-20231110;
    for(int j=0;j<100;j++)
        s[j]='\0';
    void itoa(char s[],int i);
    itoa(s,i);
    printf("%s\n",s);
    return 0;
}

void itoa(char s[],int i){
    if(i<0){
        s[num]='-';
        num++;
        i=-i;
    }
    if(i/10)
        itoa(s,i/10);
    s[num]=i%10+'0';
    num++;
}