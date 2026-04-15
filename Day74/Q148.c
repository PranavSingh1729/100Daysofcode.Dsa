/* Given a string s, return the longest palindromic substring in s. */

#include <stdio.h>
#include <string.h>

// Expand around center
void expand(char* s, int left, int right, int* start, int* maxLen) {
    while (left >= 0 && right < strlen(s) && s[left] == s[right]) {
        int len = right - left + 1;

        if (len > *maxLen) {
            *maxLen = len;
            *start = left;
        }

        left--;
        right++;
    }
}

char* longestPalindrome(char* s) {
    int n = strlen(s);

    static char result[1000]; // static for return
    int start = 0, maxLen = 1;

    for (int i = 0; i < n; i++) {

        // Odd length
        expand(s, i, i, &start, &maxLen);

        // Even length
        expand(s, i, i + 1, &start, &maxLen);
    }

    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';

    return result;
}

int main() {
    char s[1000];

    printf("Enter string: ");
    scanf("%s", s);

    printf("Longest Palindrome: %s\n", longestPalindrome(s));

    return 0;
}