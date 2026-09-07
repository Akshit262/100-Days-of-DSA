/*
 * Day 21 - Create and Traverse Singly Linked List
 *
 * Problem:
 * Create a singly linked list using n integers and
 * traverse the list to print all its elements.
 *
 * Input:
 * - First line: integer n
 * - Second line: n space-separated integers
 *
 * Output:
 * - Print all elements of the linked list in order,
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
 * The elements are stored in nodes and connected using
 * the next pointer:
 *
 * 10 -> 20 -> 30 -> 40 -> 50 -> NULL
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
