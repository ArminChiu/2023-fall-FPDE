#include <stdio.h>
/*
int arr1[1000];
int arr2[1000];
int arr3[1000];
*/

void insertSort(int arr[],int len){
    int c;
    for(int i=1;i<len;i++){
        for(int a=i;a>0 && arr[a-1] > arr[a];a--){
            c=arr[a];
            arr[a]=arr[a-1];
            arr[a-1]=c;
        }
    }
}

int main(){
    int n1,n2,n3;
    
    scanf("%d",&n1);
    int arr1[n1];
    for(int i=0;i<n1;i++) scanf("%d",&arr1[i]);
    insertSort(arr1,n1);
    
    scanf("%d",&n2);
    int arr2[n2];
    for(int i=0;i<n2;i++) scanf("%d",&arr2[i]);
    insertSort(arr2,n2);
    
    scanf("%d",&n3);
    int arr3[n3];
    for(int i=0;i<n3;i++) scanf("%d",&arr3[i]);
    insertSort(arr3,n3);
    
    for(int i=0;i<n1-1;i++) printf("%d ",arr1[i]); printf("%d\n",arr1[n1-1]);
    for(int i=0;i<n2-1;i++) printf("%d ",arr2[i]); printf("%d\n",arr2[n2-1]);
    for(int i=0;i<n3-1;i++) printf("%d ",arr3[i]); printf("%d\n",arr3[n3-1]);
    
    return 0;
}