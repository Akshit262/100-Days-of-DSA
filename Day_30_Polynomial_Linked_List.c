/*
 * Day 30 - Polynomial Using Linked List
 *
 * Problem:
 * Implement a polynomial using a linked list with
 * dynamic memory allocation.
 *
 * Each node stores:
 * - coefficient
 * - exponent
 * - pointer to the next node
 *
 * Input:
 * - First line: integer n (number of terms)
 * - Next n lines: two integers (coefficient and exponent)
 *
 * Output:
 * - Print the polynomial in standard form.
 *
 * Example:
 * Input:
 * 5
 * 10 4
 * 20 3
 * 30 2
 * 40 1
 * 50 0
 *
 * Output:
 * 10x^4 + 20x^3 + 30x^2 + 40x + 50
 *
 * Explanation:
 * Each node stores a coefficient and exponent.
 * The nodes are traversed to print the polynomial
 * in decreasing order of exponent.
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coefficient;
    int exponent;
    struct Node *next;
};

int main() {
    int n;

    scanf("%d", &n);

    struct Node *head = NULL;
    struct Node *tail = NULL;

    for (int i = 0; i < n; i++) {
        int coefficient, exponent;

        scanf("%d %d", &coefficient, &exponent);

        struct Node *newNode =
            malloc(sizeof(struct Node));

        newNode->coefficient = coefficient;
        newNode->exponent = exponent;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    struct Node *current = head;

    while (current != NULL) {

        printf("%d", current->coefficient);

        if (current->exponent > 0) {
            printf("x");

            if (current->exponent > 1) {
                printf("^%d", current->exponent);
            }
        }

        if (current->next != NULL) {
            printf(" + ");
        }

        current = current->next;
    }

    return 0;
}
