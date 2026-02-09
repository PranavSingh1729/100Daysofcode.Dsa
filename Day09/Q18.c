/* Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory. */

#include <stdio.h>
#include <string.h>

int main() {
    char s[100];

    // Input string
    scanf("%s", s);

    int i = 0;
    int j = strlen(s) - 1;

    // Reverse in-place
    while (i < j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;

        i++;
        j--;
    }

    // Output reversed string
    printf("%s", s);

    return 0;
}
