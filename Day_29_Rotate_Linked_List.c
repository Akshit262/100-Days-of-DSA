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