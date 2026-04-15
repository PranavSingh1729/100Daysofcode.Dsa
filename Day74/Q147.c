/* Problem Statement
Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

Input Format
First line contains an integer n representing number of votes.
Second line contains n space-separated strings representing candidate names. */

#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    int n;
    printf("Enter number of votes: ");
    scanf("%d", &n);

    char votes[MAX][50];

    printf("Enter candidate names:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", votes[i]);
    }

    char names[MAX][50];
    int count[MAX] = {0};
    int unique = 0;

    // Count frequencies
    for (int i = 0; i < n; i++) {
        int found = 0;

        for (int j = 0; j < unique; j++) {
            if (strcmp(votes[i], names[j]) == 0) {
                count[j]++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(names[unique], votes[i]);
            count[unique] = 1;
            unique++;
        }
    }

    // Find winner
    int maxVotes = -1;
    char winner[50];

    for (int i = 0; i < unique; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, names[i]);
        }
        else if (count[i] == maxVotes) {
            // Lexicographically smaller
            if (strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }

    printf("Winner: %s\n", winner);
    printf("Votes: %d\n", maxVotes);

    return 0;
}