#include <stdio.h>
char *month_name(int n);
int main(){
    int n;
    char *pname;
    printf("Input number:");
    scanf("%d",&n);
    pname=month_name(n);
    printf("%s\n",pname);
    return 0;
}