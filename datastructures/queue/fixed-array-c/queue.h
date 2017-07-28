/* ***********************************************************************
 *
 *                         Queue Data Structure
 *
 *  A queue data structure with a fixed capacity that uses an array
 *  to hold queue elements. The capacity is specified upon creation.
 *
 *  createQueue - creates and returns a new, empty queue of specified capacity.
 *  enqueue - adds an element to the queue.
 *  dequeue - returns and removes the next element from the queue.
 *  isEmpty - returns true (1) or false (0) if the queue is empty.
 *  isFull - returns true (1) or false (0) if the queue is full.
 *  destroyQueue - frees memory and resets member variables.
 *
 *  e.g.
 *
 *  Queue *q = createQueue(10);
 *
 *  enqueue(q, 5);
 *  enqueue(q, 7);
 *
 *  while(!isEmpty(*q)) {
 *      print("Value: %d\n", dequeue(q));
 *  }
 *
 *  destroyQueue(q);
 *
 * ******************************************************************** */


#ifndef QUEUE_H
#define QUEUE_H

typedef int queueElement;

typedef struct {
    int capacity;
    int readIndex;
    int writeIndex;
    queueElement *arr;
}Queue;


/// Creates and returns a new, empty queue of specified capacity.
/// \param capacity Maximum number of elements held by the queue.
/// \return The queue.
Queue *createQueue(int capacity);


/// Adds an element to the queue.
/// \param queue The queue.
/// \param element The element to add to the queue.
void enqueue(Queue *queue, queueElement element);


/// Returns and removes the next element from the queue.
/// \param queue The queue.
/// \return The next element on the queue.
queueElement dequeue(Queue *queue);


/// Returns true (1) or false (0) if the queue is empty.
/// \param queue The queue.
/// \return true (1) or false (0) if the queue is empty.
int isEmpty(Queue queue);


/// Returns true (1) or false (0) if the queue is full.
/// \param queue The queue.
/// \return true (1) or false (0) if the queue is full.
int isFull(Queue queue);


/// Frees memory and resets member variables.
/// \param queue The queue.
void destroyQueue(Queue *queue);

#endif //QUEUE_H
