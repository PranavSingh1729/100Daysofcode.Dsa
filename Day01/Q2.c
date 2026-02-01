/* Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.*/

#include <stdio.h>

#define MAX 1000

int main() {
    int n, target;
    int nums[MAX];

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    scanf("%d", &target);

    // Simple hash storage
    int value[MAX];
    int index[MAX];
    int size = 0;

    for(int i = 0; i < n; i++) {
        int needed = target - nums[i];

        // Check if needed number already exists
        for(int j = 0; j < size; j++) {
            if(value[j] == needed) {
                printf("%d %d", index[j], i);
                return 0;
            }
        }

        // Store current number
        value[size] = nums[i];
        index[size] = i;
        size++;
    }

    return 0;
}
