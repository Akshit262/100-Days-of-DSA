/*
 * Day 32 - Push and Pop in Stack
 *
 * Problem:
 * Implement push and pop operations on a stack and
 * verify stack operations.
 *
 * Input:
 * - First line: integer n
 * - Second line: n integers to push
 * - Third line: integer m (number of pops)
 *
 * Output:
 * - Print remaining stack elements from top to bottom.
 *
 * Example:
 * Input:
 * 5
 * 10 20 30 40 50
 * 2
 *
 * Output:
 * 30 20 10
 *
 * Explanation:
 * Push: 10, 20, 30, 40, 50
 * Pop twice: 50, 40
 * Remaining stack: 30, 20, 10
 */

#include <stdio.h>

#define MAX 1000

int main() {
    int stack[MAX];
    int n, m;
    int top = -1;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        top++;
        stack[top] = value;
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        if (top >= 0) {
            top--;
        }
    }

    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}
