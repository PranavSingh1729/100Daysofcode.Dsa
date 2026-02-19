/* Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n. */

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    int totalSum = 0;
    int maxSum = nums[0], currentMax = 0;
    int minSum = nums[0], currentMin = 0;

    for(int i = 0; i < n; i++) {
        totalSum += nums[i];

        // Max Kadane
        if(currentMax > 0)
            currentMax += nums[i];
        else
            currentMax = nums[i];

        if(currentMax > maxSum)
            maxSum = currentMax;

        // Min Kadane
        if(currentMin < 0)
            currentMin += nums[i];
        else
            currentMin = nums[i];

        if(currentMin < minSum)
            minSum = currentMin;
    }

    if(maxSum < 0)
        printf("%d", maxSum);
    else {
        int circularSum = totalSum - minSum;
        printf("%d", (maxSum > circularSum) ? maxSum : circularSum);
    }

    return 0;
}
