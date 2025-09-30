#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size = 0;
    printf("Enter size of array: ");
    scanf("%d", &size);
    int* arr = calloc(size, sizeof(int));

    printf("Enter array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == 0) {
            count++;
        }
    }

    printf("Zero elements count: %d \n", count);

    free(arr);

    return 0;
}
