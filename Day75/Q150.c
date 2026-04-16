/* Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
Return a boolean indicating whether the matching covers the entire input string (not partial). */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isMatch(char* s, char* p) {
    int m = strlen(s);
    int n = strlen(p);

    bool dp[m+1][n+1];

    // Initialize dp table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = false;
        }
    }

    dp[0][0] = true;

    // Handle patterns like a*, a*b*, etc.
    for (int j = 2; j <= n; j++) {
        if (p[j-1] == '*') {
            dp[0][j] = dp[0][j-2];
        }
    }

    // Fill DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {

            // Match or '.'
            if (p[j-1] == s[i-1] || p[j-1] == '.') {
                dp[i][j] = dp[i-1][j-1];
            }

            // '*' case
            else if (p[j-1] == '*') {
                // Zero occurrence
                dp[i][j] = dp[i][j-2];

                // One or more occurrence
                if (p[j-2] == s[i-1] || p[j-2] == '.') {
                    dp[i][j] = dp[i][j] || dp[i-1][j];
                }
            }
        }
    }

    return dp[m][n];
}

int main() {
    char s[1000], p[1000];

    printf("Enter string: ");
    scanf("%s", s);

    printf("Enter pattern: ");
    scanf("%s", p);

    if (isMatch(s, p)) {
        printf("Match: true\n");
    } else {
        printf("Match: false\n");
    }

    return 0;
}