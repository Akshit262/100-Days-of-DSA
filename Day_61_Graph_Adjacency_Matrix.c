/*
Problem Statement:
Build a graph with n vertices and m edges using adjacency matrix representation.
The graph may be directed or undirected.

Input:
- First line contains n (number of vertices)
- Second line contains m (number of edges)
- Next m lines contain pairs (u, v)

Output:
- Print the n x n adjacency matrix.
*/

#include <stdio.h>

int main() {
    int n, m;

    scanf("%d", &n);
    scanf("%d", &m);

    int matrix[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v;

        scanf("%d %d", &u, &v);

        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
