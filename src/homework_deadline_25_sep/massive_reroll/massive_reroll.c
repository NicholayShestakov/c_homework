#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);

    int* arr = calloc(n + m, sizeof(int));
    for (int i = 0; i < n + m; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = n; i < n + m; i++) {
        for (int j = i; j > i - n; j--) {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
        }
    }

    for (int i = 0; i < n + m; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
