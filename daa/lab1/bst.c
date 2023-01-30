#include<stdio.h>
#include<stdlib.h>

typedef struct Node* Nodeptr;

typedef struct Node{
    int data;
    Nodeptr left;
    Nodeptr right;
}Node;

Nodeptr search(Nodeptr root, int key){
    if(!root){
        Nodeptr temp = (Nodeptr)malloc(sizeof(Node));
        temp->data = key;
        temp->left = temp->right = NULL;
        printf("key inserted in BST\n");
        return temp;
    }
    if(root->data == key){
        printf("key found\n");
    }
    else if(root->data > key)
        root->left = search(root->left, key);
    else
        root->right = search(root->right, key);
    return root;
    }

void preorder(Nodeptr root){
    if(root){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Nodeptr root){
    if(root){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void postorder(Nodeptr root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

int main(){
    int op;
    Nodeptr root = NULL;
    int flag = 1;
    while(flag){
        printf("enter option\n");
        printf("1. enter key to search/insert\n2. inorder\n3. preorder\n4. postorder\n5. exit\n");
        scanf("%d",&op);
        switch(op){
            case 1 : printf("enter key: ");
                     int a;
                     scanf("%d",&a);
                     root = search(root, a);
                     break;
            case 2 : printf("inorder traversal: \n");
                     inorder(root);
                     printf("\n");
                     break;
            case 3 : printf("preorder traversal: \n");
                     preorder(root);
                     printf("\n");
                     break;
            case 4 : printf("postorder traversal: \n");
                     postorder(root);
                     printf("\n");
                     break;
            case 5 : exit (0);
            default : flag = 0;
        }
    }
    return 0;
}