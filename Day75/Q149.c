/* Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[]. */

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Simple hash map using array (for range handling)
int maxLen(int arr[], int n) {
    
    int prefixSum = 0;
    int maxLength = 0;

    // Hash map: store first occurrence of prefix sum
    int hash[2 * MAX] = {0};

    // Initialize with -1 (not seen)
    for (int i = 0; i < 2 * MAX; i++) {
        hash[i] = -2;
    }

    hash[MAX] = -1; // prefix sum = 0 at index -1

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        int index = prefixSum + MAX;

        if (hash[index] != -2) {
            int len = i - hash[index];
            if (len > maxLength)
                maxLength = len;
        } else {
            hash[index] = i;
        }
    }

    return maxLength;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Longest subarray length: %d\n", maxLen(arr, n));

    return 0;
}