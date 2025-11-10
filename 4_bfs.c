/*
 * Breadth First Search (BFS) Graph Traversal
 * 
 * Pseudocode:
 * 1. Create a queue Q
 * 2. Mark the starting node as visited and enqueue it to Q
 * 3. While Q is not empty:
 *    a. Dequeue a vertex from Q and print it
 *    b. Get all adjacent vertices of the dequeued vertex
 *    c. For each adjacent vertex, if it has not been visited:
 *       - Mark it as visited
 *       - Enqueue it to Q
 * 4. Repeat until the queue is empty
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// Structure to represent a queue
struct Queue {
    int items[MAX];
    int front;
    int rear;
};

// Structure to represent a graph
struct Graph {
    int numVertices;
    int** adjMatrix;
};

// Function to create a queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check if the queue is empty
bool isEmpty(struct Queue* q) {
    return q->rear == -1;
}

// Add an element to the queue
void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1)
        printf("\nQueue is Full!!");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Remove an element from the queue
int dequeue(struct Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

// Function to create a graph with n vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    
    // Allocate memory for adjacency matrix
    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int*)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++)
            graph->adjMatrix[i][j] = 0;
    }
    
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;  // For undirected graph
}

// BFS traversal algorithm
void BFS(struct Graph* graph, int startVertex) {
    struct Queue* q = createQueue();
    
    // Create visited array to keep track of visited vertices
    bool* visited = (bool*)malloc(graph->numVertices * sizeof(bool));
    for (int i = 0; i < graph->numVertices; i++)
        visited[i] = false;
    
    // Mark the starting vertex as visited and enqueue it
    visited[startVertex] = true;
    enqueue(q, startVertex);
    
    printf("BFS Traversal starting from vertex %d: ", startVertex);
    
    // Loop until queue is empty
    while (!isEmpty(q)) {
        // Dequeue a vertex from queue and print it
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);
        
        // Get all adjacent vertices of the dequeued vertex
        // If an adjacent vertex has not been visited, mark it visited and enqueue it
        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(q, i);
            }
        }
    }
    printf("\n");
    
    free(visited);
    free(q);
}

// Driver program to test BFS
int main() {
    /* Example graph:
         0 --- 1
         |     |
         |     |
         2 --- 3
    */
    
    struct Graph* graph = createGraph(4);
    
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    
    printf("Breadth First Search (BFS) Graph Traversal\n");
    printf("===========================================\n\n");
    
    BFS(graph, 0);
    
    // Free allocated memory
    for (int i = 0; i < graph->numVertices; i++)
        free(graph->adjMatrix[i]);
    free(graph->adjMatrix);
    free(graph);
    
    return 0;
}
