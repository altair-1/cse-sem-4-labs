#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void insert(int* HashTable,int n,int i,int key){
    if(i==n)
        i=0;
    if(HashTable[i]==0)
        HashTable[i]=key;
    else
        insert(HashTable,n,i+1,key);
}

void main(){
    int m,n;
    printf("enter no. of elements: ");
    scanf("%d",&n);
    printf("enter no. of cells: ");
    scanf("%d",&m);
    if(m<n)
        exit(0);
    double alpha=n/m;
    int key;
    int *HashTable;
    HashTable=(int*)calloc(m,sizeof(int));
    int mod;
    for(int i=0;i<n;i++){
        printf("enter key %d: ",i+1);
        scanf("%d",&key);
        mod=key%m;
        insert(HashTable,m,mod,key);
    }
    for(int i=0;i<m;i++){
        printf("%d ",HashTable[i]);
    }
    printf("\nsuccesful search comparisons: %f\n",0.5*(1+1/(1-alpha)));
    printf("unsuccesful search comparisons: %f\n",0.5*(1+1/pow((1-alpha),2)));
}