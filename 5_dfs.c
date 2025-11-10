/*
 * Depth First Search (DFS) Graph Traversal
 * 
 * Pseudocode (Recursive):
 * 1. Mark the current node as visited and print it
 * 2. For each adjacent vertex of current node:
 *    a. If the adjacent vertex is not visited, recursively call DFS on it
 * 3. Repeat until all reachable vertices are visited
 * 
 * Pseudocode (Iterative using Stack):
 * 1. Create a stack S
 * 2. Mark the starting node as visited and push it to S
 * 3. While S is not empty:
 *    a. Pop a vertex from S and print it
 *    b. Get all adjacent vertices of the popped vertex
 *    c. For each adjacent vertex, if it has not been visited:
 *       - Mark it as visited
 *       - Push it to S
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a graph
struct Graph {
    int numVertices;
    int** adjMatrix;
};

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

// Recursive DFS traversal helper function
void DFSUtil(struct Graph* graph, int vertex, bool visited[]) {
    // Mark the current node as visited and print it
    visited[vertex] = true;
    printf("%d ", vertex);
    
    // Recur for all the vertices adjacent to this vertex
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
}

// DFS traversal using recursion
void DFS_Recursive(struct Graph* graph, int startVertex) {
    // Create visited array to keep track of visited vertices
    bool* visited = (bool*)malloc(graph->numVertices * sizeof(bool));
    for (int i = 0; i < graph->numVertices; i++)
        visited[i] = false;
    
    printf("DFS Traversal (Recursive) starting from vertex %d: ", startVertex);
    DFSUtil(graph, startVertex, visited);
    printf("\n");
    
    free(visited);
}

// DFS traversal using stack (iterative)
void DFS_Iterative(struct Graph* graph, int startVertex) {
    // Create visited array
    bool* visited = (bool*)malloc(graph->numVertices * sizeof(bool));
    for (int i = 0; i < graph->numVertices; i++)
        visited[i] = false;
    
    // Create a stack for DFS
    int* stack = (int*)malloc(graph->numVertices * sizeof(int));
    int top = -1;
    
    // Push the starting vertex to stack
    stack[++top] = startVertex;
    
    printf("DFS Traversal (Iterative) starting from vertex %d: ", startVertex);
    
    while (top >= 0) {
        // Pop a vertex from stack
        int currentVertex = stack[top--];
        
        // If not visited, mark as visited and print
        if (!visited[currentVertex]) {
            printf("%d ", currentVertex);
            visited[currentVertex] = true;
        }
        
        // Get all adjacent vertices of the popped vertex
        // Push unvisited adjacent vertices to stack
        for (int i = graph->numVertices - 1; i >= 0; i--) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                stack[++top] = i;
            }
        }
    }
    printf("\n");
    
    free(visited);
    free(stack);
}

// Driver program to test DFS
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
    
    printf("Depth First Search (DFS) Graph Traversal\n");
    printf("=========================================\n\n");
    
    DFS_Recursive(graph, 0);
    DFS_Iterative(graph, 0);
    
    // Free allocated memory
    for (int i = 0; i < graph->numVertices; i++)
        free(graph->adjMatrix[i]);
    free(graph->adjMatrix);
    free(graph);
    
    return 0;
}
