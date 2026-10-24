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

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    struct Node *graph[n];
    int indegree[n];

    for (int i = 0; i < n; i++) {
        graph[i] = NULL;
        indegree[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v;

        scanf("%d %d", &u, &v);

        addEdge(graph, u, v);
        indegree[v]++;
    }

    int queue[n];
    int front = 0;
    int rear = 0;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;

    while (front < rear) {
        int vertex = queue[front++];

        printf("%d ", vertex);
        count++;

        struct Node *current = graph[vertex];

        while (current != NULL) {
            int next = current->vertex;

            indegree[next]--;

            if (indegree[next] == 0) {
                queue[rear++] = next;
            }

            current = current->next;
        }
    }

    return 0;
}