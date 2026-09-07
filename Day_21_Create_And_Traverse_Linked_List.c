#include <stdio.h>
#include <stdlib.h>

// Structure for a linked list node
struct Node {
    int data;
    struct Node *next;
};

int main() {
    int n;

    scanf("%d", &n);

    struct Node *head = NULL;
    struct Node *tail = NULL;

    // Create the linked list
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        struct Node *newNode = malloc(sizeof(struct Node));

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            // First node
            head = newNode;
            tail = newNode;
        } else {
            // Add node at the end
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Traverse and print the linked list
    struct Node *current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    // Free allocated memory
    current = head;

    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}