/* Given a 2d matrix cost[][] of size n where cost[i][j] denotes the cost of moving from city i to city j. Your task is to complete a tour from city 0 (0-based index) to all other cities such that you visit each city exactly once and then at the end come back to city 0 at minimum cost. */

#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAX 12

int n;
int cost[MAX][MAX];
int dp[1<<MAX][MAX];

// Recursive TSP
int solve(int mask, int pos) {

    // All cities visited → return to start
    if (mask == (1 << n) - 1) {
        return cost[pos][0];
    }

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX;

    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {

            int newAns = cost[pos][city] +
                         solve(mask | (1 << city), city);

            if (newAns < ans)
                ans = newAns;
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    memset(dp, -1, sizeof(dp));

    int result = solve(1, 0); // start from city 0

    printf("Minimum travelling cost: %d\n", result);

    return 0;
}