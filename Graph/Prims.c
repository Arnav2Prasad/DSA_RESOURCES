#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define INF 999999

int adj_matrix[MAX_VERTICES][MAX_VERTICES];

int minKey(int key[], bool mstSet[], int vertices) {
    int min = INF, min_index;
    for (int v = 0; v < vertices; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void printMST(int parent[], int num_vertices) {
    printf("Edges in the MST using Prim's Algorithm:\n");
    for (int i = 1; i < num_vertices; i++)
        printf("%d -- %d weight: %d\n", parent[i], i, adj_matrix[i][parent[i]]);
}

void primMST(int num_vertices) {
    int parent[num_vertices];
    int key[num_vertices];
    bool mstSet[num_vertices];

    for (int i = 0; i < num_vertices; i++)
        key[i] = INF, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < num_vertices - 1; count++) {
        int u = minKey(key, mstSet, num_vertices);
        mstSet[u] = true;

        for (int v = 0; v < num_vertices; v++)
            if (adj_matrix[u][v] && mstSet[v] == false && adj_matrix[u][v] < key[v])
                parent[v] = u, key[v] = adj_matrix[u][v];
    }

    printMST(parent, num_vertices);
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

    // Call Prim's Algorithm
    primMST(num_vertices);

    return 0;
}
