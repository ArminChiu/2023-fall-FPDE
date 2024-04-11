#include <stdio.h>

char s[1000];
int a[1000];
int start;

int mygetline(char s[]){
    int c,i;
    for(i=0;i<1000&&(c=getchar())!=EOF&&c!='\n';i++){
        s[i]=c;
    }
    s[i]='\0';
    return i;
}

int judge(char s[],int len){
    if(len>2){
        if(s[0]>='1'&&s[0]<='9')
            return 10;
        else if(s[0]=='0'){
            if(s[1]=='x'||s[1]=='X')
                return 16;
            else if(s[1]=='b'||s[1]=='B')
                return 2;
            else if(s[1]>='1'&&s[1]<='9')
                return 8;
            else
                return 0;
        }
        else
            return 0;
    }
    else if(len<=2){
        if(s[0]=='0'){
            if(s[1]=='\0')
                return 10;
            else if(s[1]>='1'&&s[1]<='9')
                return 8;
            else
                return 0;
        }
        else if(s[0]>='1'&&s[0]<='9'){
            return 10;
        }
        else
            return 0;
    }
    else
        return 0;
}

int islegal(char s[],int len,int base){
    switch(base){
        case 2:
            start=2;
            for(int i=start;i<len;i++){
                if(s[i]<'0'||s[i]>'1')
                    return -1;
                a[i]=s[i]-'0';
            }
            return 0;
        case 8:
            start=1;
            for(int i=start;i<len;i++){
                if(s[i]<'0'||s[i]>'7')
                    return -1;
                a[i]=s[i]-'0';
            }
            return 0;
        case 10:
            start=0;
            for(int i=start;i<len;i++){
                if(s[i]<'0'||s[i]>'9')
                    return -1;
                a[i]=s[i]-'0';
            }
            return 0;
        case 16:
            start=2;
            for(int i=start;i<len;i++){
                if(!((s[i]>='0'&&s[i]<='9')||(s[i]>='A'&&s[i]<='F')))
                    return -1;
                if(s[i]>='0'&&s[i]<='9'){
                    a[i]=s[i]-'0';
                }
                else if(s[i]>='A'&&s[i]<='F')
                    a[i]=s[i]-'A'+10;
            }
            return 0;
        default:
            return -1;
    }
    return -1;
}

int todecimal(int a[],int len,int base){
    int result=0;
    for(int i=start;i<len;i++){
        result*=base;
        result+=a[i];
    }
    return result;
}

int main(){
    int len;
    int base;
    int state;
    int result;
    len=mygetline(s);
    base=judge(s,len);
    state=islegal(s,len,base);
    if(state==-1){
        printf("error\n");
        return 0;
    }
    result=todecimal(a,len,base);
    printf("%d\n",result);
    return 0;
}