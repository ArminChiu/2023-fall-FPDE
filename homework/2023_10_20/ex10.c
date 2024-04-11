#include <stdio.h>

int main(){
    int a=5,b=10;
    b=b+a++;
    printf("b=%d a=%d\n",b,a);
    return 0;
}