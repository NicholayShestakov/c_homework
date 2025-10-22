#include "stack.h"
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

// Takes infix form of expression as string and returns pointer on postfix form string.
char* sortingStation(char* infixForm)
{
    char* output = calloc(strlen(infixForm), sizeof(output) + 1);
    Stack* operators = newStack();

    int indexOfOutput = 0;
    for (int indexOfInfix = 0; infixForm[indexOfInfix] != '\0'; ++indexOfInfix) {
        if (isdigit(infixForm[indexOfInfix])) {
            output[indexOfOutput] = infixForm[indexOfInfix];
            output[indexOfOutput + 1] = ' ';
            indexOfOutput += 2;
        }
        if (isOperatorFirstPriority(infixForm[indexOfInfix]) || infixForm[indexOfInfix] == '(') {
            push(operators, infixForm[indexOfInfix]);
        }
        if (isOperatorSecondPriority(infixForm[indexOfInfix])) {
            while (!isEmpty(operators) && peek(operators) != '(') {
                output[indexOfOutput] = pop(operators);
                output[indexOfOutput + 1] = ' ';
                indexOfOutput += 2;
            }
            push(operators, infixForm[indexOfInfix]);
        }
        if (infixForm[indexOfInfix] == ')') {
            while (peek(operators) != '(') {
                output[indexOfOutput] = pop(operators);
                output[indexOfOutput + 1] = ' ';
                indexOfOutput += 2;
            }
            pop(operators);
        }
    }

    while (!isEmpty(operators)) {
        output[indexOfOutput] = pop(operators);
        output[indexOfOutput + 1] = ' ';
        indexOfOutput += 2;
    }

    deleteStack(operators);
    return output;
}

int main()
{
    char* input1 = "(1 + 1) * 2";
    char* output1 = sortingStation(input1);
    char* input2 = "4/2+6";
    char* output2 = sortingStation(input2);
    char* input3 = "((1 + 2) * 3) - 4";
    char* output3 = sortingStation(input3);
    char* input4 = "((((1))))";
    char* output4 = sortingStation(input4);
    char* input5 = "(1 + (4 + 5 + 2) - 3) + (6 + 8)";
    char* output5 = sortingStation(input5);
    char* input6 = "1";
    char* output6 = sortingStation(input6);
    char* input7 = "";
    char* output7 = sortingStation(input7);

    printf("%s  ->  %s\n", input1, output1);
    printf("%s  ->  %s\n", input2, output2);
    printf("%s  ->  %s\n", input3, output3);
    printf("%s  ->  %s\n", input4, output4);
    printf("%s  ->  %s\n", input5, output5);
    printf("%s  ->  %s\n", input6, output6);
    printf("%s  ->  %s\n", input7, output7);

    free(output1);
    free(output2);
    free(output3);
    free(output4);
    free(output5);
    free(output6);
    free(output7);
    return 0;
}
