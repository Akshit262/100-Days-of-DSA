#include <stdio.h>

#define MAX 1000

int main() {
    int n;
    int queue[MAX];
    int stack[MAX];

    int front = 0;
    int rear = 0;
    int top = -1;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &queue[rear]);
        rear++;
    }

    while (front < rear) {
        stack[++top] = queue[front];
        front++;
    }

    rear = 0;

    while (top >= 0) {
        queue[rear] = stack[top];
        rear++;
        top--;
    }

    for (int i = 0; i < rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}