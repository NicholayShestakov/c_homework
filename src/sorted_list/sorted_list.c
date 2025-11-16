#include "sorted_list.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct ListElement {
    int value;
    struct ListElement *next;
} ListElement;

struct List {
    ListElement *head;
    ListElement *tail;
};

List *createList()
{
    List *list = calloc(1, sizeof(*list));
    return list;
}

void deleteList(List *list)
{
    ListElement *currentElement = list->head;
    while (currentElement != NULL) {
        ListElement *deletingElement = currentElement;
        currentElement = currentElement->next;
        free(deletingElement);
    }
    free(list);
}

void appendValue(List *list, int value)
{
    if (list->head == NULL) {
        ListElement *newElement = malloc(sizeof(*newElement));
        newElement->value = value;
        newElement->next = NULL;
        list->head = newElement;
        list->tail = newElement;
        return;
    }
    if (value <= list->head->value) {
        ListElement *newElement = malloc(sizeof(*newElement));
        newElement->value = value;
        newElement->next = list->head;
        list->head = newElement;
        return;
    }
    if (list->tail->value <= value) {
        ListElement *newElement = malloc(sizeof(*newElement));
        newElement->value = value;
        newElement->next = NULL;
        list->tail->next = newElement;
        list->tail = newElement;
        return;
    }

    ListElement *currentElement = list->head;
    while (!(currentElement->value < value && value <= currentElement->next->value)) {
        currentElement = currentElement->next;
    }

    ListElement *newElement = malloc(sizeof(*newElement));
    newElement->value = value;
    newElement->next = currentElement->next;
    currentElement->next = newElement;
}

void deleteValue(List *list, int value)
{
    if (list->head == NULL) {
        printf("The list is empty. \n");
        return;
    }
    if (list->head->value == value) {
        ListElement *deletingElement = list->head;
        list->head = deletingElement->next;
        free(deletingElement);
        return;
    }
    if (list->tail->value < value) {
        printf("The list not contains this value. \n");
        return;
    }

    ListElement *currentElement = list->head;
    while (currentElement->next != NULL) {
        if (currentElement->next->value == value) {
            ListElement *deletingElement = currentElement->next;
            currentElement->next = deletingElement->next;
            free(deletingElement);
            return;
        }
    }

    printf("The list not contains this value. \n");
}

void printList(List *list)
{
    ListElement *currentElement = list->head;
    while (currentElement != NULL) {
        printf("%d ", currentElement->value);
        currentElement = currentElement->next;
    }
    printf("\n");
}
