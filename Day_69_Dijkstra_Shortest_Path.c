/*
Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.

Input:
- First line contains n and m.
- Next m lines contain u, v, w representing an edge from u to v with weight w.
- Last line contains the source vertex.

Output:
- Print the shortest distance from the source to every vertex.
- Print -1 for unreachable vertices.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int vertex;
    int weight;
    struct Node *next;
};

struct HeapNode {
    int vertex;
    int distance;
};

struct MinHeap {
    struct HeapNode heap[10000];
    int size;
};

struct Node* createNode(int vertex, int weight) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;

    return newNode;
}

void addEdge(struct Node *graph[], int u, int v, int weight) {
    struct Node *newNode = createNode(v, weight);

    newNode->next = graph[u];
    graph[u] = newNode;
}

void swap(struct HeapNode *a, struct HeapNode *b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void push(struct MinHeap *pq, int vertex, int distance) {
    int i = pq->size;

    pq->heap[i].vertex = vertex;
    pq->heap[i].distance = distance;
    pq->size++;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (pq->heap[parent].distance <= pq->heap[i].distance) {
            break;
        }

        swap(&pq->heap[parent], &pq->heap[i]);

        i = parent;
    }
}

struct HeapNode pop(struct MinHeap *pq) {
    struct HeapNode result = pq->heap[0];

    pq->size--;

    if (pq->size > 0) {
        pq->heap[0] = pq->heap[pq->size];

        int i = 0;

        while (1) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = i;

            if (left < pq->size &&
                pq->heap[left].distance < pq->heap[smallest].distance) {
                smallest = left;
            }

            if (right < pq->size &&
                pq->heap[right].distance < pq->heap[smallest].distance) {
                smallest = right;
            }

            if (smallest == i) {
                break;
            }

            swap(&pq->heap[i], &pq->heap[smallest]);

            i = smallest;
        }
    }

    return result;
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    struct Node *graph[n];

    for (int i = 0; i < n; i++) {
        graph[i] = NULL;
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;

        scanf("%d %d %d", &u, &v, &w);

        addEdge(graph, u, v, w);
        addEdge(graph, v, u, w);
    }

    int source;
    scanf("%d", &source);

    int distance[n];

    for (int i = 0; i < n; i++) {
        distance[i] = INT_MAX;
    }

    distance[source] = 0;

    struct MinHeap pq;
    pq.size = 0;

    push(&pq, source, 0);

    while (pq.size > 0) {
        struct HeapNode current = pop(&pq);

        int vertex = current.vertex;
        int currentDistance = current.distance;

        if (currentDistance > distance[vertex]) {
            continue;
        }

        struct Node *temp = graph[vertex];

        while (temp != NULL) {
            int next = temp->vertex;
            int newDistance = currentDistance + temp->weight;

            if (newDistance < distance[next]) {
                distance[next] = newDistance;
                push(&pq, next, newDistance);
            }

            temp = temp->next;
        }
    }

    for (int i = 0; i < n; i++) {
        if (distance[i] == INT_MAX) {
            printf("-1 ");
        } else {
            printf("%d ", distance[i]);
        }
    }

    return 0;
}
