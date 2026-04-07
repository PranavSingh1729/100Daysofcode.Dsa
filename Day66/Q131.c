/* Problem: Detect cycle in directed graph using DFS and recursion stack. */

#include <stdio.h>

#define MAX 100005

int adj[MAX][100];   // adjacency list (limit neighbors per node)
int size[MAX];
int visited[MAX];
int recStack[MAX];

// DFS function
int dfs(int node) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < size[node]; i++) {
        int nb = adj[node][i];

        if (!visited[nb]) {
            if (dfs(nb))
                return 1;
        }
        else if (recStack[nb]) {
            return 1;  // cycle found
        }
    }

    recStack[node] = 0; // remove from recursion stack
    return 0;
}

// Function to detect cycle
int isCycle(int V, int E, int edges[][2]) {

    // initialize
    for (int i = 0; i < V; i++) {
        size[i] = 0;
        visited[i] = 0;
        recStack[i] = 0;
    }

    // build directed graph
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u][size[u]++] = v;
    }

    // check all components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i))
                return 1;
        }
    }

    return 0;
}

// MAIN FUNCTION (for VS Code)
int main() {
    int V, E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    int edges[E][2];

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    if (isCycle(V, E, edges))
        printf("Cycle detected\n");
    else
        printf("No cycle\n");

    return 0;
}