/*
 * Day 25 - Count Occurrences of an Element in Linked List
 *
 * Problem:
 * Count the number of times a given key appears in a
 * singly linked list using dynamic memory allocation.
 *
 * Input:
 * - First line: integer n (number of nodes)
 * - Second line: n space-separated integers
 * - Third line: integer key
 *
 * Output:
 * - Print the number of times the key appears in the
 *   linked list.
 *
 * Example:
 * Input:
 * 6
 * 10 20 30 20 40 20
 * 20
 *
 * Output:
 * 3
 *
 * Explanation:
 * Traverse the linked list from head to end.
 * Each time a node's data matches the key, increment
 * the counter.
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    int n, key;

    scanf("%d", &n);

    struct Node *head = NULL;
    struct Node *tail = NULL;

    for (int i = 0; i < n; i++) {
        struct Node *newNode = malloc(sizeof(struct Node));

        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    scanf("%d", &key);
    
    int count = 0;
    struct Node *current = head;

    while (current != NULL) {
        if (current->data == key) {
            count++;
        }

        current = current->next;
    }

    printf("%d", count);
    
    current = head;

    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
