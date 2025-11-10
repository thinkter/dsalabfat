/*
 * Minimum Spanning Tree using Prim's Algorithm (Greedy Method)
 * 
 * Pseudocode:
 * 1. Create a set mstSet to keep track of vertices already included in MST
 * 2. Assign a key value to all vertices (Initialize all keys as INFINITE)
 * 3. Assign key value as 0 for the first vertex (so it is picked first)
 * 4. While mstSet doesn't include all vertices:
 *    a. Pick a vertex u which is not in mstSet and has minimum key value
 *    b. Include u to mstSet
 *    c. Update key value of all adjacent vertices of u
 *       - For every adjacent vertex v, if weight of edge u-v is less than
 *         the previous key value of v, update the key value as weight of u-v
 * 5. Print the edges and their weights in the MST
 */

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5  // Number of vertices in the graph

// Function to find the vertex with minimum key value from the set of vertices
// not yet included in MST
int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;
    
    for (int v = 0; v < V; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    
    return min_index;
}

// Function to print the constructed MST stored in parent[]
void printMST(int parent[], int graph[V][V]) {
    printf("Edge \t\tWeight\n");
    int totalWeight = 0;
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t\t%d\n", parent[i], i, graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]];
    }
    printf("\nTotal weight of MST: %d\n", totalWeight);
}

// Function to construct and print MST for a graph represented using adjacency matrix
void primMST(int graph[V][V]) {
    int parent[V];    // Array to store constructed MST
    int key[V];       // Key values used to pick minimum weight edge in cut
    bool mstSet[V];   // To represent set of vertices included in MST
    
    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    
    // Always include first vertex in MST
    // Make key 0 so that this vertex is picked as first vertex
    key[0] = 0;
    parent[0] = -1;  // First node is always root of MST
    
    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet);
        
        // Add the picked vertex to the MST Set
        mstSet[u] = true;
        
        // Update key value and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // Update the key only if:
            // - graph[u][v] is non-zero (edge exists)
            // - v is not in mstSet
            // - weight of edge u-v is smaller than current key of v
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    
    // Print the constructed MST
    printMST(parent, graph);
}

// Driver program to test above functions
int main() {
    /* Example graph represented as adjacency matrix */
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    
    printf("Prim's Minimum Spanning Tree Algorithm\n");
    printf("=======================================\n\n");
    
    primMST(graph);
    
    return 0;
}
