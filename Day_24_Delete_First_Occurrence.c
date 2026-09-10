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