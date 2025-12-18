#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Проверка на палиндром. Принимает указатель на строку. Возвращает булево значение.
bool palindromeCheck(char* str)
{
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

    return isPalindrome;
}

int main()
{
    char str[] = "Lorem m e r o L";
    char str2[] = "Lorem ipsum";
    char str3[] = "";
    char str4[] = "1";

    printf("%s - %d \n", str, palindromeCheck(str));
    printf("%s - %d \n", str2, palindromeCheck(str2));
    printf("%s - %d \n", str3, palindromeCheck(str3));
    printf("%s - %d \n", str4, palindromeCheck(str4));

    return 0;
}
