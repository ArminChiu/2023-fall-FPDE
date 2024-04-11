#include <stdio.h>

union u_tag{
    int ival;
    float fval;
    char *sval;
}a;

int main(){
    printf("sizeof u_tag:%ld");
    a.fval=1.0;
    printf("a.fval:%f\n",a.fval);
    printf("a.ival:0x%x\n",a.ival);
    a.ival=0x40133333;
    printf("a.fval:%f\n",a.fval);
    printf("a.ival:0x%x\n",a.ival);
    return 0;
}