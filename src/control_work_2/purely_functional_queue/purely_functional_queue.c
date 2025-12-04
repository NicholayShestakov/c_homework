#include "purely_functional_queue.h"

#include <assert.h>
#include <stdlib.h>

typedef struct ListElement {
    int value;
    struct ListElement* next;
    struct ListElement* prev;
} ListElement;

typedef struct Queue {
    ListElement* fHead;
    ListElement* rHead;
} Queue;

void swapLists(Queue* queue)
{
    ListElement* currentElement = queue->rHead;
    ListElement* previousElement = currentElement;
    while (currentElement != NULL) {
        ListElement* temp = currentElement->next;
        currentElement->next = currentElement->prev;
        currentElement->prev = temp;

        previousElement = currentElement;
        currentElement = currentElement->next;
    }

    queue->fHead = previousElement;
    queue->rHead = NULL;
}

Queue* createQueue()
{
    Queue* queue = malloc(sizeof(*queue));
    assert(queue != NULL && "Error! Memory is not allocated.");
    queue->fHead = NULL;
    queue->rHead = NULL;
    return queue;
}

void enqueue(Queue* queue, int value)
{
    ListElement* newElement = malloc(sizeof(*newElement));
    assert(newElement != NULL && "Error! Memory is not allocated.");
    newElement->value = value;
    newElement->next = NULL;
    newElement->prev = queue->rHead;
    queue->rHead = newElement;
}

int dequeue(Queue* queue)
{
    if (queue->fHead == NULL) {
        swapLists(queue);
    }
    if (queue->fHead == NULL) {
        return -1;
    }

    int value = queue->fHead->value;
    ListElement* newHead = queue->fHead->prev;
    free(queue->fHead);
    queue->fHead = newHead;
    queue->fHead->next = NULL;

    return value;
}

void deleteQueue(Queue* queue)
{
    while (queue->fHead != NULL || queue->rHead != NULL) {
        dequeue(queue);
    }
    free(queue);
}
