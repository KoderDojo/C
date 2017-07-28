#include <stdio.h>
#include <stdlib.h>

#include "queue.h"


Queue * createQueue(int capacity) {
    if (capacity < 1) {
        puts("Queue capacity must be greater than 0.");
        exit(1);
    }

    Queue *queueAlloc = (Queue *)malloc(sizeof(Queue));
    if (queueAlloc == NULL) {
        puts("Error allocating memory for queue.");
        exit(1);
    }
    Queue *queue = queueAlloc;

    // In order to queue N elements, the array
    // needs to be allocated to N + 1, because
    // a full array has 1 empty cell.
    queueElement *queueElements = (queueElement *)malloc((capacity + 1) * sizeof(queueElement));
    if (queueElements == NULL) {
        puts("Error allocating memory for queue elements.");
        exit(1);
    }
    queue->arr = queueElements;

    queue->capacity = capacity;
    queue->readIndex = 0;
    queue->writeIndex = 0;

    return queue;
}


void enqueue(Queue *queue, queueElement element) {
    if (isFull(*queue)) {
        puts("Enqueue when queue is full.");
        exit(1);
    }

    queue->arr[queue->writeIndex] = element;

    if(queue->writeIndex == queue->capacity)
        queue->writeIndex = 0;
    else
        queue->writeIndex++;
}


queueElement dequeue(Queue *queue) {
    if (isEmpty(*queue)) {
        puts("Dequeue when queue is empty.");
        exit(1);
    }

    queueElement temp = queue->arr[queue->readIndex];

    if(queue->readIndex == queue->capacity) {
        queue->readIndex = 0;
    } else
        queue->readIndex++;

    return temp;
}


int isEmpty(Queue queue) {
    return queue.readIndex == queue.writeIndex;
}


int isFull(Queue queue) {
    if (queue.writeIndex < queue.readIndex)
        return queue.readIndex == queue.writeIndex + 1;

    return queue.writeIndex == queue.capacity && queue.readIndex == 0;
}


void destroyQueue(Queue *queue) {
    free(queue->arr);
    free(queue);

    queue->capacity = 0;
    queue->readIndex = 0;
    queue->writeIndex = 0;
}
