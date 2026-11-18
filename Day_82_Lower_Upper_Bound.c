#include <stdio.h>

int lowerBound(int arr[], int n, int x) {
    int left = 0;
    int right = n;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] >= x) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int upperBound(int arr[], int n, int x) {
    int left = 0;
    int right = n;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > x) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    int n;

    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int x;
    scanf("%d", &x);

    int lower = lowerBound(arr, n, x);
    int upper = upperBound(arr, n, x);

    printf("%d %d", lower, upper);

    return 0;
}