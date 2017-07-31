#include <assert.h>
#include <string.h>
#include <stdlib.h>


typedef struct listNode{
    int value;
    struct listNode* next;
}listNode;

listNode* delete_at_head(listNode* head){
    if (head == NULL) return head;

    listNode *newHead = head->next;

    free(head);

    return newHead;
}

int main() {
    assert(delete_at_head(NULL) == NULL);

    listNode *head = calloc(1, sizeof(listNode));
    head->value = 5;

    assert(delete_at_head(head) == NULL);

    head = calloc(1, sizeof(listNode));
    head->value = 5;

    listNode *nextNode = calloc(1, sizeof(listNode));
    nextNode->value = 6;

    head->next = nextNode;

    assert(delete_at_head(head)->value == 6);

    free(nextNode);

    return 0;
}
