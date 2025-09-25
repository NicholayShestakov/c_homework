#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 0, b = 0;
    scanf("%d %d", &a, &b);

    if (b == 0) {
        printf("Error: Divide by zero. \n");
        return 1;
    }

    int absA = abs(a);
    int absB = abs(b);
    int quotient = 0;
    while (absA >= absB) {
        quotient++;
        absA -= absB;
    }

    if (a * b < 0) {
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
