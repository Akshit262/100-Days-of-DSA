/*
 * Day 35 - Queue Using Array
 *
 * Problem:
 * Implement a queue using an array.
 *
 * A queue follows FIFO:
 * First In, First Out.
 *
 * Input:
 * - First line: integer n (number of elements)
 * - Second line: n space-separated integers
 *
 * Output:
 * - Print queue elements from front to rear,
 *   separated by spaces.
 *
 * Example:
 * Input:
 * 5
 * 10 20 30 40 50
 *
 * Output:
 * 10 20 30 40 50
 *
 * Explanation:
 * Enqueue inserts elements at the rear.
 * Dequeue removes elements from the front.
 * Display prints elements from front to rear.
 */

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
