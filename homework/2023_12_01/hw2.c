#include <stdio.h>
float a;
float result;

int main(){
    scanf("%f",&a);
    void squaref(float x);
    squaref(a);
    printf("%f\n",result);
    return 0;
}

void squaref(float x){
    result=(x+a/x)/2;
    if(result-x>=0.00001 || x-result>=0.00001)
        squaref(result);
}