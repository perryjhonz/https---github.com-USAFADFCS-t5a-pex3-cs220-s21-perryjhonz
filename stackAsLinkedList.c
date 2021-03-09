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
    insertElementLinkedList(stack, stack->head, element, type);
}

// pops an element off the stack
void* stackPop(StackAsLinkedList* stack, ElementType* type) {
    deleteElementLinkedList(stack, stack->tail);
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
    getElementLinkedList(stack, stack->head, type);
}

// determines the size of the stack
int stackSize(StackAsLinkedList* stack) {
    lengthOfLinkedList(stack);

    return stackSize(stack);
}

// outputs the stack to the console
void stackPrint(StackAsLinkedList* stack) {
    printLinkedList(stack);
}