/** queueAsLinkedList.c
 * ===========================================================
 * Name: Daniel Perry
 * Section: T5
 * Project: PEX 3 - RPN Calculator
 * Purpose: Queue ADT library - FIFO
 * ===========================================================
 */
#include "queueAsLinkedList.h"
#include "listAsLinkedList.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

// initializes the queue structure
QueueAsLinkedList* queueInit() {
    QueueAsLinkedList* queue = (QueueAsLinkedList*)malloc(sizeof(QueueAsLinkedList));
    queue->head = NULL;
    queue->tail = NULL;
    queue->numberOfElements = 0;

    return queue;
}

// puts an element onto the back of the queue
void queueEnqueue(QueueAsLinkedList* queue, void* element, ElementType type) {
    appendElementLinkedList(queue, element, type);
}

// removes an element from the front of the queue
void* queueDequeue(QueueAsLinkedList* queue, ElementType* type) {
    if (queueIsEmpty(queue)) {
        return NULL;
    }
    void* ptr = getElementLinkedList(queue, 0, type);

    deleteElementLinkedList(queue, 0);
    return ptr;
}

// determines if the queue is empty
bool queueIsEmpty(QueueAsLinkedList* queue) {
    return queue->numberOfElements == 0;
}

// determines if the queue is full
bool queueIsFull(QueueAsLinkedList* queue) {
    lengthOfLinkedList(queue);

    if (queue->numberOfElements > 0) {
        return true;
    }
    else {
        return false;
    }
}

// deletes queue, freeing all memory used
void deleteQueue(QueueAsLinkedList* queue) {
    deleteLinkedList(queue);
}

// returns the item in the front of the queue but doesn't remove it
void* queuePeek(QueueAsLinkedList* queue, ElementType* type) {
    return getElementLinkedList(queue, 0, type);
}

// determines the size of the queue
int queueSize(QueueAsLinkedList* queue) {
    return lengthOfLinkedList(queue);
}

// outputs the queue to the console
void queuePrint(QueueAsLinkedList* queue) {
    printLinkedList(queue);
}