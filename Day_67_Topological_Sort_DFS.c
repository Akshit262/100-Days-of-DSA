/*
Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.

Input:
- First line contains two integers n and m.
- Next m lines contain directed edges u v.

Output:
- Print a valid topological ordering.
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

void dfs(struct Node *graph[], int visited[], int stack[],
         int *top, int vertex) {

    visited[vertex] = 1;

    struct Node *current = graph[vertex];

    while (current != NULL) {
        int next = current->vertex;

        if (!visited[next]) {
            dfs(graph, visited, stack, top, next);
        }

        current = current->next;
    }

    stack[++(*top)] = vertex;
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    struct Node *graph[n];

    for (int i = 0; i < n; i++) {
        graph[i] = NULL;
    }

    for (int i = 0; i < m; i++) {
        int u, v;

        scanf("%d %d", &u, &v);

        addEdge(graph, u, v);
    }

    int visited[n];
    int stack[n];
    int top = -1;

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(graph, visited, stack, &top, i);
        }
    }

    while (top >= 0) {
        printf("%d ", stack[top]);
        top--;
    }

    return 0;
}
