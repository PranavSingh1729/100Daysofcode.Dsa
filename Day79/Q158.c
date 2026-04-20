/* Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges. The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes a direct edge from vertex u to v. Find the number of strongly connected components in the graph. */

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int V, E;
int adj[MAX][MAX];
int rev[MAX][MAX];
int visited[MAX];
int stack[MAX], top = -1;

// DFS to fill stack
void dfs1(int node) {
    visited[node] = 1;

    for (int i = 0; i < V; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs1(i);
        }
    }

    stack[++top] = node;
}

// DFS on reversed graph
void dfs2(int node) {
    visited[node] = 1;

    for (int i = 0; i < V; i++) {
        if (rev[node][i] && !visited[i]) {
            dfs2(i);
        }
    }
}

int main() {
    scanf("%d %d", &V, &E);

    // initialize
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
            rev[i][j] = 0;
        }
        visited[i] = 0;
    }

    // input edges
    int u, v;
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        rev[v][u] = 1; // reverse graph
    }

    // step 1: fill stack
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    // reset visited
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
    }

    // step 2 & 3: process stack
    int scc_count = 0;

    while (top != -1) {
        int node = stack[top--];

        if (!visited[node]) {
            dfs2(node);
            scc_count++;
        }
    }

    printf("%d\n", scc_count);

    return 0;
}