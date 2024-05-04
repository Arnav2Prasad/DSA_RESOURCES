#include <stdio.h>
#include <stdlib.h>

// for true and false
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


// Structure for a queue node
struct QueueNode {
    int data;
    struct QueueNode* next;
};


// Structure for the queue
struct Queue {
    struct QueueNode *front, *rear;
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


// Function to create a new queue node
struct QueueNode* newQueueNode(int data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
bool isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// Function to enqueue an item into the queue
void enqueue(struct Queue* queue, int data) {
    struct QueueNode* newNode = newQueueNode(data);
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

// Function to dequeue an item from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return -1;
    struct QueueNode* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    free(temp);
    return data;
}


// BFS traversal
void BFS(struct Graph* graph, int startVertex) {
    // Mark all the vertices as not visited
    bool* visited = (bool*)malloc(graph->V * sizeof(bool));
    for (int i = 0; i < graph->V; i++)
        visited[i] = false;

    // Create a queue for BFS
    struct Queue* queue = createQueue();

    // Mark the startVertex as visited and enqueue it
    visited[startVertex] = true;
    enqueue(queue, startVertex);

    printf("Breadth First Search starting from vertex %d: ", startVertex);

    // Continue until queue is empty
    while (!isEmpty(queue)) {
        // Dequeue a vertex from queue and print it
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        // Visit all adjacent vertices of currentVertex
        struct AdjListNode* temp = graph->array[currentVertex].head;
        while (temp != NULL) {
            if (!visited[temp->dest]) {
                // Mark the adjacent vertex as visited and enqueue it
                visited[temp->dest] = true;
                enqueue(queue, temp->dest);
            }
            temp = temp->next;
        }
    }

    printf("\n");
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

    BFS(graph, 0);

    return 0;
}
