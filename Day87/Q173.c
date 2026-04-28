/* Problem: Implement Binary Search Iterative - Implement the algorithm.

Input:
- First line: integer n
- Second line: n space-separated integers */

#include <stdio.h>

int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;

        else if (arr[mid] < target)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1; // not found
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    scanf("%d", &target);

    int index = binarySearch(arr, n, target);

    printf("%d\n", index);

    return 0;
} 