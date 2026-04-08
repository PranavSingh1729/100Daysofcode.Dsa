/* Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS. */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list
int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int V;

// Function for DFS
void dfs(int node) {
    visited[node] = 1;

    for (int i = 0; i < V; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs(i);
        }
    }

    stack[++top] = node; // push to stack
}

// Topological Sort function
void topologicalSort() {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}

// Main function
int main() {
    V = 6;

    // Initialize matrix with 0
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }

    // Example graph
    adj[5][2] = 1;
    adj[5][0] = 1;
    adj[4][0] = 1;
    adj[4][1] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;

    topologicalSort();

    return 0;
}