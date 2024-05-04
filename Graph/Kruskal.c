#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// -----------------UNION - FIND ALGO ---------------

#define MAX_VERTICES 100
#define INF 999999

int adj_matrix[MAX_VERTICES][MAX_VERTICES];

struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent, rank;
};

int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int comparator(const void* a, const void* b) {
    struct Edge* a_edge = (struct Edge*)a;
    struct Edge* b_edge = (struct Edge*)b;
    return a_edge->weight - b_edge->weight;
}

void KruskalMST(int num_vertices) {
    struct Edge result[num_vertices];
    int e = 0;
    int i = 0;

    struct Edge edges[num_vertices*num_vertices];
    for (int u = 0; u < num_vertices; u++) {
        for (int v = 0; v < num_vertices; v++) {
            if (adj_matrix[u][v] != 0) {
                edges[i].src = u;
                edges[i].dest = v;
                edges[i].weight = adj_matrix[u][v];
                i++;
            }
        }
    }

    qsort(edges, i, sizeof(struct Edge), comparator);

    struct Subset subsets[num_vertices];
    for (int v = 0; v < num_vertices; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    i = 0;
    while (e < num_vertices - 1 && i < num_vertices * num_vertices) {
        struct Edge next_edge = edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    printf("Edges in the MST using Kruskal's Algorithm:\n");
    for (i = 0; i < e; ++i)
        printf("%d -- %d weight: %d\n", result[i].src, result[i].dest, result[i].weight);
}

int main() {
    int num_vertices = 5;
    // Populate the adjacency matrix
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            // Assume the adjacency matrix is already populated
            // For demonstration purposes, initializing with some values
            if (i == j)
                adj_matrix[i][j] = 0;
            else
                adj_matrix[i][j] = rand() % 10 + 1; // Random weights between 1 and 10
        }
    }

    // Print the adjacency matrix
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    // Call Kruskal's Algorithm
    KruskalMST(num_vertices);

    return 0;
}
