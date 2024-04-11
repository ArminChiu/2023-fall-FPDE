#include<stdio.h>
int replacePart(int x,int y,int p,int len);
int main(){
       int x,y,p,len;
       int num;
       scanf("%d %d %d %d",&x,&y,&p,&len);
       num=replacePart(x,y,p,len);
       printf("%d",num);
       return 0;
}

int replacePart(int x,int y,int p,int len){
   int  m,n,o,r;
   m=x;
   n=(y&(~(~0<<len)))<<(p-len+1);
   o=m&(~(((~0)<<(p-len+1))^(int)((~0ul)<< (p+1) )));
   r=o|n;
   return r;
}