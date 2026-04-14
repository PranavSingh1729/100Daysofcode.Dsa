/* In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input. */

#include <stdio.h>

int parent[1001];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

int unionSet(int a, int b) {
    int pa = find(a);
    int pb = find(b);

    if (pa == pb)
        return 0;

    parent[pa] = pb;
    return 1;
}

int main() {
    int edges[][2] = {
        {1,2},
        {1,3},
        {2,3}
    };

    int n = 3;

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    int res[2];

    for (int i = 0; i < n; i++) {
        if (!unionSet(edges[i][0], edges[i][1])) {
            res[0] = edges[i][0];
            res[1] = edges[i][1];
        }
    }

    printf("Redundant Edge: [%d, %d]\n", res[0], res[1]);

    return 0;
}