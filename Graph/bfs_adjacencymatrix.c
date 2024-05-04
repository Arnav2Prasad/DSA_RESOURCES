#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Queue structure for BFS
struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

// Initialize queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check if the queue is empty
bool isEmpty(struct Queue* q) {
    return (q->rear == -1);
}

// Enqueue an item into the queue
void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX_SIZE - 1)
        printf("\nQueue is Full!!");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Dequeue an item from the queue
int dequeue(struct Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            // Reset queue to empty state
            q->front = q->rear = -1;
        }
    }
    return item;
}

// Graph structure
struct Graph {
    int vertices;
    int** adjMatrix;
    int* visited;
};

// Create graph with n vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    // Allocate memory for adjacency matrix
    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int*)malloc(vertices * sizeof(int));
        // Initialize all elements to 0 (no edges by default)
        for (int j = 0; j < vertices; j++)
            graph->adjMatrix[i][j] = 0;
    }

    // Allocate memory for visited array
    graph->visited = (int*)malloc(vertices * sizeof(int));
    // Initialize visited array to 0 (unvisited)
    for (int i = 0; i < vertices; i++)
        graph->visited[i] = 0;

    return graph;
}

// Add edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    graph->adjMatrix[src][dest] = 1;
    // For undirected graph, add edge from dest to src as well
    graph->adjMatrix[dest][src] = 1;
}

// Breadth-First Search traversal
void BFS(struct Graph* graph, int startVertex) {
    // Create a queue for BFS
    struct Queue* q = createQueue();

    // Mark the startVertex as visited and enqueue it
    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);

    printf("Breadth First Search starting from vertex %d: ", startVertex);

    // Continue until queue is empty
    while (!isEmpty(q)) {
        // Dequeue a vertex from queue and print it
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        // Visit all adjacent vertices of currentVertex
        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && graph->visited[i] == 0) {
                // Mark i as visited and enqueue it
                graph->visited[i] = 1;
                enqueue(q, i);
            }
        }
    }

    printf("\n");
}

// Main function
int main() {
    int vertices, edges, startVertex;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    struct Graph* graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    int src, dest;
    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    BFS(graph, startVertex);

    return 0;
}
