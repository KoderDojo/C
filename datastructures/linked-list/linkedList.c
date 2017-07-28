#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "linkedList.h"

linkedList* makeLinkedList() {
    linkedList *list = (linkedList *)calloc(1, sizeof(linkedList));

    if (list == NULL) {
        puts("Error allocating memory for linked list.");
        exit(1);
    }

    return list;
}

void destroyLinkedList(linkedList *list) {
    if (list == NULL) {
        puts("Error calling destroyLinkedList on NULL list.");
        exit(1);
    }

    node *currentNode = list->head;
    while(currentNode != NULL) {
        node *nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }

    list->head = NULL;
    list->tail = NULL;

    free(list);
}

bool isEmpty(linkedList *list) {
    return list->head == NULL && list->tail == NULL;
}

nodeElement popFront(linkedList *list) {
    if (isEmpty(list)) {
        puts("Error calling popFront from empty linked list.");
        exit(1);
    }

    node *oldHead = list->head;
    nodeElement element = oldHead->element;

    list->head = list->head->next;
    if (list->tail == oldHead)
        list->tail = list->head;

    free(oldHead);
    return element;
}

nodeElement popBack(linkedList *list) {
    if (isEmpty(list)) {
        puts("Error calling popBack from empty linked list.");
        exit(1);
    }

    // Only 1 Node in List
    if (list->head == list->tail) {
        nodeElement element = list->head->element;
        list->head = NULL;
        list->tail = NULL;
        return element;
    }

    node *currentNode = list->head;
    while(currentNode->next->next != NULL) {
        currentNode = currentNode->next;
    }

    nodeElement element = currentNode->next->element;
    free(currentNode->next);

    list->tail = currentNode;
    list->tail->next = NULL;

    return element;
}

void pushFront(linkedList *list, nodeElement element) {
    node *newNode = (node *)calloc(1, sizeof(node));

    if (newNode == NULL) {
        puts("Error allocating memory for newNode.");
        exit(1);
    }

    newNode->element = element;
    newNode->next = list->head;

    list->head = newNode;

    if (list->tail == NULL)
        list->tail = list->head;
}

void pushBack(linkedList *list, nodeElement element) {
    node *newNode = (node *)calloc(1, sizeof(node));

    if (newNode == NULL) {
        puts("Error allocating memory for newNode.");
        exit(1);
    }

    newNode->element = element;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
        return;
    }

    list->tail->next = newNode;
    list->tail = newNode;
}


int delete(linkedList *list, nodeElement element) {
    if (isEmpty(list)) {
        puts("Error calling delete from empty linked list.");
        exit(1);
    }

    node *previousNode = NULL;
    node *currentNode = list->head;

    while (currentNode != NULL) {
        if (currentNode->element == element)
            break;

        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    // Element not found.
    if (currentNode == NULL)
        return 0;

    // Element at Head
    if (list->head == currentNode) {
        popFront(list);
        return 1;
    }

    // Element at Tail, but not Head
    if (list->tail == currentNode) {
        popBack(list);
        return 1;
    }

    previousNode->next = currentNode->next;
    free(currentNode);
    return 1;
}
