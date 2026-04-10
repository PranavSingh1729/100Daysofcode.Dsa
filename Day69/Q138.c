/* You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1. */

#include <stdio.h>
#include <limits.h>

#define MAX 101

int networkDelayTime(int times[][3], int timesSize, int n, int k) {
    
    int dist[MAX];
    int visited[MAX] = {0};

    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    dist[k] = 0;

    // Dijkstra
    for (int i = 1; i <= n; i++) {
        int u = -1;

        for (int j = 1; j <= n; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        visited[u] = 1;

        for (int i = 0; i < timesSize; i++) {
            int src = times[i][0];
            int dest = times[i][1];
            int wt = times[i][2];

            if (src == u && dist[u] != INT_MAX) {
                if (dist[u] + wt < dist[dest]) {
                    dist[dest] = dist[u] + wt;
                }
            }
        }
    }

    int maxTime = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            return -1;
        if (dist[i] > maxTime)
            maxTime = dist[i];
    }

    return maxTime;
}

int main() {
    int times[][3] = {
        {2,1,1},
        {2,3,1},
        {3,4,1}
    };

    int n = 4;
    int k = 2;

    int result = networkDelayTime(times, 3, n, k);
    printf("Minimum time: %d\n", result);

    return 0;
}