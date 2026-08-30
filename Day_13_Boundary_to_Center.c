#include <stdio.h>

int main() {
    int r, c;

    scanf("%d %d", &r, &c);

    int matrix[r][c];

    // Read matrix
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int top = 0;
    int bottom = r - 1;
    int left = 0;
    int right = c - 1;

    // Spiral traversal
    while (top <= bottom && left <= right) {

        // Move from left to right
        for (int j = left; j <= right; j++) {
            printf("%d ", matrix[top][j]);
        }
        top++;

        // Move from top to bottom
        for (int i = top; i <= bottom; i++) {
            printf("%d ", matrix[i][right]);
        }
        right--;

        // Move from right to left
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                printf("%d ", matrix[bottom][j]);
            }
            bottom--;
        }

        // Move from bottom to top
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                printf("%d ", matrix[i][left]);
            }
            left++;
        }
    }

    return 0;
}