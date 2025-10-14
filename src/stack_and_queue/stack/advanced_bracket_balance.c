#include "stack.h"
#include <stdbool.h>
#include <stdio.h>

bool isBracket(char c)
{
    if (c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}') {
        return true;
    }
    return false;
}

// Saves opening brackets in stack. Deletes pairs.
// Takes bracket symbol and pointer on the bracket stack.
// Returns true if brackets closes right or opens. Else returns false.
bool bracketProcessing(char bracket, Stack* bracketStack)
{
    if (bracket == '(') {
        push(bracketStack, 1);
    }
    if (bracket == '[') {
        push(bracketStack, 2);
    }
    if (bracket == '{') {
        push(bracketStack, 3);
    }
    if (bracket == ')') {
        if (pop(bracketStack) != 1) {
            return false;
        }
    }
    if (bracket == ']') {
        if (pop(bracketStack) != 2) {
            return false;
        }
    }
    if (bracket == '}') {
        if (pop(bracketStack) != 3) {
            return false;
        }
    }
    return true;
}

int main()
{
    int size = 0;
    printf("Input size of string: ");
    scanf("%d", &size);

    Stack* bracketStack = newStack();
    char currentChar = 0;
    // Костыль для избавления от символа переноса строки после ввода размера.
    scanf("%c", &currentChar);
    bool isBalanced = true;
    printf("Input string: ");
    for (int i = 0; i < size; i++) {
        scanf("%c", &currentChar);
        if (isBracket(currentChar)) {
            isBalanced = bracketProcessing(currentChar, bracketStack);
            if (!isBalanced) {
                break;
            }
        }
    }
    // Проверка, что не осталось незакрытых скобок.
    if (pop(bracketStack) != -1) {
        isBalanced = false;
    }

    if (isBalanced) {
        printf("Brackets balanced. \n");
    } else {
        printf("Brackets not balanced. \n");
    }

    deleteStack(bracketStack);

    return 0;
}
