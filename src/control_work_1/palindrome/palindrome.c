#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main()
{
    const char str[] = "Lorem m e r o L";
    int startPointer = 0;
    int endPointer = strlen(str) - 1;
    bool isPalindrome = true;

    while (startPointer < endPointer) {
        while (str[startPointer] == ' ') {
            startPointer++;
        }
        while (str[endPointer] == ' ') {
            endPointer--;
        }

        if (str[startPointer] != str[endPointer]) {
            isPalindrome = false;
            break;
        }

        startPointer++;
        endPointer--;
    }

    if (isPalindrome) {
        printf("String is palindrome. \n");
    } else {
        printf("String is not palindrome. \n");
    }

    return 0;
}
