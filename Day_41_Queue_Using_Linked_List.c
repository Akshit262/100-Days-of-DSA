#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    int n;

    scanf("%d", &n);

    struct Node *front = NULL;
    struct Node *rear = NULL;

    for (int i = 0; i < n; i++) {
        char operation[20];

        scanf("%s", operation);

        if (strcmp(operation, "enqueue") == 0) {
            int value;
            scanf("%d", &value);

            struct Node *newNode =
                (struct Node *)malloc(sizeof(struct Node));

            newNode->data = value;
            newNode->next = NULL;

            if (rear == NULL) {
                
                front = newNode;
                rear = newNode;
            } else {
                
                rear->next = newNode;
                rear = newNode;
            }
        }

        else if (strcmp(operation, "dequeue") == 0) {

            if (front == NULL) {
                printf("-1\n");
            } else {
                struct Node *temp = front;

                printf("%d\n", front->data);

                front = front->next;

                if (front == NULL) {
                    rear = NULL;
                }

                free(temp);
            }
        }
    }

    return 0;
}