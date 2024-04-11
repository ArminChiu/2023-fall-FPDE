#include <stdio.h>
int main(){
    float sign=1;
    float sum=0;
    float deno=1;
    float term;
    do{
        term=sign*(1/deno);
        sum=sum+term;
        sign=-1*sign;
        deno=deno+1;
    }while(deno<=100);
    printf("sum = %f \n",sum);
    return 0;
}