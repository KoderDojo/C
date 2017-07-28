#include <stdio.h>
#include "stack.h"


int main (int argc, char *argv[]) {

    const int maxElements = 8;

    // Create stack.
    stack *s = create(maxElements);

    printf("\nNew stack.\n");

    // Print capacity of stack.
    printf("Capacity: %d\n", capacity(s));

    // Print length of stack.
    printf("Length = %d\n\n", length(s));

    // Push values on stack.
    printf("Adding elements to stack: ");
    for(int i=maxElements; i > 0; i--) {
        push(s, i);
        printf("%d, ", i);
    }

    // Print capacity of stack.
    printf("\nCapacity: %d\n", capacity(s));

    // Print length of stack.
    printf("Length = %d\n\n", length(s));

    // Peek at stack.
    printf("Only Peeking at Next Value to Pop: %d\n", peek(s));

    // Print capacity of stack.
    printf("Capacity: %d\n", capacity(s));

    // Print length of stack.
    printf("Length = %d\n\n", length(s));

    // Pop values off stack.
    printf("Popping Values: ");
    while(!isEmpty(s)) {
        printf("%d, ", pop(s));
    }

    // Print capacity of stack.
    printf("\nCapacity: %d\n", capacity(s));

    // Print length of stack.
    printf("Length = %d\n", length(s));

    // Destroy stack.
    destroy(s);
    printf("\nStack destroyed.\n");
}
