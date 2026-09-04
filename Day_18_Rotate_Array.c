/*
 * Day 18 - Rotate Array by K Positions
 *
 * Problem:
 * Given an array of integers, rotate the array to the right
 * by k positions.
 *
 * Input:
 * - First line: integer n
 * - Second line: n integers
 * - Third line: integer k
 *
 * Output:
 * - Print the rotated array.
 *
 * Example:
 * Input:
 * 5
 * 1 2 3 4 5
 * 2
 *
 * Output:
 * 4 5 1 2 3
 *
 * Explanation:
 * Rotating the array to the right by 2 positions moves
 * the last two elements (4, 5) to the beginning.
 */

#include <stdio.h>

int main() {
    int n, k;

    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);

    k = k % n;

    for (int r = 0; r < k; r++) {
        int last = arr[n - 1];

        for (int i = n - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }

        arr[0] = last;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
