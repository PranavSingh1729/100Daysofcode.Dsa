/* You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points. */

#include <stdio.h>
#include <limits.h>

int absVal(int x) {
    return x < 0 ? -x : x;
}

int minCostConnectPoints(int points[][2], int n) {
    
    int minDist[n];
    int visited[n];

    for (int i = 0; i < n; i++) {
        minDist[i] = INT_MAX;
        visited[i] = 0;
    }

    minDist[0] = 0;
    int result = 0;

    for (int i = 0; i < n; i++) {

        int u = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                u = j;
            }
        }

        visited[u] = 1;
        result += minDist[u];

        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                int cost = absVal(points[u][0] - points[v][0]) +
                           absVal(points[u][1] - points[v][1]);

                if (cost < minDist[v]) {
                    minDist[v] = cost;
                }
            }
        }
    }

    return result;
}

int main() {
    int points[][2] = {
        {0,0}, {2,2}, {3,10}, {5,2}, {7,0}
    };

    int n = 5;

    int result = minCostConnectPoints(points, n);
    printf("Minimum Cost: %d\n", result);

    return 0;
}