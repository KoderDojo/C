/* ***********************************************************************
 *
 *                         Stack Data Structure
 *
 *  A stack data structure with a fixed capacity that uses an array
 *  to hold stack elements. The capacity is specified upon creation.
 *
 *  create - creates and returns a new, empty stack of specified capacity.
 *  peek - returns, but does not remove, next element from stack.
 *  pop - returns and removes next element from stack.
 *  push - adds element to stack.
 *  isEmpty - returns true (1) or false (0) if stack is empty.
 *  capacity - returns max number of elements that can be held by stack.
 *  length - returns number of elements currently in stack.
 *  destroy - frees memory and resets member variables.
 *
 *  e.g.
 *
 *  stack *s = create(10);
 *
 *  push(s, 5);
 *  print("Peek: %d\n", peek(s));
 *  print("Pop: %d\n", pop(s));
 *
 *  destroy(s);
 *
 * ******************************************************************** */

#ifndef STACK_C_STACK_H
#define STACK_C_STACK_H

typedef int stackElement;

typedef struct{
    int capacity;
    int top;
    stackElement *arr;
}stack;


/// Creates a stack that can hold a maximum number of elements.
///
/// \param capacity Maximum # of elements that can be held by the stack.
/// \return A new, empty stack.
stack* create(int capacity);


/// Returns, but does not remove, the next element to be
/// popped from the stack.
///
/// \param s The stack.
/// \return The next element to be popped from the stack.
stackElement peek(stack *s);


/// Returns and removes the next element from the stack.
///
/// \param s The stack.
/// \return The next element from the stack.
stackElement pop(stack *s);


/// Adds an element to the stack.
///
/// \param s The stack.
/// \param element The element to be added to the stack.
void push(stack *s, stackElement element);


/// Returns 1 (true) if stack is empty, otherwise 0 (false).
///
/// \param s The stack.
/// \return 1 (true) if stack is empty, otherwise 0 (false).
int isEmpty(stack *s);


/// Returns the maximum number of elements that can be
/// held by the stack.
///
/// \param s The stack.
/// \return Maximum # of elements that can be held by the stack.
int capacity(stack *s);


/// The current number of elements on the stack.
///
/// \param s The stack.
/// \return The number of elements currently on the stack.
int length(stack *s);


/// Frees all memory and resets all member variables associated
/// with the stack.
/// \param s The stack.
void destroy(stack *s);

#endif //STACK_C_STACK_H
