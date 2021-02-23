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

int lengthOfLinkedList(LinkedList* list) {
    return list->numberOfElements;
}

void printLinkedList(LinkedList* list) {
    Node* temp1 = list->head;
    for (int i = 0; i < list->numberOfElements; i++) {
        printf("%lf, ", temp1->data);
        temp1 = temp1->next;
    }
    printf("\n");
}

double getElementLinkedList(LinkedList* list, int position) {
    Node* temp1 = list->head;
    for (int i = 0; i < position; i++) {
        temp1 = temp1->next;
    }
    return temp1->data;
}

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

void insertElementLinkedList(LinkedList* list, int position, double element) {
    Node* temp1 = list->head;
    Node* new = (Node*)malloc(sizeof(Node));

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

void changeElementLinkedList(LinkedList* list, int position, double newElement) {
    Node* temp1 = list->head;

    for (int i = 0; i < position; i++) {
        temp1 = temp1->next;
    }
    temp1->data = newElement;
}

int findElementLinkedList(LinkedList* list, double element) {
    Node* temp1 = list->head;

    for (int i = 0; i < list->numberOfElements; i++) {
        if (temp1->data <= element + .1 && temp1->data >= element - .1) {
            return i;
        }
        temp1 = temp1->next;
    }
    return -1;
}

void selSortLinkedList(LinkedList* list) {
    Node* temp1 = list->head;
    Node* temp2 = list->head;
    Node* temp3 = list->head;

    for (int i = 0; i < list->numberOfElements - 1; i++) {
        for (int j = i; j < list->numberOfElements; j++) {
            if (temp3->data < temp2->data) {
                temp2 = temp3;
            }
            temp3 = temp3->next;
        }
        double temp = temp2->data;
        temp2->data = temp1->data;
        temp1->data = temp;
        temp1 = temp1->next;
        temp3 = temp1;
        temp2 = temp1;
    }
}

void insertSortLinkedList(LinkedList* list) {
    Node* temp1 = list->head;

    for (int i = 0; i < list->numberOfElements - 1; i++) {
        temp1 = list->head;
        for (int j = i; j < list->numberOfElements - 1; j++) {
            temp1 = temp1->next;
        }
        while (temp1->next != NULL && temp1->data > temp1->next->data) {
            double soup = temp1->data;
            temp1->data = temp1->next->data;
            temp1->next->data = soup;
            temp1 = temp1->next;
        }
    }
}