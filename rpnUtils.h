/** rpnUtils.c
 * ===========================================================
 * Name: Daniel Perry
 * Section: T5
 * Project: PEX 3 - RPN Calculator
 * Purpose: Reverse polish notation utilities library
 * ===========================================================
 */

#ifndef RPNUTILS_H
#define RPNUTILS_H
#define _CRT_SECURE_NO_WARNINGS  // Hide "unsafe, deprecated" warnings, must be at the top

// What other includes do you need?
#include <string.h>

#include "queueAsLinkedList.h"
#include "stackAsLinkedList.h"

// prototypes for utility functions

/** inputToken()
 * @brief - collects input from user and places it into a queue
 * @param queue - a ptr for the queue used in the function
 * @param input - the user's input
 * @return - void, because all inputs are in a queue
 * @pre   - none
 * @post  - queue has user input, until a NULL character is entered
 */
void inputToken(QueueAsLinkedList* queue, char input[50]);

/** inputToken()
 * @brief - traverses the queue and completes RPN calculations
 * @param queue - a ptr for the queue used in the function
 * @param stack - a ptr for the stack used in the function
 * @return - void
 * @pre   - must have values and operations gotten from the queue
 * @post  - calculation done, queue should be empty, and stack only has 1 value
 */
void rpnCalculation(QueueAsLinkedList* queue, StackAsLinkedList* stack);

#endif  // RPNUTILS_H
