/* Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity. */

#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target);

int main() {
    int nums[] = {1,3,5,6};
    int target = 5;

    printf("Index: %d\n", searchInsert(nums, 4, target));

    return 0;
}

int searchInsert(int* nums, int numsSize, int target) {
    
    int low = 0, high = numsSize - 1;
    int ans = numsSize; // default insert at end

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] >= target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}