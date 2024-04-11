#include <stdio.h>
#define square1(x) x*x
#define square2(x) (x)*(x)
#define dprint1(expr) printf(#expr)
#define dprint2(expr) printf(#expr "=%g\n",expr)

int main(){
    double a=3.0,b=19.0;
    dprint1(Interesting Macro.\n);
    printf("Hello" " world!\n");
    dprint2(square1(a+b));
    dprint2(square2(a+b));
    return 0;
}