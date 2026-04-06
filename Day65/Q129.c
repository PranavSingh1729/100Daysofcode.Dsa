/* Problem: Using DFS and parent tracking, detect if undirected graph has a cycle. */

#include <stdio.h>

#define MAX 100

int visited[MAX];

// DFS function
int dfs(int node, int parent, int adj[MAX][MAX], int n) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1) {  // edge exists

            if (!visited[i]) {
                if (dfs(i, node, adj, n))
                    return 1;
            }
            else if (i != parent) {
                return 1;  // cycle found
            }
        }
    }
    return 0;
}

// Function to check cycle
int hasCycle(int adj[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, n))
                return 1;
        }
    }
    return 0;
}

int main() {
    int n;
    int adj[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    if (hasCycle(adj, n))
        printf("Cycle detected\n");
    else
        printf("No cycle\n");

    return 0;
}