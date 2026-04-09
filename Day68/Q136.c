/* A new alien language uses the English alphabet, but the order of letters is unknown. You are given a list of words[] from the alien language’s dictionary, where the words are claimed to be sorted lexicographically according to the language’s rules.

Your task is to determine the correct order of letters in this alien language based on the given words. If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules. If there are multiple valid orders, return any one of them.

However, if the given arrangement of words is inconsistent with any possible letter ordering, return an empty string ("").

A string a is lexicographically smaller than a string b if, at the first position where they differ, the character in a appears earlier in the alien language than the corresponding character in b. If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 26
#define MAX_WORD 100
#define MAX_LEN 100

int adj[MAX][MAX];
int indegree[MAX];

// Function to find order
void findOrder(char dict[][MAX_LEN], int N, int K) {
    
    // Initialize
    for (int i = 0; i < K; i++) {
        indegree[i] = 0;
        for (int j = 0; j < K; j++) {
            adj[i][j] = 0;
        }
    }

    // Step 1: Build graph
    for (int i = 0; i < N - 1; i++) {
        char *w1 = dict[i];
        char *w2 = dict[i + 1];

        int len1 = strlen(w1);
        int len2 = strlen(w2);
        int len = len1 < len2 ? len1 : len2;

        int found = 0;

        for (int j = 0; j < len; j++) {
            if (w1[j] != w2[j]) {
                int u = w1[j] - 'a';
                int v = w2[j] - 'a';

                if (!adj[u][v]) {
                    adj[u][v] = 1;
                    indegree[v]++;
                }
                found = 1;
                break;
            }
        }

        // Prefix invalid case
        if (!found && len1 > len2) {
            printf("Invalid ordering (prefix issue)\n");
            return;
        }
    }

    // Step 2: Kahn's Algorithm
    int queue[MAX];
    int front = 0, rear = 0;

    for (int i = 0; i < K; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    char result[MAX];
    int idx = 0;

    while (front < rear) {
        int node = queue[front++];
        result[idx++] = node + 'a';

        for (int i = 0; i < K; i++) {
            if (adj[node][i]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    result[idx] = '\0';

    // Cycle check
    if (idx != K) {
        printf("Invalid ordering (cycle detected)\n");
        return;
    }

    // Print result
    printf("Character Order: %s\n", result);
}

// Main function
int main() {
    int N, K;

    printf("Enter number of words: ");
    scanf("%d", &N);

    printf("Enter number of unique characters (K): ");
    scanf("%d", &K);

    char dict[MAX_WORD][MAX_LEN];

    printf("Enter words:\n");
    for (int i = 0; i < N; i++) {
        scanf("%s", dict[i]);
    }

    findOrder(dict, N, K);

    return 0;
}