/* Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue. */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Graph
int adj[MAX][MAX];
int V;

// Min Heap structure
typedef struct {
    int node;
    int dist;
} HeapNode;

HeapNode heap[MAX];
int size = 0;

// Swap
void swap(HeapNode *a, HeapNode *b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1)/2].dist > heap[i].dist) {
        swap(&heap[i], &heap[(i - 1)/2]);
        i = (i - 1)/2;
    }
}

// Heapify down
void heapifyDown(int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && heap[left].dist < heap[smallest].dist)
        smallest = left;

    if (right < size && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Insert into heap
void push(int node, int dist) {
    heap[size].node = node;
    heap[size].dist = dist;
    heapifyUp(size);
    size++;
}

// Extract min
HeapNode pop() {
    HeapNode root = heap[0];
    heap[0] = heap[--size];
    heapifyDown(0);
    return root;
}

// Dijkstra
void dijkstra(int src) {
    int dist[MAX];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;
    push(src, 0);

    while (size > 0) {
        HeapNode current = pop();
        int u = current.node;

        for (int v = 0; v < V; v++) {
            if (adj[u][v] > 0) {
                int weight = adj[u][v];
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    push(v, dist[v]);
                }
            }
        }
    }

    // Print result
    printf("Shortest distances from source %d:\n", src);
    for (int i = 0; i < V; i++) {
        printf("To %d = %d\n", i, dist[i]);
    }
}

// Main
int main() {
    V = 5;

    // Initialize graph
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    // Example graph
    adj[0][1] = 10;
    adj[0][4] = 5;
    adj[1][2] = 1;
    adj[1][4] = 2;
    adj[2][3] = 4;
    adj[3][0] = 7;
    adj[4][1] = 3;
    adj[4][2] = 9;
    adj[4][3] = 2;

    dijkstra(0);

    return 0;
}