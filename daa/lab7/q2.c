#include <stdio.h>
#include <stdlib.h>
#include "functions.c"

int balfac(Nodeptr root){
    return height(root->lchild)-height(root->rchild);
}

Nodeptr leftrotate(Nodeptr x){
    Nodeptr y=x->rchild;
    Nodeptr z=y->lchild;
    y->lchild=x;
    x->rchild=z;
    return y;
}

Nodeptr rightrotate(Nodeptr x){
    Nodeptr y=x->lchild;
    Nodeptr z=y->rchild;
    y->rchild=x;
    x->lchild=z;
    return y;
}

Nodeptr insertAVL(Nodeptr root,int item){
    if (!root){
        root = getnode();
        root->data= item;
        root->lchild=root->rchild = NULL;
        return root;
    }
    if (item<root->data)
            root->lchild = insertAVL(root->lchild, item);
        else if (item>root->data)
            root->rchild = insertAVL(root->rchild, item);
        else
            return root;
    int bal=balfac(root);
    if (bal > 1 && item < root->lchild->data)
        return rightrotate(root);
    if (bal < -1 && item > root->rchild->data)
        return leftrotate(root);
    if (bal > 1 && item > root->lchild->data){
        root->lchild =  leftrotate(root->lchild);
        return rightrotate(root);
    }
    if (bal < -1 && item < root->rchild->data){
        root->rchild = rightrotate(root->rchild);
        return leftrotate(root);
    }
    return root;
}

Nodeptr createAVL(Nodeptr root,int data){
    int x;
    root=getnode();
    root->data=data;
    root->lchild=root->rchild=NULL;
    while(1){
        printf("enter data to insert (-1 to exit): \n");
        scanf("%d",&x);
        if(x==-1){
            break;
        }
        root=insertAVL(root,x);
    }
    return root;
}

void preorder(Nodeptr root){
    if(root){
        printf("%d ",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void main(){
    Nodeptr root=NULL;
    int data;
    printf("enter root data: ");
    scanf("%d",&data);
    root=createAVL(root,data);
    printf("preorder traversal of the AVL tree inserted: \n");
    preorder(root);
    printf("\n");
}