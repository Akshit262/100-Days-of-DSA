/*
 * Day 24 - Delete First Occurrence of a Key
 *
 * Problem:
 * Implement deletion of the first occurrence of a given key
 * from a singly linked list using dynamic memory allocation.
 *
 * Input:
 * - First line: integer n
 * - Second line: n space-separated integers
 * - Third line: integer key
 *
 * Output:
 * - Print the linked list elements after deletion,
 *   separated by spaces.
 *
 * Example:
 * Input:
 * 5
 * 10 20 30 40 50
 * 30
 *
 * Output:
 * 10 20 40 50
 *
 * Explanation:
 * Traverse the list, find the first node containing the key,
 * and remove it by adjusting the previous node's next pointer.
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

    scanf("%d", &key);

    struct Node *current = head;
    struct Node *previous = NULL;

    while (current != NULL) {

        if (current->data == key) {

            if (previous == NULL) {
                head = current->next;
            } else {
                
                previous->next = current->next;
            }

            free(current);
            break;
        }

        previous = current;
        current = current->next;
    }
    
    current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}
