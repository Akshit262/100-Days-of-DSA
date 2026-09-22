/*
 * Day 36 - Circular Queue Using Array
 *
 * Problem:
 * Implement a circular queue using an array.
 *
 * Input:
 * - First line: integer n (number of elements to enqueue)
 * - Second line: n space-separated integers
 * - Third line: integer m (number of dequeue operations)
 *
 * Output:
 * - Print queue elements from front to rear after
 *   performing the dequeue operations.
 *
 * Example:
 * Input:
 * 5
 * 10 20 30 40 50
 * 2
 *
 * Output:
 * 30 40 50
 *
 * Explanation:
 * The queue initially contains:
 * 10 20 30 40 50
 *
 * After two dequeue operations:
 * 30 40 50
 *
 * The circular queue allows front and rear to wrap around
 * when they reach the end of the array.
 */

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
