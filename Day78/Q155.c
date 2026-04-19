/* Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
... */
#include <stdio.h>
#include <limits.h>

#define MAX 100

int graph[MAX][MAX];
int n, m;

// Find minimum key vertex
int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, minIndex;

    for (int i = 0; i < n; i++) {
        if (!mstSet[i] && key[i] < min) {
            min = key[i];
            minIndex = i;
        }
    }

    return minIndex;
}

int primMST() {
    int key[MAX];     // Minimum weight to connect
    int mstSet[MAX];  // Included in MST

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0; // Start from node 0

    int totalWeight = 0;

    for (int count = 0; count < n; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;
        totalWeight += key[u];

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    return totalWeight;
}

int main() {
    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    // Initialize graph
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        graph[u][v] = w;
        graph[v][u] = w; // undirected
    }

    int result = primMST();

    printf("Total weight of MST: %d\n", result);

    return 0;
}