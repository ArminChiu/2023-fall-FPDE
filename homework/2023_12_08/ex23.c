#include <stdio.h>
int main(){
    int i=0;
    int arr0[]={1,2,3,4,5};
    int arr1[]={11,12,13,14,15};
    int arr2[]={21,22,23,24,25};
    int arr3[]={31,32,33,34,35};
    int arr4[]={41,42,43,44,45};
    int *ap[]={arr0,arr1,arr2,arr3,arr4};
    int **p2p;
    printf("ADR: %14s %14s %14s %14s %14s\n","arr0","arr1","arr2","arr3","arr4");
    printf("     %14p %14p %14p %14p %14p\n",arr0,arr1,arr2,arr3,arr4);
    p2p=ap;
    printf("p2p=%p,*p2p=%p,**p2p=%d\n",p2p,*p2p,**p2p);
    ++p2p;
    printf("p2p=%p,*p2p=%p,**p2p=%d\n",p2p,*p2p,**p2p);
    ++*p2p;
    printf("p2p=%p,*p2p=%p,**p2p=%d\n",p2p,*p2p,**p2p);
    ++p2p,++*p2p,++**p2p;
    printf("p2p=%p,*p2p=%p,**p2p=%d\n",p2p,*p2p,**p2p);
    return 0;
}