#pragma once

typedef struct StackNode StackNode;

typedef struct Stack Stack;

// Creates new stack.
// Returns pointer on the created stack.
Stack* newStack();

// Deletes stack.
// Takes pointer on the stack.
void deleteStack(Stack* stack);

// Pushes new value on the top of the stack.
// Takes pointer on the stack and value for push.
void push(Stack* stack, int value);

// Deletes the top value of the stack and returns it.
// Takes pointer on the stack.
// If the stack is empty returns -1.
int pop(Stack* stack);

// Returns the top value of the stack.
// Takes pointer on the stack.
// If the stack is empty returns -1.
int peek(Stack* stack);
