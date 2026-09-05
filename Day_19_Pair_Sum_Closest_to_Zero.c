/*
 * Day 19 - Pair Sum Closest to Zero
 *
 * Problem:
 * Given an array of integers, find two elements whose
 * sum is closest to zero.
 *
 * Input:
 * - First line: integer n
 * - Second line: n space-separated integers
 *
 * Output:
 * - Print the pair of elements whose sum is closest to zero.
 *
 * Example:
 * Input:
 * 5
 * 1 60 -10 70 -80
 *
 * Output:
 * -10 1
 *
 * Explanation:
 * The sum of -10 and 1 is -9, which is closest to zero
 * compared to all other possible pairs.
 */

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;

    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;

    int bestLeft = arr[left];
    int bestRight = arr[right];

    int bestSum = arr[left] + arr[right];

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < abs(bestSum)) {
            bestSum = sum;
            bestLeft = arr[left];
            bestRight = arr[right];
        }

        if (sum < 0) {
            left++;
        }
        
        else if (sum > 0) {
            right--;
        }
        else {
    
            bestLeft = arr[left];
            bestRight = arr[right];
            break;
        }
    }

    printf("%d %d", bestLeft, bestRight);

    return 0;
}
