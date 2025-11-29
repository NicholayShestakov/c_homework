#pragma once

#include <stdint.h>

/*
Returns pointer on string with "binary" representation of int.
Uses int32_t from <stdint.h>.
*/
char* decimalToBinary(int32_t decimal);

/*
Returns pointer on string with "binary" representation of sum of two
strings with "binary" representation of int. If integers in sum reaches the limit,
sum may be incorrect.
*/
char* binarySum(char* binaryFirst, char* binarySecond);

/*
Returns decimal representation of "binary" representation of int.
Don`t frees "binary" representation memory.
*/
int32_t binaryToDecimal(char* binary);

/*
Prints "binary" representation of int.
*/
void binaryPrint(char* binary);
