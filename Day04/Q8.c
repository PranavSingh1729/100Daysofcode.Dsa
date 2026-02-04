/* Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
Return k.
Custom Judge: */

#include <stdio.h>

int main() {
    int n, val;
    scanf("%d", &n);

    int nums[n];

    // Input array
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // Value to remove
    scanf("%d", &val);

    int k = 0;  // Count of elements not equal to val

    // Overwrite unwanted elements
    for(int i = 0; i < n; i++) {
        if(nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }

    // Output
    printf("k = %d\n", k);
    printf("Updated array: ");

    for(int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}

