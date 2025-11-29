#include "binlib.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test()
{
    char* zero = decimalToBinary(0);
    assert(!strcmp(zero, "00000000000000000000000000000000") && "Zero test is not passed.");

    char* one = decimalToBinary(1);
    assert(!strcmp(one, "00000000000000000000000000000001") && "One test is not passed.");
    char* minusOne = decimalToBinary(-1);
    assert(!strcmp(minusOne, "11111111111111111111111111111111") && "Minus one test is not passed.");

    char* sum = binarySum(one, minusOne);
    assert(!strcmp(sum, "00000000000000000000000000000000") && "Sum test is not passed.");

    assert(binaryToDecimal(zero) == 0 && "Zero binary to decimal test is not passed");
    assert(binaryToDecimal(one) == 1 && "Positive binary to decimal test is not passed.");
    assert(binaryToDecimal(minusOne) == -1 && "Negative binary to decimal test is not passed.");

    free(zero);
    free(one);
    free(minusOne);
    free(sum);
}

int main(int argc, char* argv[])
{
    if (argc > 1) {
        if (strcmp(argv[1], "--test") == 0) {
            test();
            printf("All tests has successfully passed.\n");
        }
    }
    int32_t a = 0;
    int32_t b = 0;
    printf("Enter two integers after space: ");
    scanf("%d %d", &a, &b);

    char* aBinary = decimalToBinary(a);
    char* bBinary = decimalToBinary(b);

    printf("Binary representation of integers:\n");
    binaryPrint(aBinary);
    binaryPrint(bBinary);

    char* sumBinary = binarySum(aBinary, bBinary);
    printf("Binary sum of integers (If integers goes beyond the limit, result may be incorrect):\n");
    binaryPrint(sumBinary);

    int32_t aDecimal = binaryToDecimal(aBinary);
    int32_t bDecimal = binaryToDecimal(bBinary);
    int32_t sumDecimal = aDecimal + bDecimal;

    printf("Decimal sum of integers (If integers goes beyond the limit, result may be incorrect):\n%d\n", sumDecimal);

    free(aBinary);
    free(bBinary);
    return 0;
}
