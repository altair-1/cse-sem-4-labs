#include <stdio.h>
#include <stdlib.h>

int opCount = 0;

void topDown(int arr[], int currIndex){
    int parent = (currIndex - 1)/2;
    while(parent >= 0){
	opCount++;
        if(arr[parent]<arr[currIndex]){
            int temp = arr[parent];
            arr[parent] = arr[currIndex];
            arr[currIndex] = temp;
            currIndex = parent;
            parent = (currIndex - 1)/2;
        }
        else
            return;
    }
}

int main(){
    int h[20], n;
    printf("enter no. of elements: ");
    scanf("%d", &n);
    printf("enter elements:\n");
    for(int i = 0; i<n; i++){
        scanf("%d", &h[i]);
        topDown(h,i);
    }
    
    printf("heap:\n");
    for(int i = 0; i<n; i++)
        printf("%d ", h[i]);
    printf("\n");
    printf("opCount = %d\n", opCount);
    exit(0);
    return 0;
}