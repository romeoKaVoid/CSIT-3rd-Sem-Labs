// C Program to Implement Shortest Path Algorithm
#include <limits.h>
#include <stdio.h>
// Number of vertices in the graph
#define V 5

// Function to find the vertex with the minimum distance
// value from the set of vertices not yet visited in the
// shortest path tree
int min_dist(int dist[], int visited[])
{
    int min = INT_MAX, min_index;

    // Traverse all vertices to find the vertex with the
    // minimum distance value
    for (int v = 0; v < V; v++)
    {
        if (visited[v] == 0 && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the constructed distance array
void display(int dist[])
{
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
    {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

// Function that implements Dijkstra's algorithm
void Dijkstra(int graph[V][V], int src)
{
    // Array to store the minimum distance from source node
    // to the current node
    int dist[V];
    // Array to keep track of visited nodes
    int visited[V];

    // Initialize all distances as INFINITE and visited as
    // false
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find the shortest path for all vertices
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed
        int u = min_dist(dist, visited);

        // Mark the selected vertex as visited
        visited[u] = 1;

        // Update the distance of all the adjacent vertices
        // of the selected vertex
        for (int v = 0; v < V; v++)
        {
            // update dist[v] if it is already note visited
            // and the current distance is less then it's
            // original distance
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array
    display(dist);
}

int main()
{

    int graph[V][V] = {
        { 0, 2, 0, 3, 0 }, // Node A (0) connections
        { 2, 0, 1, 0, 4 }, // Node B (1) connections
        { 0, 1, 0, 5, 0 }, // Node C (2) connections
        { 3, 0, 5, 0, 6 }, // Node D (3) connections
        { 0, 4, 0, 6, 0 }  // Node E (4) connections
    };

    // Perform Dijkstra's algorithm starting from vertex 0
    // (Node A)
    printf("Dijkastra's Algorithm starting from vertex: %d\n",0);
    Dijkstra(graph, 0);
    printf("\n\n\tBy Krishna Aryal");
    return 0;
}