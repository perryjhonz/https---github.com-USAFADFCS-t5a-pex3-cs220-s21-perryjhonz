/** stackAsLinkedList.c
 * ===========================================================
 * Name: Daniel Perry
 * Section: T5
 * Project: PEX 3 - RPN Calculator
 * Purpose: Stack ADT library - LIFO
 * ===========================================================
 */
#include "stackAsLinkedList.h"

#include <stdbool.h>
#include <stddef.h>

// initializes the stack structure
StackAsLinkedList* stackInit() {
    StackAsLinkedList* stack = createLinkedList();
    return stack;
}

// puts an element onto the top of the stack
void stackPush(StackAsLinkedList* stack, void* element, ElementType type) {
    insertElementLinkedList(stack, 0, element, type);
}

// pops an element off the stack
void* stackPop(StackAsLinkedList* stack, ElementType* type) {
    void* ptr = getElementLinkedList(stack, 0, type);
    deleteElementLinkedList(stack, 0);

    return ptr;
}

// determines if the stack is empty
bool stackIsEmpty(StackAsLinkedList* stack) {
    return stack->numberOfElements = 0;
}

// determines if the stack is full
bool stackIsFull(StackAsLinkedList* stack) {
    if (stack->numberOfElements > 0) {
        return true;
    }
    else {
        return false;
    }
}

// deletes stack, freeing all memory used
void deleteStack(StackAsLinkedList* stack) {
    deleteLinkedList(stack);
}

// returns the item on the top of the stack but doesn't remove it
void* stackPeek(StackAsLinkedList* stack, ElementType* type) {
    return getElementLinkedList(stack, 0, type);
}

// determines the size of the stack
int stackSize(StackAsLinkedList* stack) {
    return lengthOfLinkedList(stack);
}

// outputs the stack to the console
void stackPrint(StackAsLinkedList* stack) {
    printLinkedList(stack);
}