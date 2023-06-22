#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * left;
    struct node * right;
} Node;

Node * createNode(int x) {
    Node * new = (Node *) malloc(sizeof(Node));
    new->val = x;
    new->left = NULL;
    new->right = NULL;
    return new;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int height(Node * root) {
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

int balanceFactor(Node * root) {
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}

void inOrder(Node *tree) {
    if (tree != NULL) {
        inOrder(tree->left);
        printf("node with value %d has balance factor %d\n",tree->val,balanceFactor(tree));
        inOrder(tree->right);
    }
}

void insertBST(Node **tree,int x) {
    Node * temp = createNode(x);
    Node * prev = NULL;
    Node * iter = *tree;
    while (iter != NULL) {
        prev = iter;
        if (iter->val > x)
            iter = iter->left;
        else
            iter = iter->right;
    }
    if (prev == NULL) 
        *tree = temp;
    else if (x < prev->val) 
        prev->left = temp;
    else 
        prev->right = temp;
}

void main() {
    int n,i,x;
    Node * tree = NULL;
    printf("enter number of elements: ");
    scanf("%d",&n);
    printf("enter elements:\n");
    for (i=0;i<n;i++) {
        scanf("%d",&x);
        insertBST(&tree,x);
    }
    inOrder(tree);
}