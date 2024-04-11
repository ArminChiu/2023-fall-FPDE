#include <stdio.h>
#define LEN 10
typedef int Length;
typedef int * Pointer;
typedef int Array[LEN];
typedef int Func(int);
typedef Func (*Fp);

int main(){
    int square(int len);
    Length len;
    Pointer p;
    Array a;
    Fp f;
    int i;
    f=square;
    for(i=0;i<LEN;i++)
        a[i]=(*f)(i);
    for(p=a;p<a+LEN;p++)
        printf("%3d ",*p);
    printf("\n");
    return 0;
}

int square(int n){
    return n*n;
}