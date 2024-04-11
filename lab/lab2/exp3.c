#include <stdio.h>

int main(){
    int c,state;
    state=0;
    while((c=getchar())!=EOF){
        if(c!='\n'&&c!='\t'&&c!=' '){
            if(state==0){
                state=1;
                if(c>='a'&&c<='z')
                    c=c-32;
            }
            else
                if(c>='A'&&c<='Z')
                    c=c+32;
        }else if(state==1){
            state=0;
        }
        putchar(c);
    }
    return 0;
}