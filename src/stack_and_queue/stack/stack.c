#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

Stack* newStack()
{
    Stack* stack = malloc(sizeof(Stack));
    stack->head = NULL;
    return stack;
}

void deleteStack(Stack* stack)
{
    StackNode* highest = stack->head;
    while (highest != NULL) {
        StackNode* newHighest = highest->next;
        free(highest);
        highest = newHighest;
    }
    free(stack);
}

void push(Stack* stack, int value)
{
    StackNode* newNode = malloc(sizeof(StackNode));
    newNode->value = value;
    newNode->next = stack->head;
    stack->head = newNode;
}

int pop(Stack* stack)
{
    if (stack->head == NULL) {
        printf("The stack is empty. \n");
        return -1;
    }

    StackNode* poppedNode = stack->head;
    int value = poppedNode->value;
    stack->head = poppedNode->next;
    free(poppedNode);
    return value;
}

void peek(Stack* stack)
{
    if (stack->head == NULL) {
        printf("The stack is empty. \n");
        return;
    }

    printf("The highest element: %d \n", stack->head->value);
}
