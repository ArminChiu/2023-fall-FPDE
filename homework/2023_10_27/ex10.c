#include <stdio.h>

int main(){
    void shellsort(int s[],int len);
    int s[]={3,1,59,2,6,53};
    shellsort(s,6);
    for(int i=0;i<6;i++){
        printf("%d ",s[i]);
    }
    
    return 0;
}

void shellsort(int s[],int len){
    int i,j,gap;
    int temp;
    for(gap=len/2;gap>0;gap/=2)
        for(i=gap;i<len;i+=1){
            for(j=i-gap;j>=0 && s[j]>s[j+gap];j-=gap){
                temp=s[j+gap];
                s[j+gap]=s[j];
                s[j]=temp;
            }
        }
}