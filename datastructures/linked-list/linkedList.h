/* ***********************************************************************
 *
 *                         Linked List
 *
 *
 *  makeLinkedList - creates and returns a new, empty linked list.
 *  destroyLinkedList - frees memory and resets member variables.
 *  isEmpty - returns true if the list is empty, otherwise false.
 *  popFront - returns the first element (head) in the linked list.
 *  pushFront - appends element to front (head) of the linked list.
 *  popBack - return the last element (tail) in the linked list.
 *  pushBack - append element to end (tail) of the linked list.
 *  delete - removes first element from the linked list.
 *
 *  Note: popBack and delete are O(n) operations. Avoid if possible.
 *
 *  e.g.
 *
 *  linkedList *stack = makeLinkedList();
 *
 *  pushFront(stack, 1);
 *  pushFront(stack, 2);
 *
 *  popFront(stack); // 2
 *  popFront(stack); // 1
 *
 *  destroyLinkedList(stack);
 *
 * ******************************************************************** */


#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>

typedef int nodeElement;

struct node {
    nodeElement element;
    struct node *next;
};

typedef struct node node;

typedef struct linkedList {
    node *head;
    node *tail;
}linkedList;

/// Creates a new, empty linked list;
/// \return The new, empty linked list.
linkedList* makeLinkedList();

/// Removes all nodes and frees all memory.
/// \param list The linked list.
void destroyLinkedList(linkedList *list);

/// Determines if the linked list is empty.
/// \param list The linked list.
/// \return True if list empty, else false.
bool isEmpty(linkedList *list);

/// Returns the first element in the linked list.
/// \param list The linked list.
/// \return The first element in the linked list.
nodeElement popFront(linkedList *list);

/// Returns the last element in the linked list.
/// \param list The linked list.
/// \return The last element in the linked list.
nodeElement popBack(linkedList *list);

/// Appends the new element to the front of the linked list.
/// \param list The linked list.
/// \param element The new element to append to the list.
void pushFront(linkedList *list, nodeElement element);

/// Appends the new element to the end of the linked list.
/// \param list The linked list.
/// \param element The new element to append to the list.
void pushBack(linkedList *list, nodeElement element);

/// Removes the first element found from the linked list.
/// \param list The Linked List.
/// \param element The element to remove.
/// \return Number of elements deleted from the list: 0 or 1.
int delete(linkedList *list, nodeElement element);

#endif LINKEDLIST_H
