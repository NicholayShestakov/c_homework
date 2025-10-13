#include <stdio.h>
#include <stdlib.h>

void gnomeSort(int* array, int size)
{
    int current = 1;

    while (current < size) {
        if (array[current] < array[current - 1]) {
            int temp = array[current];
            array[current] = array[current - 1];
            array[current - 1] = temp;

            if (current == 1) {
                current++;
            } else {
                current--;
            }
        } else {
            current++;
        }
    }
}

int main()
{
    int size = 0;
    printf("Input size of array: ");
    scanf("%d", &size);
    int* array = calloc(size, sizeof(int));
    printf("Input array numbers separated by space: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    gnomeSort(array, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
