#include <stdio.h>

#define MAX 30

// Structure to store an edge
struct Edge {
    int u, v, w;  // u and v are vertices, w is weight
};

// To store parent of each vertex
int parent[MAX];

// Function to find the parent (used to detect cycle)
int findParent(int vertex) {
    if (parent[vertex] == vertex)
        return vertex;
    return findParent(parent[vertex]);
}

// Function to unite two sets
void unionVertices(int a, int b) {
    int parentA = findParent(a);
    int parentB = findParent(b);
    parent[parentA] = parentB;
}

int main() {
    struct Edge edges[MAX], temp;
    int n, e, i, j;
    int totalCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v w):\n");
    for (i = 0; i < e; i++)
        scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);

    // Initialize parent array
    for (i = 0; i < n; i++)
        parent[i] = i;

    // Sort edges in increasing order of weight (simple bubble sort)
    for (i = 0; i < e - 1; i++) {
        for (j = 0; j < e - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    printf("\nEdges in Minimum Spanning Tree:\n");

    // Kruskal’s Algorithm
    int edgeCount = 0;
    for (i = 0; i < e && edgeCount < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        int parentU = findParent(u);
        int parentV = findParent(v);

        // If including this edge doesn’t cause a cycle
        if (parentU != parentV) {
            printf("%d -- %d = %d\n", u, v, w);
            totalCost += w;
            edgeCount++;
            unionVertices(u, v);
        }
    }

    printf("Total cost of MST = %d\n", totalCost);

    return 0;
}