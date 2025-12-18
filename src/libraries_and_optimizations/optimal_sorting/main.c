#include "optimal_sorting.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* arr = calloc(100, sizeof(int));
    int size = 0;
    printf("Enter array (with an explicit end-of-line character): ");
    while (scanf("%d ", &arr[size])) {
        size++;
    }

    int* sortedArr = mergeSort(arr, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", sortedArr[i]);
    }
    printf("\n");

    int return_code = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] != sortedArr[i]) {
            return_code++;
        }
    }

    free(arr);
    free(sortedArr);

    return return_code;
}
