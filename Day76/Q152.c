/* Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
} */


#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

// Visited map
struct Node* visited[101];

// DFS clone
struct Node* dfs(struct Node* node) {
    if (!node) return NULL;

    if (visited[node->val] != NULL)
        return visited[node->val];

    // Create clone
    struct Node* clone = (struct Node*)malloc(sizeof(struct Node));
    clone->val = node->val;
    clone->numNeighbors = node->numNeighbors;
    clone->neighbors = (struct Node**)malloc(node->numNeighbors * sizeof(struct Node*));

    visited[node->val] = clone;

    // Clone neighbors
    for (int i = 0; i < node->numNeighbors; i++) {
        clone->neighbors[i] = dfs(node->neighbors[i]);
    }

    return clone;
}

// Clone Graph
struct Node* cloneGraph(struct Node* node) {
    for (int i = 0; i < 101; i++)
        visited[i] = NULL;

    return dfs(node);
}

// Helper to create node
struct Node* createNode(int val, int numNeighbors) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->numNeighbors = numNeighbors;
    node->neighbors = (struct Node**)malloc(numNeighbors * sizeof(struct Node*));
    return node;
}

// Print graph (DFS)
void printGraph(struct Node* node, int visitedPrint[]) {
    if (!node || visitedPrint[node->val]) return;

    visitedPrint[node->val] = 1;

    printf("Node %d -> ", node->val);
    for (int i = 0; i < node->numNeighbors; i++) {
        printf("%d ", node->neighbors[i]->val);
    }
    printf("\n");

    for (int i = 0; i < node->numNeighbors; i++) {
        printGraph(node->neighbors[i], visitedPrint);
    }
}

int main() {
    // Create example graph:
    // 1 -- 2
    // |    |
    // 4 -- 3

    struct Node* n1 = createNode(1, 2);
    struct Node* n2 = createNode(2, 2);
    struct Node* n3 = createNode(3, 2);
    struct Node* n4 = createNode(4, 2);

    n1->neighbors[0] = n2;
    n1->neighbors[1] = n4;

    n2->neighbors[0] = n1;
    n2->neighbors[1] = n3;

    n3->neighbors[0] = n2;
    n3->neighbors[1] = n4;

    n4->neighbors[0] = n1;
    n4->neighbors[1] = n3;

    printf("Original Graph:\n");
    int visitedPrint[101] = {0};
    printGraph(n1, visitedPrint);

    struct Node* cloned = cloneGraph(n1);

    printf("\nCloned Graph:\n");
    int visitedPrint2[101] = {0};
    printGraph(cloned, visitedPrint2);

    return 0;
}
