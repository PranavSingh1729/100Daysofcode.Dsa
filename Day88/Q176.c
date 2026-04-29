/* In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.

Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

Given the integer array position and the integer m. Return the required force. */

#include <stdio.h>
#include <stdlib.h>

// Compare for sorting
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Check if we can place m balls with minimum distance = dist
int canPlace(int pos[], int n, int m, int dist) {
    int count = 1;
    int last = pos[0];

    for (int i = 1; i < n; i++) {
        if (pos[i] - last >= dist) {
            count++;
            last = pos[i];
        }
        if (count >= m) return 1;
    }

    return 0;
}

int maxDistance(int* position, int n, int m) {

    // Sort positions
    qsort(position, n, sizeof(int), cmp);

    int low = 1;
    int high = position[n - 1] - position[0];
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlace(position, n, m, mid)) {
            ans = mid;       // possible → try bigger
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}
int main() {
    int position[] = {1, 2, 3, 4, 7};
    int n = 5, m = 3;

    printf("%d\n", maxDistance(position, n, m));

    return 0;
}