#pragma once

#include <stdbool.h>

typedef struct Stack Stack;

// Creates new stack.
// Returns pointer on the created stack.
Stack* newStack();

// Deletes stack. Frees all memory used in it.
// Takes pointer on the stack.
void deleteStack(Stack* stack);

// Pushes new value on the top of the stack.
// Takes pointer on the stack and value for push.
void push(Stack* stack, int value);

// Deletes the top value of the stack and returns it. Frees memory used for top node.
<<<<<<< HEAD
// Takes pointer on the stack.
// If the stack is empty returns -1.
int pop(Stack* stack);

// Returns the top value of the stack.
// Takes pointer on the stack.
// If the stack is empty returns -1.
=======
// Takes pointer to the stack.
// Don`t use if the stack is empty. It causes the error.
// Check this with isEmpty before use this function.
int pop(Stack* stack);

// Returns the top value of the stack.
// Takes pointer to the stack.
// Don`t use if the stack is empty. It causes the error.
// Check this with isEmpty before use this function.
>>>>>>> cce4851 (Update stack header documentation)
int peek(Stack* stack);

// Returns true if the stack is empty and false if not.
// Takes pointer on the stack.
bool isEmpty(Stack* stack);
