#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int degree[MAX];
int visited[MAX];

void dfs(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < degree[vertex]; i++) {
        int next = graph[vertex][i];

        if (!visited[next]) {
            dfs(next);
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

    int s;
    scanf("%d", &s);

    dfs(s);

    return 0;
}