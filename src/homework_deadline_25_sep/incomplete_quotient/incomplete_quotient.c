#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    if (b == 0) {
        printf("Error: Divide by zero. \n");
        return 1;
    }

    int absA = a > 0 ? a : -a;
    int absB = b > 0 ? b : -b;
    int quotient = 0;
    while (absA >= absB) {
        quotient++;
        absA -= absB;
    }

    if ((a < 0) != (b < 0)) {
        quotient = -quotient;
        if (a - b * quotient < 0) {
            quotient--;
        }
    } else {
        if (a - b * quotient < 0) {
            quotient++;
        }
    }

    printf("%d \n", quotient);

    return 0;
}
