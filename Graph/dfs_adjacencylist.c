#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for an adjacency list node
struct AdjListNode {
    int dest;
    int weight;
    struct AdjListNode* next;
};

// Structure for the adjacency list
struct AdjList {
    struct AdjListNode* head;
};

// Structure for the graph
struct Graph {
    int V; // Number of vertices
    struct AdjList* array;
};

// Function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest, int weight) {
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    // Add an edge from src to dest
    struct AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since the graph is undirected, add an edge from dest to src as well
    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// DFS traversal
void DFSUtil(struct Graph* graph, int v, bool visited[]) {
    // Mark the current node as visited and print it
    visited[v] = true;
    printf("%d ", v);

    // Recur for all the vertices adjacent to this vertex
    struct AdjListNode* temp = graph->array[v].head;
    while (temp != NULL) {
        if (!visited[temp->dest])
            DFSUtil(graph, temp->dest, visited);
        temp = temp->next;
    }
}

// DFS traversal starting from vertex v
void DFS(struct Graph* graph, int v) {
    // Mark all the vertices as not visited
    bool* visited = (bool*)malloc(graph->V * sizeof(bool));
    for (int i = 0; i < graph->V; i++)
        visited[i] = false;

    // Call the recursive helper function to print DFS traversal
    DFSUtil(graph, v, visited);
}

// Main function
int main() {
    // Create a graph
    int V = 5; // Number of vertices
    struct Graph* graph = createGraph(V);

    // Add edges
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 2, 20);
    addEdge(graph, 1, 2, 30);
    addEdge(graph, 1, 3, 40);
    addEdge(graph, 2, 3, 50);
    addEdge(graph, 3, 4, 60);

    printf("Depth First Traversal starting from vertex 0: ");
    DFS(graph, 0);

    return 0;
}
