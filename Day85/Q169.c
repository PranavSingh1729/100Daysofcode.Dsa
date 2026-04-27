/* Problem: Find the integer square root of a given non-negative integer using Binary Search. The integer square root of a number is defined as the greatest integer whose square is less than or equal to the given number.

Input:
- First line: an integer n */

#include <stdio.h>

long long intSqrt(long long n) {
    long long low = 0, high = n;
    long long ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        // Avoid overflow: use division instead of mid*mid
        if (mid <= n / mid) {
            ans = mid;        // possible answer
            low = mid + 1;    // try bigger
        } else {
            high = mid - 1;   // go smaller
        }
    }

    return ans;
}

int main() {
    long long n;
    scanf("%lld", &n);

    printf("%lld\n", intSqrt(n));

    return 0;
}