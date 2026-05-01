/* Problem Statement
Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.

Determine the minimum time required to paint all boards.

Input Format
n k
n space-separated integers representing board lengths */

#include <stdio.h>

// Check if we can paint within maxTime using k painters
int canPaint(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int current = 0;

    for (int i = 0; i < n; i++) {

        if (boards[i] > maxTime)
            return 0;

        if (current + boards[i] <= maxTime) {
            current += boards[i];
        } else {
            painters++;
            current = boards[i];
        }

        if (painters > k)
            return 0;
    }

    return 1;
}

// Main function
int minTime(int boards[], int n, int k) {

    int low = 0, high = 0;

    // Initialize search space
    for (int i = 0; i < n; i++) {
        if (boards[i] > low)
            low = boards[i];
        high += boards[i];
    }

    int ans = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPaint(boards, n, k, mid)) {
            ans = mid;
            high = mid - 1;   // try smaller time
        } else {
            low = mid + 1;    // increase time
        }
    }

    return ans;
}

int main() {
    int n, k;

    scanf("%d %d", &n, &k);

    int boards[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    printf("%d\n", minTime(boards, n, k));

    return 0;
}