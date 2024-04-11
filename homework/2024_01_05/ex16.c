#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRINGLEN 100
#define ARRAYLEN 10
typedef char *String;
typedef String StringArray[ARRAYLEN];
typedef char CharArray[STRINGLEN];

int main(){
    CharArray ca;
    StringArray sa;
    String ps;
    int i;
    for(i=ARRAYLEN-1;i>=0;i--){
        printf("Input string %d:",i);
        scanf("%s",ca);
        ps=(String)malloc(strlen(ca)+1);
        strcpy(ps,ca);
        sa[i]=ps;
    }
    printf("Data in array sa:\n");
    for(i=0;i<ARRAYLEN;i++){
        printf("sa[%d]:\"%s\"\n",i,sa[i]);
    }
    return 0;
}