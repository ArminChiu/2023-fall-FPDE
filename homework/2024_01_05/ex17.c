#include <stdio.h>
#include <stdlib.h>
typedef struct tnode *Treeptr;
typedef struct tnode{
    char *word;
    int count;
    Treeptr left;
    Treeptr right;
}Treenode;

int main(){
    Treeptr ptree;
    Treeptr buildroot();
    ptree = buildroot();
    printf("root node data:\n");
    printf("word:%s\n",ptree->word);
    printf("count:%d\n",ptree->count);
    return 0;
}

Treeptr buildroot(){
    Treeptr p;
    p=(Treeptr)malloc(sizeof(Treenode));
    p->right=p->left=NULL;
    p->count = 1;
    p->word = "root";
    return p;
}
