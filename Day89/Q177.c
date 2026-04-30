/* Problem Statement
Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.

Books must be allocated in contiguous order.

Input Format
n m
n space-separated integers representing pages in books */


#include <stdio.h>

// Check if allocation is possible with maxPages
int canAllocate(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pages = 0;

    for (int i = 0; i < n; i++) {

        if (arr[i] > maxPages)
            return 0;

        if (pages + arr[i] <= maxPages) {
            pages += arr[i];
        } else {
            students++;
            pages = arr[i];
        }

        if (students > m)
            return 0;
    }

    return 1;
}

int allocateBooks(int arr[], int n, int m) {

    if (m > n) return -1;

    int low = 0, high = 0;

    // Calculate range
    for (int i = 0; i < n; i++) {
        if (arr[i] > low)
            low = arr[i];
        high += arr[i];
    }

    int ans = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canAllocate(arr, n, m, mid)) {
            ans = mid;
            high = mid - 1;   // try smaller
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", allocateBooks(arr, n, m));

    return 0;
}