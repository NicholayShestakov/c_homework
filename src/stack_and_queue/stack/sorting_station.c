#include "stack.h"
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isOperatorFirstPriority(char c)
{
    return c == '*' || c == '/';
}

bool isOperatorSecondPriority(char c)
{
    return c == '+' || c == '-';
}

// Takes infix form of expression as string and returns pointer to postfix form string. Please, dont forget free memory.
// Can track unbalanced brackets and correctness of order of numbers and operators. Cant track extraneous symbols.
// If the error is tracked, returns pointer to the string with the error description.
char* sortingStation(char* infixForm)
{
    char* output = calloc(2 * strlen(infixForm), sizeof(output));
    Stack* operators = newStack();

    bool isNumberTurn = true; // For check correctness of order.
    char* errorMessage = calloc(64, sizeof(*errorMessage)); // For error returns.
    int indexOfOutput = 0;
    for (int indexOfInfix = 0; infixForm[indexOfInfix] != '\0'; ++indexOfInfix) {
        if (isdigit(infixForm[indexOfInfix])) {
            if (!isNumberTurn) {
                strcat(errorMessage, "Error! Order of numbers and operators is incorrect.");
            }
            isNumberTurn = !isNumberTurn;

            output[indexOfOutput] = infixForm[indexOfInfix];
            output[indexOfOutput + 1] = ' ';
            indexOfOutput += 2;
        }
        if (isOperatorFirstPriority(infixForm[indexOfInfix])) {
            if (isNumberTurn) {
                strcat(errorMessage, "Error! Order of numbers and operators is incorrect.");
            }
            isNumberTurn = !isNumberTurn;

            push(operators, infixForm[indexOfInfix]);
        }
        if (isOperatorSecondPriority(infixForm[indexOfInfix])) {
            if (isNumberTurn) {
                strcat(errorMessage, "Error! Order of numbers and operators is incorrect.");
            }
            isNumberTurn = !isNumberTurn;

            while (!isEmpty(operators) && peek(operators) != '(') {
                output[indexOfOutput++] = pop(operators);
                output[indexOfOutput++] = ' ';
            }
            push(operators, infixForm[indexOfInfix]);
        }
        if (infixForm[indexOfInfix] == '(') {
            if (!isNumberTurn) {
                strcat(errorMessage, "Error! Number before opening bracket.");
            }

            push(operators, infixForm[indexOfInfix]);
        }
        // Многоступенчатость в целях предотвращения одновременного добавления сразу нескольких сообщений об ошибке.
        if (infixForm[indexOfInfix] == ')') {
            if (isEmpty(operators)) {
                strcat(errorMessage, "Error! Brackets not opened.");
            } else {
                if (isNumberTurn) {
                    strcat(errorMessage, "Error! Operator before closing bracket.");
                } else {
                    while (peek(operators) != '(') {
                        output[indexOfOutput++] = pop(operators);
                        output[indexOfOutput++] = ' ';

                        if (isEmpty(operators)) {
                            strcat(errorMessage, "Error! Brackets not opened.");
                            break;
                        }
                    }
                    if (!isEmpty(operators)) {
                        pop(operators);
                    }
                }
            }
        }

        // Данное условие истинно, когда строки не равны.
        if (strcmp(errorMessage, "")) {
            free(output);
            deleteStack(operators);
            return errorMessage;
        }
    }

    while (!isEmpty(operators)) {
        output[indexOfOutput++] = pop(operators);
        output[indexOfOutput++] = ' ';

        if (output[indexOfOutput - 2] == '(') {
            free(output);
            deleteStack(operators);
            strcat(errorMessage, "Error! Brackets not closed.");
            return errorMessage;
        }
    }

    deleteStack(operators);
    return output;
}

int main()
{
    char* testSimple = sortingStation("(1 + (4 + 5 / 2) - 3) + (6 + 8)");
    char* testNoSpaces = sortingStation("4/2+6");
    char* testManyBrackets = sortingStation("((((1))))");
    char* testOnlyNumber = sortingStation("1");
    char* testEmpty = sortingStation("");
    char* testIncorrectOrder = sortingStation("1 + + 1");
    char* testIncorrectOrder2 = sortingStation("+ 1");
    char* testNumberBeforeBracket = sortingStation("1 (+ 3)");
    char* testOperatorBeforeBracket = sortingStation("1 + (2 + ) 3");
    char* testBracketsNotOpened = sortingStation("1 + 2)");
    char* testBracketsNotClosed = sortingStation("1 + (2 + 3");

    assert(!strcmp(testSimple, "1 4 5 2 / + + 3 - 6 8 + + ") && "testSimple incorrect.");
    assert(!strcmp(testNoSpaces, "4 2 / 6 + ") && "testNoSpaces incorrect.");
    assert(!strcmp(testManyBrackets, "1 ") && "testManyBrackets incorrect.");
    assert(!strcmp(testOnlyNumber, "1 ") && "testOnlyNumber incorrect.");
    assert(!strcmp(testEmpty, "") && "testEmpty incorrect.");
    assert(!strcmp(testIncorrectOrder, "Error! Order of numbers and operators is incorrect.") && "testIncorrectOrder incorrect.");
    assert(!strcmp(testIncorrectOrder2, "Error! Order of numbers and operators is incorrect.") && "testIncorrectOrder2 incorrect.");
    assert(!strcmp(testNumberBeforeBracket, "Error! Number before opening bracket.") && "testNumberBeforeBracket incorrect.");
    assert(!strcmp(testOperatorBeforeBracket, "Error! Operator before closing bracket.") && "testOperatorBeforeBracket incorrect.");
    assert(!strcmp(testBracketsNotOpened, "Error! Brackets not opened.") && "testBracketsNotOpened incorrect.");
    assert(!strcmp(testBracketsNotClosed, "Error! Brackets not closed.") && "testBracketsNotClosed incorrect.");

    printf("All tests passed successfully.\n");

    free(testSimple);
    free(testNoSpaces);
    free(testManyBrackets);
    free(testOnlyNumber);
    free(testEmpty);
    free(testIncorrectOrder);
    free(testIncorrectOrder2);
    free(testNumberBeforeBracket);
    free(testOperatorBeforeBracket);
    free(testBracketsNotOpened);
    free(testBracketsNotClosed);
    return 0;
}
