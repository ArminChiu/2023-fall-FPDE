#include <stdio.h>

union u_tag{
    int ival;
    float fval;
    char *sval;
}a;

int main(){
    union u_tag b,*p;
    a.fval=1.0;
    p=&a;
    printf("(*p).fval:%f\n",(*p).fval);
    printf("p->fval:%f\n",p->fval);
    p->fval=2.0;
    b=a;
    printf("b.fval:%f\n",b.fval);
    return 0;
}