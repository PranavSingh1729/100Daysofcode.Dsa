/* Problem Statement
Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.

Input Format
A single string s. */

#include <stdio.h>

char firstNonRepeating(char *s) {
    int freq[26] = {0};

    // Step 1: Count frequency
    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }

    // Step 2: Find first non-repeating
    for (int i = 0; s[i] != '\0'; i++) {
        if (freq[s[i] - 'a'] == 1) {
            return s[i];
        }
    }

    return '$'; // all characters repeat
}

int main() {
    char s[100];

    printf("Enter string: ");
    scanf("%s", s);

    char result = firstNonRepeating(s);

    printf("Result: %c\n", result);

    return 0;
}

           