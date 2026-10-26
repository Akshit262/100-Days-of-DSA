/*
Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

Input:
- First line contains n and m.
- Next m lines contain directed edges u v w.
- Source vertex is 0.

Output:
- Print shortest distances from source.
- Print NEGATIVE CYCLE if a negative weight cycle is reachable from source.
*/

#include <stdio.h>
#include <limits.h>

struct Edge {
    int u;
    int v;
    int weight;
};

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    struct Edge edges[m];

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d",
              &edges[i].u,
              &edges[i].v,
              &edges[i].weight);
    }

    int distance[n];

    for (int i = 0; i < n; i++) {
        distance[i] = INT_MAX;
    }

    distance[0] = 0;

    for (int i = 1; i < n; i++) {
        int changed = 0;

        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int weight = edges[j].weight;

            if (distance[u] != INT_MAX &&
                distance[u] + weight < distance[v]) {

                distance[v] = distance[u] + weight;
                changed = 1;
            }
        }

        if (!changed) {
            break;
        }
    }

    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        if (distance[u] != INT_MAX &&
            distance[u] + weight < distance[v]) {

            printf("NEGATIVE CYCLE");
            return 0;
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
