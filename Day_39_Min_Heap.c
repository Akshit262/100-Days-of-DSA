/*
 * Day 39 - Min Heap Using Array
 *
 * Problem:
 * Implement a Min Heap using an array where the smallest
 * element is always at the root.
 *
 * Supported Operations:
 * - insert x
 * - extractMin
 * - peek
 *
 * Input:
 * - First line contains integer N
 * - Next N lines contain heap operations
 *
 * Output:
 * - Print results of extractMin and peek
 * - Print -1 if operation cannot be performed
 *
 * Example:
 * Input:
 * 6
 * insert 40
 * insert 10
 * insert 30
 * peek
 * extractMin
 * peek
 *
 * Output:
 * 10
 * 10
 * 30
 */

#include <stdio.h>
#include <string.h>

#define MAX 1000

int heap[MAX];
int size = 0;

void insert(int value) {
    int i = size;

    heap[size] = value;
    size++;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap[parent] <= heap[i]) {
            break;
        }

        int temp = heap[parent];
        heap[parent] = heap[i];
        heap[i] = temp;

        i = parent;
    }
}

int peek() {
    if (size == 0) {
        return -1;
    }

    return heap[0];
}

int extractMin() {
    if (size == 0) {
        return -1;
    }

    int min = heap[0];

    heap[0] = heap[size - 1];
    size--;

    int i = 0;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < size && heap[left] < heap[smallest]) {
            smallest = left;
        }

        if (right < size && heap[right] < heap[smallest]) {
            smallest = right;
        }

        if (smallest == i) {
            break;
        }

        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;

        i = smallest;
    }

    return min;
}

int main() {
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char operation[20];

        scanf("%s", operation);

        if (strcmp(operation, "insert") == 0) {
            int value;
            scanf("%d", &value);

            if (size < MAX) {
                insert(value);
            }
        }

        else if (strcmp(operation, "peek") == 0) {
            printf("%d\n", peek());
        }

        else if (strcmp(operation, "extractMin") == 0) {
            printf("%d\n", extractMin());
        }
    }

    return 0;
}
