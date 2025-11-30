#include <stdio.h>

typedef struct BitField {
    unsigned long mantissa : 52;
    unsigned int exp : 11;
    unsigned int sign : 1;
} BitField;

typedef union Number {
    double number;
    BitField bitField;
} Number;

int main()
{
    Number number;
    printf("Enter a number: ");
    scanf("%lf", &number.number);

    char sign = number.bitField.sign ? '-' : '+';
    // Считаем экспоненту.
    int exponent = number.bitField.exp - 1023;
    // Считаем мантиссу.
    double mantissa = number.bitField.mantissa;
    unsigned long two_in_52_pow = 1;
    two_in_52_pow = two_in_52_pow << 52;
    double mantissaNormalized = 1 + mantissa / two_in_52_pow;

    printf("Result: %c%.52f*2^%d\n", sign, mantissaNormalized, exponent);

    return 0;
}
