#include <stdio.h>
#include <stdlib.h>

int bubbleSort(int * a, int n) {
    int i, j, temp, count = 0;
    for (i=0; i < n-1; i++) {
        for (j=0; j < n-i-1; j++) {
            count++;
            if (a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    return count;
}

void main() {
    int n, i, j, temp, count, countBC, countWC;
    printf("enter n: ");
    scanf("%d",&n);
    int * arr = (int *) malloc(n * sizeof(int));
    for (i=0; i < n; i++) {
        printf("enter arr[%d]: ", i);
        scanf("%d",&arr[i]);
    }

    count = bubbleSort(arr, n);

    printf("sorted array is \n");
    for (i=0; i < n; i++)
        printf("%d ", arr[i]);
    printf("and it took %d comparisons", count);

    int bc[] = {1, 2, 3, 4, 5};
    int wc[] = {5, 4, 3, 2, 1};

    countBC = bubbleSort(bc, 5);
    countWC = bubbleSort(wc, 5);
    printf("\nnumber of operations for best case is %d and for worst case is %d \n(for n = %d)\n", countBC, countWC,5);
}