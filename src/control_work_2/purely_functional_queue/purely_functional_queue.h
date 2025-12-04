#pragma once

typedef struct Queue Queue;

/*
Creates purely functional queue and returns pointer on it.
*/
Queue* createQueue();

/*
Pushes value in the queue.
*/
void enqueue(Queue* queue, int value);

/*
Pops value from the queue.
If queue is empty, returns -1.
*/
int dequeue(Queue* queue);

/*
Creates deletes queue and frees memory.
*/
void deleteQueue(Queue* queue);
