#include "purely_functional_queue.c"

#include <assert.h>
#include <stdlib.h>

int main()
{
    Queue* queue = createQueue();
    assert(queue != NULL && queue->fHead == NULL && queue->rHead == NULL && "Queue created incorrect.");
    assert(dequeue(queue) == -1 && "Dequeue from empty queue works incorrect.");
    enqueue(queue, 1);
    assert(queue->rHead->value == 1 && "Enqueue works incorrect.");
    assert(dequeue(queue) == 1 && "Dequeue works incorrect.");
    enqueue(queue, 1);
    enqueue(queue, 2);
    assert(dequeue(queue) == 1 && "Dequeue with many elements works incorrect.");
    assert(queue->fHead->value == 2 && "ListSwap works incorrect.");
    deleteQueue(queue);
}
