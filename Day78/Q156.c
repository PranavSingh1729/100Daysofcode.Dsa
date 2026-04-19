/* Given an undirected connected graph with V vertices and adjacency list adj. You are required to find all the vertices removing which (and edges through it) disconnects the graph into 2 or more components and return it in sorted manner.
Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph. */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int timeCounter;

// DFS
void dfs(int u, int parent, int adj[MAX][MAX], int visited[],
         int disc[], int low[], int ap[], int n) {

    visited[u] = 1;
    disc[u] = low[u] = ++timeCounter;

    int children = 0;

    for (int v = 0; v < n; v++) {

        if (!adj[u][v]) continue;

        if (v == parent) continue;

        if (!visited[v]) {
            children++;

            dfs(v, u, adj, visited, disc, low, ap, n);

            low[u] = (low[u] < low[v]) ? low[u] : low[v];

            // Non-root condition
            if (parent != -1 && low[v] >= disc[u]) {
                ap[u] = 1;
            }
        }
        else {
            // Back edge
            low[u] = (low[u] < disc[v]) ? low[u] : disc[v];
        }
    }

    // Root condition
    if (parent == -1 && children > 1) {
        ap[u] = 1;
    }
}

int main() {
    int n, m;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    int adj[MAX][MAX] = {0};

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int visited[MAX] = {0};
    int disc[MAX], low[MAX], ap[MAX] = {0};

    timeCounter = 0;

    // Handle disconnected graph
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, -1, adj, visited, disc, low, ap, n);
        }
    }

    printf("Articulation Points:\n");
    int found = 0;

    for (int i = 0; i < n; i++) {
        if (ap[i]) {
            printf("%d ", i);
            found = 1;
        }
    }

    if (!found) {
        printf("-1");
    }

    printf("\n");

    return 0;
}