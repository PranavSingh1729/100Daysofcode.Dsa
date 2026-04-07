/* There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false. */

#include <stdio.h>

#define MAX 100005

int adj[MAX][100];   // adjacency list
int size[MAX];
int indegree[MAX];
int queue[MAX];

// function to check if all courses can be finished
int canFinish(int numCourses, int prerequisites[][2], int P) {

    // initialize
    for (int i = 0; i < numCourses; i++) {
        size[i] = 0;
        indegree[i] = 0;
    }

    // build graph
    for (int i = 0; i < P; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];

        adj[b][size[b]++] = a;  // b → a
        indegree[a]++;
    }

    // queue for BFS
    int front = 0, rear = 0;

    // push nodes with indegree 0
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    int count = 0;

    while (front < rear) {
        int node = queue[front++];
        count++;

        for (int i = 0; i < size[node]; i++) {
            int nb = adj[node][i];
            indegree[nb]--;

            if (indegree[nb] == 0)
                queue[rear++] = nb;
        }
    }

    return count == numCourses;
}

// MAIN FUNCTION
int main() {
    int numCourses = 2;
    int prerequisites[2][2] = {
        {1, 0},
        {0, 1}
    };

    if (canFinish(numCourses, prerequisites, 2))
        printf("Can finish all courses\n");
    else
        printf("Cannot finish (cycle exists)\n");

    return 0;
}