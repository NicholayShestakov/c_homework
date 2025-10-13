#include <stdio.h>

int main()
{
    int sum = 0;
    int last = 1;
    int prelast = 0;

    while (prelast <= 1000000) {
        if (prelast % 2 == 0) {
            sum += prelast;
        }

        int temp = last;
        last += prelast;
        prelast = temp;
    }

    printf("Сумма чётных чисел Фибоначчи, не превосходящих миллиона: %d \n", sum);

    return 0;
}
