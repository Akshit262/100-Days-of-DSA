#include <stdio.h>

#define MAX 1000

int main() {
    int queue[MAX];
    int front = 0;
    int rear = 0;
    int size = 0;

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        queue[rear] = value;
        rear = (rear + 1) % MAX;
        size++;
    }

    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        if (size > 0) {
            front = (front + 1) % MAX;
            size--;
        }
    }

    for (int i = 0; i < size; i++) {
        printf("%d ", queue[(front + i) % MAX]);
    }

    return 0;
}