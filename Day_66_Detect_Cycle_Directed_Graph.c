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

int dfs(struct Node *graph[], int visited[], int recursionStack[], int vertex) {
    visited[vertex] = 1;
    recursionStack[vertex] = 1;

    struct Node *current = graph[vertex];

    while (current != NULL) {
        int next = current->vertex;

        if (!visited[next]) {
            if (dfs(graph, visited, recursionStack, next)) {
                return 1;
            }
        }
        else if (recursionStack[next]) {
            return 1;
        }

        current = current->next;
    }

    recursionStack[vertex] = 0;

    return 0;
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
    int recursionStack[n];

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        recursionStack[i] = 0;
    }

    int cycle = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(graph, visited, recursionStack, i)) {
                cycle = 1;
                break;
            }
        }
    }

    if (cycle) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}