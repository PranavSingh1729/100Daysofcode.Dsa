/* There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order. */

#include <stdio.h>

#define MAX 100

int adj[MAX][MAX], visited[MAX];
int disc[MAX], low[MAX];
int n, timeCounter = 0;

void dfs(int u, int parent) {
    visited[u] = 1;
    disc[u] = low[u] = ++timeCounter;

    for (int v = 0; v < n; v++) {
        if (adj[u][v]) {

            if (v == parent) continue;

            if (!visited[v]) {
                dfs(v, u);

                low[u] = (low[u] < low[v]) ? low[u] : low[v];

                if (low[v] > disc[u]) {
                    printf("Bridge: %d - %d\n", u, v);
                }
            } else {
                low[u] = (low[u] < disc[v]) ? low[u] : disc[v];
            }
        }
    }
}

int main() {
    int m;
    printf("Enter nodes and edges: ");
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter edges:\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }

    dfs(0, -1);

    return 0;
}