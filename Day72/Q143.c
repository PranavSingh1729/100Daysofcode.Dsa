/* Problem Statement
Given a string s consisting of lowercase letters, find the first repeated character in the string. A character is considered repeated if it appears more than once, and among all such characters, the one whose second occurrence has the smallest index should be returned.

Input Format
A single string s. */

#include <stdio.h>

char firstRepeatedChar(char *s) {
    int freq[26] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';

        freq[index]++;

        // If appears second time → return immediately
        if (freq[index] == 2) {
            return s[i];
        }
    }

    return '\0'; // no repeated character
}

int main() {
    char s[100];

    printf("Enter string: ");
    scanf("%s", s);

    char result = firstRepeatedChar(s);

    if (result == '\0')
        printf("No repeated character\n");
    else
        printf("First repeated character: %c\n", result);

    return 0;
}