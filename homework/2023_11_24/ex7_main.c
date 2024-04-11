#include <stdio.h>
#define SIZE 10
int array[SIZE];

int main(){
    int n,getint(int*);
    for(n=0;n<SIZE && getint(&array[n])!=EOF;n++)
        ;
    for(n=0;n<SIZE;n++)
        printf("array[%d]=%d\n",n,array[n]);
    return 0;
}