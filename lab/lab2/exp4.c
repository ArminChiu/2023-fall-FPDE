#include <stdio.h>

int main(){
    int c,state,a[26];
    state=0;
    for(int i=0;i<=25;i++)
        a[i]=0;
    while((c=getchar())!=EOF){
        if(c!='\n'&&c!='\t'&&c!=' '){
            if(state==0){
                state=1;
                if(c>='a'&&c<='z')
                    c=c-32;
                    a[c-65]++;
            }
            else
                if(c>='A'&&c<='Z')
                    c=c+32;
        }else if(state==1){
            state=0;
        }
        putchar(c);
    }
    for(int i=0;i<=25;i++)
        printf("\n%c: %d\n",i+65,a[i]);
    return 0;
}