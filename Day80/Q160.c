/* There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path. */

#include <stdio.h>
#include <stdlib.h>

#define MAX 105
#define INF 1000000000

int findTheCity(int n, int edges[][3], int edgesSize, int distanceThreshold) {

    int dist[MAX][MAX];

    // Initialize
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    // Fill edges
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        dist[u][v] = w;
        dist[v][u] = w;
    }

    // Floyd-Warshall
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int minCount = INF;
    int city = -1;

    // Count reachable cities
    for (int i = 0; i < n; i++) {
        int count = 0;

        for (int j = 0; j < n; j++) {
            if (i != j && dist[i][j] <= distanceThreshold) {
                count++;
            }
        }

        // Choose smallest count, if tie pick larger index
        if (count <= minCount) {
            minCount = count;
            city = i;
        }
    }

    return city;
}

// Driver for VS Code
int main() {
    int n = 4;
    int edges[][3] = {
        {0,1,3},
        {1,2,1},
        {1,3,4},
        {2,3,1}
    };
    int threshold = 4;

    int result = findTheCity(n, edges, 4, threshold);

    printf("Answer: %d\n", result);

    return 0;
}