/*
Problem Statement
Using DFS or BFS, count number of connected components.

Input Format
n m
edges

Output Format
Number of connected components.

Sample Input
6 3
1 2
2 3
5 6

Sample Output
3

Explanation
Components: {1,2,3}, {4}, {5,6}
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node *next;
};

struct Node* createNode(int vertex) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->vertex = vertex;
    newNode->next = NULL;

    return newNode;
}

void addEdge(struct Node *graph[], int u, int v) {
    struct Node *newNode = createNode(v);

    newNode->next = graph[u];
    graph[u] = newNode;
}

void dfs(struct Node *graph[], int visited[], int vertex) {
    visited[vertex] = 1;

    struct Node *current = graph[vertex];

    while (current != NULL) {
        int next = current->vertex;

        if (!visited[next]) {
            dfs(graph, visited, next);
        }

        current = current->next;
    }
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    struct Node *graph[n + 1];

    for (int i = 1; i <= n; i++) {
        graph[i] = NULL;
    }

    for (int i = 0; i < m; i++) {
        int u, v;

        scanf("%d %d", &u, &v);

        addEdge(graph, u, v);
        addEdge(graph, v, u);
    }

    int visited[n + 1];

    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
    }

    int components = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            components++;
            dfs(graph, visited, i);
        }
    }

    printf("%d", components);

    return 0;
}
