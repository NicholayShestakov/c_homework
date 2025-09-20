#include <stdio.h>

int main()
{
    int countSums[28] = { 0 };

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                countSums[i + j + k] += 1;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < 28; i++) {
        sum += countSums[i] * countSums[i];
    }

    printf("%d \n", sum);

    return 0;
}