#include <stdio.h>
#define LOWER 2000
#define UPPER 2100
int main(){
    int isLeapYear(int year);
    int year;
    year=LOWER;
    do{
        if(isLeapYear(year)==1)
            printf("%d is leap year\n",year);
        else
            printf("%d is not leap year\n",year);
            year=year+1;
    }while (year<=UPPER);
    return 0;
}

int isLeapYear(int year){
    int r;
    r=year%4;
    if(r!=0){
        return 0;
    }else{
        r=year%100;
        if(r!=0){
            return 1;
        }else{
            r=year%400;
            if(r==0){
                return 1;
            }else{
                return 0;
            }
        }
    }
}