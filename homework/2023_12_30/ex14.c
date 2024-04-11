#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define HASHSIZE 101
struct node{
    struct node *next;
    char *name;
    char *defn;
};
static struct node *hashtab[HASHSIZE];
struct node *install(char *name,char *defn);
struct node *lookup(char *s);
unsigned hash(char *s);
void buildlist();
char *mystrdup(char *s);

int main(){
    struct node *pnode;
    char keyword[100];
    buildlist();
    printf("Please input keyword:");
    scanf("%s",(char*)keyword);
    pnode=(struct node*)lookup(keyword);
    if(pnode)
        printf("%s>>>%s\n",pnode->name,pnode->defn);
    else
        printf("not found\n");
    return 0;
}

void buildlist(){
    struct name_and_defn{
        char *name;
        char *defn;
    }ndpairs[]={
        {"WANGGUIHUA","1024"},
        {"UTF8","13"},
        {"LIXUEQIN","12"},
        {"IN","1"},
        {"OUT","2"},
        {"MAX","10000"},
        {"MIN","3"},
        {"NUMBER","1024"},
        {"1N","2048"}
    };
    int i;
    for(i=0;i<sizeof(ndpairs)/sizeof(struct name_and_defn);i++)
        install(ndpairs[i].name,ndpairs[i].defn);
    return;
}

struct node *install(char *name,char *defn){
    struct node *np;
    unsigned hashval;
    if((np=lookup(name))==NULL){
        np=(struct node *)malloc(sizeof(*np));
        if(np==NULL||(np->name=mystrdup(name))==NULL)
            return NULL;
        hashval=hash(name);
        np->next=hashtab[hashval];
        hashtab[hashval]=np;
    }else
        free((void *)np->defn);
    if((np->defn=mystrdup(defn))==NULL)
        return NULL;
    return np;
}

unsigned hash(char *s){
    unsigned hashval;
    for(hashval=0;*s!='\0';s++)
        hashval=*s+31*hashval;
    return hashval % HASHSIZE;
}

struct node *lookup(char *s){
    struct node *np;
    for(np=hashtab[hash(s)];np!=NULL;np=np->next)
        if(strcmp(s,np->name)==0)
            return np;
        return NULL;
}

char *mystrdup(char *s){
    char *p;
    p=(char*)malloc(strlen(s)+1);
    if(p!=NULL)
        strcpy(p,s);
    return p;
}