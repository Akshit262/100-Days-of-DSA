/*
 * Day 40 - Heap Sort Using Max Heap
 *
 * Problem:
 * Implement Heap Sort using a Max Heap to sort an array
 * in ascending order.
 *
 * First build a Max Heap, then repeatedly extract the
 * maximum element and place it at the end of the array.
 *
 * Input:
 * - First line: integer n
 * - Second line: n space-separated integers
 *
 * Output:
 * - Print the sorted array in ascending order.
 *
 * Example:
 * Input:
 * 5
 * 4 1 3 9 7
 *
 * Output:
 * 1 3 4 7 9
 */

#include <stdio.h>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {

        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main() {
    int n;

    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    heapSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
