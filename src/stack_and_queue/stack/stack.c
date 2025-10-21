#include "stack.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode {
    int value;
    struct StackNode* next;
} StackNode;

typedef struct Stack {
    StackNode* head;
} Stack;

Stack* newStack()
{
    Stack* stack = malloc(sizeof(*stack));
    stack->head = NULL;
    return stack;
}

void deleteStack(Stack* stack)
{
    while (stack->head != NULL) {
        pop(stack);
    }
    free(stack);
}

void push(Stack* stack, int value)
{
    StackNode* newNode = malloc(sizeof(*newNode));
    newNode->value = value;
    newNode->next = stack->head;
    stack->head = newNode;
}

int pop(Stack* stack)
{
    if (isEmpty(stack)) {
        return -1;
    }

    StackNode* poppedNode = stack->head;
    int value = poppedNode->value;
    stack->head = poppedNode->next;
    free(poppedNode);
    return value;
}

int peek(Stack* stack)
{
    if (isEmpty(stack)) {
        return -1;
    }

    return stack->head->value;
}

bool isEmpty(Stack* stack)
{
    return stack->head == NULL;
}
