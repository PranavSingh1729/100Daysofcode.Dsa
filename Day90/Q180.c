/* Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array. */

int canSplit(int* nums, int n, int k, int maxSum) {
    int count = 1;
    int current = 0;

    for (int i = 0; i < n; i++) {

        if (nums[i] > maxSum)
            return 0;

        if (current + nums[i] <= maxSum) {
            current += nums[i];
        } else {
            count++;
            current = nums[i];
        }

        if (count > k)
            return 0;
    }

    return 1;
}

int splitArray(int* nums, int numsSize, int k) {

    int low = 0, high = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > low)
            low = nums[i];
        high += nums[i];
    }

    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canSplit(nums, numsSize, k, mid)) {
            ans = mid;
            high = mid - 1;   // try smaller max sum
        } else {
            low = mid + 1;
        }
    }

    return ans;
}
#include <stdio.h>

int splitArray(int* nums, int numsSize, int k);

int main() {
    int nums[] = {7,2,5,10,8};
    int k = 2;

    printf("%d\n", splitArray(nums, 5, k));

    return 0;
}