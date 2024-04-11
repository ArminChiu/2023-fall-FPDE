#include <stdio.h>

int main(){
    static char name1[13][15]={
        "Illegal month",
        "january","February","March",
        "April","May","June",
        "July","August","September",
        "October","November","December"
    };
    static char *name2[13]={
        "Illegal month",
        "january","February","March",
        "April","May","June",
        "July","August","September",
        "October","November","December"
    };
    printf("size of name1=%3ld \n",sizeof(name1));
    printf("size of name2=%3ld \n",sizeof(name2));
    printf("name1[1][0]=%c\n",name1[1][0]);
    printf("name2[1][0]=%c\n",name2[1][0]);
    name2[1]=name2[2];
    printf("name2[1][0]=%c\n",name2[1][0]);
    return 0;
}