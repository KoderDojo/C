#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct listNode{
    int value;
    struct listNode* next;
}listNode;

listNode* insert_at_head( listNode* head, int data){
    listNode *newNode = (listNode *)malloc(sizeof(listNode));

    newNode->value = data;
    newNode->next = head;

    return newNode;
}

int main() {
    listNode *head = insert_at_head(NULL, 6);
    assert(head->value == 6);
    assert(head->next == NULL);

    listNode *newHead = insert_at_head(head, 7);
    assert(newHead->value == 7);
    assert(newHead->next == head);
    assert(newHead->next->value == 6);
    assert(newHead->next->next == NULL);

    free(head);
    free(newHead);

    return 0;
}
