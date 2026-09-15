/*
 * Day 29 - Rotate Linked List Right by K Places
 *
 * Problem:
 * Implement rotating a linked list to the right by k places
 * using dynamic memory allocation.
 *
 * Input:
 * - First line: integer n
 * - Second line: n space-separated integers
 * - Third line: integer k
 *
 * Output:
 * - Print the linked list elements after rotation,
 *   separated by spaces.
 *
 * Example:
 * Input:
 * 5
 * 10 20 30 40 50
 * 2
 *
 * Output:
 * 40 50 10 20 30
 *
 * Explanation:
 * Connect the last node to the head to form a circular list.
 * Traverse to the (n-k)th node, set its next to NULL,
 * and update the head to the next node.
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    int n, k;

    scanf("%d", &n);

    if (n == 0) {
        return 0;
    }

    struct Node *head = NULL;
    struct Node *tail = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        struct Node *newNode = malloc(sizeof(struct Node));

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    scanf("%d", &k);

    k = k % n;

    if (k == 0) {
        struct Node *current = head;

        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }

        return 0;
    }

    tail->next = head;

    int steps = n - k;

    struct Node *newTail = head;

    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    head = newTail->next;

    newTail->next = NULL;

    struct Node *current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}
