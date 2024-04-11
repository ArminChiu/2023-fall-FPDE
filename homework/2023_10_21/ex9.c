#include <ctype.h>
#include<stdio.h>
int atoi(char s[]){
    int i,n,sign;
    for(i=0;isspace(s[i]);++i)
        ;
    sign=(s[i]=='-')?-1:1;

    if(s[i]=='-'||s[i]=='+')
        ++i;
    for(n=0;isdigit(s[i]);i++)
        n=n*10+(s[i]-'0');
    return sign*n;
}

int main(){
    char stringdata1[]="416";
    char stringdata2[]="    416";
    char stringdata3[]="    -416";
    char stringdata4[]=" + 416";
    char stringdata5[]="-4 1 6";
    int d;
    d=atoi(stringdata1);
    printf("stringdata1=\"%s\", atoivalue=%d\n",stringdata1,d);
    d=atoi(stringdata2);
    printf("stringdata2=\"%s\", atoivalue=%d\n",stringdata2,d);
    d=atoi(stringdata3);
    printf("stringdata3=\"%s\", atoivalue=%d\n",stringdata3,d);
    d=atoi(stringdata4);
    printf("stringdata4=\"%s\", atoivalue=%d\n",stringdata4,d);
    d=atoi(stringdata5);
    printf("stringdata5=\"%s\", atoivalue=%d\n",stringdata5,d);
    return 0;
}