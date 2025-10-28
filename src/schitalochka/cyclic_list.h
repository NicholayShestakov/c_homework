#pragma once

#include <stdbool.h>

typedef struct List List;

// Creates cyclic list with n elements numerated from 1 to n.
// If n <= 0 returns NULL, else returns pointer on the list.
// Takes n - count of elements.
List* createList(int n);

// Deletes the list. The list is assumed to be empty.
// Takes pointer on the list;
void deleteList(List* list);

// Deletes element with taken index. Changes index starting pointer on the next element after deleted.
// Takes pointer on the list and index of the element.
// Returns 0. If the element is the last returns element.
int deleteElement(List* list, int index);
