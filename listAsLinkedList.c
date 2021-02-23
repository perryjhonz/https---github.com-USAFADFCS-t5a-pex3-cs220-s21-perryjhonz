/** listAsLinkedList.c
 * ===========================================================
 * Name: Daniel Perry
 * Section: T5
 * Project: PEX 3 - RPN Calculator
 * Purpose: List ADT as linked list
 * ===========================================================
 */
#include "listAsLinkedList.h"

#include <stdio.h>
#include <stdlib.h>

// initializes the linked list structure
LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->numberOfElements = 0;

    return list;
}

// deletes linked list, freeing all memory used
void deleteLinkedList(LinkedList* list) {
    Node* temp1 = list->head;
    Node* temp2 = list->head;
    for (int i = 0; i < list->numberOfElements; i++) {
        temp2 = temp1->next;
        free(temp1);
        temp1 = temp2;
    }
    list->head = NULL;
    list->tail = NULL;

    free(list);
    list = NULL;
}

// addes a new element to the end of the linked list
void appendElementLinkedList(LinkedList* list, void* element, ElementType type) {
    Node* temp1 = (Node*)malloc(sizeof(Node));
    temp1->type = type;

    temp1->data = element;
    temp1->next = NULL;
    if (list->numberOfElements == 0) {
        list->head = temp1;
        list->tail = temp1;
    }
    else {
        list->tail->next = temp1;
        list->tail = temp1;
    }
    list->numberOfElements++;
}

// returns the size of the linked list
int lengthOfLinkedList(LinkedList* list) {
    return list->numberOfElements;
}

// outputs the linked list to the console
void printLinkedList(LinkedList* list) {
    Node* temp1 = list->head;
    for (int i = 0; i < list->numberOfElements; i++) {
        printf("%lf, ", temp1->data);
        temp1 = temp1->next;
    }
    printf("\n");
}

// retrieves element at a given position
void* getElementLinkedList(LinkedList* list, int position) {
    Node* temp1 = list->head;
    for (int i = 0; i < position; i++) {
        temp1 = temp1->next;
    }
    return temp1->data;
}

// deletes element at a given position
void deleteElementLinkedList(LinkedList* list, int position) {
    Node* temp1 = list->head;
    if (position == 0) {
        list->head = list->head->next;
        free(temp1);
    }
    else {
        for (int i = 0; i < position - 1; i++) {
            temp1 = temp1->next;
        }
        Node* temp2 = temp1->next->next;
        free(temp1->next);
        temp1->next = temp2;
        if (position == list->numberOfElements - 1) {
            list->tail = temp1->next;
        }
    }
    
    list->numberOfElements--;
}

// adds element at a given position
void insertElementLinkedList(LinkedList* list, int position, void* element, ElementType type) {
    Node* temp1 = list->head;
    Node* new = (Node*)malloc(sizeof(Node));
    temp1->type = type;

    new->data = element;
    new->next = NULL;
    if (position == 0) {
        new->next = list->head;
        list->head = new;
    }
    else {
        for (int i = 0; i < position - 1; i++) {
            temp1 = temp1->next;
        }
        new->next = temp1->next;
        temp1->next = new;
    }
    list->numberOfElements++;
}

// changes element at a given position
void changeElementLinkedList(LinkedList* list, int position, void* newElement, ElementType type) {
    Node* temp1 = list->head;
    temp1->type = type;

    for (int i = 0; i < position; i++) {
        temp1 = temp1->next;
    }
    temp1->data = newElement;
}

// determines if the list is empty
bool isEmpty(LinkedList* list) {
    return list->numberOfElements = 0;
}