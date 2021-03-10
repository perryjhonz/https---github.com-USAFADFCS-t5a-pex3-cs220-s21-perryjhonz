/** rpnCalc.c
 * ===========================================================
 * Name: Daniel Perry
 * Section: T5
 * Project: PEX 3 - RPN Calculator
 * Purpose: Calculate answer given input in
 *          reverse polish notation
 * Documentation: C3C Brayboy helped me to include my test functions as well
 * as the string token functions that I needed for the queue. C3C Garbrecht helped me
 * to include the arithmetic that I needed for each of my math operators (i.e., +, -, *, /, ^).
 * No additional help was received.
 * ===========================================================
 */

#define _CRT_SECURE_NO_WARNINGS  // Hide "unsafe, deprecated" warnings, must be at the top

// what includes do we need here?
#include <stdio.h>

#include "rpnUtils.h"


int main() {
    char input[50]; // User input as an array
    do {
        printf("Enter the RPN expression: ");
        fgets(input, sizeof(input), stdin);
        fflush(stdin);

        StackAsLinkedList* steck = stackInit(); // Initialization that is later ommitted
        QueueAsLinkedList* queke = queueInit(); // Initialization that is later ommitted

        inputToken(queke, input);
        printf("\n");

        rpnCalculation(queke, steck);
        printf("\n");

    } while(input[0] != '\n');

    return 0;
}

