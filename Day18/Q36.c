/* Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation. */

 #include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];
    int result[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    int left = 1;

    // Left pass
    for(int i = 0; i < n; i++) {
        result[i] = left;
        left *= nums[i];
    }

    int right = 1;

    // Right pass
    for(int i = n - 1; i >= 0; i--) {
        result[i] *= right;
        right *= nums[i];
    }

    for(int i = 0; i < n; i++)
        printf("%d ", result[i]);

    return 0;
}
