/*You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.*/

#include <stdio.h>

void merge(int nums1[], int m, int nums2[], int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    // Merge from back
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }

    // Copy remaining nums2 elements
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}

int main() {
    int m, n;

    // Input first array size
    scanf("%d", &m);
    int nums1[m + 100];  // extra space for merge

    // Input first array elements
    for(int i = 0; i < m; i++) {
        scanf("%d", &nums1[i]);
    }

    // Input second array size
    scanf("%d", &n);
    int nums2[n];

    // Input second array elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums2[i]);
    }

    // Call merge
    merge(nums1, m, nums2, n);

    // Print merged array
    for(int i = 0; i < m + n; i++) {
        printf("%d ", nums1[i]);
    }

    return 0;
}
