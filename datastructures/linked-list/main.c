#include <assert.h>
#include <stddef.h>
#include "linkedList.h"

// Forward Declare Tests
// Many of these are white box tests,
// which are fragile.
void test_newLinkedListIsEmpty();
void test_pushFront();
void test_pushBack();
void test_popFrontReturnsElementsInOrder();
void test_popBackReturnsElementsInReverseOrder();
void test_deleteFromFrontReturns1();
void test_deleteFromBackReturns1();
void test_deleteNonExistentElementsReturns0();

int main (int argc, char *argv[]) {
    test_newLinkedListIsEmpty();
    test_pushFront();
    test_pushBack();
    test_popFrontReturnsElementsInOrder();
    test_popBackReturnsElementsInReverseOrder();
    test_deleteFromFrontReturns1();
    test_deleteFromBackReturns1();
    test_deleteNonExistentElementsReturns0();
}

void test_newLinkedListIsEmpty() {
    linkedList *list = makeLinkedList();
    assert(isEmpty(list));
    destroyLinkedList(list);
}

void test_pushFront() {
    linkedList *list = makeLinkedList();

    pushFront(list, 5);
    assert(!isEmpty(list));
    assert(list->head->element == 5);
    assert(list->tail->element == 5);
    assert(list->head == list->tail);

    pushFront(list, 6);
    assert(list->head->element == 6);
    assert(list->tail->element == 5);
    assert(list->head->next == list->tail);
    assert(list->tail->next == NULL);

    pushFront(list, 7);
    assert(list->head->element == 7);
    assert(list->tail->element == 5);
    assert(list->head->next->element == 6);
    assert(list->head->next->next == list->tail);
    assert(list->tail->next == NULL);

    assert(popBack(list) == 5);
    assert(popBack(list) == 6);
    assert(popBack(list) == 7);

    assert(isEmpty(list));

    destroyLinkedList(list);
}

void test_pushBack() {
    linkedList *list = makeLinkedList();

    pushBack(list, 5);
    assert(!isEmpty(list));
    assert(list->head->element == 5);
    assert(list->tail->element == 5);
    assert(list->head == list->tail);

    pushBack(list, 6);
    assert(list->head->element == 5);
    assert(list->tail->element == 6);
    assert(list->head->next == list->tail);
    assert(list->tail->next == NULL);

    pushBack(list, 7);
    assert(list->head->element == 5);
    assert(list->tail->element == 7);
    assert(list->head->next->element == 6);
    assert(list->head->next->next == list->tail);
    assert(list->tail->next == NULL);

    assert(popFront(list) == 5);
    assert(popFront(list) == 6);
    assert(popFront(list) == 7);

    assert(isEmpty(list));

    destroyLinkedList(list);
}

void test_popFrontReturnsElementsInOrder() {
    linkedList *list = makeLinkedList();

    for(int i=0; i < 20; i++) {
        pushBack(list, i);
        assert(!isEmpty(list));
    }

    for(int i=0; i < 20; i++) {
        assert(!isEmpty(list));
        assert(popFront(list) == i);
    }

    assert(isEmpty(list));

    destroyLinkedList(list);
}

void test_popBackReturnsElementsInReverseOrder() {
    linkedList *list = makeLinkedList();

    for(int i=0; i < 20; i++) {
        pushBack(list, i);
        assert(!isEmpty(list));
    }

    for(int i=19; i > -1; i--) {
        assert(!isEmpty(list));
        assert(popBack(list) == i);
    }

    assert(isEmpty(list));

    destroyLinkedList(list);
}

void test_deleteFromFrontReturns1() {
    linkedList *list = makeLinkedList();

    for(int i=0; i < 20; i++) {
        pushBack(list, i);
        assert(!isEmpty(list));
    }

    for(int i=0; i < 20; i++) {
        assert(!isEmpty(list));
        assert(delete(list, i) == 1);
    }

    assert(isEmpty(list));

    destroyLinkedList(list);
}

void test_deleteFromBackReturns1() {
    linkedList *list = makeLinkedList();

    for(int i=0; i < 20; i++) {
        pushBack(list, i);
        assert(!isEmpty(list));
    }

    for(int i=19; i > -1; i--) {
        assert(!isEmpty(list));
        assert(delete(list, i) == 1);
    }

    assert(isEmpty(list));

    destroyLinkedList(list);
}

void test_deleteNonExistentElementsReturns0() {
    linkedList *list = makeLinkedList();

    for(int i=0; i < 20; i++) {
        pushBack(list, i);
        assert(!isEmpty(list));
    }

    for(int i=100; i < 120; i++) {
        assert(!isEmpty(list));
        assert(delete(list, i) == 0);
    }

    assert(!isEmpty(list));

    destroyLinkedList(list);
}
