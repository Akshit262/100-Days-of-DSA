/*
Problem: Given a weighted graph with n vertices, implement the Floyd-Warshall algorithm
to compute the shortest distances between every pair of vertices. The graph may contain
positive or negative edge weights, but it does not contain any negative weight cycles.

Input:
- First line: integer n representing the number of vertices
- Next n lines: n space-separated integers representing the adjacency matrix
- -1 indicates no direct edge between two vertices

Output:
- Print the shortest distance matrix.

Example:
Input:
4
0 5 -1 10
-1 0 3 -1
-1 -1 0 1
-1 -1 -1 0

Output:
0 5 8 9
-1 0 3 4
-1 -1 0 1
-1 -1 -1 0

Explanation:
The Floyd-Warshall algorithm considers each vertex as an intermediate point
and updates the shortest paths between all pairs of vertices.
*/

#include <stdio.h>
#include <limits.h>

#define INF 1000000000

int main() {
    int n;

    scanf("%d", &n);

    int dist[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int value;
            scanf("%d", &value);

            if (value == -1 && i != j) {
                dist[i][j] = INF;
            } else {
                dist[i][j] = value;
            }
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (dist[i][k] != INF &&
                    dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {

                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (dist[i][j] == INF) {
                printf("-1");
            } else {
                printf("%d", dist[i][j]);
            }

            if (j < n - 1) {
                printf(" ");
            }
        }

        printf("\n");
    }

    return 0;
}
