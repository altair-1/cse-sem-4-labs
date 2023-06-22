#include <stdio.h>
#include <stdlib.h>
typedef struct node * Nodeptr;
struct node{
    int data;
    Nodeptr lchild;
    Nodeptr rchild;
};

Nodeptr getnode(){
    return ((Nodeptr)malloc(sizeof(struct node)));
}

int max(int a,int b){
    return a>b?a:b;
}

int height(Nodeptr root){
    if(root){
        return max(height(root->lchild),height(root->rchild))+1;
    }
}