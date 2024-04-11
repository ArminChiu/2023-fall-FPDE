#include <stdio.h>

int main(){
    long nc=0;
    int c;
    c=getchar();
    while(c!=EOF){
        nc++;
        c=getchar();
    }
    printf("\nthe total number:%ld\n",nc);
    return 0;
}