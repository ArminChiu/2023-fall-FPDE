#include <stdio.h>

int main(){
    double sum=1.0;
    int m=1;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
           m*=j;
        }
        sum+=1.0/m;
        m=1;
    }
    printf("%.6f\n",sum);
    return 0;
}