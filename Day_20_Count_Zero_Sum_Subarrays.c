/*
 * Day 20 - Count Subarrays with Sum Zero
 *
 * Problem:
 * Given an array of integers, count the number of subarrays
 * whose sum is equal to zero.
 *
 * Input:
 * - First line: integer n
 * - Second line: n integers
 *
 * Output:
 * - Print the count of subarrays having sum zero.
 *
 * Example:
 * Input:
 * 6
 * 1 -1 2 -2 3 -3
 *
 * Output:
 * 6
 *
 * Explanation:
 * The zero-sum subarrays are:
 * [1, -1]
 * [2, -2]
 * [3, -3]
 * [1, -1, 2, -2]
 * [2, -2, 3, -3]
 * [1, -1, 2, -2, 3, -3]
 *
 * Total = 6
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long count = 0;
    long long prefixSum = 0;

    /*
     * Store prefix sums and their frequencies.
     * Since this is a beginner implementation, we use
     * two arrays to store the prefix sums and their counts.
     */
    long long prefix[n + 1];
    int frequency[n + 1];

    int unique = 0;

    prefix[unique] = 0;
    frequency[unique] = 1;
    unique++;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        int found = -1;

        for (int j = 0; j < unique; j++) {
            if (prefix[j] == prefixSum) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            /*
             * Every previous occurrence of the same prefix sum
             * gives us one zero-sum subarray.
             */
            count += frequency[found];
            frequency[found]++;
        } else {
            prefix[unique] = prefixSum;
            frequency[unique] = 1;
            unique++;
        }
    }

    printf("%lld", count);

    return 0;
}
