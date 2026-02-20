/* Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

Input:
- First line: integer n
- Second line: n integers */

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int sum = 0;
    int count = 0;

    // Simple frequency storage (since no hashmap in basic C)
    int freq[20001] = {0};  // adjust range if needed
    int offset = 10000;     // to handle negative sums

    freq[offset] = 1; // sum = 0 initially

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(freq[sum + offset] > 0)
            count += freq[sum + offset];

        freq[sum + offset]++;
    }

    printf("%d", count);

    return 0;
}
