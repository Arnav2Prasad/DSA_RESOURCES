#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Stack structure for DFS
struct Stack {
    int items[MAX_SIZE];
    int top;
};

// Initialize stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

// Check if the stack is empty
bool isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

// Push an item onto the stack
void push(struct Stack* stack, int value) {
    if (stack->top == MAX_SIZE - 1)
        printf("\nStack is Full!!");
    else {
        stack->top++;
        stack->items[stack->top] = value;
    }
}

// Pop an item from the stack
int pop(struct Stack* stack) {
    int item;
    if (isEmpty(stack)) {
        printf("Stack is empty");
        item = -1;
    } else {
        item = stack->items[stack->top];
        stack->top--;
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

// Depth-First Search traversal
void DFS(struct Graph* graph, int startVertex) {
    // Create a stack for DFS
    struct Stack* stack = createStack();

    // Mark the startVertex as visited and push it onto the stack
    graph->visited[startVertex] = 1;
    push(stack, startVertex);

    printf("Depth First Search starting from vertex %d: ", startVertex);

    // Continue until stack is empty
    while (!isEmpty(stack)) {
        // Pop a vertex from stack and print it
        int currentVertex = pop(stack);
        printf("%d ", currentVertex);

        // Visit all adjacent vertices of currentVertex
        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && graph->visited[i] == 0) {
                // Mark i as visited and push it onto the stack
                graph->visited[i] = 1;
                push(stack, i);
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

    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    DFS(graph, startVertex);

    return 0;
}
