#include <assert.h>
#include <stdlib.h>
#include <time.h>

#include "queue.h"

#define MAX_CAPACITY 100


// Forward declare tests
void test_new_queue_empty();
void test_new_queue_not_full();
void test_queue_holds_capacity_items();
void test_queue_empty_with_0_items();
void test_queue_not_empty_with_at_least_1_item();
void test_queue_full_with_capacity_items();
void test_queue_not_full_with_less_than_capacity_items();
void test_queue_is_FIFO();
void test_queue_random_usage();


// Forward declare helper methods
void fillQueue(Queue *queue, int startElement, int numberOfElements);
void emptyQueue(Queue *queue, int numberOfElements);


int main() {
    test_new_queue_empty();
    test_new_queue_not_full();
    test_queue_holds_capacity_items();
    test_queue_empty_with_0_items();
    test_queue_not_empty_with_at_least_1_item();
    test_queue_full_with_capacity_items();
    test_queue_not_full_with_less_than_capacity_items();
    test_queue_is_FIFO();
    test_queue_random_usage();

    return 0;
}


/******************************************************************
 *
 *                            Test Methods
 *
 ******************************************************************/


void test_new_queue_empty() {
    Queue *queue = createQueue(1);

    assert(isEmpty(*queue));

    destroyQueue(queue);
}


void test_new_queue_not_full(){
    Queue *queue = createQueue(1);

    assert(!isFull(*queue));

    destroyQueue(queue);
}


// No assert statement here. Test will 'fail'
// if the code fails to execute because it
// can't hold capacity items.
// TODO: Re-evaluate this test because no assert.
void test_queue_holds_capacity_items() {
    for(int capacity=1; capacity < MAX_CAPACITY + 1; capacity++) {
        Queue *queue = createQueue(capacity);

        fillQueue(queue, 0, capacity);

        destroyQueue(queue);
    }
}


void test_queue_empty_with_0_items() {
    for(int capacity=1; capacity < MAX_CAPACITY + 1; capacity++) {
        Queue *queue = createQueue(capacity);

        fillQueue(queue, 0, capacity);
        emptyQueue(queue, capacity);

        assert(isEmpty(*queue));

        destroyQueue(queue);
    }
}


void test_queue_not_empty_with_at_least_1_item() {
    for(int capacity=1; capacity < MAX_CAPACITY + 1; capacity++) {
        Queue *queue = createQueue(capacity);

        for(int value=0; value < capacity; value++) {
            enqueue(queue, value);
            assert(!isEmpty(*queue));
        }

        destroyQueue(queue);
    }
}


void test_queue_full_with_capacity_items() {
    for(int capacity=1; capacity < MAX_CAPACITY + 1; capacity++) {
        Queue *queue = createQueue(capacity);

        fillQueue(queue, 0, capacity);

        assert(isFull(*queue));

        destroyQueue(queue);
    }
}


void test_queue_not_full_with_less_than_capacity_items() {
    for(int capacity=1; capacity < MAX_CAPACITY + 1; capacity++) {
        Queue *queue = createQueue(capacity);

        for(int value=0; value < capacity-1; value++) {
            enqueue(queue, value);
            assert(!isFull(*queue));
        }

        destroyQueue(queue);
    }
}


void test_queue_is_FIFO() {
    for(int capacity=1; capacity < MAX_CAPACITY + 1; capacity++) {
        Queue *queue = createQueue(capacity);

        int startValue = 300;

        // Purposely not using fillQueue here.
        int j=0;
        while(!isFull(*queue)) {
            enqueue(queue, startValue + j);
            j++;
        }

        j=0;
        while(!isEmpty(*queue)) {
            assert(dequeue(queue) == startValue+j);
            j++;
        }

        destroyQueue(queue);
    }
}


void test_queue_random_usage() {
    for(int capacity=1; capacity < MAX_CAPACITY + 1; capacity++) {
        Queue *queue = createQueue(capacity);

        assert(isEmpty(*queue));
        assert(!isFull(*queue));

        srand(time(NULL));

        for(int i=0; i < 100; i++) {
            int totalEnqueues = rand() % capacity + 1;

            int startValue = rand() % 10000;

            for(int j=0; j < totalEnqueues; j++) {
                enqueue(queue, startValue + j);
                assert(!isEmpty(*queue));

                if (j != totalEnqueues - 1 && totalEnqueues != capacity)
                    assert(!isFull(*queue));
            }

            if (totalEnqueues == capacity)
                assert(isFull(*queue));

            int j=0;
            while(!isEmpty(*queue)) {
                assert(dequeue(queue) == startValue + j);
                assert(!isFull(*queue));
                j++;
            }
        }

        destroyQueue(queue);
    }
}


/******************************************************************
 *
 *                           Helper Methods
 *
 ******************************************************************/


void fillQueue(Queue *queue, int startElement, int numberOfElements) {
    for(int i=startElement; i < startElement + numberOfElements; i++) {
        enqueue(queue, i);
    }
}


void emptyQueue(Queue *queue, int numberOfElements) {
    for(int i=0; i < numberOfElements; i++) {
        dequeue(queue);
    }
}
