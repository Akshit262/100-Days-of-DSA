/*
 * Day 26 - Doubly Linked List Insertion and Traversal
 *
 * Problem:
 * Implement a doubly linked list using dynamic memory allocation.
 *
 * Each node contains:
 * - data
 * - next pointer
 * - prev pointer
 *
 * Insert nodes sequentially and traverse the list
 * from head using the next pointer.
 *
 * Input:
 * - First line: integer n
 * - Second line: n space-separated integers
 *
 * Output:
 * - Print the linked list elements in forward order,
 *   separated by spaces.
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
 * Each node has data, next, and prev.
 * Nodes are inserted sequentially and the list is
 * traversed from head using the next pointer.
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
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
        newNode->prev = NULL;

        if (head == NULL) {
            
            head = newNode;
            tail = newNode;
        } else {
            
            tail->next = newNode;
            newNode->prev = tail;

            tail = newNode;
        }
    }

    struct Node *current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    current = head;

    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
