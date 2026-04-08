/* There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array. */

#include <stdio.h>
#include <stdlib.h>

#define MAX 2000

int adj[MAX][MAX];
int state[MAX];   // 0 = unvisited, 1 = visiting, 2 = visited
int stack[MAX];
int top = -1;
int V;

// DFS with cycle detection
int dfs(int node) {
    state[node] = 1; // visiting

    for (int i = 0; i < V; i++) {
        if (adj[node][i]) {
            if (state[i] == 1) return 0; // cycle found
            if (state[i] == 0) {
                if (!dfs(i)) return 0;
            }
        }
    }

    state[node] = 2; // visited
    stack[++top] = node;
    return 1;
}

// Main function to find order
void findOrder() {
    for (int i = 0; i < V; i++) {
        if (state[i] == 0) {
            if (!dfs(i)) {
                printf("[]"); // cycle → no valid order
                return;
            }
        }
    }

    // Print result
    printf("[");
    for (int i = top; i >= 0; i--) {
        printf("%d", stack[i]);
        if (i != 0) printf(", ");
    }
    printf("]");
}

int main() {
    V = 4;
    
    // initialize
    for (int i = 0; i < V; i++) {
        state[i] = 0;
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }

    // prerequisites: [ai, bi] => bi -> ai
    adj[1][0] = 1; // 0 depends on 1
    adj[2][0] = 1;
    adj[3][1] = 1;
    adj[3][2] = 1;

    findOrder();

    return 0;
}