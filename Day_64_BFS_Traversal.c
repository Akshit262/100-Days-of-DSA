/*
Problem: Perform BFS from a given source using queue.

Input:
- First line: integer n
- Next n lines: number of neighbors followed by the neighbors
- Last line: source vertex s

Output:
- BFS traversal order
*/

#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int degree[MAX];
int visited[MAX];

void bfs(int source, int n) {
    int queue[MAX];
    int front = 0;
    int rear = 0;

    queue[rear++] = source;
    visited[source] = 1;

    while (front < rear) {
        int vertex = queue[front++];

        printf("%d ", vertex);

        for (int i = 0; i < degree[vertex]; i++) {
            int next = graph[vertex][i];

            if (!visited[next]) {
                visited[next] = 1;
                queue[rear++] = next;
            }
        }
    }
}

int main() {
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &degree[i]);

        for (int j = 0; j < degree[i]; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int source;
    scanf("%d", &source);

    bfs(source, n);

    return 0;
}
