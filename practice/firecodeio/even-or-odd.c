#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct listNode{
    int value;
    struct listNode* next;
}listNode;


int is_list_even(listNode* head){
    int isEven = 1;

    listNode *currentNode = head;
    while(currentNode != NULL) {
        isEven = !isEven;
        currentNode = currentNode->next;
    }

    return isEven;
}


int main() {
    assert(is_list_even(NULL) == 1);

    listNode *head = (listNode *)malloc(sizeof(listNode));
    head->value = 6;
    head->next = NULL;

    assert(is_list_even(head) == 0);

    listNode *newNode = (listNode *)malloc(sizeof(listNode));
    newNode->value = 5;
    newNode->next = NULL;

    head->next = newNode;

    assert(is_list_even(head) == 1);

    free(head);
    free(newNode);

    return 0;
}
