#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum number of vertices

int queue[MAX], front = -1, rear = -1;
int visited[MAX];

// Function to add an element to the queue (for BFS)
void enqueue(int value)
{
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = value;
}

// Function to remove an element from the queue (for BFS)
int dequeue()
{
    if (front > rear || front == -1)
        return -1;
    return queue[front++];
}

// BFS Function
void BFS(int graph[MAX][MAX], int vertices, int start)
{
    for (int i = 0; i < vertices; i++)
        visited[i] = 0; // Reset visited array

    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front <= rear)
    {
        int node = dequeue();
        printf("%d ", node);

        for (int i = 1; i <= vertices; i++)
        {
            if (graph[node][i] == 1 && visited[i] == 0)
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// DFS Function (Recursive)
void DFS(int graph[MAX][MAX], int vertices, int node)
{
    printf("%d ", node);
    visited[node] = 1;

    for (int i = 1; i <= vertices; i++)
    {
        if (graph[node][i] == 1 && visited[i] == 0)
        {
            DFS(graph, vertices, i);
        }
    }
}

// Main Function
int main()
{
    int vertices, edges, u, v, start;
    int graph[MAX][MAX] = {0};

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; // Mark edge (u -> v)
        graph[v][u] = 1; // If undirected, mark (v -> u)
    }

    printf("Enter the starting node: ");
    scanf("%d", &start);

    // Perform BFS
    BFS(graph, vertices, start);

    // Reset visited array for DFS
    for (int i = 0; i <= vertices; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    DFS(graph, vertices, start);
    printf("\n\n\tBy Krishna Aryal");
    return 0;
}