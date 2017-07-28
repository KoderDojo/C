#include <assert.h>
#include <stdlib.h>


struct Node {
    int value;
    struct Node *next;
};


// Creating a new list in reverse order as
// opposed to mutating existing list.
struct Node * reverse_list(struct Node *node) {
    struct Node *headOfNewList = NULL;

    struct Node *currentNode = node;
    while (currentNode != NULL) {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->value = currentNode->value;
        newNode->next = headOfNewList;

        headOfNewList = newNode;
        currentNode = currentNode->next;
    }

    return headOfNewList;
}


// Test code
int main (int argc, char *argv[]) {
    struct Node input[3];
    struct Node expected[3];
    input[0].value = 1; input[0].next = &input[1];
    input[1].value = 2; input[1].next = &input[2];
    input[2].value = 3; input[2].next = NULL;
    expected[0].value = 3; expected[0].next = &expected[1];
    expected[1].value = 2; expected[1].next = &expected[2];
    expected[2].value = 1; expected[2].next = NULL;

    struct Node *actual = reverse_list(input);

    struct Node *currentNode = actual;
    int i=0;

    do {
        assert(currentNode->value == expected[i].value);

        i++;
        currentNode = currentNode->next;
    } while(currentNode != NULL);

    return 0;
}
