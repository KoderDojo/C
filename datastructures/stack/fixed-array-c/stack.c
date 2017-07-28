#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

#define EMPTY -1


stack* create(int capacity) {
    if (capacity < 1) {
        printf("Stack capacity must be greater than zero.");
        exit(1);
    }

    stack *s = NULL;

    s = (stack *)malloc(sizeof(stack));
    if (s == NULL) {
        printf("Error allocating memory for stack.");
        exit(1);
    }

    s->capacity = capacity;
    s->top = EMPTY;

    s->arr = (stackElement *)malloc(capacity * sizeof(stackElement));
    if (s->arr == NULL) {
        printf("Error allocating memory for stack elements.");
        exit(1);
    }

    return s;
}


stackElement peek(stack *s) {
    if (s->top == EMPTY) {
        printf("Peek from empty stack.");
        exit(1);
    }

    return s->arr[s->top];
}


stackElement pop(stack *s) {
    if (s->top == EMPTY) {
        printf("Pop from empty stack.");
        exit(1);
    }

    return s->arr[s->top--];
}


void push(stack *s, stackElement element) {
    if (s-> top == s->capacity - 1) {
        printf("Push to full stack.");
        exit(1);
    }

    s->arr[++s->top] = element;
}


int isEmpty(stack *s) {
    return s->top == EMPTY;
}


int capacity(stack *s) {
    return s->capacity;
}


int length(stack *s) {
    return s->top + 1;
}


void destroy(stack *s) {

    // Free memory allocated by malloc.
    free(s->arr);
    free(s);

    // Reset member variables.
    s->capacity = 0;
    s->top = EMPTY;
    s->arr = NULL;
}
