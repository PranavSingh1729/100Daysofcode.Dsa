/* Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours. */

#include <stdio.h>

// Check if Koko can finish at speed k within h hours
int canFinish(int piles[], int n, int h, int k) {
    long long hours = 0;

    for (int i = 0; i < n; i++) {
        // ceil(piles[i] / k)
        hours += (piles[i] + k - 1) / k;
    }

    return hours <= h;
}

// Main function to find minimum speed
int minEatingSpeed(int piles[], int n, int h) {
    int low = 1, high = 0;

    // Find maximum pile
    for (int i = 0; i < n; i++) {
        if (piles[i] > high)
            high = piles[i];
    }

    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canFinish(piles, n, h, mid)) {
            ans = mid;
            high = mid - 1;   // try smaller speed
        } else {
            low = mid + 1;    // increase speed
        }
    }

    return ans;
}

int main() {
    int n;

    // Input number of piles
    scanf("%d", &n);

    int piles[n];

    // Input piles
    for (int i = 0; i < n; i++) {
        scanf("%d", &piles[i]);
    }

    int h;
    scanf("%d", &h);

    int result = minEatingSpeed(piles, n, h);

    printf("%d\n", result);

    return 0;
}