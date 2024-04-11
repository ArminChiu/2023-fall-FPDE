#include <stdio.h>
#include <string.h>
int islegalANSI(char s[]){
    if (strlen(s) >= 32)
        return 0;
    else if(s[0]<='9'&&s[0]>='0') return 0;
    else
        for (int i = 0; i < strlen(s); i++){
            if (s[i] <= '9' && s[i] >= '0')
                ;
            else if (s[i] <= 'z' && s[i] >= 'a')
                ;
            else if (s[i] <= 'Z' && s[i] >= 'A')
                ;
            else if (s[i] == '_')
                ;
            else
                return 0;
        }
    return 1;
}
int main(){
    char s[100];
    scanf("%s", s);
    printf("%d",islegalANSI(s));
}