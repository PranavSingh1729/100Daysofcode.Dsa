/* Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting? */

#include <stdlib.h>

// Swap helper
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition (descending order)
int partition(int nums[], int low, int high) {
    int pivot = nums[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (nums[j] > pivot) {  // for kth largest
            swap(&nums[i], &nums[j]);
            i++;
        }
    }

    swap(&nums[i], &nums[high]);
    return i;
}

// QuickSelect
int quickSelect(int nums[], int low, int high, int k) {
    if (low <= high) {
        int pi = partition(nums, low, high);

        if (pi == k)
            return nums[pi];
        else if (pi > k)
            return quickSelect(nums, low, pi - 1, k);
        else
            return quickSelect(nums, pi + 1, high, k);
    }
    return -1;
}

int findKthLargest(int* nums, int numsSize, int k) {
    return quickSelect(nums, 0, numsSize - 1, k - 1);
}

#include <stdio.h>

int findKthLargest(int* nums, int numsSize, int k);

int main() {
    int nums[] = {3,2,1,5,6,4};
    int k = 2;

    printf("%d\n", findKthLargest(nums, 6, k)); // Output: 5

    return 0;
}