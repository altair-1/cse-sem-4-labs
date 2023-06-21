#include <stdio.h>
#include <stdlib.h>

int opCount=0;
typedef struct node{
    int val;
    struct node *l;
    struct node *r;
} node;

node* create(int x){
    node *new = (node*)malloc(sizeof(node));
    new->val = x;
    new->l = new->r = NULL;
    return new;
}

int count(node *root){
    if(root == NULL)
        return 0;
    int l = count(root->l);
    int r = count(root->r);

    return 1 + l + r;
}

void main(){
    node* root = create(25);
    root->l = create(27);
    root->r = create(19);
    root->l->l = create(17);
    root->l->r = create(91);
    root->r->l = create(13);
    root->r->r = create(55);
    printf("total number of nodes is %d\n", count(root));
}