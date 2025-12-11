#include "stack.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode {
    int value;
    struct StackNode* next;
} StackNode;

struct Stack {
    StackNode* head;
};

Stack* newStack()
{
    Stack* stack = calloc(1, sizeof(*stack));
    assert(stack != NULL && "Error! Memory allocated incorrect.");
    return stack;
}

void deleteStack(Stack* stack)
{
    while (!isEmpty(stack)) {
        pop(stack);
    }
    free(stack);
}

void push(Stack* stack, int value)
{
    StackNode* newNode = malloc(sizeof(*newNode));
    assert(newNode != NULL && "Error! Memory allocated incorrect.");
    newNode->value = value;
    newNode->next = stack->head;
    stack->head = newNode;
}

int pop(Stack* stack)
{
    assert(!isEmpty(stack) && "Error! Stack is empty. Can`t pop value.");
    StackNode* poppedNode = stack->head;
    int value = poppedNode->value;
    stack->head = poppedNode->next;
    free(poppedNode);
    return value;
}

int peek(Stack* stack)
{
    assert(!isEmpty(stack) && "Error! Stack is empty. Can`t peek value.");
    return stack->head->value;
}

bool isEmpty(Stack* stack)
{
    return stack->head == NULL;
}
