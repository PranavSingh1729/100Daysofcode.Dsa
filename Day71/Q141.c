/* Problem Statement
Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input Format
Same as previous. */

#include <stdio.h>

#define EMPTY -1

int main() {
    int m, n;

    printf("Enter hash table size: ");
    scanf("%d", &m);

    int table[m];
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    printf("Enter number of keys: ");
    scanf("%d", &n);

    int key;
    for (int x = 0; x < n; x++) {
        printf("Enter key %d: ", x + 1);
        scanf("%d", &key);

        int h = key % m;
        int inserted = 0;

        for (int i = 0; i < m; i++) {
            int index = (h + i * i) % m;

            if (table[index] == EMPTY) {
                table[index] = key;
                inserted = 1;
                break;
            }
        }

        if (!inserted) {
            printf("Hash table is full, cannot insert %d\n", key);
        }
    }

    printf("\nHash Table:\n");
    for (int i = 0; i < m; i++) {
        if (table[i] == EMPTY)
            printf("Index %d : EMPTY\n", i);
        else
            printf("Index %d : %d\n", i, table[i]);
    }

    return 0;
}