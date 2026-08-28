/*
 * Day 11 - Matrix Addition
 *
 * Problem:
 * Write a program to perform addition of two matrices
 * having the same dimensions.
 *
 * The sum of two matrices is obtained by adding
 * corresponding elements of the matrices.
 *
 * Input:
 * - First line: two integers m and n representing the
 *   number of rows and columns.
 * - Next m lines: n integers each representing the
 *   elements of the first matrix.
 * - Next m lines: n integers each representing the
 *   elements of the second matrix.
 *
 * Output:
 * - Print the resultant matrix after addition.
 * - Each row should be on a new line.
 * - Elements should be separated by spaces.
 *
 * Example:
 * Input:
 * 3 3
 * 1 2 3
 * 4 5 6
 * 7 8 9
 * 9 8 7
 * 6 5 4
 * 3 2 1
 *
 * Output:
 * 10 10 10
 * 10 10 10
 * 10 10 10
 *
 * Explanation:
 * Each element of the result matrix is the sum of the
 * corresponding elements from the two input matrices.
 */

#include <stdio.h>

int main() {
    int m, n;

    scanf("%d %d", &m, &n);

    int matrix1[m][n];
    int matrix2[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix1[i][j] + matrix2[i][j]);
        }

        printf("\n");
    }

    return 0;
}
