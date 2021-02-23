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
    LinkedList* list = createLinkedList();
    double* testies = malloc(sizeof(double));
    *testies = 1;

    char* thingy = malloc(sizeof(char));
    *thingy = '*';

    appendElementLinkedList(list, testies, REAL_NUMBER);
    testies = malloc(sizeof(double));
    *testies = 2;

    appendElementLinkedList(list, thingy, MATH_OPERATOR);
    thingy = malloc(sizeof(char));
    *thingy = '+';

    appendElementLinkedList(list, testies, REAL_NUMBER);

    printf("%d\n", lengthOfLinkedList(list));

    printLinkedList(list);

    ElementType type = MATH_OPERATOR;
    printf("%c\n", *(char*)getElementLinkedList(list, 1, &type));

    appendElementLinkedList(list, thingy, MATH_OPERATOR);

    deleteElementLinkedList(list, 2);

    printLinkedList(list);

    testies = malloc(sizeof(double));
    *testies = 6;
    insertElementLinkedList(list, 1, testies, REAL_NUMBER);

    printLinkedList(list);

    changeElementLinkedList(list, 1, testies, REAL_NUMBER);

    printLinkedList(list);

    if (isEmpty(list)) {
        printf("Empty.\n");
    }

    deleteLinkedList(list);

    return 0;
}