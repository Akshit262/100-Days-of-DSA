#include <stdio.h>

int main() {
    int n, pos, x;

    scanf("%d", &n);

    int arr[n + 1];

    // Read array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &pos);
    scanf("%d", &x);

    // Shift elements to the right
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert new element
    arr[pos - 1] = x;

    // Print updated array
    for (int i = 0; i < n + 1; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}