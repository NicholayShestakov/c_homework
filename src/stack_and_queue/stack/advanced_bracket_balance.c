#include "stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isBracket(char c)
{
    return (c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}');
}

// Checks brackets balance.
// Returns true if brackets balanced and false if not.
// Takes string.
bool isBracketsBalanced(char* string)
{
    int size = strlen(string);
    Stack* brackets = newStack();

    for (int i = 0; i < size; i++) {
        // If char is opening bracket, pushes individual for all bracket types number in the stack.
        // If char is closing bracket, pops number from the stack. If number is not right, returns false.
        if (isBracket(string[i])) {
            if (string[i] == '(') {
                push(brackets, 1);
            }
            if (string[i] == '[') {
                push(brackets, 2);
            }
            if (string[i] == '{') {
                push(brackets, 3);
            }
            if (string[i] == ')') {
                if (pop(brackets) != 1) {
                    deleteStack(brackets);
                    return false;
                }
            }
            if (string[i] == ']') {
                if (pop(brackets) != 2) {
                    deleteStack(brackets);
                    return false;
                }
            }
            if (string[i] == '}') {
                if (pop(brackets) != 3) {
                    deleteStack(brackets);
                    return false;
                }
            }
        }
    }
    // Check for all brackets closed.
    if (!isEmpty(brackets)) {
        deleteStack(brackets);
        return false;
    }

    deleteStack(brackets);
    return true;
}

int main()
{
    char a[] = "T(e){s}[t]";
    char b[] = "123";
    char c[] = "";
    char d[] = "(";
    char e[] = "({a)}";
    char f[] = "((({{{[[[]]]}}})))";

    printf("%s - %d\n", a, isBracketsBalanced(a));
    printf("%s - %d\n", b, isBracketsBalanced(b));
    printf("%s - %d\n", c, isBracketsBalanced(c));
    printf("%s - %d\n", d, isBracketsBalanced(d));
    printf("%s - %d\n", e, isBracketsBalanced(e));
    printf("%s - %d\n", f, isBracketsBalanced(f));

    return 0;
}
