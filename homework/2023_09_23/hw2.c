#include <stdio.h>

int main(){
    int nw,state,c,capital,lower,other;
    state=nw=capital=lower=0;
    while((c=getchar())!=EOF){
        if(c==' '||c=='\t'||c=='\n'){
            state=0;
        }else{
            if(state==0){
                if(c>='a'&&c<='z')
                    lower++;
                if(c>='A'&&c<='Z')
                    capital++;
                nw++;
                state=1;
            }
        }
    }
    other=nw-capital-lower;
    printf("\nCapitalized words:%d\nLowercase letter starting words:%d\nOther words:%d\n",capital,lower,other);
    return 0;
}