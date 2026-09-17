/*
 * Day 31 - Stack Implementation Using Array
 *
 * Problem:
 * Implement a stack data structure using an array with
 * the following operations:
 * push, pop, and display.
 *
 * Input:
 * - First line: integer n (number of operations)
 * - Next n lines: operation type and value (if applicable)
 *
 * Operations:
 * 1 value -> Push value onto the stack
 * 2       -> Pop the top element
 * 3       -> Display stack elements from top to bottom
 *
 * Output:
 * - For display: print stack elements from top to bottom
 * - For pop: print the popped element or "Stack Underflow"
 *
 * Example:
 * Input:
 * 5
 * 1 10
 * 1 20
 * 3
 * 2
 * 3
 *
 * Output:
 * 20 10
 * 20
 * 10
 */

#include <stdio.h>

#define MAX 100

int main() {
    int stack[MAX];
    int top = -1;

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int operation;

        scanf("%d", &operation);

        if (operation == 1) {
            int value;
            scanf("%d", &value);

            if (top == MAX - 1) {
                printf("Stack Overflow\n");
            } else {
                top++;
                stack[top] = value;
            }
        }

        else if (operation == 2) {
            if (top == -1) {
                printf("Stack Underflow\n");
            } else {
                printf("%d\n", stack[top]);
                top--;
            }
        }

        else if (operation == 3) {
            for (int j = top; j >= 0; j--) {
                printf("%d ", stack[j]);
            }

            printf("\n");
        }
    }

    return 0;
}
