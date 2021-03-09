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

// initializes the queue structure
QueueAsLinkedList* queueInit() {
    QueueAsLinkedList* queue = (QueueAsLinkedList*)malloc(sizeof(QueueAsLinkedList));
    queue->head = -1;
    queue->tail = -1;

    return queue;
}

// puts an element onto the back of the queue
void queueEnqueue(QueueAsLinkedList* queue, void* element, ElementType type) {
    appendElementLinkedList(queue, element, type);
}

// removes an element from the front of the queue
void* queueDequeue(QueueAsLinkedList* queue, ElementType* type) {
    deleteElementLinkedList(queue, queue->head);
}

// determines if the queue is empty
bool queueIsEmpty(QueueAsLinkedList* queue) {
    return queue->numberOfElements = 0;
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
    getElementLinkedList(queue, queue->head, type);
}

// determines the size of the queue
int queueSize(QueueAsLinkedList* queue) {
    lengthOfLinkedList(queue);

    return queueSize(queue);
}

// outputs the queue to the console
void queuePrint(QueueAsLinkedList* queue) {
    printLinkedList(queue);
}