// Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

#include <stdio.h>

int main() {
    int p, q;

    // Read size of first log
    scanf("%d", &p);
    int a[p];

    for(int i = 0; i < p; i++) {
        scanf("%d", &a[i]);
    }

    // Read size of second log
    scanf("%d", &q);
    int b[q];

    for(int i = 0; i < q; i++) {
        scanf("%d", &b[i]);
    }

    int merged[p + q];
    int i = 0, j = 0, k = 0;

    // Merge
    while(i < p && j < q) {
        if(a[i] <= b[j]) {
            merged[k++] = a[i++];
        } else {
            merged[k++] = b[j++];
        }
    }

    // Remaining elements
    while(i < p) {
        merged[k++] = a[i++];
    }

    while(j < q) {
        merged[k++] = b[j++];
    }

    // Output merged log
    for(int x = 0; x < p + q; x++) {
        printf("%d ", merged[x]);
    }

    return 0;
}
