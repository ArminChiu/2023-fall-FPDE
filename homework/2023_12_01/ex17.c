#include <stdio.h>

int main(){
    int array[]={0,1,2,3,4,5,6,7,8,9};
    int *p;
    p=array;
    printf("*++p=%d \n",*++p);
    printf("p[3]=%d \n",p[3]);
    printf("p++[2]=%d \n",p++[2]);
    printf("*(p+=3)=%d \n",*(p+=3));
    printf("*p+=2=%d \n",*p+=2);
    printf("*p++=%d \n",*p++);
    printf("p[1]=%d \n",p[1]);
    printf("*p--=%d \n",*p--);
    printf("p[3]=%d \n",p[3]);
    return 0;
}