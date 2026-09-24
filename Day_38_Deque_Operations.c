#include <stdio.h>
#include <string.h>

#define MAX 1000

int main() {
    int deque[MAX];
    int front = 0;
    int rear = -1;
    int size = 0;

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {

        char operation[20];
        scanf("%s", operation);

        if (strcmp(operation, "push_front") == 0) {
            int value;
            scanf("%d", &value);

            if (size == MAX) {
                printf("-1\n");
            } else {
                front = (front - 1 + MAX) % MAX;
                deque[front] = value;
                size++;

                if (size == 1) {
                    rear = front;
                }
            }
        }

        else if (strcmp(operation, "push_back") == 0) {
            int value;
            scanf("%d", &value);

            if (size == MAX) {
                printf("-1\n");
            } else {
                rear = (rear + 1) % MAX;
                deque[rear] = value;
                size++;

                if (size == 1) {
                    front = rear;
                }
            }
        }

        else if (strcmp(operation, "pop_front") == 0) {
            if (size == 0) {
                printf("-1\n");
            } else {
                printf("%d\n", deque[front]);

                front = (front + 1) % MAX;
                size--;

                if (size == 0) {
                    front = 0;
                    rear = -1;
                }
            }
        }

        else if (strcmp(operation, "pop_back") == 0) {
            if (size == 0) {
                printf("-1\n");
            } else {
                printf("%d\n", deque[rear]);

                rear = (rear - 1 + MAX) % MAX;
                size--;

                if (size == 0) {
                    front = 0;
                    rear = -1;
                }
            }
        }

        else if (strcmp(operation, "front") == 0) {
            if (size == 0) {
                printf("-1\n");
            } else {
                printf("%d\n", deque[front]);
            }
        }

        else if (strcmp(operation, "back") == 0) {
            if (size == 0) {
                printf("-1\n");
            } else {
                printf("%d\n", deque[rear]);
            }
        }

        else if (strcmp(operation, "empty") == 0) {
            printf("%d\n", size == 0);
        }

        else if (strcmp(operation, "size") == 0) {
            printf("%d\n", size);
        }
    }

    return 0;
}