/** rpnUtils.c
 * ===========================================================
 * Name: Daniel Perry
 * Section: T5
 * Project: PEX 3 - RPN Calculator
 * Purpose: Reverse polish notation utilities library
 * ===========================================================
 */

#include "rpnUtils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void inputToken(QueueAsLinkedList* queue, char input[50]) {
    ElementType type = REAL_NUMBER; // MATH_OPERATOR vs REAL_NUMBER
    char* strToken;

    // String is tokenized and is ran until completed
    strToken = strtok(input, "\n ");
    while (strToken != NULL) {
        // Sends all numbers to queue
        if (atof(strToken) != 0) {
            type = REAL_NUMBER;

            double* tmep = (double*)malloc(sizeof(double)); // temp pointer
            tmep[0] = atof(strToken);
            queueEnqueue(queue, (void*)tmep, type); // element of queue is enqueued
        }
        // Sends math operators, that are valid, to queue
        else if (strlen(strToken) == 1) {
            switch (strToken[0]) {
                case '^':
                case '*':
                case '/':
                case '+':
                case '-':
                    type = MATH_OPERATOR;
                    char* temp = (char*)malloc(sizeof(char)); // temp pointer 
                    temp[0] = strToken[0];
                    queueEnqueue(queue, (void*)temp, type); // element of queue is enqueued
                    break;
                default:
                    printf("invalid input: %s", strToken);
                    deleteQueue(queue);
                    break;
            }
        }
        else {
            printf("invalid input: %s", strToken);
            deleteQueue(queue);
            return;
        }
        strToken = strtok(NULL, "\n ");
    }
}

void rpnCalculation(QueueAsLinkedList* queue, StackAsLinkedList* stack) {
    ElementType type = REAL_NUMBER; // MATH_OPERATOR vs REAL_NUMBER
    void* element = NULL;
    element = queueDequeue(queue, &type);
    while (element != NULL) {
        if (type == MATH_OPERATOR) {
            if (stackSize(stack) < 2) {
                printf("invalid expression: not enough #'s\n");
                return;
            }
            else {
                printf("Operator: '%c' | Stack before operation: ", *(char*)element);
                stackPrint(stack);
                double* bheesecurger = malloc(sizeof(double)); // value from operation
                switch (*(char*)element) {
                    case '^':
                        bheesecurger[0] = pow(*(double*)stackPop(stack, &type), *(double*)stackPop(stack, &type));
                        break;
                    case '*':
                        bheesecurger[0] = *(double*)stackPop(stack, &type) * *(double*)stackPop(stack, &type);
                        break;
                    case '/':
                        bheesecurger[0] = *(double*)stackPop(stack, &type) / *(double*)stackPop(stack, &type);
                        break;
                    case '+':
                        bheesecurger[0] = *(double*)stackPop(stack, &type) + *(double*)stackPop(stack, &type);
                        break;
                    case '-':
                        bheesecurger[0] = *(double*)stackPop(stack, &type) - *(double*)stackPop(stack, &type);
                        break;
                    default:
                        printf("invalid operation: %c\n", *(char*)element);
                        return;
                }
                stackPush(stack, bheesecurger, REAL_NUMBER);
            }
        }
        else {
            stackPush(stack, element, REAL_NUMBER);
        }
        element = queueDequeue(queue, &type);
    }
    if (stackSize(stack) == 1) {
        element = stackPop(stack, &type);
        printf("Answer: %.3lf\n\n", *(double*)element);
    }
    else {
        printf("invalid expression: not enough operators\n");
    }
}
