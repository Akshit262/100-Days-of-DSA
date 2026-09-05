#include <stdio.h>
#include <stdlib.h>

// Function used by qsort()
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;

    scanf("%d", &n);

    int arr[n];

    // Read array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array
    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;

    int bestLeft = arr[left];
    int bestRight = arr[right];

    int bestSum = arr[left] + arr[right];

    // Two-pointer approach
    while (left < right) {
        int sum = arr[left] + arr[right];

        // Check if current sum is closer to zero
        if (abs(sum) < abs(bestSum)) {
            bestSum = sum;
            bestLeft = arr[left];
            bestRight = arr[right];
        }

        // If sum is negative, increase it
        if (sum < 0) {
            left++;
        }
        // If sum is positive, decrease it
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