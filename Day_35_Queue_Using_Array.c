#include <stdio.h>

#define MAX 1000

int main() {
    int queue[MAX];
    int front = 0;
    int rear = -1;
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        rear++;
        queue[rear] = value;
    }

    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}