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