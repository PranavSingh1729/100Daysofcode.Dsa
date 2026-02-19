/* Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers */

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Sort the array
    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;

    int minSum = arr[left] + arr[right];
    int minAbs = abs(minSum);

    while(left < right) {
        int sum = arr[left] + arr[right];

        if(abs(sum) < minAbs) {
            minAbs = abs(sum);
            minSum = sum;
        }

        if(sum < 0)
            left++;
        else
            right--;
    }

    printf("Sum closest to zero: %d\n", minSum);

    return 0;
}
