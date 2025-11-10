/*
 * Single Source Shortest Path using Dijkstra's Algorithm
 * 
 * Pseudocode:
 * 1. Initialize distances of all vertices as INFINITE
 * 2. Set distance of source vertex as 0
 * 3. Create a set to keep track of vertices included in shortest path tree
 * 4. While all vertices are not included in the set:
 *    a. Pick a vertex u which is not in set and has minimum distance value
 *    b. Include u to the set
 *    c. Update distance value of all adjacent vertices of u
 *       - For each adjacent vertex v, if sum of distance[u] and weight(u,v)
 *         is less than distance[v], then update distance[v]
 * 5. Print the shortest distances from source to all vertices
 */

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 9  // Number of vertices in the graph

// Function to find the vertex with minimum distance value from the set of vertices
// not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;
    
    for (int v = 0; v < V; v++) {
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    
    return min_index;
}

// Function to print the constructed distance array
void printSolution(int dist[]) {
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

// Function to implement Dijkstra's single source shortest path algorithm
// graph[i][j] represents the weight of edge from i to j (0 means no edge)
void dijkstra(int graph[V][V], int src) {
    int dist[V];      // dist[i] will hold the shortest distance from src to i
    bool sptSet[V];   // sptSet[i] will be true if vertex i is included in shortest path tree
    
    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
    
    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, sptSet);
        
        // Mark the picked vertex as processed
        sptSet[u] = true;
        
        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // Update dist[v] only if:
            // - it is not in sptSet
            // - there is an edge from u to v
            // - total weight of path from src to v through u is smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    
    // Print the constructed distance array
    printSolution(dist);
}

// Driver program to test above functions
int main() {
    /* Example graph represented as adjacency matrix */
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };
    
    printf("Dijkstra's Single Source Shortest Path Algorithm\n");
    printf("=================================================\n\n");
    
    dijkstra(graph, 0);  // Run Dijkstra's algorithm starting from vertex 0
    
    return 0;
}
