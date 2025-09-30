#include <stdio.h>

int main()
{
    char character = 0;
    int countNotClosedBrackets = 0;

    printf("Enter string: ");
    do {
        scanf("%c", &character);

        if (character == '(') {
            countNotClosedBrackets++;
        }
        if (character == ')') {
            countNotClosedBrackets--;
        }

        if (countNotClosedBrackets < 0) {
            break;
        }
    } while (character != '\n');

    if (countNotClosedBrackets == 0) {
        printf("Brackets balanced. \n");
    } else {
        printf("Brackets not balanced. \n");
    }
}
