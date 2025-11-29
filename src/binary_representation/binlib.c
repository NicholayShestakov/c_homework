#include "binlib.h"

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

char* decimalToBinary(int32_t decimal)
{
    char* binary = malloc(32 * sizeof(char));

    for (int i = 0; i < 32; ++i) {
        // Берём по биту, начиная с наименьшего разряда.
        if ((1 << i) & decimal) {
            binary[31 - i] = '1';
        } else {
            binary[31 - i] = '0';
        }
    }

    return binary;
}

char* binarySum(char* binaryFirst, char* binarySecond)
{
    char* sum = malloc(32 * sizeof(char));

    // Берём каждый три чиселка, два из текущего разряда чисел и третье - остаток от предыдущего сложения.
    int fromPrevious = 0;
    for (int i = 31; i >= 0; --i) {
        int fromFirst = binaryFirst[i] == '1' ? 1 : 0;
        int fromSecond = binarySecond[i] == '1' ? 1 : 0;

        switch (fromPrevious + fromFirst + fromSecond) {
        case 0:
            sum[i] = '0';
            fromPrevious = 0;
            break;
        case 1:
            sum[i] = '1';
            fromPrevious = 0;
            break;
        case 2:
            sum[i] = '0';
            fromPrevious = 1;
            break;
        case 3:
            sum[i] = '1';
            fromPrevious = 1;
            break;
        }
    }

    return sum;
}

int32_t binaryToDecimal(char* binary)
{
    int32_t decimal = 0;

    // Переменная, которая показывает, что мы в данном случае считаем за непустой разряд.
    char forOne = '1';
    if (binary[0] == '1') {
        forOne = '0';
    }

    for (int i = 1; i < 32; ++i) {
        if (binary[i] == forOne) {
            // Прибавляем к десятичной форме двойку в нужной степени.
            decimal += (1 << (32 - i - 1));
        }
    }

    // Если число было отрицательным, то нужно прибавить 1 и умножить на -1 для правильного результата перевода из дополнительного кода.
    if (binary[0] == '1') {
        ++decimal;
        decimal *= -1;
    }

    return decimal;
}

void binaryPrint(char* binary)
{
    // Ищем, где кончаются лидирующие нули и их не выводим. Если число 0, то выведется 0.
    int firstOneIndex = 31;
    for (int i = 0; i < 32; ++i) {
        if (binary[i] == '1') {
            firstOneIndex = i;
            break;
        }
    }
    for (int i = firstOneIndex; i < 32; ++i) {
        printf("%c", binary[i]);
    }
    printf("\n");
}
