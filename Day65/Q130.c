/* Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.

Note: The graph can have multiple component. */
#include <stdio.h>

#define MAX 100005

int parent[MAX];

// Find with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Union
void unionSet(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if (pa != pb)
        parent[pa] = pb;
}

// Cycle detection using DSU
int isCycle(int V, int E, int edges[][2]) {

    // Initialize parent
    for (int i = 0; i < V; i++)
        parent[i] = i;

    // Process edges
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        if (find(u) == find(v))
            return 1;  // cycle found

        unionSet(u, v);
    }

    return 0; // no cycle
}

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
