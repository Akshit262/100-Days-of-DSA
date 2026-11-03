/*
Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6

Explanation
One possible MST edges: (2-3), (3-4), (1-2) in c
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
    int weight;
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

void push(struct MinHeap *pq, int vertex, int weight) {
    int i = pq->size;

    pq->heap[i].vertex = vertex;
    pq->heap[i].weight = weight;
    pq->size++;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (pq->heap[parent].weight <= pq->heap[i].weight) {
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
                pq->heap[left].weight < pq->heap[smallest].weight) {
                smallest = left;
            }

            if (right < pq->size &&
                pq->heap[right].weight < pq->heap[smallest].weight) {
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

    struct Node *graph[n + 1];

    for (int i = 1; i <= n; i++) {
        graph[i] = NULL;
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;

        scanf("%d %d %d", &u, &v, &w);

        addEdge(graph, u, v, w);
        addEdge(graph, v, u, w);
    }

    int visited[n + 1];

    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
    }

    struct MinHeap pq;
    pq.size = 0;

    push(&pq, 1, 0);

    int total = 0;
    int count = 0;

    while (pq.size > 0 && count < n) {
        struct HeapNode current = pop(&pq);

        int vertex = current.vertex;
        int weight = current.weight;

        if (visited[vertex]) {
            continue;
        }

        visited[vertex] = 1;
        total += weight;
        count++;

        struct Node *temp = graph[vertex];

        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                push(&pq, temp->vertex, temp->weight);
            }

            temp = temp->next;
        }
    }

    if (count == n) {
        printf("%d", total);
    } else {
        printf("-1");
    }

    return 0;
}
