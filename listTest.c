/** listTest.c
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

int main() {
    // Creating the list
    LinkedList* list = createLinkedList();
    // Variable for REAL_NUMBER
    double* testies = malloc(sizeof(double));
    *testies = 1;

    // Variable for MATH_OPERATOR
    char* thingy = malloc(sizeof(char));
    *thingy = '*';

    // Test Case 1
    appendElementLinkedList(list, testies, REAL_NUMBER);
    testies = malloc(sizeof(double));
    *testies = 2;

    // Test Case 2
    appendElementLinkedList(list, thingy, MATH_OPERATOR);
    thingy = malloc(sizeof(char));
    *thingy = '+';

    // Test Case 3
    appendElementLinkedList(list, testies, REAL_NUMBER);

    printf("%d\n", lengthOfLinkedList(list));

    printLinkedList(list);

    ElementType type = MATH_OPERATOR;
    printf("%c\n", *(char*)getElementLinkedList(list, 1, &type));

    // Test Case 4
    appendElementLinkedList(list, thingy, MATH_OPERATOR);

    deleteElementLinkedList(list, 2);

    printLinkedList(list);

    // Test Case 5
    testies = malloc(sizeof(double));
    *testies = 6;
    insertElementLinkedList(list, 1, testies, REAL_NUMBER);

    printLinkedList(list);

    // Test Case 6
    changeElementLinkedList(list, 1, testies, REAL_NUMBER);

    printLinkedList(list);

    if (isEmpty(list)) {
        printf("Empty.\n");
    }

    deleteLinkedList(list);

    return 0;
}