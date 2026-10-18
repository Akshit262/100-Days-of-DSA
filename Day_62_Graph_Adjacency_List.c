/*
Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

Input:
- n (vertices)
- m (edges)
- edges (u, v)

Output:
- List of adjacency lists for each vertex
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

void addEdge(struct Node *adj[], int u, int v) {
    struct Node *newNode = createNode(v);

    if (adj[u] == NULL) {
        adj[u] = newNode;
    } else {
        struct Node *current = adj[u];

        while (current->next != NULL) {
            current = current->next;
        }

        current->next = newNode;
    }
}

int main() {
    int n, m;

    scanf("%d", &n);
    scanf("%d", &m);

    struct Node *adj[n];

    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }

    for (int i = 0; i < m; i++) {
        int u, v;

        scanf("%d %d", &u, &v);

        addEdge(adj, u, v);
        addEdge(adj, v, u);
    }

    for (int i = 0; i < n; i++) {
        printf("%d:", i);

        struct Node *current = adj[i];

        while (current != NULL) {
            printf(" %d", current->vertex);
            current = current->next;
        }

        printf("\n");
    }

    return 0;
}
