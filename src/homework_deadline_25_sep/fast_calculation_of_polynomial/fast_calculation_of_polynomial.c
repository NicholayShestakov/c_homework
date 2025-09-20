#include <stdio.h>

int main()
{
    float x;
    scanf("%f", &x);
    float t = x * x;
    float result = t * (t + x) + t + x + 1;
    printf("%f \n", result);

    return 0;
}