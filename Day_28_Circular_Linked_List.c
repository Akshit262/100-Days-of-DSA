/*
 * Day 28 - Circular Linked List Creation and Traversal
 *
 * Problem:
 * Implement a circular linked list using dynamic memory
 * allocation.
 *
 * The last node's next pointer should point back to the head.
 * Traverse the circular linked list starting from the head.
 *
 * Input:
 * - First line: integer n
 * - Second line: n space-separated integers
 *
 * Output:
 * - Print the circular linked list elements starting from
 *   head, separated by spaces.
 *
 * Example:
 * Input:
 * 5
 * 10 20 30 40 50
 *
 * Output:
 * 10 20 30 40 50
 *
 * Explanation:
 * The last node's next points to the head.
 * Traverse from head until returning to head to avoid
 * an infinite loop.
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    int n;

    scanf("%d", &n);

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

    tail->next = head;

    struct Node *current = head;

    if (head != NULL) {
        do {
            printf("%d ", current->data);
            current = current->next;
        } while (current != head);
    }

    return 0;
}
