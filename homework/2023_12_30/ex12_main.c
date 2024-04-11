#include "myhead.h"

int main(){
    struct tnode *ptree;
    char word[MAXWORD];
    ptree=NULL;
    while(getword(word,MAXWORD)!=EOF){
        if(isalpha(word[0])){
            ptree=addtree(ptree,word);
        }
    }
    printf("the results are:\n");
    treeprint(ptree);
    return 0;
}

void treeprint(struct tnode *ptree){
    if(ptree){
        treeprint(ptree->left);
        printf("%4d %s\n",ptree->count,ptree->word);
        treeprint(ptree->right);
    }
}