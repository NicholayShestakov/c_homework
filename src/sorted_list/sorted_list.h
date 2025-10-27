#pragma once

typedef struct List List;

// Creates empty sorted list.
// Returns pointer on it.
List* createList();

// Deletes the sorted list and frees memory it used.
// Takes pointer on the sorted list.
void deleteList(List* list);

// Appends value in the sorted list.
// Takes pointer on the sorted list and value.
void appendValue(List* list, int value);

// Deletes one element from the sorted list with taken value and frees memory it used.
// Takes pointer on the sorted list and value.
// If in the list have not elements with this value, prints it.
void deleteValue(List* list, int value);

// Prints the list.
// Takes pointer on the sorted list.
void printList(List* list);
