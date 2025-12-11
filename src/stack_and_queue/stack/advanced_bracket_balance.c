#include "stack.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isOpeningBracket(char c)
{
    return (c == '(' || c == '[' || c == '{');
}

bool isClosingBracket(char c)
{
    return (c == ')' || c == ']' || c == '}');
}

// Checks brackets balance.
// Returns true if brackets balanced and false if not.
// Takes string.
bool isBracketsBalanced(char* string)
{
    int size = strlen(string);
    Stack* brackets = newStack();

    for (int i = 0; i < size; i++) {
        if (isOpeningBracket(string[i])) {
            push(brackets, string[i]);
        }
        if (isClosingBracket(string[i])) {
            if (isEmpty(brackets)) {
                return false;
            }

            bool isClosed = false;
            switch (pop(brackets)) {
            case '(':
                isClosed = string[i] == ')';
                break;
            case '[':
                isClosed = string[i] == ']';
                break;
            case '{':
                isClosed = string[i] == '}';
                break;
            }

            if (!isClosed) {
                return false;
            }
        }
    }
    // Check for unclosed brackets.
    if (!isEmpty(brackets)) {
        deleteStack(brackets);
        return false;
    }

    deleteStack(brackets);
    return true;
}

int main()
{
    assert(isBracketsBalanced("T(e){s}[t]") && "Test failed.");
    assert(isBracketsBalanced("123") && "Test failed.");
    assert(isBracketsBalanced("") && "Test failed.");
    assert(!isBracketsBalanced("(") && "Test failed.");
    assert(!isBracketsBalanced("({a)}") && "Test failed.");
    assert(isBracketsBalanced("((({{{[[[]]]}}})))") && "Test failed.");
    printf("All tests successfully passed.\n");

    return 0;
}
