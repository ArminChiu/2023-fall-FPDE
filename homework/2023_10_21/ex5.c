#include <stdio.h>
#define DATANUM 15
int binsearch(int x,int v[],int n);

int main(){
    int data[]={1,2,3,10,29,33,35,48,54,56,61,62,63,70,79};
    int x;
    int index;
    scanf("%d",&x);
    index=binsearch(x,data,DATANUM);
    if(index!=-1)
        printf("index = %d \n",index);
    else
        printf("%d is no in thee arry\n",x);
    return 0;
}

int binsearch(int x, int v[], int n){
    int low,high,mid;
    low=0;
    high=n-1;
    while(low<=high){
        mid=(high+low)/2;
        if(x>v[mid])
            low=mid+1;
            else if(x<v[mid])
                high=mid-1;
            else
                return mid;
    }
    return -1;
}