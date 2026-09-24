/*
 * Day 38 - Deque (Double-Ended Queue)
 *
 * Problem:
 * Implement a Deque using an array.
 *
 * A Deque allows insertion and deletion from both
 * the front and the rear.
 *
 * Operations:
 * 1. push_front(value) - Insert at the front
 * 2. push_back(value)  - Insert at the rear
 * 3. pop_front()       - Remove from the front
 * 4. pop_back()        - Remove from the rear
 * 5. front()           - Return the front element
 * 6. back()            - Return the rear element
 * 7. empty()           - Check whether deque is empty
 * 8. size()            - Return number of elements
 *
 * Input:
 * - First line: integer n (number of operations)
 * - Next n lines: deque operations
 *
 * Output:
 * - Print results of front, back, size, pop_front,
 *   and pop_back operations.
 * - Print -1 if the deque is empty.
 */

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
