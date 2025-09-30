#include <stdio.h>
#include <stdlib.h>

int main()
{
    char* string = NULL;
    char* substring = NULL;
    size_t stringSize = 0;
    size_t substringSize = 0;

    printf("Enter string: ");
    int realStringSize = getline(&string, &stringSize, stdin);
    printf("Enter substring: ");
    int realSubstringSize = getline(&substring, &substringSize, stdin);

    int substringCount = 0;
    for (int i = 0; i < realStringSize - 1; i++) {
        if (string[i] == substring[0]) {
            substringCount++;
            for (int j = 0; j < realSubstringSize - 1; j++) {
                if (string[i + j] != substring[j]) {
                    substringCount--;
                    break;
                }
            }
        }
    }

    printf("Substring count in string: %d \n", substringCount);

    free(string);
    free(substring);

    return 0;
}
