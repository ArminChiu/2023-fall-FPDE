#include <stdio.h>
#include <string.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];
int readlines(char *lineptr[],int nlines);
void writelines(char *lineptr[],int nlines);
void shellsort(char *lineptr[],int len);

int main(){
    int nlines;
    if((nlines=readlines(lineptr,MAXLINES))>0){
        shellsort(lineptr,nlines);
        writelines(lineptr,nlines);
        return 0;
    }else{
        printf("error: input too big to sort\n");
        return 1;
    }
}

