#include <stdio.h>
#include <ctype.h>

int main(){
    char s[100];
    int c;
    int len=0;
    while((c=getchar())!='\n'){
        s[len]=c;
        len++;
    }
    s[len]='\0';
    double d;
    double atof(char s[]);
    d=atof(s);
    printf("%.6le\n",d);
    return 0;
}

double atof(char s[]){
    double val,power;
    int sign2,val2;
    int i,sign;
    for(i=0;isspace(s[i]);i++)
        ;
    sign=(s[i]=='-')?-1:1;
    if(s[i]=='-'||s[i]=='+')
        i++;
    for(val=0.0;isdigit(s[i]);i++)
        val=10.0*val+s[i]-'0';
    if(s[i]=='.')
        i++;
    for(power=1.0;isdigit(s[i]);i++){
        val=10.0*val+s[i]-'0';
        power*=10.0;
    }
    if(s[i]=='E'||s[i]=='e')
        i++;
    sign2=(s[i]=='-')?-1:1;
    if(s[i]=='-'||s[i]=='+')
        i++;
    for(val2=0;isdigit(s[i]);i++)
        val2=10*val2+s[i]-'0';
    if(sign2==1){
        for(int j=1;j<=val2;j++)
            val*=10;
    }else if(sign2==-1){
        for(int j=1;j<=val2;j++)
            val/=10;
    }
    return sign*val/power;
}