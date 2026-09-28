/*
 * Day 42 - Reverse a Queue Using Stack
 *
 * Problem:
 * Given a queue of integers, reverse the queue using a stack.
 *
 * Input:
 * - First line contains integer N
 * - Second line contains N space-separated integers
 *
 * Output:
 * - Print the reversed queue.
 *
 * Example:
 * Input:
 * 5
 * 10 20 30 40 50
 *
 * Output:
 * 50 40 30 20 10
 *
 * Explanation:
 * First, push all queue elements into a stack.
 * Then pop elements from the stack and put them back
 * into the queue. This reverses the queue.
 */

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
