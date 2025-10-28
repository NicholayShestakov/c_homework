#include "cyclic_list.h"

#include <stdlib.h>

typedef struct ListElement {
    int value;
    struct ListElement* next;
    struct ListElement* prev;
} ListElement;

struct List {
    ListElement* zeroIndexElement;
    int size;
};

List* createList(int n)
{
    if (n <= 0) {
        return NULL;
    }

    ListElement* oldElement = malloc(sizeof(*oldElement));
    oldElement->value = 1;
    List* list = malloc(sizeof(*list));
    list->zeroIndexElement = oldElement;
    list->size = n;
    for (int i = 2; i <= n; ++i) {
        ListElement* newElement = malloc(sizeof(*newElement));
        newElement->value = i;
        newElement->prev = oldElement;
        oldElement->next = newElement;
        oldElement = newElement;
    }
    oldElement->next = list->zeroIndexElement;
    list->zeroIndexElement->prev = oldElement;

    return list;
}

void deleteList(List* list)
{
    free(list);
}

int deleteElement(List* list, int index)
{
    if (list->zeroIndexElement->next == list->zeroIndexElement) {
        int value = list->zeroIndexElement->value;
        free(list->zeroIndexElement);
        return value;
    }

    index = index < 0 ? (index % list->size + list->size) : (index % list->size);

    ListElement* currentElement = list->zeroIndexElement;
    for (int i = 0; i < index; ++i) {
        currentElement = currentElement->next;
    }
    currentElement->prev->next = currentElement->next;
    currentElement->next->prev = currentElement->prev;
    list->zeroIndexElement = currentElement->next;
    list->size--;
    free(currentElement);

    return 0;
}
