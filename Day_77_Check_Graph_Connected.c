/*
Problem Statement
Using BFS or DFS, check if the entire graph is connected.

Input Format
n m
edges

Output Format
CONNECTED
NOT CONNECTED

Sample Input
4 2
1 2
3 4

Sample Output
NOT CONNECTED
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
        if (!visited[current->vertex]) {
            dfs(graph, visited, current->vertex);
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

    dfs(graph, visited, 1);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            printf("NOT CONNECTED");
            return 0;
        }
    }

    printf("CONNECTED");

    return 0;
}
