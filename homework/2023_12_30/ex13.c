#include "myhead.h"
char filebuf[BUFLEN];
int size;

int main(int argc,char *argv[]){
    struct tnode *ptree;
    char word[MAXWORD];
    int fd;
    if(argc!=2){
        printf("Error. Please enter: ./countwords filename\n");
        return 1;
    }
    if((fd=open(argv[1],O_RDONLY))==-1){
        printf("Error. Cannot find file \'%s\'\n",argv[1]);
        return 1;
    }
    size=read(fd,filebuf,BUFLEN);
    close(fd);

    ptree=NULL;
    while(getword(word,MAXWORD)!=EOF){
        if(isalpha(word[0])){
            ptree=addtree(ptree,word);
        }
    }
    printf("the results are:\n");
    treeprint(ptree);
}

int getword(char *word,int lim){
    static char *p=filebuf;
    char *w=word;
    while(p<(filebuf+size) && (isspace(*p)))
        p++;
    
    if(p==(filebuf+size)||*p=='\0')
        return EOF;

    *w++=*p;
    if(!isalpha(*p)){
        *w='\0';
        return *p++;
    }
    for(;++p<(filebuf+size) && --lim>0;w++)
        if(!isalnum(*w=*p)){
            break;
        }
    *w='\0';
    return word[0];
}

struct tnode * addtree(struct tnode *ptree,char *word){
    struct tnode *p;
    int cmpresult;
    if(ptree==NULL){
        p=talloc();
        p->word=mystrdup(word);
        p->count=1;
        p->left=p->right=NULL;
        return p;
    }else if((cmpresult=strcmp(word,ptree->word))==0){
        ptree->count++;
    }else if(cmpresult<0){
        ptree->left=addtree(ptree->left,word);
    }else{
        ptree->right=addtree(ptree->right,word);
    }
    return ptree;
}

void treeprint(struct tnode *ptree){
    if(ptree){
        treeprint(ptree->left);
        printf("%4d %s\n",ptree->count,ptree->word);
        treeprint(ptree->right);
    }
}

struct tnode * talloc(void){
    return (struct tnode*)malloc(sizeof(struct tnode));
}

char *mystrdup(char *s){
    char *p;
    p=(char*)malloc(strlen(s)+1);
    if(p!=NULL)
        strcpy(p,s);
    return p;
}