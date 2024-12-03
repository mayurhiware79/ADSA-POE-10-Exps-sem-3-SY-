#include <stdio.h>

#define MAX 20 // Maximum number of vertices

void BFS(int graph[MAX][MAX], int start, int visited[MAX], int n);

int main()
{
    int n;                  // Number of vertices
    int graph[MAX][MAX];    // Adjacency matrix
    int visited[MAX] = {0}; // Visited array initialized to 0
    int start;              // Starting node

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting node (0 to %d): ", n - 1);
    scanf("%d", &start);

    printf("BFS starting from node %d:\n", start);
    BFS(graph, start, visited, n);

    return 0;
}

void BFS(int graph[MAX][MAX], int start, int visited[MAX], int n)
{
    int queue[MAX], front = 0, rear = 0;

    // Mark the start node as visited and enqueue it
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear)
    {
        int current = queue[front++]; // Dequeue the front node
        printf("Visited node: %d\n", current);

        // Check all neighbors of the current node
        for (int i = 0; i < n; i++)
        {
            if (graph[current][i] == 1 && !visited[i])
            {
                visited[i] = 1;    // Mark neighbor as visited
                queue[rear++] = i; // Enqueue the neighbor
            }
        }
    }
}
